#ifndef HANDLEBBOX_H
#define HANDLEBBOX_H

#include <QtCore>

//class QFile;
class QTextDocument;
//class QVector;
//class QPair;
//class QString;

class HandleBbox
{
public:
	HandleBbox();
	~HandleBbox();
	QTextDocument *loadFileInDoc(QFile *f);
	void insertBboxes(QFile *f);
	int blockCount = -1;
	QVector<QPair<QString,QString> > bboxes;

private:
	QTextDocument *doc;

	void storeBboxes(QFile *f);
};

#endif // HANDLEBBOX_H
