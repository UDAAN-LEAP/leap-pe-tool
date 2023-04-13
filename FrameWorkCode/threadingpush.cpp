#include "threadingpush.h"
#include "qmessagebox.h"
#include <QDir>
#include <QFileInfo>
#include <QTextStream>
#include <sstream>
#include <ostream>
#include <iostream>
#include <QObject>
#include <git2.h>
#include <QDebug>
#include <string>
#include <QJsonObject>
#include <QSettings>

std::string user_,pass_;
QString gDir;


/*!
 * \fn threadingPush::threadingPush
 * \brief Constructor
 * \param parent
 * \param repo
 * \param user
 * \param pass
 * \param gDirTwoLevelUp
 */
threadingPush::threadingPush(QObject *parent, git_repository *repo, std::string user, std::string pass, QString gDirTwoLevelUp)
    : QObject{parent}
{
    this->repo = repo;
    user_ = user;
    pass_ = pass;
    gDir = gDirTwoLevelUp+"/.git/config";
}

/*!
 * \fn credentials_cb_func
 * \brief
 * \param out
 * \param url
 * \param username_from_url
 * \param allowed_types
 * \param payload
 * \return
 */
int credentials_cb_func(git_cred ** out, const char *url, const char *username_from_url,
                        unsigned int allowed_types, void *payload)
{
    /*
     * Ask the user via the UI. On error, store the information and return GIT_EUSER which will be
     * bubbled up to the code performing the fetch or push. Using GIT_EUSER allows the application
     * to know it was an error from the application instead of libgit2.
     */
    return git_cred_userpass_plaintext_new(out, user_.c_str(), pass_.c_str());
}

/*!
 * \fn threadingPush::ControlPush
 * \brief 
 * This function helps in pushing the changes to the cloud in a thread.
 * The branch Name is Store as an QByte Array 
 * This function first looks for the repo where changes are to be pushed.
 * Then fetch options are initialized 
 * Then are commit is successful, The changes are pushed.
 * This function is being called in mainwindow.cpp file where with the help of threads this function is called so that in
 * large sets the changes are successfully pushed. 
 */
void threadingPush::ControlPush()
{
    git_libgit2_init();
    git_remote * remote = NULL;
    if(!fetch_n_merge()){
        error = -100;
        emit finishedPush();
    }
    QFile f(gDir);
    f.open(QIODevice::ReadOnly);
    while(!f.atEnd()) {
        QString line = f.readLine();
        if(line.contains("branch")){
            QStringList l = line.split(" ");
            l[1] = l[1].remove("\"");
            branchName = l[1].remove("]").simplified();
            break;
        }
    }
    f.close();
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
    error = git_remote_lookup(&remote, repo, "origin");
    if(error){
        std::cout<<0<<endl;
        //goto cleanup;
    }


    /* Fetch objects from remote repository
         * Direct pull is not available via libgit2
         */
    git_fetch_init_options(&fetch_opts, GIT_FETCH_OPTIONS_VERSION);
    fetch_opts.callbacks.credentials = credentials_cb_func;
    error = git_remote_fetch( remote, NULL, &fetch_opts, NULL );
    if(error){
        std::cout<<1<<endl;
        //goto cleanup;
    }

    /* Merge fetched objects with local branch
         * It will update index and current working area
         */
    QString name_ref = "refs/remotes/origin/"+branchName;
    QByteArray name_ref_ar = name_ref.toLatin1();
    error = (git_reference_lookup(&theirs_ref, repo, name_ref_ar.data()) != GIT_OK);
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
        if(git_index_has_conflicts(index))qDebug()<<"conflict";
        /* Commit the merge and cleanup repo state
             */
//        error = (git_reference_peel((git_object **)&parents[0], head_ref, GIT_OBJ_COMMIT))
//                || (git_commit_lookup(&parents[1], repo, git_annotated_commit_id(heads[0])))
//                || (git_commit_create(&id, repo, "HEAD", signature, signature, NULL, "Merge commit", tree, 0, (const git_commit **)parents))
//                || (git_repository_state_cleanup(repo));

//        if(error){
//            std::cout<<4<<endl;
//            //goto cleanup;
//        }
    }

    qDebug()<<"Error"<<error<<endl;

    error = git_push_init_options(&push_opts, GIT_PUSH_OPTIONS_VERSION);
    push_opts.callbacks.credentials = credentials_cb_func;
    error = git_remote_push(remote, &refspecs , &push_opts);
    emit finishedPush();
}

/*!
 * \fn MainWindow::on_actionFetch_2_triggered
 * \brief Used for syncing cloud data
 */
bool threadingPush::fetch_n_merge()
{
    //check whether user is logged in or not
    QSettings settings("IIT-B", "OpenOCRCorrect");
    settings.beginGroup("loginConsent");
    QString value = settings.value("consent").toString();
    settings.endGroup();
    if(value != "loggedIn"){
        QMessageBox msg;
        msg.setText("Please login to sync cloud data");
        msg.exec();
        return false;
    }
    settings.beginGroup("login");
    QString email = settings.value("email").toString();
    QString token = settings.value("token").toString();
    settings.endGroup();
    int error = 0;
    git_remote *remote = NULL;
    //	const git_indexer_progress *stats;
    git_fetch_options fetch_opts = GIT_FETCH_OPTIONS_INIT;

    /* Figure out whether it's a named remote or a URL */
    error = git_remote_lookup(&remote, repo, "origin");
    if (error < 0) {
        error = git_remote_create_anonymous(&remote, repo, "origin");
        if (error < 0) {
            qDebug() << "error in git_remote";
            goto cleanup;
        }
    }

    /* Set up the callbacks (only update_tips for now) */
    fetch_opts.callbacks.credentials = credentials_cb_func;

    /**
     * Perform the fetch with the configured refspecs from the
     * config. Update the reflog for the updated references with
     * "fetch".
     */
    error = git_remote_fetch(remote, NULL, &fetch_opts, "pull");
    if (error < 0) {
        qDebug() << "error in fetch";
        goto cleanup;
    }

    /**
     * 1. Check if the repository is already up to date (Don't perform git reset)
     * 2. If it is not up to date then reset the repo to the latest commit (This will delete the modifications done by user)
     */

    git_revwalk *walker;
    error = git_revwalk_new(&walker, repo);
    if (error < 0) {
        goto cleanup;
    }
    error = git_revwalk_push_range(walker, "HEAD..refs/remotes/origin/HEAD");
    if (error < 0) {
        goto cleanup;
    }

    git_oid oid;
    int count;
    count = 0;
    while(!git_revwalk_next(&oid, walker)) {
        count++;
    }
    git_revwalk_free(walker);
    qDebug() << "Final count = " << count;
    if (count > 0) {
        //find local branch name
        QString branchName;
        QFile f(gDir);
        if(!f.open(QIODevice::ReadOnly)){
            qDebug()<<"unable to open "<<gDir;
        }
        while(!f.atEnd()) {
            QString line = f.readLine();
            if(line.contains("branch")){
                QStringList l = line.split(" ");
                l[1] = l[1].remove("\"");
                branchName = l[1].remove("]").simplified();
                break;
            }
        }
        f.close();
        // perform git merge
        git_reference *local_branch_ref = NULL;
        error = git_branch_lookup(&local_branch_ref, repo, branchName.toUtf8().constData(), GIT_BRANCH_LOCAL);
        if (error < 0) {
            qDebug() << "Cannot find local branch"<<branchName;
            goto cleanup;
        }

        git_annotated_commit *remote_commit = NULL;
        error = git_annotated_commit_lookup(&remote_commit, repo, &oid);
        if (error < 0) {
            qDebug() << "Cannot find remote commit";
            goto cleanup;
        }

        git_merge_options merge_opts = GIT_MERGE_OPTIONS_INIT;
        error = git_merge(repo, (const git_annotated_commit **) &remote_commit, count, &merge_opts, NULL);
        if (error < 0) {
            qDebug() << "Cannot merge changes from remote branch";
//            goto cleanup;
        }

        git_reference_free(local_branch_ref);
        git_annotated_commit_free(remote_commit);

        // Check for conflicts after the merge
        git_index *index = NULL;
        error = git_repository_index(&index, repo);
        if (error < 0) {
            qDebug() << "Failed to open repository index";
            goto cleanup;
        }

        int has_conflicts = git_index_has_conflicts(index);
        git_index_free(index);
        if (has_conflicts) {
            qDebug() << "Merge conflicts exist. Please resolve conflicts manually.";

            // Resolve merge conflicts by giving local copy more importance
            git_index *index;
            int error = git_repository_index(&index, repo);
            if (error < 0) {
                qDebug() << "Failed to get repository index";
                return false;
            }

            git_index_conflict_iterator *conflict_iter;
            git_index_conflict_iterator_new(&conflict_iter, index);
            const git_index_entry *ancestor, *ours, *theirs;
            while (git_index_conflict_next(&ancestor, &ours, &theirs, conflict_iter) == 0) {
                // Use the local copy (ours) in case of conflict
                git_index_conflict_add(index, ours, ancestor, theirs);
            }
            git_index_conflict_iterator_free(conflict_iter);

            // Write the resolved index back to the repository
            git_index_write(index);
            git_index_free(index);

            return false;
        } else {
            qDebug() << "Merge successful";
            return true;
        }


    }

    cleanup:
        git_remote_free(remote);
        if(error<0) return false;
        else return true;
}





