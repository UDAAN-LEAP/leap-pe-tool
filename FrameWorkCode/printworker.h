#ifndef PRINTWORKER_H
#define PRINTWORKER_H

#include <QObject>

class QTextDocument;
class QPrinter;

class PrintWorker : public QObject
{
	Q_OBJECT
public:
	explicit PrintWorker(QObject *parent = nullptr, const QString &str = "");
	~PrintWorker();
	QPrinter *printer = nullptr;

private:
	// data members
	QString fullHtml = "";
	QTextDocument *doc = nullptr;

public slots:
	void printPDF();

signals:
	void finishedPrintingPDF();
};

#endif // PRINTWORKER_H
