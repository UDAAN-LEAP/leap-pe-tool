#pragma once
#include<QFile>
#include"Filters.h"
#include "3rdParty/RapidXML/rapidxml.hpp"
#include "TreeItem.h"
#include "TreeModel.h"
#include <QDir>
class Project {
public:
	void parse_project_xml(rapidxml::xml_document<> & pDoc);
	void process_node(rapidxml::xml_node<> * pNode, TreeItem * parent);
	void process_xml(QFile & pPath);
	void addFile(QFile & pFile);
	void getFile(const QString & pFileName);
	TreeModel * getModel();
	~Project() {
		for (auto p : mFiles) {
			delete p;
		}
	}
private:
	QVector<QFile*> mFiles;
	QVector<Filter> mFilters;
	TreeItem * mRoot;
	TreeModel * mTreeModel;
	QString mFileName;
	QString mProjectName;
	std::string mXML;
	QDir mProjectDir;
	rapidxml::xml_document<> mDoc;
};