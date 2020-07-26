#pragma once
#include<QFile>
#include"Filters.h"
#include "TreeItem.h"
#include "TreeModel.h"
#include <QDir>
#include <pugixml.hpp>
class Project {
public:
	void parse_project_xml(rapidxml::xml_document<> & pDoc);
	void process_node(rapidxml::xml_node<> * pNode, TreeItem * parent);
	void process_xml(QFile & pPath);
	void process_node(pugi::xml_node * pNode, TreeItem * parent);
	void addFile(Filter &f, QFile & pFile);
	void getFile(const QString & pFileName);
	void save_xml();
	QDir GetDir();
	void removeFile(QModelIndex & idx, Filter & pFilter, QFile & pFile);
	pugi::xml_node FindFile(QFile & file, pugi::xml_node  & n);
	TreeModel * getModel();
	~Project() {
		for (auto p : mFiles) {
			delete p;
		}
	}
private:
	QVector<QFile*> mFiles;
	QVector<Filter*> mFilters;
	TreeItem * mRoot;
	TreeModel * mTreeModel;
	QString mFileName;
	QString mProjectName;
	std::string mXML;
	QDir mProjectDir;
	pugi::xml_document doc;
	
};