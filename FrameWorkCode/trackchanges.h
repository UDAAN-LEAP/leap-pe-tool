#ifndef TRACKCHANGES_H
#define TRACKCHANGES_H

#include <QObject>
#include <QTextDocument>
#include <QDebug>
#include <vector>
#include <tuple>
#include <set>
#include <unordered_set>
#include <QFile>
#include <QTextStream>
#include <QTextCursor>

class TrackChanges : public QObject
{
    Q_OBJECT
public:
    explicit TrackChanges(QObject *parent = nullptr);

private:
    QString currentProjectAbsPath;
    QString currentPageAbsPath;

    std::vector<std::tuple<int,std::string>> wordsTracked;
	bool isCurrentFileWritable;
	std::string pageTitle;

	std::unordered_set<std::string> punctuations;
	QString endOfWordChars;

	QTextDocument *currentDocument;

	QVector<QPair<int,QString>> getValidWords(const QString &);

private slots:
    void projectChanged(const QString &);

    void currentPageChanged(const QString &, bool, QTextDocument *);

    void trackWords();

	void handleTimeOut(QTextDocument *);

signals:
    void finished();
};

#endif // TRACKCHANGES_H
