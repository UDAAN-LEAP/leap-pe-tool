#include "pdfhandling.h"
#include <QPrintDialog>
#include <QPrinter>

PDFHandling::PDFHandling(QObject *parent,
                         QTextDocument *document,
                         QPrinter *printer,
                         QString html_contents
                         ) : QObject{parent}
{
    this->html_contents = html_contents;
    this->document = document;
    this->printer = printer;
}

void PDFHandling::SavePDF()
{
    //document->setHtml(html_contents);
    document->setPageSize(printer->pageRect().size());
    document->print(printer);
    emit finishedSavingPDF();
}
