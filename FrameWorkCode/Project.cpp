#include "Project.h"
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

void Project::parse_project_xml(rapidxml::xml_document<>& pDoc)
{

}

pugi::xml_node Project::FindFile(QFile & file,pugi::xml_node  & n) {
    auto ch = n.child("File");
    if (!ch) return ch;
    auto key =  mProjectDir.relativeFilePath(file.fileName()).toStdString();
    while (ch) {
        std::string filename = ch.attribute("Include").as_string();
        if (filename == key) {
            return ch;
        }
        ch = ch.next_sibling();
    }
    auto next = n.next_sibling();
    return FindFile(file, next);
}
void Project::set_stage_verifier() {
    auto c = doc.child("Project").child("Metadata");
    bool s = c.child("Stage").first_child().set_value("Verifier");
    save_xml();
}
bool Project::enable_push(bool increment) {
    auto c = doc.child("Project").child("Metadata");
    bool s = c.child("Stage").first_child().set_value("Corrector");
    int ver = std::stoi(c.child("Version").child_value());
    if(increment)
        ver++;
    c.child("Version").first_child().set_value(std::to_string(ver).c_str());
    save_xml();
    return true;
}

void Project::removeFile(QModelIndex & idx,Filter & pFilter, QFile & pFile) {
    auto first = doc.child("Project").child("ItemGroup");

    auto ch = first.next_sibling();
    auto node = FindFile(pFile, ch);
    auto pnode  = node.parent();
    pnode.remove_child(node);
    save_xml();

    mTreeModel->layoutAboutToBeChanged();
    TreeItem * item = (TreeItem*)idx.internalPointer();
    auto parent = item->parentItem();
    mTreeModel->RemoveRow(idx.row(), 1, idx.parent());
    parent->RemoveNode(item);

    delete item;

    mTreeModel->layoutChanged();
}
void Project::process_node(pugi::xml_node * pNode, TreeItem * parent)
{
    if (pNode) {
        std::string node_name = pNode->name();
        if (node_name == "ItemGroup") {
            pugi::xml_node p = pNode->first_child();
            process_node(&p, parent);
        }
        else if (node_name == "Filter") {
            /*   Example
                 <Filter Include="Image">
                    <Extensions>jpeg;jpg;png;</Extensions>
                 </Filter>
            */

            std::string filter_name = pNode->attribute("Include").as_string();;
            auto ch = pNode->child("Extensions");
            if(!ch) setProjectOpen(false);
            std::string filter_exts =  ch.child_value();

            Filter *filter = new Filter(filter_name, filter_exts);
            mFilters.push_back(filter);
            QString str;
            str = str.fromStdString(filter_name);
            //mFilters.push_back(filter_name);
            TreeItem * filter_node = new TreeItem(str, NodeType::FILTER, parent);
            filter_node->SetFilter(filter);
            parent->append_child(filter_node);
            auto p = pNode->next_sibling();
            process_node(&p, parent);
        }
        else if (node_name == "File") {

            /*
                Example:
                <File Include="page-1.jpeg">
                    <Filter>Image</Filter>
                </File>
            */
            std::string filtername = pNode->child("Filter").child_value();
            QString qfilter;
            qfilter = qfilter.fromStdString(filtername);
            auto node = mRoot->find(qfilter);
            QString filepath = QString(pNode->attribute("Include").value());

            QString fpath = "";
            fpath = mProjectDir.absolutePath()+ "/" + filepath;
            QFileInfo fileinfo(fpath);
            QFile *f = new QFile(fpath);
            mFiles.push_back(f);
            auto filename = fileinfo.fileName();
            TreeItem *nodefile = new TreeItem(filename, _FILETYPE, node);
            node->append_child(nodefile);
            nodefile->SetFile(f);
            auto p = pNode->next_sibling();
            process_node(&p, parent);
        }
    }
    else {
        setProjectOpen(false);
    }
}
/*
* Give XML file path and the content will be stored inside the class
* and processed by rapidxml
*/
void Project::process_xml(QFile & pFile) {
    if (mTreeModel)delete mTreeModel;
    /*if (mRoot) delete mRoot;*/
    setProjectOpen(true);
    pFile.open(QIODevice::ReadOnly);
    QFileInfo info;
    info.setFile(pFile);
    std::string path = pFile.fileName().toStdString();
    pugi::xml_parse_result res =  doc.load_file(path.c_str());
    if (!res) setProjectOpen(false);
    mProjectDir = info.absoluteDir();
    mFileName = info.absoluteFilePath();
    mXML = pFile.readAll().toStdString();
    auto child = doc.child("Project");
    if (!child) setProjectOpen(false);

    mProjectName = child.attribute("name").as_string();
    TreeItem * root = new TreeItem(mProjectName,FOLDER);

    mRoot = root;
    for (pugi::xml_node child : doc.child("Project")) {
        process_node(&child, root);
    }
    if(isProjectOpen()) {
        mTreeModel = new TreeModel();
        mTreeModel->setRoot(root);
        mTreeModel->layoutChanged();
    }
}
QDir Project::GetDir() {
    return mProjectDir;
}

void Project::addFile(Filter &f,QFile & pFile)
{
    auto node = doc.child("Project").child("ItemGroup").next_sibling();
    QString path = pFile.fileName();
    QString relpath = mProjectDir.relativeFilePath(path);
    std::string str = relpath.toStdString();
    std::string filtername = f.name().toStdString();
    /*
                Example:
                <File Include="page-1.jpeg">
                    <Filter>Image</Filter>
                </File>
    */

    pugi::xml_node chnode = node.append_child("File");
    chnode.append_attribute("Include") = str.c_str();
    auto fn = chnode.append_child("Filter").append_child(pugi::node_pcdata).set_value(filtername.c_str());
    auto val = chnode.first_child().child_value();
    save_xml();
    process_node(&chnode, mRoot);
    mTreeModel->layoutChanged();
}
void Project::AddTemp(Filter * filter, QFile & file,QString prefix) {
    QString name = filter->name();
    TreeItem * t = mRoot->find(name);
    QFileInfo finfo(file.fileName());
    QString fileName = prefix+finfo.fileName();
    TreeItem * f = new TreeItem(fileName,NodeType::_FILETYPE,t);
    QFile * filep = new QFile(file.fileName());
    mFiles.push_back(filep);
    f->SetFile(filep);
    Filter * filtr = new Filter();
    f->SetFilter(filter);
    t->append_child(f);
    mTreeModel->layoutChanged();
}
void Project::save_xml() {
    try {
        std::string str = mFileName.toStdString();
        bool isSaved = doc.save_file(str.c_str());
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << "Runtime error was: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error was: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred." << std::endl;
    }
}
void Project::getFile(const QString & pFileName)
{
}

TreeModel * Project::getModel() {
    return mTreeModel;
}



git_repository_init_options make_opts(bool bare, const char * templ,
    uint32_t shared,
    const char * gitdir,
    const char * dir)
{
    git_repository_init_options opts = GIT_REPOSITORY_INIT_OPTIONS_INIT;

    if (bare)
        opts.flags |= GIT_REPOSITORY_INIT_BARE;

    if (templ)
    {
        opts.flags |= GIT_REPOSITORY_INIT_EXTERNAL_TEMPLATE;
        opts.template_path = templ;
    }

    if (gitdir)
    {
        /* if you specified a separate git directory, then initialize
         * the repository at that path and use the second path as the
         * working directory of the repository (with a git-link file)
         */
        opts.workdir_path = dir;
        dir = gitdir;
    }

    if (shared != 0)
        opts.mode = shared;

    return opts;
}

void create_initial_commit(git_repository * repo) {
    git_signature *sig;
    git_index *index;
    git_oid tree_id, commit_id;
    git_tree *tree;


    /** First use the config to initialize a commit signature for the user. */

    //check_lg2(git_signature_default(&sig, repo),"Unable to create a commit signature.","Perhaps 'user.name' and 'user.email' are not set");

    check_lg2(git_signature_default(&sig, repo),"Could not create commit signature","");
    /* Now let's create an empty tree for this commit */


    check_lg2(git_repository_index(&index, repo),"Could not open repository index", "");

    /**
     * Outside of this example, you could call git_index_add_bypath()
     * here to put actual files into the index.  For our purposes, we'll
     * leave it empty for now.
     */

    check_lg2(git_index_write_tree(&tree_id, index),"Unable to write initial tree from index", "");
    git_index_free(index);
    check_lg2(git_tree_lookup(&tree, repo, &tree_id),"Could not look up initial tree", "");

    /**
     * Ready to create the initial commit.
     *
     * Normally creating a commit would involve looking up the current
     * HEAD commit and making that be the parent of the initial commit,
     * but here this is the first commit so there will be no parent.
     */

    check_lg2(git_commit_create_v(&commit_id, repo, "HEAD", sig, sig,NULL, "Initial project commit", tree, 0),"Could not create the initial commit", "");

    /** Clean up so we don't leak memory. */

    git_tree_free(tree);
    git_signature_free(sig);
}
enum index_mode {
    INDEX_NONE,
    INDEX_ADD,
};

struct index_options {
    int dry_run;
    int verbose;
    git_repository *repo;
    enum index_mode mode;
    int add_update;
};

static int login_tries = 1;
static bool is_cred_cached = false;
int credentials_cb(git_cred ** out, const char *url, const char *username_from_url,
    unsigned int allowed_types, void *payload)
{
    int error;
    static std::string user, pass;

    /*
     * Ask the user via the UI. On error, store the information and return GIT_EUSER which will be
     * bubbled up to the code performing the fetch or push. Using GIT_EUSER allows the application
     * to know it was an error from the application instead of libgit2.
     */
    if (!is_cred_cached)
    {
        QInputDialog inp;
        bool ok = false;
        if (login_tries != 1) {
            QMessageBox msgWarning;
            msgWarning.setText("Invalid username or password. Please try again");
            msgWarning.setIcon(QMessageBox::Warning);
            msgWarning.setWindowTitle("Authentication Failed!");
            msgWarning.exec();
        }
        QDialog dialog(nullptr);
        dialog.setWindowTitle("Github Login");
        QFormLayout form(&dialog);

        QLineEdit *userfield = new QLineEdit(&dialog);
        QString userlabel = QString("Username: ");
        form.addRow(userlabel, userfield);
        QLineEdit *passfield = new QLineEdit(&dialog);
        passfield->setEchoMode(QLineEdit::Password);
        QString passlabel = QString("Password: ");
        form.addRow(passlabel, passfield);

        QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                                   Qt::Horizontal, &dialog);
        form.addRow(&buttonBox);
        QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
        QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

        if (dialog.exec() == QDialog::Accepted) {
            user = userfield->text().toStdString();
            pass = passfield->text().toStdString();
            ok = true;
        }
        else {
            ok = false;
        }
        if (!ok) return -1;

        login_tries++;
        delete userfield;
        delete passfield;
    }
    return git_cred_userpass_plaintext_new(out, user.c_str(), pass.c_str());
}
bool Project::push() {
//    lg2_add();
    git_libgit2_init();
    login_tries = 1;
    git_remote * remote = NULL;
    char * refspec = (char*)"refs/heads/master";
    const git_strarray refspecs = { &refspec,1 };
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
    if(error)
        goto cleanup;

    /* Fetch objects from remote repository
     * Direct pull is not available via libgit2
     */
    git_fetch_init_options(&fetch_opts, GIT_FETCH_OPTIONS_VERSION);
    fetch_opts.callbacks.credentials = credentials_cb;
    error = git_remote_fetch( remote, NULL, &fetch_opts, NULL );
    if(error)
        goto cleanup;
    // cache the credentials
    is_cred_cached = true;

    /* Merge fetched objects with local branch
     * It will update index and current working area
     */
    error = (git_reference_lookup(&theirs_ref, repo, "refs/remotes/origin/master") != GIT_OK)
         || (git_annotated_commit_from_ref(heads, repo, theirs_ref) != GIT_OK)
         || (git_merge(repo, (const git_annotated_commit **)heads, 1, &merge_opts, &checkout_opts) != GIT_OK);

    if(error)
        goto cleanup;

    /* Get the needed ref, index, sign and tree
     */
    error = (git_repository_head(&head_ref, repo))
         || (git_repository_index(&index, repo))
         || (git_signature_default(&signature, repo))
         || (git_index_write_tree(&tree_oid, index))
         || (git_tree_lookup(&tree, repo, &tree_oid));

    if(error)
        goto cleanup;

    /* Commit the merge and cleanup repo state
     */
    error = (git_reference_peel((git_object **)&parents[0], head_ref, GIT_OBJECT_COMMIT))
         || (git_commit_lookup(&parents[1], repo, git_annotated_commit_id(heads[0])))
         || (git_commit_create(&id, repo, "HEAD", signature, signature, NULL, "Merge commit - OpenOCRCorrect", tree, 2, (const git_commit **)parents))
         || (git_repository_state_cleanup(repo));

    if(error)
        goto cleanup;

    error = git_push_init_options(&push_opts, GIT_PUSH_OPTIONS_VERSION);
    push_opts.callbacks.credentials = credentials_cb;
    error = git_remote_push(remote, &refspecs, &push_opts);

    cleanup:
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

    if (error)
        return false;
    return true;//No errors
}

static int progress_cb(const char *str, int len, void *data)
{
    return 0;
}
static int update_cb(const char *refname, const git_oid *a, const git_oid *b, void *data)
{
    char a_str[GIT_OID_HEXSZ + 1], b_str[GIT_OID_HEXSZ + 1];
    (void)data;

    git_oid_fmt(b_str, b);
    b_str[GIT_OID_HEXSZ] = '\0';

    if (git_oid_iszero(a)) {
        printf("[new]     %.20s %s\n", b_str, refname);
    }
    else {
        git_oid_fmt(a_str, a);
        a_str[GIT_OID_HEXSZ] = '\0';
        printf("[updated] %.10s..%.10s %s\n", a_str, b_str, refname);
    }

    return 0;
}
static int transfer_progress_cb(const git_transfer_progress *stats, void *payload)
{
    (void)payload;

    if (stats->received_objects == stats->total_objects) {

    }
    else if (stats->total_objects > 0) {


    }
    return 0;
}
void Project::fetch() {

    QDir::setCurrent(mProjectDir.absolutePath());
    QProcess::execute("git pull");
//	QProcess::execute("git reset --hard origin/master");
    QDir::setCurrent(mProjectDir.absolutePath()+"/CorrectorOutput/");

}


bool Project::commit(std::string message) {
    lg2_add();
    git_signature *sig;
    git_index *index;
    git_oid tree_id, commit_id;
    git_tree *tree;

    git_object *parent = NULL;
    git_reference *ref = NULL;
    /** First use the config to initialize a commit signature for the user. */

    //check_lg2(git_signature_default(&sig, repo),"Unable to create a commit signature.","Perhaps 'user.name' and 'user.email' are not set");
    int klass = check_lg2(git_signature_now(&sig, mName.c_str(), mEmail.c_str()),"Could not create signature","");
    if (klass > 0) {
        if(sig)
            git_signature_free(sig);

    }
    klass = check_lg2(git_revparse_ext(&parent, &ref, repo, "HEAD"),"Head not found","");
    if (klass > 0) {
        return 0;
    }
    /* Now let's create an empty tree for this commit */

    klass = check_lg2(git_repository_index(&index, repo), "Could not open repository index", "");
    if (klass > 0) {
        return 0;
    }

    /**
     * Outside of this example, you could call git_index_add_bypath()
     * here to put actual files into the index.  For our purposes, we'll
     * leave it empty for now.
     */

    klass = check_lg2(git_index_write_tree(&tree_id, index), "Could not write tree", "");;
    if (klass > 0) {
        return 0;
    }

    klass = check_lg2(git_index_write(index), "Could not write index", "");;
    if (klass > 0) {
        return 0;
    }

    klass = check_lg2(git_tree_lookup(&tree, repo, &tree_id), "Error looking up tree", "");
    if (klass > 0) {
        return 0;
    }

    klass = check_lg2(git_signature_default(&sig, repo), "Error creating signature", "");
    if (klass > 0) {
        return 0;
    }

    /**
     * Ready to create the initial commit.
     *
     * Normally creating a commit would involve looking up the current
     * HEAD commit and making that be the parent of the initial commit,
     * but here this is the first commit so there will be no parent.
     */

    klass = check_lg2(git_commit_create_v(&commit_id, repo, "HEAD", sig, sig, NULL, message.c_str(), tree, parent ? 1 : 0, parent), "Could not create commit", "");
    if (klass > 0) {
        git_tree_free(tree);
        git_signature_free(sig);
        git_index_free(index);
        return 0;
    }

    /** Clean up so we don't leak memory. */

    git_tree_free(tree);
    git_signature_free(sig);
    git_index_free(index);
    return 1;
}
bool Project::add_config() {
    git_config * cfg = NULL;
    git_config* sys_cfg = NULL;
    git_config_entry* entry = NULL;
    std::string user = "";
    std::string email = "";

    int error = git_repository_config(&cfg, repo);
    check_lg2(error, "Couldn't open config file", "");

    error = git_config_open_level(&sys_cfg, cfg, GIT_CONFIG_LEVEL_SYSTEM);
    check_lg2(error, "Couldn't open system level config", "");

    error = git_config_get_entry(&entry, sys_cfg, "user.name");
    check_lg2(error, "Couldn't get user.name", "");
    std::string str = "";
    if (entry) {
        str = entry->value;
    }
    else {
        //add username
        bool ok = false;
        QString quser = QInputDialog::getText(nullptr, QWidget::tr("Enter name:"),
            QWidget::tr("Username:"), QLineEdit::Normal,
            " ", &ok);

        str = quser.toStdString();
        error = git_config_set_string(sys_cfg, "user.name", (char*)str.c_str());
        check_lg2(error, "Could not set user.name", "");
        if (!ok || error < 0)
            return false;

    }
    mName = str;

    error = git_config_get_entry(&entry, sys_cfg, "user.email");
    check_lg2(error, "Couldn't get user.email", "");
    if (entry) {
        str = entry->value;
    }
    else
    {
        //add username
        bool ok = false;
        QString quser = QInputDialog::getText(nullptr, QWidget::tr("Enter email:"),
            QWidget::tr("Email:"), QLineEdit::Normal,
            " ", &ok);
        std::string str = quser.toStdString();
        error = git_config_set_string(sys_cfg, "user.email", (char*)str.c_str());
        check_lg2(error, "Could not set user.email", "");
        if (!ok || error < 0)
            return false;

    }
    mEmail = str;
    git_config_free(cfg);
    git_config_free(sys_cfg);
    return true;
}
int match_cb(const char *path, const char *spec, void *payload) {

    //match_data *d = (match_data*)payload;
    /*
     * return 0 to add/remove this path,
     * a positive number to skip this path,
     * or a negative number to abort the operation.
     */
    std::string spath = path;
    return 0;
}
void Project::lg2_add(QString workingFolder) {
    const char * paths[] = { "/Dicts" ,"/Comments","/Images", workingFolder.toUtf8().constData()};
    git_strarray arr = { (char**)paths,1 };
    git_index *idx = NULL;
    int error = git_repository_index(&idx, repo);
    check_lg2(error, "Error Could not open index", "");
    error = git_index_add_all(idx, &arr, GIT_INDEX_ADD_DEFAULT, match_cb, nullptr);
    check_lg2(error, "Error could not add", "");
    error = git_index_update_all(idx, &arr, match_cb, nullptr);
    check_lg2(error, "Error could not update", "");
    git_index_write(idx);
    git_index_free(idx);
}
void Project::lg2_add() {
    const char * paths[] = { "/*"};
    git_strarray arr = { (char**)paths,1 };
    git_index *idx = NULL;
    int error = git_repository_index(&idx, repo);
    check_lg2(error, "Error Could not open index", "");
    error = git_index_add_all(idx, &arr, GIT_INDEX_ADD_DEFAULT, match_cb, nullptr);
    check_lg2(error, "Error could not add", "");
    error = git_index_update_all(idx, &arr, match_cb, nullptr);
    check_lg2(error, "Error could not update", "");
    git_index_write(idx);
    git_index_free(idx);
}
void Project::add_and_commit() {

}
Filter * Project::getFilter(QString str) {
    for (auto * p : mFilters) {
        if (p->name() == str) {
            return p;
        }
    }
    return nullptr;
}
QString Project::get_stage() {
    auto c = doc.child("Project").child("Metadata");
    QString stage = c.child("Stage").child_value();
    return stage;
}
QString Project::get_version() {
    auto c = doc.child("Project").child("Metadata");
    QString version = c.child("Version").child_value();
    return version;
}
QString Project::get_pmEmail() {
    auto c = doc.child("Project").child("Metadata");
    QString stage = c.child("ProjectManagerEmail").child_value();
    return stage;
}
QString Project::get_bookId() {
    auto c = doc.child("Project").child("Metadata");
    QString version = c.child("BookId").child_value();
    return version;
}
QString Project::get_setId() {
    auto c = doc.child("Project").child("Metadata");
    QString stage = c.child("SetId").child_value();
    return stage;
}
QString Project::get_repo() {
    auto c = doc.child("Project").child("Metadata");
    QString stage = c.child("RepositoryLink").child_value();
    return stage;
}

void Project::open_git_repo() {
    std::string dir = mProjectDir.path().toStdString();
    QString gitpath = mProjectDir.path() + "/.git";
    QDir gitdir(gitpath);
    git_signature * out;


    if (gitdir.exists())
    {
        check_lg2(git_repository_open(&repo, dir.c_str()), "Failed to Open", "");
        add_config();
    }
    else
    {
        check_lg2(git_repository_init(&repo, dir.c_str(),0), "Failed to Open", "");
        add_config();
        lg2_add();
        create_initial_commit(repo);

    }
}

#ifdef _WIN32
int Project::findNumberOfFilesInDirectory(std::string path)
{
    FILE* fp;
    int file_count;
    replace(path.begin(), path.end(), '/', '\\');
    
 //   std::string command = R"(dir /b /a-s-d ")" + path + R"(" | find /c /v "")"; //  non-recursive count -> files in sub-directories will not be counted
    std::string command = R"(dir /b /s /a-s-d ")" + path + R"(" | find /c /v "")"; // recursive count
    fp = _popen(command.c_str(), "r");
    if (!fp) {
        std::cout << "Failed to count files at " << path << std::endl;
        return -1;
    }

    fscanf_s(fp, "%d", &file_count);

    _pclose(fp);
    return file_count;
}
#endif

#ifdef __unix__
int Project::findNumberOfFilesInDirectory(std::string path)
{
    FILE* fp;
    int file_count;

//    std::string command = R"(find ")" + path + R"(" -maxdepth 1 -not -path '*/\.*' -type f | wc -l)"; //  non-recursive count -> files in sub-directories will not be counted
    std::string command = R"(find ")" + path + R"(" -not -path '*/\.*' -type f | wc -l)"; // recursive count
    
    fp = popen(command.c_str(), "r");
    if (!fp) {
        std::cout << "Failed to count files at " << path << std::endl;
        return -1;
    }
    fscanf(fp, "%d", &file_count);
    pclose(fp);
    return file_count;

}
#endif
