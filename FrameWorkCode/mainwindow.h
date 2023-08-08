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
#include <QCompleter>
#include <QDirModel>
#include <QStringListModel>
#include <QModelIndex>
#include <QAbstractItemModel>
#include <QScrollBar>
#include "customtextbrowser.h"
#include "handlebbox.h"
#include <QMediaRecorder>
#include <QCalendarWidget>

#include <QProgressBar>



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

    void saveStatusChanged();

    void gotToken(const QString& token);

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    Project & GetProject() {
        return mProject;
    }

    bool setRole();

    bool exitStatus() {
        return mExitStatus;
    }

    int getCurrentTabIndex() {
        return currentTabIndex;
    }

    CustomTextBrowser * getCurrentBrowser() {
        return curr_browser;
    }

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

    void on_actionCheck_for_Updates_triggered(int arg = 2);

    void closeProgressBar();

    void setProgressBarPerc(int);

    void setProgressBarText(int);

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
    void insertImage(QImage img);

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

    void on_actionImage_triggered();

    void on_actionAbout_Udaan_PE_triggered();

    void on_actionIncrease_Indent_triggered(int left = 0, int right = 0);

    void on_actionDecrease_Indent_triggered();

    void on_actionIndentation_Options_triggered();
    void on_actionSpecial_Characters_triggered();
    void on_actionResize_Image_2_triggered();


    void on_actionWord_Count_triggered();

    void on_actionVoice_Typing_triggered();

    void getDate(QCalendarWidget *calendar);



    void on_actionTable_Border_Color_triggered();

    void on_actionCell_Padding_triggered();

    void processProgress(qint64 bytesReceived, qint64 bytesTotal, QProgressBar *pb, QLabel *labelProgress);

    void on_pushButton_6_clicked();

    //! Page Status -- Corrected || Verified || Marked For Review
    void on_corrected_clicked();
    void on_verified_clicked();
    void on_mark_review_clicked();
    void write_corrected_pages();
    void write_verified_pages();
    void read_corrected_pages();
    void read_verified_pages();
    void read_review_pages();
    void write_review_pages();
    void read_recorrected_pages();
    void write_recorrected_pages();
    void pageStatusHandler();

    void on_actionClear_Menu_triggered();

    void on_actionJustified_triggered();

    void on_actionColumn_Width_triggered();


    void on_actionEnable_Disable_Suggestions_triggered();

    //! Bulleted List Options
    void on_actionDecimal_triggered();
    void on_actionUpper_Roman_triggered();
    void on_actionLower_Alpha_triggered();
    void on_actionUpper_Alpha_triggered();
    void on_actionLower_Roman_triggered();
    void on_actionDisc_triggered();
    void on_actionCircle_triggered();
    void on_actionSquare_triggered();

    void on_pushButton_7_clicked();

    void on_actionPaste_without_Format_triggered();

    void on_actionClear_Settings_triggered();

    void on_actionFullScreen_triggered();

    void on_pushButton_8_clicked();

    void setSaveStatus();

    void on_actionRecentProject_triggered();

    //! Handling Comments
    void on_actionComment_triggered();
    void highlightComment(bool deleteCommentFlag = false);
    void writeCommentLogs(QString word, QString comment);
   // void showComments();
    void deleteComment();
    void readCommentLogs();
    void sendComment(QString str);


    void on_actionUndo_Two_Column_view_triggered();

    void on_hinButton_clicked();

    void on_sanButton_clicked();

    void on_copyToVerifier_clicked();

    void on_actionTitle_triggered();

    void on_actionSubtitle_triggered();

    void on_actionHeading_1_triggered();

    void on_actionHeading_2_triggered();

    void on_actionHeading_3_triggered();

    void on_actionHeading_4_triggered();

    void on_actionHeading_5_triggered();

    void on_actionHeading_6_triggered();

    void on_actionNormal_Text_triggered();

<<<<<<< HEAD
    void on_actionApply_Title_triggered();

    void on_actionUpdate_Title_to_match_triggered();
=======
    void on_actionInsert_Line_Graph_triggered();

    void on_actionInsert_Histogram_triggered();

    void insertGraph(const QString& graphFilePath, bool& status);

    void on_actionBar_Plot_triggered();
    void barPlotManual();
    void barPlotCsv();

    void on_actionScatter_Plot_triggered();
    void scatterPlotManual();
    void scatterPlotCsv();

    void on_actionBox_Plot_triggered();
    void boxPlotManual();
    void boxPlotCsv();

    void on_actionInsert_Pie_Chart_triggered();
>>>>>>> 207d7c1fa1ab8d81ebf8807daa4a66543b458b11

public slots:
    void on_actionLoad_Next_Page_triggered();

    void on_actionLoad_Prev_Page_triggered();

    void LoadDocument(QFile * file, QString ext, QString name);

    void pdfPrintIsReady();

    void readOutputFromPdfPrint();

	void blockCountChanged(int);

    void login();

    void createTable();

    void e_d_features(bool value);

    void update_tool(QString latestVersion);

    void changeColumnWidth();

    void setWordCount(int value);
    void setPageCount(int value);
    void setTotalWords(int value);
    void showWordCount();



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
    QSet<QString> dict_set1; //! Keep it available globally so that we need not to parse dictionary file at the time of saving logs.
    bool check();
    bool check_access();
    void cloud_save();
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

    QVector <QString> changedWords;
    QByteArray m_data;
    std::string m_user, m_pass;
    //Storing the status of the pages :-> Corrected || Verified
    QMap<QString,int>correct;
    QMap<QString,int>verify;
    QMap<QString,int>recorrect;
    QString currentFile = "";
    QMap<QString,int>markForReview;

    int presentWidth;
    int currentTablePosition;

    QString check_for_updates();
    bool onStart = true;
    QString m_update_path = "";

    int wordCount = 0;
    int pageCount = 0;
    int totalWord = 0;

    QString currentCommentWord;
    QMap<QString,QMap<QString,QString>> corrector_comment, verifier_comment;

};

#endif // MAINWINDOW_H
