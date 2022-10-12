#pragma once
#include<QFile>
#include"Filters.h"
#include "TreeItem.h"
#include "TreeModel.h"
#include <QDir>
#include <pugixml.hpp>
#include <git2.h>
#include <string>
#include <diff_match_patch.h>
#include <qlist.h>
#include <QObject>

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
    bool push(QString branchName);
	bool add_config();
	bool add_git_config(); // New function which does not looks up the git configurations (regardless of any level)
	int fetch();
    bool enable_push(bool increment);
	void AddTemp(Filter * f, QFile &pFile,QString prefix);
    int findNumberOfFilesInDirectory(std::string);
    int LevenshteinWithGraphemes(QList<Diff> diffs);
    int GetGraphemesCount(QString string);
    int GetPageNumber(std::string localFilename, std::string *no, size_t *loc, QString *ext);
    static int clone(QString url_, QString path);

	~Project() {
		for (auto p : mFiles) {
			delete p;
		}
        for (auto f : mFilters) {
                    delete f;
                }
		if(repo)
        //git_repository_free(repo);
            ;
	}
	void add_and_commit();
    void set_stage_verifier();
    void set_stage(QString mRole);
    void set_verifier();
    void set_corrector();
	QString get_stage();
    QString get_version();
    QString get_configuration();
    void set_version(int);
    void set_configuration(QString val);
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
	static QString getCommmitID(git_commit *commit);
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
