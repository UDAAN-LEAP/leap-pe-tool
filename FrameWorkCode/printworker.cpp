#include "printworker.h"

#include <QTextDocument>
#include <QPrinter>

/*!
 * \fn PrintWorker::PrintWorker
 * \brief This is the constructor which sets a data member to the HTML text passed to it
 * \param parent
 * \param str
 */
PrintWorker::PrintWorker(QObject *parent, const QString &str)
    : QObject{parent}
{
    this->fullHtml = QString(str);
}

/*!
 * \fn PrintWorker::~PrintWorker
 * \brief Destructor
 */
PrintWorker::~PrintWorker()
{
    delete doc;
}

/*!
 * \fn PrintWorker::printPDF
 * \brief It prints the PDF in a file
 */
void PrintWorker::printPDF()
{
    doc = new QTextDocument(this);
    doc->setHtml(fullHtml);
    doc->print(printer);
    emit finishedPrintingPDF();
}
