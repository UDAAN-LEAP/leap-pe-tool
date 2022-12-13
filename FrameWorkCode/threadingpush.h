#ifndef THREADINGPUSH_H
#define THREADINGPUSH_H

#include <QObject>
#include <git2.h>
class threadingPush : public QObject
{
    Q_OBJECT
public:
    explicit threadingPush(QObject *parent = nullptr, git_repository *repo = nullptr);
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
};

#endif // THREADINGPUSH_H
