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
    void lg2_add(QString workingFolder);
    void lg2_add();
    bool commit(std::string message);
    bool push();
	bool add_config();
	void fetch();
    bool enable_push(bool increment);
    void enable_push();
	void AddTemp(Filter * f, QFile &pFile,QString prefix);

	~Project() {
		for (auto p : mFiles) {
			delete p;
		}
        for (auto f : mFilters) {
                    delete f;
                }
		if(repo)
		git_repository_free(repo);
	}
	void add_and_commit();
    void disable_push();
	QString get_stage();
    QString get_version();
    QString get_pmEmail();
    QString get_bookId();
    QString get_setId();
    QString get_repo();
	Filter * getFilter(QString name);
	bool isProjectOpen() {
		return m_isOpen;
	}
	void setProjectOpen(bool open) {
		m_isOpen = open;
	}
private:
	bool m_isOpen = false;
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
