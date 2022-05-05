#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QInputDialog>
#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <iostream>
#include <fstream>
#include <sstream>
#include <QFileDialog>
#include<string>
#include<QFontDialog>
#include<QFont>
#include<QFile>
//#include<hash_map>
#include <unordered_map>
//#include <std::codecvt>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <QAction>
#include <QtDebug>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
//#include <tesseract/baseapi.h>
//#include <leptonica/allheaders.h>
#include <QPlainTextEdit>
//#include "toFromslp1.h"
#include "zoom.h"
#include<QMessageBox>
#include<QTime>
#include<QPrinter>
#include<QPrintDialog>
//#include"staticDict.h"
//#include "lcsqt.h"
#include <Project.h>
#include <QTextBrowser>
#include <QSet>
#include<QDomDocument>
#include <QFileSystemWatcher>
#include<QGraphicsRectItem>
#include "globalreplacedialog.h"
#include "loadingspinner.h"
#include "progressbardialog.h"
#include "globalreplacepreview.h"
#include<markRegion.h>

//#include <set>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void closeSignal();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Project & GetProject() {
        return mProject;
    }
    bool setRole(QString role);
    bool exitStatus() {
        return mExitStatus;
    }
    int getCurrentTabIndex() {
        return currentTabIndex;
    }
    QTextBrowser * getCurrentBrowser() {
        return curr_browser;
    };

    void load_data();
    void reLoadTabWindow();

private slots:
    void createActions();
    void WordCount();
    void DisplayJsonDict(QTextBrowser *b, QString input);

    bool eventFilter(QObject *, QEvent *);

    void saveImageRegion(QPixmap, QString, QString,int,int,int);

 //   void displayHolder(QString,QString,QString,int,int,int,int,int);

    void on_actionNew_triggered();

    //void on_actionOpen_triggered();

    void AddRecentProjects();

    //void actionRecent_Project_clicked();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionSpell_Check_triggered();

    void mousePressEvent(QMouseEvent *ev);

    void menuSelection(QAction* action);

    void translate_replace(QAction*);
    void clipboard_paste(QAction*);
    void keyPressEvent(QKeyEvent*);

//    void SaveFile();

    void on_actionLoadGDocPage_triggered();

    void on_actionToDevanagari_triggered();

    void on_actionLoadData_triggered();

    void on_actionLoadDict_triggered();

    void on_actionLoadOCRWords_triggered();

    void on_actionLoadDomain_triggered();

    void on_actionLoadSubPS_triggered();

    void on_actionLoadConfusions_triggered();

    void on_actionSugg_triggered();

    //void on_actionCreateBest2OCR_triggered();

    void on_actionToSlp1_triggered();

    //void on_actionCreateSuggestionLog_triggered();

    //void on_actionCreateSuggestionLogNearestPriority_triggered();

    //void on_actionErrorDetectionRep_triggered();

    //void on_actionErrorDetectWithoutAdaptation_triggered();

    //void on_actionCPair_triggered();

    //void on_actionToSlp1_2_triggered();

    //void on_actionToDev_triggered();

    //void on_actionExtractDev_triggered();

    //void on_actionPrimarySecOCRPair_triggered();

    //void on_actionCPairIEROcrVsCorrect_triggered();

    //void on_actionEditDistRep_triggered();

    //void on_actionConfusionFreqHist_triggered();

    //void on_actionCPairGEROcrVsCorrect_triggered();

    //void on_actionCPairGEROcrVsCorrectSeparate_triggered();

    //void on_actionFilterOutGT50EditDisPairs_triggered();

    //void on_actionPrepareFeatures_triggered();

    //void on_actionErrorDetectionRepUniq_triggered();

    void on_actionSanskrit_triggered();

    void on_actionHindi_triggered();

    void on_actionEnglish_triggered();

    void on_actionLeftAlign_triggered();

    void on_actionRightAlign_triggered();

    void on_actionCentreAlign_triggered();

    void on_actionAllFontProperties_triggered();

    void on_actionUnBold_triggered();

    void on_actionJusitfiedAlign_triggered();

    void on_actionHighlight_triggered();

    void on_actionFontBlack_triggered();

    void updateAverageAccuracies();

    void on_actionViewAverageAccuracies_triggered();

    void on_actionOpen_Project_triggered();

    void file_click(const QModelIndex & indx);

    void LoadDocument(QFile * file, QString ext, QString name);

    void LoadImageFromFile(QFile * file);

    void CustomContextMenuTriggered(const QPoint &p);

    void AddNewFile();

    void OpenDirectory();

    void RemoveFile();

    void closetab(int index);

    void tabchanged(int index);

    //void on_actionCommit_triggered();

    void on_actionTurn_In_triggered();

    void on_actionPush_triggered();

    void on_actionFetch_2_triggered();

    void on_actionVerifier_Turn_In_triggered();

    void directoryChanged(const QString &path);

    void on_actionAccuracyLog_triggered();

    //void on_actionView_File_Hierarchy_triggered();

    //void on_actionFetch_triggered();

    //void on_actionCompare_Verifier_triggered();

    void on_compareCorrectorOutput_clicked();

    void on_viewComments_clicked();

    void on_actionZoom_In_triggered();

    void on_actionZoom_Out_triggered();

    void on_actionSymbols_triggered();

    //void on_actionCompare_Verifier_triggered();

    void on_actionInsert_Tab_Space_triggered();

    //void on_actionLineSpace_triggered();

    void on_actionInsert_Horizontal_Line_triggered();

    void on_actionSubscript_triggered();

    void on_actionSuperscript_triggered();

    void UpdateFileBrekadown();

    void on_actionAdd_Image_triggered();

    void SaveTimeLog();

    void DisplayTimeLog();

    void on_actionResize_Image_triggered();

    void LogHighlights(QString word);

    void on_compareVerifierOutput_clicked();

    void on_sanButton_toggled(bool checked);

    void on_hinButton_toggled(bool checked);

    void on_actionLineSpace_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionNew_Project_triggered();

    void on_actionInsert_Table_2_triggered();

    void closeEvent (QCloseEvent *event);

    QJsonObject getAverageAccuracies(QJsonObject mainObj);

    bool sendEmail(QString message);

    void on_actionInsert_Columnleft_triggered();

    void on_actionInsert_Columnright_triggered();

    void on_actionInsert_Rowabove_triggered();

    void on_actionInsert_Rowbelow_triggered();

    void on_actionRemove_Column_triggered();

    void on_actionRemove_Row_triggered();

    void on_actionItalic_triggered();

    void on_actionNonitalic_triggered();

    void on_actionSave_All_triggered();

    void on_actionFind_and_Replace_triggered();

    bool checkUnsavedWork();

    void saveAllWork();

    void readSettings();

    void writeSettings();

    void setMFilename( QString );

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void runGlobalReplace(QString, QVector<QString>);

    bool globalReplaceQueryMessageBox(QString old_word, QString new_word, int &chk);

    int writeGlobalCPairsToFiles(QString file_path, QMap <QString, QString> globalReplacementMap);

    void addCurrentlyOpenFileToEditedFilesLog();

    void deleteEditedFilesLog();
    void RecentPageInfo();

   // void highlight_dict(QTextBrowser *b);
    bool isStringInFile(QString file_path, QString searchString);

    void dumpStringToFile(QString file_path, QString string);

    void highlight(QTextBrowser *b , QString input);

    QMap <QString, QString> getGlobalReplacementMapFromChecklistDialog(QVector <QString> replacedWords, QVector<int> *replaceInAllPages);

    //void on_textEdit_dict_copyAvailable(bool b);

    void on_actionas_PDF_triggered();

    void on_actionGet_Help_triggered();

    void on_actionTutorial_triggered();

    void on_actionLinux_triggered();

    void on_actionWindows_triggered();

    void on_actionShortcut_Guide_triggered();

    void on_textBrowser_textChanged();

    void on_zoom_Out_Button_clicked();

    void on_zoom_In_Button_clicked();

    void zoom_slider_valueChanged(int value);

    void zoom_slider_moved(int value);

    void zoomedUsingScroll(); // Slot for signal zoomed() emitted from zoom.cpp

    void on_actionUndo_Global_Replace_triggered();

    bool undoGlobalReplace_Single_Word(QString oldWord, QString newWord);

    void reverseGlobalReplacedWordsMap();

    QMap<QString, QString> getUndoGlobalReplaceMap_Multiple_Words(QMap<QString, QString>);

    void replaceInAllFilesFromTSVfile();

    bool checkForValidTSVfile(QFile & file);

    void globalReplacePreviewfn(QMap <QString, QString>,QVector<int>);

    QMap<QString,QStringList> getBeforeAndAfterWords(QString fPath,QMap <QString, QString> globalReplacementMap);

    //QMap<QString,QStringList> getBeforeGlobalReplaceSentences(QString fPath,QMap <QString, QString> globalReplacementMap);

    //QMap<QString,QStringList> getAfterGlobalReplaceSentences(QString fPath,QMap <QString, QString> globalReplacementMap);


    void on_actionUpload_triggered();

    void on_justify_triggered();

    void on_actionFont_Color_triggered();

    void on_actionBold_triggered();

    void SaveFile_GUI_Preprocessing();

    void SaveFile_GUI_Postprocessing();

    void GlobalReplace();

    void stopSpinning();

    void on_lineEditSearch_textChanged(const QString &arg1);

    void on_action1_triggered();

    void on_action2_triggered();

    void on_action3_triggered();

    void on_actionCheck_for_Updates_triggered();

    void closeProgressBar();

    void setProgressBarPerc(int);

    QString toDevanagari(string text);

    void on_find_clicked();

    void on_actionPDF_Preview_triggered();

    void print(QPrinter *printer);

public slots:
    void SaveFile_Backend();

    void on_actionLoad_Next_Page_triggered();

    void on_actionLoad_Prev_Page_triggered();

private:
    bool mExitStatus = false;
    QString mRole;
    bool isVerifier;
    Ui::MainWindow *ui;
    Project mProject;
    QString mFilename;
    QString mFilenameImage;
    QString current_folder;
    QString currentTabPageName="";
    int currentTabIndex;
    QTextBrowser * curr_browser = nullptr;
    QGraphicsScene * graphic =nullptr;
    Graphics_view_zoom * z = nullptr;
    QModelIndex curr_idx;
    QSet<QString> corrector_set;
    QSet<QString> verifier_set;
    QFileSystemWatcher watcher;
    QGraphicsRectItem* item1;
    QGraphicsRectItem* crop_rect;
    QString s1, s2;
    int NextPrevTrig = 0;
    bool isRecentProjclick =false;
    QString RecentProjFile;
    QString RecentProjFile2;
    QString RecentProjFile3;
    QString proj_flag; //for choosing recent opened project out of 3
    LoadingSpinner *spinner;
    ProgressBarDialog *progressBarDialog;
    QString toolDirAbsolutePath; // This path is the absolute path of this tool
};

#endif // MAINWINDOW_H
