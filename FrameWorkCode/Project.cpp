#include "Project.h"
#include "TreeItem.h"
#include "TreeModel.h"
#include <QDir>
#include <QFileInfo>
#include <QTextStream>
#include <sstream>
#include <ostream>
#include <iostream>
#include "3rdParty/RapidXML/rapidxml_print.hpp"
#include <Windows.h>
#include <debugapi.h>
#include <pugixml.hpp>
#include "lg2_common.h"
void Project::parse_project_xml(rapidxml::xml_document<>& pDoc)
{
	
}

void Project::process_node(rapidxml::xml_node<>* pNode, TreeItem * parent)
{
	if (pNode) {
		std::string node_name = pNode->name();
		if (node_name == "ItemGroup") {
			process_node(pNode->first_node(), parent);
		}
		if (node_name == "Filter")
		{
			/*   Example
				 <Filter Include="Image">
					<Extensions>jpeg;jpg;png;</Extensions>
				 </Filter>
			*/
			std::string filter_name = pNode->first_attribute("Include")->value();
			std::string filter_exts = pNode->first_node()->value();

			Filter *filter = new Filter(filter_name, filter_exts);
			mFilters.push_back(filter);
			QString str;
			str = str.fromStdString(filter_name);
			//mFilters.push_back(filter_name);
			TreeItem * filter_node = new TreeItem(str, NodeType::FILTER, parent);
			filter_node->SetFilter(filter);
			parent->append_child(filter_node);
			process_node(pNode->next_sibling(), parent);
		}
		if (node_name == "File") {

			/*
				Example:
				<File Include="page-1.jpeg">
					<Filter>Image</Filter>
				</File>
			*/
			std::string filtername = pNode->first_node()->value();
			QString qfilter;
			qfilter = qfilter.fromStdString(filtername);
			auto node = mRoot->find(qfilter);
			QString val = QString(pNode->first_attribute("Include")->value());
			QFileInfo info1(val);

			auto path_ = info1.path();
			QString fpath = "";
			if (info1.isRelative())
				fpath = QFileInfo(mProjectDir.absolutePath()).absoluteDir().absolutePath() + "/" + info1.fileName();
			else
				fpath = val;
			QFileInfo fileinfo(fpath);
			QFile *f = new QFile(fpath);
			mFiles.push_back(f);
			auto filename = fileinfo.fileName();
			TreeItem *nodefile = new TreeItem(filename, _FILETYPE, node);
			node->append_child(nodefile);
			nodefile->SetFile(mFiles.back());
			process_node(pNode->next_sibling(), parent);
		}
	}
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
			process_node(&pNode->first_child(), parent);
		}
		if (node_name == "Filter")
		{
			/*   Example
				 <Filter Include="Image">
					<Extensions>jpeg;jpg;png;</Extensions>
				 </Filter>
			*/
			
			std::string filter_name = pNode->attribute("Include").as_string();;
			auto ch = pNode->child("Extensions");
			std::string filter_exts =  ch.child_value();

			Filter *filter = new Filter(filter_name, filter_exts);
			mFilters.push_back(filter);
			QString str;
			str = str.fromStdString(filter_name);
			//mFilters.push_back(filter_name);
			TreeItem * filter_node = new TreeItem(str, NodeType::FILTER, parent);
			filter_node->SetFilter(filter);
			parent->append_child(filter_node);
			process_node(&pNode->next_sibling(), parent);
		}
		if (node_name == "File") {

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
			process_node(&pNode->next_sibling(), parent);
		}
	}
}
/*
* Give XML file path and the content will be stored inside the class
* and processed by rapidxml
*/
void Project::process_xml(QFile & pFile) {
	if (mTreeModel)delete mTreeModel;
	/*if (mRoot) delete mRoot;*/
	
	pFile.open(QIODevice::ReadOnly);
	QFileInfo info;
	info.setFile(pFile);
	std::string path = pFile.fileName().toStdString();
	pugi::xml_parse_result res =  doc.load_file(path.c_str());
	
	mProjectDir = info.absoluteDir();
	mFileName = info.absoluteFilePath();
	mXML = pFile.readAll().toStdString();
	mDoc.parse<0>((char*)mXML.c_str());
	//process_node(mDoc.first_node());
	auto first = mDoc.first_node("Project");
	auto attr  = first->first_attribute("name");
	std::string project_name = attr->value();
	mProjectName = mProjectName.fromStdString(project_name);
	TreeItem * root = new TreeItem(mProjectName,FOLDER);
	auto child = doc.child("Project");

	mRoot = root;
	for (pugi::xml_node child : doc.child("Project")) {
		process_node(&child, root);
	}
	
	mTreeModel = new TreeModel();
	mTreeModel->setRoot(root);
	mTreeModel->layoutChanged();
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

void Project::save_xml() {
	try {
		std::string str = mFileName.toStdString();
		bool isSaved = doc.save_file(str.c_str());
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << "Runtime error was: " << e.what() << std::endl;
	}
	catch (const rapidxml::parse_error& e)
	{
		std::cerr << "Parse error was: " << e.what() << std::endl;
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
	std::string name = "Nipun Ramani";
	std::string email = "ramaninipun@gmail.com";

	/** First use the config to initialize a commit signature for the user. */

	//check_lg2(git_signature_default(&sig, repo),"Unable to create a commit signature.","Perhaps 'user.name' and 'user.email' are not set");

	check_lg2(git_signature_now(&sig, name.c_str(), email.c_str()),"Could not create commit signature","");
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
int credentials_cb(git_cred **out, const char *url, const char *username_from_url,
	unsigned int allowed_types, void *payload)
{
	int error;
	std::string user, pass;

	/*
	 * Ask the user via the UI. On error, store the information and return GIT_EUSER which will be
	 * bubbled up to the code performing the fetch or push. Using GIT_EUSER allows the application
	 * to know it was an error from the application instead of libgit2.
	 */


	return git_cred_userpass_plaintext_new(out, user.c_str(), pass.c_str());
}
void push(git_repository * repo) {
	check_lg2(git_remote_set_pushurl(repo, "origin", "https://github.com/BhayanakMoth/TestProject.git"),"Could not set pushurl","");
	git_push_options options;
	git_remote * remote = NULL;
	char * refspec = (char*)"refs/heads/master";
	const git_strarray refspecs = { &refspec,1 };
	git_remote_callbacks cb;
	check_lg2(git_push_options_init(&options, GIT_PUSH_OPTIONS_VERSION), "Error initializaing options", "");

	options.callbacks.credentials = credentials_cb;
	
	check_lg2(git_remote_lookup(&remote, repo, "origin"),"Unable to lookup remote","");
	check_lg2(git_remote_push(remote, &refspecs, &options), "Error Pushing", "");
	
	return;
}
void commit(git_repository * repo,std::string message) {
	git_signature *sig;
	git_index *index;
	git_oid tree_id, commit_id;
	git_tree *tree;
	std::string name = "Nipun Ramani";
	std::string email = "ramaninipun@gmail.com";
	git_object *parent = NULL;
	git_reference *ref = NULL;
	/** First use the config to initialize a commit signature for the user. */

	//check_lg2(git_signature_default(&sig, repo),"Unable to create a commit signature.","Perhaps 'user.name' and 'user.email' are not set");
	git_revparse_ext(&parent, &ref, repo, "HEAD");
	check_lg2(git_signature_now(&sig, name.c_str(), email.c_str()), "Could not create commit signature", "");
	/* Now let's create an empty tree for this commit */

	check_lg2(git_repository_index(&index, repo), "Could not open repository index", "");

	/**
	 * Outside of this example, you could call git_index_add_bypath()
	 * here to put actual files into the index.  For our purposes, we'll
	 * leave it empty for now.
	 */

	check_lg2(git_index_write_tree(&tree_id, index), "Could not write tree", "");;
	check_lg2(git_index_write(index), "Could not write index", "");;
	check_lg2(git_tree_lookup(&tree, repo, &tree_id), "Error looking up tree", "");
	check_lg2(git_signature_default(&sig, repo), "Error creating signature", "");
	/**
	 * Ready to create the initial commit.
	 *
	 * Normally creating a commit would involve looking up the current
	 * HEAD commit and making that be the parent of the initial commit,
	 * but here this is the first commit so there will be no parent.
	 */

	check_lg2(git_commit_create_v(&commit_id, repo, "HEAD", sig, sig, NULL, message.c_str(), tree, parent ? 1 : 0, parent), "Could not create the initial commit", "");

	/** Clean up so we don't leak memory. */

	git_tree_free(tree);
	git_signature_free(sig);
	git_index_free(index);
	git_tree_free(tree);
}
void lg2_add(git_repository * repo) {
	git_index *index;
	git_strarray array = { 0 };
	index_options options = { 0 };
	check_lg2(git_repository_index(&index,repo), "Could not open repository index", "");
	check_lg2(git_index_add_all(index, nullptr, GIT_INDEX_ADD_DISABLE_PATHSPEC_MATCH, 0, 0),"Could not add files","");
	git_index_free(index);
}
void Project::add_and_commit() {
	
}
void Project::open_git_repo() {
	std::string dir = mProjectDir.path().toStdString();
	QString gitpath = mProjectDir.path() + "/.git";
	QDir gitdir(gitpath);
	git_signature * out;
	
	
	if (gitdir.exists())
	{
		check_lg2(git_repository_open(&repo, dir.c_str()), "Failed to Open", "");
		//lg2_add(repo);
		//commit(repo, "Commit after adding files.");
		push(repo);
	}
	else
	{
		check_lg2(git_repository_init(&repo, dir.c_str(),0), "Failed to Open", "");
		create_initial_commit(repo);
		lg2_add(repo);
	}
	git_repository_free(repo);
}