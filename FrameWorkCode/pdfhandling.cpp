#include "pdfhandling.h"
#include <QPrintDialog>
#include <QPrinter>


/*!
 * \fn PDFHandling::PDFHandling
 * \brief This is the constructor of PDFHandling classes and initializes the objects' pointers which are required to be the shared ones between multiple threads.
 * \param parent
 * \param document
 * \param printer
 * \param html_contents
 */
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

/*!
 * \fn PDFHandling::SavePDF
 * \brief This prints the PDF and asks the user where to print it.
 * \details The user can print it on paper or save the PDF in a file.
 */
void PDFHandling::SavePDF()
{
    document->setPageSize(printer->pageRect().size());
    document->print(printer);
    emit finishedSavingPDF();
}
