#pragma once
#include<QFile>
#include"Filters.h"
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
	void lg2_add();
	void commit(std::string message);
	void push();
	bool add_config();
	void fetch();
	void enable_push();
	void AddTemp(Filter * f, QFile &pFile,QString prefix);

	~Project() {
		for (auto p : mFiles) {
			delete p;
		}
		if(repo)
		git_repository_free(repo);
	}
	void add_and_commit();
	void disable_push();
	QString get_stage();
	Filter * getFilter(QString name);
private:
	QVector<QFile*> mFiles;
	QVector<Filter*> mFilters;
	TreeItem * mRoot=nullptr;
	TreeModel * mTreeModel=nullptr;
	QString mFileName;
	QString mProjectName;
	std::string mXML;
	QDir mProjectDir;
	std::string mName = "";
	std::string mEmail = "";
    pugi::xml_document doc;
    git_repository * repo=nullptr;
};
