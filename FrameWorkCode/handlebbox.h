#ifndef HANDLEBBOX_H
#define HANDLEBBOX_H

//#include <QtCore>
#include <QVector>
#include <QString>
#include <QFile>
#include <QTextCursor>
#include <QTextStream>
#include <QRegularExpression>
#include <QTextDocument>
#include <QDebug>
#include <QTextBlock>

//class QFile;
class QTextDocument;
//class QVector;
//class QPair;
//class QString;

class HandleBbox
{
public:
	HandleBbox();
	HandleBbox(QTextDocument* doc);
	~HandleBbox();
	QTextDocument *loadFileInDoc(QFile *f);
	void insertBboxes(QFile *f);
	int blockCount = -1;
	QVector<QPair<QString,QString> > bboxes;

private:
	QTextDocument *doc;
	bool docIsPassed;
	void storeBboxes(QFile *f);
};

#endif // HANDLEBBOX_H
