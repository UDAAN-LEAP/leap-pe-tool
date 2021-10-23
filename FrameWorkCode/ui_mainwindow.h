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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
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
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
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
    QMenuBar *menuBar;
    QMenu *menuOCR_Correction_Window;
    QMenu *menuCreateReports;
    QMenu *menuFontAndLayout;
    QMenu *menuTables;
    QMenu *menuGit;
    QMenu *menuEdit;
    QMenu *menuDownload;
    QMenu *menuHelp;
    QMenu *menuInstallation_Guide;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1366, 1190);
        MainWindow->setMouseTracking(true);
        actionOpen_Project = new QAction(MainWindow);
        actionOpen_Project->setObjectName(QStringLiteral("actionOpen_Project"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_Project->setIcon(icon);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon1);
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Images/save-as.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_As->setIcon(icon2);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Images/New.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon3);
        actionNew->setVisible(true);
        actionSpell_Check = new QAction(MainWindow);
        actionSpell_Check->setObjectName(QStringLiteral("actionSpell_Check"));
        actionSpell_Check->setEnabled(true);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Images/spellcheck.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSpell_Check->setIcon(icon4);
        actionSpell_Check->setVisible(true);
        actionLoad_Next_Page = new QAction(MainWindow);
        actionLoad_Next_Page->setObjectName(QStringLiteral("actionLoad_Next_Page"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Images/next-page.png"), QSize(), QIcon::Normal, QIcon::On);
        actionLoad_Next_Page->setIcon(icon5);
        actionLoad_Prev_Page = new QAction(MainWindow);
        actionLoad_Prev_Page->setObjectName(QStringLiteral("actionLoad_Prev_Page"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Images/previous-page.png"), QSize(), QIcon::Normal, QIcon::On);
        actionLoad_Prev_Page->setIcon(icon6);
        actionLoadGDocPage = new QAction(MainWindow);
        actionLoadGDocPage->setObjectName(QStringLiteral("actionLoadGDocPage"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Images/SaveLoadPwords1.png"), QSize(), QIcon::Normal, QIcon::On);
        actionLoadGDocPage->setIcon(icon7);
        actionToDevanagari = new QAction(MainWindow);
        actionToDevanagari->setObjectName(QStringLiteral("actionToDevanagari"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/Images/toDevangari.png"), QSize(), QIcon::Normal, QIcon::On);
        actionToDevanagari->setIcon(icon8);
        actionLoadData = new QAction(MainWindow);
        actionLoadData->setObjectName(QStringLiteral("actionLoadData"));
        actionLoadData->setEnabled(true);
        QIcon icon9;
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
        icon10.addFile(QStringLiteral(":/Images/toSlp1.png"), QSize(), QIcon::Normal, QIcon::Off);
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
        icon11.addFile(QStringLiteral(":/Images/AllFont.png"), QSize(), QIcon::Normal, QIcon::On);
        actionAllFontProperties->setIcon(icon11);
        actionBold = new QAction(MainWindow);
        actionBold->setObjectName(QStringLiteral("actionBold"));
        actionUnBold = new QAction(MainWindow);
        actionUnBold->setObjectName(QStringLiteral("actionUnBold"));
        actionUnBold->setEnabled(false);
        actionUnBold->setVisible(false);
        actionLeftAlign = new QAction(MainWindow);
        actionLeftAlign->setObjectName(QStringLiteral("actionLeftAlign"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/Images/AlignLeft.png"), QSize(), QIcon::Normal, QIcon::On);
        actionLeftAlign->setIcon(icon12);
        actionRightAlign = new QAction(MainWindow);
        actionRightAlign->setObjectName(QStringLiteral("actionRightAlign"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/Images/AlignRight.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon13.addFile(QStringLiteral(":/Images/AlignCenter.png"), QSize(), QIcon::Normal, QIcon::On);
        actionRightAlign->setIcon(icon13);
        actionCentreAlign = new QAction(MainWindow);
        actionCentreAlign->setObjectName(QStringLiteral("actionCentreAlign"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/Images/AlignCenter.png"), QSize(), QIcon::Normal, QIcon::On);
        actionCentreAlign->setIcon(icon14);
        actionJusitfiedAlign = new QAction(MainWindow);
        actionJusitfiedAlign->setObjectName(QStringLiteral("actionJusitfiedAlign"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/Images/JustifiedAlign.png"), QSize(), QIcon::Normal, QIcon::On);
        actionJusitfiedAlign->setIcon(icon15);
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
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/Images/highlight-icon.png"), QSize(), QIcon::Normal, QIcon::On);
        actionHighlight->setIcon(icon16);
        actionHighlight->setVisible(true);
        actionZoom_In = new QAction(MainWindow);
        actionZoom_In->setObjectName(QStringLiteral("actionZoom_In"));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/Images/Zoom-In-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_In->setIcon(icon17);
        actionZoom_Out = new QAction(MainWindow);
        actionZoom_Out->setObjectName(QStringLiteral("actionZoom_Out"));
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/Images/Zoom-Out-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_Out->setIcon(icon18);
        actionSymbols = new QAction(MainWindow);
        actionSymbols->setObjectName(QStringLiteral("actionSymbols"));
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/Images/symbols.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon19.addFile(QStringLiteral(":/Images/symbols.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSymbols->setIcon(icon19);
        actionSuperscript = new QAction(MainWindow);
        actionSuperscript->setObjectName(QStringLiteral("actionSuperscript"));
        actionSubscript = new QAction(MainWindow);
        actionSubscript->setObjectName(QStringLiteral("actionSubscript"));
        actionInsert_Horizontal_Line = new QAction(MainWindow);
        actionInsert_Horizontal_Line->setObjectName(QStringLiteral("actionInsert_Horizontal_Line"));
        QIcon icon20;
        icon20.addFile(QStringLiteral(":/Images/horizontal-line.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInsert_Horizontal_Line->setIcon(icon20);
        actionFontBlack = new QAction(MainWindow);
        actionFontBlack->setObjectName(QStringLiteral("actionFontBlack"));
        actionLineSpace = new QAction(MainWindow);
        actionLineSpace->setObjectName(QStringLiteral("actionLineSpace"));
        actionLineSpace->setEnabled(false);
        QIcon icon21;
        icon21.addFile(QStringLiteral(":/Images/linespacing.png"), QSize(), QIcon::Normal, QIcon::On);
        actionLineSpace->setIcon(icon21);
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
        QIcon icon22;
        icon22.addFile(QStringLiteral(":/Images/undo.png"), QSize(), QIcon::Normal, QIcon::On);
        actionUndo->setIcon(icon22);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        QIcon icon23;
        icon23.addFile(QStringLiteral(":/Images/redo.png"), QSize(), QIcon::Normal, QIcon::On);
        actionRedo->setIcon(icon23);
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
        actionNonitalic = new QAction(MainWindow);
        actionNonitalic->setObjectName(QStringLiteral("actionNonitalic"));
        actionSave_All = new QAction(MainWindow);
        actionSave_All->setObjectName(QStringLiteral("actionSave_All"));
        actionFind_and_Replace = new QAction(MainWindow);
        actionFind_and_Replace->setObjectName(QStringLiteral("actionFind_and_Replace"));
        QIcon icon24;
        icon24.addFile(QStringLiteral(":/Images/find-and-replace.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFind_and_Replace->setIcon(icon24);
        actionas_PDF = new QAction(MainWindow);
        actionas_PDF->setObjectName(QStringLiteral("actionas_PDF"));
        actionGet_Help = new QAction(MainWindow);
        actionGet_Help->setObjectName(QStringLiteral("actionGet_Help"));
        QIcon icon25;
        icon25.addFile(QStringLiteral(":/Images/Help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGet_Help->setIcon(icon25);
        actionTutorial = new QAction(MainWindow);
        actionTutorial->setObjectName(QStringLiteral("actionTutorial"));
        actionLinux = new QAction(MainWindow);
        actionLinux->setObjectName(QStringLiteral("actionLinux"));
        actionWindows = new QAction(MainWindow);
        actionWindows->setObjectName(QStringLiteral("actionWindows"));
        actionas_Doc = new QAction(MainWindow);
        actionas_Doc->setObjectName(QStringLiteral("actionas_Doc"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
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
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMinimumSize(QSize(400, 20));
        lineEdit->setMaximumSize(QSize(400, 20));

        horizontalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(0, 20));
        lineEdit_2->setMaximumSize(QSize(16777215, 20));

        horizontalLayout->addWidget(lineEdit_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        viewComments = new QPushButton(centralWidget);
        viewComments->setObjectName(QStringLiteral("viewComments"));

        horizontalLayout->addWidget(viewComments);

        compareCorrectorOutput = new QPushButton(centralWidget);
        compareCorrectorOutput->setObjectName(QStringLiteral("compareCorrectorOutput"));

        horizontalLayout->addWidget(compareCorrectorOutput);

        compareVerifierOutput = new QPushButton(centralWidget);
        compareVerifierOutput->setObjectName(QStringLiteral("compareVerifierOutput"));
        compareVerifierOutput->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(compareVerifierOutput);


        verticalLayout_4->addLayout(horizontalLayout);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        splitter_2 = new QSplitter(splitter);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        tabWidget = new QTabWidget(splitter_2);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(0, 0));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
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
        hinButton->setMaximumSize(QSize(16777215, 20));
        hinButton->setCheckable(true);

        horizontalLayout_2->addWidget(hinButton);

        sanButton = new QPushButton(tab);
        sanButton->setObjectName(QStringLiteral("sanButton"));
        sanButton->setMaximumSize(QSize(16777215, 20));
        sanButton->setCheckable(true);
        sanButton->setChecked(false);

        horizontalLayout_2->addWidget(sanButton);


        verticalLayout->addLayout(horizontalLayout_2);

        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);
        textEdit->setMinimumSize(QSize(0, 0));
        textEdit->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("FreeSans"));
        font.setItalic(true);
        textEdit->setFont(font);
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
        sizePolicy1.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy1);
        treeView->setMinimumSize(QSize(0, 0));
        treeView->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_3->addWidget(treeView);

        tabWidget->addTab(tab_2, QString());
        splitter_2->addWidget(tabWidget);
        textEdit_dict = new QTextEdit(splitter_2);
        textEdit_dict->setObjectName(QStringLiteral("textEdit_dict"));
        textEdit_dict->setReadOnly(true);
        splitter_2->addWidget(textEdit_dict);
        splitter->addWidget(splitter_2);
        tabWidget_2 = new QTabWidget(splitter);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        sizePolicy1.setHeightForWidth(tabWidget_2->sizePolicy().hasHeightForWidth());
        tabWidget_2->setSizePolicy(sizePolicy1);
        tabWidget_2->setMinimumSize(QSize(0, 0));
        tabWidget_2->setMaximumSize(QSize(16777215, 16777215));
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
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy2);
        textBrowser->setMinimumSize(QSize(400, 0));
        QFont font1;
        font1.setFamily(QStringLiteral("Shobhika"));
        font1.setPointSize(16);
        font1.setItalic(false);
        textBrowser->setFont(font1);
        textBrowser->setMouseTracking(true);
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
        sizePolicy1.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy1);
        graphicsView->setMinimumSize(QSize(0, 0));
        graphicsView->setMaximumSize(QSize(16777215, 16777215));
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        graphicsView->setAlignment(Qt::AlignCenter);
        graphicsView->setRenderHints(QPainter::NonCosmeticDefaultPen);
        graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
        graphicsView->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
        graphicsView->setResizeAnchor(QGraphicsView::AnchorViewCenter);
        splitter->addWidget(graphicsView);

        verticalLayout_4->addWidget(splitter);


        verticalLayout_5->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1366, 22));
        menuOCR_Correction_Window = new QMenu(menuBar);
        menuOCR_Correction_Window->setObjectName(QStringLiteral("menuOCR_Correction_Window"));
        menuCreateReports = new QMenu(menuBar);
        menuCreateReports->setObjectName(QStringLiteral("menuCreateReports"));
        menuFontAndLayout = new QMenu(menuBar);
        menuFontAndLayout->setObjectName(QStringLiteral("menuFontAndLayout"));
        menuTables = new QMenu(menuFontAndLayout);
        menuTables->setObjectName(QStringLiteral("menuTables"));
        menuGit = new QMenu(menuBar);
        menuGit->setObjectName(QStringLiteral("menuGit"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuDownload = new QMenu(menuBar);
        menuDownload->setObjectName(QStringLiteral("menuDownload"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuInstallation_Guide = new QMenu(menuHelp);
        menuInstallation_Guide->setObjectName(QStringLiteral("menuInstallation_Guide"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuOCR_Correction_Window->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuCreateReports->menuAction());
        menuBar->addAction(menuFontAndLayout->menuAction());
        menuBar->addAction(menuGit->menuAction());
        menuBar->addAction(menuDownload->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuOCR_Correction_Window->addAction(actionNew);
        menuOCR_Correction_Window->addAction(actionNew_Project);
        menuOCR_Correction_Window->addAction(actionOpen_Project);
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
        menuDownload->addAction(actionas_PDF);
        menuHelp->addAction(actionGet_Help);
        menuHelp->addAction(menuInstallation_Guide->menuAction());
        menuHelp->addAction(actionTutorial);
        menuInstallation_Guide->addAction(actionLinux);
        menuInstallation_Guide->addAction(actionWindows);
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
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionToDevanagari);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAllFontProperties);
        mainToolBar->addAction(actionBold);
        mainToolBar->addAction(actionUnBold);
        mainToolBar->addAction(actionItalic);
        mainToolBar->addAction(actionFontBlack);
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
        actionLoadGDocPage->setText(QApplication::translate("MainWindow", "Save&LoadPWords(CntrlShftP)", Q_NULLPTR));
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
        actionInsert_Tab_Space->setText(QApplication::translate("MainWindow", "Insert Tab Space(Ctrl+T)", Q_NULLPTR));
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
        pushButton_2->setText(QApplication::translate("MainWindow", "Resize Image", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Mark Regions", Q_NULLPTR));
        viewComments->setText(QApplication::translate("MainWindow", "Comments & Accuracy", Q_NULLPTR));
        compareCorrectorOutput->setText(QApplication::translate("MainWindow", "Compare Corrector Output", Q_NULLPTR));
        compareVerifierOutput->setText(QApplication::translate("MainWindow", "Comapre Verifier Output", Q_NULLPTR));
        hinButton->setText(QApplication::translate("MainWindow", "Hindi/Marathi", Q_NULLPTR));
        sanButton->setText(QApplication::translate("MainWindow", "Sanskrit", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "SLP", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Project", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Shobhika'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">Please Select the Language from top left menu before loading any document.</span></p></body></html>", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "Tab 1", Q_NULLPTR));
        menuOCR_Correction_Window->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuCreateReports->setTitle(QApplication::translate("MainWindow", "Reports", Q_NULLPTR));
        menuFontAndLayout->setTitle(QApplication::translate("MainWindow", "FontAndLayout", Q_NULLPTR));
        menuTables->setTitle(QApplication::translate("MainWindow", "Tables", Q_NULLPTR));
        menuGit->setTitle(QApplication::translate("MainWindow", "Version Control", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        menuDownload->setTitle(QApplication::translate("MainWindow", "Download", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
        menuInstallation_Guide->setTitle(QApplication::translate("MainWindow", "Installation Guide", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
