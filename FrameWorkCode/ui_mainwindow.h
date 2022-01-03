/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_Project;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionNew;
    QAction *actionSpell_Check;
    QAction *actionLoad_Next_Page;
    QAction *actionLoad_Prev_Page;
    QAction *actionLoadGDocPage;
    QAction *actionToDevanagari;
    QAction *actionLoadData;
    QAction *actionLoadDict;
    QAction *actionLoadOCRWords;
    QAction *actionLoadDomain;
    QAction *actionLoadSubPS;
    QAction *actionLoadConfusions;
    QAction *actionSugg;
    QAction *actionCreateBest2OCR;
    QAction *actionToSlp1;
    QAction *actionCreateSuggestionLog;
    QAction *actionCreateSuggestionLogNearestPriority;
    QAction *actionErrorDetectionRep;
    QAction *actionErrorDetectWithoutAdaptation;
    QAction *actionCPair;
    QAction *actionToSlp1_2;
    QAction *actionToDev;
    QAction *actionExtractDev;
    QAction *actionPrimarySecOCRPair;
    QAction *actionCPairIEROcrVsCorrect;
    QAction *actionEditDistRep;
    QAction *actionConfusionFreqHist;
    QAction *actionCPairGEROcrVsCorrect;
    QAction *actionFilterOutGT50EditDisPairs;
    QAction *actionErrorDetectionRepUniq;
    QAction *actionAllFontProperties;
    QAction *actionBold;
    QAction *actionUnBold;
    QAction *actionLeftAlign;
    QAction *actionRightAlign;
    QAction *actionCentreAlign;
    QAction *actionJusitfiedAlign;
    QAction *actionAccuracyLog;
    QAction *actionView_File_Hierarchy;
    QAction *actionTurn_In;
    QAction *actionFetch;
    QAction *actionCompare_Verifier;
    QAction *actionCompare_Corrector;
    QAction *actionAverage_Accuracy;
    QAction *actionView_Comments;
    QAction *actionCommit;
    QAction *actionFetch_2;
    QAction *actionPush;
    QAction *actionVerifier_Turn_In;
    QAction *actionHighlight;
    QAction *actionZoom_In;
    QAction *actionZoom_Out;
    QAction *actionSymbols;
    QAction *actionSuperscript;
    QAction *actionSubscript;
    QAction *actionInsert_Horizontal_Line;
    QAction *actionFontBlack;
    QAction *actionLineSpace;
    QAction *actionViewAverageAccuracies;
    QAction *actionInsert_Tab_Space;
    QAction *actionAdd_Image;
    QAction *actionResize_Image;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionNew_Project;
    QAction *actionInsert_Table_2;
    QAction *actionInsert_Columnleft;
    QAction *actionInsert_Columnright;
    QAction *actionInsert_Rowabove;
    QAction *actionInsert_Rowbelow;
    QAction *actionRemove_Column;
    QAction *actionRemove_Row;
    QAction *actionItalic;
    QAction *actionNonitalic;
    QAction *actionSave_All;
    QAction *actionFind_and_Replace;
    QAction *actionas_PDF;
    QAction *actionGet_Help;
    QAction *actionTutorial;
    QAction *actionLinux;
    QAction *actionWindows;
    QAction *actionas_Doc;
    QAction *actionSanskrit;
    QAction *actionHindi;
    QAction *actionEnglish;
    QAction *actionShortcut_Guide;
    QAction *action1;
    QAction *actionSanskrit_2;
    QAction *actionUndo_Global_Replace;
    QAction *actionUpload;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *viewComments;
    QPushButton *compareCorrectorOutput;
    QPushButton *compareVerifierOutput;
    QSplitter *splitter;
    QSplitter *splitter_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *hinButton;
    QPushButton *sanButton;
    QTextEdit *textEdit;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QTreeView *treeView;
    QTextEdit *textEdit_dict;
    QTabWidget *tabWidget_2;
    QWidget *tab_5;
    QGridLayout *gridLayout_4;
    QTextBrowser *textBrowser;
    QGraphicsView *graphicsView;
    QHBoxLayout *Buttom_Slider;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *zoom_Out_Button;
    QSlider *horizontalSlider;
    QPushButton *zoom_In_Button;
    QLabel *zoom_level_value;
    QMenuBar *menuBar;
    QMenu *menuCreateReports;
    QMenu *menuFontAndLayout;
    QMenu *menuTables;
    QMenu *menuGit;
    QMenu *menuEdit;
    QMenu *menuDownload;
    QMenu *menuHelp;
    QMenu *menuInstallation_Guide;
    QMenu *menuSelectLanguage;
    QMenu *menuOCR_Correction_Window;
    QMenu *menuRecent_Project;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1366, 1190);
        QFont font;
        font.setFamily(QStringLiteral("WorkSans,Sans"));
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        MainWindow->setFont(font);
        MainWindow->setMouseTracking(true);
        MainWindow->setStyleSheet(QLatin1String("background:rgb(32, 33, 72); \n"
"color:white;\n"
"\n"
""));
        actionOpen_Project = new QAction(MainWindow);
        actionOpen_Project->setObjectName(QStringLiteral("actionOpen_Project"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/Resources/open file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_Project->setIcon(icon);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/Resources/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon1);
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Images/Resources/save as.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_As->setIcon(icon2);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Images/Resources/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon3);
        actionNew->setVisible(true);
        actionSpell_Check = new QAction(MainWindow);
        actionSpell_Check->setObjectName(QStringLiteral("actionSpell_Check"));
        actionSpell_Check->setEnabled(true);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Images/Resources/spell check.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QStringLiteral(":/Images/spellcheck.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSpell_Check->setIcon(icon4);
        actionSpell_Check->setVisible(true);
        actionLoad_Next_Page = new QAction(MainWindow);
        actionLoad_Next_Page->setObjectName(QStringLiteral("actionLoad_Next_Page"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Images/Resources/preivious page.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QStringLiteral(":/Images/next-page.png"), QSize(), QIcon::Normal, QIcon::On);
        actionLoad_Next_Page->setIcon(icon5);
        actionLoad_Prev_Page = new QAction(MainWindow);
        actionLoad_Prev_Page->setObjectName(QStringLiteral("actionLoad_Prev_Page"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Images/Resources/next page.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon6.addFile(QStringLiteral(":/Images/previous-page.png"), QSize(), QIcon::Normal, QIcon::On);
        actionLoad_Prev_Page->setIcon(icon6);
        actionLoadGDocPage = new QAction(MainWindow);
        actionLoadGDocPage->setObjectName(QStringLiteral("actionLoadGDocPage"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Images/Resources/save load p words.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoadGDocPage->setIcon(icon7);
        actionToDevanagari = new QAction(MainWindow);
        actionToDevanagari->setObjectName(QStringLiteral("actionToDevanagari"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/Images/Resources/english to hindi.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon8.addFile(QStringLiteral(":/Images/toDevangari.png"), QSize(), QIcon::Normal, QIcon::On);
        actionToDevanagari->setIcon(icon8);
        actionLoadData = new QAction(MainWindow);
        actionLoadData->setObjectName(QStringLiteral("actionLoadData"));
        actionLoadData->setEnabled(true);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/Images/Resources/load data.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon9.addFile(QStringLiteral(":/Images/LoadData.png"), QSize(), QIcon::Normal, QIcon::On);
        actionLoadData->setIcon(icon9);
        actionLoadData->setVisible(true);
        actionLoadDict = new QAction(MainWindow);
        actionLoadDict->setObjectName(QStringLiteral("actionLoadDict"));
        actionLoadOCRWords = new QAction(MainWindow);
        actionLoadOCRWords->setObjectName(QStringLiteral("actionLoadOCRWords"));
        actionLoadDomain = new QAction(MainWindow);
        actionLoadDomain->setObjectName(QStringLiteral("actionLoadDomain"));
        actionLoadSubPS = new QAction(MainWindow);
        actionLoadSubPS->setObjectName(QStringLiteral("actionLoadSubPS"));
        actionLoadConfusions = new QAction(MainWindow);
        actionLoadConfusions->setObjectName(QStringLiteral("actionLoadConfusions"));
        actionSugg = new QAction(MainWindow);
        actionSugg->setObjectName(QStringLiteral("actionSugg"));
        actionCreateBest2OCR = new QAction(MainWindow);
        actionCreateBest2OCR->setObjectName(QStringLiteral("actionCreateBest2OCR"));
        actionToSlp1 = new QAction(MainWindow);
        actionToSlp1->setObjectName(QStringLiteral("actionToSlp1"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/Images/Resources/tospl.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionToSlp1->setIcon(icon10);
        actionCreateSuggestionLog = new QAction(MainWindow);
        actionCreateSuggestionLog->setObjectName(QStringLiteral("actionCreateSuggestionLog"));
        actionCreateSuggestionLogNearestPriority = new QAction(MainWindow);
        actionCreateSuggestionLogNearestPriority->setObjectName(QStringLiteral("actionCreateSuggestionLogNearestPriority"));
        actionErrorDetectionRep = new QAction(MainWindow);
        actionErrorDetectionRep->setObjectName(QStringLiteral("actionErrorDetectionRep"));
        actionErrorDetectWithoutAdaptation = new QAction(MainWindow);
        actionErrorDetectWithoutAdaptation->setObjectName(QStringLiteral("actionErrorDetectWithoutAdaptation"));
        actionCPair = new QAction(MainWindow);
        actionCPair->setObjectName(QStringLiteral("actionCPair"));
        actionToSlp1_2 = new QAction(MainWindow);
        actionToSlp1_2->setObjectName(QStringLiteral("actionToSlp1_2"));
        actionToDev = new QAction(MainWindow);
        actionToDev->setObjectName(QStringLiteral("actionToDev"));
        actionExtractDev = new QAction(MainWindow);
        actionExtractDev->setObjectName(QStringLiteral("actionExtractDev"));
        actionPrimarySecOCRPair = new QAction(MainWindow);
        actionPrimarySecOCRPair->setObjectName(QStringLiteral("actionPrimarySecOCRPair"));
        actionCPairIEROcrVsCorrect = new QAction(MainWindow);
        actionCPairIEROcrVsCorrect->setObjectName(QStringLiteral("actionCPairIEROcrVsCorrect"));
        actionEditDistRep = new QAction(MainWindow);
        actionEditDistRep->setObjectName(QStringLiteral("actionEditDistRep"));
        actionConfusionFreqHist = new QAction(MainWindow);
        actionConfusionFreqHist->setObjectName(QStringLiteral("actionConfusionFreqHist"));
        actionCPairGEROcrVsCorrect = new QAction(MainWindow);
        actionCPairGEROcrVsCorrect->setObjectName(QStringLiteral("actionCPairGEROcrVsCorrect"));
        actionFilterOutGT50EditDisPairs = new QAction(MainWindow);
        actionFilterOutGT50EditDisPairs->setObjectName(QStringLiteral("actionFilterOutGT50EditDisPairs"));
        actionErrorDetectionRepUniq = new QAction(MainWindow);
        actionErrorDetectionRepUniq->setObjectName(QStringLiteral("actionErrorDetectionRepUniq"));
        actionAllFontProperties = new QAction(MainWindow);
        actionAllFontProperties->setObjectName(QStringLiteral("actionAllFontProperties"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/Images/Resources/all font properties 2.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon11.addFile(QStringLiteral(":/Images/AllFont.png"), QSize(), QIcon::Normal, QIcon::On);
        actionAllFontProperties->setIcon(icon11);
        actionBold = new QAction(MainWindow);
        actionBold->setObjectName(QStringLiteral("actionBold"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/Images/Resources/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBold->setIcon(icon12);
        actionUnBold = new QAction(MainWindow);
        actionUnBold->setObjectName(QStringLiteral("actionUnBold"));
        actionUnBold->setEnabled(false);
        actionUnBold->setVisible(false);
        actionLeftAlign = new QAction(MainWindow);
        actionLeftAlign->setObjectName(QStringLiteral("actionLeftAlign"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/Images/Resources/allign left.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon13.addFile(QStringLiteral(":/Images/AlignLeft.png"), QSize(), QIcon::Normal, QIcon::On);
        actionLeftAlign->setIcon(icon13);
        actionRightAlign = new QAction(MainWindow);
        actionRightAlign->setObjectName(QStringLiteral("actionRightAlign"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/Images/Resources/align right.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon14.addFile(QStringLiteral(":/Images/AlignCenter.png"), QSize(), QIcon::Normal, QIcon::On);
        actionRightAlign->setIcon(icon14);
        actionCentreAlign = new QAction(MainWindow);
        actionCentreAlign->setObjectName(QStringLiteral("actionCentreAlign"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/Images/Resources/align center.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon15.addFile(QStringLiteral(":/Images/AlignCenter.png"), QSize(), QIcon::Normal, QIcon::On);
        actionCentreAlign->setIcon(icon15);
        actionJusitfiedAlign = new QAction(MainWindow);
        actionJusitfiedAlign->setObjectName(QStringLiteral("actionJusitfiedAlign"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/Images/Resources/align para.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon16.addFile(QStringLiteral(":/Images/JustifiedAlign.png"), QSize(), QIcon::Normal, QIcon::On);
        actionJusitfiedAlign->setIcon(icon16);
        actionAccuracyLog = new QAction(MainWindow);
        actionAccuracyLog->setObjectName(QStringLiteral("actionAccuracyLog"));
        actionView_File_Hierarchy = new QAction(MainWindow);
        actionView_File_Hierarchy->setObjectName(QStringLiteral("actionView_File_Hierarchy"));
        actionTurn_In = new QAction(MainWindow);
        actionTurn_In->setObjectName(QStringLiteral("actionTurn_In"));
        actionFetch = new QAction(MainWindow);
        actionFetch->setObjectName(QStringLiteral("actionFetch"));
        actionCompare_Verifier = new QAction(MainWindow);
        actionCompare_Verifier->setObjectName(QStringLiteral("actionCompare_Verifier"));
        actionCompare_Corrector = new QAction(MainWindow);
        actionCompare_Corrector->setObjectName(QStringLiteral("actionCompare_Corrector"));
        actionAverage_Accuracy = new QAction(MainWindow);
        actionAverage_Accuracy->setObjectName(QStringLiteral("actionAverage_Accuracy"));
        actionView_Comments = new QAction(MainWindow);
        actionView_Comments->setObjectName(QStringLiteral("actionView_Comments"));
        actionCommit = new QAction(MainWindow);
        actionCommit->setObjectName(QStringLiteral("actionCommit"));
        actionFetch_2 = new QAction(MainWindow);
        actionFetch_2->setObjectName(QStringLiteral("actionFetch_2"));
        actionFetch_2->setEnabled(false);
        actionPush = new QAction(MainWindow);
        actionPush->setObjectName(QStringLiteral("actionPush"));
        actionPush->setEnabled(false);
        actionVerifier_Turn_In = new QAction(MainWindow);
        actionVerifier_Turn_In->setObjectName(QStringLiteral("actionVerifier_Turn_In"));
        actionHighlight = new QAction(MainWindow);
        actionHighlight->setObjectName(QStringLiteral("actionHighlight"));
        actionHighlight->setEnabled(true);
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/Images/Resources/highlighter.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon17.addFile(QStringLiteral(":/Images/highlight-icon.png"), QSize(), QIcon::Normal, QIcon::On);
        actionHighlight->setIcon(icon17);
        actionHighlight->setVisible(true);
        actionZoom_In = new QAction(MainWindow);
        actionZoom_In->setObjectName(QStringLiteral("actionZoom_In"));
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/Images/Resources/zoom in.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_In->setIcon(icon18);
        actionZoom_Out = new QAction(MainWindow);
        actionZoom_Out->setObjectName(QStringLiteral("actionZoom_Out"));
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/Images/Resources/zoom out.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_Out->setIcon(icon19);
        actionSymbols = new QAction(MainWindow);
        actionSymbols->setObjectName(QStringLiteral("actionSymbols"));
        QIcon icon20;
        icon20.addFile(QStringLiteral(":/Images/Resources/spl symbol.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon20.addFile(QStringLiteral(":/Images/symbols.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSymbols->setIcon(icon20);
        actionSuperscript = new QAction(MainWindow);
        actionSuperscript->setObjectName(QStringLiteral("actionSuperscript"));
        QIcon icon21;
        icon21.addFile(QStringLiteral(":/Images/Resources/superscrpt.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSuperscript->setIcon(icon21);
        actionSubscript = new QAction(MainWindow);
        actionSubscript->setObjectName(QStringLiteral("actionSubscript"));
        QIcon icon22;
        icon22.addFile(QStringLiteral(":/Images/Resources/subscpt.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSubscript->setIcon(icon22);
        actionInsert_Horizontal_Line = new QAction(MainWindow);
        actionInsert_Horizontal_Line->setObjectName(QStringLiteral("actionInsert_Horizontal_Line"));
        QIcon icon23;
        icon23.addFile(QStringLiteral(":/Images/Resources/underline  2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInsert_Horizontal_Line->setIcon(icon23);
        actionFontBlack = new QAction(MainWindow);
        actionFontBlack->setObjectName(QStringLiteral("actionFontBlack"));
        QIcon icon24;
        icon24.addFile(QStringLiteral(":/Images/Resources/font black.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFontBlack->setIcon(icon24);
        actionLineSpace = new QAction(MainWindow);
        actionLineSpace->setObjectName(QStringLiteral("actionLineSpace"));
        actionLineSpace->setEnabled(false);
        QIcon icon25;
        icon25.addFile(QStringLiteral(":/Images/linespacing.png"), QSize(), QIcon::Normal, QIcon::On);
        actionLineSpace->setIcon(icon25);
        actionViewAverageAccuracies = new QAction(MainWindow);
        actionViewAverageAccuracies->setObjectName(QStringLiteral("actionViewAverageAccuracies"));
        actionInsert_Tab_Space = new QAction(MainWindow);
        actionInsert_Tab_Space->setObjectName(QStringLiteral("actionInsert_Tab_Space"));
        actionAdd_Image = new QAction(MainWindow);
        actionAdd_Image->setObjectName(QStringLiteral("actionAdd_Image"));
        actionResize_Image = new QAction(MainWindow);
        actionResize_Image->setObjectName(QStringLiteral("actionResize_Image"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        QIcon icon26;
        icon26.addFile(QStringLiteral(":/Images/Resources/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon26.addFile(QStringLiteral(":/Images/undo.png"), QSize(), QIcon::Normal, QIcon::On);
        actionUndo->setIcon(icon26);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        QIcon icon27;
        icon27.addFile(QStringLiteral(":/Images/Resources/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon27.addFile(QStringLiteral(":/Images/redo.png"), QSize(), QIcon::Normal, QIcon::On);
        actionRedo->setIcon(icon27);
        actionNew_Project = new QAction(MainWindow);
        actionNew_Project->setObjectName(QStringLiteral("actionNew_Project"));
        actionNew_Project->setVisible(false);
        actionInsert_Table_2 = new QAction(MainWindow);
        actionInsert_Table_2->setObjectName(QStringLiteral("actionInsert_Table_2"));
        actionInsert_Columnleft = new QAction(MainWindow);
        actionInsert_Columnleft->setObjectName(QStringLiteral("actionInsert_Columnleft"));
        actionInsert_Columnright = new QAction(MainWindow);
        actionInsert_Columnright->setObjectName(QStringLiteral("actionInsert_Columnright"));
        actionInsert_Rowabove = new QAction(MainWindow);
        actionInsert_Rowabove->setObjectName(QStringLiteral("actionInsert_Rowabove"));
        actionInsert_Rowbelow = new QAction(MainWindow);
        actionInsert_Rowbelow->setObjectName(QStringLiteral("actionInsert_Rowbelow"));
        actionRemove_Column = new QAction(MainWindow);
        actionRemove_Column->setObjectName(QStringLiteral("actionRemove_Column"));
        actionRemove_Row = new QAction(MainWindow);
        actionRemove_Row->setObjectName(QStringLiteral("actionRemove_Row"));
        actionItalic = new QAction(MainWindow);
        actionItalic->setObjectName(QStringLiteral("actionItalic"));
        QIcon icon28;
        icon28.addFile(QStringLiteral(":/Images/Resources/ittalic.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionItalic->setIcon(icon28);
        actionNonitalic = new QAction(MainWindow);
        actionNonitalic->setObjectName(QStringLiteral("actionNonitalic"));
        actionSave_All = new QAction(MainWindow);
        actionSave_All->setObjectName(QStringLiteral("actionSave_All"));
        actionFind_and_Replace = new QAction(MainWindow);
        actionFind_and_Replace->setObjectName(QStringLiteral("actionFind_and_Replace"));
        QIcon icon29;
        icon29.addFile(QStringLiteral(":/Images/Resources/find 1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFind_and_Replace->setIcon(icon29);
        actionas_PDF = new QAction(MainWindow);
        actionas_PDF->setObjectName(QStringLiteral("actionas_PDF"));
        actionGet_Help = new QAction(MainWindow);
        actionGet_Help->setObjectName(QStringLiteral("actionGet_Help"));
        QIcon icon30;
        icon30.addFile(QStringLiteral(":/Images/Resources/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGet_Help->setIcon(icon30);
        actionTutorial = new QAction(MainWindow);
        actionTutorial->setObjectName(QStringLiteral("actionTutorial"));
        actionLinux = new QAction(MainWindow);
        actionLinux->setObjectName(QStringLiteral("actionLinux"));
        actionWindows = new QAction(MainWindow);
        actionWindows->setObjectName(QStringLiteral("actionWindows"));
        actionas_Doc = new QAction(MainWindow);
        actionas_Doc->setObjectName(QStringLiteral("actionas_Doc"));
        actionSanskrit = new QAction(MainWindow);
        actionSanskrit->setObjectName(QStringLiteral("actionSanskrit"));
        QFont font1;
        actionSanskrit->setFont(font1);
        actionHindi = new QAction(MainWindow);
        actionHindi->setObjectName(QStringLiteral("actionHindi"));
        actionEnglish = new QAction(MainWindow);
        actionEnglish->setObjectName(QStringLiteral("actionEnglish"));
        actionShortcut_Guide = new QAction(MainWindow);
        actionShortcut_Guide->setObjectName(QStringLiteral("actionShortcut_Guide"));
        action1 = new QAction(MainWindow);
        action1->setObjectName(QStringLiteral("action1"));
        actionSanskrit_2 = new QAction(MainWindow);
        actionSanskrit_2->setObjectName(QStringLiteral("actionSanskrit_2"));
        actionUndo_Global_Replace = new QAction(MainWindow);
        actionUndo_Global_Replace->setObjectName(QStringLiteral("actionUndo_Global_Replace"));
        actionUpload = new QAction(MainWindow);
        actionUpload->setObjectName(QStringLiteral("actionUpload"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral("mainToolBar{background:rgb(143, 89, 2)}"));
        verticalLayout_5 = new QVBoxLayout(centralWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton{background-color:rgb(227, 228, 228);border:0px; color: rgb(32, 33, 72); height:26.96px; width: 113.5px; padding-top:1px; border-radius:4.8px; padding-left:1.3px; selection-color: rgb(32, 33, 72); selection-background-color: rgb(136, 138, 133);\n"
"} QPushButton:checked{background-color: rgb(136, 138, 133);} QPushButton:pressed {background-color: rgb(136, 138, 133);}"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QStringLiteral("QPushButton{background-color:rgb(227, 228, 228);border:0px; color: rgb(32, 33, 72); height:26.96px; width: 109.11px; padding-top:1px; border-radius:4.8px; padding-left:1.3px;}QPushButton:checked{background-color: rgb(136, 138, 133);}QPushButton:pressed {background-color: rgb(136, 138, 133);}"));

        horizontalLayout->addWidget(pushButton);

        viewComments = new QPushButton(centralWidget);
        viewComments->setObjectName(QStringLiteral("viewComments"));
        viewComments->setStyleSheet(QLatin1String("QPushButton{background-color:rgb(227, 228, 228);border:0px; color: rgb(32, 33, 72); height:26.96px; width: 176.03px; padding-top:1px; border-radius:4.8px; padding-left:1.3px;} QPushButton:checked{background-color: rgb(136, 138, 133);}QPushButton:pressed {background-color: rgb(136, 138, 133);}\n"
""));

        horizontalLayout->addWidget(viewComments);

        compareCorrectorOutput = new QPushButton(centralWidget);
        compareCorrectorOutput->setObjectName(QStringLiteral("compareCorrectorOutput"));
        compareCorrectorOutput->setStyleSheet(QLatin1String("QPushButton{background-color:rgb(227, 228, 228);border:0px; color: rgb(32, 33, 72); height:26.96px; width: 210.62px; padding-top:1px; border-radius:4.8px; padding-left:1.3px;} QPushButton:checked{background-color: rgb(136, 138, 133);}QPushButton:pressed {background-color: rgb(136, 138, 133);}\n"
""));

        horizontalLayout->addWidget(compareCorrectorOutput);

        compareVerifierOutput = new QPushButton(centralWidget);
        compareVerifierOutput->setObjectName(QStringLiteral("compareVerifierOutput"));
        compareVerifierOutput->setMinimumSize(QSize(0, 0));
        compareVerifierOutput->setStyleSheet(QLatin1String("QPushButton{background-color:rgb(227, 228, 228);border:0px; color: rgb(32, 33, 72); height:26.96px; width: 210.62px; padding-top:1px; border-radius:4.8px; padding-left:1.3px;}QPushButton:checked{background-color: rgb(136, 138, 133);}QPushButton:pressed {background-color: rgb(136, 138, 133);}\n"
""));

        horizontalLayout->addWidget(compareVerifierOutput);


        verticalLayout_4->addLayout(horizontalLayout);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setStyleSheet(QLatin1String("QSplitter{\n"
"QGraphicsView{background-color:white;}\n"
"}\n"
"QGraphicsView{background-color:white;}\n"
"QScrollBar:vertical { \n"
"                                                border: none;\n"
"                                                background: white;\n"
"                                                 width: 9.81px;\n"
"                                            }\n"
"QScrollBar::handle:vertical { \n"
"                                                background-color:  rgba(1, 22, 51, 0.5);\n"
"                                                border-radius:4.905px;\n"
"														border: 0px solid red; \n"
"													\n"
"														\n"
"                                            }\n"
"QScrollBar::add-line:vertical {       \n"
"                            height: 0px;\n"
"                            subcontrol-position: bottom; \n"
"                            subcontrol-origin: margin; \n"
"								\n"
"                        } \n"
"QScrollBar::sub-line:vertical { \n"
"             "
                        "               height: 0 px; \n"
"                            subcontrol-position: top; \n"
"                            subcontrol-origin: margin; \n"
"                        }\n"
"\n"
"QScrollBar:horizontal { \n"
"                                                border: none;\n"
"                                                background: white;\n"
" 													   \n"
"                                             		\n"
"                                            }\n"
"QScrollBar::handle:horizontal { \n"
"                                                background-color:  rgba(1, 22, 51, 0.5);\n"
"														border: 0px solid red; \n"
"														border-radius:4.905px;\n"
"														\n"
"                                            }\n"
"QScrollBar::add-line:horizontal {       \n"
"                            height: 0px;\n"
"                            subcontrol-position: bottom; \n"
"                            subcontrol-origin: margin; \n"
"								\n"
"                        } \n"
"QScrollBa"
                        "r::sub-line:horizontal { \n"
"                            height: 0 px; \n"
"                            subcontrol-position: top; \n"
"                            subcontrol-origin: margin; \n"
"                        }\n"
"\n"
""));
        splitter->setOrientation(Qt::Horizontal);
        splitter_2 = new QSplitter(splitter);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        tabWidget = new QTabWidget(splitter_2);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(0, 0));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tabWidget->setStyleSheet(QLatin1String("QTabBar::tab {\n"
"	border-radius: 0px;\n"
"	padding: 5px 15px;\n"
"	color: #1F2046;\n"
"\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"	background-color: #BCBDBD;\n"
"}\n"
"\n"
"QTabBar::tab:!selected {\n"
"	background-color: #E3E4E4;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"	top: -1px;\n"
"	bottom: 0px;\n"
"	border: 0px solid #BCBDBD;\n"
"	padding: 0px;\n"
"	margin: -10px -9px -10px -9px;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        hinButton = new QPushButton(tab);
        hinButton->setObjectName(QStringLiteral("hinButton"));
        hinButton->setMaximumSize(QSize(16777215, 16777215));
        hinButton->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color:rgb(227, 228, 228);\n"
"border:0px;\n"
"color: rgb(32, 33, 72);\n"
"height:26.96px;\n"
"width: 113.5px; \n"
"padding-top:1px; \n"
"border-radius:4.8px; \n"
"padding-left:1.3px; \n"
"selection-color: rgb(32, 33, 72);\n"
" selection-background-color: rgb(136, 138, 133);\n"
"margin-top: 5px;\n"
"} \n"
"QPushButton:checked{\n"
"background-color: rgb(136, 138, 133);\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgb(136, 138, 133);\n"
"}"));
        hinButton->setCheckable(true);

        horizontalLayout_2->addWidget(hinButton);

        sanButton = new QPushButton(tab);
        sanButton->setObjectName(QStringLiteral("sanButton"));
        sanButton->setMaximumSize(QSize(16777215, 16777215));
        sanButton->setStyleSheet(QLatin1String("QPushButton{background-color:rgb(227, 228, 228);border:0px; color: rgb(32, 33, 72); width: 113.5px;height:26.96px; padding-top:1px; border-radius:4.8px; padding-left:1.3px; selection-color: rgb(32, 33, 72); selection-background-color: rgb(136, 138, 133); margin-top: 5px;\n"
"} QPushButton:checked{background-color: rgb(136, 138, 133);} QPushButton:pressed {background-color: rgb(136, 138, 133);}"));
        sanButton->setCheckable(true);
        sanButton->setChecked(false);

        horizontalLayout_2->addWidget(sanButton);


        verticalLayout->addLayout(horizontalLayout_2);

        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setMinimumSize(QSize(0, 0));
        textEdit->setMaximumSize(QSize(16777215, 16777215));
        textEdit->setFont(font);
        textEdit->setStyleSheet(QLatin1String("QTextEdit{\n"
"	color:rgb(32, 33, 72);\n"
"\n"
"	background-color:white;\n"
"}\n"
"QScrollBar:vertical { \n"
"                                                border: none;\n"
"                                                background: white;\n"
"                                             \n"
"                                            }\n"
"QScrollBar::handle:vertical { \n"
"                                                background-color:  rgba(1, 22, 51, 0.5);\n"
"                                                min-height: 273.41px;\n"
"														border: 0px solid red; \n"
"														border-radius:4.905px;\n"
"                                            }\n"
"QScrollBar::add-line:vertical {       \n"
"                            height: 0px;\n"
"                            subcontrol-position: bottom; \n"
"                            subcontrol-origin: margin; \n"
"								\n"
"                        } \n"
"QScrollBar::sub-line:vertical { \n"
"                            height: 0 px; \n"
"     "
                        "                       subcontrol-position: top; \n"
"                            subcontrol-origin: margin; \n"
"                        }\n"
""));
        textEdit->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);


        verticalLayout_2->addLayout(verticalLayout);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        treeView = new QTreeView(tab_2);
        treeView->setObjectName(QStringLiteral("treeView"));
        sizePolicy.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy);
        treeView->setMinimumSize(QSize(0, 0));
        treeView->setMaximumSize(QSize(16777215, 16777215));
        treeView->setStyleSheet(QLatin1String("#treeView {\n"
"	color:rgb(32, 33, 72);\n"
"	border: 5px solid #BCBDBD;\n"
"	background-color:white;\n"
"	margin: 0px;\n"
"}\n"
"\n"
"QHeaderView {\n"
"	background-color: #ffffff;\n"
"}\n"
"\n"
"\n"
"QHeaderView::section {\n"
"	background-color: #ffffff;\n"
"	color: #202148;\n"
"	font-size: 15px;\n"
"	line-height: 18px;\n"
"	border: none;\n"
"	margin: 11px 242px 13px 20px;\n"
"}\n"
"\n"
"QTreeView::item {\n"
"	padding: 12px 100px 12px 17px;\n"
"	border: 0.5px solid #202148;\n"
"	color: #202148;\n"
"	font-size: 15px;\n"
"}\n"
"\n"
"QTreeView::branch {\n"
"    background-color: white;\n"
"}\n"
"\n"
"QTreeView::item:selected{\n"
"    background: #0267d4;\n"
"	color: #ffffff;\n"
"}\n"
"\n"
"QTreeView::branch:open:has-children:!has-siblings,\n"
"QTreeView::branch:open:has-children:has-siblings {\n"
"    image: url(\":/Images/Resources/stylesheet-branch-open.png\");\n"
"}\n"
"\n"
"QTreeView::branch:has-children:!has-siblings:closed,\n"
"QTreeView::branch:closed:has-children:has-siblings {\n"
"    image: url(\":/Imag"
                        "es/Resources/stylesheet-branch-closed.png\");\n"
"}\n"
"QScrollBar:vertical { \n"
"                                                border: none;\n"
"                                                background: white;\n"
"                                             \n"
"                                            }\n"
"QScrollBar::handle:vertical { \n"
"                                                background-color:  rgba(1, 22, 51, 0.5);\n"
"                                                min-height: 273.41px;\n"
"														border: 0px solid red; \n"
"														border-radius:4.905px;\n"
"                                            }\n"
"QScrollBar::add-line:vertical {       \n"
"                            height: 0px;\n"
"                            subcontrol-position: bottom; \n"
"                            subcontrol-origin: margin; \n"
"								\n"
"                        } \n"
"QScrollBar::sub-line:vertical { \n"
"                            height: 0 px; \n"
"                            subc"
                        "ontrol-position: top; \n"
"                            subcontrol-origin: margin; \n"
"                        }\n"
""));

        verticalLayout_3->addWidget(treeView);

        tabWidget->addTab(tab_2, QString());
        splitter_2->addWidget(tabWidget);
        textEdit_dict = new QTextEdit(splitter_2);
        textEdit_dict->setObjectName(QStringLiteral("textEdit_dict"));
        textEdit_dict->setStyleSheet(QLatin1String("QTextEdit{\n"
"color:#18182F;\n"
"	border: 5px solid #BCBDBD;\n"
"	background-color:white;\n"
"}\n"
"QScrollBar:vertical { \n"
"                                                border: none;\n"
"                                                background: white;\n"
"                                                \n"
"                                            }\n"
"QScrollBar::handle:vertical { \n"
"                                                background-color:  rgba(1, 22, 51, 0.5);\n"
"                                                min-height: 273.41px;\n"
"														border: 0px solid red; \n"
"														border-radius:4.905px;\n"
"														\n"
"                                            }\n"
"QScrollBar::add-line:vertical {       \n"
"                            height: 0px;\n"
"                            subcontrol-position: bottom; \n"
"                            subcontrol-origin: margin; \n"
"								\n"
"                        } \n"
"QScrollBar::sub-line:vertical { \n"
"            "
                        "                height: 0 px; \n"
"                            subcontrol-position: top; \n"
"                            subcontrol-origin: margin; \n"
"                        }\n"
"\n"
"\n"
""));
        textEdit_dict->setReadOnly(true);
        splitter_2->addWidget(textEdit_dict);
        splitter->addWidget(splitter_2);
        tabWidget_2 = new QTabWidget(splitter);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        sizePolicy.setHeightForWidth(tabWidget_2->sizePolicy().hasHeightForWidth());
        tabWidget_2->setSizePolicy(sizePolicy);
        tabWidget_2->setMinimumSize(QSize(0, 0));
        tabWidget_2->setMaximumSize(QSize(16777215, 16777215));
        tabWidget_2->setStyleSheet(QLatin1String("background-color:white; color:black;\n"
""));
        tabWidget_2->setTabsClosable(true);
        tabWidget_2->setMovable(true);
        tabWidget_2->setTabBarAutoHide(false);
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_4 = new QGridLayout(tab_5);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        textBrowser = new QTextBrowser(tab_5);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy1);
        textBrowser->setMinimumSize(QSize(400, 0));
        QFont font2;
        font2.setFamily(QStringLiteral("WorkSans,Sans"));
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        textBrowser->setFont(font2);
        textBrowser->setMouseTracking(true);
        textBrowser->setStyleSheet(QLatin1String("QTextBrowser{\n"
"	border: 0px;\n"
"	background-color:white;\n"
"font-size: 20pt;\n"
"}\n"
"QScrollBar:vertical { \n"
"                                                border: none;\n"
"                                                background: white;\n"
"                                               \n"
"                                            }\n"
"QScrollBar::handle:vertical { \n"
"                                                background-color:  rgba(1, 22, 51, 0.5);\n"
"                                              \n"
"														border: 0px solid red; \n"
"														\n"
"														\n"
"                                            }\n"
"QScrollBar::add-line:vertical {       \n"
"                            height: 0px;\n"
"                            subcontrol-position: bottom; \n"
"                            subcontrol-origin: margin; \n"
"								\n"
"                        } \n"
"QScrollBar::sub-line:vertical { \n"
"                            height: 0 px; \n"
"                    "
                        "        subcontrol-position: top; \n"
"                            subcontrol-origin: margin; \n"
"                        }\n"
""));
        textBrowser->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        textBrowser->setUndoRedoEnabled(true);
        textBrowser->setReadOnly(false);
        textBrowser->setAcceptRichText(true);
        textBrowser->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_4->addWidget(textBrowser, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_5, QString());
        splitter->addWidget(tabWidget_2);
        graphicsView = new QGraphicsView(splitter);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(0, 0));
        graphicsView->setMaximumSize(QSize(16777215, 16777215));
        graphicsView->setStyleSheet(QLatin1String("QGraphicsView{background-color:white;}\n"
"QScrollBar:vertical { \n"
"                                                border: none;\n"
"                                                background: white;\n"
"                                                \n"
"                                            }\n"
"QScrollBar::handle:vertical { \n"
"                                                background-color:  rgba(1, 22, 51, 0.5);\n"
"                                                \n"
"														border: 0px solid red; \n"
"													\n"
"														\n"
"                                            }\n"
"QScrollBar::add-line:vertical {       \n"
"                            height: 0px;\n"
"                            subcontrol-position: bottom; \n"
"                            subcontrol-origin: margin; \n"
"								\n"
"                        } \n"
"QScrollBar::sub-line:vertical { \n"
"                            height: 0 px; \n"
"                            subcontrol-position: top; \n"
"        "
                        "                    subcontrol-origin: margin; \n"
"                        }\n"
"\n"
"QScrollBar:horizontal { \n"
"                                                border: none;\n"
"                                                background: white;\n"
"                                             		\n"
"                                            }\n"
"QScrollBar::handle:horizontal { \n"
"                                                background-color:  rgba(1, 22, 51, 0.5);\n"
"														border: 0px solid red; \n"
"													\n"
"                                            }\n"
"QScrollBar::add-line:horizontal {       \n"
"                            height: 0px;\n"
"                            subcontrol-position: bottom; \n"
"                            subcontrol-origin: margin; \n"
"								\n"
"                        } \n"
"QScrollBar::sub-line:horizontal { \n"
"                            height: 0 px; \n"
"                            subcontrol-position: top; \n"
"                            s"
                        "ubcontrol-origin: margin; \n"
"                        }\n"
"\n"
""));
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        graphicsView->setAlignment(Qt::AlignCenter);
        graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
        graphicsView->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
        graphicsView->setResizeAnchor(QGraphicsView::AnchorViewCenter);
        splitter->addWidget(graphicsView);

        verticalLayout_4->addWidget(splitter);


        verticalLayout_5->addLayout(verticalLayout_4);

        Buttom_Slider = new QHBoxLayout();
        Buttom_Slider->setSpacing(6);
        Buttom_Slider->setObjectName(QStringLiteral("Buttom_Slider"));
        Buttom_Slider->setSizeConstraint(QLayout::SetDefaultConstraint);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);
        lineEdit->setMinimumSize(QSize(0, 0));
        lineEdit->setMaximumSize(QSize(16777215, 16777215));
        lineEdit->setStyleSheet(QLatin1String("background-color:white;\n"
"color: rgb(0, 0, 0); height:37.39px; width: 469.37px; border:0px; padding-left:7.81px;"));

        Buttom_Slider->addWidget(lineEdit);

        lineEdit_3 = new QLineEdit(centralWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setMaximumSize(QSize(119, 16777215));
        lineEdit_3->setAutoFillBackground(false);
        lineEdit_3->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);  height:37.39px; width:32.73px; border:0px; padding-left:7.81px;"));

        Buttom_Slider->addWidget(lineEdit_3);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(0, 0));
        lineEdit_2->setMaximumSize(QSize(184, 16777215));
        lineEdit_2->setStyleSheet(QLatin1String("background-color:white;\n"
"color: rgb(0, 0, 0); height:37.39px; border:0px; width:184.8px; padding-left:7.81px;"));

        Buttom_Slider->addWidget(lineEdit_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Buttom_Slider->addItem(horizontalSpacer_2);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy3);
        groupBox->setMinimumSize(QSize(264, 37));
        groupBox->setMaximumSize(QSize(264, 37));
        groupBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"	background: white;\n"
"	padding-top:15px;\n"
"	margin-top:-15px; \n"
"   height:37.9px;\n"
"}\n"
""));
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        zoom_Out_Button = new QPushButton(groupBox);
        zoom_Out_Button->setObjectName(QStringLiteral("zoom_Out_Button"));
        zoom_Out_Button->setStyleSheet(QLatin1String("#zoom_Out_Button {\n"
"	color: #202148;\n"
"	background: white;\n"
"	font-size: 24px;\n"
"	padding-right: 12px;\n"
"	padding-left: 12px;\n"
"	border: none;\n"
"}"));

        horizontalLayout_3->addWidget(zoom_Out_Button);

        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setStyleSheet(QLatin1String("QSlider {\n"
"	background: white;\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"border: none;\n"
"background: rgba(1, 22, 51, 0.72);\n"
"height: 3.47px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: #202148;\n"
"border-radius: 1.7px;\n"
"width:  10px;\n"
"height: 26px;\n"
"margin-top: -10px;\n"
"margin-bottom: -10px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: grey;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"background: grey;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: grey;\n"
"}\n"
""));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider);

        zoom_In_Button = new QPushButton(groupBox);
        zoom_In_Button->setObjectName(QStringLiteral("zoom_In_Button"));
        zoom_In_Button->setStyleSheet(QLatin1String("#zoom_In_Button {\n"
"	color: #202148;\n"
"	background: white;\n"
"	font-size: 24px;\n"
"	padding-right: 12px;\n"
"	padding-left: 12px;\n"
"	border: none;\n"
"}"));

        horizontalLayout_3->addWidget(zoom_In_Button);

        zoom_level_value = new QLabel(groupBox);
        zoom_level_value->setObjectName(QStringLiteral("zoom_level_value"));
        sizePolicy3.setHeightForWidth(zoom_level_value->sizePolicy().hasHeightForWidth());
        zoom_level_value->setSizePolicy(sizePolicy3);
        zoom_level_value->setStyleSheet(QLatin1String("#zoom_level_value {\n"
"	color: #202148;\n"
"	background: white;\n"
"}"));

        horizontalLayout_3->addWidget(zoom_level_value);


        Buttom_Slider->addWidget(groupBox);


        verticalLayout_5->addLayout(Buttom_Slider);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1366, 50));
        menuBar->setStyleSheet(QLatin1String("QMenuBar{\n"
"font-size:17px;\n"
"}\n"
"QMenuBar::item{\n"
" /* spacing between menu bar items */\n"
"padding: 15px 15px 15px 15px;\n"
"background: transparent;\n"
"}\n"
"QMenuBar::item:selected{\n"
"    background-color: rgb(52,73,94);\n"
"}\n"
"QMenu::item {\n"
"    spacing: 2px; /* spacing between menu bar items */\n"
"    padding: 10px 85px 10px 20px;\n"
"    background: transparent;\n"
"}\n"
"QMenu::item:selected{\n"
"    background-color: rgb(52,73,94);\n"
"    border-top: none;\n"
"    border-left:none;\n"
"    border-bottom:none;\n"
"    border-left:3px solid  #EEF0F2;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        menuCreateReports = new QMenu(menuBar);
        menuCreateReports->setObjectName(QStringLiteral("menuCreateReports"));
        menuCreateReports->setStyleSheet(QStringLiteral("font-size: 17px;"));
        menuFontAndLayout = new QMenu(menuBar);
        menuFontAndLayout->setObjectName(QStringLiteral("menuFontAndLayout"));
        menuFontAndLayout->setStyleSheet(QStringLiteral("font-size: 17px;"));
        menuTables = new QMenu(menuFontAndLayout);
        menuTables->setObjectName(QStringLiteral("menuTables"));
        menuTables->setStyleSheet(QStringLiteral("font-size: 17px;"));
        menuGit = new QMenu(menuBar);
        menuGit->setObjectName(QStringLiteral("menuGit"));
        menuGit->setStyleSheet(QStringLiteral("font-size: 17px;"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuEdit->setStyleSheet(QStringLiteral("font-size: 17px;"));
        menuDownload = new QMenu(menuBar);
        menuDownload->setObjectName(QStringLiteral("menuDownload"));
        menuDownload->setStyleSheet(QStringLiteral("font-size: 17px;"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuHelp->setStyleSheet(QStringLiteral("font-size: 17px;"));
        menuInstallation_Guide = new QMenu(menuHelp);
        menuInstallation_Guide->setObjectName(QStringLiteral("menuInstallation_Guide"));
        menuInstallation_Guide->setStyleSheet(QStringLiteral("font-size: 17px;"));
        menuSelectLanguage = new QMenu(menuBar);
        menuSelectLanguage->setObjectName(QStringLiteral("menuSelectLanguage"));
        menuSelectLanguage->setStyleSheet(QStringLiteral("font-size: 17px;"));
        menuOCR_Correction_Window = new QMenu(menuBar);
        menuOCR_Correction_Window->setObjectName(QStringLiteral("menuOCR_Correction_Window"));
        menuOCR_Correction_Window->setStyleSheet(QLatin1String("font-size: 17px;\n"
"\n"
""));
        menuOCR_Correction_Window->setToolTipsVisible(true);
        menuRecent_Project = new QMenu(menuOCR_Correction_Window);
        menuRecent_Project->setObjectName(QStringLiteral("menuRecent_Project"));
        menuRecent_Project->setStyleSheet(QStringLiteral("font-size: 17px;"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setStyleSheet(QLatin1String("QToolBar {\n"
"spacing: 3px; /* spacing between items in the tool bar */\n"
"padding: 5px; 	\n"
"color: rgb(0, 0, 0);\n"
"}\n"
"QToolTip{\n"
"color:#202148;\n"
"background-color: #EEF0F2;\n"
"}"));
        mainToolBar->setIconSize(QSize(32, 32));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuOCR_Correction_Window->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuSelectLanguage->menuAction());
        menuBar->addAction(menuCreateReports->menuAction());
        menuBar->addAction(menuFontAndLayout->menuAction());
        menuBar->addAction(menuGit->menuAction());
        menuBar->addAction(menuDownload->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuCreateReports->addAction(actionAccuracyLog);
        menuCreateReports->addAction(actionViewAverageAccuracies);
        menuFontAndLayout->addAction(actionAllFontProperties);
        menuFontAndLayout->addAction(actionBold);
        menuFontAndLayout->addAction(actionUnBold);
        menuFontAndLayout->addAction(actionItalic);
        menuFontAndLayout->addAction(actionHighlight);
        menuFontAndLayout->addSeparator();
        menuFontAndLayout->addAction(actionLeftAlign);
        menuFontAndLayout->addAction(actionRightAlign);
        menuFontAndLayout->addAction(actionCentreAlign);
        menuFontAndLayout->addAction(actionSuperscript);
        menuFontAndLayout->addAction(actionSubscript);
        menuFontAndLayout->addAction(actionInsert_Horizontal_Line);
        menuFontAndLayout->addAction(actionFontBlack);
        menuFontAndLayout->addAction(actionInsert_Tab_Space);
        menuFontAndLayout->addAction(menuTables->menuAction());
        menuTables->addAction(actionInsert_Table_2);
        menuTables->addAction(actionInsert_Columnleft);
        menuTables->addAction(actionInsert_Columnright);
        menuTables->addAction(actionInsert_Rowabove);
        menuTables->addAction(actionInsert_Rowbelow);
        menuTables->addAction(actionRemove_Column);
        menuTables->addAction(actionRemove_Row);
        menuGit->addAction(actionFetch_2);
        menuGit->addAction(actionVerifier_Turn_In);
        menuGit->addAction(actionTurn_In);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionFind_and_Replace);
        menuEdit->addSeparator();
        menuEdit->addAction(actionUndo_Global_Replace);
        menuEdit->addAction(actionUpload);
        menuDownload->addAction(actionas_PDF);
        menuHelp->addAction(actionGet_Help);
        menuHelp->addAction(menuInstallation_Guide->menuAction());
        menuHelp->addAction(actionTutorial);
        menuHelp->addAction(actionShortcut_Guide);
        menuInstallation_Guide->addAction(actionLinux);
        menuInstallation_Guide->addAction(actionWindows);
        menuSelectLanguage->addAction(actionSanskrit_2);
        menuSelectLanguage->addAction(actionHindi);
        menuSelectLanguage->addAction(actionEnglish);
        menuOCR_Correction_Window->addAction(actionNew);
        menuOCR_Correction_Window->addAction(actionNew_Project);
        menuOCR_Correction_Window->addAction(actionOpen_Project);
        menuOCR_Correction_Window->addAction(menuRecent_Project->menuAction());
        menuOCR_Correction_Window->addAction(actionSave);
        menuOCR_Correction_Window->addAction(actionSave_As);
        menuOCR_Correction_Window->addAction(actionSpell_Check);
        menuOCR_Correction_Window->addAction(actionLoad_Next_Page);
        menuOCR_Correction_Window->addAction(actionLoad_Prev_Page);
        menuOCR_Correction_Window->addSeparator();
        menuOCR_Correction_Window->addAction(actionToDevanagari);
        menuOCR_Correction_Window->addAction(actionToSlp1);
        menuOCR_Correction_Window->addAction(actionLoadGDocPage);
        menuOCR_Correction_Window->addAction(actionLoadData);
        menuOCR_Correction_Window->addAction(actionLoadDict);
        menuOCR_Correction_Window->addAction(actionLoadOCRWords);
        menuOCR_Correction_Window->addAction(actionLoadDomain);
        menuOCR_Correction_Window->addAction(actionLoadSubPS);
        menuOCR_Correction_Window->addAction(actionLoadConfusions);
        menuOCR_Correction_Window->addAction(actionSugg);
        menuRecent_Project->addAction(action1);
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen_Project);
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionSave_As);
        mainToolBar->addAction(actionLoadData);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionLoad_Prev_Page);
        mainToolBar->addAction(actionLoad_Next_Page);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionUndo);
        mainToolBar->addAction(actionRedo);
        mainToolBar->addAction(actionFind_and_Replace);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionLoadGDocPage);
        mainToolBar->addAction(actionToDevanagari);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAllFontProperties);
        mainToolBar->addAction(actionBold);
        mainToolBar->addAction(actionItalic);
        mainToolBar->addAction(actionUnBold);
        mainToolBar->addAction(actionFontBlack);
        mainToolBar->addAction(actionSuperscript);
        mainToolBar->addAction(actionSubscript);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionLeftAlign);
        mainToolBar->addAction(actionCentreAlign);
        mainToolBar->addAction(actionRightAlign);
        mainToolBar->addAction(actionInsert_Horizontal_Line);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionHighlight);
        mainToolBar->addAction(actionSymbols);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionZoom_In);
        mainToolBar->addAction(actionZoom_Out);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionGet_Help);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionOpen_Project->setText(QApplication::translate("MainWindow", "Open Project", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionOpen_Project->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSave_As->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionNew->setText(QApplication::translate("MainWindow", "New", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSpell_Check->setText(QApplication::translate("MainWindow", "Spell Check(CntrlShftC)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSpell_Check->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+C", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionLoad_Next_Page->setText(QApplication::translate("MainWindow", "Page(CntlShiftR)>>", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionLoad_Next_Page->setToolTip(QApplication::translate("MainWindow", "Page(CntlShiftR)>>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionLoad_Next_Page->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+R", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionLoad_Prev_Page->setText(QApplication::translate("MainWindow", "<<Page(CntrlShftL)", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionLoad_Prev_Page->setToolTip(QApplication::translate("MainWindow", "<<Page(CntrlShftL)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionLoad_Prev_Page->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+L", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionLoadGDocPage->setText(QApplication::translate("MainWindow", "SaveLoadPWords(CntrlShftP)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionLoadGDocPage->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+P", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionToDevanagari->setText(QApplication::translate("MainWindow", "toDevanagari(CntrlD)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionToDevanagari->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionLoadData->setText(QApplication::translate("MainWindow", "LoadData", Q_NULLPTR));
        actionLoadDict->setText(QApplication::translate("MainWindow", "LoadDict", Q_NULLPTR));
        actionLoadOCRWords->setText(QApplication::translate("MainWindow", "LoadOCRWords", Q_NULLPTR));
        actionLoadDomain->setText(QApplication::translate("MainWindow", "LoadDomain", Q_NULLPTR));
        actionLoadSubPS->setText(QApplication::translate("MainWindow", "LoadSubPS", Q_NULLPTR));
        actionLoadConfusions->setText(QApplication::translate("MainWindow", "LoadConfusions", Q_NULLPTR));
        actionSugg->setText(QApplication::translate("MainWindow", "sugg", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSugg->setShortcut(QApplication::translate("MainWindow", "Menu", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionCreateBest2OCR->setText(QApplication::translate("MainWindow", "CreateBest2OCR", Q_NULLPTR));
        actionToSlp1->setText(QApplication::translate("MainWindow", "toSlp1(CntrlG)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionToSlp1->setShortcut(QApplication::translate("MainWindow", "Ctrl+G", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionCreateSuggestionLog->setText(QApplication::translate("MainWindow", "CreateSuggestionLog", Q_NULLPTR));
        actionCreateSuggestionLogNearestPriority->setText(QApplication::translate("MainWindow", "CreateSuggestionLogNearestPriority", Q_NULLPTR));
        actionErrorDetectionRep->setText(QApplication::translate("MainWindow", "ErrorDetectionRep", Q_NULLPTR));
        actionErrorDetectWithoutAdaptation->setText(QApplication::translate("MainWindow", "ErrorDetectWithoutAdaptation", Q_NULLPTR));
        actionCPair->setText(QApplication::translate("MainWindow", "CPair", Q_NULLPTR));
        actionToSlp1_2->setText(QApplication::translate("MainWindow", "toSlp1", Q_NULLPTR));
        actionToDev->setText(QApplication::translate("MainWindow", "toDev", Q_NULLPTR));
        actionExtractDev->setText(QApplication::translate("MainWindow", "ExtractDevWords", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionExtractDev->setToolTip(QApplication::translate("MainWindow", "ExtractDevWords", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionPrimarySecOCRPair->setText(QApplication::translate("MainWindow", "PrimarySecOCRPairs", Q_NULLPTR));
        actionCPairIEROcrVsCorrect->setText(QApplication::translate("MainWindow", "CPairIEROcrVsCorrect", Q_NULLPTR));
        actionEditDistRep->setText(QApplication::translate("MainWindow", "EditDistRep", Q_NULLPTR));
        actionConfusionFreqHist->setText(QApplication::translate("MainWindow", "ConfusionFreqHist", Q_NULLPTR));
        actionCPairGEROcrVsCorrect->setText(QApplication::translate("MainWindow", "CPairGEROcrVsCorrect", Q_NULLPTR));
        actionFilterOutGT50EditDisPairs->setText(QApplication::translate("MainWindow", "FilterOutGT50EditDisPairs", Q_NULLPTR));
        actionErrorDetectionRepUniq->setText(QApplication::translate("MainWindow", "ErrorSuggRepUniq", Q_NULLPTR));
        actionAllFontProperties->setText(QApplication::translate("MainWindow", "AllFontProperties", Q_NULLPTR));
        actionBold->setText(QApplication::translate("MainWindow", "Bold", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionBold->setToolTip(QApplication::translate("MainWindow", "Bold/Unbold - Ctrl+B", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionBold->setShortcut(QApplication::translate("MainWindow", "Ctrl+B", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionUnBold->setText(QApplication::translate("MainWindow", "UnBold", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionUnBold->setToolTip(QApplication::translate("MainWindow", "UnBold (Deprecated - Use Bold button for bold/unbold)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionLeftAlign->setText(QApplication::translate("MainWindow", "LeftAlign", Q_NULLPTR));
        actionRightAlign->setText(QApplication::translate("MainWindow", "RightAlign", Q_NULLPTR));
        actionCentreAlign->setText(QApplication::translate("MainWindow", "CentreAlign", Q_NULLPTR));
        actionJusitfiedAlign->setText(QApplication::translate("MainWindow", "JusitfiedAlign", Q_NULLPTR));
        actionAccuracyLog->setText(QApplication::translate("MainWindow", "AccuracyLog", Q_NULLPTR));
        actionView_File_Hierarchy->setText(QApplication::translate("MainWindow", "View File Hierarchy", Q_NULLPTR));
        actionTurn_In->setText(QApplication::translate("MainWindow", "Submit Corrector", Q_NULLPTR));
        actionFetch->setText(QApplication::translate("MainWindow", "Fetch", Q_NULLPTR));
        actionCompare_Verifier->setText(QApplication::translate("MainWindow", "Verifier Diff View", Q_NULLPTR));
        actionCompare_Corrector->setText(QApplication::translate("MainWindow", "Corrector Diff View", Q_NULLPTR));
        actionAverage_Accuracy->setText(QApplication::translate("MainWindow", "Average Accuracy", Q_NULLPTR));
        actionView_Comments->setText(QApplication::translate("MainWindow", "View Comments", Q_NULLPTR));
        actionCommit->setText(QApplication::translate("MainWindow", "Commit", Q_NULLPTR));
        actionFetch_2->setText(QApplication::translate("MainWindow", "Pull", Q_NULLPTR));
        actionPush->setText(QApplication::translate("MainWindow", "Push", Q_NULLPTR));
        actionVerifier_Turn_In->setText(QApplication::translate("MainWindow", "Submit Verifier", Q_NULLPTR));
        actionHighlight->setText(QApplication::translate("MainWindow", "Highlight", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionHighlight->setToolTip(QApplication::translate("MainWindow", "Highlight (Ctrl+H)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionHighlight->setShortcut(QApplication::translate("MainWindow", "Ctrl+H", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionZoom_In->setText(QApplication::translate("MainWindow", "Zoom In", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionZoom_In->setToolTip(QApplication::translate("MainWindow", "Zoom In (Ctrl + +)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionZoom_In->setShortcut(QApplication::translate("MainWindow", "Ctrl++", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionZoom_Out->setText(QApplication::translate("MainWindow", "Zoom_Out", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionZoom_Out->setToolTip(QApplication::translate("MainWindow", "Zoom Out (Ctrl + -)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionZoom_Out->setShortcut(QApplication::translate("MainWindow", "Ctrl+-", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSymbols->setText(QApplication::translate("MainWindow", "Symbols", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSymbols->setToolTip(QApplication::translate("MainWindow", "Special Symbols", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionSuperscript->setText(QApplication::translate("MainWindow", "Superscript", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSuperscript->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+`", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSubscript->setText(QApplication::translate("MainWindow", "Subscript", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSubscript->setShortcut(QApplication::translate("MainWindow", "Ctrl+`", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionInsert_Horizontal_Line->setText(QApplication::translate("MainWindow", "Horizontal Line", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionInsert_Horizontal_Line->setToolTip(QApplication::translate("MainWindow", "Horizontal Line", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionFontBlack->setText(QApplication::translate("MainWindow", "FontBlack", Q_NULLPTR));
        actionLineSpace->setText(QApplication::translate("MainWindow", "LineSpace", Q_NULLPTR));
        actionViewAverageAccuracies->setText(QApplication::translate("MainWindow", "ViewAverageAccuracies", Q_NULLPTR));
        actionInsert_Tab_Space->setText(QApplication::translate("MainWindow", "Insert Tab Space", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionInsert_Tab_Space->setToolTip(QApplication::translate("MainWindow", "Insert Tab Space (Ctrl+T)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionInsert_Tab_Space->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionAdd_Image->setText(QApplication::translate("MainWindow", "Add Image", Q_NULLPTR));
        actionResize_Image->setText(QApplication::translate("MainWindow", "Resize Image", Q_NULLPTR));
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Z", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionNew_Project->setText(QApplication::translate("MainWindow", "New Project", Q_NULLPTR));
        actionInsert_Table_2->setText(QApplication::translate("MainWindow", "Insert Table", Q_NULLPTR));
        actionInsert_Columnleft->setText(QApplication::translate("MainWindow", "Insert Column at Left", Q_NULLPTR));
        actionInsert_Columnright->setText(QApplication::translate("MainWindow", "Insert Column at Right", Q_NULLPTR));
        actionInsert_Rowabove->setText(QApplication::translate("MainWindow", "Insert Row above", Q_NULLPTR));
        actionInsert_Rowbelow->setText(QApplication::translate("MainWindow", "Insert Row Below", Q_NULLPTR));
        actionRemove_Column->setText(QApplication::translate("MainWindow", "Remove Column", Q_NULLPTR));
        actionRemove_Row->setText(QApplication::translate("MainWindow", "Remove Row", Q_NULLPTR));
        actionItalic->setText(QApplication::translate("MainWindow", "Italic", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionItalic->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionNonitalic->setText(QApplication::translate("MainWindow", "Non Italic", Q_NULLPTR));
        actionSave_All->setText(QApplication::translate("MainWindow", "Save All", Q_NULLPTR));
        actionFind_and_Replace->setText(QApplication::translate("MainWindow", "Find and Replace", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionFind_and_Replace->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionas_PDF->setText(QApplication::translate("MainWindow", "as PDF", Q_NULLPTR));
        actionGet_Help->setText(QApplication::translate("MainWindow", "Get Help", Q_NULLPTR));
        actionTutorial->setText(QApplication::translate("MainWindow", "Tutorial", Q_NULLPTR));
        actionLinux->setText(QApplication::translate("MainWindow", "Linux", Q_NULLPTR));
        actionWindows->setText(QApplication::translate("MainWindow", "Windows", Q_NULLPTR));
        actionas_Doc->setText(QApplication::translate("MainWindow", "as Doc", Q_NULLPTR));
        actionSanskrit->setText(QApplication::translate("MainWindow", "Sanskrit", Q_NULLPTR));
        actionHindi->setText(QApplication::translate("MainWindow", "Hindi/Marathi", Q_NULLPTR));
        actionEnglish->setText(QApplication::translate("MainWindow", "English", Q_NULLPTR));
        actionShortcut_Guide->setText(QApplication::translate("MainWindow", "Shortcut Guide", Q_NULLPTR));
        action1->setText(QApplication::translate("MainWindow", "1| ", Q_NULLPTR));
        actionSanskrit_2->setText(QApplication::translate("MainWindow", "Sanskrit", Q_NULLPTR));
        actionUndo_Global_Replace->setText(QApplication::translate("MainWindow", "Undo Global Replace", Q_NULLPTR));
        actionUpload->setText(QApplication::translate("MainWindow", "Upload and Replace", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Resize Image", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Mark Regions", Q_NULLPTR));
        viewComments->setText(QApplication::translate("MainWindow", "Comments Accuracy", Q_NULLPTR));
        compareCorrectorOutput->setText(QApplication::translate("MainWindow", "Compare Corrector Output", Q_NULLPTR));
        compareVerifierOutput->setText(QApplication::translate("MainWindow", "Compare Verifier Output", Q_NULLPTR));
        hinButton->setText(QApplication::translate("MainWindow", "Hindi/Marathi", Q_NULLPTR));
        sanButton->setText(QApplication::translate("MainWindow", "Sanskrit", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "SLP", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Project", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'WorkSans,Sans'; font-size:20pt; font-weight:400; font-style:normal;\" bgcolor=\"#ffffff\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">Please Select the Language from top left menu before loading any document.</span></p></body></html>", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "Tab 1", Q_NULLPTR));
        lineEdit_3->setText(QApplication::translate("MainWindow", "Words 0", Q_NULLPTR));
        groupBox->setTitle(QString());
        zoom_Out_Button->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        zoom_In_Button->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        zoom_level_value->setText(QApplication::translate("MainWindow", "100%", Q_NULLPTR));
        menuCreateReports->setTitle(QApplication::translate("MainWindow", "Reports", Q_NULLPTR));
        menuFontAndLayout->setTitle(QApplication::translate("MainWindow", "View", Q_NULLPTR));
        menuTables->setTitle(QApplication::translate("MainWindow", "Tables", Q_NULLPTR));
        menuGit->setTitle(QApplication::translate("MainWindow", "Versions", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        menuDownload->setTitle(QApplication::translate("MainWindow", "Download", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
        menuInstallation_Guide->setTitle(QApplication::translate("MainWindow", "Installation Guide", Q_NULLPTR));
        menuSelectLanguage->setTitle(QApplication::translate("MainWindow", "Language", Q_NULLPTR));
        menuOCR_Correction_Window->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuRecent_Project->setTitle(QApplication::translate("MainWindow", "Recent Project", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
