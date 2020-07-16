#include "Project.h"
#include "TreeItem.h"
#include "TreeModel.h"
#include <QDir>
#include <QFileInfo>
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

			Filter filter(filter_name, filter_exts);
			
			QString str;
			str = str.fromStdString(filter_name);
			//mFilters.push_back(filter_name);
			TreeItem * filter_node = new TreeItem(str,parent);
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
			QString path = QString(pNode->first_attribute("Include")->value());
			QString fpath= QFileInfo(mProjectDir.absolutePath()).absoluteDir().absolutePath()+"/"+path;
			QFileInfo fileinfo(fpath);
			QFile *f = new QFile(fpath);
			mFiles.push_back(f);
			auto filename = fileinfo.fileName();
			TreeItem *nodefile = new TreeItem(filename,node);
			node->append_child(nodefile);
			nodefile->SetFile(mFiles.back());
			process_node(pNode->next_sibling(), parent);
		}
	}
}
/*
* Give XML file path and the content will be stored inside the class
* and processed by rapidxml
*/
void Project::process_xml(QFile & pFile) {
	
	pFile.open(QIODevice::ReadOnly);
	QFileInfo info;
	info.setFile(pFile);
	
	mProjectDir = info.absoluteFilePath();
	mXML = pFile.readAll().toStdString();
	mDoc.parse<0>((char*)mXML.c_str());
	//process_node(mDoc.first_node());
	auto first = mDoc.first_node("Project");
	auto attr  = first->first_attribute("name");
	std::string project_name = attr->value();
	mProjectName = mProjectName.fromStdString(project_name);
	TreeItem * root = new TreeItem(mProjectName);
	mRoot = root;
	auto child = first->first_node();
	while (child) {
		process_node(child->first_node(), root);
		child = child->next_sibling();
	}
	mTreeModel = new TreeModel();
	mTreeModel->setRoot(root);
}
void Project::addFile(QFile & pFile)
{
}

void Project::getFile(const QString & pFileName)
{
}

TreeModel * Project::getModel() {
	return mTreeModel;
}