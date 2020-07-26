#include "Project.h"
#include "TreeItem.h"
#include "TreeModel.h"
#include <QDir>
#include <QFileInfo>
#include <QTextStream>
#include <sstream>
#include <ostream>
#include <iostream>
#include <Windows.h>
#include <debugapi.h>
#include <pugixml.hpp>
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
	auto child = doc.child("Project");
	mProjectName = child.attribute("name").as_string();
	TreeItem * root = new TreeItem(mProjectName,FOLDER);

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