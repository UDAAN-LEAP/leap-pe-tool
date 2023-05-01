#ifndef THREADINGPUSH_H
#define THREADINGPUSH_H

#include <QObject>
#include <git2.h>
class threadingPush : public QObject
{
    Q_OBJECT
public:
    explicit threadingPush(QObject *parent = nullptr, git_repository *repo = nullptr, std::string user="", std::string pass ="", QString gDirTwoLevelUp="");
    int error;
private:
    git_repository *repo = nullptr;
    std::string mEmail;
    std::string mName;
    QString branchName;
signals:
    void finishedPush();
public slots:
    void ControlPush();
    bool fetch_n_merge();

};

#endif // THREADINGPUSH_H
