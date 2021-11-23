#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "averageaccuracies.h"
#include "eddis.h"
#include "slpNPatternDict.h" //as included through lcsqt.h
#include "trieEditdis.h"
#include "meanStdPage.h"
#include <math.h>
#include <QPrinter>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include "DiffView.h"
#include "diff_match_patch.h"
#include "interndiffview.h"
#include "commentsview.h"
#include "Symbols.h"
#include "textfinder.h"
#include "resizeimageview.h"
#include <string>
#include <fstream>
#include <vector>
#include <utility>
#include "ProjectHierarchyWindow.h"
#include "3rdParty/RapidXML/rapidxml.hpp"
#include <QDomDocument>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QTreeView>
#include <QFont>
#include <git2.h>
#include "shortcutguidedialog.h"
#include <QFileSystemWatcher>
#include <set>
#include <algorithm>
#include <QSet>
#include <QAction>
#include "ProjectWizard.h"
#include <SimpleMail/SimpleMail>
//# include <QTask>
#include <QDebug>
#include<QtCore>
#include<QtXml>
#include <QPainter>
#include <QJsonObject>
#include <QTextDocumentFragment>
#include <sstream>
#include <QVector>
#include <vector>
#include <QJsonValue>
#include <QGraphicsRectItem>
#include <QToolTip>
#include <QSyntaxHighlighter>
#ifdef __unix__
#include <unistd.h>
#endif
#include <editdistance.h>
#include <QRegularExpressionMatch>

//gs -dNOPAUSE -dBATCH -sDEVICE=jpeg -r300 -sOutputFile='page-%00d.jpeg' Book.pdf
map<string, int> Dict, GBook, IBook, PWords, PWordsP,ConfPmap,ConfPmapFont,CPairRight;
trie TDict,TGBook,TGBookP, newtrie,TPWords,TPWordsP;
vector<string> vGBook,vIBook;
QImage imageOrig;
QString gDirOneLevelUp,gDirTwoLevelUp,gCurrentPageName, gCurrentDirName;
map<QString, QString> gInitialTextHtml;
QString gTimeLogLocation;
map<QString, int> timeLog;
vector<QString> vs; vector<int> vx, vy, vw, vh, vright;
map<string, vector<string>> SRules;
map<string, string> TopConfusions;
map<string, int> TopConfusionsMask;
map<string, int> TimeLog;
string TimeLogLocation = "../Logs/log.txt";
string alignment = "left";
bool prevTRig = 0;
map<string, vector<int>> synonym;
vector<vector<string>> synrows;
//map<string, int> GPage; trie TGPage;
//map<string, int> PWords;//Common/Possitive OCR Words // already defined before
map<string, string> CPair;//Correction Pairs
std::map<string, set<string> > CPairs;
bool highlightchecked = false;
map<int, QString> commentdict;
map<int, vector<int>> commentederrors;
int openedFileChars;
int openedFileWords;
bool gSaveTriggered = 0;
map<QString, QString> filestructure_fw;
QMap <QString, QString> mapOfReplacements;

map<QString, QString> filestructure_bw = { {"VerifierOutput","CorrectorOutput"},
                                           {"CorrectorOutput","Inds"},
                                           {"Inds" , "Inds"}
                                         };

QString gSanskrit, gHindi;

bool drawRectangleFlag=false;      //This flag is to prevent inserting the IMAGEHOLDER twice

bool loadimage=false;           //Check image is loaded on not

bool shouldIDraw=false;         //button functioning over marking a region for figure/table/equations

int pressedFlag;            //Resposible for dynamic rectangular drawing

QString branchName;
//Constructor
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int largeWidth = QGuiApplication::primaryScreen ()->size ().width ();
    ui->splitter->setSizes(QList<int>({largeWidth/2 , largeWidth, largeWidth}));
    ui->tabWidget_2->tabBar()->hide();
    QString password  = "";
    QString passwordFilePath = QDir::currentPath() + "/pass.txt";
    QFile passwordFile(passwordFilePath);
    if(passwordFile.open(QFile::ReadOnly | QFile::Text))
        password = passwordFile.readAll().replace("\n","").replace("\r","");
    passwordFile.close();

    map<QString, QString> passwordRoleMap = { { "x3JzWx5KY}Gd&,]A" ,"Verifier"},
                                              { "3`t,FxjytJ[uU,HW" ,"Corrector"},
                                              { "$5Y9hkc+`{<7N%{L:KuR", "Admin"},
                                              { "sfbkasg81!248-Bks","Project Manager"}
                                            };
    if(!setRole(passwordRoleMap[password]))
        mExitStatus = true;

    QString common = "डॉ - xZ,, अ  - a,, आ/ ा  - A,, इ/ ि  - i,, ई/ ी  - I,, उ/ ु  - u,, ऊ/ ू  - U,, ऋ/ ृ  - f,, ए/ े  - e,, ऐ/ ै  - E,, ओ/ ो  - o,, औ/ ौ  - O,, ं  - M,, ः  - H,,  ँ   - ~,, ज्ञ  - jYa,, त्र  - tra,, श्र  - Sra,, क्ष्/क्ष  - kz/kza,, द्य्/द्य  - dy/dya,, क्/क  - k/ka,, ख्/ख  - K/Ka,, ग्/ग  - g/ga,, घ्/घ  - G/Ga,, ङ्/ङ  - N/Na,, च्/च  - c/ca,, छ्/छ  - C/Ca,, ज्/ज  - j/ja,, झ्/झ  - J/Ja,, ञ्/ञ  - Y/Ya,, ट्/ट  - w/wa,, ठ्/ठ  - W/Wa,, ड्/ड  - q/qa,, ढ्/ढ  - Q/Qa,, ण्/ण  - R/Ra,, त्/त  - t/ta,, थ्/थ  - T/Ta,, द्/द  - d/da,, ध्/ध  - D/Da,, न्/न  - n/na,, प्/प  - p/pa,, फ्/फ  - P/Pa,, ब्/ब  - b/ba,, भ्/भ  - B/Ba,, म्/म  - m/ma,, य्/य  - y/ya,, र्/र  - r/ra,, ल्/ल  - l/la,, व्/व  - v/va,, श्/श  - S/Sa,, ष्/ष  - z/za,, स्/स  - s/sa,, ह्/ह  - h/ha,, ळ्/ळ  - L/La,, १  - 1,, २  - 2,, ३  - 3,, ४  - 4,, ५  - 5,, ६  - 6,, ७  - 7,, ८  - 8,, ९  - 9,, ०  - 0,, ।  - |,, ॥  - ||";
    gSanskrit = "SLP1 Sanskrit Guide:";
    gSanskrit += "\n";
    gSanskrit+= "ऽ - $,, ॐ - %,, ᳲ  - Z,,  ᳳ  - V,, ॠ/ ॄ  - F,, ऌ/ ॢ  - x,, ॡ/ \"ॣ\”  - X,, ,, ,, ";
    gSanskrit += common;
    gSanskrit.replace(",, ", "\n");

    gHindi = "SLP1 Hindi Guide:";
    gHindi += "\n";
    gHindi+= "ग़् - $,, ऩ् - %,, ऑ - Z,, ऱ् - V,, ज़ - F,, ड़्/ड़ -x/xa,, ढ़्/ढ़  - X/Xa,, य़्  - &,, क़ - @,, ख़ - #,, फ़् - ^,, ॅ - *,, ,, ,, ";
    gHindi += common;
    gHindi.replace(",, ", "\n");
    QFont font("Shobhika-Regular");
    font.setWeight(14);
    font.setPointSize(12);
    ui->textEdit->setFont(font);

    ui->sanButton->setChecked(true);

    ui->tabWidget_2->removeTab(0);
    ui->tabWidget_2->removeTab(0);

    bool b = connect(ui->tabWidget_2, SIGNAL(tabCloseRequested(int)), this, SLOT(closetab(int)));
    b = connect(ui->tabWidget_2, SIGNAL(currentChanged(int)), this, SLOT(tabchanged(int)));
    b = connect(&watcher, SIGNAL(directoryChanged(const QString&)), this, SLOT(directoryChanged(const QString&)));
    connect(ui->treeView, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(CustomContextMenuTriggered(const QPoint&)));
    connect(ui->treeView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(file_click(const QModelIndex&)));

    qApp->installEventFilter(this);
}

/*!
 * \brief MainWindow::setRole()
 * \param role
 * \return true/false
 */
bool MainWindow::setRole(QString role)
{
    this->mRole = role;

    //! Checking role
    if(mRole == "Admin")
    {
        int button = QMessageBox::question(this, "Select Role", "Which Role do you want to Load?",
                                           "Verifier", "Corrector","Project Manager", 0);
        if(button == 0)
            mRole = "Verifier";
        else if(button == 1)
            mRole = "Corrector";
        else if(button == 2)
            mRole = "Project Manager";
        else
            return false;
    }

    if(mRole == "Project Manager")
    {
        ui->actionNew_Project->setEnabled(true);    //enable the option
        ui->actionNew_Project->setVisible(true);    //make it visible
        mRole = "Verifier";
    }

    if(mRole == "Verifier")
    {
        //! setting its each filesructure with verifieroutput
        filestructure_fw = { {"Inds","VerifierOutput"},
                             {"CorrectorOutput","VerifierOutput",},
                             {"VerifierOutput","VerifierOutput" }
                           };
        isVerifier = 1;
        ui->actionTurn_In->setVisible(false);      //set false to its visibility; now shown
        ui->actionTurn_In->setEnabled(false);      //disable the option

        this->setWindowTitle("OpenOCRCorrect-Verifier");


    }
    else if(mRole == "Corrector")
    {
        //! setting its each filesructure with correctoroutput
        filestructure_fw = { {"Inds","CorrectorOutput"},
                             {"CorrectorOutput","CorrectorOutput",},
                             {"VerifierOutput","CorrectorOutput" }
                           };

        ui->compareVerifierOutput->setVisible(false);
        ui->compareVerifierOutput->setEnabled(false);

        ui->actionVerifier_Turn_In->setVisible(false);
        ui->actionVerifier_Turn_In->setEnabled(false);

        isVerifier = 0;
        this->setWindowTitle("OpenOCRCorrect-Corrector");
    }
    else
    {
        int result = QMessageBox::information(this,"Login","Login Failed");
        return false;
    }
    return true;
}

//destructor
MainWindow::~MainWindow()
{
    delete ui;
}

/*!
 * \brief readJsonFile
 * \param filepath
 * \return
 */
QJsonObject readJsonFile(QString filepath)
{
    QFile jsonFile(filepath);
    jsonFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray data = jsonFile.readAll();

    QJsonParseError errorPtr;
    QJsonDocument document = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject mainObj = document.object();
    jsonFile.close();
    return mainObj;
}

/*!
 * \brief writeJsonFile
 * \param filepath
 * \param mainObj
 */
void writeJsonFile(QString filepath, QJsonObject mainObj)
{
    QJsonDocument document1(mainObj);

    QFile jsonFile(filepath);
    jsonFile.open(QIODevice::WriteOnly);
    jsonFile.write(document1.toJson());
    jsonFile.close();
}
QString file = "";
bool fileFlag = 0;
QElapsedTimer myTimer;
int secs;
int gSeconds;

/*!
 * \brief MainWindow::SaveTimeLog
 */
void MainWindow::SaveTimeLog()
{
    QJsonObject mainObj;
    QJsonObject page;
    for (auto i = timeLog.begin(); i!=timeLog.end(); i++ )
    {
        page["directory"] = i->first;
        page["seconds"] = i->second;
        mainObj.insert(i->first, page);
    }
    writeJsonFile(gTimeLogLocation, mainObj);
}

/*!
 * \brief MainWindow::DisplayTimeLog
 */
void MainWindow::DisplayTimeLog()
{
    QString currentVersion = mProject.get_version();
    if(mRole == "Verifier" && mRole != currentVersion)
        currentVersion = QString::number(currentVersion.toInt() - 1);

    gSeconds = timeLog[mRole +":"+ gCurrentPageName +":V-"+ currentVersion];
    int nMilliseconds = myTimer.elapsed();
    gSeconds += nMilliseconds / 1000;
    int mins = gSeconds / 60;
    int seconds = gSeconds - mins * 60;
    ui->lineEdit->setText(QString::number(mins) + "mins " + QString::number(seconds) +
                          " secs elapsed on this page(Right Click to update)");
}

/*!
 * \brief MainWindow::UpdateFileBrekadown
 */
void MainWindow::UpdateFileBrekadown()
{
    QFileInfo finfo(mFilename);
    QString qstr = finfo.fileName();

    string str = qstr.toStdString();
    str.erase(remove(str.begin(), str.end(), ' '), str.end());

    gCurrentPageName = QString::fromStdString(str);
    gDirTwoLevelUp = mProject.GetDir().absolutePath();
    gCurrentDirName = finfo.dir().dirName();
    gDirOneLevelUp = gDirTwoLevelUp + "/" + gCurrentDirName;
}

/*!
 * \brief DisplayError
 * \param error
 */
void DisplayError(QString error)
{
    QMessageBox msgBox;
    msgBox.setText(error);
    msgBox.exec();
}

vector<string> vGPage, vIPage, vCPage; // for calculating WER

vector<string> vBest;

/*!
\fn mousePressEvent()
\param event
\brief Checks if the right click is pressed on the mouse and loads suggestion changes
Custom mouse event is created which loads a suggestion and translation menu for the string on which the current string
highlight is present. These are loaded with the help of dictionary files which are loaded with the help of loaddata
function. Works with the help of a flag.
\sa print5NearestEntries(), print2OCRSugg(), loadWConfusionsNindex1(), editDist(), make_pair()
*/

bool RightclickFlag = 0;
string selectedStr ="";

//!GIVE EVENT TO TEXT BROWZER INSTEAD OF MAINWINDOW
void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if (curr_browser)
    {
        curr_browser->cursorForPosition(ev->pos());

        DisplayTimeLog();

        //! if right click
        if ((ev->button() == Qt::RightButton) || (RightclickFlag))
        {
            QTextCursor cursor1 = curr_browser->cursorForPosition(ev->pos());
            QTextCursor cursor = curr_browser->textCursor();
            cursor.select(QTextCursor::WordUnderCursor);
            //BlockUnderCursor
            // code to copy selected string:-
            QString str1 = cursor.selectedText();
            selectedStr = str1.toUtf8().constData();

            if (selectedStr != "") {
                // code to display options on rightclick
                curr_browser->setContextMenuPolicy(Qt::CustomContextMenu);//IMP TO AVOID UNDO ETC AFTER SELECTING A SUGGESTION
                QMenu* popup_menu = curr_browser->createStandardContextMenu();
                QMenu* spell_menu, *translate_menu;

                spell_menu = new QMenu("suggestions", this);
                translate_menu = new QMenu("translate", this);
                QFont font("Shobhika-Regular");
                font.setWeight(14);
                font.setPointSize(12);
                spell_menu->setFont(font);
                translate_menu->setFont(font);

                QAction* act;

                vector<string>  Words1 = print5NearestEntries(TGBook, selectedStr);
                if (Words1.empty()) return;
                vector<string> Alligned = print5NearestEntries(TGBookP, selectedStr);
                if (Alligned.empty()) return;

                vector<string> PWords1 = print5NearestEntries(TPWords, selectedStr);
                if (PWords1.empty()) return;

                string PairSugg = print2OCRSugg(selectedStr, Alligned[0], ConfPmap, Dict); // map<string,int>&
                if (PairSugg.empty())return;
                vector<string>  Words = print1OCRNearestEntries(toslp1(selectedStr), vIBook);
                if (Words.empty())return;

                //! find nearest confirming to OCR Sugg from Book
                string nearestCOnfconfirmingSuggvec;
                vector<string> vec = Words1;
                int min = 100;
                for (size_t t = 0; t < vec.size(); t++)
                {
                    vector<string> wordConfusions; vector<int> wCindex;
                    int minFactor = loadWConfusionsNindex1(selectedStr, vec[t], ConfPmap, wordConfusions, wCindex);
                    wordConfusions.clear(); wCindex.clear();
                    if (minFactor < min) { min = minFactor; nearestCOnfconfirmingSuggvec = vec[t]; }
                }

                //! find nearest confirming to OCR Sugg from PWords
                string nearestCOnfconfirmingSuggvec1;
                vector<string> vec1 = PWords1;
                min = 100;
                for (size_t t = 0; t < vec1.size(); t++) {
                    vector<string> wordConfusions; vector<int> wCindex;
                    int minFactor = loadWConfusionsNindex1(selectedStr, vec1[t], ConfPmap, wordConfusions, wCindex);
                    wordConfusions.clear(); wCindex.clear();
                    if (minFactor < min) { min = minFactor; nearestCOnfconfirmingSuggvec1 = vec1[t]; }
                }

                vector<pair<int, string>> vecSugg, vecSugg1;
                map<string, int> mapSugg;

                vector<string> out;
                map<string, set<string>>::iterator itr;
                set<string>::iterator set_it;

                for (itr = CPairs.begin(); itr != CPairs.end(); ++itr)
                {
                    if(toslp1(itr->first) == toslp1(selectedStr))
                    {
                        for (set_it = itr->second.begin(); set_it != itr->second.end(); ++set_it)
                        {
                           out.push_back(toslp1(*set_it));
                        }
                    }
                }

                cout<<"From CPairs: ";
                for(auto& it : out){
                    cout << toslp1(it) << endl;
                }
                for (size_t ksugg1 = 0; ksugg1 < 6; ksugg1++)
                {
                    if (out.size() > ksugg1)  mapSugg[toslp1(out[ksugg1])]++;
                }

                if(mProject.get_configuration()=="True")
                {
                    if (Words.size() > 0)  mapSugg[toslp1(Words[0])]++;
                    if (Words1.size() > 0) mapSugg[toslp1(nearestCOnfconfirmingSuggvec)]++;
                    if (PWords1.size() > 0) mapSugg[toslp1(nearestCOnfconfirmingSuggvec1)]++;
                    if (PairSugg.size() > 0) mapSugg[toslp1(PairSugg)]++;
                    mapSugg[SamasBreakLRCorrect(toslp1(selectedStr), Dict, PWords, TPWords, TPWordsP)]++;
                    string s1 = toslp1(selectedStr);
                    string nearestCOnfconfirmingSuggvecFont = "";
                    min = 100;
                    for (size_t t = 0; t < vec.size(); t++)
                    {
                        vector<string> wordConfusions; vector<int> wCindex;
                        int minFactor = loadWConfusionsNindex1(s1, vec[t], ConfPmapFont, wordConfusions, wCindex);
                        wordConfusions.clear(); wCindex.clear();
                        if (minFactor < min) { min = minFactor; nearestCOnfconfirmingSuggvecFont = vec[t]; }
                    }
                    //if (nearestCOnfconfirmingSuggvecFont.size() > 0) mapSugg[nearestCOnfconfirmingSuggvecFont]++;

                    string PairSuggFont = "";
                    if (Alligned.size() > 0) PairSuggFont = print2OCRSugg(s1, Alligned[0], ConfPmap, Dict);
                    //if (PairSuggFont.size() > 0) mapSugg[PairSuggFont]++;

                    string sugg9 = "";
                    sugg9 = generatePossibilitesNsuggest(s1, TopConfusions, TopConfusionsMask, Dict, SRules);
                    //if (sugg9.size() > 0) mapSugg[sugg9]++;

                    cout<<"selected string: "<<toslp1(selectedStr)<<endl;
                    cout<<"Mapped Suggestion 0: "<<endl; //(string,int) Words, last no. of occuring, create single entry for single same word

                    cout<<"From Primary OCR: ";
                    for(auto& it : Words){
                        for(uint i = 0;i<it.size();i++){
                             cout << it[i];
                        }
                        cout<<"\n";
                    }
                    cout<<"Nearest confirming from Secondary OCR "<<nearestCOnfconfirmingSuggvec<<endl;
                    cout<<"Nearest confirming from PWords "<<nearestCOnfconfirmingSuggvec1<<endl;
                    cout<<"One suggestion from ConfusionPair and secondary OCR Trie Pattern Data "<<toslp1(PairSugg)<<endl;
                    cout<<"One suggestion from Pwords which is present in Dict "<<SamasBreakLRCorrect(toslp1(selectedStr), Dict, PWords, TPWords, TPWordsP)<<endl;
    //                cout<<"Nearest confirming from Secondary OCR by converting the string in English "<<nearestCOnfconfirmingSuggvecFont<<endl;
    //                cout<<"One suggestion from ConfusionPair and secondary OCR Trie Pattern Data by converting the string in English "<<toslp1(PairSuggFont)<<endl;
    //                cout<<"One suggestion from TopConfusion and SandhiRules by converting the string in English "<<sugg9<<endl;
                }

                for (map<string, int>::const_iterator eptr = mapSugg.begin(); eptr != mapSugg.end(); eptr++)
                {
                    vecSugg.push_back(make_pair(editDist(toslp1(eptr->first), toslp1(selectedStr)), eptr->first));
                }

                sort(vecSugg.begin(), vecSugg.end());

                cout << "\nVector Suggestions 0\n";
                cout << "MappingNum\t vector_int\t Word\n";
                for (uint i = 0; i < vecSugg.size(); i++){
                    cout<<mapSugg[vecSugg[i].second]<<"\t"<<vecSugg[i].first<<"\t"<<toDev(vecSugg[i].second)<<endl;
                }

                for (uint bitarrayi = 0; bitarrayi < vecSugg.size(); bitarrayi++)
                {
                    act = new QAction(QString::fromStdString(toDev(vecSugg[bitarrayi].second)), spell_menu);
                    spell_menu->addAction(act);
                }

                selectedStr.erase(remove(selectedStr.begin(), selectedStr.end(), ' '), selectedStr.end());
                vector<string> translate;
                vector<int>& syn = synonym[selectedStr];
                for(int i=0; i < syn.size(); i++)
                {
                    vector<string>& rowit = synrows[syn[i]];
                    for(int j=0; j < rowit.size(); j++)
                    {
                        if(rowit[j] != selectedStr)
                        {
                            translate.push_back(rowit[j]);
                            cout << rowit[j] << endl;
                        }
                    }
                }

                for (uint bitarrayi = 0; bitarrayi < translate.size(); bitarrayi++) {

                    act = new QAction(QString::fromStdString(translate[bitarrayi]), translate_menu);
                    translate_menu->addAction(act);
                }

                popup_menu->insertSeparator(popup_menu->actions()[0]);
                popup_menu->insertMenu(popup_menu->actions()[0], spell_menu);

                popup_menu->insertSeparator(popup_menu->actions()[1]);
                popup_menu->insertMenu(popup_menu->actions()[1], translate_menu);


                connect(spell_menu, SIGNAL(triggered(QAction*)), this, SLOT(menuSelection(QAction*)));
                connect(translate_menu, SIGNAL(triggered(QAction*)), this, SLOT(translate_replace(QAction*)));

                popup_menu->exec(ev->globalPos());
                popup_menu->close(); popup_menu->clear();

                vecSugg.clear(); Words1.clear(); Words.clear(); Alligned.clear(); PairSugg.clear();
                translate.clear();
            }
            else
            {
                DisplayTimeLog();

                QMenu* popup_menu = curr_browser->createStandardContextMenu();
                popup_menu->exec(ev->globalPos());
                popup_menu->close(); popup_menu->clear();
            }
        } // if right click
    }
}// if mouse event

/*!
 * \brief MainWindow::menuSelection
 * \param action
 */
void MainWindow::menuSelection(QAction* action)
{
    if (curr_browser)
    {
        QTextCursor cursor = curr_browser->textCursor();
        cursor.select(QTextCursor::WordUnderCursor);
        cursor.beginEditBlock();
        cursor.removeSelectedText();

        string target = (action->text().toUtf8().constData());
        CPair[toslp1(selectedStr)] = toslp1(target);
        PWords[toslp1(target)]++;
        cursor.insertText(action->text());

        cursor.endEditBlock();
    }
}

/*!
 * \brief MainWindow::translate_replace
 * \param action
 */
void MainWindow::translate_replace(QAction* action)
{
    if (curr_browser)
    {
        QTextCursor cursor = curr_browser->textCursor();
        cursor.select(QTextCursor::WordUnderCursor);
        cursor.beginEditBlock();
        cursor.removeSelectedText();

        string target = (action->text().toUtf8().constData());
        cursor.insertText(action->text());
        cursor.endEditBlock();
    }
}

//start

/*!
 * \fn MainWindow::on_actionSanskrit_triggered()
 * \brief Sets the language of the current broweser to Sanskrit by by passing the SanFlag as true
 * \sa setText()
*/
void MainWindow::on_actionSanskrit_triggered()
{
    HinFlag = 0, SanFlag = 1;
    ui->textEdit->setText(gSanskrit);//whenever language change is required it will be converted to Sanskrit using the slpNPatternDict.h
    ui->hinButton->setChecked(HinFlag);
}


/*!
 * \fn MainWindow::on_actionHindi_triggered
 * \brief Sets the language of the current broweser to Hindi by by passing the HinFlag as true
 * \sa setText()
*/
void MainWindow::on_actionHindi_triggered()
{
    HinFlag = 1, SanFlag = 0;
    ui->textEdit->setText(gHindi);  //whenever language change is required it will be converted to Hindi using the slpNPatternDict.h
    ui->sanButton->setChecked(SanFlag);
}


/*!
 * \fn MainWindow::on_actionEnglish_triggered()
 * \brief Sets the language of the current broweser to Hindi by passing the HinFlag and the SanFlag as false
 * \sa setText()
*/
void MainWindow::on_actionEnglish_triggered()
{
    HinFlag = 0, SanFlag = 0;
    ui->hinButton->setChecked(HinFlag);//whenever language change is required it will be left as it is
    ui->sanButton->setChecked(SanFlag);
}


/*!
 * \fn MainWindow::on_actionNew_triggered
 * \brief This function allows the user to create new file/project.
 */
void MainWindow::on_actionNew_triggered()
{
    QTextBrowser * b = new QTextBrowser(this);
    b->setReadOnly(false);
    b->setUndoRedoEnabled(true);            //User can use Undo/Redo commands

    //! When opened tabs count is not zero
    if (ui->tabWidget_2->count() != 0) {
        for (int i = 0; i < ui->tabWidget_2->count(); i++) {
            //!When opened file name is not set
            if ("Untitled" == ui->tabWidget_2->tabText(i)) {
                ui->tabWidget_2->setCurrentIndex(i);
            }
        }
    }
    //! Setting current tab index
    currentTabIndex = ui->tabWidget_2->addTab(b, "Untitled");
    ui->tabWidget_2->setCurrentIndex(currentTabIndex);
}

/*!
 * \fn MainWindow::on_actionOpen_Project_triggered
 * \brief Opens a new OCR project
 * \note Every project contains six folders - Images, Inds, CorrectorOutput, VerifierOutput, Dicts and Comments.
 *
 * \sa process_xml(), open_git_repo(), get_stage(), get_version(), getModel(), AddTemp(), getFilter(), insert(), UpdateFileBrekadown(), readJsonFile()
 */
void MainWindow::on_actionOpen_Project_triggered() { //Version Based

    /* Description
     * 1. Check if file named "project.xml" exists else terminates the function.
     * 2. Create a new directory if CorrectorOutput, VerifierOutput or Comments folders does not exist.
     * 3. Loading the requisites.
     *    a) Processing the project.xml file.
     *    b) Load git repository.
     * 4. Set the model for ProjectHierarchyWindow(TreeView). TreeView is composed of Documents and Images.
     * 5. Reset the current file name and directory levels.
     * 6. Get the value for time elapsed from Timelog.json.
     */

    QFile xml(QFileDialog::getOpenFileName(this, "Open Project", "./", tr("Project(*.xml)")));   //Opens only if the file name is Project.xml
    QFileInfo finfo(xml);
    QString basedir = finfo.absoluteDir().absolutePath();

    //!Initializes the string with directory name
    QString s1 = basedir + "/Images/";
    QString s2 = basedir + "/Inds/";
    QString s3 = basedir+"/CorrectorOutput/";
    QString s4 = basedir + "/VerifierOutput/";
    QString s5 = basedir + "/Comments/";

    //! Terminates function if Project.xml doesn't exist
    if (finfo.fileName() == "")
        return;

    //! Creates a new directory if the CorrectorOutput, VerifierOutput or Comments folders does not exist.
    if (!QDir(s3).exists())
    {
        QDir().mkdir(s3);
    }
    if (!QDir(s4).exists())
    {
        QDir().mkdir(s4);
    }
    if (!QDir(s5).exists())
    {
        QDir().mkdir(s5);
    }

    bool exists = QDir(s1).exists() && QDir(s2).exists();
    if (xml.exists()&& exists)
    {
        ui->treeView->reset();    //reinitialize the ProjectHierarchyWindow
        mProject.process_xml(xml);

        mProject.open_git_repo();   //Open git repo
        if(!mProject.isProjectOpen())
        {
            QMessageBox::warning(0, "Project Error", "Couldn't open project. Please check your project.");
            return;
        }
        ui->treeView->setModel(mProject.getModel());
        ui->treeView->setContextMenuPolicy(Qt::CustomContextMenu);

        QString stage = mProject.get_stage();                          //fetches the stage from project.xml file
        QString version = mProject.get_version();                      //Fetches version from project.xml file
        ui->lineEdit_2->setText("Version: " + version);                //Updates version in ui

        //!Get the path of all necessary directories
        QDir dir = mProject.GetDir();
        QString str1 = mProject.GetDir().absolutePath()+"/CorrectorOutput/";
        QString str2 = mProject.GetDir().absolutePath() + "/VerifierOutput/";
        QString str3 = mProject.GetDir().absolutePath() + "/Inds/";
        QString str4 = mProject.GetDir().absolutePath() + "/Images/";

        //!To lookout for changes in CorrectorOutput and VerifierOutput directory
        watcher.addPath(str1);
        watcher.addPath(str2);

        //!To Display tree view for Document
        QDir cdir(str1);

        Filter * filter = mProject.getFilter("CorrectorOutput");
        //Filter * filter2 = mProject.getFilter("CorrectorOutput");
        //Filter * filter1 = mProject.getFilter("VerifierOutput");
        //!Adds each file present in CorrectorOutput directory to treeView
        auto list = cdir.entryList(QDir::Filter::Files);

for (auto f : list)
        {   QStringList x = f.split(QRegExp("[.]"));

            QString t = str1 + "/" + f;
            QFile f2(t);
            if(x[1]=="html")
            mProject.AddTemp(filter,f2," ");
            corrector_set.insert(f);


        }
        //!Adds each file present in VerifierOutput directory to treeView
        filter = mProject.getFilter("VerifierOutput");
        cdir.setPath(str2);
        list = cdir.entryList(QDir::Files);
        for (auto f : list)
        {
            //QStringList x1 = f.split(QRegExp("[.]"));
            verifier_set.insert(f);
            QString t = str2 + "/" + f;
            QFile f2(t);
            mProject.AddTemp(filter, f2, "");

        }
        filter = mProject.getFilter("Document");
        //!Adds the files from inds folder to treeView
        cdir.setPath(str3);
        list = cdir.entryList(QDir::Filter::Files);
        for (auto f : list)
        {
            QString t = str3 + "/" + f;
            QFile f2(t);
            mProject.AddTemp(filter, f2, "");
        }

        //!To Display treeView for Image
        filter = mProject.getFilter("Image");

        //!Adds the files from Image folder to treeView
        cdir.setPath(str4);
        list = cdir.entryList(QDir::Filter::Files);
        for (auto f : list) {
            QString t = str4 + "/" + f;
            QFile f2(t);
            mProject.AddTemp(filter, f2, "");
        }

//        //!Disable Corrector Turn In once the Corrector has Turned in until the next version is fetched.
//        if(!isVerifier)
//        {
//            if (stage != "Corrector")
//            {
//                ui->actionTurn_In->setEnabled(false);
//            }
//        }
        UpdateFileBrekadown();    //Reset the current file and dir levels

        //!Get the elapsed time in Timelog.json file under Comments folder
        gTimeLogLocation = gDirTwoLevelUp + "/Comments/Timelog.json";     //Navigate to Timelog.json uder Comments folder
        QJsonObject mainObj =  readJsonFile(gTimeLogLocation);

        //!Get the seconds elapsed for their file name in json file
        foreach(const QJsonValue &val, mainObj)
        {
            QString directory = val.toObject().value("directory").toString();
            int seconds    = val.toObject().value("seconds").toInt();
            timeLog[directory] = seconds;
        }

        //bool isSet = QDir::setCurrent(mProject.GetDir().absolutePath() + "/CorrectorOutput") ; //Change application Directory to any subfolder of mProject folder for Image Insertion feature.
        //if(!QDir(mProject.GetDir().absolutePath() + "/Images/Inserted").exists())
        //    QDir().mkdir(mProject.GetDir().absolutePath() + "/Images/Inserted");

        QMessageBox::information(0, "Success", "Project opened successfully.");
        ui->tabWidget_2->removeTab(0);
        //!Genearte image.xml for figure/table/equation entries and initialize these values by 1.
        createImageInfoXMLFile();

    }
    else
    {
        QMessageBox::warning(0, "Project Error", "Couldn't open project. Please check your project.");
        return;
    }
}

/*!
 * \fn MainWindow::on_actionSave_triggered()
 * \brief This function will save any changes made in the current file.
 * \sa SaveTimeLog(), DisplayTimeLog()
*/
bool ConvertSlpDevFlag = 0;
void MainWindow::on_actionSave_triggered()
{
    SaveTimeLog();
    DisplayTimeLog();
    QVector <QString> changedWords;
    //! When changes are made by the verifier the following values are also updated.
    if(isVerifier)
    {
        gSaveTriggered = 1;
        on_viewComments_clicked();
        gSaveTriggered = 0;
        updateAverageAccuracies();
    }
    ConvertSlpDevFlag =1;

    /*
     * If file name is \value untitled on_actionSave_As_triggered is called.
     * Otherwise we will update the changes in the existing saved file.
    */
    if (mFilename=="Untitled")
    {
        on_actionSave_As_triggered();
    }
    else
    {
        QString tempPageName = gCurrentPageName;

        //! Selecting the location where file is to be saved
        QString changefiledir = filestructure_fw[gCurrentDirName];
        QString localFilename = gDirTwoLevelUp + "/" +changefiledir +"/" + tempPageName;

        localFilename.replace(".txt",".html");

        //! Don't create and save new file if output file already exists.
        if (gCurrentDirName == "Inds" || isVerifier && gCurrentDirName == "CorrectorOutput")
        {
            QFileInfo check_file(localFilename);
            if (check_file.exists() && check_file.isFile())
            {
                return ;
            }
        }

        QFile sFile(localFilename);

        QTextCharFormat fmt;
        fmt.setForeground(QBrush(QColor(0,0,0)));           //Setting foreground brush to render text
        QTextCursor cursor = curr_browser->textCursor();
        cursor.select(QTextCursor::Document);
        cursor.mergeCharFormat(fmt);

        QString output = curr_browser->toHtml();

        QTextDocument doc;
        doc.setHtml( gInitialTextHtml[currentTabPageName] );
        s1 = doc.toPlainText();          //before Saving
        s2 = curr_browser->toPlainText();       //after Saving

        changedWords = editDistance(s1, s2);             // Update CPair by editdistance
        QVectorIterator<QString> i(changedWords);
        while (i.hasNext())
            qDebug() << i.next()<<endl;
        //! Do commit when there are some changes in previous and new html file on the basis of editdistance.
        if(changedWords.size())
        {
            if(mProject.get_version().toInt())     //Check version number
            {
                QString commit_msg = "Corrector Turned in Version: " + mProject.get_version();
                //!Check commit condition
                if(!mProject.commit(commit_msg.toStdString()))
                {
                    cout<<"Commit Unsuccessful"<<endl;
                    return;
                }
                else
                {
                    mProject.commit(commit_msg.toStdString());
                    cout<<"Commit Successful"<<endl;
                }
            }
        }

        //CPair.insert(CPair_editDis.begin(), CPair_editDis.end());
        //! Enters entries in CPairs through CPair_editDis; allows multiple entries for a incorrent word entry
        for(auto elem : CPair_editDis)
        {
           std::cerr << elem.first << " " << elem.second << "\n";
           std::cerr << toslp1(elem.first) << " " << toslp1(elem.second) << "\n";
           //CPair.insert(make_pair(toslp1(elem.first), toslp1(elem.second)));
           if ( CPairs.find(toslp1(elem.first)) != CPairs.end())
           {
               std::set< std::string>& s_ref = CPairs[toslp1(elem.first)];
               s_ref.insert(toslp1(elem.second));
           }
           else
           {
               CPairs[toslp1(elem.first)].insert(toslp1(elem.second));
           }
        }

        //! Reflecting CPairs entries in the file /Dicts/CPair; Making it dynamic
        QString filename12 = mProject.GetDir().absolutePath() + "/Dicts/" + "CPair";
        QFile file12(filename12);
        if(!file12.exists())
        {
           qDebug() << "No exist file "<<filename12;
        }
        else
        {
           qDebug() << filename12<<"exists";
        }

        //! Insert entries in Correct Formatting Hello (/t) hi,(comma)hiii
        if (file12.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file12);
            out.setCodec("UTF-8");
            map<string, set<string>>::iterator itr;
            set<string>::iterator set_it;

            for (itr = CPairs.begin(); itr != CPairs.end(); ++itr)
            {
                out <<  QString::fromStdString(toDev(itr->first)) << '\t';
                for (set_it = itr->second.begin(); set_it != itr->second.end(); ++set_it)
                {
                    if(set_it != prev(itr->second.end()))
                    {
                        out << QString::fromStdString(toDev(*set_it)) << ",";
                    }
                    else {
                        out << QString::fromStdString(toDev(*set_it));
                    }

                }
                out <<"\n";
            }
             file12.close();
        }

        //! If file is in write-only mode
        if(sFile.open(QFile::WriteOnly))
        {
            QTextStream out(&sFile);
            out.setCodec("UTF-8");          //Sets the codec for this stream
            gInitialTextHtml[currentTabPageName] = output;
            output = "<style> body{ width: 21cm; height: 29.7cm; margin: 30mm 45mm 30mm 45mm; } </style>" + output;     //Formatting the output using CSS <style> tag
            out << output;
            sFile.flush();      //Flushes any buffered data waiting to be written in the \a sFile
            sFile.close();      //Closing the file
        }

        //! Converting html output into plain text.
        QTextDocumentFragment qtextdocfragment;
        QString plain = qtextdocfragment.fromHtml(output).toPlainText();

        std::stringstream ss(plain.toStdString());
        std::string to;
        //! Appending the plain text in QVector<QString> object.
        QVector<QString> s;
        if (plain != NULL)
        {
            while(std::getline(ss,to,'\n'))
            {
                QString qstr = QString::fromStdString(to);
                s.append(qstr);
            }
        }

        //! Inserting string values in \a qjsonobj.
        QJsonObject qjsonobj;
        for(int i = 0;i < s.size(); i++)
        {
            QString z = QString::number(i);
            qjsonobj.insert(z, QJsonValue(s[i]));
        }
        int len = qjsonobj.length();

        localFilename.replace(".html",".json");         //Replacing extension of file from .html to .json
        QFile sFile2(localFilename);

        //! Sets codec value and then adding values in file
        if(sFile2.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&sFile2);
            out.setCodec("UTF-8");
            out << "{\n";
            for(int x = 0; x<len; x++)
            {
                QString z = QString::number(x);
                out << "\"" << x << "\"" << ":" << "\"" << qjsonobj[z].toString() << "\"" <<","<< '\n';
            }
            out << "}";

            sFile2.flush();
            sFile2.close();
        }

        //! Set Inds file readonly after saving - Corrector mode
        if (!isVerifier && gCurrentDirName == "Inds")
        {
            if(QFile::exists(localFilename))
            {
                curr_browser->setReadOnly(true);
            }

        }

        //! Set Inds and CorrectorOutput files readonly after generating output file - Verifier mode
        if (isVerifier && (gCurrentDirName == "Inds" || gCurrentDirName == "CorrectorOutput"))
        {
            if(QFile::exists(localFilename))
            {
                QString Inds_file = gCurrentPageName;
                Inds_file.replace(".html", ".txt");
                QString Corr_file = Inds_file;
                Corr_file.replace(".txt", ".html");
                for (int i = 0; i < ui->tabWidget_2->count(); i++)
                {
                    QString tab_name = ui->tabWidget_2->tabText(i);
                    if (tab_name == Inds_file || tab_name == Corr_file)
                    {
                        auto b = (QTextBrowser*)ui->tabWidget_2->widget(i);
                        b->setReadOnly(true);
                    }
                }
            }
        }
    }

    QString currentDirAbsolutePath = gDirTwoLevelUp + "/" + gCurrentDirName;
    runGlobalReplace(currentDirAbsolutePath, changedWords);

    ConvertSlpDevFlag =0;
}


/*!
 * \fn MainWindow::on_actionSave_As_triggered()
 * \brief This function saves the file which has never been saved once.
 */
void MainWindow::on_actionSave_As_triggered()
{
    QString file(QFileDialog::getSaveFileName(this, "Open a File"));

    //! Sets the file name and saves the file.
    if (!file.isEmpty())
    {
        setMFilename(file);
        UpdateFileBrekadown();

        on_actionSave_triggered();
    }
}

/*!
 * \fn on_actionSpell_Check_triggered()
 * \brief Converts the whole html page to the original text page in orange color
 * \note works on the basis of a pre-defined flag which helps to always convert the text to Devanagari
 * \sa findDictEntries(), find_and_replace_oddInstancesblue(), find_and_replace_oddInstancesorange(),hasM40PerAsci()
 */
map<string, int> wordLineIndex;

void MainWindow::on_actionSpell_Check_triggered()
{
    if(!curr_browser || curr_browser->isReadOnly())
        return;

    QString textBrowserText = curr_browser->toPlainText();
    QChar ch;
    ch=textBrowserText[1];
    textBrowserText+=" ";
    string str1=textBrowserText.toUtf8().constData();

    //! load number of words
    istringstream iss1(str1);
    size_t WordCount = 0;
    string word1;
    while(iss1 >> word1) WordCount++;

    //str1 = toslp1(str1);
    istringstream iss(str1);
    string strHtml = "<html><body>";
    string line;

    int value = 0;
    while (getline(iss, line))
    {
        istringstream issw(line);
        string word;

        while(issw >> word)
        {
            if(ConvertSlpDevFlag)
            {
                string word1 = word;
                word = toslp1(word);
                string wordNext;
                if(hasM40PerAsci(word1))
                {
                    wordNext = word1;
                }
                else
                {
                    wordNext = toDev(word);
                }
                strHtml += wordNext; strHtml += " ";
                value ++;
            }
            else
            {
                string word1 = word;
                word = toslp1(word);
                string wordNext;
                //! checks if the word exists in the English language, Seconday OCR, Pwords, Dict and CPair; convert its color coding
                if(hasM40PerAsci(word1))
                    wordNext = word1;

                else if(GBook[(word)] > 0 )
                {
                    wordNext = toDev(word);
                    PWords[word]++;
                }

                else if(PWords[word] > 0)
                {
                    wordNext = "<font color=\'gray\'>" + toDev(word) + "</font>";
                }
                else if((Dict[word] ==0) && (PWords[word] == 0) && (CPair[word].size() > 0))
                {
                    wordNext = "<font color=\'purple\'>" + toDev(CPair[word]) + "</font>";
                }
                else
                {
                    wordNext = findDictEntries(toslp1(word),Dict,PWords, word.size());     //replace m1 with m2,m1 for combined search
                    wordNext = find_and_replace_oddInstancesblue(wordNext);
                    wordNext = find_and_replace_oddInstancesorange(wordNext);
                }
                strHtml += wordNext;
                strHtml += " ";
                value ++;
            }
        }
        strHtml +="<br>";  // To add new line
    }
    strHtml += "</body></html>";
    curr_browser->setHtml(QString::fromStdString(strHtml));

    str1=textBrowserText.toUtf8().constData();

    istringstream iss2(str1);
    size_t WordCount2 = 0;

    //! clean(word) instead of word
    while (getline(iss2, line))
    {
        istringstream issw(line);
        string word;
        while(issw >> word)
        {
            wordLineIndex[(word + "###" + line)] = WordCount2; WordCount2++;
        }
    }
}

/*!
 * \fn MainWindow::on_actionLoad_Next_Page_triggered
 * \brief Sets the browser window to display the next page
 *
 * \sa on_actionSave_triggered() ,get_version(), SaveTimeLog(), GetPageNumber(), LoadDocument()
 */
void MainWindow::on_actionLoad_Next_Page_triggered()
{
    /*Description
     * 1. Check if the file is saved else save the file
     * 2. Add Entries in Timelog.json about the elapsed time
     *    a) If the present mode is verifier, adds entries as verifer. Eg: "Verifier:page-2.txt:V-0"
     *    b) If the present mode is corrector, adds entries as corrector Eg: "Corrector:page-1.txt:V-1"
     * 3. Increment the page number extracted from the localFilename by value one. Terminates function if file doesn't exist
     * 4. Page number extracted from the tab name is incremented and set as the new tab name
     * 5. Loads the file with the incremented page number
     * */

    //! Checking if the file is saved else saves the file
    if(curr_browser) {
        if(gInitialTextHtml[currentTabPageName].compare(curr_browser->toHtml())) {    //fetching the text from the key(tab name) and comparing it to current browser text
            int btn = QMessageBox::question(this, "Save?", "Do you want to save this file?",
                                            QMessageBox::StandardButton::Ok, QMessageBox::StandardButton::No);
            if (btn == QMessageBox::StandardButton::Ok)
                on_actionSave_triggered();
        }

        string localFilename = mFilename.toUtf8().constData();
        string localCurrentTabPageName = currentTabPageName.toUtf8().constData();

        //! Adding entries in Timelog.json about the elapsed time
        int nMilliseconds = myTimer.elapsed();
        gSeconds = nMilliseconds/1000;                                 //Converting milliseconds to seconds
        QString currentVersion = mProject.get_version();
        if(mRole == "Verifier" && mRole != currentVersion)
            currentVersion = QString::number(currentVersion.toInt() - 1);   //Version is decremented for Verifier

        gSeconds = timeLog[mRole +":"+ gCurrentPageName +":V-"+ currentVersion];

        SaveTimeLog();

        //! Extract page number from the localFilename and checks if the incremented page exists
        string no = "";

        size_t loc;
        QString ext = "";

        if(!mProject.GetPageNumber(localFilename, &no, &loc, &ext))
            return;

        localFilename.replace(loc,no.size(),to_string(stoi(no) + 1));   //Increments page number by one

        QFile *file = new QFile(QString::fromStdString(localFilename));
        QFileInfo finfo(file->fileName());

        if(!(finfo.exists() && finfo.isFile())){
            return; }

        //!Extract page number from tab name and set the incremented page number as a new tab name and Loads the file
        if(!mProject.GetPageNumber(localCurrentTabPageName, &no, &loc, &ext))
            return;
        localCurrentTabPageName.replace(loc,no.size(),to_string(stoi(no) + 1));  //Increments page number by one
        currentTabPageName = QString::fromStdString(localCurrentTabPageName);

        fileFlag = 1;
        NextPrevTrig =1;
        LoadDocument(file, ext, currentTabPageName);    //loads the new file
        fileFlag = 0;

    }
}

/*!
 * \fn MainWindow::on_actionLoad_Prev_Page_triggered()
 * \brief Sets the browser window to display the previous page
 *
 * \sa on_actionSave_triggered() ,get_version(), SaveTimeLog(), GetPageNumber(), LoadDocument()
 */
void MainWindow::on_actionLoad_Prev_Page_triggered()
{
    /*Description
     * 1. Check if the file is saved else save the file
     * 2. Add Entries in Timelog.json about the elapsed time
     *    a) If the present mode is verifier, adds entries as verifer. Eg: "Verifier:page-2.txt:V-0"
     *    b) If the present mode is corrector, adds entries as corrector Eg: "Corrector:page-1.txt:V-1"
     * 3. Extract page number from the localfileName and decrements the page number by one. Terminates function if file doesn't exist
     * 4. Decrement the page number extracted from tab name and sets it as new tab name
     * 5. Loads the file with the decremented page number
     * */

    //! Check if the file is saved or not
    if(curr_browser) {
        if(gInitialTextHtml[currentTabPageName].compare(curr_browser->toHtml())) {   //fetching the text from the key(tab name) and comparing it to current browser text
            int btn = QMessageBox::question(this, "Save?", "Do you want to save " + currentTabPageName + " file?",
                                            QMessageBox::StandardButton::Ok, QMessageBox::StandardButton::No);
            if (btn == QMessageBox::StandardButton::Ok)
                on_actionSave_triggered();
        }

        string localFilename = mFilename.toUtf8().constData();
        string localCurrentTabPageName = currentTabPageName.toUtf8().constData();

        //! Adding entries in Timelog.json about the elapsed time
        int nMilliseconds = myTimer.elapsed();
        gSeconds = nMilliseconds/1000;                           //Converting milliseconds to seconds
        QString currentVersion = mProject.get_version();
        if(mRole == "Verifier" && mRole != currentVersion)
            currentVersion = QString::number(currentVersion.toInt() - 1);  //Version is decremented for Verifier
        gSeconds = timeLog[mRole +":"+ gCurrentPageName +":V-"+ currentVersion];
        SaveTimeLog();

        //! Extract page number from the localFilename
        string no = "";
        size_t loc;
        QString ext = "";
        if(!mProject.GetPageNumber(localFilename, &no, &loc, &ext))
            return;
        localFilename.replace(loc,no.size(),to_string(stoi(no) - 1));    //Version is decremented for Verifier

        //!checks if the decremented page exists
        QFile *file = new QFile(QString::fromStdString(localFilename));
        QFileInfo finfo(file->fileName());
        if(!(finfo.exists() && finfo.isFile())) // Check if file exists
            return;

        //!Extract page number from tab name and set the decremented page number as a new tab name and Loads the file
        if(!mProject.GetPageNumber(localCurrentTabPageName, &no, &loc, &ext))
            return;
        localCurrentTabPageName.replace(loc,no.size(),to_string(stoi(no) - 1));
        currentTabPageName = QString::fromStdString(localCurrentTabPageName);  //sets the decremented page number
        fileFlag = 1;
        NextPrevTrig =1;
        LoadDocument(file, ext, currentTabPageName);          //loads the file with the decremented page name
        fileFlag = 0;
    }
}

/*!
 * \fn MainWindow::on_actionToDevnagri_triggered()
 * \brief Converts transliterated text to devanagri text
 * Transliterated here means Hindi/ Sanskrit written in English.
 * This function converts selected translitrate text or last written translitrate word to Devanagri.
*/
void MainWindow::on_actionToDevanagari_triggered()
{
    if(!curr_browser || curr_browser->isReadOnly())
        return;
    QTextCursor cursor = curr_browser->textCursor();

    if(!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);

    QString str1 = cursor.selectedText();
    selectedStr = str1.toUtf8().constData();
    cursor.beginEditBlock();
    cursor.removeSelectedText();
    cursor.insertText(QString::fromStdString(toDev(toslp1(selectedStr))));
    cursor.endEditBlock();
}

/*!
 * \fn MainWindow::on_actionToSlp1_triggered()
 * \brief Converts devanagri/Sanskrit text to transliterated(english) text
 * This function converts selected Devanagri text to transliterated text.
*/
void MainWindow::on_actionToSlp1_triggered()
{
    if(!curr_browser || curr_browser->isReadOnly())
            return;
    QTextCursor cursor = curr_browser->textCursor();

    if(!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);

    QString str1 = cursor.selectedText();
    selectedStr = str1.toUtf8().constData();
    cursor.beginEditBlock();
    cursor.removeSelectedText();
    cursor.insertText(QString::fromStdString((toslp1(selectedStr))));
    cursor.endEditBlock();
}

/*!
 * \fn MainWindow::on_actionLoadGDocPage_triggered()
 * \brief Loads PWords and its associated trie data structure
 * \sa on_actionSave_As_triggered(), loadMap(), loadmaptoTrie(), generateCorrectionPairs(), loadConfusionsFont, loadTopConfusions()
*/
void MainWindow::on_actionLoadGDocPage_triggered()
{
    /*! If file name is Untitled do nothing*/
    if (mFilename == "Untitled")
    {

    }
    else
    {
        /*! Create an html file for current ind file*/
        on_actionSave_As_triggered();
        QString changefiledir = filestructure_fw[gCurrentDirName];
        QString str1 = gDirTwoLevelUp + "/" + changefiledir + "/" + gCurrentPageName;
        str1.replace(".txt", ".html");

        QFile sFile(str1);
        if (sFile.open(QFile::WriteOnly | QFile::Text))
        {
            QTextStream out(&sFile);
            out.setCodec("UTF-8");
            out << curr_browser->toHtml(); //toPlainText(); //Modified
            sFile.flush();
            sFile.close();
        }

        /*! Load PWord and Top Confusion Words*/
        loadMap(str1.toUtf8().constData(), PWords, "PWords");

        map<string, int> PWordspage;
        loadMap(str1.toUtf8().constData(), PWordspage, "PWordspage");
        loadmaptoTrie(TPWords, PWordspage);

        vector<string> wrong, right;
        QString str2 = mFilename;

        generateCorrectionPairs(wrong, right, str2.toUtf8().constData(), str1.toUtf8().constData());

        loadConfusionsFont(wrong, right, ConfPmapFont);
        loadConfusionsFont(wrong, right, ConfPmap);

        TopConfusions.clear();
        TopConfusionsMask.clear();
        loadTopConfusions(ConfPmap, TopConfusions, TopConfusionsMask);
    }
}

/*!
 * \fn MainWindow::on_actionLoadData_triggered()
 * \brief Loads the dictionary files only once
 * This function is only called once per project to load the dictionary file of the project,
 * dictionary files can be used to work on suggestions.
 */
bool LoadDataFlag = 1; //To load data only once
QString mFilename1, loadStr, loadStr1;
void MainWindow::on_actionLoadData_triggered()
{
    if (mProject.isProjectOpen())
    {
        if (LoadDataFlag)
        {
            QString initialText = ui->lineEdit->text();
            ui->lineEdit->setText("Loading Data...");
            QString  localmFilename1 = mFilename;
            string localmFilename1n = localmFilename1.toUtf8().constData();
            localmFilename1n = localmFilename1n.substr(0, localmFilename1n.find("page"));
            localmFilename1 = QString::fromStdString(localmFilename1n);

            on_actionLoadDict_triggered();       //sanskrit dictionary files are called
            loadStr += "\n";

            //!GEROCR IEROCR PWords and CPair files are loaded and reflected in terminal
            on_actionLoadOCRWords_triggered();
            on_actionLoadDomain_triggered();
            on_actionLoadSubPS_triggered();
            on_actionLoadConfusions_triggered();

            QString filepath = mProject.GetDir().absolutePath() + "/Dicts/synonyms.csv" ;
            loadFileCSV(synonym, synrows, filepath.toUtf8().constData());

            ui->lineEdit->setText(initialText);
            LoadDataFlag = 0;
            QMessageBox messageBox;
            messageBox.information(0, "Load Data", "Data has been loaded.");
        }
    }
}

/*!
 * \fn loadDict()
 * \param current project file location
 * \brief The path of the dictionary file is fetched and the files are returned in the map
 * these words are then fetched depending upon the word selected
 * \sa loadMap()
 */
bool loadDict(Project & project) {
    QString localmFilename1 = project.GetDir().absolutePath() + "/Dicts/" + "Dict";
    if (!QFile::exists(localmFilename1)) return false;
    loadMap(localmFilename1.toUtf8().constData(), Dict, "Dict");
    return true;
}

/*!
 * \fn on_actionLoadDict_triggered()
 * \brief The path of the dictionary file is fetched and the files are returned in the map
 * these words are then fetched depending upon the word selected
 * \sa loadDict()
 */
void MainWindow::on_actionLoadDict_triggered()
{
    loadDict(mProject);
}

/*!
 * \fn MainWindow::on_actionLoadOCRWords_triggered()
 * \brief Loads the OCR files
 * The path of the GEROCR and IEROCR file is fetched and the files are returned in the map which is again,
 * used as a suggestion depending upon the word selected
 * \sa LoadMapNV()
 */
void MainWindow::on_actionLoadOCRWords_triggered()
{
    QString localmFilename1 = mProject.GetDir().absolutePath() + "/Dicts/" + "GEROCR";
    cout << localmFilename1.toUtf8().constData() << endl;
    loadMapNV(localmFilename1.toUtf8().constData(), GBook, vGBook, "GBook"); localmFilename1 = mFilename1;
    cout << localmFilename1.toUtf8().constData() << endl;
    localmFilename1 = mProject.GetDir().absolutePath() + "/Dicts/" + "IEROCR";
    loadMapNV(localmFilename1.toUtf8().constData(), IBook, vIBook, "IBook");
    cout << GBook.size() << " " << IBook.size() << endl;

}

/*!
  \fn MainWindow::on_actionLoadDomain_triggered()
  \brief loads the common OCR files
 The path of the PWords file is fetched and the files are returned in the map which can be used
 for the suggestion feature
 \sa loadMapPWords()
 */
void MainWindow::on_actionLoadDomain_triggered()
{
    QString localmFilename1 = mProject.GetDir().absolutePath() + "/Dicts/" + "/PWords";
    loadMapPWords(vGBook, vIBook, PWords);
}

/*!
  \fn MainWindow::on_actionLoadSubPS_triggered()
  \brief the CPair files
    The path of the CPair files are fetched and the files are returned in the map which is returned
    to load the suggestions
  \sa loadmaptoTrie(), loadPwordsPatternstoTrie(), loadCPair()
 */
map<string, string> LSTM;
void MainWindow::on_actionLoadSubPS_triggered()
{
    size_t count = loadPWordsPatternstoTrie(TPWordsP, PWords);// justsubstrings not patterns exactly // PWordsP,
    QString localmFilename1 = mProject.GetDir().absolutePath() + "/Dicts/" + "CPair";

    loadCPairs(localmFilename1.toUtf8().constData(), CPairs, Dict, PWords);
    localmFilename1 = mFilename1;

    localmFilename1 = mProject.GetDir().absolutePath() + "/Dicts/" + "LSTM";
    ifstream myfile(localmFilename1.toUtf8().constData());
    if (myfile.is_open())
    {
        string str1, str2, line;
        while (getline(myfile, line))
        {
            istringstream slinenew(line); slinenew >> str1; slinenew >> str2;
            if (str2.size() > 0) LSTM[str1] = str2;
        }
    }
    cout << LSTM.size() << "LSTM Pairs Loaded";
    localmFilename1 = mFilename1;

    loadmaptoTrie(TPWords, PWords);
    loadmaptoTrie(TDict, Dict);
    loadmaptoTrie(TGBook, GBook);
    loadPWordsPatternstoTrie(TGBookP, GBook);
}

/*!
 * \fn MainWindow::on_actionLoadConfusions_triggered
 * \brief Loads the confusions for CPair
 */
void MainWindow::on_actionLoadConfusions_triggered()
{
    QString localmFilename1 = mProject.GetDir().absolutePath() + "/Dicts/" + "CPair";
    loadConfusions(localmFilename1.toUtf8().constData(), ConfPmap);
    localmFilename1 = mFilename;
}

/*!
 * \fn MainWindow::on_actionSugg_triggered
 * \brief Displays the context menu that has suggestion item
 * \note It works only when the data is loaded
 */
void MainWindow::on_actionSugg_triggered()
{
    /*Description
     * The function loads the context menu and waits for mouse event.
     * As soon as the mouse event is captured, the context menu is unloaded.
     */
    RightclickFlag = 1;
    QMouseEvent *ev1;
    mousePressEvent(ev1);      //to capture mouse events
    RightclickFlag = 0;

}

/*!
 * \fn MainWindow::on_actionUndo_triggered()
 * \brief undo the changes made QTextBrowser
 */
void MainWindow::on_actionUndo_triggered()
{
    if(!curr_browser || curr_browser->isReadOnly())
        return;
    curr_browser->undo();
}

/*!
 * \fn MainWindow::on_actionRedo_triggered()
 * \brief Redo the changes made in QTextBrowser
 */
void MainWindow::on_actionRedo_triggered()
{
    if(!curr_browser || curr_browser->isReadOnly())
        return;
    curr_browser->redo();
}

/*!
 * \fn MainWindow::on_actionFind_and_Replace_triggered()
 * \brief helps to find particular text and replaces them with new user entered text
 * \sa openFindAndReplace
 */
void MainWindow::on_actionFind_and_Replace_triggered()
{
    TextFinder *dialog = TextFinder::openFindAndReplace(this);
    dialog->show();
}

/*!
 * \fn MainWindow::on_actionCreateBest2OCR_triggered
 * \brief Creates a new text file named Best2ocrRep which is appended to its original file name.
 * The new file contains the best strings of two OCR by their their edit distance
 *
 * \note vGBook and vIBook contain the loaded words from both OCR
void MainWindow::on_actionCreateBest2OCR_triggered()
{
    if (curr_browser)
    {
        //! vGBook and vIBook contain the loaded words from both OCR
        int vGsz = vGBook.size(), vIsz = vIBook.size();
        int win = vGsz - vIsz;      //calculate the difference
        if (win < 0) win = -1 * win;   //convert to positive value if it is negative
        win = std::max(win, 5);

        int mineEdDis = 1000;

        //! search for a word(pre space, post space as well) in Indsenz within win sized window in GDocs and if found then add to PWords
        string localFilename = mFilename.toUtf8().constData();
        size_t loc = localFilename.find("Inds");
        localFilename = localFilename.substr(0, loc);
        localFilename = localFilename + "Best2ocrRep.txt";
        cout << "writing to" << localFilename << " please wait" << endl;

        std::ofstream best2(localFilename);
        for (int t = 0; t < vIsz; t++)
        {
            mineEdDis = 1000;
            string BestString1;
            string s1 = vIBook[t];

            for (int t1 = std::max(t - win, 0); t1 < min(t + win, vGsz); t1++)
            {
                int EdDis = editDist(vGBook[t1], s1);
                if (EdDis < mineEdDis) { mineEdDis = EdDis; BestString1 = vGBook[t1]; }
                if (vGBook[t1] == s1) { BestString1 = s1; break; }
            }
            if (s1 == BestString1)
            {
                vBest.push_back(s1); best2 << toDev(s1) << " ";
            }
            else
            {
                string s22 = bestIG(s1, BestString1, Dict); vBest.push_back(s22); best2 << toDev(s22) << " ";
            }
        }
        best2 << endl;
    }
}
*/
/*!
 * \fn MainWindow::on_actionCreateSuggestionLog_triggered
 * \brief The application crashes when CreateSuggestionLog is clicked under reports
 * \bug
void MainWindow::on_actionCreateSuggestionLog_triggered()
{
    map<size_t, size_t> mapCorrect, mapinCorrect, mapTyping, mapSugg1, mapSugg2, mapSugg3, mapSugg4, mapSugg5, mapSugg6, mapSugg7, mapSugg8, mapSugg9, mapSugg10;

    //! Load foders in strC and strI
    QString strI = gDirTwoLevelUp + "/Inds/"+ gCurrentPageName ;
    strI.replace(".html",".txt");
    QString strC = gDirTwoLevelUp + "/CorrectorOutput/"+ gCurrentPageName ;

    //! load text files one by one
    //! Load page1 of Inds
    size_t page_no = 1;
    QString filereport;

    while (1)
    {
        string nos = "0123456789";
        string localFilenameI = strI.toUtf8().constData();
        size_t loc = localFilenameI.find(".txt");
        string s = localFilenameI.substr(loc - 1, 1); // page-123.txt s = 3
        string no;

        vector<string> wrong, right;
        //! if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
        while (nos.find(s) != string::npos)
        {
            no = s + no; loc--; s = localFilenameI.substr(loc - 1, 1);
        }

        localFilenameI.replace(loc, no.size(), to_string(page_no));//to_string(stoi(no) + 1)

        //! Load page1 of C
        string localFilenameC = strC.toUtf8().constData();
        loc = localFilenameC.find(".txt");
        s = localFilenameC.substr(loc - 1, 1); // page-123.txt s = 3
        no = "";

        //! if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
        while (nos.find(s) != string::npos)
        {
            no = s + no; loc--; s = localFilenameC.substr(loc - 1, 1);
        }

        localFilenameC.replace(loc, no.size(), to_string(page_no));//to_string(stoi(no) + 1)

        //! load fileI in vecpI and
        vector<string> vecpI, vecpC;
        map<string, bool> isAscii;
        std::ifstream sIpage(localFilenameI);

        if (!(sIpage.is_open())) break;   // break the while loop for page_no
        string localstr;
        while (sIpage >> localstr) vecpI.push_back(toslp1(localstr)); sIpage.close();
        std::ifstream sCpage(localFilenameC);
        while (sCpage >> localstr)
        {
            if (hasM40PerAsci(localstr))
            {
                isAscii[toslp1(localstr)] = 1;
            }
            vecpC.push_back(toslp1(localstr));
        }

        sIpage.close();

        //! if 1st word is wrong generate suggestions
        int vGsz = vecpC.size(), vIsz = vecpI.size();
        if (vGsz > vIsz) mapTyping[page_no] = vGsz - vIsz;

        int win = vGsz - vIsz;
        if (win < 0) win = -1 * win;
        win = std::max(win, 5);

        //! search for a word(pre space, post space as well) in Indsenz within win sized window in GDocs and if found then add to PWords
        for (int t = 0; t < vIsz; t++)
        {
            size_t minedit = 1000;
            string s1 = vecpI[t];
            string sC;
            for (int t1 = std::max(t - win, 0); t1 < min(t + win, vGsz); t1++)
            {
                string sCt1 = vecpC[t1];
                size_t mineditIC = editDist(s1, sCt1);
                if (mineditIC < minedit) { minedit = mineditIC; sC = sCt1; }
                //if (sCt1 == s1) {WER++;
                                break; }
            }

            // now we have IndsWord in s1 and correct word in sC
            if ((sC == (s1)))
            {
                mapCorrect[page_no]++; //cout<< " in correct words ke liye if" << endl;
            }
            else if (!isAscii[sC])
            {
                wrong.push_back(s1);
                right.push_back(sC);
                vector<string>  Words1 = print5NearestEntries(TGBook, s1);

                if (Words1.size() == 0) Words1.push_back("");
                string nearestCOnfconfirmingSuggvec;
                vector<string> vec = Words1;

                int min = 100;
                for (size_t t = 0; t < vec.size(); t++)
                {
                    vector<string> wordConfusions; vector<int> wCindex;
                    int minFactor = loadWConfusionsNindex1(s1, vec[t], ConfPmap, wordConfusions, wCindex);
                    wordConfusions.clear(); wCindex.clear();
                    if (minFactor < min) { min = minFactor; nearestCOnfconfirmingSuggvec = vec[t]; }
                }

                if (nearestCOnfconfirmingSuggvec == (sC))
                {
                    mapSugg1[page_no]++;
                }
                if ((Words1[0] == (sC)))
                {
                    mapSugg2[page_no]++;
                }
                //else
                {
                    vector<string> Alligned = print5NearestEntries(TGBookP, s1);
                    if (Alligned.size() == 0) Alligned.push_back("");

                    string PairSugg = "";
                    if (Alligned.size() > 0) PairSugg = print2OCRSugg(s1, Alligned[0], ConfPmap, Dict);

                    if (PairSugg == sC)
                    {
                        mapSugg3[page_no]++;
                    }
                    //else
                    {
                        vector<string>  Words = print1OCRNearestEntries(toslp1(s1), vIBook);
                        if (Words.size() == 0) Words.push_back("");
                        if (Words[0] == (sC))
                        {
                            mapSugg4[page_no]++;
                        }
                        //else
                        {
                            string samassugg = SamasBreakLRCorrect(toslp1(s1), Dict, PWords, TPWords, TPWordsP);
                            if (samassugg == sC) { mapSugg5[page_no]++; }
                            //else
                            {
                                vector<string> PWords1 = print5NearestEntries(TPWords, s1);
                                if (PWords1.size() == 0) PWords1.push_back("");
                                if (PWords1[0] == (sC))
                                {
                                    mapSugg6[page_no]++;
                                }
                                //else
                                {
                                    string nearestCOnfconfirmingSuggvecFont;
                                    int min = 100;
                                    for (size_t t = 0; t < vec.size(); t++)
                                    {
                                        vector<string> wordConfusions; vector<int> wCindex;
                                        int minFactor = loadWConfusionsNindex1(s1, vec[t], ConfPmapFont, wordConfusions, wCindex);
                                        wordConfusions.clear(); wCindex.clear();
                                        if (minFactor < min) { min = minFactor; nearestCOnfconfirmingSuggvecFont = vec[t]; }
                                    }
                                    if (nearestCOnfconfirmingSuggvecFont == sC)
                                    {
                                        mapSugg7[page_no]++;
                                    }
                                    //else
                                    {
                                        vector<string> Wordsdict;
                                        {
                                            Wordsdict = print5NearestEntries(TDict, s1);
                                        }
                                        if ((Wordsdict.size() > 0) && (Wordsdict[0] == sC))
                                        {
                                            mapSugg8[page_no]++;
                                        }
                                        //else
                                        {
                                            string sugg9 = generatePossibilitesNsuggest(s1, TopConfusions, TopConfusionsMask, Dict, SRules);
                                            if (sugg9 == sC)
                                            {
                                                mapSugg9[page_no]++;
                                            }
                                            //else
                                            {
                                                if (LSTM[s1] == sC)
                                                {
                                                    mapSugg10[page_no]++;
                                                    cout << s1 << " lstm " << sC << endl;
                                                }
                                                else mapTyping[page_no]++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                mapTyping[page_no]++;
            }
        }// for 1st page ends

        mapinCorrect[page_no] = vIsz - mapCorrect[page_no];

        //!Loading PWords
        cout << "page_no = " << page_no << endl;
        loadMap(localFilenameC, PWords, "PWords");
        map<string, int> PWordspage;
        loadMap(localFilenameC, PWordspage, "PWordspage");
        loadmaptoTrie(TPWords, PWordspage);

        loadConfusionsFont(wrong, right, ConfPmap);
        loadConfusionsFont(wrong, right, ConfPmapFont);
        TopConfusions.clear(); TopConfusionsMask.clear();
        loadTopConfusions(ConfPmap, TopConfusions, TopConfusionsMask);

        page_no++;
        filereport = QString::fromStdString(localFilenameC);
    } //  while(1) ends

    page_no--;
    filereport.replace(("CorrectorOutput/page-" + QString::number(page_no) + ".txt"), "SuggReport1.txt");
    std::ofstream rep(filereport.toUtf8().constData());

    rep << "y0 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapinCorrect[i] << " "; rep << "];" << endl;
    rep << "y1 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapCorrect[i] << " "; rep << "];" << endl;
    rep << "y2 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapTyping[i] << " "; rep << "];" << endl;
    rep << "y3 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg1[i] << " "; rep << "];" << endl;
    rep << "y4 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg2[i] << " "; rep << "];" << endl;
    rep << "y5 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg3[i] << " "; rep << "];" << endl;
    rep << "y6 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg4[i] << " "; rep << "];" << endl;
    rep << "y7 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg5[i] << " "; rep << "];" << endl;
    rep << "y8 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg6[i] << " "; rep << "];" << endl;
    rep << "y9 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg7[i] << " "; rep << "];" << endl;
    rep << "y10 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg8[i] << " "; rep << "];" << endl;
    rep << "y11 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg9[i] << " "; rep << "];" << endl;
    rep << "y12 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg10[i] << " "; rep << "];" << endl;
    rep << "x = 1:" << page_no << ";" << endl << "plot(x,y0,x,y1,x,y2,x,y3,x,y4,x,y5,x,y6,x,y7,x,y8,x,y9,x,y10,x,y11);" << endl;
    rep << "legend(\'IncorrectWords\',\'CorrectWords\', \'#TypingCorrections\', \'#CorrectSugg1\',\'#CorrectSugg2\',\'#CorrectSugg3\',\'#CorrectSugg4\',\'#CorrectSugg5\',\'#CorrectSugg6\',\'#CorrectSugg7\',\'#CorrectSugg8\',\'#CorrectSugg9\' )" << endl;
    rep << "TotalSuggestions =" << "sum(y3+y4+y5+y6+y7+y8+y9+y10+y11)" << endl;
    rep << "TotalSuggestionsWithLSTM =" << "sum(y3+y4+y5+y6+y7+y8+y9+y10+y11+y12)" << endl;
}
*/

/*!
 * \fn MainWindow::on_actionCreateSuggestionLogNearestPriority_triggered
 * \badcode Application crashes when CreateSuggestionLogNearestPriority is clicked under reports
 * \bug
void MainWindow::on_actionCreateSuggestionLogNearestPriority_triggered()
{
    map<size_t, size_t> mapCorrect, mapinCorrect, mapTyping, mapSugg1, mapSugg2, mapSugg3, mapSugg4, mapSugg5, mapSugg6, mapSugg7, mapSugg8, mapSugg9, mapSugg10;

    //! Load foders in strC and strI
    QString strI = gDirTwoLevelUp + "/Inds/"+ gCurrentPageName ;
    strI.replace(".html",".txt");
    QString strC = gDirTwoLevelUp + "/CorrectorOutput/"+ gCurrentPageName ;

    //! load text files one by one
    //! Load page1 of Inds
    size_t page_no = 1;
    QString filereport;

    while (1)
    {
        string nos = "0123456789";
        string localFilenameI = strI.toUtf8().constData();
        size_t loc = localFilenameI.find(".txt");
        if(loc == string::npos)
            loc = localFilenameI.find(".html");
        string s = localFilenameI.substr(loc - 1, 1); // page-123.txt s = 3
        string no;

        //! if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
        while (nos.find(s) != string::npos)
        {
            no = s + no; loc--; s = localFilenameI.substr(loc - 1, 1);
        }

        localFilenameI.replace(loc, no.size(), to_string(page_no));

        //! Load page1 of C
        string localFilenameC = strC.toUtf8().constData();
        loc = localFilenameC.find(".txt");
        if(loc == string::npos)
            loc = localFilenameC.find(".html");
        s = localFilenameC.substr(loc - 1, 1);   // page-123.txt s = 3
        no = "";

        //! if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
        while (nos.find(s) != string::npos)
        {
            no = s + no; loc--; s = localFilenameC.substr(loc - 1, 1);
        }

        localFilenameC.replace(loc, no.size(), to_string(page_no));//to_string(stoi(no) + 1)

        //! load fileI in vecpI and
        vector<string> vecpI, vecpC;
        std::ifstream sIpage(localFilenameI);
        if (!(sIpage.is_open())) break; // break the while loop for page_no

        string localstr;
        while (sIpage >> localstr) vecpI.push_back(toslp1(localstr));
        sIpage.close();
        std::ifstream sCpage(localFilenameC);
        while (sCpage >> localstr) vecpC.push_back(toslp1(localstr));
        sIpage.close();

        //! if 1st word is wrong generate suggestions
        int vGsz = vecpC.size(), vIsz = vecpI.size();
        if (vGsz > vIsz) mapTyping[page_no] = vGsz - vIsz;
        int win = vGsz - vIsz;
        if (win < 0) win = -1 * win;
        win = std::max(win, 5);

        //! search for a word(pre space, post space as well) in Indsenz within win sized window in GDocs and if found then add to PWords
        for (int t = 0; t < vIsz; t++)
        {
            size_t minedit = 1000;
            string s1 = vecpI[t];
            string sC;
            for (int t1 = std::max(t - win, 0); t1 < min(t + win, vGsz); t1++)
            {
                string sCt1 = vecpC[t1];
                size_t mineditIC = editDist(s1, sCt1);
                if (mineditIC < minedit)
                {
                    minedit = mineditIC; sC = sCt1;
                }
                if (sCt1 == s1)
                {//WER++;
                    break;
                }
            }

            //! now we have IndsWord in s1 and correct word in sC
            if ((sC == (s1)))
            {
                mapCorrect[page_no]++;
            }
            else
            {
                vector<string>  Words1 = print5NearestEntries(TGBook, s1);
                vector<string> Alligned = print5NearestEntries(TGBookP, s1);
                vector<string> PWords1 = print5NearestEntries(TPWords, s1);
                string PairSugg = print2OCRSugg(s1, Alligned[0], ConfPmap, Dict);
                vector<string>  Words = print1OCRNearestEntries(toslp1(s1), vIBook);

                //! find nearest confirming to OCR Sugg from Book
                string nearestCOnfconfirmingSuggvec;
                vector<string> vec = Words1;
                int min = 100;
                for (size_t t = 0; t < vec.size(); t++)
                {
                    vector<string> wordConfusions; vector<int> wCindex;
                    int minFactor = loadWConfusionsNindex1(s1, vec[t], ConfPmap, wordConfusions, wCindex);
                    wordConfusions.clear(); wCindex.clear();
                    if (minFactor < min)
                    {
                        min = minFactor; nearestCOnfconfirmingSuggvec = vec[t];
                    }
                }

                //! find nearest confirming to OCR Sugg from PWords
                string nearestCOnfconfirmingSuggvec1;
                vector<string> vec1 = PWords1;
                min = 100;
                for (size_t t = 0; t < vec1.size(); t++)
                {
                    vector<string> wordConfusions; vector<int> wCindex;
                    int minFactor = loadWConfusionsNindex1(s1, vec1[t], ConfPmap, wordConfusions, wCindex);
                    wordConfusions.clear(); wCindex.clear();
                    if (minFactor < min)
                    {
                        min = minFactor; nearestCOnfconfirmingSuggvec1 = vec1[t];
                    }
                }

                vector<pair<int, string>> vecSugg, vecSugg1;
                map<string, int> mapSugg;
                string CSugg = CPair[toslp1(s1)];
                if (CSugg.size() > 0) mapSugg[toslp1(CSugg)]++;
                if (Words.size() > 0)  mapSugg[toslp1(Words[0])]++;
                if (Words1.size() > 0) mapSugg[toslp1(nearestCOnfconfirmingSuggvec)]++;
                if (PWords1.size() > 0) mapSugg[toslp1(nearestCOnfconfirmingSuggvec1)]++;
                if (PairSugg.size() > 0) mapSugg[toslp1(PairSugg)]++;
                mapSugg[SamasBreakLRCorrect(toslp1(s1), Dict, PWords, TPWords, TPWordsP)]++;

                map<string, int> mapsugg1;
                for (size_t ksugg1 = 0; ksugg1 < 5; ksugg1++)
                {
                    if (Words.size() > ksugg1)  mapsugg1[toslp1(Words[ksugg1])]++;
                    if (Words1.size() > ksugg1) mapsugg1[toslp1(Words1[ksugg1])]++;
                    if (PWords1.size() > ksugg1) mapsugg1[toslp1(PWords1[ksugg1])]++;
                }


                for (map<string, int>::const_iterator eptr = mapSugg.begin(); eptr != mapSugg.end(); eptr++)
                {
                    vecSugg.push_back(make_pair(editDist(toslp1(eptr->first), toslp1(s1)), eptr->first));
                }

                for (map<string, int>::const_iterator eptr = mapsugg1.begin(); eptr != mapsugg1.end(); eptr++)
                {
                    vecSugg1.push_back(make_pair(editDist(toslp1(eptr->first), toslp1(s1)), eptr->first));
                }

                sort(vecSugg.begin(), vecSugg.end()); sort(vecSugg1.begin(), vecSugg1.end());

                vecSugg.insert(vecSugg.end(), vecSugg1.begin(), vecSugg1.end());

                if ((vecSugg.size() > 0) && (vecSugg[0].second == sC)) mapSugg1[page_no]++;
                else if ((vecSugg.size() > 1) && (vecSugg[1].second == sC)) mapSugg2[page_no]++;
                else if ((vecSugg.size() > 2) && (vecSugg[2].second == sC)) mapSugg3[page_no]++;
                else if ((vecSugg.size() > 3) && (vecSugg[3].second == sC)) mapSugg4[page_no]++;
                else if ((vecSugg.size() > 4) && (vecSugg[4].second == sC)) mapSugg5[page_no]++;
                else if ((vecSugg.size() > 5) && (vecSugg[5].second == sC)) mapSugg6[page_no]++;
                else mapTyping[page_no]++;

            }
        }// for 1st page ends

        mapinCorrect[page_no] = vGsz - mapCorrect[page_no];
        loadMap(localFilenameC, PWords, "PWords");
        map<string, int> PWordspage;
        loadMap(localFilenameC, PWordspage, "PWordspage");
        loadmaptoTrie(TPWords, PWordspage);

        page_no++;
        filereport = QString::fromStdString(localFilenameC);
    } //  while(1) ends

    page_no--;
    filereport.replace(("CorrectorOutput/page-" + QString::number(page_no) + ".txt"), "SuggReportNearestPriority.txt");
    std::ofstream rep(filereport.toUtf8().constData());

    rep << "y0 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapinCorrect[i] << " "; rep << "];" << endl;
    rep << "y1 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapCorrect[i] << " "; rep << "];" << endl;
    rep << "y2 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapTyping[i] << " "; rep << "];" << endl;
    rep << "y3 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg1[i] << " "; rep << "];" << endl;
    rep << "y4 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg2[i] << " "; rep << "];" << endl;
    rep << "y5 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg3[i] << " "; rep << "];" << endl;
    rep << "y6 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg4[i] << " "; rep << "];" << endl;
    rep << "y7 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg5[i] << " "; rep << "];" << endl;
    rep << "y8 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg6[i] << " "; rep << "];" << endl;
    rep << "x = 1:" << page_no << ";" << endl << "plot(x,y0,x,y1,x,y2,x,y3,x,y4,x,y5,x,y6,x,y7,x,y8);" << endl;
    rep << "legend(\'IncorrectWords\',\'CorrectWords\', \'#TypingCorrections\', \'#UniqueCorrectSugg1\',\'#UniqueCorrectSugg2\',\'#UniqueCorrectSugg3\',\'#UniqueCorrectSugg4\',\'#UniqueCorrectSugg5\',\'#UniqueCorrectSugg6\' )" << endl;
}
*/

/*!
 * \fn MainWindow::on_actionErrorDetectionRep_triggered
 * \brief
 * \brief Detects if there's an error is loaded file or not
 *  Checks correct marked words if they are correct or incorrect and after mapping it adds them in PWords file.
 *  Additionally, it creates an error detection report.
 * \sa searchS1inGVec(), toslp1()
void MainWindow::on_actionErrorDetectionRep_triggered()
{
    //! Load foders in strC and strI
    QString strI = mFilename;
    QString strC = strI, strG = strI, strIF = strI, strCF = strI;

    strI.replace("CorrectorOutput", "Inds"); strC.replace("Inds", "CorrectorOutput");
    strG.replace("CorrectorOutput/page-1.txt", "GEROCR"); strG.replace("Inds/page-1.txt", "GEROCR");
    strIF.replace("CorrectorOutput/page-1.txt", "IEROCR"); strIF.replace("Inds/page-1.txt", "IEROCR");
    strCF.replace("CorrectorOutput/page-1.txt", "CorrectorOutput.txt"); strCF.replace("Inds/page-1.txt", "CorrectorOutput.txt");//Dict CorrectorOutput.txt for lower upper baseline resp

    //! load text files one by one
    string locstr;
    vector<string> iocr, gocr;
    std::ifstream sG(strG.toUtf8().constData());

    while (sG >> locstr) gocr.push_back(toslp1(locstr)); sG.close();
    std::ifstream sInd(strIF.toUtf8().constData());

    while (sInd >> locstr) iocr.push_back(toslp1(locstr)); sInd.close();
    cout << strG.toUtf8().constData() << " " << strIF.toUtf8().constData() << endl;
    cout << gocr.size() << " " << iocr.size() << endl;

    size_t winig = iocr.size() - gocr.size();
    if (iocr.size() < gocr.size()) winig = -1 * winig;
    size_t iocrdone = 0;     // will be used in each page of IEROCR

    map<string, int> mapCF;    // F for Full Book
    loadMap(strCF.toUtf8().constData(), mapCF, "CorrectorOutput.txt");
    cout << mapCF.size() << endl;

    //!Load page1 of Inds
    size_t page_no = 1;
    QString filereport;

    map<size_t, size_t> mapCorrect, mapInCorrect, mapCorrectMarkedCorrect, mapInCorrectMarkedCorrect;

    while (1)
    {
        string nos = "0123456789";
        string localFilenameI = strI.toUtf8().constData();
        size_t loc = localFilenameI.find(".txt");
        if(loc == string::npos)
            loc = localFilenameI.find(".html");
        string s = localFilenameI.substr(loc - 1, 1); // page-123.txt s = 3
        string no;

        //! if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
        while (nos.find(s) != string::npos)
        {
            no = s + no; loc--; s = localFilenameI.substr(loc - 1, 1);
        }

        localFilenameI.replace(loc, no.size(), to_string(page_no));//to_string(stoi(no) + 1)

        //!Load page1 of C
        string localFilenameC = strC.toUtf8().constData();
        loc = localFilenameC.find(".txt");
        if(loc == string::npos)
            loc = localFilenameC.find(".html");
        s = localFilenameC.substr(loc - 1, 1); // page-123.txt s = 3
        no = "";

        //! if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
        while (nos.find(s) != string::npos)
        {
            no = s + no; loc--; s = localFilenameC.substr(loc - 1, 1);
        }

        localFilenameC.replace(loc, no.size(), to_string(page_no));//to_string(stoi(no) + 1)

        //! load fileI in vecpI and
        vector<string> vecpI, vecpC;
        std::ifstream sIpage(localFilenameI);
        if (!(sIpage.is_open())) break; // break the while loop for page_no
        string localstr;

        while (sIpage >> localstr) vecpI.push_back(toslp1(localstr)); sIpage.close();
        std::ifstream sCpage(localFilenameC);

        while (sCpage >> localstr) vecpC.push_back(toslp1(localstr)); sIpage.close();

        //! if 1st word is correct and detected correct mark 1 else mark 0
        int vGsz = vecpC.size(), vIsz = vecpI.size();
        int win = vGsz - vIsz;
        if (win < 0) win = -1 * win;
        win = std::max(win, 5);

        //! search for a word(pre space, post space as well) in Indsenz within win sized window in GDocs and if found then add to PWords
        for (int t = 0; t < vIsz; t++)
        {
            size_t minedit = 1000;
            string s1 = vecpI[t]; //(vGBook[t1].find(s1) != string::npos) || (vGBook[t1] == s1)
            string sC;

            for (int t1 = std::max(t - win, 0); t1 < min(t + win, vGsz); t1++)
            {
                string sCt1 = vecpC[t1];
                size_t mineditIC = editDist(s1, sCt1);
                if (mineditIC < minedit)
                {
                    minedit = mineditIC; sC = sCt1;
                }
                if (sCt1 == s1)
                {//WER++;
                    break;
                }
            }

            //! now we have IndsWord in s1 and correct word in sC
            if ((sC == (s1)))
            {
                mapCorrect[page_no]++;
                if (searchS1inGVec(s1, iocrdone, gocr, winig)) mapCorrectMarkedCorrect[page_no]++;
            }
            else
            {
                mapInCorrect[page_no]++;  if (searchS1inGVec(s1, iocrdone, gocr, winig)) mapInCorrectMarkedCorrect[page_no]++;
            }
            iocrdone++;    //(PWords[s1] >0) searchS1inGVec(s1,iocrdone,gocr,winig) mapCF[s1]>0|| Dict[s1]>0
        }

        page_no++;
        filereport = QString::fromStdString(localFilenameC);
    } //  while(1) ends

    page_no--;
    filereport.replace(("CorrectorOutput/page-" + QString::number(page_no) + ".txt"), "ErrorDetect.txt");

    std::ofstream rep(filereport.toUtf8().constData());
    rep << "y0A = ["; for (size_t i = 1; i <= page_no; i++) rep << mapCorrectMarkedCorrect[i] << " "; rep << "];" << endl;
    rep << "y1A = ["; for (size_t i = 1; i <= page_no; i++) rep << mapInCorrectMarkedCorrect[i] << " "; rep << "];" << endl;
    rep << "y2A = ["; for (size_t i = 1; i <= page_no; i++) rep << mapCorrect[i] << " "; rep << "];" << endl;
    rep << "y3A = ["; for (size_t i = 1; i <= page_no; i++) rep << mapInCorrect[i] << " "; rep << "];" << endl;

    rep << "x = 1:" << page_no << ";" << endl << "plot(x,y2A,x,y3A,x,y0A,x,y1A);" << endl;
    rep << "legend(\'CorrectA\',\'InCorrectA\',\'CorrectMarkedcorrectA\', \'InCorrectMarkedCorrectA\')" << endl;

}
*/

/*!
 * \fn MainWindow::on_actionErrorDetectWithoutAdaptation_triggered
 * \brief
 * \sa toslp1(),
 * \brief Detects error in loaded file
 *  It checks correct marked words are correct or incorrect and after mapping it add them in PWords file.
 * \sa toslp1()
void MainWindow::on_actionErrorDetectWithoutAdaptation_triggered()
{
    //! Load foders in strC and strI
    QString strI = mFilename;
    QString strC = strI;
    strI.replace("CorrectorOutput", "Inds"); strC.replace("Inds", "CorrectorOutput");   // load text files one by one

    //! Load page1 of Inds
    size_t page_no = 1;
    QString filereport;
    map<size_t, size_t> mapCorrect, mapInCorrect, mapCorrectMarkedCorrect, mapInCorrectMarkedCorrect;
    while (1)
    {
        string nos = "0123456789";
        string localFilenameI = strI.toUtf8().constData();
        size_t loc = localFilenameI.find(".txt");
        if(loc == string::npos)
            loc = localFilenameI.find(".html");
        string s = localFilenameI.substr(loc - 1, 1);
        string no;

        //! if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
        while (nos.find(s) != string::npos)
        {
            no = s + no; loc--; s = localFilenameI.substr(loc - 1, 1);
        }

        localFilenameI.replace(loc, no.size(), to_string(page_no));

        //!Load page1 of C
        string localFilenameC = strC.toUtf8().constData();
        loc = localFilenameC.find(".txt");
        if(loc == string::npos)
            loc = localFilenameC.find(".html");

        s = localFilenameC.substr(loc - 1, 1);     // page-123.txt s = 3
        no = "";

        //! if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
        while (nos.find(s) != string::npos)
        {
            no = s + no; loc--; s = localFilenameC.substr(loc - 1, 1);
        }

        localFilenameC.replace(loc, no.size(), to_string(page_no));        // NOW localFilenameI and localFilenameC has page1 of both

        //! load fileI in vecpI and
        vector<string> vecpI, vecpC;
        std::ifstream sIpage(localFilenameI);
        if (!(sIpage.is_open())) break; // break the while loop for page_no

        string localstr;
        while (sIpage >> localstr) vecpI.push_back(toslp1(localstr)); sIpage.close();
        std::ifstream sCpage(localFilenameC);
        while (sCpage >> localstr) vecpC.push_back(toslp1(localstr)); sIpage.close();

        //! if 1st word is correct and detected correct mark 1 else mark 0
        int vGsz = vecpC.size(), vIsz = vecpI.size();
        int win = vGsz - vIsz;
        if (win < 0) win = -1 * win;
        win = std::max(win, 5);

        //! search for a word(pre space, post space as well) in Indsenz within win sized window in GDocs and if found then add to PWords
        for (int t = 0; t < vIsz; t++)
        {
            size_t minedit = 1000;
            string s1 = vecpI[t]; //(vGBook[t1].find(s1) != string::npos) || (vGBook[t1] == s1)
            string sC;
            for (int t1 = std::max(t - win, 0); t1 < min(t + win, vGsz); t1++)
            {
                string sCt1 = vecpC[t1];
                size_t mineditIC = editDist(s1, sCt1);
                if (mineditIC < minedit)
                {
                    minedit = mineditIC; sC = sCt1;
                }
                if (sCt1 == s1)
                {//WER++;
                    break;
                }
            }

            //! now we have IndsWord in s1 and correct word in sC
            if ((sC == (s1)))
            {
                mapCorrect[page_no]++;
                if ((GBook[s1] > 0) || (PWords[s1] > 0)) mapCorrectMarkedCorrect[page_no]++;
            }
            else
            {
                mapInCorrect[page_no]++; if ((GBook[s1] > 0) || (PWords[s1] > 0)) mapInCorrectMarkedCorrect[page_no]++;
            }
        }

        page_no++;
        filereport = QString::fromStdString(localFilenameC);
    }

    page_no--;
    filereport.replace(("CorrectorOutput/page-" + QString::number(page_no) + ".txt"), "ErrorDetectWOAdapt");
    std::ofstream rep(filereport.toUtf8().constData());

    rep << "y0 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapCorrectMarkedCorrect[i] << " "; rep << "];" << endl;
    rep << "y1 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapInCorrectMarkedCorrect[i] << " "; rep << "];" << endl;
    rep << "y2 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapCorrect[i] << " "; rep << "];" << endl;
    rep << "y3 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapInCorrect[i] << " "; rep << "];" << endl;
    rep << "x = 1:" << page_no << ";" << endl << "plot(x,y2,x,y3,x,y0,x,y1);" << endl;
    rep << "legend(\'Correct\',\'InCorrect\',\'CorrectMarkedcorrect\', \'InCorrectMarkedCorrect\')" << endl;
}

/*!
 * \fn MainWindow::on_actionErrorDetectionRepUniq_triggered()
 * \brief Creates Report in CorrectorOutput named SuggRepUniq.txt of all unique suggestions for current file incorrect words
 * \sa hasM40PerAsci(), loadWConfusionsNindex1(), loadMap(), loadMaptoTrie(), loadConfusionsFont(), loadTopConfusions()
void MainWindow::on_actionErrorDetectionRepUniq_triggered()
{
    map<size_t, size_t> mapCorrect, mapinCorrect, mapTyping, mapSugg1, mapSugg2, mapSugg3, mapSugg4, mapSugg5, mapSugg6, mapSugg7, mapSugg8, mapSugg9, mapSugg10;

    QString strI = mFilename;
    QString strC = strI;
    strI.replace("CorrectorOutput", "Inds"); strC.replace("Inds", "CorrectorOutput");
    size_t page_no = 1;
    QString filereport;

    while (1)
    {
        string nos = "0123456789";
        string localFilenameI = strI.toUtf8().constData();
        size_t loc = localFilenameI.find(".txt");
        if(loc == string::npos)
            loc = localFilenameI.find(".html");

        string s = localFilenameI.substr(loc - 1, 1);
        string no;

        vector<string> wrong, right;
        while (nos.find(s) != string::npos)
        {
            no = s + no; loc--; s = localFilenameI.substr(loc - 1, 1);
        }

        localFilenameI.replace(loc, no.size(), to_string(page_no));
        string localFilenameC = strC.toUtf8().constData();
        loc = localFilenameC.find(".txt");
        if(loc == string::npos)
            loc = localFilenameC.find(".html");

        s = localFilenameC.substr(loc - 1, 1);
        no = "";

        while (nos.find(s) != string::npos)
        {
            no = s + no; loc--; s = localFilenameC.substr(loc - 1, 1);
        }

        localFilenameC.replace(loc, no.size(), to_string(page_no));

        vector<string> vecpI, vecpC;
        map<string, bool> isAscii;
        std::ifstream sIpage(localFilenameI);
        if (!(sIpage.is_open())) break;
        string localstr;

        while (sIpage >> localstr) vecpI.push_back(toslp1(localstr));
        sIpage.close();

        std::ifstream sCpage(localFilenameC);
        while (sCpage >> localstr) { if (hasM40PerAsci(localstr)) { isAscii[toslp1(localstr)] = 1; }  vecpC.push_back(toslp1(localstr)); } sIpage.close();
        int vGsz = vecpC.size(), vIsz = vecpI.size();
        if (vGsz > vIsz) mapTyping[page_no] = vGsz - vIsz;
        int win = vGsz - vIsz;
        if (win < 0) win = -1 * win;
        win = std::max(win, 5);

        for (int t = 0; t < vIsz; t++)
        {
            size_t minedit = 1000;
            string s1 = vecpI[t];
            string sC;
            for (int t1 = std::max(t - win, 0); t1 < min(t + win, vGsz); t1++)
            {
                string sCt1 = vecpC[t1];
                size_t mineditIC = editDist(s1, sCt1);
                if (mineditIC < minedit) { minedit = mineditIC; sC = sCt1; }
                if (sCt1 == s1) { break; }
            }

            if ((sC == (s1)))
            {
                mapCorrect[page_no]++;
            }
            else if (!isAscii[sC])
            {
                wrong.push_back(s1); right.push_back(sC);
                vector<string>  Words1 = print5NearestEntries(TGBook, s1);
                if (Words1.size() == 0) Words1.push_back("");
                string nearestCOnfconfirmingSuggvec;
                vector<string> vec = Words1;
                int min = 100;
                for (size_t t = 0; t < vec.size(); t++)
                {
                    vector<string> wordConfusions; vector<int> wCindex;
                    int minFactor = loadWConfusionsNindex1(s1, vec[t], ConfPmap, wordConfusions, wCindex);
                    wordConfusions.clear(); wCindex.clear();
                    if (minFactor < min)
                    {
                        min = minFactor; nearestCOnfconfirmingSuggvec = vec[t];
                    }
                }

                if (nearestCOnfconfirmingSuggvec == (sC))
                {
                    mapSugg1[page_no]++;
                }
                else if ((Words1[0] == (sC)))
                {
                    mapSugg2[page_no]++;
                }
                else
                {
                    vector<string> Alligned = print5NearestEntries(TGBookP, s1); //6
                    if (Alligned.size() == 0) Alligned.push_back("");

                    string PairSugg = "";
                    if (Alligned.size() > 0) PairSugg = print2OCRSugg(s1, Alligned[0], ConfPmap, Dict);//3
                    if (PairSugg == sC)
                    {
                        mapSugg3[page_no]++;
                    }
                    else
                    {
                        vector<string>  Words = print1OCRNearestEntries(toslp1(s1), vIBook); // 4 primary doc based
                        if (Words.size() == 0) Words.push_back("");
                        if (Words[0] == (sC))
                        {
                            mapSugg4[page_no]++;
                        }
                        else
                        {
                            string samassugg = SamasBreakLRCorrect(toslp1(s1), Dict, PWords, TPWords, TPWordsP); // 5
                            if (samassugg == sC)
                            {
                                mapSugg5[page_no]++;
                            }
                            else
                            {
                                vector<string> PWords1 = print5NearestEntries(TPWords, s1); // 6
                                if (PWords1.size() == 0) PWords1.push_back("");
                                if (PWords1[0] == (sC))
                                {
                                    mapSugg6[page_no]++;
                                }
                                else
                                {
                                    string nearestCOnfconfirmingSuggvecFont;
                                    int min = 100;
                                    for (size_t t = 0; t < vec.size(); t++)
                                    {
                                        vector<string> wordConfusions; vector<int> wCindex;
                                        int minFactor = loadWConfusionsNindex1(s1, vec[t], ConfPmapFont, wordConfusions, wCindex);
                                        wordConfusions.clear(); wCindex.clear();
                                        if (minFactor < min)
                                        {
                                            min = minFactor; nearestCOnfconfirmingSuggvecFont = vec[t];
                                        }
                                    }
                                    if (nearestCOnfconfirmingSuggvecFont == sC)
                                    {
                                        mapSugg7[page_no]++;
                                    }
                                    else
                                    {
                                        vector<string> Wordsdict; {Wordsdict = print5NearestEntries(TDict, s1);
                                        }
                                        if ((Wordsdict.size() > 0) && (Wordsdict[0] == sC))
                                        {
                                            mapSugg8[page_no]++;
                                        }
                                        else
                                        {
                                            string sugg9 = generatePossibilitesNsuggest(s1, TopConfusions, TopConfusionsMask, Dict, SRules);
                                            if (sugg9 == sC)
                                            {
                                                mapSugg9[page_no]++;
                                            }
                                            else
                                            {
                                                if (LSTM[s1] == sC)
                                                {
                                                    mapSugg10[page_no]++;
                                                    cout << s1 << " lstm " << sC << endl;
                                                }
                                                else mapTyping[page_no]++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                mapTyping[page_no]++;
            } // else
        }// for 1st page ends

        mapinCorrect[page_no] = vIsz - mapCorrect[page_no];

        //Loading PWords:-
        cout << "page_no = " << page_no << endl;
        loadMap(localFilenameC, PWords, "PWords");

        map<string, int> PWordspage;
        loadMap(localFilenameC, PWordspage, "PWordspage");
        loadmaptoTrie(TPWords, PWordspage);
        loadConfusionsFont(wrong, right, ConfPmap);
        loadConfusionsFont(wrong, right, ConfPmapFont);

        TopConfusions.clear(); TopConfusionsMask.clear();
        loadTopConfusions(ConfPmap, TopConfusions, TopConfusionsMask);
        page_no++;

        filereport = QString::fromStdString(localFilenameC);
    } //  while(1) ends

    page_no--;
    filereport.replace(("CorrectorOutput/page-" + QString::number(page_no) + ".txt"), "SuggReportUniq1.txt");
    std::ofstream rep(filereport.toUtf8().constData());

    rep << "y0 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapinCorrect[i] << " "; rep << "];" << endl;
    rep << "y1 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapCorrect[i] << " "; rep << "];" << endl;
    rep << "y2 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapTyping[i] << " "; rep << "];" << endl;
    rep << "y3 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg1[i] << " "; rep << "];" << endl;
    rep << "y4 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg2[i] << " "; rep << "];" << endl;
    rep << "y5 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg3[i] << " "; rep << "];" << endl;
    rep << "y6 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg4[i] << " "; rep << "];" << endl;
    rep << "y7 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg5[i] << " "; rep << "];" << endl;
    rep << "y8 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg6[i] << " "; rep << "];" << endl;
    rep << "y9 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg7[i] << " "; rep << "];" << endl;
    rep << "y10 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg8[i] << " "; rep << "];" << endl;
    rep << "y11 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg9[i] << " "; rep << "];" << endl;
    rep << "y12 = ["; for (size_t i = 1; i <= page_no; i++) rep << mapSugg10[i] << " "; rep << "];" << endl;
    rep << "x = 1:" << page_no << ";" << endl << "plot(x,y0,x,y1,x,y2,x,y3,x,y4,x,y5,x,y6,x,y7,x,y8,x,y9,x,y10,x,y11);" << endl;
    rep << "legend(\'IncorrectWords\',\'CorrectWords\', \'#TypingCorrections\', \'#CorrectSugg1\',\'#CorrectSugg2\',\'#CorrectSugg3\',\'#CorrectSugg4\',\'#CorrectSugg5\',\'#CorrectSugg6\',\'#CorrectSugg7\',\'#CorrectSugg8\',\'#CorrectSugg9\' )" << endl;
    rep << "TotalSuggestions =" << "sum(y3+y4+y5+y6+y7+y8+y9+y10+y11)" << endl;
    rep << "TotalSuggestionsWithLSTM =" << "sum(y3+y4+y5+y6+y7+y8+y9+y10+y11+y12)" << endl;
}
*/

/*!
 * \fn MainWindow::on_actionAccuracyLog_triggered()
 * \brief Logs various accuracies to AccuracyLog.csv
 * Stores the following values in the csv:
 * Page Name
 * Percent Difference in Corrector and Verifier Text
 * Percent Character Level Accuracy (Corrector)
 * Percent Word Level Accuracy (Corrector)
 * Percent Change made by Corrector wrt OCR Text
 * Percent Word Errors
 * Percent Accuracy of OCR
 * \sa diff_match_patch::diff_main(),  Project::LevenshteinWithGraphemes(), Project::GetGraphemesCount()
*/
void MainWindow::on_actionAccuracyLog_triggered()
{
    QString qs1="", qs2="",qs3="";

    file = QFileDialog::getOpenFileName(this,"Open File from VerifierOutput Folder"); //open file
    int loc =  file.lastIndexOf("/");
    QString folder = file.mid(0,loc);      //fetch parent tdirectory

    QDir directory(folder);
    QStringList textFiles = directory.entryList((QStringList()<<"*.txt", QDir::Files)); //fetch all files in the parent directory

    int loc1 = folder.lastIndexOf("/");
    QString qcsvfolder =  folder.mid(0,loc1) +"/AccuracyLog.csv";
    string csvfolder = qcsvfolder.toUtf8().constData();

    std::ofstream csvFile(csvfolder);
    csvFile<<"Page Name,"<<"Errors (Word level),"<<"Errors (Character-Level),"<< "Accuracy of Corrector (Word level),"<<"Accuracy of Corrector (Character-Level)," <<"Changes made by Corrector(%)," <<"OCR Accuracy(w.rt. Verified Text)"<<"\n";

    foreach(QString fileName, textFiles)
    {

        string pageName = fileName.toUtf8().constData();
        fileName = folder + "/" + fileName;

        QString verifierText = fileName;
        QString correctorText = fileName.replace("VerifierOutput","CorrectorOutput"); //CAN CHANGE ACCORDING TO FILE STRUCTURE
        QString ocrText = fileName.replace("CorrectorOutput","Inds"); //CAN CHANGE ACCORDING TO FILE STRUCTURE
        ocrText.replace(".html",".txt");
        ocrText.replace("V1_", "");
        ocrText.replace("V2_", "");
        ocrText.replace("V3_", "");

        if(!ocrText.isEmpty())
        {
            QFile sFile(ocrText);
            if(sFile.open(QFile::ReadOnly | QFile::Text))
            {
                QTextStream in(&sFile);
                in.setCodec("UTF-8");
                qs1 = in.readAll().simplified();
            }

        }
        if(!correctorText.isEmpty())
        {
            QFile sFile(correctorText);
            if(sFile.open(QFile::ReadOnly | QFile::Text))
            {
                QTextStream in(&sFile);
                in.setCodec("UTF-8");
                qs2 = in.readAll().simplified();
            }

        }
        if(!verifierText.isEmpty())
        {
            QFile sFile(verifierText);
            if(sFile.open(QFile::ReadOnly | QFile::Text))
            {
                QTextStream in(&sFile);
                in.setCodec("UTF-8");
                qs3 = in.readAll().simplified();
                sFile.close();
            }

        }
        int l1,l2,l3, DiffOcr_Corrector,DiffCorrector_Verifier,DiffOcr_Verifier; float correctorChangesPerc,verifierChangesPerc,ocrErrorPerc;


        QTextDocument doc;

        doc.setHtml(qs2);
        qs2 = doc.toPlainText().replace(" \n","\n");

        doc.setHtml(qs3);
        qs3 = doc.toPlainText().replace(" \n","\n");

        l1 = mProject.GetGraphemesCount(qs1); l2 = mProject.GetGraphemesCount(qs2); l3 = mProject.GetGraphemesCount(qs3);
        if(qs1=="" | qs2 == "" | qs3 == "")
        {
            continue;
        }

        diff_match_patch dmp;

        auto diffs1 = dmp.diff_main(qs1,qs2);
        DiffOcr_Corrector = mProject.LevenshteinWithGraphemes(diffs1);
        correctorChangesPerc = ((float)(DiffOcr_Corrector)/(float)l2)*100;
        if(correctorChangesPerc>100)
            correctorChangesPerc = ((float)(DiffOcr_Corrector)/(float)l1)*100;
        correctorChangesPerc = (((float)lround(correctorChangesPerc*100))/100);

        auto diffs2 = dmp.diff_main(qs2,qs3);
        DiffCorrector_Verifier = mProject.LevenshteinWithGraphemes(diffs2);
        verifierChangesPerc = ((float)(DiffCorrector_Verifier)/(float)l3)*100;
        if(verifierChangesPerc>100)
            verifierChangesPerc = ((float)(DiffCorrector_Verifier)/(float)l2)*100;
        verifierChangesPerc = (((float)lround(verifierChangesPerc*100))/100);
        float correctorCharAcc =100- (((float)lround(verifierChangesPerc*100))/100); //Corrector accuracy = 100-changes mabe by Verfier

        auto diffs3 = dmp.diff_main(qs1,qs3);
        DiffOcr_Verifier = mProject.LevenshteinWithGraphemes(diffs3);
        ocrErrorPerc = ((float)(DiffOcr_Verifier)/(float)l3)*100;
        if(ocrErrorPerc>100)
            ocrErrorPerc = ((float)(DiffOcr_Verifier)/(float)l1)*100;
        float ocrAcc = 100 - (((float)lround(ocrErrorPerc*100))/100);


        auto a = dmp.diff_linesToChars(qs2, qs3); //LinesToChars modifed for WordstoChar in diff_match_patch.cpp
        auto lineText1 = a[0].toString();
        auto lineText2 = a[1].toString();
        auto lineArray = a[2].toStringList();
        int wordCount2 = qs2.simplified().count(" ");
        int wordCount3 = qs3.simplified().count(" ");
        auto diffs = dmp.diff_main(lineText1, lineText2);
        int worderrors = dmp.diff_levenshtein(diffs);
        dmp.diff_charsToLines(diffs, lineArray);

        float correctorwordaccuracy = (float)(worderrors)/(float)wordCount3*100;
        if(correctorwordaccuracy>100)
            correctorwordaccuracy = (float)(worderrors)/(float)wordCount2*100;
        correctorwordaccuracy = (((float)lround(correctorwordaccuracy*100))/100);

        csvFile<<pageName<<","<<worderrors<<","<<DiffCorrector_Verifier<<","<< correctorwordaccuracy<<","<<correctorCharAcc<<"," <<correctorChangesPerc<<","<<ocrAcc<<"\n";

    }

    csvFile.close();

}

/*!
 * \fn MainWindow::on_actionViewAverageAccuracies_triggered()
 * \brief Calculates the average accuracy of the submission based upon the comments and the csv file input which depend upon the
 * page changes. Also updates in the csv file of the current project.
 * \sa AverageAccuracies(),readJsonFile()
 */
void MainWindow::on_actionViewAverageAccuracies_triggered()
{
    QString commentFilename = gDirTwoLevelUp + "/Comments/comments.json";
    QString csvFile = gDirTwoLevelUp + "/Comments/AverageAccuracies.csv";
    QString pagename = gCurrentPageName;
    pagename.replace(".txt", "");
    pagename.replace(".html", "");

    float avgcharacc = 0, avgwordacc = 0, avgrating = 0; int avgcharerrors = 0, avgworderrors = 0;

    QJsonObject mainObj = readJsonFile(commentFilename);

    avgcharacc = mainObj["AverageCharAccuracy"].toDouble();
    avgwordacc = mainObj["AverageWordAccuracy"].toDouble();
    avgcharerrors = mainObj["AverageCharErrors"].toInt();
    avgworderrors = mainObj["AverageWordErrors"].toInt();

    AverageAccuracies *aa = new AverageAccuracies(csvFile, avgwordacc, avgcharacc, avgworderrors, avgcharerrors);
    aa->show();
}

/*!
 * \fn MainWindow::on_actionCPair_triggered()
 * \brief generates a wrong to right pair
 * A pair of 1 wrong word to 1 right word
 * \sa slpNPatternDict::generatePairs()
void MainWindow::on_actionCPair_triggered()
{
    QString strI = mFilename;
    QString strC = strI;
    strI.replace("CorrectorOutput", "Inds"); strC.replace("Inds", "CorrectorOutput");
    size_t page_no = 1;
    string localFilenameN = strI.toUtf8().constData();
    size_t loc1 = localFilenameN.find("Inds");
    string s1 = localFilenameN.substr(0, loc1);
    std::ofstream repx(s1 + "Report/CPair");

    while (1)
    {
        cout << page_no << endl;
        string nos = "0123456789";
        string localFilenameI = strI.toUtf8().constData();
        size_t loc = localFilenameI.find(".txt");
        if(loc == string::npos)
            loc = localFilenameI.find(".html");
        string s = localFilenameI.substr(loc - 1, 1);
        string no;

        while (nos.find(s) != string::npos)
        {
            no = s + no; loc--; s = localFilenameI.substr(loc - 1, 1);
            localFilenameI.replace(loc, no.size(), to_string(page_no));
            string localFilenameC = strC.toUtf8().constData();
            loc = localFilenameC.find(".txt");
            if(loc == string::npos)
                loc = localFilenameC.find(".html");
            s = localFilenameC.substr(loc - 1, 1);
            no = "";

            //! if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
            while (nos.find(s) != string::npos)
            {
                no = s + no; loc--; s = localFilenameC.substr(loc - 1, 1);
            }

            localFilenameC.replace(loc, no.size(), to_string(page_no));

            //! NOW localFilenameI and localFilenameC has page1 of both
            std::ifstream sIpage(localFilenameI);
            if (!(sIpage.is_open())) break;
            std::ifstream sCpage(localFilenameI);
            if (!(sCpage.is_open())) break;
            vector<string> wrong1, right1;
            generatePairs(wrong1, right1, localFilenameI, localFilenameC);
            size_t sz = wrong1.size();
            if (sz < right1.size()) sz = right1.size();
            for (size_t t = 0; t < sz; t++)
            {
                if (right1[t] != "") repx << wrong1[t] << "\t" << right1[t] << endl;//
            }

            page_no++;
        }
    }
}
*/

/*!
 * \fn MainWindow::on_actionPrimarySecOCRPair_triggered()
 * \brief Compares primary ocr to secondary ocr with the help of file inputs
 * and generates pairs with the help of generatePairsSpaced which generates
 * words with a space in betwen.
 * \sa slpNPatternDict::generatePairsSpaced()
void MainWindow::on_actionPrimarySecOCRPair_triggered()
{
    QString file1 = QFileDialog::getOpenFileName(this, "Open a File");

    if (!file1.isEmpty())
    {
        QFile sFile(file1);
        if (sFile.open(QFile::ReadOnly | QFile::Text))
        {
            string localFilenameN = file1.toUtf8().constData();
            int loc = localFilenameN.find("IEROCR");
            string localFilenameG = localFilenameN.substr(0, loc) + "GEROCR";

            std::ofstream op(localFilenameN + "ocrPairs");
            vector<string> wrong1, right1;
            generatePairsSpaced(wrong1, right1, localFilenameN, localFilenameG);    //Files are compared with words

            size_t sz = wrong1.size();
            if (sz < right1.size()) sz = right1.size();

            for (size_t t = 0; t < sz; t++)
            {
                if (right1[t] != "") op << wrong1[t] << "\t" << right1[t] << endl;
            }
        }
    }
}
*/

/*!
 * \fn MainWindow::on_actionCPairIEROcrVsCorrect_triggered()
 * \brief CPairs based upon Inds are generated with the help of
 * IEROCR files and these words are generated with the help of generatePairsIEROCR()
 * \sa slpNPatternDict::generatePairsIEROCR
void MainWindow::on_actionCPairIEROcrVsCorrect_triggered()
{
    QString strI1 = mFilename;    // Load foders in strC and strI

    string strInew = strI1.toUtf8().constData();
    size_t locI = strInew.find("Inds");
    string strI = strInew.substr(0, locI) + "IEROCR";
    string strC = strInew.substr(0, locI) + "Correct";

    //! load text files one by one
    string localFilenameN = strI1.toUtf8().constData();
    size_t loc1 = localFilenameN.find("Inds");
    string s1 = localFilenameN.substr(0, loc1);
    string sRepx = s1 + "Reports/inputx";
    string sRepy = s1 + "Reports/inputy";

    vector<string> wrong1, right1;
    generatePairsIEROCR(strI, strC, sRepx, sRepy);
}
*/

/*!
 * \fn MainWindow::on_actionCPairGEROcrVsCorrect_triggered()
 * \brief CPairs based upon Inds are generated with the help of
 * GEROCR files and these words are generated with the help of generatePairsGEROCR()
 * \sa slpNPatternDict::generatePairsGEROCR
void MainWindow::on_actionCPairGEROcrVsCorrect_triggered()
{
    QString strI1 = mFilename;       // Load foders in strC and strI

    string strInew = strI1.toUtf8().constData();
    size_t locI = strInew.find("Inds");
    string strI = strInew.substr(0, locI) + "GEROCR";
    string strC = strInew.substr(0, locI) + "Correct";

    //! load text files one by one
    string localFilenameN = strI1.toUtf8().constData();
    size_t loc1 = localFilenameN.find("Inds");
    string s1 = localFilenameN.substr(0, loc1);
    string sRepx = s1 + "Reports/inputx";
    string sRepy = s1 + "Reports/inputy";

    vector<string> wrong1, right1;
    generatePairsIEROCR(strI, strC, sRepx, sRepy);
}
*/

/*!
 * \fn MainWindow::on_actionAllFontProperties_triggered()
 * \brief Opens a pop up font properties selector and applies chosen properties to font.
 * The font selector lets you choose:
 * Font face, font size, variations of those fonts (regular, bold, italic).
 * The font selector is the Operating System's native font selector.
 * All fonts installed in the system will appear in the selector
 * (a software restart after font installation/ reopening the selector might be required).
*/
void MainWindow::on_actionAllFontProperties_triggered()
{
    if(!curr_browser || curr_browser->isReadOnly())
        return;
    QFont initialFont = curr_browser->font();      // initial font face
    QTextCursor cursor = curr_browser->textCursor();

    auto pointsize = curr_browser->fontPointSize();

    if(pointsize) initialFont.setPointSize(pointsize);      // initial font size
    bool ok;
    QFont font = QFontDialog::getFont(&ok, initialFont, this);

    //!Filter the font properities
      QTextCharFormat applyFont;
      qreal wgt = font.pointSize();
      QString fam = font.family();
      bool strike = font.strikeOut();
      bool underline = font.underline();
      qreal LetterSpacing=font.letterSpacing();
      qreal WordSpacing = font.wordSpacing();
      int stretch = font.stretch();
      auto styleHint = font.styleHint();
      auto styleStrategy = font.styleStrategy();
      auto letterSpacingType = font.letterSpacingType();
      bool overline = font.overline();
      bool fixedpitch = font.fixedPitch();
      auto hintingpref = font.hintingPreference();

      applyFont.setFontPointSize(wgt);
      applyFont.setFontFamily(fam);
      applyFont.setFontStrikeOut(strike);
      applyFont.setFontUnderline(underline);
      applyFont.setFontLetterSpacing(LetterSpacing);
      applyFont.setFontWordSpacing(WordSpacing);
      applyFont.setFontStretch(stretch);
      applyFont.setFontStyleHint(styleHint,styleStrategy);
      applyFont.setFontLetterSpacingType(letterSpacingType);
      applyFont.setFontOverline(overline);
      applyFont.setFontFixedPitch(fixedpitch);
      applyFont.setFontHintingPreference(hintingpref);


      //! Apply bold and italics if present
      if(font.bold())
      {
          qreal weight  =font.weight();
          applyFont.setFontWeight(weight);
      }
      if(font.italic())
      {
          bool Italics = font.italic();
          applyFont.setFontItalic(Italics);
      }

    /*! If user clicks OK then change to selected font with properties*/
    if(ok)
    {
        cursor.mergeCharFormat(applyFont);
        curr_browser->textCursor().mergeCharFormat(applyFont);
    }
}

/*!
 * \fn MainWindow::on_actionBold_triggered()
 * \brief Sets the font weight to bold
*/
void MainWindow::on_actionBold_triggered()
{
    if(!curr_browser || curr_browser->isReadOnly())
        return;
    QTextCursor cursor = curr_browser->textCursor();
    bool isBold = cursor.charFormat().font().bold();
    QTextCharFormat fmt;
    /*
     * If the font-weight value is bold then
     * it will change it to normal else bold.
    */
    fmt.setFontWeight(isBold ? QFont::Normal : QFont::Bold);
    cursor.mergeCharFormat(fmt);
    curr_browser->mergeCurrentCharFormat(fmt);
  //  curr_browser->setFont(QFontDialog::getFont(0,QFont::Bold,curr_browser->font()));
   // cursor.setCharFormat(QFontDialog::getFont(0,QFont::Bold,curr_browser->font()));
}

/*!
 * \fn MainWindow::on_actionUnBold_triggered()
 * \brief Sets the font weight to regular
*/
void MainWindow::on_actionUnBold_triggered()
{
    if(!curr_browser || curr_browser->isReadOnly())
        return;
    QTextCharFormat format;
    format.setFontWeight(QFont::Normal);
    curr_browser->textCursor().mergeCharFormat(format);
}

/*!
 * \fn MainWindow::on_actionItalic_triggered()
 * \brief Sets the font style to italic
*/
void MainWindow::on_actionItalic_triggered()
{
    if(!curr_browser || curr_browser->isReadOnly())
        return;

    QTextCursor cursor = curr_browser->textCursor();                        // initialize cursor position at text cursor's position
    bool isItalic = cursor.charFormat().font().italic();                    // check if character under cursor is italic or not

    QTextCharFormat fmt;
    fmt.setFontItalic(isItalic ? false : true);                             // if font is italic set font to regular, else set it to italic

    cursor.mergeCharFormat(fmt);
    curr_browser->mergeCurrentCharFormat(fmt);                              // Merge current character format to character under cursor's format (previous properties + italic/non italic)
}

/*!
 * \fn MainWindow::on_actionNonitalic_triggered()
 * \brief Resets the font style to non italic
*/
void MainWindow::on_actionNonitalic_triggered()
{
    if(!curr_browser || curr_browser->isReadOnly())
        return;
    QTextCharFormat format;
    format.setFontItalic(false);
    curr_browser->textCursor().mergeCharFormat(format);
}

/*!
 * \fn MainWindow::on_actionHighlight_triggered()
 * \brief Highlights selected text in text browser and then calls LogHighlights()
 * Only Verifiers can highlight the text, correctors can only remove highlights.
 * Takes the start and end position of cursor and goes to the middle of the word,
 * then formats the word.LogHighlights() is called only when a highlight is made.
 * \note Text Highlight works by changing the background colour to yellow
 * \sa LogHighlights()
*/
void MainWindow::on_actionHighlight_triggered()
{
     //! Check if text browser exists AND it is NOT in read only mode
     if(curr_browser && !curr_browser->isReadOnly())
     {
        //! Verifier gets to add and remove highlight the text
        if(isVerifier)
        {
            QTextCursor cursor = curr_browser->textCursor();
            QString text = cursor.selectedText().toUtf8().constData();
            int pos1 = curr_browser->textCursor().selectionStart();
            int pos2 = curr_browser->textCursor().selectionEnd();

            int cursorpos = round(((float)(pos1 + pos2)) / 2);      // goes to mid of the selection
            cursor.setPosition(cursorpos);

            QTextCharFormat  format = cursor.charFormat();         // gets word character format properties

            //! If word background is already yellow, set it to transparent, else set it to yellow (yellow is the highlight colour).
            if (format.background() == Qt::yellow)
            {
                format.setBackground(Qt::transparent);
            }
            else
            {
                format.setBackground(Qt::yellow);

                LogHighlights(text);       // Add log to HighlightsLog file if word is highlighted
            }
            curr_browser->textCursor().mergeCharFormat(format);        // Set format at current cursor
        }
        else
        {
            curr_browser->setTextBackgroundColor(Qt::transparent); //Correctors are only allowed to remove highlights.
        }
    }
}

/*!
 * \fn MainWindow::LogHighlights()
 * \param QString text
 * \brief Stores highlight metadata to JSON files
 * \note Meta data includes: Word highlighted, timestamp, time elapsed, page name
*/
void MainWindow::LogHighlights(QString word) //Verifier Only
{
    //!Highlighted Time meta data is stored
    QString dir = mProject.GetDir().absolutePath();

    QString highlightsFilename = gDirTwoLevelUp + "/Comments/HighlightsLog.json"; // load the highlight file name
    QString pagename = gCurrentPageName;                                          // load the current page name (in the text browser)

    pagename.replace(".txt", "");                                                 // remove extension from file name to use it as a key
    pagename.replace(".html", "");

    QJsonObject mainObj = readJsonFile(highlightsFilename);                       // read JSON file into mainObj
    QJsonObject page = mainObj.value(pagename).toObject();                        // set values for page name
    QJsonObject highlights;                                                       // make a new JSON object to store new metadata

    int nMilliseconds = myTimer.elapsed();
    secs = nMilliseconds / 1000;

    QString time = QTime::currentTime().toString();
    highlights["Word"] = word;
    highlights["Timestamp"] = time;
    highlights["Time Elapsed (s)"] = secs;
    highlights["Page Name"] = pagename;

    page.remove(time);
    page.insert(time, highlights);
    mainObj.remove(pagename);
    mainObj.insert(pagename, page);

    writeJsonFile(highlightsFilename, mainObj);
}

/*!
 * \fn MainWindow::on_actionLeftAlign_triggered()
 * \brief Sets the browser text alignment to Left Align
*/
void MainWindow::on_actionLeftAlign_triggered()
{
    if(!curr_browser || curr_browser->isReadOnly())
        return;
    curr_browser->setAlignment(Qt::AlignLeft);
}

/*!
 * \fn MainWindow::on_actionRightAlign_triggered()
 * \brief Sets the browser text alignment to Right Align
*/
void MainWindow::on_actionRightAlign_triggered()
{
    if(!curr_browser || curr_browser->isReadOnly())
        return;
    curr_browser->setAlignment(Qt::AlignRight);
}

/*!
 * \fn MainWindow::on_actionCentreAlign_triggered()
 * \brief Sets the browser text alignment to Center Align
*/
void MainWindow::on_actionCentreAlign_triggered()
{
    if(!curr_browser || curr_browser->isReadOnly())
        return;
    curr_browser->setAlignment(Qt::AlignCenter);
}

/*!
 * \deprecated
 * \fn MainWindow::on_action_JustifiedAlign_triggered()
 * \brief Justifies the text.
 * Here, whenever there is a break in the text, that is being replaced by space
 * and then text is placed in-between paragraph tags. After that, the following
 * selected text is justisfied aligned.
*/
void MainWindow::on_actionJusitfiedAlign_triggered() //Not used, does not work as intended
{
    if(!curr_browser || curr_browser->isReadOnly())
        return;
    auto cursor = curr_browser->textCursor();
    auto selected = cursor.selection();
    cursor.removeSelectedText();
    QString sel = selected.toHtml();
    sel.replace("<br />" ," ");
    sel = "</p><p>" + sel + "</p><p>";
    auto newFrag = selected.fromHtml(sel);
    cursor.insertFragment(newFrag);
    curr_browser->setAlignment(Qt::AlignJustify);
}

/*!
 *  \fn MainWindow::on_actionSuperscript_triggered()
 *  \brief toggles superscript for selected text/ character at cursor
*/
void MainWindow::on_actionSuperscript_triggered() {

    if(!curr_browser || curr_browser->isReadOnly())
        return;

    auto cursor = curr_browser->textCursor();

    QTextCharFormat fmt;

    fmt.setVerticalAlignment((cursor.charFormat().verticalAlignment() == QTextCharFormat::AlignSuperScript)?\
                                 QTextCharFormat::AlignNormal : \
                                 QTextCharFormat::AlignSuperScript
                                 ); // Ternary operator for isSuperscripted ? alignNormal : alignSuperscript

    cursor.mergeCharFormat(fmt);
    curr_browser->mergeCurrentCharFormat(fmt);
}

/*!
 *  \fn MainWindow::on_actionSubscript_triggered()
 *  \brief toggles subscript for selected text/ character at cursor
*/
void MainWindow::on_actionSubscript_triggered() {

    if(!curr_browser || curr_browser->isReadOnly())
        return;

    auto cursor = curr_browser->textCursor();

    QTextCharFormat fmt;
    fmt.setVerticalAlignment((cursor.charFormat().verticalAlignment() == QTextCharFormat::AlignSubScript)? QTextCharFormat::AlignNormal : QTextCharFormat::AlignSubScript);

    cursor.mergeCharFormat(fmt);
    curr_browser->mergeCurrentCharFormat(fmt);
}

/*!
 * \fn MainWindow::on_actionInsert_Horizontal_Line_triggered()
 * \brief Draws a horizontal rule a line below the cursor.
 * Uses html to insert a horizontal rule using <hr> tag.
 * Selecting text and then using this fuctionality will clear the text,
 * and then insert a horizontal rule below it.
 * \note The text browser is a rich text field, so html tags and styling can be used seamlessly.
*/
void MainWindow::on_actionInsert_Horizontal_Line_triggered()
{
    if(!curr_browser || curr_browser->isReadOnly())
        return;
    curr_browser->insertHtml("<hr>");
}

/*!
 * \fn MainWindow::on_actionFontBlack_triggered()
 * \brief Sets the current font colour to black.
 * \note There are no further colour properties provided by the editor.
*/
void MainWindow::on_actionFontBlack_triggered()
{
    if(!curr_browser || curr_browser->isReadOnly())
        return;
    curr_browser->setTextColor(Qt::black);
}

/*!
 * \fn MainWindow::on_actionInsert_Tab_Space_triggered()
 * \brief inserts tab (4 whitespaces) at cursor
*/
void MainWindow::on_actionInsert_Tab_Space_triggered()
{
    if(!curr_browser || curr_browser->isReadOnly())
        return;
    curr_browser->insertPlainText("    ");
}

/*!
 * \fn MainWindow::on_actionInsert_Table_2_triggered()
 * \brief Inserts table at text cursor
 * Creates a dialog to insert the numbr of rows and columns.
*/
void MainWindow::on_actionInsert_Table_2_triggered()
{
    if(!curr_browser || curr_browser->isReadOnly())
        return;

    QDialog dialog(this);
    QFormLayout form(&dialog);      // Use a layout allowing to have a label next to each field
    form.addRow(new QLabel("Insert Table", this));                                  // Create a dialog for asking table dimensions

    //! Add the lineEdits with their respective labels
    QLineEdit *rows = new QLineEdit(&dialog);
    QLineEdit *columns = new QLineEdit(&dialog);                                    // Add lineEdits to get Rows
    form.addRow("Rows", rows);                                                      // Add lineEdits to get Columns
    form.addRow("Columns", columns);

    //! Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog); // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    //! Show the dialog as modal
    if (dialog.exec() == QDialog::Accepted)
    {

        QTextTableFormat tf;
        tf.setBorderBrush(Qt::black);
        tf.setCellSpacing(0);
        tf.setCellPadding(7);
        QTextCursor cursor = curr_browser->textCursor();
        cursor.insertTable(rows->text().toInt(),columns->text().toInt(),tf);
    }
}

/*!
 * \fn MainWindow::on_actionInsert_Columnleft_triggered()
 * \brief Inserts Column to the left of table
*/
void MainWindow::on_actionInsert_Columnleft_triggered()
{
    if(!curr_browser || curr_browser->isReadOnly())
        return;
    if(curr_browser->textCursor().currentTable())
    {
        QTextTable *currentTable = curr_browser->textCursor().currentTable();
        QTextTableCell currentCell = currentTable->cellAt(curr_browser->textCursor());
        currentTable->insertColumns(currentCell.column(),1);
    }
}

/*!
 * \fn MainWindow::on_actionInsert_Columnright_triggered()
 * \brief Inserts Column to the right of table
*/
void MainWindow::on_actionInsert_Columnright_triggered()
{
    if(!curr_browser || curr_browser->isReadOnly())
        return;
    if(curr_browser->textCursor().currentTable())
    {
        QTextTable *currentTable = curr_browser->textCursor().currentTable();
        QTextTableCell currentCell = currentTable->cellAt(curr_browser->textCursor());
        currentTable->insertColumns(currentCell.column()+1,1);
    }
}

/*!
 * \fn MainWindow::on_actionInsert_Rowabove_triggered()
 * \brief Inserts Row above the table
*/
void MainWindow::on_actionInsert_Rowabove_triggered()
{
    if(!curr_browser || curr_browser->isReadOnly())
        return;
    if(curr_browser->textCursor().currentTable())
    {
        QTextTable *currentTable = curr_browser->textCursor().currentTable();
        QTextTableCell currentCell = currentTable->cellAt(curr_browser->textCursor());
        currentTable->insertRows(currentCell.row(),1);
    }
}

/*!
 * \fn MainWindow::on_actionInsert_Rowbelow_triggered()
 * \brief Inserts Row below the table
*/
void MainWindow::on_actionInsert_Rowbelow_triggered()
{
    if(!curr_browser || curr_browser->isReadOnly())
        return;
    if(curr_browser->textCursor().currentTable())
    {
        QTextTable *currentTable = curr_browser->textCursor().currentTable();
        QTextTableCell currentCell = currentTable->cellAt(curr_browser->textCursor());
        currentTable->insertRows(currentCell.row()+1,1);
    }
}

/*!
 * \fn MainWindow::on_actionRemove_Column_triggered()
 * \brief Delete selected column
*/
void MainWindow::on_actionRemove_Column_triggered()
{
    if(!curr_browser || curr_browser->isReadOnly())
        return;
    if(curr_browser->textCursor().currentTable())
    {
        QTextTable *currentTable = curr_browser->textCursor().currentTable();
        QTextTableCell currentCell = currentTable->cellAt(curr_browser->textCursor());
        currentTable->removeColumns(currentCell.column(),1);
    }
}

/*!
 * \fn MainWindow::on_actionRemove_Row_triggered()
 * \brief Delete selected row
*/
void MainWindow::on_actionRemove_Row_triggered()
{
    if(!curr_browser || curr_browser->isReadOnly())
        return;
    if(curr_browser->textCursor().currentTable())
    {
        QTextTable *currentTable = curr_browser->textCursor().currentTable();
        QTextTableCell currentCell = currentTable->cellAt(curr_browser->textCursor());
        currentTable->removeRows(currentCell.row(),1);
    }
}

/*!
 * \fn MainWindow::on_actionToSlp1_2_triggered()
 * \brief Converts devanagri text to transliterated/ romanized text.
 * This function opens a file open dialogue asking you to open a devnagri text file.
 * The output is a new file containing translitrated text
 * The output is saved as input_file_nameDev.txt
void MainWindow::on_actionToSlp1_2_triggered()
{
    QString file1 = QFileDialog::getOpenFileName(this, "Open a File");

    if (!file1.isEmpty())
    {
        QFile sFile(file1);
        if (sFile.open(QFile::ReadOnly | QFile::Text)) {
            string localFilenameN = file1.toUtf8().constData();
            std::ifstream ip(localFilenameN);
            std::ofstream op(localFilenameN + "slp1");
            string line;
            while (getline(ip, line)) op << toslp1(line) << endl;
        }
    }
}
*/

/*!
 * \fn MainWindow::on_actionToDev_triggered()
 * \brief Converts transliterated file to devanagri file
 * Transliterated here means Hindi/ Sanskrit written in English.
 * This function opens a file open dialogue asking you to open a transliterated text file.
 * The output is saved as input_file_nameDev.txt
void MainWindow::on_actionToDev_triggered()
{
    QString file1 = QFileDialog::getOpenFileName(this, "Open a File");

    if (!file1.isEmpty())
    {
        QFile sFile(file1);
        if (sFile.open(QFile::ReadOnly | QFile::Text)) {
            string localFilenameN = file1.toUtf8().constData();
            std::ifstream ip(localFilenameN);
            std::ofstream op(localFilenameN + "Dev");
            string line;
            while (getline(ip, line)) op << toDev(line) << endl;
        }
    }
}
*/

/*!
 * \fn MainWindow::on_actionExtractDev_triggered()
 * \brief Extracts words from a devnagri text file to lines.
 * This function opens a file open dialogue asking you to open a devnagri text file.
 * The output is all words in the file seperated by newline
 * The output is saved as input_file_nameDev.txt
 * \sa slpNPatternDict::toDev()
void MainWindow::on_actionExtractDev_triggered()
{
    QString file1 = QFileDialog::getOpenFileName(this, "Open a File");

    if (!file1.isEmpty())
    {
        QFile sFile(file1);
        if (sFile.open(QFile::ReadOnly | QFile::Text)) {
            string localFilenameN = file1.toUtf8().constData();
            std::ifstream ip(localFilenameN);
            std::ofstream op(localFilenameN + "Dev");
            string line;
            while (ip >> line) { if (hasNoAsci(line)) op << (line) << endl; }
        }
    }
}
*/

/*!
 * \fn MainWindow::on_actionEditDistRep_triggered
 * \brief Creates a new file that contains the edit distance values for each line present in the user opened file.
 * \note The new file is named as EditDistRep Which is appended to its original file name that user opened via OpenFileDialog window
 * \sa editDist()
void MainWindow::on_actionEditDistRep_triggered()
{
    QString file1 = QFileDialog::getOpenFileName(this, "Open a File");        //Prompts a Open File Dialog window

    if (!file1.isEmpty())
    {
        QFile sFile(file1);
        if (sFile.open(QFile::ReadOnly | QFile::Text))
        {
            string localFilenameN = file1.toUtf8().constData();
            std::ifstream ip1(localFilenameN); std::ifstream ip2(localFilenameN + "y");
            std::ofstream op(localFilenameN + "EditDisRep");       //append "EditDisRep" to the new file name
            string word1, word2;
            int max = 0;
            op << "a = [";
            while (getline(ip1, word1))
            {
                getline(ip2, word2);
                int ed = editDist(word1, word2);         //calculate the edit distance
                op << ed << " ";
                if (ed > max) max = ed;
            }
            op << "];" << endl;
            op << " hist(a,-0.5:0.5:max(a))" << endl << "pause()" << endl;
        }
    }
}
*/

/*!
 * \fn MainWindow::on_actionConfusionFreqHist_triggered()
 * \brief Creates two new files for the user opened file. One file contains thte X-axis values and the
 * other Octaves which are neccesary to form a histogram to show the frequency of items. The alternate lines are
 * stored in two files.
 * \note The two new files are named as HistOCtaveRep and HistXaxisRep and the names are appended to its original filename.
void MainWindow::on_actionConfusionFreqHist_triggered()
{
    QString file1 = QFileDialog::getOpenFileName(this, "Open a File");     //Prompts a Open File Dialog window
    if (!file1.isEmpty())
    {
        QFile sFile(file1);
        if (sFile.open(QFile::ReadOnly | QFile::Text))
        {
            string localFilenameN = file1.toUtf8().constData();
            std::ifstream ip(localFilenameN);
            std::ofstream op(localFilenameN + "HistOCtaveRep");
            std::ofstream opx(localFilenameN + "HistXaxisRep");
            string line;
            op << "a = [";
            while (getline(ip, line))
            {
                opx << line << "\t" << endl;
                line = "";
                getline(ip, line);
                op << line << " ";

            }
            op << "];" << endl;
            op << " hist(a,-0.5:0.5:max(a))" << endl << "pause()" << endl;
        }
    }
}
*/

/*!
 * \fn MainWindow::on_actionFilterOutGT50EditDisPairs_triggered
 * \brief Opens a pop up which asks the user to select a text file which filters out the words based upon the
 * edit distance, which finds the edit distance between the 2 words that have come in and if the edit distance
 * comes out to be more than 50 then the words are not printed, else they are printed in the file which is created
 * with the same name as of project file with "EditDisLE50FilteredRep" at the end.
 * \sa editdistance::editDist()
void MainWindow::on_actionFilterOutGT50EditDisPairs_triggered()
{
    QString file1 = QFileDialog::getOpenFileName(this, "Open a File");

    if (!file1.isEmpty())
    {
        QFile sFile(file1);
        if (sFile.open(QFile::ReadOnly | QFile::Text)) {
            string localFilenameN = file1.toUtf8().constData();
            std::ifstream ip(localFilenameN);
            std::ofstream op(localFilenameN + "EditDisLE50FilteredRep");
            string line;
            while (getline(ip, line)) {
                stringstream l(line);
                string word1, word2;
                getline(l, word1, '\t');
                getline(l, word2, '\t');
                //data >> word1 >> word2;
                int ed = editDist(word1, word2);
                if (ed <= 50)  op << word1 << "\t" << word2 << endl;
            }
        }
    }
}
*/

/*!
 * \brief MainWindow::on_actionPrepareFeatures_triggered()
 * deprecated; crashing
void MainWindow::on_actionPrepareFeatures_triggered()
{
    QString file1 = QFileDialog::getOpenFileName(this, "Open a File");

    if (!file1.isEmpty())
    {
        QFile sFile(file1);
        if (sFile.open(QFile::ReadOnly | QFile::Text)) {
            string localFilenameN = file1.toUtf8().constData();
            QString strI1 = file1;
            strI1.replace("Dict", "CPair");
            string strI1s = strI1.toUtf8().constData();
            map<string, int> Dictionary;
            map<string, int> DictionaryNGrams;
            loadMap(localFilenameN, Dictionary, "Dictionary");
            size_t count6 = 0;
            loadDictPatternstoMap(DictionaryNGrams, Dictionary, count6);
            size_t MaxElSize = 0; string line1;
            ifstream infile1(strI1s);
            while (getline(infile1, line1)) {
                vector<std::string> x = split(line1, "\t");
                string a2 = toslp1(x[0]);
                if (a2.size() > MaxElSize) MaxElSize = a2.size();
            }
            infile1.close();
            cout << "MaxElSize " << MaxElSize << endl;
            ifstream infile(strI1s);
            ofstream outfile;
            outfile.open(strI1s + "out");
            string line, a, b;
            size_t M = (MaxElSize*(MaxElSize - 1)) / 2;
            while (getline(infile, line)) {
                vector<std::string> x = split(line, "\t");
                a = toslp1(x[0]); b = toslp1(x[1]);
                if (a == b) outfile << "1 ";
                else outfile << "-1 ";
                if (Dictionary[a] > 0) outfile << "1:" << Dictionary[a] << " ";
                else outfile << "1:0 ";
                string a1 = a;
                size_t ia1 = 0;
                while (ia1 < MaxElSize - a.size()) {
                    a1 = a1 + "^";
                    ia1 = ia1 + 1;
                }
                vector<bool> vecBin; vector<size_t> vecBinFreq; size_t count = 0;
                getNgramFeaturesinVect(a1, DictionaryNGrams, vecBin, vecBinFreq, count);
                size_t vBsz = vecBin.size();
                for (size_t i = 0; i < vBsz; i++) {
                    if (vecBin[i]) outfile << i + 2 << ":" << 1 << " ";
                    else outfile << i + 2 << ":" << -1 << " ";
                }
                float count6f = count6;
                for (size_t i = 0; i < vecBinFreq.size(); i++) {
                    float vbnf = vecBinFreq[i];
                    outfile << i + 2 + vBsz << ":" << vbnf / count6f << " ";
                }
                outfile << endl;
            }
            outfile.close();
            infile.close();
        }
    }
}
*/

/*!
 * \brief MainWindow::on_actionFetch_2_triggered()
 * Not using this function
 */
void MainWindow::on_actionFetch_2_triggered()
{
    QString stage = mProject.get_stage();
    QString prvs_stage = (stage=="Verifier")?"Verifier":"Corrector";
    QString prvs_output_dir = prvs_stage + "Output"; //"VerifierOutput" or "CorrectorOutput"

    int btn = QMessageBox::question(this, "Pull ?", "This will overwrite files in " + prvs_output_dir + " directory. Do you want to Continue?",
                                    QMessageBox::StandardButton::Yes, QMessageBox::StandardButton::No);
    if (btn == QMessageBox::StandardButton::Yes)
    {
        mProject.fetch();
        if(mProject.get_version().toInt())
        {
            QMessageBox::information(0, "Pull Success", "Pull Succesful");
        }
        else
        {
            QMessageBox::information(0, "Pull Error", "Pull Un-succesful, Please Check Your Internet Connection");
        }
//        if(!isVerifier)
//        {
//            if (mProject.get_stage() == "Corrector")
//            {
//                ui->actionTurn_In->setEnabled(true);
//            }
//            else
//            {
//                ui->actionTurn_In->setEnabled(false);
//            }
//        }
        ui->lineEdit_2->setText("Version " + mProject.get_version());
    }
    else
        return;
}

/*!
 * \fn MainWindow::on_actionTurn_In_triggered()
 * \brief To turn-in the corrector's file to git repository when user clicks "submit corrector" button.
 *
 * \note This function turn-in files only for corrector and not for verifier.
 * \sa checkUnsavedWork(), saveAllWork(), get_version(), commit(), push(), set_stage_verifier() and enable_push()
 */
void MainWindow::on_actionTurn_In_triggered()
{
    //! Checking if the files are saved or not.
    if (checkUnsavedWork())
    {
        QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Unsaved Work",
                                                                    tr("You have unsaved files. Save it before turn-in.\n"),
                                                                    QMessageBox::Cancel | QMessageBox::Save,
                                                                    QMessageBox::Save);
        if (resBtn == QMessageBox::Cancel)
        {
            QMessageBox::information(0, "Turn In", "Turn In Cancelled");
            return;
        }
        else
        {
            saveAllWork();      //saves all the file
        }
    }

    //!Checking whether all the file are there in CorrectorOutput directory.
    if(mProject.get_version().toInt())
    {
//         if(mProject.findNumberOfFilesInDirectory(mProject.GetDir().absolutePath().toStdString() + R"(/CorrectorOutput/)")
//                 != 2* mProject.findNumberOfFilesInDirectory(mProject.GetDir().absolutePath().toStdString() + R"(/Inds/)"))
//         {
//             QMessageBox::information(0, "Couldn't Turn In", "Make sure all files are there in CorrectorOutput directory");
//             return;
//         }
        QString commit_msg = "Corrector Turned in Version: " + mProject.get_version();     // append current version

        int btn = QMessageBox::question(this, "Submit ?", "Are you ready to submit your changes?",
                                        QMessageBox::StandardButton::Yes, QMessageBox::StandardButton::No);
        if (btn == QMessageBox::StandardButton::Yes)
        {
            bool ok;
            branchName = QInputDialog::getText(this, tr("Branch Name"),
                                               tr("Enter the branch name:"), QLineEdit::Normal,
                                               "", &ok );
            if ( ok && !branchName.isEmpty() ) {
                // user entered something and pressed OK

                // mProject.set_stage_verifier();    // set_stage_verifier()inherited from project.cpp updates the stage in xml file to "verifier"

                //! commits and pushes the file. commit() and push() from Project.cpp creates a commit and pushes the file to git repo
                if(!mProject.commit(commit_msg.toStdString()) || !mProject.push(branchName))
                {
                    mProject.enable_push(false);      // enable_push() increments version and sets stage in xml file
                    QMessageBox::information(0, "Turn In", "Turn In Cancelled");
                    return;
                }
            } else {
                // user entered nothing or pressed Cancel
                QMessageBox::information(0, "Turn In", "Turn In Cancelled");
                return;
            }

        }
        else
        {
            QMessageBox::information(0, "Turn In", "Turn In Cancelled");
            return;
        }

        ui->lineEdit_2->setText("Version " + mProject.get_version());      //Update the version of file on ui.

        QString emailText =  "Book ID: " + mProject.get_bookId()
                + "\nSet ID: " + mProject.get_setId()
                + "\n" + commit_msg ;       //Send an email if turn-in failed

       // ui->actionTurn_In->setEnabled(false);        // Deactivating the "Submit Corrector" button on ui
        QMessageBox::information(0, "Turn In", "Turned In Successfully");
        deleteEditedFilesLog();
    }
    else
    {
        QMessageBox::information(0, "Turn In Error", "Please Open Project Before Turning In");
    }
}

/*!
 * \fn MainWindow::on_actionVerifier_Turn_In_triggered
 * \brief To turn-in the verifier's file to git repository when user clicks ""Submit Verifier" button.
 *
 * \note This function turn-in files for verifiers not correctors.
 * \sa checkUnsavedWork(), saveAllWork(), get_version(), get_stage(), readJsonFile(), writeJsonFile(),set_stage_verifier() and enable_push.
 */
void MainWindow::on_actionVerifier_Turn_In_triggered()
{
    /*!
     * \fn checkUnsavedWork
     * If there's unsaved work, a message box will appear on the screen
     * asking to save the usaved work or not.
     * \return boolean value, true if there is unsaved work and false if not.
    */
    if (checkUnsavedWork())
    {

        QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Unsaved Work",
                                                                    tr("You have unsaved files. Save it before turn-in.\n"),
                                                                    QMessageBox::Cancel | QMessageBox::Save,
                                                                    QMessageBox::Save);
        if (resBtn == QMessageBox::Cancel)
        {
            QMessageBox::information(0, "Turn In", "Turn In Cancelled");
            return;
        }
        else
        {
            saveAllWork();
        }
    }

    /*
     * \description
     * 1. Checks if any project is opened or not.
     * 2. Reads the comments.json file in Comments folder in the opened project.
     * 3. Calculates AverageCharAccuracy.
     * 4. mRoleCheck
     * 5. Sets the rating and formatting.
    */
    if(mProject.get_version().toInt())
    {

        int ver = mProject.get_version().toInt();
        QString commit_msg;

        QString commentFilename = gDirTwoLevelUp + "/Comments/comments.json";
        float avgcharacc = 0;
        bool formatting = false;
        int rating = 0;

        QJsonObject mainObj = readJsonFile(commentFilename);

        avgcharacc = mainObj["AverageCharAccuracy"].toDouble();

        //! Calcuates the rating for the current set.
        if(mProject.get_stage() != mRole)
            rating = mainObj["Rating-V"+ QString::number(mProject.get_version().toInt() - 1)].toInt();
        else
            rating = mainObj["Rating-V"+ mProject.get_version()].toInt();
        if(((!mainObj["Formatting"].isNull())) || (! mainObj["Formatting"].isUndefined()))
            formatting = mainObj["Formatting"].toBool();

        /*
         * \description
         * 1. Check formatting dialog box will be opened
         * 2. Dialog box will show the current rating out of 4 and a checkbox.
        */
        QDialog dialog(this);
        dialog.setWindowTitle("Check Formatting");

        QFormLayout form(&dialog);
        form.addRow(new QLabel("Average Rating of Current Set  : " + QString::number(rating) + " out of 4"));

        QCheckBox *cb = new QCheckBox("Perfect Formatting?" ,&dialog);
        cb->setChecked(formatting);
        form.addRow(cb);

        QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                                   Qt::Horizontal, &dialog);
        form.addRow(&buttonBox);

        //! Checking which signal has been passed i.e. accept or reject.
        QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));     //when ok is pressed.
        QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));     //when cancel is pressed.

        if (dialog.exec() == QDialog::Accepted)
        {
            formatting = cb->isChecked();

            //! If the checkbox is checked, increment rating by 1 else decrement the rating value by 1.
            if(rating == 4 && formatting)
                rating = 5;
            else if(rating == 5 && (!formatting))
                rating = 4;
        }
        else
        {
            QMessageBox::information(0, "Turn In", "Turn In Cancelled");
            return;
        }

        //! Updating the formatting and rating parameters value in the comments.json file, if any
        mainObj["Formatting"] = formatting;

        //! Calcuates the rating for the current set.
        if(mProject.get_stage() != mRole)
            mainObj["Rating-V"+ QString::number(mProject.get_version().toInt() - 1)] = rating;
        else
            mainObj["Rating-V"+ mProject.get_version()] = rating;

        writeJsonFile(commentFilename, mainObj);

        QMessageBox messageBox(this);
        QString msg1 = QString(
                    "Rating for Current Version Based on the Formatting Input: " + QString::number(rating) + " out of 5"

                    + "\n\nDo you want to Return the Set to the Corrector or Finalise the set?"

                    + "\n\nClick \"Return Set\" to Increment the Version from "
                    + QString::number(ver) +" to "+QString::number(ver + 1)

                    + "\nClick \"Finalise\" to Approve the set as the Final Version"
                    );

        QString msg2 = QString(
                    "Rating for Current Version Based on the Formatting Input: " + QString::number(rating) + " out of 5"

                    + "\n\nDo you want to Return or Resubmit or Finalise the set?"

                    + "\n\nClick \"Return Set\" to Turnin and Increment the Version from "
                    + QString::number(ver) +" to "+QString::number(ver + 1)

                    + " \nClick \"Resubmit\" to Turn In without Incrementing Version."

                    + "\nClick \"Finalise\" to Approve the set as the Final Version"
                    );

        messageBox.setWindowTitle("Turn In");
        QAbstractButton *resubmitButton =
                messageBox.addButton(tr("Resubmit"), QMessageBox::ActionRole);
        QAbstractButton *returnSetButton =
                messageBox.addButton(tr("Return Set"), QMessageBox::ActionRole);
        QAbstractButton *finaliseButton =
                messageBox.addButton(tr("Finalise"), QMessageBox::ActionRole);
        QAbstractButton *cancelButton =
                messageBox.addButton(tr("Cancel"), QMessageBox::RejectRole);

        /*
             * \description
             * 1.Checks if the project content is added to the staging area or not
             * 2. If no, display \a msg1 and remove the resubmit button.
             * 3. If yes, display \a msg2.
        */
        if(mRole != mProject.get_stage())
        {
            messageBox.setText(msg1);
            messageBox.removeButton(resubmitButton);
        }
        else
        {
            messageBox.setText(msg2);
        }

        messageBox.exec();

        /*!
         * \enum class SubmissionType
         *
         * This enum describes the type of submission type.
         *
         * \value resubmit To turn in without incrementing version.
         * \value return_set To turn-in and increment the version.
         * \value finalise To approve the set as the final version.
        */
        enum class SubmissionType {resubmit, return_set, finalise};
        SubmissionType s ;

        /*
            * Checking the condition: CorrectorOutputFiles != 2*IndsFiles
            * If true, then \a s and \a commit_msg are updated.
        */
        if (messageBox.clickedButton() == resubmitButton)
        {
            //mProject.enable_push( false ); //Increment = false
//             if(mProject.findNumberOfFilesInDirectory(mProject.GetDir().absolutePath().toStdString() + R"(/VerifierOutput/)")
//                     != 2* mProject.findNumberOfFilesInDirectory(mProject.GetDir().absolutePath().toStdString() + R"(/Inds/)"))
//             {
//                 QMessageBox::information(0, "Couldn't Turn In", "Make sure all files are there in VerifierOutput directory");
//                 return;
//             }
            s = SubmissionType::resubmit;
            commit_msg = "Verifier Resubmitted Version:" + mProject.get_version();
        }

        //! \a s and \a commit_msg are updated
        else if (messageBox.clickedButton() == returnSetButton)
        {
            //mProject.enable_push( true ); //Increment = true
            s = SubmissionType::return_set;
            commit_msg = "Verifier has Turned in the Next Version:" + mProject.get_version();
        }

        /*
         * Checking the condition: CorrectorOutputFiles != 2*IndsFiles
         * If true, a message box of \value Couldn't Turn in will be displayed,
         * else \a s and \a commit_msg are updated.
        */
        else if (messageBox.clickedButton() == finaliseButton)
        {
            //mProject.enable_push( false ); //Increment = false
//             if(mProject.findNumberOfFilesInDirectory(mProject.GetDir().absolutePath().toStdString() + R"(/VerifierOutput/)")
//                     != 2* mProject.findNumberOfFilesInDirectory(mProject.GetDir().absolutePath().toStdString() + R"(/Inds/)"))
//             {
//                 QMessageBox::information(0, "Couldn't Turn In", "Make sure all files are there in VerifierOutput directory");
//                 return;
//             }
            s = SubmissionType::finalise;
            commit_msg = "Verifier Finalised Version:" + mProject.get_version();
        }
        else
        {
            QMessageBox::information(0, "Turn In", "Turn In Cancelled");
            return;
        }

        int btn = QMessageBox::question(this, "Submit ?", "Are you ready to submit your changes?",
                                        QMessageBox::StandardButton::Yes, QMessageBox::StandardButton::No);
       if (btn == QMessageBox::StandardButton::Yes)
       {
            bool ok;
            branchName = QInputDialog::getText(this, tr("Branch Name"),
                                                 tr("Enter the branch name:"), QLineEdit::Normal,
                                                 "", &ok );
            if ( ok && !branchName.isEmpty() ) {
                // user entered something and pressed OK
                if(s == SubmissionType::return_set)   //If yes button is clicked and submission type is return_set then enable push
                {
                    mProject.enable_push( true );
                }
                else if (s == SubmissionType::resubmit)    //If yes button is clicked and submission type is resubmit then enable push
                {
                    mProject.enable_push( false );
                }
                if(!mProject.commit(commit_msg.toStdString()) || !mProject.push(branchName))
                {
                    if(s == SubmissionType::return_set)
                    {
                        mProject.set_version( mProject.get_version().toInt() - 1 );
                    }
                   // mProject.set_stage_verifier();
                    QMessageBox::information(0, "Turn In", "Turn In Cancelled");
                    return;
                }
            }
            else {
                // user entered nothing or pressed Cancel
                QMessageBox::information(0, "Turn In", "Turn In Cancelled");
                return;
            }
        }
        else
        {
            QMessageBox::information(0, "Turn In", "Turn In Cancelled");
            return;
        }

        //! Sending email with the following information
        QString emailText =  "Book ID: " + mProject.get_bookId()
                + "\nSet ID: " + mProject.get_setId()
                + "\nRating Provided: " + QString::number(rating)
                + "\n" + commit_msg ;

        //! Updating the Project Version
        ui->lineEdit_2->setText("Version " + mProject.get_version());
        QMessageBox::information(0, "Turn In", "Turned In Successfully");
        deleteEditedFilesLog();
    }
    else
    {
        QMessageBox::information(0, "Turn In Error", "Please Open Project Before Turning In");
    }
}

/*!
 * \brief MainWindow::on_actionSymbols_triggered
 * It shows the table for various symbols
 * \sa Symbols.cpp
 */
void MainWindow::on_actionSymbols_triggered()
{
    SymbolsView *dialog = SymbolsView::openSymbolTable(this);
    dialog->show();
}

/*!
 * \brief MainWindow::on_actionZoom_In_triggered
 * for zoom-in operation
 */
void MainWindow::on_actionZoom_In_triggered()
{
    if (z)
        z->gentle_zoom(1.1);
}

/*!
 * \brief MainWindow::on_actionZoom_Out_triggered
 * for zoom-out operation
 */
void MainWindow::on_actionZoom_Out_triggered()
{
    if (z)
        z->gentle_zoom(0.9);
}

/*!
 * \fn MainWindow::on_pushButton_clicked
 * \brief When button is clicked, then we can add placeholders for figure/table/equation.
 * \sa eventFilter
 */
void MainWindow::on_pushButton_clicked()
{
    if(loadimage)                   //Check image is loaded or not.
    {
        ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
        shouldIDraw=true;
        auto p = (QPushButton*)ui->pushButton;       //get the pushButton
        p->setStyleSheet("QPushButton { background-color: grey; }\n"
                          "QPushButton:enabled { background-color: rgb(200,205,180); }\n");      //apply style on button when it is triggered
     }
}

/*!
 * \fn MainWindow::eventFilter
 * \brief event: ToolTip and ImageMarkingRegion
      1. Responsible for drawing rectangular region
      2. Placing a PlaceHolder for figure/table/equation entries
      3. Set a MessageBox for figure/table/equation/cancel
      4. Set counter for pagewise for each entry
      5. Mark multiple image regions in a loaded image.
      6. Set various flag: a)drawRectangleFlag: is to prevent triggering of this function twice
      b) loadimage: check image is loaded on not; c) pressedFlag: resposible for dynamic rectangular
      drawing.
 * \param object, event
 * \return QMainWindow::eventFilter(object, event);
 * \sa MainWindow::displayHolder, MainWindow::updateEntries, MainWindow::createImageInfoXMLFile
 */
bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    //! Tooltip documentation
    if (event->type() == QEvent::ToolTip)
    {
          event->accept();

         if(QToolTip::isVisible())
         {

             QString qs =  QToolTip :: text();

             int x0, y0, x1, y1;

             QStringList list;
             list=qs.split(" ");
             int len = list.count();
             if (len>=5)
             {

                 x0 = list[1].toInt();
                 y0 = list[2].toInt();
                 x1 = list[3].toInt();
                 y1 = list[4].replace(";", "").toInt();
                 if(x1!=0 && x0!=0 && y1!=0 && y0!=0)
                 {
                     QColor blue40 = Qt::blue;
                     blue40.setAlphaF( 0.4 );

                     item1->setBrush(blue40);

                     item1->setRect(x0, y0, x1-x0, y1-y0);
                  }
             }
          }
      }

    //! ImageMarkingRegion feature
    if(loadimage)                   //Check image is loaded or not.
    {
     static int x1, y1;             //top & left coordinate values
     int x2, y2;                    //bottom & right coordinate values
     int x_temp , y_temp;           // dynamic coordinate values

     //! Apply event on graphicsview (image loaded part)
     if( object->parent() == ui->graphicsView)
     {
            installEventFilter(this);
            //! Capturing mouse press event on graphicsview
            if (event->type() == QEvent::MouseButtonPress && shouldIDraw)
            {
                QMouseEvent *mEvent = static_cast<QMouseEvent*>(event);
                QPointF pos =  ui->graphicsView->mapToScene( mEvent->pos()); //Capturing the coordinates values according to the image.
                QRgb rgb = imageOrig.pixel( ( int )pos.x(), ( int )pos.y());

                x1 = ( int )pos.x();      //left coordinate value
                y1 = ( int )pos.y();      //top coordinate value
                pressedFlag=1;            //drawing is on until it becomes 0 or for continuous pressing event
                event->accept();
            }
            //! Capturing mouse release event on graphicsview
            if (event->type() == QEvent::MouseButtonRelease)
            {       
                //! reponsible for preventing the event second time.
                if(drawRectangleFlag==true)
                {
                    drawRectangleFlag=false;
                    pressedFlag =0;        //for stopping the drawing
                    event->accept();
                    return true;
                }
                if(shouldIDraw){

                drawRectangleFlag=true;     //set the flag true when occuring for first time
                static int i,j,k;           //for storing the counter values for figure/equation/table for each page
                static QString a;           //pagecounter

                //! Getting PageNo string from gCurrentPageName
                QStringList PageNo=gCurrentPageName.split(QRegExp("[-.]"));
                QString PageNumber = PageNo[1];

                //!Getting i,j,k values from image.xml file
                //! first reading the file
                QDomDocument document;
                QString filename12 = mProject.GetDir().absolutePath() + "/image.xml";
                QFile f(filename12);

                //! throws an error if file is not in readonly mode
                if (!f.open(QIODevice::ReadOnly ))
                {
                    std::cerr << "Error while loading file" << std::endl;
                    return 1;
                }
                document.setContent(&f);       // Set data into the QDomDocument before processing
                f.close();

                //!for this you can refer image.xml file
                QDomElement root=document.documentElement();       //Item: BookSet
                QDomElement Component=root.firstChild().toElement();      //Item: Page(No)

                //! Loop while there is a child
                while(!Component.isNull())
                {
                    //! Check if the child tag name is Page(No)
                    if (Component.tagName()=="page"+PageNo[1])
                    {
                        a = Component.attribute("count");        //get counter value for each page starts with 1.
                        QDomElement Child=Component.firstChild().toElement();      //Item: figure
                        while (!Child.isNull())
                        {
                            //! Read tagNames and values
                            if (Child.tagName()=="figure") i=Child.firstChild().toText().data().toInt();
                            if (Child.tagName()=="table") j=Child.firstChild().toText().data().toInt();
                            if (Child.tagName()=="equation") k=Child.firstChild().toText().data().toInt();

                            Child = Child.nextSibling().toElement();        // Next child
                        }
                    }
                    Component = Component.nextSibling().toElement();        // Next component
                 }

                QMouseEvent *mEvent = static_cast<QMouseEvent*>(event);
                QPointF pos =  ui->graphicsView->mapToScene( mEvent->pos() );
                QRgb rgb = imageOrig.pixel( ( int )pos.x(), ( int )pos.y() );

                x2 = ( int )pos.x();         //right coordinate value
                y2 = ( int )pos.y();         //bottom coordinate value
                pressedFlag =0;              // stop rectangular drawing


                QColor blue40 = Qt::blue;     //sets its color
                blue40.setAlphaF( 0.4 );      //for transparency

                crop_rect->setBrush(blue40);   //set brush

                //qDebug() << x1 << " " << y1 << " " << x2 - x1 << " " << y2 - y1;   //getting the coordinates

                crop_rect->setRect(x1, y1, x2 - x1, y2 - y1);       //set final coordinates for rectangular region
                QRect rect(x1, y1, x2 - x1, y2 - y1);              //set QRect
                QPixmap image=QPixmap::fromImage(imageOrig);       //set QPixmap image
                QPixmap cropped=image.copy(rect);                   //get cropped image according to coordinates

                //! Set a messagebox for choosing what do you want to add: Figure/Table/Equation/Cancel
                QMessageBox messageBox(this);
                messageBox.setWindowTitle("Do you want to add");
                QAbstractButton *figureButton = messageBox.addButton(tr("Figure"), QMessageBox::ActionRole);
                QAbstractButton *tableButton = messageBox.addButton(tr("Table"), QMessageBox::ActionRole);
                QAbstractButton *equationButton = messageBox.addButton(tr("Equation"), QMessageBox::ActionRole);
                QAbstractButton *cancelButton = messageBox.addButton(tr("Cancel"), QMessageBox::RejectRole);

                QString msg = "Select an option\n";
                messageBox.setText(msg);
                messageBox.exec();

                //! settings for a figureholder
                if (messageBox.clickedButton() == figureButton)
                {
                    QString s1 = "IMGHOLDER";
                    QString s2 = "Figure";

                    //graphic->removeItem(crop_rect);

                    //!Saving Image Regions to their respective folder(Figure/Table/Equation)
                    saveImageRegion(cropped,a,s1,i,x2-x1,y2-y1);

                    i++;       //increment values when a figure is inserted in the textBrowser

                    crop_rect->setRect(0,0,1,1);       //settings this for dynamic rectangular region

                    //! updating entries for figure entries in xml file
                    updateEntries(document, filename12, PageNo[1], s2, i);

                    shouldIDraw=false;
                    //ui->pushButton->setStyleSheet("");     //remove the style once the operation is done
                }
                //! settings for a tableholder
                else if (messageBox.clickedButton() == tableButton)
                {
                    QString s1 = "TBHOLDER";
                    QString s2 = "Table";

                    //graphic->removeItem(crop_rect);

                    //!Saving Image Regions to their respective folder(Figure/Table/Equation)
                    saveImageRegion(cropped,a,s1,j,x2-x1,y2-y1);

                    j++;         //increment values when a table is inserted in the textBrowser

                    crop_rect->setRect(0,0,1,1);         //settings this for dynamic rectangular region

                    //! updating entries for table entries in xml file
                    updateEntries(document, filename12, PageNo[1], s2, j);

                    shouldIDraw=false;
                   // ui->pushButton->setStyleSheet("");       //remove the style once the operation is done
                }
                //! settings for a equationholder
                else if(messageBox.clickedButton() == equationButton)
                {
                    QString s1 = "EQHOLDER";
                    QString s2 = "Equation";

//                    //! for placing a equation placeholder
//                    (s1,s2,a,x1,y1,x2,y2,k);

                    //graphic->removeItem(crop_rect);

                    //!Saving Image Regions to their respective folder(Figure/Table/Equation)
                    saveImageRegion(cropped,a,s1,k,x2-x1,y2-y1);

                    k++;       //increment values when a equation is inserted in the textBrowser

                    crop_rect->setRect(0,0,1,1);       //settings this for dynamic rectangular region

                    //! updating entries for equation entries in xml file
                    updateEntries(document, filename12, PageNo[1], s2, k);

                    shouldIDraw=false;
                   // ui->pushButton->setStyleSheet("");       //remove the style once the operation is done
                }
                //! setting for cancelbutton
                else
                {
                    QMessageBox::information(0, "Not saved", "Cancelled");
                    crop_rect->setRect(0,0,1,1);
                    shouldIDraw=false;
                    ui->pushButton->setStyleSheet("");       //remove the style once the operation is done
                }
                ui->graphicsView->setDragMode( QGraphicsView::DragMode::ScrollHandDrag );
                event->accept();
                //return true;
            }
            }
        }
        //! Capturing mousemove event & creating single dynamic rectangle & Updating the temporary coordinates until pressedFlag is true
        if (event->type() == QEvent::MouseMove)
        {
             QMouseEvent *mEvent = static_cast<QMouseEvent*>(event);
             if (pressedFlag == 1)
             {
                 statusBar()->showMessage(QString("Mouse move (%1,%2)").arg(mEvent->pos().x()).arg(mEvent->pos().y()));
                 QPointF position =  ui->graphicsView->mapToScene( mEvent->pos() );
                 QRgb rgb = imageOrig.pixel( ( int )position.x(), ( int )position.y() );

                 QColor blue40 = Qt::blue;
                 blue40.setAlphaF( 0.4 );
                 crop_rect->setBrush(blue40);
                 x_temp = ( int )position.x();
                 y_temp = ( int )position.y();

                 crop_rect->setRect(x1, y1, x_temp-x1, y_temp-y1);
         }
         event->accept();
      }
    }

    return QMainWindow::eventFilter(object, event);
}

/*!
 * \fn MainWindow::saveImageRegion
 * \brief Saving Image  cropped regions to their respective folder(Figure/Table/Equation)
 * \param cropped
 * \param a
 * \param s1
 * \param z
 * \param h
 * \param w
 */
void MainWindow::saveImageRegion(QPixmap cropped, QString a, QString s1,int z, int w, int h)
{
    //! If directory exists then create the folders
    if(!QDir(gDirTwoLevelUp+"/Cropped_Images").exists())
    {
        QDir(gDirTwoLevelUp).mkdir("Cropped_Images");
        QDir(gDirTwoLevelUp).mkdir("Cropped_Images/Figures");
        QDir(gDirTwoLevelUp).mkdir("Cropped_Images/Tables");
        QDir(gDirTwoLevelUp).mkdir("Cropped_Images/Equations");
    }

    //! Adding picture to the respective directory
    if(QDir(gDirTwoLevelUp+"/Cropped_Images").exists())
    {
        if(s1 == "IMGHOLDER")
        {
            QString path = "/Cropped_Images/Figures/Figure"+a+"-"+QString::number(z)+".jpg";

            cropped.save(gDirTwoLevelUp+path,"JPG",100);       //100 is storing the image in uncompressed high resolution

            QString src = ".."+path;
            QString html = QString("\n <img src='%1' width='%2' height='%3'>").arg(src).arg(w).arg(h); //Creating an img tag for image resize in latek
            QTextCursor cursor = curr_browser->textCursor();
            cursor.insertHtml(html);
        }
        else if(s1 == "TBHOLDER")
        {
            QString path = "/Cropped_Images/Tables/Table"+a+"-"+QString::number(z)+".jpg";

            cropped.save(gDirTwoLevelUp+path,"JPG", 100);

            QString src = ".."+path;

            QString html = QString("\n <img src='%1' width='%2' height='%3'>").arg(src).arg(w).arg(h);
            QTextCursor cursor = curr_browser->textCursor();
            cursor.insertHtml(html);

        }
        else if(s1 == "EQHOLDER")
        {
            QString path = "/Cropped_Images/Equations/Equation"+a+"-"+QString::number(z)+".jpg";

            cropped.save(gDirTwoLevelUp+path,"JPG",100);

            QString src = ".."+path;
            QString html = QString("\n <img src='%1' width='%2' height='%3'>").arg(src).arg(w).arg(h);
            QTextCursor cursor = curr_browser->textCursor();
            cursor.insertHtml(html);
        }
        else
        {
            //empty
        }
    }
}

//! Updating entries for figure/table/equation pagewise in image.xml
void MainWindow::updateEntries(QDomDocument document, QString filename,QString PageNo, QString s2, int i)
{
    QDomElement root = document.documentElement();
    QDomElement Component=root.firstChild().toElement();

    while(!Component.isNull())       // Loop while there is a child
    {
        //! Check if the child tag name is COMPONENT
        if (Component.tagName()=="page"+PageNo)
        {
            QDomElement Child=Component.firstChild().toElement();
            while (!Child.isNull())
            {
                if (s2 == "Figure" && Child.tagName()=="figure")
                {
                    Child.childNodes().at(0).setNodeValue(QString::number(i));
                }
                else if (s2 == "Table" && Child.tagName()=="table")
                {
                    Child.childNodes().at(0).setNodeValue(QString::number(i));
                }
                else if (s2 == "Equation" && Child.tagName()=="equation")
                {
                    Child.childNodes().at(0).setNodeValue(QString::number(i));
                }

                Child = Child.nextSibling().toElement();       // Next child
            }
        }
        Component = Component.nextSibling().toElement();        // Next component
     }
    QFile f(filename);
    f.open(QIODevice::WriteOnly);
    QTextStream stream;
    stream.setDevice(&f);
    stream.setCodec("UTF-8");
    document.save(stream,4);
    f.close();
}

//! Genearte image.xml for figure/table/equation entries and initialize these values by 1 iff when this file does not exist.
void MainWindow::createImageInfoXMLFile()
{
    QDomDocument document;

    // Add processing instructions that are XML instructions
    QDomProcessingInstruction instruction;
    instruction = document.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
    document.appendChild(instruction);

    // add root element
    QDomElement root = document.createElement("BookSet");
    document.appendChild(root);

    //add some elements
    QString strI = gDirTwoLevelUp + "/Inds";
    QDir directory(strI);
    QStringList list1 = directory.entryList(QStringList() << "*.txt",QDir::Files);
    int counter_i = 1;
    for ( const auto& i : list1 )
    {
        QStringList PageNo = i.split(QRegExp("[-.]"));
        QDomElement tagPage = document.createElement("page"+PageNo[1]);
        tagPage.setAttribute("count", counter_i);
        root.appendChild(tagPage);

        QDomElement tagImage = document.createElement("figure");
        tagPage.appendChild(tagImage);
        QDomText NoImage = document.createTextNode("1");
        tagImage.appendChild(NoImage);

        QDomElement tagTable = document.createElement("table");
        tagPage.appendChild(tagTable);
        QDomText NoTable = document.createTextNode("1");
        tagTable.appendChild(NoTable);

        QDomElement tagEquation = document.createElement("equation");
        tagPage.appendChild(tagEquation);
        QDomText NoEquation = document.createTextNode("1");
        tagEquation.appendChild(NoEquation);
        counter_i++;
    }

    QString filename12 = mProject.GetDir().absolutePath() + "/image.xml";
    if(!QFileInfo::exists(filename12))
    {
        QFile file(filename12);

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
            qDebug()<<"Failed to open xml file";
            return;
        }
        else{
            QTextStream out(&file);
            out << document.toString();
            file.close();
            qDebug()<<"Writing to xml file";
        }
    }
}

/*!
 * \brief MainWindow::on_pushButton_2_clicked
 * Button for resizing an image
 * Captures src, width and height attributes, modifies height and width and change the image size
 * it does not chnage the quality of an image
 */
void MainWindow::on_pushButton_2_clicked()
{
    auto cursor = curr_browser->textCursor();
    auto selected = cursor.selection();
    QString sel = selected.toHtml();

    QRegularExpression re("<img[^>]*?src\=[\x27\x22](?<Url>[^\x27\x22]*)[\x27\x22][^>]*?width\=[\x27\x22](?<width>[^\x27\x22]*)[\x27\x22][^>]*?height\=[\x27\x22](?<height>[^\x27\x22]*)[\x27\x22][^>]*?>");
    QRegularExpressionMatch match = re.match(sel, 0);
    int height = match.captured(3).toInt();
    int width = match.captured(2).toInt();
    QString imgname = match.captured(1);

    //!setting width
    int n = QInputDialog::getInt(this, "Set Width","Width",width,-2147483647,2147483647,1);
    //!setting height
    int n1 = QInputDialog::getInt(this, "Set Height","height",height,-2147483647,2147483647,1);

    if(n>0 && n1>0)
    {
        cursor.removeSelectedText();   //remove old image
        QString html = QString("\n <img src='%1' width='%2' height='%3'>").arg(imgname).arg(n).arg(n1);
        QTextCursor cursor1 = curr_browser->textCursor();
        cursor1.insertHtml(html);      //insert new image with modified attributes height and width
    }
}

/*!
 * \brief MainWindow::on_viewComments_clicked
 */
void MainWindow::on_viewComments_clicked()
{
    if (curr_browser)
    {
        QString correctorOutput,currentpagetext;
        QString correctorText = gDirTwoLevelUp + "/CorrectorOutput/" + gCurrentPageName;
        QFile sFile(correctorText);
        if(sFile.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream in(&sFile);
            in.setCodec("UTF-8");
            correctorOutput = in.readAll().simplified();
            sFile.close();
        }

        map<int, int> wordCount;
        QString commentFilename = gDirTwoLevelUp + "/Comments/comments.json";
        QString pageName = gCurrentPageName;
        pageName.replace(".txt", "");
        pageName.replace(".html", "");
        int totalCharErrors = 0, totalWordErrors = 0, rating = 0;
        QString comments = "";
        QString avgAcc = "100%";
        float wordAccuracy=100, charAccuracy=100, avgCharAcc = 100;
        QString version = mProject.get_version();

        QJsonObject mainObj = readJsonFile(commentFilename);
        QJsonObject pages = mainObj.value("pages").toObject();
        QJsonObject page = pages.value(pageName).toObject();

        if( !mainObj.isEmpty() )
        {
            rating = mainObj["Rating-V"+ mProject.get_version()].toInt();
            avgCharAcc = mainObj["AverageCharAccuracy"].toDouble();
            avgAcc = QString::number((((float)lround(avgCharAcc*100))/100)) + "%";

            if(!page.isEmpty())
            {
                comments = page.value("comments").toString();
                totalCharErrors = page.value("charerrors").toInt();
                totalWordErrors = page.value("worderrors").toInt();
                wordAccuracy = page.value("wordaccuracy").toDouble();
                charAccuracy = page.value("characcuracy").toDouble();
            }
        }

        if(!isVerifier)
        {
            CommentsView *cv = new CommentsView(totalWordErrors,totalCharErrors,wordAccuracy,charAccuracy,comments,commentFilename, pageName, rating, avgAcc, mRole,version);
            cv->show();
            return;
        }

        //HIGHLIGHTS FOR Accuracy Calculation
        auto textCursor = curr_browser->textCursor();
        QString textBrowserText = curr_browser->toPlainText();
        textCursor.setPosition(0);
        QString highlightedChars = "", selectedChar; // to store all the highlighted characters
        int prevHighlightPos = -2; // Used as an indicator to separate non contigous highlighted text with a space

        while(!textCursor.atEnd())
        {
            int anchor = textCursor.position();
            QTextCharFormat format = textCursor.charFormat();
            if(anchor!=0)
                selectedChar = QString(textBrowserText[anchor-1]);
            if(!selectedChar.contains(" "))
            {
                textCursor.select(QTextCursor::WordUnderCursor);
                QString wordundercursor = textCursor.selectedText();
                int key = textCursor.selectionStart();

                if(format.background() == Qt::yellow && anchor>=(key+1))
                {
                    //totalCharErrors++;
                    if((prevHighlightPos != -2) && (anchor != prevHighlightPos + 1))
                        highlightedChars += " ";
                    highlightedChars += selectedChar;
                    wordCount[key]++;
                    prevHighlightPos = anchor;
                }
            }
            textCursor.setPosition(anchor+1);
            //textCursor.movePosition(QTextCursor::NextCharacter , QTextCursor::MoveAnchor, 1);
        }
        totalCharErrors = mProject.GetGraphemesCount(highlightedChars);

        int totalChars=0;
        QString currentText = curr_browser->toPlainText();
        int totalWords = currentText.simplified().count(" ") + 1;
        QTextBoundaryFinder finder1 = QTextBoundaryFinder(QTextBoundaryFinder::BoundaryType::Grapheme, currentText);
        while (finder1.toNextBoundary() != -1)
        {
            totalChars++;
        }

        totalWordErrors = wordCount.size();
        charAccuracy = (float)(totalChars - totalCharErrors)/(float)totalChars*100;
        wordAccuracy = (float)(totalWords - totalWordErrors)/(float)totalWords*100 ;
        wordAccuracy = ((float)lround(wordAccuracy*100))/100;
        charAccuracy = ((float)lround(charAccuracy*100))/100;

        page["comments"] = comments;
        page["charerrors"] = totalCharErrors;
        page["worderrors"] = totalWordErrors;
        page["characcuracy"] = charAccuracy;
        page["wordaccuracy"] = wordAccuracy;
        page["pagename"] = pageName;

        pages.remove(pageName);
        pages.insert(pageName, page);
        mainObj.remove("pages");
        mainObj.insert("pages",pages);

        mainObj = getAverageAccuracies(mainObj);

        if(mProject.get_stage() != mRole)
            rating = mainObj["Rating-V"+ QString::number(mProject.get_version().toInt() - 1)].toInt();
        else
            rating = mainObj["Rating-V"+ mProject.get_version()].toInt();
        avgCharAcc = mainObj["AverageCharAccuracy"].toDouble();
        avgAcc = QString::number((((float)lround(avgCharAcc*100))/100)) + "%";

        writeJsonFile(commentFilename, mainObj);

        if(!gSaveTriggered)
        {
            CommentsView *cv = new CommentsView(totalWordErrors,totalCharErrors,wordAccuracy,charAccuracy,comments,commentFilename,pageName, rating, avgAcc, mRole, version);
            cv->show();
        }
    }
}

/*!
 * \fn MainWindow::on_compareCorrectorOutput_clicked
 * \brief Compares the changes made by the Corrector in OCR generated text file.
 * \sa InternDiffView(), LevenshteinWithGraphemes(), GetGraphemesCount()
 */
void MainWindow::on_compareCorrectorOutput_clicked()
{

    if(mProject.get_version().toInt())   //checks if a project is open or not
    {
    //QString qs1="", qs2="";
    QString page = gCurrentPageName;

    //!checks whether users have selected a page
    if(page.isEmpty())
      {
           QMessageBox::information(0, "Error", "Please open a page ");
           return;
      }

    QString fpath = gDirTwoLevelUp;
    QString file = gDirTwoLevelUp + "/CorrectorOutput/" + page;

    //! Opens corresponding OCR text file and image
    if(!file.isEmpty())
    {
        InternDiffView *dv = new InternDiffView(this, page, fpath);   //Fetch OCR Image in DiffView2 and Set
        dv->show();
      }
    }
    else{
         QMessageBox::information(0, "Error", "Please Open a Project");
    }
}

/*!
 * \fn MainWindow::on_compareVerifierOutput_clicked
 * \brief Compares Verifier's Output, Corrector's Output and OCR text.
 * This function also displays the percentage of changes made by the Corrector and Verifier, and the accuracy of the OCR text w.r.t. the verified text.
 * \sa DiffView()
 */
void MainWindow::on_compareVerifierOutput_clicked() //Verifier-Version
{

  if(mProject.get_version().toInt())
   {
    QString page =gCurrentPageName;

    //!Check whether the user has clicked a page
    if(page.isEmpty())
      {
           QMessageBox::information(0, "Error", "Please open a page ");
           return;
      }

    //! Open a Verifier's Output File
    QString fpath = gDirTwoLevelUp;
    QString file = gDirTwoLevelUp + "/VerifierOutput/" + page;

    //! Opens corresponding Corrector's Output and OCR text file
    if(!file.isEmpty())
    {
        DiffView *dv = new DiffView(this,page,fpath);
        dv->show();
    }
  }
  else{
       QMessageBox::information(0, "Error", "Please Open a Project");
  }
}

//Global CPair Start
/*!
 * \brief MainWindow::dumpStringToFile
 * \param file_path
 * \param string
 * dumps given QString to file at file_path
 */
void MainWindow::dumpStringToFile(QString file_path, QString string){
    QFile file(file_path);
    if(file.open(QIODevice::WriteOnly | QIODevice::Append)){
            QTextStream outputStream(&file);
            outputStream << string << endl;
    }
    file.close();
}

/*!
 * \brief MainWindow::isStringInFile
 * \param file_path
 * \param searchString
 * \return
 * checks if a QString is in file at file_path
 */
bool MainWindow::isStringInFile(QString file_path, QString searchString){

    QFile fileToSearchIn(file_path);
    bool textFound = false;

    if(fileToSearchIn.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&fileToSearchIn);
        QString line;
        // Check in everyline if string exists*/
        do{
            line = in.readLine();
            if(line.contains(searchString)){
                textFound = true;
                break;
            }
        }while(!line.isNull());
    }
    fileToSearchIn.close();

    return textFound;

}

/*!
 * \brief MainWindow::addCurrentlyOpenFileToEditedFilesLog
 * adds currently opened file in editor in .EditedFiles.txt to mark it as dirty
 */
void MainWindow::addCurrentlyOpenFileToEditedFilesLog(){
    QString editedFilesLogPath = gDirTwoLevelUp + "/Dicts/" + ".EditedFiles.txt";
    QString currentFilePath = gDirTwoLevelUp + "/" + gCurrentDirName+ "/" + gCurrentPageName;

    bool fileFound = isStringInFile(editedFilesLogPath, currentFilePath);

    if(fileFound)
        qDebug() << gCurrentPageName <<" already found in Edited Files Log. No need to update.";
    else
    {
        qDebug() << gCurrentPageName <<" not found in Edited Files Log."<<endl;
        qDebug()<< "Writing " <<currentFilePath << " to file." << endl;
        dumpStringToFile(editedFilesLogPath, currentFilePath);
    }
}

/*!
 * \brief MainWindow::deleteEditedFilesLog
 * for now I am calling this everytime window closes
 */
void MainWindow::deleteEditedFilesLog(){
    QString editedFilesLogPath = gDirTwoLevelUp + "/Dicts/" + ".EditedFiles.txt";
    QFile file(editedFilesLogPath);
    file.remove();
}

/*!
 * \brief MainWindow::writeGlobalCPairsToFiles
 * \param file_path
 * \param globalReplacementMap
 * writes CPairs by iterating over all files
 */
void MainWindow::writeGlobalCPairsToFiles(QString file_path, QMap <QString, QString> globalReplacementMap){
    QMap <QString, QString>::iterator grmIterator;
    QFile *f = new QFile(file_path);

    f->open(QIODevice::ReadOnly);

    QTextStream in(f);
    in.setCodec("UTF-8");
    QString s1 = in.readAll();
    f->close();
    f->open(QIODevice::WriteOnly);

    for (grmIterator = globalReplacementMap.begin(); grmIterator != globalReplacementMap.end(); ++grmIterator)
    {
        QString pattern = ("(\\b)")+grmIterator.key()+("(\\b)"); // \b is word boundary, for cpp compilers an extra \ is required before \b, refer to QT docs for details
        QRegExp re(pattern);
        QString replacementString = re.cap(1) + grmIterator.value() + re.cap(2); // \1 would be replace by the first paranthesis i.e. the \b  and \2 would be replaced by the second \b by QT Regex
        //   if(!mapOfReplacements.contains(grmIterator.key()))
        string str = replacementString.toStdString();
        QString::fromStdString(str).toUtf8();
        QString replacementString1 = QString::fromStdString(str);
        mapOfReplacements[grmIterator.key()] = grmIterator.value();
        s1.replace(re, replacementString1);
    }

    in << s1;
    f->close();
}

/*!
 * \brief MainWindow::globalReplaceQueryMessageBox
 * \param old_word
 * \param new_word
 * \return
 * spawns a MessageBox and returns true if Replace is chosen
 */
bool MainWindow::globalReplaceQueryMessageBox(QString old_word, QString new_word){

    QMessageBox messageBox(this);

    //QAbstractButton *escButton = messageBox.addButton(tr("Esc"), QMessageBox::ActionRole);
    QAbstractButton *replaceButton = messageBox.addButton(tr("Yes"), QMessageBox::ActionRole);
    QAbstractButton *cancelButton = messageBox.addButton(tr("No"), QMessageBox::RejectRole);

    QString msg = "Do you want to replace " + old_word + " with " + new_word + " in rest of the pages?\n"
                + "\n\nClick \"Yes\" to save the changes and replace the word in the unedited pages."
                + "\nClick \"No\" to save the changes and not replace the word in the unedited page.";

    messageBox.setWindowTitle("Global Replace");
    messageBox.setText(msg);
    messageBox.exec();

    if (messageBox.clickedButton() == replaceButton)
        return true;
    return false;

}

/*!
 * \brief MainWindow::getGlobalReplacementMapFromChecklistDialog
 * \param changedWords
 * \return
 * spawns a checklist and returns a Qmap of selected pairs
 */
QMap <QString, QString> MainWindow::getGlobalReplacementMapFromChecklistDialog(QVector <QString> changedWords){
    QMap <QString, QString> globalReplacementMap;
    GlobalReplaceDialog grDialog(changedWords, this);

    grDialog.setModal(true);
    grDialog.exec();

    if(grDialog.on_applyButton_clicked())
        globalReplacementMap = grDialog.getFilteredGlobalReplacementMap();
    return globalReplacementMap;

}

/*!
 * \brief MainWindow::runGlobalReplace
 * \param currentFileDirectory
 * \param changedWords
 * Replace words iteratively
 */
void MainWindow::runGlobalReplace(QString currentFileDirectory , QVector <QString> changedWords)
{
    QMap <QString, QString> globalReplacementMap;

    QString editedFilesLogPath = gDirTwoLevelUp + "/Dicts/" + ".EditedFiles.txt";

    int noOfChangedWords = changedWords.size();

    //! if only one change spawn checkbox
    if (noOfChangedWords == 1){

        QStringList changesList = changedWords[0].split(" ");
        bool updateGlobalCPairs = globalReplaceQueryMessageBox(changesList[1], changesList[3]);

        if (updateGlobalCPairs)
            globalReplacementMap[changesList[1]] = changesList[3];
    }
    //! if there is more than 1 change spawn a checklist and get the checked pairs only
    else if(noOfChangedWords > 1){

       globalReplacementMap = getGlobalReplacementMapFromChecklistDialog(changedWords);

    }

    if(!globalReplacementMap.isEmpty())
    {
//        mapOfReplacements = globalReplacementMap;
        QDirIterator dirIterator(currentFileDirectory, QDirIterator::Subdirectories);

        while (dirIterator.hasNext()){

            QString it_file_path = dirIterator.next();
            bool isFileInEditedFilesLog = isStringInFile(editedFilesLogPath, it_file_path);

            if(!isFileInEditedFilesLog){
                writeGlobalCPairsToFiles(it_file_path, globalReplacementMap);
            }
        }
    }

    addCurrentlyOpenFileToEditedFilesLog();
}
//Global CPair End

/*!
 * \brief MainWindow::DisplayJsonDict
 * Load and display *.dict files
 */
void MainWindow::DisplayJsonDict(QTextBrowser *b, QString input)
{
    QVector<QString> dictionary;
    QJsonDocument doc;
    QJsonObject obj;
    QByteArray data_json;
    QStringList list1;
    QSet<QString> dict_set;
    QSet<QString> dict_set1;

    //! Get dict file from current opened file
    QString dictFilename;
    if(mRole=="Verifier")
    {
        dictFilename = gDirTwoLevelUp + "/" + "VerifierOutput" + "/" + gCurrentPageName;
    }
    else if(mRole=="Corrector")
    {
        dictFilename = gDirTwoLevelUp + "/" + "CorrectorOutput" + "/" + gCurrentPageName;
    }
    dictFilename.replace(".txt", ".dict");
    dictFilename.replace(".html", ".dict");
    QFile dictQFile(dictFilename);

    ui->textEdit_dict->clear();
    ui->textEdit_dict->setFontPointSize(15);
    //! Open the dict file and display it in textedit view
    if(QFile::exists(dictFilename))
    {
            QFile dictQFile(dictFilename);
            if(dictQFile.open(QIODevice::ReadOnly | QIODevice::Text))
            {
               data_json = dictQFile.readAll();
               dictQFile.close();
               doc = doc.fromJson(data_json);
               obj = doc.object();
               QJsonValue jv = obj.value(obj.keys().at(0));
               QJsonObject item = jv.toObject();
               for(int i = 0; i < item.count(); i++)
               {
                  ui->textEdit_dict->append(item.keys().at(i)+":");
                  QJsonValue subobj = item.value(item.keys().at(i));
                  QJsonArray test = subobj.toArray();
                  for(int k = 0; k < test.count(); k++)
                  {
                     if(test[k].toString()!=NULL){
                         QString jsonDi;

                         for(int i=0;i<test[k].toString().length();i++){
                             QString newStr=test[k].toString();
                             list1 = newStr.split(",");
                         }

                     }

                     ui->textEdit_dict->moveCursor(QTextCursor::End);
                     ui->textEdit_dict->insertPlainText(" "+test[k].toString());

                     if(k<test.count()-1)
                     {
                        ui->textEdit_dict->insertPlainText(",");
                     }
                     ui->textEdit_dict->moveCursor(QTextCursor::End);
                   }
                  foreach(auto &x,list1){
                      dict_set.insert(x);
                  }

               }

               foreach(auto &x,dict_set){
                   std::string string1= x.toStdString();
                   std::string string2;
                   string2=string1.substr(0, string1.find("(", 0));
                   QString qstr = QString::fromStdString(string2);
                   dict_set1.insert(qstr);
               }
               foreach(auto &x,dict_set1){
                   //qDebug()<<x;
               }

          }
    }

//    QTextCharFormat fmt;
//    fmt.setBackground(Qt::green);
    QTextCursor cursor(b->document());
    int indexOfReplacedWord;
    int from=0;
    int count;
    int numReplaced=0;
    foreach(auto &x, dict_set1)
    {
        count = input.count(x, Qt::CaseInsensitive);

        numReplaced=0;
        from=0;
        int flag=0;

        while(numReplaced<count)
        {

            int endIndex;
            indexOfReplacedWord = input.indexOf(x,from , Qt::CaseInsensitive);
            endIndex = indexOfReplacedWord;
//            qDebug() << indexOfReplacedWord << " " <<endIndex;
//            while(input[endIndex]!=" ")
//                endIndex++;
            //qDebug() << indexOfReplacedWord << " " <<endIndex;
            int len = x.length();
            //qDebug()<<x<<x.length()<<endl;

            while(len > 0)
            {
                endIndex++;
                len--;
            }
            if(input[endIndex]!=" ")
                flag=1;
            if(flag==0)
            {
                cursor.setPosition(indexOfReplacedWord, QTextCursor::MoveAnchor);
                cursor.setPosition(endIndex, QTextCursor::KeepAnchor);
                //cursor.setCharFormat(fmt);
                QTextEdit::ExtraSelection h;
                h.format.setBackground(Qt::green);
            }
            from = endIndex;
            numReplaced+=1;
            flag=0;
        }
    }

}

/*!
 * \brief MainWindow::getAverageAccuracies
 * \param mainObj
 * \return
 */
QJsonObject MainWindow::getAverageAccuracies(QJsonObject mainObj)
{
    float totalcharacc=0, totalwordacc = 0; int totalcharerrors = 0, totalworderrors = 0, count = 0, rating = 0;

    //!Navigate to the Json object named "pages" and extract the parent object within them
    QJsonObject pages = mainObj.value("pages").toObject();
    QJsonObject page;

    //!for every parent object or pages in json file
    foreach(const QJsonValue &val, pages)
    {
        //!Extract the values from Json file
        QString page = val.toObject().value("pagename").toString();
        float charAccuracy    = val.toObject().value("characcuracy").toDouble();
        float wordAccuracy    = val.toObject().value("wordaccuracy").toDouble();
        int charerrors = val.toObject().value("charerrors").toInt();
        int worderrors = val.toObject().value("worderrors").toInt();

        //!Store the fetched values from Json locally for calculating average and error values
        totalcharacc    += charAccuracy;
        totalwordacc    += wordAccuracy;
        totalcharerrors += charerrors;
        totalworderrors += worderrors;

        count++;
    }
    if(count)
    {
        //!Rate the average character accuracy and update it to csv file as 4,3,2 and 1
        double avgcharacc = totalcharacc/count;
        if(avgcharacc>98.5) rating = 4;
        else if(avgcharacc > 97.5) rating = 3;
        else if(avgcharacc > 96.5) rating = 2;
        else if(avgcharacc <= 96.5) rating = 1;

        if(mProject.get_stage() != mRole)
            mainObj["Rating-V"+ QString::number(mProject.get_version().toInt() - 1)] = rating;    //Decreases version and updates rating if stage in xml file and currect user is same
        else
            mainObj["Rating-V"+ mProject.get_version()] = rating;     //Update the rating in csv if stage in project.xml is different from current user Eg: "Rating-V1": 1

        //!Calculate and update the value of average accuracy and error to Json on Character and Word level
        mainObj["AverageCharAccuracy"] = avgcharacc;
        mainObj["AverageWordAccuracy"] = totalwordacc/count;
        mainObj["AverageCharErrors"] = totalcharerrors/count;
        mainObj["AverageWordErrors"] = totalworderrors/count;

    }
    return mainObj;
}

/*!
 * \fn MainWindow::updateAverageAccuracies
 * \brief The function updates accuracy and error on word and charater level to
 * the files named comments.json and AverageAccuracies.csv
 *
 * \sa readJsonFile(), writeJsonFile()
 */
void MainWindow::updateAverageAccuracies() //Verifier only
{
    //! Get the file path of comments.json and AverageAccuracies.csv
    QString commentFilename = gDirTwoLevelUp + "/Comments/comments.json";

    string csvfolder = gDirTwoLevelUp.toUtf8().constData();
    csvfolder += "/Comments/AverageAccuracies.csv";

    //!Write the column name to AverageAccuracies.csv
    std::ofstream csvFile(csvfolder);
    csvFile<<"Page Name,"<< "Word-Level Accuracy,"<<"Character-Level Accuracy," <<"Word-Level Errors,"<<"Character-Level Errors"<<"\n";

    //!Read the Json Objects and terminates functions if the file is empty
    QJsonObject mainObj = readJsonFile(commentFilename);
    if(mainObj.isEmpty())
        return;
    float totalcharacc=0, totalwordacc = 0; int totalcharerrors = 0, totalworderrors = 0, count = 0, rating = 0;

    //!Navigate to the Json object named "pages" and extract the parent object within them
    QJsonObject pages = mainObj.value("pages").toObject();
    QJsonObject page;

    //!for every parent object or pages in json file
    foreach(const QJsonValue &val, pages)
    {
        //!Extract the values from Json file
        QString page = val.toObject().value("pagename").toString();
        float charAccuracy = val.toObject().value("characcuracy").toDouble();
        float wordAccuracy = val.toObject().value("wordaccuracy").toDouble();
        int charerrors = val.toObject().value("charerrors").toInt();
        int worderrors = val.toObject().value("worderrors").toInt();

        //!Write those fetched values from Json to csv
        csvFile << page.toUtf8().constData() <<"," << wordAccuracy << "," << charAccuracy << "," << worderrors<< "," << charerrors<<"\n";

        //!Store the fetched values from Json locally for calculating average and error values
        totalcharacc    += charAccuracy;
        totalwordacc    += wordAccuracy;
        totalcharerrors += charerrors;
        totalworderrors += worderrors;

        count++;
    }
    if(count)
    {
        //!Rate the average character accuracy and update it to csv file as 4,3,2 and 1
        double avgcharacc = totalcharacc/count;
        if(avgcharacc>98.5) rating = 4;
        else if(avgcharacc > 97.5) rating = 3;
        else if(avgcharacc > 96.5) rating = 2;
        else if(avgcharacc <= 96.5) rating = 1;

        if(mProject.get_stage() != mRole)
            mainObj["Rating-V"+ QString::number(mProject.get_version().toInt() - 1)] = rating;   //Decreases version and updates rating if stage in xml file and currect user is same
        else
            mainObj["Rating-V"+ mProject.get_version()] = rating;    //Update the rating in csv if stage in project.xml is different from current user Eg: "Rating-V1": 1

        //!Calculate and update the value of average accuracy and error to Json on Character and Word level
        mainObj["AverageCharAccuracy"] = avgcharacc;
        mainObj["AverageWordAccuracy"] = totalwordacc/count;
        mainObj["AverageCharErrors"] = totalcharerrors/count;
        mainObj["AverageWordErrors"] = totalworderrors/count;

        //!Calculate and update the value of accuracy and error to csv on Character and Word level
        csvFile<<" ,"<< "Average Accuracy (Word level),"<<"Average Accuracy (Character-Level)," <<"Average Errors (Word level),"<<"Average Errors (Character-Level),"<<"\n";
        csvFile <<" " <<"," << totalwordacc/count << "," << totalcharacc/count << "," << totalworderrors/count<< "," << totalcharerrors/count<<"\n";
        writeJsonFile(commentFilename, mainObj);

    }
}

//end

/*!
 * \brief MainWindow::on_sanButton_toggled
 * \param checked
*/
void MainWindow::on_sanButton_toggled(bool checked)
{
    if(checked)
        on_actionSanskrit_triggered();
}

/*!
 * \brief MainWindow::on_hinButton_toggled
 * \param checked
*/
void MainWindow::on_hinButton_toggled(bool checked)
{
    if(checked)
        on_actionHindi_triggered();
}


/*!
 * \brief MainWindow::on_actionNew_Project_triggered
 */
void MainWindow::on_actionNew_Project_triggered()
{
    ProjectWizard* wiz = new ProjectWizard();
    wiz->show();
}

/*!
 * \brief MainWindow::on_actionLineSpace_triggered
 */
void MainWindow::on_actionLineSpace_triggered() //Not used, does not work as intended
{
    if(!curr_browser)
        return;
    QTextCursor cursor = curr_browser->textCursor();
    QTextBlockFormat format = cursor.blockFormat();
    double lineHeight = format.lineHeight()/100;
    bool False = false;
    bool *ok = &False;
    if(lineHeight == 0)
        lineHeight = 1;
    double inputLineSpace = QInputDialog::getDouble(this, "Custom Line Space", "Line Space", lineHeight, 0, 10, 2,ok);
    if(*ok) {
        // LineHeight(x,1) sets x as a percentage with base as 100
        //200 is Double LineSpace and 50 is half LineSpace
        format.setLineHeight(inputLineSpace*100, 1);
        cursor.setBlockFormat(format);
    }
}

/*!
 * \brief MainWindow::on_actionAdd_Image_triggered
 */
void MainWindow::on_actionAdd_Image_triggered()
{
    if(curr_browser) {
        QString file = QFileDialog::getOpenFileName(this, tr("Select an image"),
                                                    "./", tr("Bitmap Files (*.bmp)\n"
                                                             "JPEG (*.jpg *jpeg)\n"
                                                             "GIF (*.gif)\n"
                                                             "PNG (*.png)\n"));
        if(!file.isEmpty()){
            QFileInfo fileInfo(file);
            QString fileName = fileInfo.fileName();
            QString destinationFileName =  mProject.GetDir().absolutePath() + "/Images/Inserted/" + fileName;
            QString copiedFileName;
            if(QFileInfo::exists(destinationFileName)) {
                QString temp = destinationFileName;
                int i =0;
                while(QFileInfo::exists(temp)) {
                    temp = destinationFileName ;
                    temp.insert(destinationFileName.lastIndexOf("."),  ("(" + QString::number(++i) + ")"));
                }
                destinationFileName = temp;
                QFileInfo finfo(destinationFileName);
            }
            QFile::copy(file, destinationFileName);

            copiedFileName = QDir::current().relativeFilePath(destinationFileName);

            //QUrl Uri ( QString ( "file://%1" ).arg ( file ) );
            QImage image = QImageReader ( copiedFileName ).read();
            QTextDocument * textDocument = curr_browser->document();
            textDocument->addResource( QTextDocument::ImageResource, copiedFileName, QVariant ( image ) );
            QTextCursor cursor = curr_browser->textCursor();

            QTextImageFormat imageFormat;
            imageFormat.setWidth( image.width() );
            imageFormat.setHeight( image.height() );
            imageFormat.setName( copiedFileName );
            cursor.insertImage(imageFormat);
        }
    }
}

/*!
 * \brief MainWindow::on_actionResize_Image_triggered
 */
void MainWindow::on_actionResize_Image_triggered()
{
    QTextBlock currentBlock = curr_browser->textCursor().block();
    QTextBlock::iterator it;

    for (it = currentBlock.begin(); !(it.atEnd()); ++it) {
        QTextFragment fragment = it.fragment();
        if (fragment.isValid()) {
            if(fragment.charFormat().isImageFormat ()) {
                QTextImageFormat newImageFormat = fragment.charFormat().toImageFormat();
                QPair<double, double> size = ResizeImageView::getNewSize(this, newImageFormat.width(), newImageFormat.height());

                newImageFormat.setWidth(size.first);
                newImageFormat.setHeight(size.second);

                if (newImageFormat.isValid()) {
                    //QMessageBox::about(this, "Fragment", fragment.text());
                    //newImageFormat.setName(":/icons/text_bold.png");
                    QTextCursor helper = curr_browser->textCursor();

                    helper.setPosition(fragment.position());
                    helper.setPosition(fragment.position() + fragment.length(), QTextCursor::KeepAnchor);
                    helper.setCharFormat(newImageFormat);
                }
            }
        }
    }
}

/*!
 * \brief MainWindow::on_actionPush_triggered
 */
void MainWindow::on_actionPush_triggered()
{
    mProject.push(branchName);
}

/*!
 * \brief GetFilter
 * \param Name
 * \param list
 * \return
 */
QString GetFilter(QString & Name, const QStringList &list) {

    QString Filter = Name;
    Filter += " ( ";
    for (auto ext : list) {
        //int loc = ext.lastIndexOf(".");
        QString s = "*";
        if (ext.size() > 1) {
            if (ext[0] != '.') {
                s += ".";
            }
            s += ext;
            Filter += s + " ";
        }
    }
    Filter += ")";
    return Filter;
}

/*!
 * \brief MainWindow::LoadDocument
 * \param f
 * \param ext
 * \param name
 */
void MainWindow::LoadDocument(QFile * f, QString ext, QString name) {

    if(ui->tabWidget_2->currentIndex() >=0 && NextPrevTrig ==0)
    {
        closetab(ui->tabWidget_2->currentIndex());
        ui->tabWidget_2->removeTab(0);
    }

    f->open(QIODevice::ReadOnly);
    QFileInfo finfo(f->fileName());

    if(!(finfo.exists() && finfo.isFile())){
        return;
    }
    current_folder = finfo.dir().dirName();
    QString fileName = finfo.fileName();
    if (ui->tabWidget_2->count() != 0) {
        for (int i = 0; i < ui->tabWidget_2->count(); i++) {
            if (name == ui->tabWidget_2->tabText(i)) {
                ui->tabWidget_2->setCurrentIndex(i);
                setMFilename(f->fileName());
                UpdateFileBrekadown();
                f->close();
                return;
            }
        }
    }
    setMFilename(mFilename = f->fileName());
    UpdateFileBrekadown();
    QTextBrowser * b = new QTextBrowser(this);
    b->setReadOnly(false);

    if (!isVerifier && current_folder == "Inds") {
        QString output_file = mProject.GetDir().absolutePath() + "/" + filestructure_fw[current_folder] + "/" + fileName;
        output_file.replace(".txt", ".html");
        if (QFile::exists(output_file)) {
            b->setReadOnly(true);
        }
    }
    if (isVerifier && (current_folder == "Inds" || current_folder == "CorrectorOutput")) {
        QString output_file = mProject.GetDir().absolutePath() + "/" + filestructure_fw[current_folder] + "/" + fileName;
        output_file.replace(".txt", ".html");
        if (QFile::exists(output_file)) {
            b->setReadOnly(true);
        }
    }

    QTextStream stream(f);
    stream.setCodec("UTF-8");
    QString input = stream.readAll();
    QFont font("Shobhika Regular");
    setWindowTitle(name);
    font.setPointSize(16);
    if(ext == "txt") {
        istringstream iss(input.toUtf8().constData());
        string strHtml = "<html><body><p>";
        string line;
        while (getline(iss, line)) {
            QString qline = QString::fromStdString(line);
            if(line == "\n" | line == "" | qline.contains("\r") )
                strHtml+=line + "</p><p>";
            else strHtml += line + "<br />";
        }
        strHtml += "</p></body></html>";
        QString qstrHtml = QString::fromStdString(strHtml);
        qstrHtml.replace("<br /></p>", "</p>");

        QFont font("Shobhika-Regular");
        font.setWeight(14);
        font.setPointSize(14);
        font.setFamily("Shobhika");
        b->setFont(font);
        b->setHtml(qstrHtml);
    }
    if (ext == "html") {
        b->setHtml(input);
    }
    QDir::setCurrent(gDirOneLevelUp);   //changing application path to load document in a relative path
    b->setFont(font);
    input = b->toPlainText();

    DisplayJsonDict(b,input);
    highlight(b , input);
    
    if(fileFlag) {
        curr_browser = (QTextBrowser*)ui->tabWidget_2->widget(currentTabIndex);
        curr_browser->setDocument(b->document());
        ui->tabWidget_2->setTabText(currentTabIndex, name);
        tabchanged(currentTabIndex);

    }
    else {
        currentTabIndex = ui->tabWidget_2->addTab(b, name);
        ui->tabWidget_2->setCurrentIndex(currentTabIndex);
    }
    QString qstr = ui->tabWidget_2->tabText(currentTabIndex);
    string str = qstr.toStdString();
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    currentTabPageName=QString::fromStdString(str);

    gInitialTextHtml[currentTabPageName] = b->toHtml();

    b->setMouseTracking(true);
    b->setLineWrapColumnOrWidth(QTextEdit::NoWrap);
    b->setUndoRedoEnabled(true);

    f->close();

    QString imageFilePath = mProject.GetDir().absolutePath()+"/Images/" + gCurrentPageName;

    QString temp = imageFilePath;
    int flag=0;
    temp.replace(".txt", ".jpeg");
    if (QFile::exists(temp) && flag==0)
    {
        imageFilePath=temp;

        QFile *pImageFile = new QFile(imageFilePath);
        flag=1;
        LoadImageFromFile(pImageFile);
    }
    else
    {
        temp=imageFilePath;
    }

    temp.replace(".html", ".jpeg");
    if (QFile::exists(temp) && flag==0)
    {
        imageFilePath=temp;
        QFile *pImageFile = new QFile(imageFilePath);
        flag=1;
        LoadImageFromFile(pImageFile);
    }
    else
    {
        temp = imageFilePath;
    }
    temp.replace(".html", ".png");
    if (QFile::exists(temp) && flag==0)
    {
        imageFilePath=temp;
        QFile *pImageFile = new QFile(imageFilePath);
        flag=1;
        LoadImageFromFile(pImageFile);
    }
    else
    {
        temp = imageFilePath;
    }
    temp.replace(".html", ".jpg");
    if (QFile::exists(temp) && flag==0)
    {
        imageFilePath=temp;
        QFile *pImageFile = new QFile(imageFilePath);
        flag=1;
        LoadImageFromFile(pImageFile);
    }
    else
    {
        temp = imageFilePath;
    }
    NextPrevTrig =0;

    // Enabling Selection in treeView
    ui->treeView->selectionModel()->clearSelection();
    QModelIndex currentTreeItemIndex = ui->treeView->selectionModel()->currentIndex();
    QModelIndex parentIndex = currentTreeItemIndex.parent();
    auto model = ui->treeView->model();
    int rowCount = ui->treeView->model()->rowCount(parentIndex);

    QString treeItemLabel;
    for (int i = 0; i < rowCount; i++)
    {
        QModelIndex index = model->index(i, 0, parentIndex);
        treeItemLabel = index.data(Qt::DisplayRole).toString();

        if (index.isValid())
        {
            if (treeItemLabel == currentTabPageName)
            {
                ui->treeView->selectionModel()->setCurrentIndex(index, QItemSelectionModel::Select);
                break;
            }
            else
            {
                // Removing the space from each Label which was present at the starting of every label in the CorrectorOutput Folder
                treeItemLabel.remove(0, 1);
                if (treeItemLabel == currentTabPageName)
                {
                    ui->treeView->selectionModel()->setCurrentIndex(index, QItemSelectionModel::Select);
                    break;
                }
            }
        }
    }
}

/*!
 * \brief MainWindow::LoadImageFromFile
 * \param f
 */
void MainWindow::LoadImageFromFile(QFile * f)
{

    QString localFileName = f->fileName();
    loadimage = true;

    imageOrig.load(localFileName);
    if (graphic)delete graphic;
    graphic = new QGraphicsScene(this);
    graphic->addPixmap(QPixmap::fromImage(imageOrig));

    ui->graphicsView->setScene(graphic);
    ui->graphicsView->fitInView(graphic->itemsBoundingRect(), Qt::KeepAspectRatio);
    if (z)delete z;
    z = new Graphics_view_zoom(ui->graphicsView);
    z->set_modifiers(Qt::NoModifier);

    item1 =new QGraphicsRectItem(0, 0, 1, 1);
    graphic->addItem(item1);

    //! while loading an image; create crop_rect and add it to graphic; so we can track & capture mouse press and mouse release event
    crop_rect = new QGraphicsRectItem(0, 0, 1, 1);
    graphic->addItem(crop_rect);
    ui->graphicsView->setMouseTracking(true);
    ui->graphicsView->viewport()->installEventFilter(this);
}

void MainWindow::file_click(const QModelIndex & indx)
{
    auto item = (TreeItem*)indx.internalPointer();
    auto qvar = item->data(0).toString();
    if(qvar == "Document" || qvar == "Image" || qvar=="CorrectorOutput" || qvar=="VerifierOutput")
        return;
    auto file = item->GetFile();

    QString fileName = file->fileName();
    NodeType type = item->GetNodeType();
    switch (type) {

    case NodeType::_FILETYPE:
    {
        QFileInfo f(*file);
        QString suff = f.completeSuffix();
        if (suff == "txt" || suff == "html") {
            LoadDocument(file,suff,qvar);
        }

        if (suff == "jpeg" || suff == "jpg" || suff == "png")
        {
            LoadImageFromFile(file);
        }
        break;
    }
    default:
        break;
    }
}

/*!
 * \brief MainWindow::OpenDirectory
 */
void MainWindow::OpenDirectory()
{
    auto item = (TreeItem*)curr_idx.internalPointer();
    auto filtr = item->GetFilter();
    auto name = filtr->name();
    auto list = filtr->extensions();

    std::string extn = GetFilter(name, list).toStdString();
    QList<QString> files = QFileDialog::getOpenFileNames(this, "Open File", "./", tr(extn.c_str()));
    for (QString file : files) {
        QFile f(file);
        mProject.addFile(*filtr, f);
    }
}

/*!
 * \brief MainWindow::RemoveFile
 */
void MainWindow::RemoveFile()
{
    //std::cout << "Test";
    auto item = (TreeItem*)curr_idx.internalPointer();
    Filter * filtr = item->GetFilter();
    QFile * file = item->GetFile();
    if (file->exists())
    {
        mProject.removeFile(curr_idx, *filtr, *file);
        ui->treeView->reset();
    }
}

/*!
 * \brief MainWindow::AddNewFile
 */
void MainWindow::AddNewFile()
{
    auto item = (TreeItem*)curr_idx.internalPointer();
    Filter * filtr = item->GetFilter();
    QString name = filtr->name();
    QStringList list = filtr->extensions();
    QString filter = GetFilter(name, list);
    std::string str = filter.toStdString();
    QFile fileo(QFileDialog::getOpenFileName(this, "Open File", "./", tr(str.c_str())));
    if (fileo.exists())
    {
        mProject.addFile(*filtr, fileo);
    }
}

/*!
 * \brief MainWindow::CustomContextMenuTriggered
 * \param p
 */
void MainWindow::CustomContextMenuTriggered(const QPoint & p)
{
    curr_idx = ui->treeView->indexAt(p);

    if (curr_idx.isValid())
    {
        auto item = (TreeItem*)curr_idx.internalPointer();
        switch (item->GetNodeType())
        {
        case _FILETYPE:
        {
            QMenu * m = new QMenu(this);
            QAction * act = new QAction("Remove File", this);
            connect(act, &QAction::triggered, this, &MainWindow::RemoveFile);
            m->addAction(act);
            m->move(ui->treeView->mapToGlobal(p));
            m->show();
        }
            break;
        case FILTER:
        {
            QMenu * m = new QMenu(this);

            QAction * act = new QAction("Add New File", this);
            connect(act, &QAction::triggered, this, &MainWindow::AddNewFile);
            m->addAction(act);
            QAction * act2 = new QAction("Add Files", this);
            connect(act2, &QAction::triggered, this, &MainWindow::OpenDirectory);
            m->addAction(act2);
            m->move(ui->treeView->mapToGlobal(p));
            m->show();
            break;
        }
        }
    }
}

/*!
 * \brief MainWindow::closetab
 * \param idx
 */
void MainWindow::closetab(int idx)
{

    QTextBrowser *closing_browser = (QTextBrowser*)ui->tabWidget_2->widget(idx);
    QString closing_browserHtml = closing_browser->toHtml();
    QString qstr = ui->tabWidget_2->tabText(idx);

    string str = qstr.toStdString();
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
   QString closingTabPageName = QString::fromStdString(str);

    if(!closing_browser->isReadOnly() && (closing_browserHtml != gInitialTextHtml[closingTabPageName]))
    {
        int btn = QMessageBox::question(this, "Save?", "Do you want to save " + closingTabPageName + " file?",
                                        QMessageBox::StandardButton::Ok, QMessageBox::StandardButton::No);
        if (btn == QMessageBox::StandardButton::Ok)
            on_actionSave_triggered();
    }
    delete ui->tabWidget_2->widget(idx);
    //deleteEditedFilesLog();
}

/*!
 * \brief MainWindow::tabchanged
 * \param idx
 */
void MainWindow::tabchanged(int idx)
{
    currentTabIndex = idx;
    curr_browser = (QTextBrowser*)ui->tabWidget_2->widget(currentTabIndex);
    QString qstr = ui->tabWidget_2->tabText(currentTabIndex);
    string str = qstr.toStdString();
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    currentTabPageName=QString::fromStdString(str);
    if(mRole=="Corrector" | mRole=="Verifier"){
        setMFilename(mProject.GetDir().absolutePath() + "/" + gCurrentDirName + "/" + currentTabPageName);
    }
    else{
        setMFilename(mProject.GetDir().absolutePath() + "/Inds/" + currentTabPageName);
          }
    UpdateFileBrekadown();


    QString imagePathFile = mFilename;
    imagePathFile.replace("CorrectorOutput", "Images");
    imagePathFile.replace("VerifierOutput", "Images");
    imagePathFile.replace("Inds", "Images");
    QString temp = imagePathFile;
    int flag=0;
    temp.replace(".txt", ".jpeg");
    if (QFile::exists(temp) && flag==0)
    {
        imagePathFile=temp;
        QFile *pImageFile = new QFile(imagePathFile);
        flag=1;
        LoadImageFromFile(pImageFile);
    }
    else
    {
        temp=imagePathFile;
    }
    temp.replace(".html", ".jpeg");
    if (QFile::exists(temp) && flag==0)
    {
        imagePathFile=temp;
        QFile *pImageFile = new QFile(imagePathFile);
        flag=1;
        LoadImageFromFile(pImageFile);
    }
    else
    {
        temp=imagePathFile;
    }
    temp.replace(".html", ".png");
    if (QFile::exists(temp) && flag==0)
    {
        imagePathFile=temp;
        QFile *pImageFile = new QFile(imagePathFile);
        flag=1;
        LoadImageFromFile(pImageFile);
    }
    else
    {
        temp=imagePathFile;
    }
    temp.replace(".html", ".jpg");
    if (QFile::exists(temp) && flag==0)
    {
        imagePathFile=temp;
        QFile *pImageFile = new QFile(imagePathFile);
        flag=1;
        LoadImageFromFile(pImageFile);
    }
    else
    {
        temp=imagePathFile;
    }

    myTimer.start();
    DisplayTimeLog();
    //DisplayJsonDict(b);
}

/*!
 * \brief MainWindow::setMFilename
 * \param name
 * sets current file and image
 */
void MainWindow::setMFilename( QString name )
{
    mFilename = name;
    QString tempName = mFilename;

    tempName.replace("Inds", "Images");
    tempName.replace("CorrectorOutput", "Images");
    tempName.replace("VerifierOutput", "Images");

    tempName.replace(".txt", ".jpeg").replace(".html", ".jpeg");

    // select the image. look for jpeg, jpg and png(select first whichever is found)
    QFileInfo check_file(tempName);
    if (check_file.exists() && check_file.isFile())
    {
        mFilenameImage = tempName;
        return;
    }

    tempName.replace(".jpeg", ".jpg");
    check_file.setFile(tempName);
    if (check_file.exists() && check_file.isFile())
    {
        mFilenameImage = tempName;
        return;
    }

    tempName.replace(".jpg", ".png");
    check_file.setFile(tempName);
    if (check_file.exists() && check_file.isFile())
    {
        mFilenameImage = tempName;
        return;
    }
}

/*!
 * \brief MainWindow::directoryChanged
 * \param path
 */
void MainWindow::directoryChanged(const QString &path)
{

    QDir d(path);

    QString dirstr = d.dirName();
    auto list = d.entryList(QDir::Files);
    QSet<QString> s;
    for (auto file : list)
    {
        s.insert(file);
    }
    if (dirstr == "CorrectorOutput")
    {
        QSet<QString> added = s - corrector_set;
        QSet<QString> removed = corrector_set - s;
        QString str = mProject.GetDir().absolutePath() + "/CorrectorOutput/";
        Filter * filter = mProject.getFilter("CorrectorOutput");
        for (auto f : added)
        {
            QString t = str + "/" + f;
            QFile f2(t);
            mProject.AddTemp(filter, f2, "");
            corrector_set.insert(f);
        }
    }
    else
    {
        QSet<QString> added = s - verifier_set;
        QString str = mProject.GetDir().absolutePath() + "/VerifierOutput/";
        Filter * filter = mProject.getFilter("VerifierOutput");
        for (auto f : added)
        {
            QString t = str + "/" + f;
            QFile f2(t);
            mProject.AddTemp(filter, f2, "");
            verifier_set.insert(f);
        }
    }
}

bool MainWindow::checkUnsavedWork() {
    for (int i = 0; i < ui->tabWidget_2->count(); ++i) {
        ui->tabWidget_2->setCurrentIndex(i);
        QTextBrowser *closing_browser = (QTextBrowser*)ui->tabWidget_2->widget(i);
        QString closing_browserHtml = closing_browser->toHtml();
        QString closingTabPageName = ui->tabWidget_2->tabText(i);
        QFile f(mFilename);
        QFileInfo fileInfo(f.fileName());
        QString filename(fileInfo.fileName());
        if (filename == "Untitled" || closing_browser->isReadOnly()) {
            continue;
        }
        if(closing_browserHtml != gInitialTextHtml[closingTabPageName]) {
            return true;
        }
    }
    return false;
}

/*!
 * \brief MainWindow::saveAllWork
 */
void MainWindow::saveAllWork()
{
    for (int i = 0; i < ui->tabWidget_2->count(); ++i)
    {
        ui->tabWidget_2->setCurrentIndex(i);
        QTextBrowser *closing_browser = (QTextBrowser*)ui->tabWidget_2->widget(i);
        QString closing_browserHtml = closing_browser->toHtml();
        QString closingTabPageName = ui->tabWidget_2->tabText(i);
        QFile f(mFilename);
        QFileInfo fileInfo(f.fileName());
        QString filename(fileInfo.fileName());
        if (filename == "Untitled")
        {
            continue;
        }
        if(!closing_browser->isReadOnly() && closing_browserHtml != gInitialTextHtml[closingTabPageName]) {
            on_actionSave_triggered();
        }
    }
}

/*!
 * \brief MainWindow::on_actionSave_All_triggered
 */
void MainWindow::on_actionSave_All_triggered()  //enable when required
{
    if(ui->tabWidget_2->count()!=0)
    {
        for(int i=0;i<ui->tabWidget_2->count();i++)
        {
            ui->tabWidget_2->setCurrentIndex(i);
            UpdateFileBrekadown();
            on_actionSave_triggered();
        }
    }

}

/*!
 * \brief MainWindow::closeEvent
 * \param event
 */
void MainWindow::closeEvent (QCloseEvent *event)
{
    bool isUnsaved = checkUnsavedWork();

    if (isUnsaved)
    {
        QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Close",
                                                                    tr("You have unsaved files. Your changes will be lost if you don't save them.\n"),
                                                                    QMessageBox::Discard | QMessageBox::Cancel | QMessageBox::Save,
                                                                    QMessageBox::Save);
        if (resBtn == QMessageBox::Cancel)
        {
            event->ignore();
        }
        else if (resBtn == QMessageBox::Discard)
        {
            event->accept();
        }
        else
        {
            saveAllWork();
            event->accept();
        }
    }
}

/*!
 * \brief MainWindow::sendEmail
 * \param emailText
 * \return
 */
bool MainWindow::sendEmail(QString emailText)
{
    QString pmEmail = mProject.get_pmEmail();
    if(pmEmail == "" || (!pmEmail.contains("@")))
        return 0;

    SimpleMail::Sender sender ("smtp.gmail.com", 465, SimpleMail::Sender::SslConnection);
    sender.setUser("aksharanveshini.iitb@gmail.com");
    sender.setPassword("backend-ui"); //has to be encoded
    SimpleMail::MimeMessage message;
    message.setSender(SimpleMail::EmailAddress("aksharanveshini.iitb@gmail.com", "Akshar Anveshini"));

    QList <SimpleMail::EmailAddress> listRecipients;
    listRecipients.append(pmEmail);
    message.setToRecipients(listRecipients);
    message.setSubject(mProject.get_setId() + " Turn In");
    SimpleMail::MimeText *text = new SimpleMail::MimeText();
    text->setText(emailText);
    message.addPart(text);
    if(!sender.sendMail(message))
        return 0;

    return 1;
}

void MainWindow:: highlight(QTextBrowser *b , QString input)
{

    QMap <QString, QString>::iterator grmIterator;
//    QTextCharFormat fmt;
//    fmt.setBackground(Qt::yellow);
    QTextCursor cursor(b->document());
    int indexOfReplacedWord;
    int from=0;
    int count;
    int numReplaced=0;
    for (grmIterator = mapOfReplacements.begin(); grmIterator != mapOfReplacements.end(); ++grmIterator)
    {
        count = input.count(grmIterator.value(),Qt::CaseInsensitive);

        numReplaced=0;
        from=0;
        int flag=0;

        while(numReplaced<count)
        {

            int endIndex;
            indexOfReplacedWord = input.indexOf(grmIterator.value(),from , Qt::CaseInsensitive);
            endIndex = indexOfReplacedWord;
//            qDebug() << indexOfReplacedWord << " " <<endIndex;
//            while(input[endIndex]!=" ")
//                endIndex++;
//            qDebug() << indexOfReplacedWord << " " <<endIndex;
            int len = grmIterator.value().length();
            while(len > 0)
            {
                endIndex++;
                len--;
            }
            if(input[endIndex]!=" ")
                flag=1;
            if(flag==0)
            {
                cursor.setPosition(indexOfReplacedWord, QTextCursor::MoveAnchor);
                cursor.setPosition(endIndex, QTextCursor::KeepAnchor);
                //cursor.setCharFormat(fmt);
                QTextEdit::ExtraSelection h;
                h.format.setBackground(Qt::yellow);
            }
            from = endIndex;
            numReplaced+=1;
            flag=0;
        }
    }


}

void MainWindow::on_actionas_PDF_triggered()
{
    QTextDocument *document = new QTextDocument();
     QString currentDirAbsolutePath;
    if(mRole=="Verifier")
    currentDirAbsolutePath = gDirTwoLevelUp + "/VerifierOutput/";
    else if (mRole=="Corrector") {
        currentDirAbsolutePath = gDirTwoLevelUp + "/CorrectorOutput/";
    }

    QDir dir(currentDirAbsolutePath);
    dir.setSorting(QDir::SortFlag::DirsFirst | QDir::SortFlag::Name);
    QDirIterator dirIterator(dir,QDirIterator::NoIteratorFlags);

   // QDirIterator dirIterator(currentDirAbsolutePath);
    QString html_contents="";
    QString mainHtml;
    int count = dir.entryList(QStringList("*.html"), QDir::Files | QDir::NoDotAndDotDot).count();
    int counter=0;

    int stIndex, startFrom = 0;
    QString searchString = "background-color:#"; // string to be searched
    int l = searchString.length();
    QString whiteColor = "ffffff";

    for(auto a : dir.entryList())
    {
        QString it_file_path = a;
        QString x=currentDirAbsolutePath+a;

        startFrom = 0; // The position from which searchString will be scanned

        if(x.contains("."))
        {
            QStringList html_files = x.split(QRegExp("[.]"));
;
            if(html_files[1]=="html")
            {
                QFile file(x);
                    if (!file.open(QIODevice::ReadOnly)) qDebug() << "Error reading file main.html";
                    QTextStream stream(&file);
                    stream.setCodec("UTF-8");
                    mainHtml=stream.readAll();
                    // Changing Background of text as white
                    while (true){
                        stIndex = mainHtml.indexOf(searchString, startFrom);
                        if (stIndex == -1)
                            break;
                        stIndex += l;
                        mainHtml.replace(stIndex, 6, whiteColor); // Here, 6 is used because length of whiteColor is 6
                        startFrom = stIndex + 6;
                    }
                    counter++;
                    if(counter<count){
                        mainHtml+="<P style=\"page-break-before: always\"></P>";
                    }
                    file.close();
              html_contents.append(mainHtml);

            }
            else {
                continue;
            }
        }
    }
    document->setHtml(html_contents);
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setPageMargins(QMarginsF(5, 5, 5, 5));
    printer.setOutputFileName(gDirTwoLevelUp+"/BookSet.pdf");

    document->setPageSize(printer.pageRect().size());
    document->print(&printer);
}

void MainWindow::on_actionGet_Help_triggered()
{
    QDesktopServices::openUrl(QUrl("https://docs.google.com/document/d/1PAQKz3Vwu5EN850uxZUeSejvmwF2293j/edit?usp=sharing&ouid=114703528031965332802&rtpof=true&sd=true", QUrl::TolerantMode));
}

void MainWindow::on_actionTutorial_triggered()
{
    QDesktopServices::openUrl(QUrl("https://www.youtube.com/channel/UCrViL9ay1RO9lS7FIlnh8BQ", QUrl::TolerantMode));
}

void MainWindow::on_actionLinux_triggered()
{
    QDesktopServices::openUrl(QUrl("https://docs.google.com/document/d/15PbeYfdMl1eMypAMoqibG6Z5dxipfx_aZBSAhifTlec/edit?usp=sharing", QUrl::TolerantMode));
}

void MainWindow::on_actionWindows_triggered()
{
    QDesktopServices::openUrl(QUrl("https://docs.google.com/document/d/1xcXsNU03d-1RneksUzCHRyC4jm1mBF-N/edit?usp=sharing&ouid=114703528031965332802&rtpof=true&sd=true", QUrl::TolerantMode));
}

void MainWindow::on_actionShortcut_Guide_triggered()
{
    ShortcutGuideDialog dialog;
    dialog.setModal(true);
    dialog.exec();
}

