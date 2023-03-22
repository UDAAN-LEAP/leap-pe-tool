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
#include <string>
#include <QFontDialog>
#include <QFont>
#include <QFile>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <QAction>
#include <QtDebug>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
#include <QPlainTextEdit>
#include "qaudioprobe.h"
#include "qaudiorecorder.h"
#include "zoom.h"
#include <QMessageBox>
#include <QTime>
#include <QPrinter>
#include <QPrintDialog>
#include <Project.h>
#include <QTextBrowser>
#include <QSet>
#include <QDomDocument>
#include <QFileSystemWatcher>
#include <QGraphicsRectItem>
#include "globalreplacedialog.h"
#include "loadingspinner.h"
#include "progressbardialog.h"
#include <markRegion.h>
#include <QOAuth2AuthorizationCodeFlow>
#include <QCompleter>
#include <QDirModel>
#include <QStringListModel>
#include <QModelIndex>
#include <QAbstractItemModel>
#include <QScrollBar>
#include "customtextbrowser.h"
#include "handlebbox.h"
#include <QMediaRecorder>

using namespace std;
class AudioLevel;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void closeSignal();

    void gotToken(const QString& token);

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

    CustomTextBrowser * getCurrentBrowser() {
        return curr_browser;
    };

    void reLoadTabWindow();

    int insertedImagesCount;

    QMap<QPair<QString,QString>,QString> changesCheckedInPreviewMap;


private slots:
    void createActions();

    void WordCount();

    void DisplayJsonDict(CustomTextBrowser *b, QString input);

    bool eventFilter(QObject *, QEvent *);

    void saveImageRegion(QPixmap, QString, QString,int,int,int);

    void AddRecentProjects();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionSpell_Check_triggered();

    void mousePressEvent(QMouseEvent *ev);

    void menuSelection(QAction* action);

    void translate_replace(QAction*);

    void clipboard_paste(QAction*);

    void keyPressEvent(QKeyEvent*);

    void on_actionLoadGDocPage_triggered();

    void on_actionToDevanagari_triggered();

    void on_actionLoadData_triggered();

    void on_actionSugg_triggered();

    void on_actionToSlp1_triggered();

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

    void LoadImageFromFile(QFile * file);

    void CustomContextMenuTriggered(const QPoint &p);

    void AddNewFile();

    void OpenDirectory();

    void RemoveFile();

    void closetab(int index);

    void tabchanged(int index);

    void on_actionTurn_In_triggered();

    void on_actionPush_triggered();

    void on_actionFetch_2_triggered();

    void on_actionVerifier_Turn_In_triggered();

    void directoryChanged(const QString &path);

    void on_actionAccuracyLog_triggered();

    void on_compareCorrectorOutput_clicked();

    void on_viewComments_clicked();

    void on_actionZoom_In_triggered();

    void on_actionZoom_Out_triggered();

    void on_actionSymbols_triggered();

    void on_actionInsert_Tab_Space_triggered();

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

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void closeEvent (QCloseEvent *event);

    QJsonObject getAverageAccuracies(QJsonObject mainObj);

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

    bool isStringInFile(QString file_path, QString searchString);

    void dumpStringToFile(QString file_path, QString string);

    void highlight(CustomTextBrowser *b , QString input);

    QMap <QString, QString> getGlobalReplacementMapFromChecklistDialog(QVector <QString> replacedWords, QVector<int> *replaceInAllPages);

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

    void on_actionChange_Role_triggered();

    void bboxInsertion(QFile *f = nullptr);

    void finishedPdfCreation(int exitCode, QProcess::ExitStatus exitStatus);

    void SearchOnGoogle();

    void GoogleTranslation();

    void insertImageAction();

    void on_actionClone_Repository();

    void on_actionClose_project_triggered();

	void on_actionMerge_Cells_triggered();

    void on_actionSplit_Cell_triggered();

    void on_actionInsert_Bulleted_List_triggered();

    void on_actionInsert_Numbered_List_triggered();

    void insertList(QTextListFormat::Style styleIndex);

    void on_actionInsert_Equation_triggered();

    void on_actionEdit_Equation_triggered();

    void on_actionExit_triggered();

    void on_sanButton_toggled(bool checked);

    void on_hinButton_toggled(bool checked);

    void on_actionTwo_Column_triggered();

    void on_pushButton_3_clicked();

    void on_actionUser_Guide_triggered();

    void preprocessing();

    void on_actionCopy_Format_triggered();

    void on_actionPaste_Format_triggered();

    void on_actionUnderline_triggered();

    void on_pushButton_4_clicked();

    void on_actionFill_Table_triggered();

    void on_backward_Button_clicked();

    void on_forward_Button_clicked();

    void on_actionImport_and_Open_triggered();

    void on_actionImport_triggered();

    void on_actionEnter_manauly_triggered();



    void on_actionImport_2_triggered();


    void on_pushButton_5_clicked();

    void on_actionTable_2_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionSelect_All_triggered();

    void on_actionDelete_triggered();

    void on_actionDate_triggered();

    void on_actionLink_triggered();

    void on_actionUnderline_2_triggered();

    void on_actionIncrease_size_triggered();

    void on_actionDecrease_Size_triggered();

    void on_actionlower_case_triggered();

    void on_actionUPPER_CASE_triggered();

    void on_actionTitle_Case_triggered();

    void on_actionDelete_Table_triggered();

    void on_actionClear_Formatting_triggered();

public slots:
    void on_actionLoad_Next_Page_triggered();

    void on_actionLoad_Prev_Page_triggered();

    void LoadDocument(QFile * file, QString ext, QString name);

    void pdfPrintIsReady();

    void readOutputFromPdfPrint();

	void blockCountChanged(int);

    void authenticate();
    void login();
    void createTable();
    void e_d_features(bool value);

private:
    bool mExitStatus = false;
    QString mRole;
    QString saveRole;
    bool isVerifier;
    Ui::MainWindow *ui;
    Project mProject;
    QString mFilename;
    QString mFilenameImage;
    QString current_folder;
    QString currentTabPageName="";
    int currentTabIndex;
    CustomTextBrowser * curr_browser = nullptr;
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
    QProcess *mPrintPdfProcess;
    QMessageBox *tempMsgBox;

    CustomTextBrowser *TextBrowser;
    void createMenu();

	QCompleter *c = nullptr;
	QTextDocument *doc;

	int currentZoomLevel = 100;

	HandleBbox *handleBbox = nullptr;
	QVector<QPair<QString,QString> > bboxes;
	int blockCount = -1;
    GlobalReplaceDialog *currentGlobalReplaceDialog = nullptr;
    QOAuth2AuthorizationCodeFlow * google;
    void googleAuth();
    QSet<QString> dict_set1; //! Keep it available globally so that we need not to parse dictionary file at the time of saving logs.
    bool check();
    bool check_access();
    void cloud_save();
    bool verifier_save();
    int saved = 0;
    void autoSave();
    void messageTimer();
    bool initialSave = false;
    QAudioRecorder *m_audioRecorder = nullptr;
    QAudioProbe *m_probe = nullptr;
    QList<AudioLevel*> m_audioLevels;
    void speechToTextCall();
    bool import_flag = false;
    int flag_tab = 0;
};

#endif // MAINWINDOW_H
