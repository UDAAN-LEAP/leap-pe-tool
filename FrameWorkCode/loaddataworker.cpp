#include "loaddataworker.h"

LoadDataWorker::LoadDataWorker(
        QObject *parent,
        Project* mProject,
        QString mFilename,
        QString mFilename1,
        map<string, string>* LSTM,
        std::map<string, set<string> >* CPairs,
        map<string, int>* Dict,
        map<string, int>* GBook,
        map<string, int>* IBook,
        map<string, int>* PWords,
        map<string, int>* ConfPmap,
        vector<string>* vGBook,
        vector<string>* vIBook,
        trie* TDict,
        trie* TGBook,
        trie* TGBookP,
        trie* TPWords,
        trie* TPWordsP,
        map<string, vector<int> >* synonym,
        vector<vector<string> >* synrows
        ) : QObject(parent)
{
    this->mProject = mProject;
    this->mFilename = mFilename;
    this->mFilename1 = mFilename1;
    this->LSTM = LSTM;
    this->CPairs = CPairs;
    this->Dict = Dict;
    this->GBook = GBook;
    this->IBook = IBook;
    this->PWords = PWords;
    this->ConfPmap = ConfPmap;
    this->vGBook = vGBook;
    this->vIBook = vIBook;
    this->TDict = TDict;
    this->TGBook = TGBook;
    this->TGBookP = TGBookP;
    this->TPWords = TPWords;
    this->TPWordsP = TPWordsP;
    this->synonym = synonym;
    this->synrows = synrows;
}

void LoadDataWorker::LoadData()
{
    on_actionLoadDict_triggered();       //sanskrit dictionary files are called
    //!GEROCR IEROCR PWords and CPair files are loaded and reflected in terminal
    on_actionLoadOCRWords_triggered();
    on_actionLoadDomain_triggered();
    on_actionLoadSubPS_triggered();
    on_actionLoadConfusions_triggered();
    QString filepath = (*mProject).GetDir().absolutePath() + "/Dicts/synonyms.csv" ;
    slpNPatternDict slnp;
    slnp.loadFileCSV(*synonym, *synrows, filepath.toUtf8().constData());
    emit finishedLoadingData();
}


/*!
 * \fn loadDict()
 * \param current project file location
 * \brief The path of the dictionary file is fetched and the files are returned in the map
 * these words are then fetched depending upon the word selected
 * \sa loadMap()
 */
bool LoadDataWorker::loadDict(Project & project) {
    slpNPatternDict slnp;
    QString localmFilename1 = project.GetDir().absolutePath() + "/Dicts/" + "Dict";
    if (!QFile::exists(localmFilename1)) return false;
    slnp.loadMap(localmFilename1.toUtf8().constData(), *Dict, "Dict");
    return true;
}

/*!
 * \fn on_actionLoadDict_triggered()
 * \brief The path of the dictionary file is fetched and the files are returned in the map
 * these words are then fetched depending upon the word selected
 * \sa loadDict()
 */
void LoadDataWorker::on_actionLoadDict_triggered()
{
    loadDict(*mProject);
}

/*!
 * \fn MainWindow::on_actionLoadOCRWords_triggered()
 * \brief Loads the OCR files
 * The path of the GEROCR and IEROCR file is fetched and the files are returned in the map which is again,
 * used as a suggestion depending upon the word selected
 * \sa LoadMapNV()
 */
void LoadDataWorker::on_actionLoadOCRWords_triggered()
{
    slpNPatternDict slnp;
    QString localmFilename1 = (*mProject).GetDir().absolutePath() + "/Dicts/" + "GEROCR";
    cout << localmFilename1.toUtf8().constData() << endl;
    slnp.loadMapNV(localmFilename1.toUtf8().constData(), *GBook, *vGBook, "GBook");
    localmFilename1 = mFilename1;
    cout << localmFilename1.toUtf8().constData() << endl;
    localmFilename1 = (*mProject).GetDir().absolutePath() + "/Dicts/" + "IEROCR";
    slnp.loadMapNV(localmFilename1.toUtf8().constData(), *IBook, *vIBook, "IBook");
    cout << (*GBook).size() << " " << (*IBook).size() << endl;

}

/*!
  \fn MainWindow::on_actionLoadDomain_triggered()
  \brief loads the common OCR files
 The path of the PWords file is fetched and the files are returned in the map which can be used
 for the suggestion feature
 \sa loadMapPWords()
 */
void LoadDataWorker::on_actionLoadDomain_triggered()
{
    QString localmFilename1 = (*mProject).GetDir().absolutePath() + "/Dicts/" + "/PWords";
    slpNPatternDict slnp;
    slnp.loadMapPWords(*vGBook, *vIBook, *PWords);
}

/*!
  \fn MainWindow::on_actionLoadSubPS_triggered()
  \brief the CPair files
    The path of the CPair files are fetched and the files are returned in the map which is returned
    to load the suggestions
  \sa loadmaptoTrie(), loadPwordsPatternstoTrie(), loadCPair()
 */
void LoadDataWorker::on_actionLoadSubPS_triggered()
{
    slpNPatternDict slnp;
    trieEditDis trie;
    size_t count = trie.loadPWordsPatternstoTrie(*TPWordsP, *PWords);// justsubstrings not patterns exactly // PWordsP,
    QString localmFilename1 = (*mProject).GetDir().absolutePath() + "/Dicts/" + "CPair";

    slnp.loadCPairs(localmFilename1.toUtf8().constData(), *CPairs, *Dict, *PWords);
    localmFilename1 = mFilename1;

    localmFilename1 = (*mProject).GetDir().absolutePath() + "/Dicts/" + "LSTM";
    ifstream myfile(localmFilename1.toUtf8().constData());
    if (myfile.is_open())
    {
        string str1, str2, line;
        while (getline(myfile, line))
        {
            istringstream slinenew(line); slinenew >> str1; slinenew >> str2;
            if (str2.size() > 0) (*LSTM)[str1] = str2;
        }
    }
    cout << (*LSTM).size() << "LSTM Pairs Loaded";
    localmFilename1 = mFilename1;

    trie.loadmaptoTrie(*TPWords, *PWords);
    trie.loadmaptoTrie(*TDict, *Dict);
    trie.loadmaptoTrie(*TGBook, *GBook);
    trie.loadPWordsPatternstoTrie(*TGBookP, *GBook);
}

/*!
 * \fn MainWindow::on_actionLoadConfusions_triggered
 * \brief Loads the confusions for CPair
 */
void LoadDataWorker::on_actionLoadConfusions_triggered()
{
    slpNPatternDict slnp;
    QString localmFilename1 = (*mProject).GetDir().absolutePath() + "/Dicts/" + "CPair";
    slnp.loadConfusions(localmFilename1.toUtf8().constData(), *ConfPmap);
    localmFilename1 = mFilename;
}

