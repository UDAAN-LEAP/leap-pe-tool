#include "worker.h"
#include <regex>
Worker::Worker(QObject *parent, MainWindow *mw) : QObject(parent)
{
    mainWin = mw;
}

/*!
 * \fn Worker::doSaveBackend()
 * \brief This function calls SaveFile_Backend functions and emits finished() whenever the function completes
 *        executing.
 * \sa SaveFile_Backend()
 */
void Worker::doSaveBackend()
{
    qDebug() << "Started Backend Task";
    mainWin->SaveFile_Backend();
    qDebug() << "Completed Backend Task";
    emit finished();
}
