#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include "Project.h"
#include <set>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr,
                    Project* mProject = nullptr,
                    QString gCurrentPageName = "",
                    QString gCurrentDirName = "",
                    QString gDirTwoLevelUp = "",
                    QString s1 = "",
                    QString s2 = "",
                    std::map<std::string, std::string> CPair_editDis = {},
                    std::map<std::string, std::set<std::string> >* CPairs = nullptr,
                    std::map<QString, QString> filestructure_fw = {},
                    QSet<QString>* dict_set1 = {},
                    QString mRole = "Corrector");

private:
    QString gCurrentPageName;
    QString gCurrentDirName;
    QString gDirTwoLevelUp;
    QString s1, s2;
    Project* mProject;
    std::map<std::string, std::string> CPair_editDis;
    std::map<QString, QString> filestructure_fw;
    std::map<std::string, std::set<std::string> >* CPairs;
    QSet<QString>* dict_set1;
    QString mRole;

signals:
    void finished();

public slots:
    void doSaveBackend();
    void addCpair();
};

#endif // WORKER_H

