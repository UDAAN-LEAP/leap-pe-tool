#pragma once
#include<QFile>
#include"Filters.h"
#include "3rdParty/RapidXML/rapidxml.hpp"
class TreeItem;
class TreeModel;

class Project {
public:
	void parse_project_xml(rapidxml::xml_document<> & pDoc);
	void process_node(rapidxml::xml_node<> * pNode);
	void addFile(QFile & pFile);
	void getFile(const QString & pFileName);
	TreeModel * getModel();
private:
	QVector<QFile> mFiles;
	QVector<Filter> mFilters;
	TreeItem * mRoot;
	TreeModel * mTreeModel;
	QString mFileName;
};