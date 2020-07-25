#pragma once
#include<QFile>
#include"Filters.h"
#include "3rdParty/RapidXML/rapidxml.hpp"
#include "TreeItem.h"
#include "TreeModel.h"
#include <QDir>
#include <pugixml.hpp>
#include <git2.h>
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
	void open_git_repo();
	~Project() {
		for (auto p : mFiles) {
			delete p;
		}
	}
	void add_and_commit();
private:
	QVector<QFile*> mFiles;
	QVector<Filter*> mFilters;
	std::vector<char *> allocated_nodes;
	std::vector< rapidxml::xml_document<>*> docs;
	TreeItem * mRoot;
	TreeModel * mTreeModel;
	QString mFileName;
	QString mProjectName;
	std::string mXML;
	QDir mProjectDir;
    pugi::xml_document doc;
	rapidxml::xml_document<> mDoc;
    git_repository * repo;
};
