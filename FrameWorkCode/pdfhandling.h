#ifndef PDFHANDLING_H
#define PDFHANDLING_H

#include <QObject>
#include <QTextDocument>
#include <QPrinter>

class PDFHandling : public QObject
{
    Q_OBJECT
public:
    explicit PDFHandling(QObject *parent = nullptr,
                         QTextDocument *document = nullptr,
                         QPrinter *printer = nullptr,
                         QString html_contents = "");

private:
    QString html_contents;
    QTextDocument *document;
    QPrinter *printer;

public slots:
    void SavePDF();

signals:
    void finishedSavingPDF();

};

#endif // PDFHANDLING_H
