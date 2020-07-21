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
void Project::parse_project_xml(rapidxml::xml_document<>& pDoc)
{
	
}

void Project::process_node(rapidxml::xml_node<>* pNode,TreeItem * parent)
{
	if (pNode) {
		std::string node_name = pNode->name();
		if (node_name == "ItemGroup") {
			process_node(pNode->first_node(),parent);
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
			TreeItem * filter_node = new TreeItem(str,NodeType::FILTER,parent);
			filter_node->SetFilter(filter);
			parent->append_child(filter_node);
			process_node(pNode->next_sibling(),parent);
		}
		if (node_name == "File") {

			/*
				Example:
				<File Include="page-1.jpeg">
					<Filter>Image</Filter>
				</File>
			*/
			std::string filtername =  pNode->first_node()->value();
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
			TreeItem *nodefile = new TreeItem(filename,_FILETYPE,node);
			node->append_child(nodefile);
			nodefile->SetFile(mFiles.back());
			process_node(pNode->next_sibling(), parent);
		}
	}
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
			QString val = QString(pNode->attribute("Include").value());
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
	if (mRoot) delete mRoot;
	
	pFile.open(QIODevice::ReadOnly);
	QFileInfo info;
	info.setFile(pFile);
	std::string path = pFile.fileName().toStdString();
	pugi::xml_parse_result res =  doc.load_file(path.c_str());
	
	mProjectDir = info.absoluteFilePath();
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
void Project::addFile(Filter &f,QFile & pFile)
{
	auto node = doc.child("Project").child("ItemGroup").next_sibling();
	QString path = pFile.fileName();
	
	std::string str = path.toStdString();
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
		std::string str = mProjectDir.path().toStdString();
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