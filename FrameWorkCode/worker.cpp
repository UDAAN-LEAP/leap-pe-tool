#include "worker.h"
#include <regex>
Worker::Worker(QObject *parent, MainWindow *mw) : QObject(parent)
{
    mainWin = mw;
}

void Worker::doSaveBackend()
{
    qDebug() << "Started Backend Task";
    mainWin->SaveFile_Backend();
    qDebug() << "Completed Backend Task";
    emit finished();
}
