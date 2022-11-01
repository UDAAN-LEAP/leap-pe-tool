#include "printworker.h"

#include <QTextDocument>
#include <QPrinter>

PrintWorker::PrintWorker(QObject *parent, const QString &str)
	: QObject{parent}
{
	this->fullHtml = QString(str);
}

PrintWorker::~PrintWorker()
{
	delete doc;
}

void PrintWorker::printPDF()
{
	doc = new QTextDocument(this);
	doc->setHtml(fullHtml);
	doc->print(printer);
	emit finishedPrintingPDF();
}
