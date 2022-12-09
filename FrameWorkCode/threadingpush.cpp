#include "threadingpush.h"
#include "TreeItem.h"
#include "TreeModel.h"
#include <QDir>
#include <QFileInfo>
#include <QTextStream>
#include <sstream>
#include <ostream>
#include <iostream>
#include <pugixml.hpp>
#include <QDialog>
#include <QInputDialog>
#include "lg2_common.h"
#include <QObject>
#include <git2.h>
#include <QProcess>
#include <QMessageBox>
#include <QDebug>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QJsonObject>
#include <QJsonParseError>
#include <QSettings>
threadingPush::threadingPush(QObject *parent)
    : QObject{parent}
{

}
QString user_id;
std::string user, pass, email,mEmail,mName;
static int login_tries = 1;
static bool is_cred_cached = false;

int credentials_cb(git_cred ** out, const char *url, const char *username_from_url,
    unsigned int allowed_types, void *payload)
{
    int error;
//    static std::string user, pass;

    /*
     * Ask the user via the UI. On error, store the information and return GIT_EUSER which will be
     * bubbled up to the code performing the fetch or push. Using GIT_EUSER allows the application
     * to know it was an error from the application instead of libgit2.
     */
    if (!is_cred_cached)
    {
//		if (!takeCredentialsFromUser()) {
//			return -1;
//		}
    }
    QProcess process;
    process.execute("curl -d -X -k -POST --header "
                    "\"Content-type:application/x-www-form-urlencoded\" https://udaaniitb.aicte-india.org/udaan/email/ -o gitToken.json");

    QFile jsonFile("gitToken.json");
    jsonFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray data = jsonFile.readAll();

    QJsonParseError errorPtr;
    QJsonDocument document = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject mainObj = document.object();
    jsonFile.close();
    QString git_token = mainObj.value("github_token").toString();
    QString git_username = mainObj.value("github_username").toString();
    QFile::remove("gitToken.json");
    user = git_username.toStdString();
    pass = git_token.toStdString();
    return git_cred_userpass_plaintext_new(out, user.c_str(), pass.c_str());
}




void threadingPush::ControlPush(QString branchName,git_repository *repo,int login_tries,bool is_cred_cached){
    login_tries = login_tries;
    is_cred_cached=is_cred_cached;
    git_remote * remote = NULL;

    QByteArray array = branchName.toLocal8Bit();
    char* char_arr = array.data();
    char * refspec = (char*)"refs/heads/";
    char buffer[256];
    strncpy(buffer, refspec, sizeof(buffer));
    strncat(buffer, char_arr, sizeof(buffer));
    qDebug()<<"Buffer"<<buffer<<endl;
    char * d= (char*)buffer;
    const git_strarray refspecs = { &d,1 };

    git_fetch_options fetch_opts;
    git_merge_options merge_opts = GIT_MERGE_OPTIONS_INIT;
    git_checkout_options checkout_opts = GIT_CHECKOUT_OPTIONS_INIT;
    checkout_opts.checkout_strategy = GIT_CHECKOUT_SAFE;
    git_annotated_commit *heads[1] = {NULL};
    git_reference *theirs_ref = NULL, *head_ref = NULL;
    git_index *index = NULL;
    git_oid id, tree_oid;
    git_signature *signature = NULL;
    git_tree *tree = NULL;
    git_commit **parents = (git_commit **)calloc(2, sizeof(git_commit *));
    git_push_options push_opts;

    // Store remote info from repo
    int error = git_remote_lookup(&remote, repo, "origin");
    if(error){
        std::cout<<0<<endl;
        //goto cleanup;
    }

    /* Fetch objects from remote repository
     * Direct pull is not available via libgit2
     */
    git_fetch_init_options(&fetch_opts, GIT_FETCH_OPTIONS_VERSION);
    fetch_opts.callbacks.credentials = credentials_cb;
    error = git_remote_fetch( remote, NULL, &fetch_opts, NULL );
    if(error){
        std::cout<<1<<endl;
        //goto cleanup;
    }
    // cache the credentials
    is_cred_cached = true;

    /* Merge fetched objects with local branch
     * It will update index and current working area
     */
    /*char* string=(char*)"refs/remotes/origin/";
    char buffer1[256];
    strncpy(buffer1, string, sizeof(buffer1));
    strncat(buffer1, char_arr, sizeof(buffer1));
    qDebug()<<"Buffer1"<<buffer1<<endl;
*/
    error = (git_reference_lookup(&theirs_ref, repo, "refs/remotes/origin/master") != GIT_OK);
    qDebug()<<"Error"<<error<<endl;
    if (!error)
    {
        error = (git_annotated_commit_from_ref(heads, repo, theirs_ref) != GIT_OK)
             || (git_merge(repo, (const git_annotated_commit **)heads, 1, &merge_opts, &checkout_opts) != GIT_OK);

        if(error){
            std::cout<<2<<endl;
            //goto cleanup;
        }

        /* Get the needed ref, index, sign and tree
         */
        error = (git_repository_head(&head_ref, repo))
             || (git_repository_index(&index, repo))
             || (git_signature_now(&signature, mName.c_str(), mEmail.c_str()))
             || (git_index_write_tree(&tree_oid, index))
             || (git_tree_lookup(&tree, repo, &tree_oid));

        if(error){
            std::cout<<3<<endl;
            //goto cleanup;
        }

        /* Commit the merge and cleanup repo state
         */
        error = (git_reference_peel((git_object **)&parents[0], head_ref, GIT_OBJ_COMMIT))
             || (git_commit_lookup(&parents[1], repo, git_annotated_commit_id(heads[0])))
             || (git_commit_create(&id, repo, "HEAD", signature, signature, NULL, "Merge commit - Udaan Translation Tool", tree, 2, (const git_commit **)parents))
             || (git_repository_state_cleanup(repo));

        if(error){
            std::cout<<4<<endl;
            //goto cleanup;
        }
    }
    error = git_remote_push(remote, &refspecs , &push_opts);
    qDebug()<<"Error"<<error<<endl;
    error = git_push_init_options(&push_opts, GIT_PUSH_OPTIONS_VERSION);
    push_opts.callbacks.credentials = credentials_cb;
    //std::string str="refs/remotes/origin/master";
    //char * c = (char*)"refs/heads/master";
    //const git_strarray abc = { &c,1 };
    /*cleanup:
    if(remote)
        git_remote_free(remote);
    if(heads[0])
        git_annotated_commit_free(*heads);
    if(theirs_ref)
        git_reference_free(theirs_ref);
    if(head_ref)
        git_reference_free(head_ref);
    if(index)
        git_index_free(index);
    if(signature)
        git_signature_free(signature);
    if(tree)
        git_tree_free(tree);
    if(parents)
        free(parents);
    */
    if (error)
        return;

    /* Finding the last commit on current repo and saves the entry in commit history table
     * Email | Commit_no
     * So that we can see users commit history based on his/her email id without github account
     */
    char fullsha[42] = {0};
    git_oid_tostr(fullsha, 41, &id);
    QString sha = QString::fromStdString(fullsha);
    //qDebug()<<"Last commit full hash :"<<sha;
    QSettings settings("IIT-B", "OpenOCRCorrect");
    settings.beginGroup("login");
    QString email = settings.value("email").toString();
    //qDebug()<<"email"<<email;
    settings.endGroup();
    QProcess process;
    process.execute("curl -d -X -k -POST --header "
                    "\"Content-type:application/x-www-form-urlencoded\" https://udaaniitb.aicte-india.org/udaan/commits/ -d \"commit_no="+sha+"&email="+email+"\" ");;

    /*return;*///No errors
   // emit
}
