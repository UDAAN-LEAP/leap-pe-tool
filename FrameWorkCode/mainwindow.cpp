#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "averageaccuracies.h"
#include "eddis.h"
#include "slpNPatternDict.h" //as included through lcsqt.h
#include "trieEditdis.h"
#include "meanStdPage.h"
#include <math.h>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include "DiffView.h"
#include "diff_match_patch.h"
#include "interndiffview.h"
#include "commentsview.h"
#include "Symbols.h"
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
#include <QFileSystemWatcher>
#include <set>
#include <algorithm>
#include <QSet>
#include <QAction>
#include "ProjectWizard.h"
#include <SimpleMail/SimpleMail>
//# include <QTask>
#include <QDebug>
#include <QJsonObject>
#include <QTextDocumentFragment>
#include <sstream>
#include <QVector>
#include<vector>
#include <QJsonValue>

#ifdef __unix__
#include <unistd.h>
#endif
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

//map<string, int> GPage; trie TGPage;
//map<string, int> PWords;//Common/Possitive OCR Words // already defined before
map<string, string> CPair;//Correction Pairs
bool highlightchecked = false;
map<int, QString> commentdict;
map<int, vector<int>> commentederrors;
int openedFileChars;
int openedFileWords;
bool gSaveTriggered = 0;
map<QString, QString> filestructure_fw;
map<QString, QString> filestructure_bw = { {"VerifierOutput","CorrectorOutput"},
									 {"CorrectorOutput","Inds"},
										  {"Inds" , "Inds"}
};

QString gSanskrit, gHindi;

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

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
}
bool MainWindow::setRole(QString role)
{
    this->mRole = role;
    if(mRole == "Admin") {
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

    if(mRole == "Project Manager"){
        ui->actionNew_Project->setEnabled(true);
        ui->actionNew_Project->setVisible(true);
        mRole = "Verifier";

    }

    if(mRole == "Verifier") {
        filestructure_fw = { {"Inds","VerifierOutput"},
                             {"CorrectorOutput","VerifierOutput",},
                             {"VerifierOutput","VerifierOutput" }
                           };
        isVerifier = 1;
        ui->actionTurn_In->setVisible(false);
        ui->actionTurn_In->setEnabled(false);

    } else if(mRole == "Corrector") {
        filestructure_fw = { {"Inds","CorrectorOutput"},
                             {"CorrectorOutput","CorrectorOutput",},
                             {"VerifierOutput","CorrectorOutput" }
                           };
        ui->compareVerifierOutput->setVisible(false);
        ui->compareVerifierOutput->setEnabled(false);

        ui->actionVerifier_Turn_In->setVisible(false);
        ui->actionVerifier_Turn_In->setEnabled(false);
        isVerifier = 0;
    }
    else {
        int result = QMessageBox::information(this,"Login","Login Failed");

        return false;
    }
    return true;

}
MainWindow::~MainWindow()
{
	delete ui;
}

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

void MainWindow::UpdateFileBrekadown()
{
    QFileInfo finfo(mFilename);
    gCurrentPageName = finfo.fileName();
    gDirTwoLevelUp = mProject.GetDir().absolutePath();
    gCurrentDirName = finfo.dir().dirName();
    gDirOneLevelUp = gDirTwoLevelUp + "/" + gCurrentDirName;
}
void DisplayError(QString error)
{
    QMessageBox msgBox;
    msgBox.setText(error);
    msgBox.exec();
}


//bool OPENSPELLFLAG = 1;// TO NOT CONVERT ASCII STRINGS TO DEVANAGARI ON OPENING WHEN SPELLCHECK IS CLICKED
int GetPageNumber(string localFilename, string *no, size_t *loc, QString *ext)
{

    string nos = "0123456789";
    *no = "";
    *loc = localFilename.find(".txt");
    *ext = "txt";
    if(*loc == string::npos) {
        *loc = localFilename.find(".html");
        *ext = "html";
    }
    if(*loc == string::npos)
        return 0;
    string s = localFilename.substr((*loc)-1,1);
    while(nos.find(s) != string::npos) {
        *no = s + *no; (*loc)--; s = localFilename.substr((*loc)-1,1);
    }
    return 1;
}

int GetGraphemesCount(QString string)
{
    int count = 0;
    QTextBoundaryFinder finder = QTextBoundaryFinder(QTextBoundaryFinder::BoundaryType::Grapheme, string);
    while (finder.toNextBoundary() != -1) {
            count++;
        }
    int spaces = string.count(' ');
    return count - spaces;
}

int LevenshteinWithGraphemes(QList<Diff> diffs)
{
    int levenshtein = 0;
    QString diffChars = "";
    QString insertions = "";
    QString deletions = "";
    foreach(Diff aDiff, diffs) {
      switch (aDiff.operation) {
        case INSERT:
          insertions += aDiff.text;
          break;
        case DELETE:
          deletions += aDiff.text;
          break;
        case EQUAL:
          // A deletion and an insertion is one substitution.
          if(GetGraphemesCount(insertions)> GetGraphemesCount(deletions))
              levenshtein += insertions.length();
          else
              levenshtein += deletions.length();
          insertions = "";
          deletions = "";
          break;
        default:
            break;
      }
    }
    if(GetGraphemesCount(insertions)> GetGraphemesCount(deletions))
        levenshtein += insertions.length();
    else
        levenshtein += deletions.length();
    return levenshtein;
}


void MainWindow::on_actionLoad_Next_Page_triggered()
{
    if(curr_browser) {
        if(gInitialTextHtml[currentTabPageName].compare(curr_browser->toHtml())) {
            int btn = QMessageBox::question(this, "Save?", "Do you want to save this file?",
                                            QMessageBox::StandardButton::Ok, QMessageBox::StandardButton::No);
            if (btn == QMessageBox::StandardButton::Ok)
                on_actionSave_triggered();
        }

        string localFilename = mFilename.toUtf8().constData();
        string localCurrentTabPageName = currentTabPageName.toUtf8().constData();

        int nMilliseconds = myTimer.elapsed();
        gSeconds = nMilliseconds/1000;
        QString currentVersion = mProject.get_version();
        if(mRole == "Verifier" && mRole != currentVersion)
            currentVersion = QString::number(currentVersion.toInt() - 1);

        gSeconds = timeLog[mRole +":"+ gCurrentPageName +":V-"+ currentVersion];

        SaveTimeLog();

        string no = "";
        size_t loc;
        QString ext = "";
        if(!GetPageNumber(localFilename, &no, &loc, &ext))
            return;
        localFilename.replace(loc,no.size(),to_string(stoi(no) + 1));
        QFile *file = new QFile(QString::fromStdString(localFilename));
        QFileInfo finfo(file->fileName());
        if(!(finfo.exists() && finfo.isFile()))
            return;
        if(!GetPageNumber(localCurrentTabPageName, &no, &loc, &ext))
            return;
        localCurrentTabPageName.replace(loc,no.size(),to_string(stoi(no) + 1));
        currentTabPageName = QString::fromStdString(localCurrentTabPageName);

        fileFlag = 1;
        LoadDocument(file, ext, currentTabPageName);
        fileFlag = 0;
   }
}


void MainWindow::on_actionLoad_Prev_Page_triggered()
{
    if(curr_browser) {
        if(gInitialTextHtml[currentTabPageName].compare(curr_browser->toHtml())) {
            int btn = QMessageBox::question(this, "Save?", "Do you want to save " + currentTabPageName + " file?",
                                            QMessageBox::StandardButton::Ok, QMessageBox::StandardButton::No);
            if (btn == QMessageBox::StandardButton::Ok)
                on_actionSave_triggered();
        }

        string localFilename = mFilename.toUtf8().constData();
        string localCurrentTabPageName = currentTabPageName.toUtf8().constData();

        int nMilliseconds = myTimer.elapsed();
        gSeconds = nMilliseconds/1000;
        QString currentVersion = mProject.get_version();
        if(mRole == "Verifier" && mRole != currentVersion)
            currentVersion = QString::number(currentVersion.toInt() - 1);

        gSeconds = timeLog[mRole +":"+ gCurrentPageName +":V-"+ currentVersion];

        SaveTimeLog();

        string no = "";
        size_t loc;
        QString ext = "";
        if(!GetPageNumber(localFilename, &no, &loc, &ext))
            return;



        localFilename.replace(loc,no.size(),to_string(stoi(no) - 1));
        QFile *file = new QFile(QString::fromStdString(localFilename));
        QFileInfo finfo(file->fileName());
        if(!(finfo.exists() && finfo.isFile())) // Check if file exists
            return;

        if(!GetPageNumber(localCurrentTabPageName, &no, &loc, &ext))
            return;
        localCurrentTabPageName.replace(loc,no.size(),to_string(stoi(no) - 1));
        currentTabPageName = QString::fromStdString(localCurrentTabPageName);
        fileFlag = 1;
        LoadDocument(file, ext, currentTabPageName);
        fileFlag = 0;
   }

}




vector<string> vGPage, vIPage, vCPage; // for calculating WER

vector<string> vBest;
void MainWindow::on_actionCreateBest2OCR_triggered()
{
	if (curr_browser) {

		// vGBook and vIBook contain the loaded words from both OCR

		int vGsz = vGBook.size(), vIsz = vIBook.size();
		//cout << vGsz << " " << vIsz << endl;
		int win = vGsz - vIsz;
		if (win < 0) win = -1 * win;
		win = std::max(win, 5);

		//float WER = 0;
		int mineEdDis = 1000;
		// search for a word(pre space, post space as well) in Indsenz within win sized window in GDocs and if found then add to PWords
		//cout << win << endl;
		string localFilename = mFilename.toUtf8().constData();
		size_t loc = localFilename.find("Inds");
		localFilename = localFilename.substr(0, loc);
		localFilename = localFilename + "Best2ocrRep.txt";
		cout << "writing to" << localFilename << " please wait" << endl;
		std::ofstream best2(localFilename);
		for (int t = 0; t < vIsz; t++) {
			mineEdDis = 1000;
			//cout << mineEdDis << endl;
			string BestString1;
			//cout << vIBook[t] << endl;
			string s1 = vIBook[t]; //(vGBook[t1].find(s1) != string::npos) || (vGBook[t1] == s1)
			//cout << s1 << "s1 " ;
			for (int t1 = std::max(t - win, 0); t1 < min(t + win, vGsz); t1++) {

				int EdDis = editDist(vGBook[t1], s1);
				if (EdDis < mineEdDis) { mineEdDis = EdDis; BestString1 = vGBook[t1]; }
				if (vGBook[t1] == s1) { BestString1 = s1; break; }
			}
			//cout << BestString1 << "BestString1 " ;

			if (s1 == BestString1) { vBest.push_back(s1); best2 << toDev(s1) << " "; }
			else {
				string s22 = bestIG(s1, BestString1, Dict); vBest.push_back(s22); best2 << toDev(s22) << " ";

			}
		}
		best2 << endl;
	}
}

map<string, int> wordLineIndex;
bool ConvertSlpDevFlag = 0;
void MainWindow::on_actionSpell_Check_triggered()
{
	if (curr_browser) {
		auto txcursor = curr_browser->textCursor();
		txcursor.setPosition(0);
		auto format = txcursor.charFormat();
		format.setForeground(QColor(255, 0, 0));

		while (!txcursor.atEnd()) {
			txcursor.movePosition(QTextCursor::MoveOperation::EndOfWord);
			txcursor.select(QTextCursor::SelectionType::WordUnderCursor);
			if (txcursor.hasSelection()) {
				txcursor.beginEditBlock();
				txcursor.mergeCharFormat(format);
				txcursor.endEditBlock();
			}
			txcursor.movePosition(QTextCursor::MoveOperation::NextWord);
		}
	}
}

/*
string strPrev;
bool MainWindow::eventFilter(QObject *object, QEvent *event)
{

   /.* QTextCursor cursor = curr_browser->textCursor();
	cursor.select(QTextCursor::WordUnderCursor);
	// code to copy selected string:-
	strPrev = cursor.selectedText().toUtf8().constData();/


return 1;
}
*/


/*
// refer http://stackoverflow.com/questions/28746541/qt-mousemove-event-not-being-caught-in-eventfilter
string strPrev, linePrev;
size_t ind = 0;
bool MainWindow::eventFilter(QObject *object, QEvent *event)
{

	QTextCursor cursor = curr_browser->textCursor();
	cursor.select(QTextCursor::WordUnderCursor);
	// code to copy selected string:-
	string str1 = cursor.selectedText().toUtf8().constData();;

	cursor.select(QTextCursor::LineUnderCursor);
	string line1 = cursor.selectedText().toUtf8().constData();;

	if((str1 != strPrev) || (line1 != linePrev) ) {

	strPrev = str1; linePrev = line1;
	QImage image = imageOrig;
	ind = wordLineIndex[(str1 + "###" + line1)];
	cout << wordLineIndex.size()<< " " << str1 + "###" + line1 << " " << ind << endl;

	for(int i = vx[ind]; i < (vx[ind] + vw[ind]); i++){


				image.setPixel(i,vy[ind],qRgb(150,0,0)); image.setPixel(i,vy[ind]-1,qRgb(150,0,0));  //i,vy[ind]-1,QRg
				image.setPixel(i,(vy[ind] + vh[ind]),qRgb(150,0,0));image.setPixel(i,(vy[ind] + vh[ind]+1),qRgb(150,0,0));


	}
	for(int j = vy[ind]; j < (vy[ind] + vh[ind]); j++){

				image.setPixel(vx[ind],j,qRgb(150,0,0)); image.setPixel(vx[ind]-1,j,qRgb(150,0,0));//qGray(150)
				image.setPixel((vx[ind]+vw[ind]),j,qRgb(150,0,0)); image.setPixel((vx[ind]+vw[ind] + 1 ),j,qRgb(150,0,0));

	}

	QImage imageO = image;

	QGraphicsScene *graphic = new QGraphicsScene(this);
	graphic->addPixmap(QPixmap::fromImage(imageO));
	ui->graphicsView->setScene(graphic);
	ui->graphicsView->fitInView(graphic->itemsBoundingRect(),Qt::KeepAspectRatio);

    } // 1st if ends

	return false;

} */


bool RightclickFlag = 0;
string selectedStr ="";
//GIVE EVENT TO TEXT BROWZER INSTEAD OF MAINWINDOW
void MainWindow::mousePressEvent(QMouseEvent *ev)
{

    if (curr_browser) {
        curr_browser->cursorForPosition(ev->pos());

        DisplayTimeLog();

        if ((ev->button() == Qt::RightButton) || (RightclickFlag))
        {
            QTextCursor cursor1 = curr_browser->cursorForPosition(ev->pos());
            QTextCursor cursor = curr_browser->textCursor();
            cursor.select(QTextCursor::WordUnderCursor);
            // code to copy selected string:-
            QString str1 = cursor.selectedText();
            selectedStr = str1.toUtf8().constData();
            if (selectedStr != "") {
                // code to display options on rightclick
                curr_browser->setContextMenuPolicy(Qt::CustomContextMenu);//IMP TO AVOID UNDO ETC AFTER SELECTING A SUGGESTION
                QMenu* popup_menu = curr_browser->createStandardContextMenu();
                QMenu* spell_menu;

                spell_menu = new QMenu("suggestions", this);
                QFont font("Shobhika-Regular");
                font.setWeight(14);
                font.setPointSize(12);
                spell_menu->setFont(font);
                //QAction* action = tr("tihor");
                QAction* act;
                //vector<string> Words =  print5NearestEntries(TGPage,selectedStr);
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
                //cout <<" here " << toDev(Words[0]) << endl;


                // find nearest confirming to OCR Sugg from Book
                string nearestCOnfconfirmingSuggvec;
                vector<string> vec = Words1;
                int min = 100;
                for (size_t t = 0; t < vec.size(); t++) {
                    vector<string> wordConfusions; vector<int> wCindex;
                    int minFactor = loadWConfusionsNindex1(selectedStr, vec[t], ConfPmap, wordConfusions, wCindex);
                    wordConfusions.clear(); wCindex.clear();
                    if (minFactor < min) { min = minFactor; nearestCOnfconfirmingSuggvec = vec[t]; }
                }

                // find nearest confirming to OCR Sugg from PWords
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
                string CSugg = CPair[toslp1(selectedStr)];
                if (CSugg.size() > 0) mapSugg[toslp1(CSugg)]++;
                if (Words.size() > 0)  mapSugg[toslp1(Words[0])]++;
                if (Words1.size() > 0) mapSugg[toslp1(nearestCOnfconfirmingSuggvec)]++;
                if (PWords1.size() > 0) mapSugg[toslp1(nearestCOnfconfirmingSuggvec1)]++;
                if (PairSugg.size() > 0) mapSugg[toslp1(PairSugg)]++;
                mapSugg[SamasBreakLRCorrect(toslp1(selectedStr), Dict, PWords, TPWords, TPWordsP)]++;
                string s1 = toslp1(selectedStr);
                string nearestCOnfconfirmingSuggvecFont = "";
                min = 100;
                for (size_t t = 0; t < vec.size(); t++) {
                    vector<string> wordConfusions; vector<int> wCindex;
                    int minFactor = loadWConfusionsNindex1(s1, vec[t], ConfPmapFont, wordConfusions, wCindex);
                    wordConfusions.clear(); wCindex.clear();
                    if (minFactor < min) { min = minFactor; nearestCOnfconfirmingSuggvecFont = vec[t]; }
                }
                if (nearestCOnfconfirmingSuggvecFont.size() > 0) mapSugg[nearestCOnfconfirmingSuggvecFont]++;

                string PairSuggFont = "";
                if (Alligned.size() > 0) PairSuggFont = print2OCRSugg(s1, Alligned[0], ConfPmap, Dict);
                if (PairSuggFont.size() > 0) mapSugg[PairSuggFont]++;

                string sugg9 = "";
                sugg9 = generatePossibilitesNsuggest(s1, TopConfusions, TopConfusionsMask, Dict, SRules);
                if (sugg9.size() > 0) mapSugg[sugg9]++;

                map<string, int> mapSugg1;
                for (size_t ksugg1 = 0; ksugg1 < 5; ksugg1++) {
                    if (Words.size() > ksugg1)  mapSugg1[toslp1(Words[ksugg1])]++;
                    if (Words1.size() > ksugg1) mapSugg1[toslp1(Words1[ksugg1])]++;
                    if (PWords1.size() > ksugg1) mapSugg1[toslp1(PWords1[ksugg1])]++;
                }


                for (map<string, int>::const_iterator eptr = mapSugg.begin(); eptr != mapSugg.end(); eptr++) {
                    vecSugg.push_back(make_pair(editDist(toslp1(eptr->first), toslp1(selectedStr)), eptr->first));
                }

                for (map<string, int>::const_iterator eptr = mapSugg1.begin(); eptr != mapSugg1.end(); eptr++) {
                    vecSugg1.push_back(make_pair(editDist(toslp1(eptr->first), toslp1(selectedStr)), eptr->first));
                }


                //vecSugg.push_back(make_pair(editDist(toslp1(selectedStr),selectedStr),selectedStr));
                //if(Words.size() > 0) vecSugg.push_back(make_pair(editDist(toslp1(selectedStr),toslp1(Words[0])),Words[0]));
                //vecSugg.push_back(make_pair(editDist(toslp1(selectedStr),toslp1(Words1[0])),Words1[0]));
                //vecSugg.push_back(make_pair(editDist(toslp1(selectedStr),toslp1(PairSugg)),PairSugg));
                sort(vecSugg.begin(), vecSugg.end()); sort(vecSugg1.begin(), vecSugg1.end());
                //cout << vec[0]  << " " << vec[1]  << " " << vec[2]  << " " << newtrie.next.size() << endl;
                //Words = suggestions((selectedStr));
                for (uint bitarrayi = 0; bitarrayi < vecSugg.size(); bitarrayi++) {
                    act = new QAction(QString::fromStdString(toDev(vecSugg[bitarrayi].second)), spell_menu);
                    //cout<<vecSugg[bitarrayi].first<<endl;
                    spell_menu->addAction(act);
                }

                for (uint bitarrayi = 0; bitarrayi < vecSugg1.size(); bitarrayi++) {
                    if (mapSugg[vecSugg1[bitarrayi].second] < 1) {
                        act = new QAction(QString::fromStdString(toDev(vecSugg1[bitarrayi].second)), spell_menu);
                        //cout<<vecSugg1[bitarrayi].first<<endl;
                        spell_menu->addAction(act);
                    }
                }
                /*Words =  print5NearestEntries(TDict,selectedStr);
                if (Words.size() > 0) {
                    act = new QAction(QString::fromStdString(toDev(Words[0])), spell_menu);

                    spell_menu->addAction(act);

                }*/

                popup_menu->insertSeparator(popup_menu->actions()[0]);
                popup_menu->insertMenu(popup_menu->actions()[0], spell_menu);
                connect(spell_menu, SIGNAL(triggered(QAction*)), this, SLOT(menuSelection(QAction*)));
                popup_menu->exec(ev->globalPos());
                popup_menu->close(); popup_menu->clear();
                //curr_browser->createStandardContextMenu()->clear();
                //cursor.select(QTextCursor::WordUnderCursor);
                vecSugg.clear(); Words1.clear(); Words.clear(); Alligned.clear(); PairSugg.clear();
            }
            else {

                DisplayTimeLog();

                QMenu* popup_menu = curr_browser->createStandardContextMenu();
                popup_menu->exec(ev->globalPos());
                popup_menu->close(); popup_menu->clear();
            }
        } // if right click
    }
}// if mouse event

/*
QString strPrev = "";
void MainWindow::textChangedSlot(){
		QTextCursor cursor = curr_browser->textCursor();
		cursor.select(QTextCursor::WordUnderCursor);
		// code to copy selected string:-
		QString strPrev1 = cursor.selectedText();
		if( editDist(toslp1(strPrev1.toUtf8().constData()),toslp1(strPrev.toUtf8().constData())) > 0) {
		strPrev = cursor.selectedText();
		QString text = strPrev;
		QMessageBox* box = new QMessageBox();
		box->setWindowTitle(QString("Hello"));
		box->setText(QString("Current Text:\""+text+"\""));
		box->show();
		}
}
*/

void MainWindow::menuSelection(QAction* action)
{
    if (curr_browser) {
        QTextCursor cursor = curr_browser->textCursor();
        cursor.select(QTextCursor::WordUnderCursor);
        cursor.beginEditBlock();
        cursor.removeSelectedText();

        //cursor.insertHtml("</body></html><font color=\'purple\'>" + action->text() + "</font><html><body>");

        string target = (action->text().toUtf8().constData());
        CPair[toslp1(selectedStr)] = toslp1(target);
        PWords[toslp1(target)]++; //CPairRight[toslp1(target)]++;
        cursor.insertText(action->text());
        //cout <<target << CPair.size() << " "<< GBook.size() << " " << IBook.size() << endl;
        //on_actionSpell_Check_triggered();
        //cout << selectedStr << " to " << target << " " << CPair[toslp1(selectedStr)] <<" " << IBook[toslp1(selectedStr)] + 1 << "Corrections made"<< endl;

        // replace words with name same as selectedStr and are underlined
        // underlined:-
        //strHtml += "<a href='xxx'>";
        //strHtml += word;
        //strHtml += "</a>";

        //QTextDocument *doc=curr_browser->document();
        //QString html=doc->toHtml();
        //string html0=html.toUtf8().constData();

        //cout<<selectedStr<<endl;
        cursor.endEditBlock();

        /*
        QString textBrowserText = curr_browser->toPlainText();
        string alltext=(textBrowserText.toUtf8().constData()); //toslp1
        istringstream ss(alltext);
        string word="";
        //int len = alltext.length(),a=0;
        int noCorr = 0;
        ss >> word;
        cursor.setPosition(0,QTextCursor::MoveAnchor);
        size_t cnt = 1;
        while( ss >> word) cnt++;
        for(size_t c1 = 0; c1 < cnt + 10; c1++){ cursor.movePosition(QTextCursor::NextWord, QTextCursor::KeepAnchor);
            cursor.select(QTextCursor::WordUnderCursor);
            QString str1 = cursor.selectedText();
            word = str1.toUtf8().constData();
            if(word==(selectedStr)){
            //cursor.movePosition(QTextCursor::NextWord, QTextCursor::KeepAnchor);
            //cursor.select(QTextCursor::WordUnderCursor);
            cursor.beginEditBlock();
            cursor.removeSelectedText();
            cursor.insertHtml("</body></html><font color=\'purple\'>" + action->text() + "</font><html><body>");
            noCorr++;
            cursor.endEditBlock();
            }
            }
        cout << "noCOrr made on this Page " << noCorr << endl;
        */
        /*
        while(a<len)
        {
            if(alltext[a]==' ')
            {
                if(word==toslp1(selectedStr))
                {   cursor.setPosition(a-1,QTextCursor::MoveAnchor);
                    cursor.setPosition(a-1,QTextCursor::MoveAnchor);
                    cursor.select(QTextCursor::WordUnderCursor);
                    cursor.beginEditBlock();
                    cursor.removeSelectedText();
                    cursor.insertHtml("</body></html><font color=\'purple\'>" + action->text() + "</font><html><body>");
                    noCorr++;
                    cursor.endEditBlock();
                }
                word="";
            }
            else
                word+=alltext[a];
            a++;
        }*/


        // write code to pick word one by one in string word
    /*
        // code to search for a string in another string
        // say word has 1st word from Text Browzer
        int pos = word.find("</a>", 0);
        if(pos != static_cast<int>(string::npos)){
            // then delete extra things that underline the word
            //if this remaining string matches selectedStr(rohlt) replace it with action->text()
                //action->text() might be Qstring
                alltextnew + = action->text();// convert this Qstring to string it has rohit
            else  alltextnew + = word;
        }else alltextnew + = word;
        */
        //qDebug() << "Triggered: " << action->text();
    }
}

void MainWindow::on_actionNew_triggered()
{
    QTextBrowser * b = new QTextBrowser(this);
    b->setReadOnly(false);
    b->setUndoRedoEnabled(true);
    if (ui->tabWidget_2->count() != 0) {
        for (int i = 0; i < ui->tabWidget_2->count(); i++) {
            if ("Untitled" == ui->tabWidget_2->tabText(i)) {
                ui->tabWidget_2->setCurrentIndex(i);
            }
        }
    }
    currentTabIndex = ui->tabWidget_2->addTab(b, "Untitled");
    ui->tabWidget_2->setCurrentIndex(currentTabIndex);
}

void MainWindow::on_actionSave_triggered()
{
    SaveTimeLog();
    DisplayTimeLog();

    if(isVerifier) {
        gSaveTriggered = 1;
        on_viewComments_clicked();
        gSaveTriggered = 0;
        updateAverageAccuracies();    
    }
    ConvertSlpDevFlag =1;

    //on_actionSpell_Check_triggered();

    if (mFilename=="Untitled"){
        on_actionSave_As_triggered();
    } else {

        QString tempPageName = gCurrentPageName;
//        if(gCurrentDirName == "Inds")
//        {
//            tempPageName = "V1_" + gCurrentPageName;
//        }
//        if(gCurrentDirName == "VerifierOutput")
//        {
//            tempPageName.replace("V2_","V3_");
//            tempPageName.replace("V1_","V2_");
//        }
        QString changefiledir = filestructure_fw[gCurrentDirName];
        QString localFilename = gDirTwoLevelUp + "/" +changefiledir +"/" + tempPageName;
        QString localFilename2 = gDirTwoLevelUp + "/" +changefiledir +"/" + tempPageName;
        localFilename.replace(".txt",".html");
        localFilename2.replace(".txt",".json");


        QFile sFile(localFilename);
        //if(sFile.open(QFile::WriteOnly | QFile::Text))
        QString output = curr_browser->toHtml();
        if(sFile.open(QFile::WriteOnly))
        {
            QTextStream out(&sFile);
            out.setCodec("UTF-8");
//            QString output = curr_browser->toHtml();
            gInitialTextHtml[currentTabPageName] = output;
            output = "<style> body{ width: 21cm; height: 29.7cm; margin: 30mm 45mm 30mm 45mm; } </style>" + output;
            out << output;
            sFile.flush();
            sFile.close();
        }

        //for JSON output of html document
        QTextDocumentFragment qtextdocfragment;
        QString plain = qtextdocfragment.fromHtml(output).toPlainText();

        std::stringstream ss(plain.toStdString());
        std::string to;

        QVector<QString> s;
          if (plain != NULL)
          {
            while(std::getline(ss,to,'\n')){
                QString qstr = QString::fromStdString(to);
                s.append(qstr);

            }
          }
        QJsonObject qjsonobj;
        for(int i = 0;i < s.size(); i++){
            QString z = QString::number(i);
            qjsonobj.insert(z, QJsonValue(s[i]));
        }
        int len = qjsonobj.length();

//         QJsonDocument doc(qjsonobj);
        QFile sFile2(localFilename2);
        if(sFile2.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&sFile2);
			out.setCodec("UTF-8");
            out << "{\n";
            for(int x = 0; x<len; x++){
                QString z = QString::number(x);
                out << "\"" << x << "\"" << ":" << "\"" << qjsonobj[z].toString() << "\"" <<","<< '\n';
            }
            out << "}";
//            QTextStream out(&sFile2);
//            out << doc.toJson(QJsonDocument::Compact);
		    sFile2.flush();
            sFile2.close();
        }
    }
    ConvertSlpDevFlag =0;
    //on_actionSpell_Check_triggered();

}

void MainWindow::on_actionLoadGDocPage_triggered()
{
	if (mFilename == "Untitled") {
		
	}
	else {
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
		//qDebug() << str1 << endl;
		loadMap(str1.toUtf8().constData(), PWords, "PWords");

		map<string, int> PWordspage;
		loadMap(str1.toUtf8().constData(), PWordspage, "PWordspage");
		loadmaptoTrie(TPWords, PWordspage);
		vector<string> wrong, right;
		QString str2 = mFilename;
		generateCorrectionPairs(wrong, right, str2.toUtf8().constData(), str1.toUtf8().constData());
		loadConfusionsFont(wrong, right, ConfPmapFont);
		loadConfusionsFont(wrong, right, ConfPmap);
		TopConfusions.clear(); TopConfusionsMask.clear();
		loadTopConfusions(ConfPmap, TopConfusions, TopConfusionsMask);
	}

}


void MainWindow::on_actionSave_As_triggered()
{
	QString file(QFileDialog::getSaveFileName(this, "Open a File"));
	if (!file.isEmpty())
	{
		mFilename = file;
		UpdateFileBrekadown();
		on_actionSave_triggered();
	}

}

void MainWindow::on_actionToDevanagari_triggered()
{
    if(!curr_browser)
            return;
     QTextCursor cursor = curr_browser->textCursor();

//    int EndPos = 0;
//    QString document = curr_browser->toPlainText();
//    QTextCursor tempCursor = cursor;
//    int tempCursorPos = tempCursor.position();

    if(!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);

//    if(!cursor.hasSelection()) {
//        while((--tempCursorPos)>0) {
//            if(document[tempCursorPos] == " "){
//                break;
//            }
//        }
//        if(tempCursorPos>-1) {
//            EndPos = document.indexOf(" ", tempCursorPos + 1);
//            if(EndPos == -1 )
//                EndPos = document.length();
//            cursor.setPosition(tempCursorPos, QTextCursor::MoveAnchor);
//            cursor.setPosition(EndPos, QTextCursor::KeepAnchor);
//        }
//     }

    QString str1 = cursor.selectedText();
    selectedStr = str1.toUtf8().constData();
    cursor.beginEditBlock();
    cursor.removeSelectedText();
    cursor.insertText(QString::fromStdString(toDev(toslp1(selectedStr))));
    cursor.endEditBlock();

}

bool LoadDataFlag = 1; //To load data only once
QString mFilename1, loadStr, loadStr1;
void MainWindow::on_actionLoadData_triggered()
{
    if (mProject.isProjectOpen()) {
        if (LoadDataFlag) {
            QString initialText = ui->lineEdit->text();
            ui->lineEdit->setText("Loading Data...");
            QString  localmFilename1 = mFilename;
            string localmFilename1n = localmFilename1.toUtf8().constData();
            localmFilename1n = localmFilename1n.substr(0, localmFilename1n.find("page"));
            localmFilename1 = QString::fromStdString(localmFilename1n);
            on_actionLoadDict_triggered();
            loadStr += "\n";

            on_actionLoadOCRWords_triggered();
            on_actionLoadDomain_triggered();
            on_actionLoadSubPS_triggered();
            on_actionLoadConfusions_triggered();

            ui->lineEdit->setText(initialText);
            LoadDataFlag = 0;
            QMessageBox messageBox;
            messageBox.information(0, "Load Data", "Data has been loaded.");
        }
    }
}

bool loadDict(Project & project) {
    QString localmFilename1 = project.GetDir().absolutePath() + "/Dicts/" + "Dict";
    if (!QFile::exists(localmFilename1)) return false;
    loadMap(localmFilename1.toUtf8().constData(), Dict, "Dict");
    return true;
}
void MainWindow::on_actionLoadDict_triggered()
{
    loadDict(mProject);
}

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

void MainWindow::on_actionLoadDomain_triggered()
{
    QString localmFilename1 = mProject.GetDir().absolutePath() + "/Dicts/" + "/PWords";
    loadMapPWords(vGBook, vIBook, PWords);
}

map<string, string> LSTM;
void MainWindow::on_actionLoadSubPS_triggered()
{
    //    QString localmFilename1 = mFilename1;
    size_t count = loadPWordsPatternstoTrie(TPWordsP, PWords);// justsubstrings not patterns exactly // PWordsP,
//    localmFilename1.replace("Inds/","CPair");
    QString localmFilename1 = mProject.GetDir().absolutePath() + "/Dicts/" + "CPair";
    loadCPair(localmFilename1.toUtf8().constData(), CPair, Dict, PWords); localmFilename1 = mFilename1;

    //localmFilename1.replace("Inds/","LSTM");
    localmFilename1 = mProject.GetDir().absolutePath() + "/Dicts/" + "LSTM";
    ifstream myfile(localmFilename1.toUtf8().constData());
    if (myfile.is_open())
    {
        string str1, str2, line;
        while (getline(myfile, line)) {
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



void MainWindow::on_actionLoadConfusions_triggered()
{

    QString localmFilename1 = mProject.GetDir().absolutePath() + "/Dicts/" + "CPair";
    loadConfusions(localmFilename1.toUtf8().constData(), ConfPmap); localmFilename1 = mFilename;


}


/*
class MyTimer : public QObject
{
    Q_OBJECT
public :
    MyTimer(){
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(MySlot()));
        timer->start(1000);
    }

    QTimer *timer;

public slots:
    void MySlot(){
    secs++;
    ui->lineEdit->settext(stoi(secs) + " secs passed");
    }
};*/

void MainWindow::on_actionSugg_triggered()
{
    RightclickFlag = 1;
    QMouseEvent *ev1;
    //ev1->button() = Qt::RightButton; ->RightButton;
    mousePressEvent(ev1);
    RightclickFlag = 0;

}



void MainWindow::on_actionToSlp1_triggered()
{

    int nMilliseconds = myTimer.elapsed();
    secs = nMilliseconds / 1000;
    int mins = secs / 60;
    secs = secs - mins * 60;
    //ui->lineEdit->setText(QString::number(mins) + "mins " + QString::number(secs) + " secs elapsed on this page(Right Click to update)");
    QTextCursor cursor = curr_browser->textCursor();
    //cursor.select(QTextCursor::WordUnderCursor);
    QString str1 = cursor.selectedText();
    selectedStr = str1.toUtf8().constData();
    cursor.beginEditBlock();
    cursor.removeSelectedText();
    cursor.insertText(QString::fromStdString((toslp1(selectedStr))));
    cursor.endEditBlock();

}

void MainWindow::on_actionCreateSuggestionLog_triggered()
{
    map<size_t, size_t> mapCorrect, mapinCorrect, mapTyping, mapSugg1, mapSugg2, mapSugg3, mapSugg4, mapSugg5, mapSugg6, mapSugg7, mapSugg8, mapSugg9, mapSugg10;

    // Load foders in strC and strI
//	QString strI = mFilename;
//	QString strC = strI;
//	strI.replace("CorrectorOutput", "Inds"); strC.replace("Inds", "CorrectorOutput");
        QString strI = gDirTwoLevelUp + "/Inds/"+ gCurrentPageName ;
        strI.replace(".html",".txt");
        QString strC = gDirTwoLevelUp + "/CorrectorOutput/"+ gCurrentPageName ;

        // load text files one by one

        //Load page1 of Inds
    size_t page_no = 1;
    QString filereport;

    while (1) {

        string nos = "0123456789";
        string localFilenameI = strI.toUtf8().constData();
        size_t loc = localFilenameI.find(".txt");
        string s = localFilenameI.substr(loc - 1, 1); // page-123.txt s = 3
        string no;

        vector<string> wrong, right;
        while (nos.find(s) != string::npos) { no = s + no; loc--; s = localFilenameI.substr(loc - 1, 1); } // if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
        //cout << stoi(no) + 1 << endl;
        localFilenameI.replace(loc, no.size(), to_string(page_no));//to_string(stoi(no) + 1)
        //cout << localFilename << endl;
        //QString fileI = QString::fromStdString(localFilenameI);

        //Load page1 of C

        string localFilenameC = strC.toUtf8().constData();
        loc = localFilenameC.find(".txt");
        s = localFilenameC.substr(loc - 1, 1); // page-123.txt s = 3
        no = "";
        while (nos.find(s) != string::npos) { no = s + no; loc--; s = localFilenameC.substr(loc - 1, 1); } // if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
        //cout << stoi(no) + 1 << endl;
        localFilenameC.replace(loc, no.size(), to_string(page_no));//to_string(stoi(no) + 1)
        //cout << localFilename << endl;
       // QString fileC = QString::fromStdString(localFilenameC);

        // NOW localFilenameI and localFilenameC has page1 of both
        //cout << localFilenameI << " " << localFilenameC << endl;
        // load fileI in vecpI and
        vector<string> vecpI, vecpC;
        map<string, bool> isAscii;
        std::ifstream sIpage(localFilenameI);
        if (!(sIpage.is_open())) break; // break the while loop for page_no
        string localstr;
        while (sIpage >> localstr) vecpI.push_back(toslp1(localstr)); sIpage.close();
        std::ifstream sCpage(localFilenameC);
        while (sCpage >> localstr) { if (hasM40PerAsci(localstr)) { isAscii[toslp1(localstr)] = 1; }  vecpC.push_back(toslp1(localstr)); } sIpage.close();

        // if 1st word is wrong generate suggestions
        int vGsz = vecpC.size(), vIsz = vecpI.size();
        if (vGsz > vIsz) mapTyping[page_no] = vGsz - vIsz;
        //cout << vGsz << " " << vIsz << endl;
        int win = vGsz - vIsz;
        if (win < 0) win = -1 * win;
        win = std::max(win, 5);
        //cout << win << endl;
        //float WER = 0;
        // search for a word(pre space, post space as well) in Indsenz within win sized window in GDocs and if found then add to PWords
        for (int t = 0; t < vIsz; t++) {
            size_t minedit = 1000;
            string s1 = vecpI[t]; //(vGBook[t1].find(s1) != string::npos) || (vGBook[t1] == s1)
            string sC;
            for (int t1 = std::max(t - win, 0); t1 < min(t + win, vGsz); t1++) {
                string sCt1 = vecpC[t1];
                size_t mineditIC = editDist(s1, sCt1);
                if (mineditIC < minedit) { minedit = mineditIC; sC = sCt1; }
                if (sCt1 == s1) {/*WER++;*/ break; }
            }

            // now we have IndsWord in s1 and correct word in sC
            //cout << s1 << " " << s1.size() << " " << sC << " " << sC.size()<< endl;
            if ((sC == (s1))) {
                mapCorrect[page_no]++; //cout<< " in correct words ke liye if" << endl;
            }
            else if (!isAscii[sC]) {
                wrong.push_back(s1); right.push_back(sC);
                //cout<< " inside incorrect words ke liye else" << endl;
                vector<string>  Words1 = print5NearestEntries(TGBook, s1); //2
                if (Words1.size() == 0) Words1.push_back("");
                string nearestCOnfconfirmingSuggvec; //1
                vector<string> vec = Words1;
                int min = 100;
                for (size_t t = 0; t < vec.size(); t++) {
                    vector<string> wordConfusions; vector<int> wCindex;
                    int minFactor = loadWConfusionsNindex1(s1, vec[t], ConfPmap, wordConfusions, wCindex);
                    wordConfusions.clear(); wCindex.clear();
                    if (minFactor < min) { min = minFactor; nearestCOnfconfirmingSuggvec = vec[t]; }
                }
                //cout << "sz" << Words1.size() << " "<< Words1[0]<< endl;
                if (nearestCOnfconfirmingSuggvec == (sC)) { mapSugg1[page_no]++; }
                /*else*/ if ((Words1[0] == (sC))) { mapSugg2[page_no]++; }
                /*else*/ {

                    vector<string> Alligned = print5NearestEntries(TGBookP, s1); //6
                    if (Alligned.size() == 0) Alligned.push_back("");

                    string PairSugg = "";
                    if (Alligned.size() > 0) PairSugg = print2OCRSugg(s1, Alligned[0], ConfPmap, Dict);//3
                    //cout << sC << "PairSugg " << PairSugg<<endl;
                    if (PairSugg == sC) { mapSugg3[page_no]++; }
                    /*else*/ { vector<string>  Words = print1OCRNearestEntries(toslp1(s1), vIBook); // 4 primary doc based
                    if (Words.size() == 0) Words.push_back("");
                    if (Words[0] == (sC)) { mapSugg4[page_no]++; }
                    /*else*/ { string samassugg = SamasBreakLRCorrect(toslp1(s1), Dict, PWords, TPWords, TPWordsP); // 5
                    if (samassugg == sC) { mapSugg5[page_no]++; }
                    /*else*/ {
                        vector<string> PWords1 = print5NearestEntries(TPWords, s1); // 6
                        if (PWords1.size() == 0) PWords1.push_back("");
                        if (PWords1[0] == (sC)) { mapSugg6[page_no]++; }
                        /*else*/ {string nearestCOnfconfirmingSuggvecFont;
                        int min = 100;
                        for (size_t t = 0; t < vec.size(); t++) {
                            vector<string> wordConfusions; vector<int> wCindex;
                            int minFactor = loadWConfusionsNindex1(s1, vec[t], ConfPmapFont, wordConfusions, wCindex);
                            wordConfusions.clear(); wCindex.clear();
                            if (minFactor < min) { min = minFactor; nearestCOnfconfirmingSuggvecFont = vec[t]; }
                        }
                        if (nearestCOnfconfirmingSuggvecFont == sC) { mapSugg7[page_no]++; }
                        /*else*/ {
                            /*string PairSuggFont = "";
                            if(Alligned.size() > 0) PairSuggFont = print2OCRSugg(s1, Alligned[0], ConfPmap,Dict);//3
                            //cout << sC << "PairSugg " << PairSugg<<endl;
                            if(PairSuggFont == sC) {  mapSugg8[page_no]++;}*/
                            vector<string> Wordsdict; {Wordsdict = print5NearestEntries(TDict, s1); }
                            if ((Wordsdict.size() > 0) && (Wordsdict[0] == sC)) { mapSugg8[page_no]++; }
                            /*else*/ {
                                string sugg9 = generatePossibilitesNsuggest(s1, TopConfusions, TopConfusionsMask, Dict, SRules);
                                if (sugg9 == sC) {
                                    mapSugg9[page_no]++;
                                    //cout << s1 << " "<<sC << endl;
                                }
                                /*else*/ { if (LSTM[s1] == sC) {
                                    mapSugg10[page_no]++;
                                    cout << s1 << " lstm " << sC << endl;
                                }
                                else mapTyping[page_no]++; }
                            }
                        }
                        }
                    }
                    }
                    }

                }

            }
            else { mapTyping[page_no]++; } // else
     //cout << mapCorrect[1]<< " " << mapTyping[1]<< " " <<mapSugg1[1]<< " " <<mapSugg2[1]<< " " <<mapSugg3[1]<< " " <<mapSugg4[1]<< " " <<mapSugg5[1]<< " " <<mapSugg6[1]<<endl;
     //cout << "here" << endl;
        }// for 1st page ends
        mapinCorrect[page_no] = vIsz - mapCorrect[page_no];
        //Loading PWords:-
        cout << "page_no = " << page_no << endl;
        loadMap(localFilenameC, PWords, "PWords");
        map<string, int> PWordspage;
        loadMap(localFilenameC, PWordspage, "PWordspage");
        loadmaptoTrie(TPWords, PWordspage);
        //generateCorrectionPairs(wrong,right,str2.toUtf8().constData(), str1.toUtf8().constData());
        loadConfusionsFont(wrong, right, ConfPmap);
        loadConfusionsFont(wrong, right, ConfPmapFont);
        TopConfusions.clear(); TopConfusionsMask.clear();
        loadTopConfusions(ConfPmap, TopConfusions, TopConfusionsMask);



        //cout << mapCorrect[page_no]<< " " << mapTyping[page_no]<< " " <<mapSugg1[page_no]<< " " <<mapSugg2[page_no]<< " " <<mapSugg3[page_no]<< " " <<mapSugg4[page_no]<< " " <<mapSugg5[page_no]<< " " <<mapSugg6[page_no]<<endl;
        //cout << vIsz - WER << endl;
        //ui->lineEdit->setText("Page WER = " + QString::number((vIsz-WER)*100/vIsz));
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


/*
 // 3 map<string,int>&

//cout <<" here " << toDev(Words[0]) << endl;


// find nearest confirming to OCR Sugg from 2ndary Book //1


// find nearest confirming to OCR Sugg from PWords
string nearestCOnfconfirmingSuggvec1;
    vector<string> vec1 = PWords1;
    min= 100;
        for (size_t t=0;t<vec1.size();t++){
        vector<string> wordConfusions; vector<int> wCindex;
        int minFactor = loadWConfusionsNindex1(selectedStr,vec1[t],ConfPmap,wordConfusions,wCindex);
        wordConfusions.clear(); wCindex.clear();
        if(minFactor < min) {min = minFactor; nearestCOnfconfirmingSuggvec1 = vec1[t];}
        }

vector<pair<int,string>> vecSugg,vecSugg1;
map<string, int> mapSugg;
string CSugg = CPair[toslp1(selectedStr)];
if(CSugg.size() > 0) mapSugg[toslp1(CSugg)]++;
if(Words.size() > 0)  mapSugg[toslp1(Words[0])]++;
if(Words1.size() > 0) mapSugg[toslp1(nearestCOnfconfirmingSuggvec)]++;
if(PWords1.size() > 0) mapSugg[toslp1(nearestCOnfconfirmingSuggvec1)]++;
if(PairSugg.size() > 0) mapSugg[toslp1(PairSugg)]++;



map<string, int> mapSugg1;
for(size_t ksugg1 = 0; ksugg1 < 5; ksugg1++) {
if(Words.size() > ksugg1)  mapSugg1[toslp1(Words[ksugg1])]++;
if(Words1.size() > ksugg1) mapSugg1[toslp1(Words1[ksugg1])]++;
if(PWords1.size() > ksugg1) mapSugg1[toslp1(PWords1[ksugg1])]++;
}


for( map<string,int>::const_iterator eptr=mapSugg.begin(); eptr!=mapSugg.end(); eptr++){
    vecSugg.push_back(make_pair(editDist(toslp1(eptr->first),toslp1(selectedStr)),eptr->first));
}

for( map<string,int>::const_iterator eptr=mapSugg1.begin(); eptr!=mapSugg1.end(); eptr++){
    vecSugg1.push_back(make_pair(editDist(toslp1(eptr->first),toslp1(selectedStr)),eptr->first));
}


//vecSugg.push_back(make_pair(editDist(toslp1(selectedStr),selectedStr),selectedStr));
//if(Words.size() > 0) vecSugg.push_back(make_pair(editDist(toslp1(selectedStr),toslp1(Words[0])),Words[0]));
//vecSugg.push_back(make_pair(editDist(toslp1(selectedStr),toslp1(Words1[0])),Words1[0]));
//vecSugg.push_back(make_pair(editDist(toslp1(selectedStr),toslp1(PairSugg)),PairSugg));
sort(vecSugg.begin(), vecSugg.end()); sort(vecSugg1.begin(), vecSugg1.end());
//cout << vec[0]  << " " << vec[1]  << " " << vec[2]  << " " << newtrie.next.size() << endl;
//Words = suggestions((selectedStr));
for ( uint bitarrayi = 0; bitarrayi < vecSugg.size(); bitarrayi++) {
    act = new QAction( QString::fromStdString(toDev(vecSugg[bitarrayi].second)) , spell_menu);
    //cout<<vecSugg[bitarrayi].first<<endl;
    spell_menu->addAction(act);
    }

for ( uint bitarrayi = 0; bitarrayi < vecSugg1.size(); bitarrayi++) {
    if(mapSugg[vecSugg1[bitarrayi].second] < 1){
    act = new QAction(QString::fromStdString(toDev(vecSugg1[bitarrayi].second)), spell_menu);
    //cout<<vecSugg1[bitarrayi].first<<endl;
    spell_menu->addAction(act);
    }
    }
*/


void MainWindow::on_actionCreateSuggestionLogNearestPriority_triggered()
{
    map<size_t, size_t> mapCorrect, mapinCorrect, mapTyping, mapSugg1, mapSugg2, mapSugg3, mapSugg4, mapSugg5, mapSugg6, mapSugg7, mapSugg8, mapSugg9, mapSugg10;

    // Load foders in strC and strI
//	QString strI = mFilename;
//	QString strC = strI;
//	strI.replace("CorrectorOutput", "Inds"); strC.replace("Inds", "CorrectorOutput");
        QString strI = gDirTwoLevelUp + "/Inds/"+ gCurrentPageName ;
        strI.replace(".html",".txt");
        QString strC = gDirTwoLevelUp + "/CorrectorOutput/"+ gCurrentPageName ;

    // load text files one by one

    //Load page1 of Inds
    size_t page_no = 1;
    QString filereport;

    while (1) {

        string nos = "0123456789";
        string localFilenameI = strI.toUtf8().constData();
        size_t loc = localFilenameI.find(".txt");
        if(loc == string::npos)
            loc = localFilenameI.find(".html");
        string s = localFilenameI.substr(loc - 1, 1); // page-123.txt s = 3
        string no;


        while (nos.find(s) != string::npos) { no = s + no; loc--; s = localFilenameI.substr(loc - 1, 1); } // if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
        //cout << stoi(no) + 1 << endl;
        localFilenameI.replace(loc, no.size(), to_string(page_no));//to_string(stoi(no) + 1)
        //cout << localFilename << endl;
        //QString fileI = QString::fromStdString(localFilenameI);

        //Load page1 of C

        string localFilenameC = strC.toUtf8().constData();
        loc = localFilenameC.find(".txt");
        if(loc == string::npos)
            loc = localFilenameC.find(".html");
        s = localFilenameC.substr(loc - 1, 1); // page-123.txt s = 3
        no = "";
        while (nos.find(s) != string::npos) { no = s + no; loc--; s = localFilenameC.substr(loc - 1, 1); } // if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
        //cout << stoi(no) + 1 << endl;
        localFilenameC.replace(loc, no.size(), to_string(page_no));//to_string(stoi(no) + 1)
        //cout << localFilename << endl;
       // QString fileC = QString::fromStdString(localFilenameC);

        // NOW localFilenameI and localFilenameC has page1 of both
        //cout << localFilenameI << " " << localFilenameC << endl;
        // load fileI in vecpI and
        vector<string> vecpI, vecpC;
        std::ifstream sIpage(localFilenameI);
        if (!(sIpage.is_open())) break; // break the while loop for page_no
        string localstr;
        while (sIpage >> localstr) vecpI.push_back(toslp1(localstr)); sIpage.close();
        std::ifstream sCpage(localFilenameC);
        while (sCpage >> localstr) vecpC.push_back(toslp1(localstr)); sIpage.close();

        // if 1st word is wrong generate suggestions
        int vGsz = vecpC.size(), vIsz = vecpI.size();
        if (vGsz > vIsz) mapTyping[page_no] = vGsz - vIsz;
        //cout << vGsz << " " << vIsz << endl;
        int win = vGsz - vIsz;
        if (win < 0) win = -1 * win;
        win = std::max(win, 5);
        //cout << win << endl;
        //float WER = 0;
        // search for a word(pre space, post space as well) in Indsenz within win sized window in GDocs and if found then add to PWords
        for (int t = 0; t < vIsz; t++) {
            size_t minedit = 1000;
            string s1 = vecpI[t]; //(vGBook[t1].find(s1) != string::npos) || (vGBook[t1] == s1)
            string sC;
            for (int t1 = std::max(t - win, 0); t1 < min(t + win, vGsz); t1++) {
                string sCt1 = vecpC[t1];
                size_t mineditIC = editDist(s1, sCt1);
                if (mineditIC < minedit) { minedit = mineditIC; sC = sCt1; }
                if (sCt1 == s1) {/*WER++;*/ break; }
            }
            // now we have IndsWord in s1 and correct word in sC
            //cout << s1 << " " << s1.size() << " " << sC << " " << sC.size()<< endl;
            if ((sC == (s1))) {
                mapCorrect[page_no]++; //cout<< " in correct words ke liye if" << endl;
            }
            else {
                vector<string>  Words1 = print5NearestEntries(TGBook, s1);
                vector<string> Alligned = print5NearestEntries(TGBookP, s1);
                vector<string> PWords1 = print5NearestEntries(TPWords, s1);
                string PairSugg = print2OCRSugg(s1, Alligned[0], ConfPmap, Dict); // map<string,int>&
                vector<string>  Words = print1OCRNearestEntries(toslp1(s1), vIBook);
                //cout <<" here " << toDev(Words[0]) << endl;


                // find nearest confirming to OCR Sugg from Book
                string nearestCOnfconfirmingSuggvec;
                vector<string> vec = Words1;
                int min = 100;
                for (size_t t = 0; t < vec.size(); t++) {
                    vector<string> wordConfusions; vector<int> wCindex;
                    int minFactor = loadWConfusionsNindex1(s1, vec[t], ConfPmap, wordConfusions, wCindex);
                    wordConfusions.clear(); wCindex.clear();
                    if (minFactor < min) { min = minFactor; nearestCOnfconfirmingSuggvec = vec[t]; }
                }

                // find nearest confirming to OCR Sugg from PWords
                string nearestCOnfconfirmingSuggvec1;
                vector<string> vec1 = PWords1;
                min = 100;
                for (size_t t = 0; t < vec1.size(); t++) {
                    vector<string> wordConfusions; vector<int> wCindex;
                    int minFactor = loadWConfusionsNindex1(s1, vec1[t], ConfPmap, wordConfusions, wCindex);
                    wordConfusions.clear(); wCindex.clear();
                    if (minFactor < min) { min = minFactor; nearestCOnfconfirmingSuggvec1 = vec1[t]; }
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
                for (size_t ksugg1 = 0; ksugg1 < 5; ksugg1++) {
                    if (Words.size() > ksugg1)  mapsugg1[toslp1(Words[ksugg1])]++;
                    if (Words1.size() > ksugg1) mapsugg1[toslp1(Words1[ksugg1])]++;
                    if (PWords1.size() > ksugg1) mapsugg1[toslp1(PWords1[ksugg1])]++;
                }


                for (map<string, int>::const_iterator eptr = mapSugg.begin(); eptr != mapSugg.end(); eptr++) {
                    vecSugg.push_back(make_pair(editDist(toslp1(eptr->first), toslp1(s1)), eptr->first));
                }

                for (map<string, int>::const_iterator eptr = mapsugg1.begin(); eptr != mapsugg1.end(); eptr++) {
                    vecSugg1.push_back(make_pair(editDist(toslp1(eptr->first), toslp1(s1)), eptr->first));
                }


                //vecSugg.push_back(make_pair(editDist(toslp1(s1),s1),s1));
                //if(Words.size() > 0) vecSugg.push_back(make_pair(editDist(toslp1(s1),toslp1(Words[0])),Words[0]));
                //vecSugg.push_back(make_pair(editDist(toslp1(s1),toslp1(Words1[0])),Words1[0]));
                //vecSugg.push_back(make_pair(editDist(toslp1(s1),toslp1(PairSugg)),PairSugg));
                sort(vecSugg.begin(), vecSugg.end()); sort(vecSugg1.begin(), vecSugg1.end());
                //cout << vec[0]  << " " << vec[1]  << " " << vec[2]  << " " << newtrie.next.size() << endl;
                //Words = suggestions((s1));
                vecSugg.insert(vecSugg.end(), vecSugg1.begin(), vecSugg1.end());

                if ((vecSugg.size() > 0) && (vecSugg[0].second == sC)) mapSugg1[page_no]++;
                else if ((vecSugg.size() > 1) && (vecSugg[1].second == sC)) mapSugg2[page_no]++;
                else if ((vecSugg.size() > 2) && (vecSugg[2].second == sC)) mapSugg3[page_no]++;
                else if ((vecSugg.size() > 3) && (vecSugg[3].second == sC)) mapSugg4[page_no]++;
                else if ((vecSugg.size() > 4) && (vecSugg[4].second == sC)) mapSugg5[page_no]++;
                else if ((vecSugg.size() > 5) && (vecSugg[5].second == sC)) mapSugg6[page_no]++;
                else mapTyping[page_no]++;

            }

            //cout << mapCorrect[1]<< " " << mapTyping[1]<< " " <<mapSugg1[1]<< " " <<mapSugg2[1]<< " " <<mapSugg3[1]<< " " <<mapSugg4[1]<< " " <<mapSugg5[1]<< " " <<mapSugg6[1]<<endl;
            //cout << "here" << endl;
        }// for 1st page ends
        mapinCorrect[page_no] = vGsz - mapCorrect[page_no];
        loadMap(localFilenameC, PWords, "PWords");
        map<string, int> PWordspage;
        loadMap(localFilenameC, PWordspage, "PWordspage");
        loadmaptoTrie(TPWords, PWordspage);
        //cout << mapCorrect[page_no]<< " " << mapTyping[page_no]<< " " <<mapSugg1[page_no]<< " " <<mapSugg2[page_no]<< " " <<mapSugg3[page_no]<< " " <<mapSugg4[page_no]<< " " <<mapSugg5[page_no]<< " " <<mapSugg6[page_no]<<endl;
        //cout << vIsz - WER << endl;
        //ui->lineEdit->setText("Page WER = " + QString::number((vIsz-WER)*100/vIsz));
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

void MainWindow::on_actionErrorDetectionRep_triggered()
{
    // Load foders in strC and strI
    QString strI = mFilename;
    QString strC = strI, strG = strI, strIF = strI, strCF = strI;
    strI.replace("CorrectorOutput", "Inds"); strC.replace("Inds", "CorrectorOutput");
    strG.replace("CorrectorOutput/page-1.txt", "GEROCR"); strG.replace("Inds/page-1.txt", "GEROCR");
    strIF.replace("CorrectorOutput/page-1.txt", "IEROCR"); strIF.replace("Inds/page-1.txt", "IEROCR");
    strCF.replace("CorrectorOutput/page-1.txt", "CorrectorOutput.txt"); strCF.replace("Inds/page-1.txt", "CorrectorOutput.txt");//Dict CorrectorOutput.txt for lower upper baseline resp
    // load text files one by one
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
    size_t iocrdone = 0;// will be used in each page of IEROCR
    map<string, int> mapCF;// F for Full Book
    loadMap(strCF.toUtf8().constData(), mapCF, "CorrectorOutput.txt");
    cout << mapCF.size() << endl;
    //Load page1 of Inds
    size_t page_no = 1;
    QString filereport;

    map<size_t, size_t> mapCorrect, mapInCorrect, mapCorrectMarkedCorrect, mapInCorrectMarkedCorrect;

    while (1) {

        string nos = "0123456789";
        string localFilenameI = strI.toUtf8().constData();
        size_t loc = localFilenameI.find(".txt");
        if(loc == string::npos)
            loc = localFilenameI.find(".html");
        string s = localFilenameI.substr(loc - 1, 1); // page-123.txt s = 3
        string no;

        while (nos.find(s) != string::npos) { no = s + no; loc--; s = localFilenameI.substr(loc - 1, 1); } // if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
        //cout << stoi(no) + 1 << endl;
        localFilenameI.replace(loc, no.size(), to_string(page_no));//to_string(stoi(no) + 1)
        //cout << localFilename << endl;
        //QString fileI = QString::fromStdString(localFilenameI);

        //Load page1 of C

        string localFilenameC = strC.toUtf8().constData();
        loc = localFilenameC.find(".txt");
        if(loc == string::npos)
            loc = localFilenameC.find(".html");
        s = localFilenameC.substr(loc - 1, 1); // page-123.txt s = 3
        no = "";
        while (nos.find(s) != string::npos) { no = s + no; loc--; s = localFilenameC.substr(loc - 1, 1); } // if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
        //cout << stoi(no) + 1 << endl;
        localFilenameC.replace(loc, no.size(), to_string(page_no));//to_string(stoi(no) + 1)
        //cout << localFilename << endl;
       // QString fileC = QString::fromStdString(localFilenameC);

        // NOW localFilenameI and localFilenameC has page1 of both
        //cout << localFilenameI << " " << localFilenameC << endl;
        // load fileI in vecpI and
        vector<string> vecpI, vecpC;
        std::ifstream sIpage(localFilenameI);
        if (!(sIpage.is_open())) break; // break the while loop for page_no
        string localstr;
        while (sIpage >> localstr) vecpI.push_back(toslp1(localstr)); sIpage.close();
        std::ifstream sCpage(localFilenameC);
        while (sCpage >> localstr) vecpC.push_back(toslp1(localstr)); sIpage.close();

        // if 1st word is correct and detected correct mark 1 else mark 0
        int vGsz = vecpC.size(), vIsz = vecpI.size();
        int win = vGsz - vIsz;
        if (win < 0) win = -1 * win;
        win = std::max(win, 5);

        // search for a word(pre space, post space as well) in Indsenz within win sized window in GDocs and if found then add to PWords
        for (int t = 0; t < vIsz; t++) {
            size_t minedit = 1000;
            string s1 = vecpI[t]; //(vGBook[t1].find(s1) != string::npos) || (vGBook[t1] == s1)
            string sC;
            for (int t1 = std::max(t - win, 0); t1 < min(t + win, vGsz); t1++) {
                string sCt1 = vecpC[t1];
                size_t mineditIC = editDist(s1, sCt1);
                if (mineditIC < minedit) { minedit = mineditIC; sC = sCt1; }
                if (sCt1 == s1) {/*WER++;*/ break; }
            }
            // now we have IndsWord in s1 and correct word in sC

            if ((sC == (s1))) {
                mapCorrect[page_no]++;
                if (searchS1inGVec(s1, iocrdone, gocr, winig)) mapCorrectMarkedCorrect[page_no]++;
            }
            else { mapInCorrect[page_no]++;  if (searchS1inGVec(s1, iocrdone, gocr, winig)) mapInCorrectMarkedCorrect[page_no]++; }  //(GBook[s1] >0) ||
            iocrdone++; //(PWords[s1] >0) searchS1inGVec(s1,iocrdone,gocr,winig) mapCF[s1]>0|| Dict[s1]>0
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

void MainWindow::on_actionErrorDetectWithoutAdaptation_triggered()
{
    // Load foders in strC and strI
    QString strI = mFilename;
    QString strC = strI;
    strI.replace("CorrectorOutput", "Inds"); strC.replace("Inds", "CorrectorOutput");

    // load text files one by one

    //Load page1 of Inds
    size_t page_no = 1;
    QString filereport;
    map<size_t, size_t> mapCorrect, mapInCorrect, mapCorrectMarkedCorrect, mapInCorrectMarkedCorrect;
    while (1) {

        string nos = "0123456789";
        string localFilenameI = strI.toUtf8().constData();
        size_t loc = localFilenameI.find(".txt");
        if(loc == string::npos)
            loc = localFilenameI.find(".html");
        string s = localFilenameI.substr(loc - 1, 1);
        string no;
        while (nos.find(s) != string::npos) { no = s + no; loc--; s = localFilenameI.substr(loc - 1, 1); } // if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
        localFilenameI.replace(loc, no.size(), to_string(page_no));
        //Load page1 of C
        string localFilenameC = strC.toUtf8().constData();
        loc = localFilenameC.find(".txt");
        if(loc == string::npos)
            loc = localFilenameC.find(".html");
        s = localFilenameC.substr(loc - 1, 1); // page-123.txt s = 3
        no = "";
        while (nos.find(s) != string::npos) { no = s + no; loc--; s = localFilenameC.substr(loc - 1, 1); } // if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
        localFilenameC.replace(loc, no.size(), to_string(page_no));
        // NOW localFilenameI and localFilenameC has page1 of both
        // load fileI in vecpI and
        vector<string> vecpI, vecpC;
        std::ifstream sIpage(localFilenameI);
        if (!(sIpage.is_open())) break; // break the while loop for page_no
        string localstr;
        while (sIpage >> localstr) vecpI.push_back(toslp1(localstr)); sIpage.close();
        std::ifstream sCpage(localFilenameC);
        while (sCpage >> localstr) vecpC.push_back(toslp1(localstr)); sIpage.close();
        // if 1st word is correct and detected correct mark 1 else mark 0
        int vGsz = vecpC.size(), vIsz = vecpI.size();
        int win = vGsz - vIsz;
        if (win < 0) win = -1 * win;
        win = std::max(win, 5);
        // search for a word(pre space, post space as well) in Indsenz within win sized window in GDocs and if found then add to PWords
        for (int t = 0; t < vIsz; t++) {
            size_t minedit = 1000;
            string s1 = vecpI[t]; //(vGBook[t1].find(s1) != string::npos) || (vGBook[t1] == s1)
            string sC;
            for (int t1 = std::max(t - win, 0); t1 < min(t + win, vGsz); t1++) {
                string sCt1 = vecpC[t1];
                size_t mineditIC = editDist(s1, sCt1);
                if (mineditIC < minedit) { minedit = mineditIC; sC = sCt1; }
                if (sCt1 == s1) {/*WER++;*/ break; }
            }
            // now we have IndsWord in s1 and correct word in sC
            //cout << s1 << " " << s1.size() << " " << sC << " " << sC.size()<< endl;
            if ((sC == (s1))) {
                mapCorrect[page_no]++;
                if ((GBook[s1] > 0) || (PWords[s1] > 0)) mapCorrectMarkedCorrect[page_no]++;
            }
            else { mapInCorrect[page_no]++; if ((GBook[s1] > 0) || (PWords[s1] > 0)) mapInCorrectMarkedCorrect[page_no]++; }
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
    while (1) {
        cout << page_no << endl;
        string nos = "0123456789";
        string localFilenameI = strI.toUtf8().constData();
        size_t loc = localFilenameI.find(".txt");
        if(loc == string::npos)
            loc = localFilenameI.find(".html");
        string s = localFilenameI.substr(loc - 1, 1);
        string no;
        while (nos.find(s) != string::npos) {
            no = s + no; loc--; s = localFilenameI.substr(loc - 1, 1);
            localFilenameI.replace(loc, no.size(), to_string(page_no));
            string localFilenameC = strC.toUtf8().constData();
            loc = localFilenameC.find(".txt");
            if(loc == string::npos)
                loc = localFilenameC.find(".html");
            s = localFilenameC.substr(loc - 1, 1);
            no = "";
            while (nos.find(s) != string::npos) { no = s + no; loc--; s = localFilenameC.substr(loc - 1, 1); } // if s in nos, s = 2  no = 23, s = 1 no = 123, s = - break
            localFilenameC.replace(loc, no.size(), to_string(page_no));
            // NOW localFilenameI and localFilenameC has page1 of both
            std::ifstream sIpage(localFilenameI);
            if (!(sIpage.is_open())) break;
            std::ifstream sCpage(localFilenameI);
            if (!(sCpage.is_open())) break;
            vector<string> wrong1, right1;
            generatePairs(wrong1, right1, localFilenameI, localFilenameC);
            size_t sz = wrong1.size();
            if (sz < right1.size()) sz = right1.size();
            for (size_t t = 0; t < sz; t++) {
                if (right1[t] != "") repx << wrong1[t] << "\t" << right1[t] << endl;//
            }

            page_no++;
        }
    }
}

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

void MainWindow::on_actionPrimarySecOCRPair_triggered()
{
    QString file1 = QFileDialog::getOpenFileName(this, "Open a File");

    if (!file1.isEmpty())
    {
        QFile sFile(file1);
        if (sFile.open(QFile::ReadOnly | QFile::Text)) {
            string localFilenameN = file1.toUtf8().constData();
            int loc = localFilenameN.find("IEROCR");
            string localFilenameG = localFilenameN.substr(0, loc) + "GEROCR";
            cout << localFilenameG << endl;
            std::ofstream op(localFilenameN + "ocrPairs");
            vector<string> wrong1, right1;
            generatePairsSpaced(wrong1, right1, localFilenameN, localFilenameG);
            size_t sz = wrong1.size();
            if (sz < right1.size()) sz = right1.size();
            for (size_t t = 0; t < sz; t++) {
                if (right1[t] != "") op << wrong1[t] << "\t" << right1[t] << endl;
            }
        }

    }
}



void MainWindow::on_actionCPairGEROcrVsCorrect_triggered()
{
    QString strI1 = mFilename;
    string strInew = strI1.toUtf8().constData();
    size_t locI = strInew.find("Inds");
    string strI = strInew.substr(0, locI) + "GEROCR";
    string strC = strInew.substr(0, locI) + "Correct";
    string localFilenameN = strI1.toUtf8().constData();
    size_t loc1 = localFilenameN.find("Inds");
    string s1 = localFilenameN.substr(0, loc1);
    string sRepx = s1 + "Reports/inputx";
    string sRepy = s1 + "Reports/inputy";
    vector<string> wrong1, right1;
    generatePairsIEROCR(strI, strC, sRepx, sRepy);
}


void MainWindow::on_actionCPairIEROcrVsCorrect_triggered()
{
    // Load foders in strC and strI
    QString strI1 = mFilename;
    //strI.replace("Correct", "Inds"); strC.replace("Inds","Correct");
    string strInew = strI1.toUtf8().constData();
    size_t locI = strInew.find("Inds");
    string strI = strInew.substr(0, locI) + "IEROCR";
    string strC = strInew.substr(0, locI) + "Correct";
    // load text files one by one
    //Load page1 of Inds
    string localFilenameN = strI1.toUtf8().constData();
    size_t loc1 = localFilenameN.find("Inds");
    string s1 = localFilenameN.substr(0, loc1);
    string sRepx = s1 + "Reports/inputx";
    string sRepy = s1 + "Reports/inputy";
    vector<string> wrong1, right1;
    generatePairsIEROCR(strI, strC, sRepx, sRepy);

}

void MainWindow::on_actionEditDistRep_triggered()
{
    QString file1 = QFileDialog::getOpenFileName(this, "Open a File");

    if (!file1.isEmpty())
    {
        QFile sFile(file1);
        if (sFile.open(QFile::ReadOnly | QFile::Text)) {
            string localFilenameN = file1.toUtf8().constData();
            std::ifstream ip1(localFilenameN); std::ifstream ip2(localFilenameN + "y");
            std::ofstream op(localFilenameN + "EditDisRep");
            string word1, word2;
            int max = 0;
            op << "a = [";
            while (getline(ip1, word1)) {
                getline(ip2, word2);
                int ed = editDist(word1, word2);
                op << ed << " ";
                if (ed > max) max = ed;
            }
            op << "];" << endl;
            op << " hist(a,-0.5:0.5:max(a))" << endl << "pause()" << endl;


        }
    }
}

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

void MainWindow::on_actionConfusionFreqHist_triggered()
{
    QString file1 = QFileDialog::getOpenFileName(this, "Open a File");
    if (!file1.isEmpty())
    {
        QFile sFile(file1);
        if (sFile.open(QFile::ReadOnly | QFile::Text)) {
            string localFilenameN = file1.toUtf8().constData();
            std::ifstream ip(localFilenameN);
            std::ofstream op(localFilenameN + "HistOCtaveRep");
            std::ofstream opx(localFilenameN + "HistXaxisRep");
            string line;
            op << "a = [";
            while (getline(ip, line)) {
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

void MainWindow::on_actionErrorDetectionRepUniq_triggered()
{
    map<size_t, size_t> mapCorrect, mapinCorrect, mapTyping, mapSugg1, mapSugg2, mapSugg3, mapSugg4, mapSugg5, mapSugg6, mapSugg7, mapSugg8, mapSugg9, mapSugg10;

    QString strI = mFilename;
    QString strC = strI;
    strI.replace("CorrectorOutput", "Inds"); strC.replace("Inds", "CorrectorOutput");


    size_t page_no = 1;
    QString filereport;

    while (1) {
        string nos = "0123456789";
        string localFilenameI = strI.toUtf8().constData();
        size_t loc = localFilenameI.find(".txt");
        if(loc == string::npos)
            loc = localFilenameI.find(".html");
        string s = localFilenameI.substr(loc - 1, 1);
        string no;
        vector<string> wrong, right;
        while (nos.find(s) != string::npos) { no = s + no; loc--; s = localFilenameI.substr(loc - 1, 1); }
        localFilenameI.replace(loc, no.size(), to_string(page_no));
        string localFilenameC = strC.toUtf8().constData();
        loc = localFilenameC.find(".txt");
        if(loc == string::npos)
            loc = localFilenameC.find(".html");
        s = localFilenameC.substr(loc - 1, 1);
        no = "";
        while (nos.find(s) != string::npos) { no = s + no; loc--; s = localFilenameC.substr(loc - 1, 1); }
        localFilenameC.replace(loc, no.size(), to_string(page_no));

        vector<string> vecpI, vecpC;
        map<string, bool> isAscii;
        std::ifstream sIpage(localFilenameI);
        if (!(sIpage.is_open())) break;
        string localstr;
        while (sIpage >> localstr) vecpI.push_back(toslp1(localstr)); sIpage.close();
        std::ifstream sCpage(localFilenameC);
        while (sCpage >> localstr) { if (hasM40PerAsci(localstr)) { isAscii[toslp1(localstr)] = 1; }  vecpC.push_back(toslp1(localstr)); } sIpage.close();
        int vGsz = vecpC.size(), vIsz = vecpI.size();
        if (vGsz > vIsz) mapTyping[page_no] = vGsz - vIsz;
        int win = vGsz - vIsz;
        if (win < 0) win = -1 * win;
        win = std::max(win, 5);
        for (int t = 0; t < vIsz; t++) {
            size_t minedit = 1000;
            string s1 = vecpI[t];
            string sC;
            for (int t1 = std::max(t - win, 0); t1 < min(t + win, vGsz); t1++) {
                string sCt1 = vecpC[t1];
                size_t mineditIC = editDist(s1, sCt1);
                if (mineditIC < minedit) { minedit = mineditIC; sC = sCt1; }
                if (sCt1 == s1) { break; }
            }

            if ((sC == (s1))) {
                mapCorrect[page_no]++;
            }
            else if (!isAscii[sC]) {
                wrong.push_back(s1); right.push_back(sC);
                vector<string>  Words1 = print5NearestEntries(TGBook, s1);
                if (Words1.size() == 0) Words1.push_back("");
                string nearestCOnfconfirmingSuggvec;
                vector<string> vec = Words1;
                int min = 100;
                for (size_t t = 0; t < vec.size(); t++) {
                    vector<string> wordConfusions; vector<int> wCindex;
                    int minFactor = loadWConfusionsNindex1(s1, vec[t], ConfPmap, wordConfusions, wCindex);
                    wordConfusions.clear(); wCindex.clear();
                    if (minFactor < min) { min = minFactor; nearestCOnfconfirmingSuggvec = vec[t]; }
                }
                if (nearestCOnfconfirmingSuggvec == (sC)) { mapSugg1[page_no]++; }
                else if ((Words1[0] == (sC))) { mapSugg2[page_no]++; }
                else {

                    vector<string> Alligned = print5NearestEntries(TGBookP, s1); //6
                    if (Alligned.size() == 0) Alligned.push_back("");

                    string PairSugg = "";
                    if (Alligned.size() > 0) PairSugg = print2OCRSugg(s1, Alligned[0], ConfPmap, Dict);//3
                    if (PairSugg == sC) { mapSugg3[page_no]++; }
                    else {
                        vector<string>  Words = print1OCRNearestEntries(toslp1(s1), vIBook); // 4 primary doc based
                        if (Words.size() == 0) Words.push_back("");
                        if (Words[0] == (sC)) { mapSugg4[page_no]++; }
                        else {
                            string samassugg = SamasBreakLRCorrect(toslp1(s1), Dict, PWords, TPWords, TPWordsP); // 5
                            if (samassugg == sC) { mapSugg5[page_no]++; }
                            else {
                                vector<string> PWords1 = print5NearestEntries(TPWords, s1); // 6
                                if (PWords1.size() == 0) PWords1.push_back("");
                                if (PWords1[0] == (sC)) { mapSugg6[page_no]++; }
                                else {
                                    string nearestCOnfconfirmingSuggvecFont;
                                    int min = 100;
                                    for (size_t t = 0; t < vec.size(); t++) {
                                        vector<string> wordConfusions; vector<int> wCindex;
                                        int minFactor = loadWConfusionsNindex1(s1, vec[t], ConfPmapFont, wordConfusions, wCindex);
                                        wordConfusions.clear(); wCindex.clear();
                                        if (minFactor < min) { min = minFactor; nearestCOnfconfirmingSuggvecFont = vec[t]; }
                                    }
                                    if (nearestCOnfconfirmingSuggvecFont == sC) { mapSugg7[page_no]++; }
                                    else {
                                        vector<string> Wordsdict; {Wordsdict = print5NearestEntries(TDict, s1); }
                                        if ((Wordsdict.size() > 0) && (Wordsdict[0] == sC)) { mapSugg8[page_no]++; }
                                        else {
                                            string sugg9 = generatePossibilitesNsuggest(s1, TopConfusions, TopConfusionsMask, Dict, SRules);
                                            if (sugg9 == sC) {
                                                mapSugg9[page_no]++;
                                            }
                                            else {
                                                if (LSTM[s1] == sC) {
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
            else { mapTyping[page_no]++; } // else
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

void MainWindow::on_actionSanskrit_triggered()
{
    HinFlag = 0, SanFlag = 1;
    ui->textEdit->setText(gSanskrit);
    ui->hinButton->setChecked(HinFlag);
    //ui->sanButton->setChecked(SanFlag);


}

void MainWindow::on_actionHindi_triggered()
{
    HinFlag = 1, SanFlag = 0;
    ui->textEdit->setText(gHindi);
    //ui->hinButton->setChecked(HinFlag);
    ui->sanButton->setChecked(SanFlag);
}

void MainWindow::on_actionEnglish_triggered()
{
    HinFlag = 0, SanFlag = 0;
    ui->hinButton->setChecked(HinFlag);
    ui->sanButton->setChecked(SanFlag);
}

void MainWindow::on_sanButton_toggled(bool checked)
{
    if(checked)
        on_actionSanskrit_triggered();
}

void MainWindow::on_hinButton_toggled(bool checked)
{

    if(checked)
        on_actionHindi_triggered();
}


void MainWindow::on_actionUndo_triggered()
{
    if(!curr_browser)
        return;
    curr_browser->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    if(!curr_browser)
        return;
    curr_browser->redo();
}

void MainWindow::on_actionNew_Project_triggered()
{
        ProjectWizard* wiz = new ProjectWizard();
        wiz->show();
}


void MainWindow::on_actionBold_triggered()
{
	if(!curr_browser)
		return;
    QTextCharFormat format;
    format.setFontWeight(QFont::Bold);
    curr_browser->textCursor().mergeCharFormat(format);
}

void MainWindow::on_actionUnBold_triggered()
{
	if(!curr_browser)
		return;
    QTextCharFormat format;
    format.setFontWeight(QFont::Normal);
    curr_browser->textCursor().mergeCharFormat(format);
}

void MainWindow::on_actionLeftAlign_triggered()
{
	if(!curr_browser)
		return;
    curr_browser->setAlignment(Qt::AlignLeft);
}

void MainWindow::on_actionRightAlign_triggered()
{
	if(!curr_browser)
		return;
    curr_browser->setAlignment(Qt::AlignRight);
}

void MainWindow::on_actionCentreAlign_triggered()
{
	if(!curr_browser)
		return;
    curr_browser->setAlignment(Qt::AlignCenter);
}
void MainWindow::on_actionJusitfiedAlign_triggered() //Not used, does not work as intended
{
	if(!curr_browser)
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

void MainWindow::on_actionAllFontProperties_triggered()
{
	if(!curr_browser)
		return;
    QFont initialFont = curr_browser->font();
    auto pointsize = curr_browser->fontPointSize();
    if(pointsize) initialFont.setPointSize(pointsize);
    bool ok;
    QFont font = QFontDialog::getFont(&ok, initialFont, this);
    if(ok)
    {
        QTextCharFormat newFont;
        newFont.setFont(font);
        curr_browser->textCursor().mergeCharFormat(newFont);
    }
}

void MainWindow::on_actionFontBlack_triggered()
{
	if(!curr_browser)
		return;
    curr_browser->setTextColor(Qt::black);
}

void MainWindow::on_actionSuperscript_triggered() {
    if(!curr_browser)
        return;
    auto cursor = curr_browser->textCursor();
    auto selected = cursor.selection();
    QString sel = selected.toPlainText();
    cursor.removeSelectedText();
    sel = "<sup>" + sel + "</sup>";
    auto newFrag = selected.fromHtml(sel);
    cursor.insertFragment(newFrag);
}
void MainWindow::on_actionSubscript_triggered() {
    if(!curr_browser)
        return;
    auto cursor = curr_browser->textCursor();
    auto selected = cursor.selection();
    cursor.removeSelectedText();
    QString sel = selected.toPlainText();
    sel = "<sub>" + sel + "</sub>";
    auto newFrag = selected.fromHtml(sel);
    cursor.insertFragment(newFrag);
}
void MainWindow::on_actionInsert_Horizontal_Line_triggered()
{
	if(!curr_browser)
		return;
    curr_browser->insertHtml("<hr>");
}

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

void MainWindow::on_actionInsert_Tab_Space_triggered()
{
	if(!curr_browser)
		return;
    curr_browser->insertPlainText("    ");
}

void MainWindow::on_actionZoom_In_triggered()
{
    if (z)
        z->gentle_zoom(1.1);
}

void MainWindow::on_actionZoom_Out_triggered()
{
    if (z)
        z->gentle_zoom(0.9);
}

void MainWindow::on_actionSymbols_triggered()
{
    SymbolsView *symbols = new SymbolsView(this);
    symbols->show();
}


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



void MainWindow::on_actionHighlight_triggered() //Version Based
{
    if(curr_browser) {

        if(isVerifier) {
            QTextCursor cursor = curr_browser->textCursor();
            QString text = cursor.selectedText().toUtf8().constData();
            int pos1 = curr_browser->textCursor().selectionStart();
            int pos2 = curr_browser->textCursor().selectionEnd();
        
            int cursorpos = round(((float)(pos1 + pos2)) / 2);
            cursor.setPosition(cursorpos);
        
            QTextCharFormat  format = cursor.charFormat();
            if (format.background() == Qt::yellow)
            {
                format.setBackground(Qt::transparent);
            }
            else
            {
                format.setBackground(Qt::yellow);

                LogHighlights(text);
            }
            curr_browser->textCursor().mergeCharFormat(format);
            curr_browser->copy();
        }
        else {
            curr_browser->setTextBackgroundColor(Qt::transparent); //Correctors are only allowed to remove highlights.
        }
    }
}

void MainWindow::LogHighlights(QString word) //Verifier Only
{
    //Highlighted Time meta data is stored

    QString dir = mProject.GetDir().absolutePath();
    QString highlightsFilename = gDirTwoLevelUp + "/Comments/HighlightsLog.json";
    QString pagename = gCurrentPageName;
    pagename.replace(".txt", "");
    pagename.replace(".html", "");
    QJsonObject mainObj = readJsonFile(highlightsFilename);
    QJsonObject page = mainObj.value(pagename).toObject();
    QJsonObject highlights;


    int nMilliseconds = myTimer.elapsed();
    secs = nMilliseconds / 1000;
    //    int mins = secs/60;
    //    secs = secs - mins*60;
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

QJsonObject MainWindow::getAverageAccuracies(QJsonObject mainObj)
{
    float totalcharacc=0, totalwordacc = 0; int totalcharerrors = 0, totalworderrors = 0, count = 0, rating = 0;

    QJsonObject pages = mainObj.value("pages").toObject();
    QJsonObject page;

    foreach(const QJsonValue &val, pages)
    {
        QString page = val.toObject().value("pagename").toString();
        float charAccuracy    = val.toObject().value("characcuracy").toDouble();
        float wordAccuracy    = val.toObject().value("wordaccuracy").toDouble();
        int charerrors = val.toObject().value("charerrors").toInt();
        int worderrors = val.toObject().value("worderrors").toInt();

        totalcharacc    += charAccuracy;
        totalwordacc    += wordAccuracy;
        totalcharerrors += charerrors;
        totalworderrors += worderrors;

        count++;
    }
    if(count)
    {

        double avgcharacc = totalcharacc/count;
        if(avgcharacc>98.5) rating = 4;
        else if(avgcharacc > 97.5) rating = 3;
        else if(avgcharacc > 96.5) rating = 2;
        else if(avgcharacc <= 96.5) rating = 1;

        if(mProject.get_stage() != mRole)
            mainObj["Rating-V"+ QString::number(mProject.get_version().toInt() - 1)] = rating;
        else
            mainObj["Rating-V"+ mProject.get_version()] = rating;
        mainObj["AverageCharAccuracy"] = avgcharacc;
        mainObj["AverageWordAccuracy"] = totalwordacc/count;
        mainObj["AverageCharErrors"] = totalcharerrors/count;
        mainObj["AverageWordErrors"] = totalworderrors/count;

    }
    return mainObj;
}

void MainWindow::updateAverageAccuracies() //Verifier only
{
    QString commentFilename = gDirTwoLevelUp + "/Comments/comments.json";

    string csvfolder = gDirTwoLevelUp.toUtf8().constData();
    csvfolder += "/Comments/AverageAccuracies.csv";
    std::ofstream csvFile(csvfolder);
    csvFile<<"Page Name,"<< "Word-Level Accuracy,"<<"Character-Level Accuracy," <<"Word-Level Errors,"<<"Character-Level Errors"<<"\n";

    QJsonObject mainObj = readJsonFile(commentFilename);
    if(mainObj.isEmpty())
        return;
    float totalcharacc=0, totalwordacc = 0; int totalcharerrors = 0, totalworderrors = 0, count = 0, rating = 0;


    QJsonObject pages = mainObj.value("pages").toObject();
    QJsonObject page;

    foreach(const QJsonValue &val, pages)
    {
        QString page = val.toObject().value("pagename").toString();
        float charAccuracy    = val.toObject().value("characcuracy").toDouble();
        float wordAccuracy    = val.toObject().value("wordaccuracy").toDouble();
        int charerrors = val.toObject().value("charerrors").toInt();
        int worderrors = val.toObject().value("worderrors").toInt();

        csvFile << page.toUtf8().constData() <<"," << wordAccuracy << "," << charAccuracy << "," << worderrors<< "," << charerrors<<"\n";

        totalcharacc    += charAccuracy;
        totalwordacc    += wordAccuracy;
        totalcharerrors += charerrors;
        totalworderrors += worderrors;

        count++;
    }
    if(count)
    {

        double avgcharacc = totalcharacc/count;
        if(avgcharacc>98.5) rating = 4;
        else if(avgcharacc > 97.5) rating = 3;
        else if(avgcharacc > 96.5) rating = 2;
        else if(avgcharacc <= 96.5) rating = 1;

        if(mProject.get_stage() != mRole)
            mainObj["Rating-V"+ QString::number(mProject.get_version().toInt() - 1)] = rating;
        else
            mainObj["Rating-V"+ mProject.get_version()] = rating;
        mainObj["AverageCharAccuracy"] = avgcharacc;
        mainObj["AverageWordAccuracy"] = totalwordacc/count;
        mainObj["AverageCharErrors"] = totalcharerrors/count;
        mainObj["AverageWordErrors"] = totalworderrors/count;

    csvFile<< ",,,,";
    csvFile<<" ,"<< "Average Accuracy (Word level),"<<"Average Accuracy (Character-Level)," <<"Average Errors (Word level),"<<"Average Errors (Character-Level),"<<"\n";
    csvFile <<" " <<"," << totalwordacc/count << "," << totalcharacc/count << "," << totalworderrors/count<< "," << totalcharerrors/count<<"\n";


    writeJsonFile(commentFilename, mainObj);

    }

}

void MainWindow::on_viewComments_clicked() //Version Based
{
	if (curr_browser) {
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

            if( !mainObj.isEmpty() ) {

                rating = mainObj["Rating-V"+ mProject.get_version()].toInt();
                avgCharAcc = mainObj["AverageCharAccuracy"].toDouble();
                avgAcc = QString::number((((float)lround(avgCharAcc*100))/100)) + "%";

                if(!page.isEmpty()) {
                    comments = page.value("comments").toString();
                    totalCharErrors = page.value("charerrors").toInt();
                    totalWordErrors = page.value("worderrors").toInt();
                    wordAccuracy = page.value("wordaccuracy").toDouble();
                    charAccuracy = page.value("characcuracy").toDouble();
                }
            }

            if(!isVerifier) {

                CommentsView *cv = new CommentsView(totalWordErrors,totalCharErrors,wordAccuracy,charAccuracy,comments,commentFilename, pageName, rating, avgAcc, mRole,version);
                cv->show();
                return;
            }

            if(gDirOneLevelUp!= (gDirTwoLevelUp + "/Inds")) //if Inds file-> do not create new accuracies just display previous accuracy to the Verifier
            {

                /*
                //      Character Changes for Accuracy Calculation

                QTextDocument doc;
                doc.setHtml(correctorOutput);
                correctorOutput = doc.toPlainText().simplified();
                currentpagetext = curr_browser->toPlainText().simplified();

                int l1 = correctorOutput.length(), l2 = currentpagetext.length();


                diff_match_patch dmp;
                auto diffs1 = dmp.diff_main(correctorOutput,currentpagetext);
                totalCharErrors = LevenshteinWithGraphemes(diffs1);

                auto diffs2 = dmp.diff_linesToChars(correctorOutput, currentpagetext); //LinesToChars modifed for WordstoChar in diff_match_patch.cpp
                auto lineText1 = diffs2[0].toString();
                auto lineText2 = diffs2[1].toString();
                auto lineArray = diffs2[2].toStringList();
                int totalwords = lineArray.count();
                auto diffs3 = dmp.diff_main(lineText1, lineText2);
                totalWordErrors= LevenshteinWithGraphemes(diffs3);
                dmp.diff_charsToLines(diffs3, lineArray);


                charAccuracy = (float)(l1 - totalCharErrors)/(float)l1*100;
                if(charAccuracy<0) charAccuracy = ((float)(l2 - totalCharErrors)/(float)l2)*100;
                charAccuracy = (((float)lround(charAccuracy*100))/100);

                wordAccuracy = (float)(totalwords - totalWordErrors)/(float)totalwords*100;
                wordAccuracy = (((float)lround(wordAccuracy*100))/100);
                */

            //HIGHLIGHTS FOR Accuracy Calculation

                auto textCursor = curr_browser->textCursor();
                QString textBrowserText = curr_browser->toPlainText();
                textCursor.setPosition(0);
                QString highlightedChars = "", selectedChar; // to store all the highlighted characters
                int prevHighlightPos = -2; // Used as an indicator to separate non contigous highlighted text with a space
                while(!textCursor.atEnd()) {
                    int anchor = textCursor.position();
                    QTextCharFormat format = textCursor.charFormat();
                    if(anchor!=0)
                        selectedChar = QString(textBrowserText[anchor-1]);
                    if(!selectedChar.contains(" ")) {
                        textCursor.select(QTextCursor::WordUnderCursor);
                        QString wordundercursor = textCursor.selectedText();
                        int key = textCursor.selectionStart();

                        if(format.background() == Qt::yellow && anchor>=(key+1)) {
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

                totalCharErrors = GetGraphemesCount(highlightedChars);

                int totalChars=0;
                QString currentText = curr_browser->toPlainText();
                int totalWords = currentText.simplified().count(" ") + 1;
                QTextBoundaryFinder finder1 = QTextBoundaryFinder(QTextBoundaryFinder::BoundaryType::Grapheme, currentText);
                while (finder1.toNextBoundary() != -1) {
                        totalChars++;
                    }

                totalWordErrors = wordCount.size();
                charAccuracy = (float)(totalChars - totalCharErrors)/(float)totalChars*100;
                wordAccuracy = (float)(totalWords - totalWordErrors)/(float)totalWords*100 ;
                wordAccuracy = ((float)lround(wordAccuracy*100))/100;
                charAccuracy = ((float)lround(charAccuracy*100))/100;

            }

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


void MainWindow::on_compareCorrectorOutput_clicked()
{
    QString qs1="", qs2="";
        file = QFileDialog::getOpenFileName(this,"Open Corrector's Output File");
        if(!file.isEmpty())
        {
            QString correctortext = file;
            QString ocrtext = file;
            ocrtext.replace("CorrectorOutput","Inds"); //CAN CHANGE ACCORDING TO FILE STRUCTURE
            ocrtext.replace(".html",".txt");
//            ocrtext.replace("V1_","");
//            ocrtext.replace("V2_","");
//            ocrtext.replace("V3_","");
            QString ocrimage = ocrtext;
            ocrimage.replace("Inds", "Images");
            ocrimage.replace(".txt", ".jpeg");
            ocrimage.replace(".html",".jpeg");

            if(!ocrtext.isEmpty())
            {
                QFile sFile(ocrtext);
                if(sFile.open(QFile::ReadOnly | QFile::Text))
                {
                    QTextStream in(&sFile);
                    in.setCodec("UTF-8");
                    qs1 = in.readAll().replace(" \n","\n");
                    if(qs1=="") {
                        DisplayError("Error in Displaying File: "+ ocrtext+ "is Empty");
                        return;      }
                    sFile.close();
                }

            }
            if(!correctortext.isEmpty())
            {
                QFile sFile(correctortext);
                if(sFile.open(QFile::ReadOnly | QFile::Text))
                {
                    QTextStream in(&sFile);
                    in.setCodec("UTF-8");
                    qs2 = in.readAll();
                    if(qs2=="") {
                        DisplayError("Error in Displaying File: "+ correctortext + "is Empty");
                        return;      }
                    sFile.close();
                }

            }
            QTextDocument doc;
            doc.setHtml(qs2);
            qs2 = doc.toPlainText().replace(" \n", "\n");

            int l1,l2, DiffOcr_Corrector; float correctorChangesPerc;

            l1 = GetGraphemesCount(qs1); l2 = GetGraphemesCount(qs2);

            diff_match_patch dmp;
            auto diffs1 = dmp.diff_main(qs1,qs2);
            DiffOcr_Corrector = LevenshteinWithGraphemes(diffs1);
            correctorChangesPerc = ((float)(DiffOcr_Corrector)/(float)l2)*100;
            if(correctorChangesPerc>100) correctorChangesPerc = ((float)(DiffOcr_Corrector)/(float)l1)*100;
            correctorChangesPerc = (((float)lround(correctorChangesPerc*100))/100);

            InternDiffView *dv = new InternDiffView(qs1,qs2,ocrimage,QString::number(correctorChangesPerc)); //Fetch OCR Image in DiffView2 and Set
            dv->show();
    }
}

void MainWindow::on_compareVerifierOutput_clicked() //Verifier-Version
{

    QString qs1="", qs2="",qs3="";
    file = QFileDialog::getOpenFileName(this,"Open Verifier's Output File");
    if(!file.isEmpty())
    {
        QString verifierText = file;
        QString correctorText = file.replace("VerifierOutput","CorrectorOutput"); //CAN CHANGE ACCORDING TO FILE STRUCTURE
        QString ocrText = file.replace("CorrectorOutput","Inds"); //CAN CHANGE ACCORDING TO FILE STRUCTURE
        ocrText.replace(".html",".txt");
//        ocrText.replace("V1_","");
//        ocrText.replace("V2_","");
//        ocrText.replace("V3_","");
        if(!ocrText.isEmpty())
        {
            QFile sFile(ocrText);
            if(sFile.open(QFile::ReadOnly | QFile::Text))
            {
                QTextStream in(&sFile);
                in.setCodec("UTF-8");
                qs1 = in.readAll().replace(" \n","\n");
                if(qs1=="") {
                    DisplayError("Error in Displaying File: "+ ocrText + "is Empty");
                    return;      }
                sFile.close();
            }

        }
        if(!correctorText.isEmpty())
        {
            QFile sFile(correctorText);
            if(sFile.open(QFile::ReadOnly | QFile::Text))
            {
                QTextStream in(&sFile);
                in.setCodec("UTF-8");
                qs2 = in.readAll();
                if(qs2=="") {
                    DisplayError("Error in Displaying File: "+ correctorText + "is Empty");
                    return;      }
                sFile.close();
            }

        }
        if(!verifierText.isEmpty())
        {
            QFile sFile(verifierText);
            if(sFile.open(QFile::ReadOnly | QFile::Text))
            {
                QTextStream in(&sFile);
                in.setCodec("UTF-8");
                qs3 = in.readAll();
                if(qs3=="") {
                    DisplayError("Error in Displaying File: "+ verifierText + "is Empty");
                    return;      }
                sFile.close();
            }

        }
        QTextDocument doc;

        doc.setHtml(qs2);
        qs2 = doc.toPlainText().replace(" \n","\n");

        doc.setHtml(qs3);
        qs3 = doc.toPlainText().replace(" \n","\n");

        int l1,l2,l3, DiffOcr_Corrector,DiffCorrector_Verifier,DiffOcr_Verifier; float correctorChangesPerc,verifierChangesPerc,ocrErrorPerc;

        l1 = GetGraphemesCount(qs1); l2 = GetGraphemesCount(qs2); l3 = GetGraphemesCount(qs3);

        diff_match_patch dmp;

        auto diffs1 = dmp.diff_main(qs1,qs2);
        DiffOcr_Corrector = LevenshteinWithGraphemes(diffs1);
        correctorChangesPerc = ((float)(DiffOcr_Corrector)/(float)l2)*100;
        if(correctorChangesPerc>100) correctorChangesPerc = ((float)(DiffOcr_Corrector)/(float)l1)*100;
        correctorChangesPerc = (((float)lround(correctorChangesPerc*100))/100);

        auto diffs2 = dmp.diff_main(qs2,qs3);
        DiffCorrector_Verifier = LevenshteinWithGraphemes(diffs2);
        verifierChangesPerc = ((float)(DiffCorrector_Verifier)/(float)l3)*100;
        if(verifierChangesPerc>100) verifierChangesPerc = ((float)(DiffCorrector_Verifier)/(float)l2)*100;
        verifierChangesPerc = (((float)lround(verifierChangesPerc*100))/100);

        auto diffs3 = dmp.diff_main(qs1,qs3);
        DiffOcr_Verifier = LevenshteinWithGraphemes(diffs3);
        ocrErrorPerc = ((float)(DiffOcr_Verifier)/(float)l3)*100;
        if(ocrErrorPerc>100) ocrErrorPerc = ((float)(DiffOcr_Verifier)/(float)l1)*100;
        float ocrAcc = 100 - (((float)lround(ocrErrorPerc*100))/100);

        DiffView *dv = new DiffView(qs1,qs2,qs3,QString::number(correctorChangesPerc),QString::number(verifierChangesPerc),QString::number(ocrAcc));
        dv->show();
    }
}


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


void MainWindow::on_actionAccuracyLog_triggered()
{
    QString qs1="", qs2="",qs3="";

    file = QFileDialog::getOpenFileName(this,"Open File from VerifierOutput Folder"); //open file
    int loc =  file.lastIndexOf("/");
    QString folder = file.mid(0,loc); //fetch parent tdirectory

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

       l1 = GetGraphemesCount(qs1); l2 = GetGraphemesCount(qs2); l3 = GetGraphemesCount(qs3);
       if(qs1=="" | qs2 == "" | qs3 == "")
       {
           continue;
       }

       diff_match_patch dmp;

       auto diffs1 = dmp.diff_main(qs1,qs2);
       DiffOcr_Corrector = LevenshteinWithGraphemes(diffs1);
       correctorChangesPerc = ((float)(DiffOcr_Corrector)/(float)l2)*100;
       if(correctorChangesPerc>100)
           correctorChangesPerc = ((float)(DiffOcr_Corrector)/(float)l1)*100;
       correctorChangesPerc = (((float)lround(correctorChangesPerc*100))/100);

       auto diffs2 = dmp.diff_main(qs2,qs3);
       DiffCorrector_Verifier = LevenshteinWithGraphemes(diffs2);
       verifierChangesPerc = ((float)(DiffCorrector_Verifier)/(float)l3)*100;
       if(verifierChangesPerc>100)
           verifierChangesPerc = ((float)(DiffCorrector_Verifier)/(float)l2)*100;
       verifierChangesPerc = (((float)lround(verifierChangesPerc*100))/100);
       float correctorCharAcc =100- (((float)lround(verifierChangesPerc*100))/100); //Corrector accuracy = 100-changes mabe by Verfier

       auto diffs3 = dmp.diff_main(qs1,qs3);
       DiffOcr_Verifier = LevenshteinWithGraphemes(diffs3);
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

void MainWindow::on_actionPush_triggered() {
    mProject.push();
}

//void MainWindow::on_actionCommit_triggered() {

//    QString text = "Verifier has Turned in Version:" + mProject.get_version();
//    mProject.commit(text.toStdString());
//}

void MainWindow::on_actionTurn_In_triggered() {  //Corrector-only
    if(mProject.get_version().toInt()){       
        if(mProject.findNumberOfFilesInDirectory(mProject.GetDir().absolutePath().toStdString() + R"(/CorrectorOutput/)")
                    != 2* mProject.findNumberOfFilesInDirectory(mProject.GetDir().absolutePath().toStdString() + R"(/Inds/)"))
        {
            QMessageBox::information(0, "Couldn't Turn In", "Make sure all files are there in CorrectorOutput directory");
            return;
        }
        QString commit_msg = "Corrector Turned in Version: " + mProject.get_version();
        if(! mProject.commit(commit_msg.toStdString())) {
            QMessageBox::information(0, "Turn In", "Turn In Cancelled");
            return;
        }
        on_actionFetch_2_triggered();

        if(! mProject.push()){
            QMessageBox::information(0, "Turn In", "Turn In Cancelled");
            return;
        }

        ui->lineEdit_2->setText("Version " + mProject.get_version());

        QString emailText =  "Book ID: " + mProject.get_bookId()
                            + "\nSet ID: " + mProject.get_setId()
                            + "\n" + commit_msg ;
      /*  if( !sendEmail(emailText)) {
            QMessageBox::information(0, "Turn In", "Network-Connection Error!\n\nEmail Notification Unsuccessful!,Please Check your Internet Connection");
            return;
        } */
        mProject.set_stage_verifier();
        ui->actionTurn_In->setEnabled(false);
        QMessageBox::information(0, "Turn In", "Turned In Successfully");
    }
    else{
        QMessageBox::information(0, "Turn In Error", "Please Open Project Before Turning In");
    }
}

void MainWindow::on_actionFetch_2_triggered() {
    QString stage = mProject.get_stage();
    QString prvs_stage = (stage=="Corrector")?"Verifier":"Corrector";
    QString prvs_output_dir = prvs_stage + "Output"; //"VerifierOutput" or "CorrectorOutput"

    int btn = QMessageBox::question(this, "Pull?", "This will overwrite files in" + prvs_output_dir + "directory. Do you want to Continue?",
                                    QMessageBox::StandardButton::Yes, QMessageBox::StandardButton::No);
    if (btn == QMessageBox::StandardButton::Yes){
        int btn2 = QMessageBox::question(this, "Are you sure?", "This will delete all your previous work from this project.        DO YOU STILL WANT TO CONTINUE?",
                                        QMessageBox::StandardButton::Yes, QMessageBox::StandardButton::No);
        if (btn2 == QMessageBox::StandardButton::Yes){
            mProject.fetch();
            qDebug() << "Fetch funtion executed ";
            if(mProject.get_version().toInt()){
            QMessageBox::information(0, "Pull Success", "Pull Succesful");
            }
            else{
            QMessageBox::information(0, "Pull Error", "Pull Un-succesful, Please Check Your Internet Connection");
            }
            if(!isVerifier) {
                if (mProject.get_stage() == "Corrector") {
                    ui->actionTurn_In->setEnabled(true);
                }
                else {
                    ui->actionTurn_In->setEnabled(false);
                }
            }
            ui->lineEdit_2->setText("Version " + mProject.get_version());
        }

    }
    else
        return;
}
void MainWindow::on_actionVerifier_Turn_In_triggered() { //Verifier-only

    if(mProject.findNumberOfFilesInDirectory(mProject.GetDir().absolutePath().toStdString() + R"(/VerifierOutput/)")
                != 2* mProject.findNumberOfFilesInDirectory(mProject.GetDir().absolutePath().toStdString() + R"(/Inds/)"))
    {
        QMessageBox::information(0, "Couldn't Turn In", "Make sure all files are there in VerifierOutput directory");
        return;
    }

    if(mProject.get_version().toInt()){
    int ver = mProject.get_version().toInt();
    QString commit_msg;


    QString commentFilename = gDirTwoLevelUp + "/Comments/comments.json";
    float avgcharacc = 0;
    bool formatting = false;
    int rating = 0;

    QJsonObject mainObj = readJsonFile(commentFilename);

    avgcharacc = mainObj["AverageCharAccuracy"].toDouble();
    if(mProject.get_stage() != mRole)
        rating = mainObj["Rating-V"+ QString::number(mProject.get_version().toInt() - 1)].toInt();
    else
        rating = mainObj["Rating-V"+ mProject.get_version()].toInt();
    if(((!mainObj["Formatting"].isNull())) || (! mainObj["Formatting"].isUndefined()))
        formatting = mainObj["Formatting"].toBool();


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
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    if (dialog.exec() == QDialog::Accepted) {
        formatting = cb->isChecked();
        if(rating == 4 && formatting)
            rating = 5;
        else if(rating == 5 && (!formatting))
            rating = 4;
    }
    else{
        QMessageBox::information(0, "Turn In", "Turn In Cancelled");
        return;
    }

    mainObj["Formatting"] = formatting;
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

    if(mRole != mProject.get_stage()) {
        messageBox.setText(msg1);
        messageBox.removeButton(resubmitButton);
    }
    else {
        messageBox.setText(msg2);
    }

    messageBox.exec();
    if (messageBox.clickedButton() == resubmitButton) {
        mProject.enable_push( false ); //Increment = false
        commit_msg = "Verifier Resubmitted Version:" + mProject.get_version();
    }
    else if (messageBox.clickedButton() == returnSetButton) {
        mProject.enable_push( true ); //Increment = true
        commit_msg = "Verifier has Turned in the Next Version:" + mProject.get_version();
    }
    else if (messageBox.clickedButton() == finaliseButton) {
        mProject.enable_push( false ); //Increment = false
        commit_msg = "Verifier Finalised Version:" + mProject.get_version();
    }
    else {
        QMessageBox::information(0, "Turn In", "Turn In Cancelled");
        return;
    }


    if(! mProject.commit(commit_msg.toStdString())) {
        QMessageBox::information(0, "Turn In", "Turn In Cancelled");
        return;
    }
    on_actionFetch_2_triggered();
    if(! mProject.push()){
      QMessageBox::information(0, "Turn In", "Turn In Cancelled");
      return;
    }

    ui->lineEdit_2->setText("Version " + mProject.get_version());

    QString emailText =  "Book ID: " + mProject.get_bookId()
                       + "\nSet ID: " + mProject.get_setId()
                        + "\nRating Provided: " + QString::number(rating)
                       + "\n" + commit_msg ;
  /*  if( !sendEmail(emailText)) {
        QMessageBox::information(0, "Turn In", "Network-Connection Error!\n\nTurn-In Unsuccessful!,Please Check your Internet Connection");
        return;
    } */
    QMessageBox::information(0, "Turn In", "Turned In Successfully");
    }
    else{
    QMessageBox::information(0, "Turn In Error", "Please Open Project Before Turning In");
    }

}
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
void MainWindow::LoadDocument(QFile * f, QString ext, QString name) {

    f->open(QIODevice::ReadOnly);
    QFileInfo finfo(f->fileName());
    if(!(finfo.exists() && finfo.isFile()))
            return;
    current_folder = finfo.dir().dirName();
    QString fileName = finfo.fileName();
    if (ui->tabWidget_2->count() != 0) {
        for (int i = 0; i < ui->tabWidget_2->count(); i++) {
            if (name == ui->tabWidget_2->tabText(i)) {
                ui->tabWidget_2->setCurrentIndex(i);
                mFilename = f->fileName();
                UpdateFileBrekadown();
                f->close();
                return;
            }
        }
    }
    mFilename = f->fileName();
    UpdateFileBrekadown();
    QTextBrowser * b = new QTextBrowser(this);
    b->setReadOnly(false);
    QTextStream stream(f);
    stream.setCodec("UTF-8");
    QFont font("Shobhika Regular");
    setWindowTitle(name);
    font.setPointSize(16);
    if(ext == "txt") {
        istringstream iss(stream.readAll().toUtf8().constData());
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
       b->setFont(font);
    }
    if (ext == "html") {
        b->setHtml(stream.readAll());
    }
    b->setFont(font);
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
    currentTabPageName = ui->tabWidget_2->tabText(currentTabIndex);
    gInitialTextHtml[currentTabPageName] = b->toHtml();

    b->setMouseTracking(true);
    b->installEventFilter(this);
    b->setLineWrapColumnOrWidth(QTextEdit::NoWrap);
    b->setUndoRedoEnabled(true);

    f->close();

    QString imageFilePath = mProject.GetDir().absolutePath()+"/Images/" + gCurrentPageName;
    imageFilePath.replace(".txt", ".jpeg");
    imageFilePath.replace(".html", ".jpeg");
    QFile *pImageFile = new QFile(imageFilePath);
    LoadImageFromFile(pImageFile);

}

void MainWindow::LoadImageFromFile(QFile * f) {
    QString localFileName = f->fileName();

    imageOrig.load(localFileName);
    if (graphic)delete graphic;
    graphic = new QGraphicsScene(this);
    graphic->addPixmap(QPixmap::fromImage(imageOrig));
    ui->graphicsView->setScene(graphic);
    ui->graphicsView->fitInView(graphic->itemsBoundingRect(), Qt::KeepAspectRatio);
    if (z)delete z;
    z = new Graphics_view_zoom(ui->graphicsView);
    z->set_modifiers(Qt::NoModifier);
}

void MainWindow::file_click(const QModelIndex & indx) {
    //std::cout << "Test";
    auto item = (TreeItem*)indx.internalPointer();
    auto qvar = item->data(0).toString();
    if(qvar == "Document" || qvar == "Image")
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
        if (suff == "jpeg") {
            LoadImageFromFile(file);
        }
        break;
    }
    default:
        break;

    }
    //auto data = qvar.data();;
}
void MainWindow::OpenDirectory() {
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
void MainWindow::RemoveFile() {
    //std::cout << "Test";
    auto item = (TreeItem*)curr_idx.internalPointer();
    Filter * filtr = item->GetFilter();
    QFile * file = item->GetFile();
    if (file->exists()) {
        mProject.removeFile(curr_idx, *filtr, *file);
        ui->treeView->reset();
    }
}
void MainWindow::AddNewFile() {
    auto item = (TreeItem*)curr_idx.internalPointer();
    Filter * filtr = item->GetFilter();
    QString name = filtr->name();
    QStringList list = filtr->extensions();
    QString filter = GetFilter(name, list);
    std::string str = filter.toStdString();
    QFile fileo(QFileDialog::getOpenFileName(this, "Open File", "./", tr(str.c_str())));
    if (fileo.exists()) {
        //Add it to project
        mProject.addFile(*filtr, fileo);
    }
}

void MainWindow::CustomContextMenuTriggered(const QPoint & p) {
    curr_idx = ui->treeView->indexAt(p);

    if (curr_idx.isValid()) {
        auto item = (TreeItem*)curr_idx.internalPointer();
        switch (item->GetNodeType()) {
        case _FILETYPE: {
            QMenu * m = new QMenu(this);
            QAction * act = new QAction("Remove File");
            connect(act, &QAction::triggered, this, &MainWindow::RemoveFile);
            m->addAction(act);
            m->move(ui->treeView->mapToGlobal(p));
            m->show();
        }
                        break;
        case FILTER:
        {
            QMenu * m = new QMenu(this);

            QAction * act = new QAction("Add New File");
            connect(act, &QAction::triggered, this, &MainWindow::AddNewFile);
            m->addAction(act);
            QAction * act2 = new QAction("Add Files");
            connect(act2, &QAction::triggered, this, &MainWindow::OpenDirectory);
            m->addAction(act2);
            m->move(ui->treeView->mapToGlobal(p));
            m->show();
            break;
        }
        }
    }
}

void MainWindow::closetab(int idx) {

    QTextBrowser *closing_browser = (QTextBrowser*)ui->tabWidget_2->widget(idx);
    QString closing_browserHtml = closing_browser->toHtml();
    QString closingTabPageName = ui->tabWidget_2->tabText(idx);
    if(closing_browserHtml != gInitialTextHtml[closingTabPageName]) {
        int btn = QMessageBox::question(this, "Save?", "Do you want to save " + closingTabPageName + " file?",
                                        QMessageBox::StandardButton::Ok, QMessageBox::StandardButton::No);
        if (btn == QMessageBox::StandardButton::Ok)
            on_actionSave_triggered();
    }
    delete ui->tabWidget_2->widget(idx);
}

void MainWindow::tabchanged(int idx) {
    currentTabIndex = idx;
    curr_browser = (QTextBrowser*)ui->tabWidget_2->widget(currentTabIndex);
    currentTabPageName = ui->tabWidget_2->tabText(currentTabIndex);
    if(currentTabPageName.contains("CorrectorOutput/") | currentTabPageName.contains("VerifierOutput/"))
        mFilename = mProject.GetDir().absolutePath() + "/" + currentTabPageName;
    else
        mFilename = mProject.GetDir().absolutePath() + "/Inds/" + currentTabPageName;
    UpdateFileBrekadown();

    QString imagePathFile = mFilename;
    imagePathFile.replace("CorrectorOutput", "Images");
    imagePathFile.replace("VerifierOutput", "Images");
    imagePathFile.replace("Inds", "Images");
    imagePathFile.replace(".txt", ".jpeg");
    imagePathFile.replace(".html", ".jpeg");
    QFile *pImageFile = new QFile(imagePathFile);
    LoadImageFromFile(pImageFile);

    myTimer.start();
    DisplayTimeLog();
}

void MainWindow::on_actionOpen_Project_triggered() { //Version Based

    QFile xml(QFileDialog::getOpenFileName(this, "Open Project", "./", tr("Project(*.xml)")));
    QFileInfo finfo(xml);
    QString basedir = finfo.absoluteDir().absolutePath();
    QString s1 = basedir + "/Images/";
    QString s2 = basedir + "/Inds/";
    QString s3 = basedir+"/CorrectorOutput/";
    QString s4 = basedir + "/VerifierOutput/";
    bool exists = QDir(s1).exists() && QDir(s2).exists() && QDir(s3).exists() &&(QDir(s3).exists()|| QDir(s4).exists());
    if (xml.exists()&& exists) {
        ui->treeView->reset();
        mProject.process_xml(xml);
        mProject.open_git_repo();
        mProject.setProjectOpen(true);
        ui->treeView->setModel(mProject.getModel());
        ui->treeView->setContextMenuPolicy(Qt::CustomContextMenu);
        bool b = connect(ui->treeView, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(CustomContextMenuTriggered(const QPoint&)));
        b = connect(ui->treeView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(file_click(const QModelIndex&)));
        QString stage = mProject.get_stage();
        QString version = mProject.get_version();
        ui->lineEdit_2->setText("Version: " + version);
        QDir dir = mProject.GetDir();
        QString str1 = mProject.GetDir().absolutePath()+"/CorrectorOutput/";
        QString str2 = mProject.GetDir().absolutePath() + "/VerifierOutput/";
        QString str3 = mProject.GetDir().absolutePath() + "/Inds/";
        QString str4 = mProject.GetDir().absolutePath() + "/Images/";
        watcher.addPath(str1);
        watcher.addPath(str2);
//        watcher.addPath(str3);
//        watcher.addPath(str4);
        QDir cdir(str1);
        Filter * filter = mProject.getFilter("Document");
        auto list = cdir.entryList(QDir::Filter::Files);
        std::cout << stage.toStdString();
        for (auto f : list) {
            QString t = str1 + "/" + f;
            QFile f2(t);
            mProject.AddTemp(filter,f2, "CorrectorOutput/" );
            corrector_set.insert(f);
        }
        cdir.setPath(str2);
        list = cdir.entryList(QDir::Files);
        for (auto f : list) {
            verifier_set.insert(f);
            QString t = str2 + "/" + f;
            QFile f2(t);
            mProject.AddTemp(filter, f2, "VerifierOutput/");
        }
        cdir.setPath(str3);
        list = cdir.entryList(QDir::Filter::Files);
        for (auto f : list) {
            QString t = str3 + "/" + f;
            QFile f2(t);
            mProject.AddTemp(filter, f2, "");
        }

        filter = mProject.getFilter("Image");
        cdir.setPath(str4);
        list = cdir.entryList(QDir::Filter::Files);
        for (auto f : list) {
            QString t = str4 + "/" + f;
            QFile f2(t);
            mProject.AddTemp(filter, f2, "");
        }

        //Disable Corrector Turn In once the Corrector has Turned in until the next version is fetched.
        if(!isVerifier) {
            if (stage != "Corrector") {
                ui->actionTurn_In->setEnabled(false);
            }
        }

        UpdateFileBrekadown();

        gTimeLogLocation = gDirTwoLevelUp + "/Comments/Timelog.json";
        QJsonObject mainObj =  readJsonFile(gTimeLogLocation);

        foreach(const QJsonValue &val, mainObj)
        {
            QString directory = val.toObject().value("directory").toString();
            int seconds    = val.toObject().value("seconds").toInt();
            timeLog[directory] = seconds;
        }

        bool isSet = QDir::setCurrent(mProject.GetDir().absolutePath() + "/CorrectorOutput") ; //Change application Directory to any subfolder of mProject folder for Image Insertion feature.
        if(!QDir(mProject.GetDir().absolutePath() + "/Images/Inserted").exists())
            QDir().mkdir(mProject.GetDir().absolutePath() + "/Images/Inserted");
    }
}
void MainWindow::directoryChanged(const QString &path) {

    QDir d(path);
    QString dirstr = d.dirName();
    auto list = d.entryList(QDir::Files);
    QSet<QString> s;
    for (auto file : list) {
        s.insert(file);
    }
    if (dirstr == "CorrectorOutput") {
        QSet<QString> added = s - corrector_set;
        QString str = mProject.GetDir().absolutePath() + "/CorrectorOutput/";
        Filter * filter = mProject.getFilter("Document");
        for (auto f : added) {
            QString t = str + "/" + f;
            QFile f2(t);
            mProject.AddTemp(filter, f2, "CorrectorOutput/");
            corrector_set.insert(f);
        }
    }
    else
    {
        QSet<QString> added = s - verifier_set;
        QString str = mProject.GetDir().absolutePath() + "/VerifierOutput/";
        Filter * filter = mProject.getFilter("Document");
        for (auto f : added) {
            QString t = str + "/" + f;
            QFile f2(t);
            mProject.AddTemp(filter, f2, "VerifierOutput/");
            verifier_set.insert(f);
        }
    }
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Close",
                                                               tr("Are you sure?\n"),
                                                               QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                               QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
    }
}


void MainWindow::on_actionInsert_Table_2_triggered()
{
    if(!curr_browser)
        return;

    QDialog dialog(this);
    // Use a layout allowing to have a label next to each field
    QFormLayout form(&dialog);
    form.addRow(new QLabel("Insert Table"));

    // Add the lineEdits with their respective labels
    QLineEdit *rows = new QLineEdit(&dialog);
    QLineEdit *columns = new QLineEdit(&dialog);
    form.addRow("Rows", rows);
    form.addRow("Columns", columns);
    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    // Show the dialog as modal
    if (dialog.exec() == QDialog::Accepted) {


        QTextTableFormat tf;
        tf.setBorderBrush(Qt::black);
        tf.setCellSpacing(0);

        QTextCursor cursor = curr_browser->textCursor();
        cursor.insertTable(rows->text().toInt(),columns->text().toInt(),tf);

        }
}
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

void MainWindow::on_actionInsert_Columnleft_triggered()
{
    if(!curr_browser)
            return;
    if(curr_browser->textCursor().currentTable())
        {
            QTextTable *currentTable = curr_browser->textCursor().currentTable();
            QTextTableCell currentCell = currentTable->cellAt(curr_browser->textCursor());
            currentTable->insertColumns(currentCell.column(),1);
         }
}

void MainWindow::on_actionInsert_Columnright_triggered()
{
    if(!curr_browser)
            return;
    if(curr_browser->textCursor().currentTable())
        {
            QTextTable *currentTable = curr_browser->textCursor().currentTable();
            QTextTableCell currentCell = currentTable->cellAt(curr_browser->textCursor());
            currentTable->insertColumns(currentCell.column()+1,1);
         }
}

void MainWindow::on_actionInsert_Rowabove_triggered()
{
    if(!curr_browser)
         return;
    if(curr_browser->textCursor().currentTable())
       {
         QTextTable *currentTable = curr_browser->textCursor().currentTable();
         QTextTableCell currentCell = currentTable->cellAt(curr_browser->textCursor());
         currentTable->insertRows(currentCell.row(),1);
       }
}

void MainWindow::on_actionInsert_Rowbelow_triggered()
{
    if(!curr_browser)
         return;
    if(curr_browser->textCursor().currentTable())
       {
         QTextTable *currentTable = curr_browser->textCursor().currentTable();
         QTextTableCell currentCell = currentTable->cellAt(curr_browser->textCursor());
         currentTable->insertRows(currentCell.row()+1,1);
       }
}

void MainWindow::on_actionRemove_Column_triggered()
{
    if(!curr_browser)
            return;
    if(curr_browser->textCursor().currentTable())
        {
            QTextTable *currentTable = curr_browser->textCursor().currentTable();
            QTextTableCell currentCell = currentTable->cellAt(curr_browser->textCursor());
            currentTable->removeColumns(currentCell.column(),1);
         }
}

void MainWindow::on_actionRemove_Row_triggered()
{
    if(!curr_browser)
         return;
    if(curr_browser->textCursor().currentTable())
       {
         QTextTable *currentTable = curr_browser->textCursor().currentTable();
         QTextTableCell currentCell = currentTable->cellAt(curr_browser->textCursor());
         currentTable->removeRows(currentCell.row(),1);
       }
}

void MainWindow::on_actionItalic_triggered()    //enable when required
{
    if(!curr_browser)
        return;
    QTextCharFormat format;
    format.setFontItalic(true);
    curr_browser->textCursor().mergeCharFormat(format);
}

void MainWindow::on_actionNonitalic_triggered() //enable when required
{
    if(!curr_browser)
        return;
    QTextCharFormat format;
    format.setFontItalic(false);
    curr_browser->textCursor().mergeCharFormat(format);
}

void MainWindow::on_actionSave_All_triggered()  //enable when required
{
    if(ui->tabWidget_2->count()!=0){
        for(int i=0;i<ui->tabWidget_2->count();i++){
            ui->tabWidget_2->setCurrentIndex(i);
            UpdateFileBrekadown();
            on_actionSave_triggered();
        }
    }

}
