#ifndef LOADDATAWORKER_H
#define LOADDATAWORKER_H

#include <QObject>
#include <Project.h>
#include "slpNPatternDict.h"
#include "trieEditdis.h"

class LoadDataWorker : public QObject
{
    Q_OBJECT
public:
    explicit LoadDataWorker(
            QObject *parent = nullptr,
            Project* mProject = nullptr,
            QString mFilename = "",
            QString mFilename1 = "",
            map<string, string>* LSTM = nullptr,
            std::map<string, set<string> >* CPairs = nullptr,
            map<string, int>* Dict = nullptr,
            map<string, int>* GBook = nullptr,
            map<string, int>* IBook = nullptr,
            map<string, int>* PWords = nullptr,
            map<string, int>* ConfPmap = nullptr,
            vector<string>* vGBook = nullptr,
            vector<string>* vIBook = nullptr,
            trie* TDict = nullptr,
            trie* TGBook = nullptr,
            trie* TGBookP = nullptr,
            trie* TPWords = nullptr,
            trie* TPWordsP = nullptr,
            map<string, vector<int> >* synonym = nullptr,
            vector<vector<string> >* synrows = nullptr
            );
private:
    map<string, string>* LSTM;
    map<string, set<string> >* CPairs;
    map<string, int> *Dict, *GBook, *IBook, *PWords, *ConfPmap;
    vector<string> *vGBook, *vIBook;
    trie *TDict, *TGBook, *TGBookP, *TPWords, *TPWordsP;
    Project *mProject;
    QString mFilename1, mFilename;
    map<string, vector<int> >* synonym;
    vector<vector<string> >* synrows;

    bool loadDict(Project & project);
    void on_actionLoadDict_triggered();
    void on_actionLoadOCRWords_triggered();
    void on_actionLoadDomain_triggered();
    void on_actionLoadSubPS_triggered();
    void on_actionLoadConfusions_triggered();

public slots:
    void LoadData();

signals:
    void finishedLoadingData();
};

#endif // LOADDATAWORKER_H
