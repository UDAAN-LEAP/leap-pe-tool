#ifndef GLOBALREPLACEWORKER_H
#define GLOBALREPLACEWORKER_H

#include <QObject>
#include <QMap>
#include "handlebbox.h"

class QTextBrowser;

class GlobalReplaceWorker : public QObject
{
    Q_OBJECT
public:
    explicit GlobalReplaceWorker(
            QObject *parent = nullptr,
            QList<QString> *filesChangedUsingGlobalReplace = nullptr,
            QMap<QString, QString> *mapOfReplacements = nullptr,
            QMap<QString, QString> globalReplacementMap = {},
            QMap<QPair<QString,QString>,QString> globalReplacementMapAfterCheck = {},
            QMap<QString, QString> replaceInAllPages_Map = {},
            QMap<QString, QString> replaceInUneditedPages_Map = {},
            QString currentFileDirectory = "",
            QString gDirTwoLevelUp = "",
            QString gCurrentPageName = "",
            int numOfChangedWords = 0,
            int check = 0,
            int *r1 = nullptr,
            int *r2 = nullptr,
            int *x1 = nullptr,
            int *files = nullptr,
            int pairMap = 1
            );
    int pairMap;

private:
    QMap<QString, QString> globalReplacementMap;
    QMap<QString, QString> globalReplacementMap2;
    QMap<QPair<QString,QString>,QString> globalReplacementMapAfterCheck;
    QList<QString> *filesChangedUsingGlobalReplace;
    QMap<QString, QString> *mapOfReplacements;
    QMap<QString, QString> replaceInAllPages_Map;
    QMap<QString, QString> replaceInUneditedPages_Map;

    QString currentFileDirectory;
    QString gDirTwoLevelUp;
    QString gCurrentPageName;
    QString editedFilesLogPath;
    int numOfChangedWords, check, *r1, *r2, *x1, *files;

    int writeGlobalCPairsToFiles(QString file_path, QMap <QString, QString> globalReplacementMap, QTextDocument* doc);
    bool isStringInFile(QString file_path, QString searchString);
    HandleBbox *handleBbox = nullptr;

public slots:
    void replaceWordsInFiles();
    void writeLogs();

signals:
    void finishedReplacingWords();
    void finishedWritingLogs();
    void changeProgressBarValue(int);
};

#endif // GLOBALREPLACEWORKER_H
