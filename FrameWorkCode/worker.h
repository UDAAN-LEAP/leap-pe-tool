#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include "mainwindow.h"

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr, MainWindow *mw = nullptr);

private:
    MainWindow *mainWin;

signals:
    void finished();

public slots:
    void doSaveBackend();
};

#endif // WORKER_H
