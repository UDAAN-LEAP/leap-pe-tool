#ifndef CRASHLOG_H
#define CRASHLOG_H

#endif // CRASHLOG_H
#include <QApplication>
#include <QtDebug>
#include <QFile>
#include <QTextStream>

namespace crashlog {

void myMessageHandler(QtMsgType type, const QMessageLogContext &, const QString & msg);


}
