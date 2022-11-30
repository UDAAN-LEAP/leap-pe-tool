#include "printworker.h"

#include <QTextDocument>
#include <QPrinter>

/*!
 * \fn PrintWorker::PrintWorker
 * params:
 * 1)QObject-parent 2)QString->str
 *
 * brief:
 * Takes string as input and stores it as an html(inside the parent itself)
 */
PrintWorker::PrintWorker(QObject *parent, const QString &str)
	: QObject{parent}
{
	this->fullHtml = QString(str);
}
/*!
 *Destructor.
 */
PrintWorker::~PrintWorker()
{
	delete doc;
}
/*!
 * \fn PrintWorker::printPDF
 * brief:
 * 1)creats the new Text Document and stores the value inside doc
 * 2) Converts the text to html format
 * 3)Prints the document to the given printer
 * 4) emit the signal when the pdf is generated.
 */
void PrintWorker::printPDF()
{
	doc = new QTextDocument(this);
	doc->setHtml(fullHtml);
	doc->print(printer);
	emit finishedPrintingPDF();
}
