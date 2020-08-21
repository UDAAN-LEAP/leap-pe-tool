/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
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
    QAction *actionPrepareFeatures;
    QAction *actionErrorDetectionRepUniq;
    QAction *actionSanskrit;
    QAction *actionHindi;
    QAction *actionEnglish;
    QAction *actionAllFontProperties;
    QAction *actionBold;
    QAction *actionUnBold;
    QAction *actionLeftAlign;
    QAction *actionRightAlign;
    QAction *actionCentreAlign;
    QAction *actionJusitfiedAlign;
    QAction *actionAccuracyLog;
    QAction *actionOpen_Project;
    QAction *actionView_File_Hierarchy;
    QAction *actionTurn_In;
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
    QAction *actionDiacritics;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_2;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QTreeView *treeView;
    QTabWidget *tabWidget_2;
    QWidget *tab_5;
    QTextBrowser *textBrowser;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuOCR_Correction_Window;
    QMenu *menuCreateReports;
    QMenu *menuSaveVariables;
    QMenu *menuConvertFiles;
    QMenu *menuFeatureExtraction;
    QMenu *menuSelectLanguage;
    QMenu *menuFontAndLayout;
    QMenu *menuView;
    QMenu *menuGit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1386, 788);
        MainWindow->setMouseTracking(true);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon);
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/save-as.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_As->setIcon(icon1);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Images/New.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon2);
        actionSpell_Check = new QAction(MainWindow);
        actionSpell_Check->setObjectName(QString::fromUtf8("actionSpell_Check"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Images/spellcheck.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSpell_Check->setIcon(icon3);
        actionLoad_Next_Page = new QAction(MainWindow);
        actionLoad_Next_Page->setObjectName(QString::fromUtf8("actionLoad_Next_Page"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Images/next-page.png"), QSize(), QIcon::Normal, QIcon::On);
        actionLoad_Next_Page->setIcon(icon4);
        actionLoad_Prev_Page = new QAction(MainWindow);
        actionLoad_Prev_Page->setObjectName(QString::fromUtf8("actionLoad_Prev_Page"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Images/previous-page.png"), QSize(), QIcon::Normal, QIcon::On);
        actionLoad_Prev_Page->setIcon(icon5);
        actionLoadGDocPage = new QAction(MainWindow);
        actionLoadGDocPage->setObjectName(QString::fromUtf8("actionLoadGDocPage"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Images/SaveLoadPwords1.png"), QSize(), QIcon::Normal, QIcon::On);
        actionLoadGDocPage->setIcon(icon6);
        actionToDevanagari = new QAction(MainWindow);
        actionToDevanagari->setObjectName(QString::fromUtf8("actionToDevanagari"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Images/toDevangari.png"), QSize(), QIcon::Normal, QIcon::On);
        actionToDevanagari->setIcon(icon7);
        actionLoadData = new QAction(MainWindow);
        actionLoadData->setObjectName(QString::fromUtf8("actionLoadData"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Images/LoadData.png"), QSize(), QIcon::Normal, QIcon::On);
        actionLoadData->setIcon(icon8);
        actionLoadDict = new QAction(MainWindow);
        actionLoadDict->setObjectName(QString::fromUtf8("actionLoadDict"));
        actionLoadOCRWords = new QAction(MainWindow);
        actionLoadOCRWords->setObjectName(QString::fromUtf8("actionLoadOCRWords"));
        actionLoadDomain = new QAction(MainWindow);
        actionLoadDomain->setObjectName(QString::fromUtf8("actionLoadDomain"));
        actionLoadSubPS = new QAction(MainWindow);
        actionLoadSubPS->setObjectName(QString::fromUtf8("actionLoadSubPS"));
        actionLoadConfusions = new QAction(MainWindow);
        actionLoadConfusions->setObjectName(QString::fromUtf8("actionLoadConfusions"));
        actionSugg = new QAction(MainWindow);
        actionSugg->setObjectName(QString::fromUtf8("actionSugg"));
        actionCreateBest2OCR = new QAction(MainWindow);
        actionCreateBest2OCR->setObjectName(QString::fromUtf8("actionCreateBest2OCR"));
        actionToSlp1 = new QAction(MainWindow);
        actionToSlp1->setObjectName(QString::fromUtf8("actionToSlp1"));
        actionCreateSuggestionLog = new QAction(MainWindow);
        actionCreateSuggestionLog->setObjectName(QString::fromUtf8("actionCreateSuggestionLog"));
        actionCreateSuggestionLogNearestPriority = new QAction(MainWindow);
        actionCreateSuggestionLogNearestPriority->setObjectName(QString::fromUtf8("actionCreateSuggestionLogNearestPriority"));
        actionErrorDetectionRep = new QAction(MainWindow);
        actionErrorDetectionRep->setObjectName(QString::fromUtf8("actionErrorDetectionRep"));
        actionErrorDetectWithoutAdaptation = new QAction(MainWindow);
        actionErrorDetectWithoutAdaptation->setObjectName(QString::fromUtf8("actionErrorDetectWithoutAdaptation"));
        actionCPair = new QAction(MainWindow);
        actionCPair->setObjectName(QString::fromUtf8("actionCPair"));
        actionToSlp1_2 = new QAction(MainWindow);
        actionToSlp1_2->setObjectName(QString::fromUtf8("actionToSlp1_2"));
        actionToDev = new QAction(MainWindow);
        actionToDev->setObjectName(QString::fromUtf8("actionToDev"));
        actionExtractDev = new QAction(MainWindow);
        actionExtractDev->setObjectName(QString::fromUtf8("actionExtractDev"));
        actionPrimarySecOCRPair = new QAction(MainWindow);
        actionPrimarySecOCRPair->setObjectName(QString::fromUtf8("actionPrimarySecOCRPair"));
        actionCPairIEROcrVsCorrect = new QAction(MainWindow);
        actionCPairIEROcrVsCorrect->setObjectName(QString::fromUtf8("actionCPairIEROcrVsCorrect"));
        actionEditDistRep = new QAction(MainWindow);
        actionEditDistRep->setObjectName(QString::fromUtf8("actionEditDistRep"));
        actionConfusionFreqHist = new QAction(MainWindow);
        actionConfusionFreqHist->setObjectName(QString::fromUtf8("actionConfusionFreqHist"));
        actionCPairGEROcrVsCorrect = new QAction(MainWindow);
        actionCPairGEROcrVsCorrect->setObjectName(QString::fromUtf8("actionCPairGEROcrVsCorrect"));
        actionFilterOutGT50EditDisPairs = new QAction(MainWindow);
        actionFilterOutGT50EditDisPairs->setObjectName(QString::fromUtf8("actionFilterOutGT50EditDisPairs"));
        actionPrepareFeatures = new QAction(MainWindow);
        actionPrepareFeatures->setObjectName(QString::fromUtf8("actionPrepareFeatures"));
        actionErrorDetectionRepUniq = new QAction(MainWindow);
        actionErrorDetectionRepUniq->setObjectName(QString::fromUtf8("actionErrorDetectionRepUniq"));
        actionSanskrit = new QAction(MainWindow);
        actionSanskrit->setObjectName(QString::fromUtf8("actionSanskrit"));
        actionHindi = new QAction(MainWindow);
        actionHindi->setObjectName(QString::fromUtf8("actionHindi"));
        actionEnglish = new QAction(MainWindow);
        actionEnglish->setObjectName(QString::fromUtf8("actionEnglish"));
        actionAllFontProperties = new QAction(MainWindow);
        actionAllFontProperties->setObjectName(QString::fromUtf8("actionAllFontProperties"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Images/AllFont.png"), QSize(), QIcon::Normal, QIcon::On);
        actionAllFontProperties->setIcon(icon9);
        actionBold = new QAction(MainWindow);
        actionBold->setObjectName(QString::fromUtf8("actionBold"));
        actionUnBold = new QAction(MainWindow);
        actionUnBold->setObjectName(QString::fromUtf8("actionUnBold"));
        actionLeftAlign = new QAction(MainWindow);
        actionLeftAlign->setObjectName(QString::fromUtf8("actionLeftAlign"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Images/AlignLeft.png"), QSize(), QIcon::Normal, QIcon::On);
        actionLeftAlign->setIcon(icon10);
        actionRightAlign = new QAction(MainWindow);
        actionRightAlign->setObjectName(QString::fromUtf8("actionRightAlign"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Images/AlignRight.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon11.addFile(QString::fromUtf8(":/Images/AlignCenter.png"), QSize(), QIcon::Normal, QIcon::On);
        actionRightAlign->setIcon(icon11);
        actionCentreAlign = new QAction(MainWindow);
        actionCentreAlign->setObjectName(QString::fromUtf8("actionCentreAlign"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/Images/AlignCenter.png"), QSize(), QIcon::Normal, QIcon::On);
        actionCentreAlign->setIcon(icon12);
        actionJusitfiedAlign = new QAction(MainWindow);
        actionJusitfiedAlign->setObjectName(QString::fromUtf8("actionJusitfiedAlign"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/Images/JustifiedAlign.png"), QSize(), QIcon::Normal, QIcon::On);
        actionJusitfiedAlign->setIcon(icon13);
        actionAccuracyLog = new QAction(MainWindow);
        actionAccuracyLog->setObjectName(QString::fromUtf8("actionAccuracyLog"));
        actionOpen_Project = new QAction(MainWindow);
        actionOpen_Project->setObjectName(QString::fromUtf8("actionOpen_Project"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/Images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_Project->setIcon(icon14);
        actionView_File_Hierarchy = new QAction(MainWindow);
        actionView_File_Hierarchy->setObjectName(QString::fromUtf8("actionView_File_Hierarchy"));
        actionTurn_In = new QAction(MainWindow);
        actionTurn_In->setObjectName(QString::fromUtf8("actionTurn_In"));
        actionCompare_Verifier = new QAction(MainWindow);
        actionCompare_Verifier->setObjectName(QString::fromUtf8("actionCompare_Verifier"));
        actionCompare_Corrector = new QAction(MainWindow);
        actionCompare_Corrector->setObjectName(QString::fromUtf8("actionCompare_Corrector"));
        actionAverage_Accuracy = new QAction(MainWindow);
        actionAverage_Accuracy->setObjectName(QString::fromUtf8("actionAverage_Accuracy"));
        actionView_Comments = new QAction(MainWindow);
        actionView_Comments->setObjectName(QString::fromUtf8("actionView_Comments"));
        actionCommit = new QAction(MainWindow);
        actionCommit->setObjectName(QString::fromUtf8("actionCommit"));
        actionFetch_2 = new QAction(MainWindow);
        actionFetch_2->setObjectName(QString::fromUtf8("actionFetch_2"));
        actionPush = new QAction(MainWindow);
        actionPush->setObjectName(QString::fromUtf8("actionPush"));
        actionVerifier_Turn_In = new QAction(MainWindow);
        actionVerifier_Turn_In->setObjectName(QString::fromUtf8("actionVerifier_Turn_In"));
        actionHighlight = new QAction(MainWindow);
        actionHighlight->setObjectName(QString::fromUtf8("actionHighlight"));
        actionZoom_In = new QAction(MainWindow);
        actionZoom_In->setObjectName(QString::fromUtf8("actionZoom_In"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/Images/Zoom-In-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_In->setIcon(icon15);
        actionZoom_Out = new QAction(MainWindow);
        actionZoom_Out->setObjectName(QString::fromUtf8("actionZoom_Out"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/Images/Zoom-Out-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_Out->setIcon(icon16);
        actionDiacritics = new QAction(MainWindow);
        actionDiacritics->setObjectName(QString::fromUtf8("actionDiacritics"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/Images/icon_diacritics.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDiacritics->setIcon(icon17);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_4->addWidget(lineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        gridLayout_3->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(120, 0));
        tabWidget->setMaximumSize(QSize(300, 16777215));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);
        textEdit->setMinimumSize(QSize(120, 0));
        textEdit->setMaximumSize(QSize(300, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("FreeSans"));
        font.setItalic(true);
        textEdit->setFont(font);
        textEdit->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        treeView = new QTreeView(tab_2);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        sizePolicy1.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy1);
        treeView->setMinimumSize(QSize(90, 600));
        treeView->setMaximumSize(QSize(400, 16777215));

        gridLayout_2->addWidget(treeView, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        splitter->addWidget(tabWidget);
        tabWidget_2 = new QTabWidget(splitter);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setTabsClosable(true);
        tabWidget_2->setMovable(true);
        tabWidget_2->setTabBarAutoHide(false);
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        textBrowser = new QTextBrowser(tab_5);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(-70, 20, 600, 600));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy2);
        textBrowser->setMinimumSize(QSize(400, 600));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Shobhika"));
        font1.setPointSize(16);
        font1.setItalic(false);
        textBrowser->setFont(font1);
        textBrowser->setMouseTracking(true);
        textBrowser->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        textBrowser->setUndoRedoEnabled(true);
        textBrowser->setReadOnly(false);
        textBrowser->setAcceptRichText(true);
        textBrowser->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        tabWidget_2->addTab(tab_5, QString());
        splitter->addWidget(tabWidget_2);
        splitter_2->addWidget(splitter);
        graphicsView = new QGraphicsView(splitter_2);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy3);
        graphicsView->setMinimumSize(QSize(400, 600));
        graphicsView->setMaximumSize(QSize(608, 16777215));
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        graphicsView->setAlignment(Qt::AlignCenter);
        graphicsView->setRenderHints(QPainter::NonCosmeticDefaultPen);
        graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
        graphicsView->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
        graphicsView->setResizeAnchor(QGraphicsView::AnchorViewCenter);
        splitter_2->addWidget(graphicsView);

        gridLayout_3->addWidget(splitter_2, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1386, 21));
        menuOCR_Correction_Window = new QMenu(menuBar);
        menuOCR_Correction_Window->setObjectName(QString::fromUtf8("menuOCR_Correction_Window"));
        menuCreateReports = new QMenu(menuBar);
        menuCreateReports->setObjectName(QString::fromUtf8("menuCreateReports"));
        menuSaveVariables = new QMenu(menuBar);
        menuSaveVariables->setObjectName(QString::fromUtf8("menuSaveVariables"));
        menuConvertFiles = new QMenu(menuBar);
        menuConvertFiles->setObjectName(QString::fromUtf8("menuConvertFiles"));
        menuFeatureExtraction = new QMenu(menuBar);
        menuFeatureExtraction->setObjectName(QString::fromUtf8("menuFeatureExtraction"));
        menuSelectLanguage = new QMenu(menuBar);
        menuSelectLanguage->setObjectName(QString::fromUtf8("menuSelectLanguage"));
        menuFontAndLayout = new QMenu(menuBar);
        menuFontAndLayout->setObjectName(QString::fromUtf8("menuFontAndLayout"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuGit = new QMenu(menuBar);
        menuGit->setObjectName(QString::fromUtf8("menuGit"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(textBrowser, graphicsView);

        menuBar->addAction(menuSelectLanguage->menuAction());
        menuBar->addAction(menuOCR_Correction_Window->menuAction());
        menuBar->addAction(menuCreateReports->menuAction());
        menuBar->addAction(menuSaveVariables->menuAction());
        menuBar->addAction(menuFontAndLayout->menuAction());
        menuBar->addAction(menuConvertFiles->menuAction());
        menuBar->addAction(menuFeatureExtraction->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuGit->menuAction());
        menuOCR_Correction_Window->addAction(actionNew);
        menuOCR_Correction_Window->addAction(actionOpen_Project);
        menuOCR_Correction_Window->addAction(actionSave);
        menuOCR_Correction_Window->addAction(actionSave_As);
        menuOCR_Correction_Window->addAction(actionSpell_Check);
        menuOCR_Correction_Window->addAction(actionLoad_Next_Page);
        menuOCR_Correction_Window->addAction(actionLoad_Prev_Page);
        menuOCR_Correction_Window->addSeparator();
        menuOCR_Correction_Window->addAction(actionLoadGDocPage);
        menuOCR_Correction_Window->addAction(actionToDevanagari);
        menuOCR_Correction_Window->addAction(actionLoadData);
        menuOCR_Correction_Window->addAction(actionLoadDict);
        menuOCR_Correction_Window->addAction(actionLoadOCRWords);
        menuOCR_Correction_Window->addAction(actionLoadDomain);
        menuOCR_Correction_Window->addAction(actionLoadSubPS);
        menuOCR_Correction_Window->addAction(actionLoadConfusions);
        menuOCR_Correction_Window->addAction(actionSugg);
        menuOCR_Correction_Window->addAction(actionToSlp1);
        menuCreateReports->addAction(actionCreateBest2OCR);
        menuCreateReports->addAction(actionCreateSuggestionLog);
        menuCreateReports->addAction(actionCreateSuggestionLogNearestPriority);
        menuCreateReports->addAction(actionErrorDetectionRep);
        menuCreateReports->addAction(actionErrorDetectWithoutAdaptation);
        menuCreateReports->addAction(actionErrorDetectionRepUniq);
        menuCreateReports->addAction(actionAccuracyLog);
        menuSaveVariables->addAction(actionCPair);
        menuSaveVariables->addAction(actionPrimarySecOCRPair);
        menuSaveVariables->addAction(actionCPairIEROcrVsCorrect);
        menuSaveVariables->addAction(actionCPairGEROcrVsCorrect);
        menuConvertFiles->addAction(actionToSlp1_2);
        menuConvertFiles->addAction(actionToDev);
        menuConvertFiles->addAction(actionExtractDev);
        menuConvertFiles->addAction(actionEditDistRep);
        menuConvertFiles->addAction(actionConfusionFreqHist);
        menuConvertFiles->addAction(actionFilterOutGT50EditDisPairs);
        menuFeatureExtraction->addAction(actionPrepareFeatures);
        menuSelectLanguage->addAction(actionSanskrit);
        menuSelectLanguage->addAction(actionHindi);
        menuSelectLanguage->addAction(actionEnglish);
        menuFontAndLayout->addAction(actionAllFontProperties);
        menuFontAndLayout->addAction(actionBold);
        menuFontAndLayout->addAction(actionUnBold);
        menuFontAndLayout->addAction(actionHighlight);
        menuFontAndLayout->addSeparator();
        menuFontAndLayout->addAction(actionLeftAlign);
        menuFontAndLayout->addAction(actionRightAlign);
        menuFontAndLayout->addAction(actionCentreAlign);
        menuFontAndLayout->addAction(actionJusitfiedAlign);
        menuView->addAction(actionCompare_Verifier);
        menuView->addAction(actionCompare_Corrector);
        menuView->addSeparator();
        menuView->addAction(actionAverage_Accuracy);
        menuView->addAction(actionView_Comments);
        menuGit->addAction(actionTurn_In);
        menuGit->addAction(actionCommit);
        menuGit->addAction(actionFetch_2);
        menuGit->addAction(actionVerifier_Turn_In);
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen_Project);
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionSave_As);
        mainToolBar->addAction(actionLoadData);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSpell_Check);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionLoad_Prev_Page);
        mainToolBar->addAction(actionLoad_Next_Page);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionLoadGDocPage);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSanskrit);
        mainToolBar->addAction(actionEnglish);
        mainToolBar->addAction(actionHindi);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionToDevanagari);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAllFontProperties);
        mainToolBar->addAction(actionBold);
        mainToolBar->addAction(actionUnBold);
        mainToolBar->addAction(actionLeftAlign);
        mainToolBar->addAction(actionCentreAlign);
        mainToolBar->addAction(actionRightAlign);
        mainToolBar->addAction(actionJusitfiedAlign);
        mainToolBar->addAction(actionHighlight);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionZoom_In);
        mainToolBar->addAction(actionZoom_Out);
        mainToolBar->addAction(actionDiacritics);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_As->setText(QCoreApplication::translate("MainWindow", "Save As", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_As->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSpell_Check->setText(QCoreApplication::translate("MainWindow", "Spell Check(CntrlShftC)", nullptr));
#if QT_CONFIG(shortcut)
        actionSpell_Check->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLoad_Next_Page->setText(QCoreApplication::translate("MainWindow", "Page(CntlShiftR)>>", nullptr));
#if QT_CONFIG(tooltip)
        actionLoad_Next_Page->setToolTip(QCoreApplication::translate("MainWindow", "Page(CntlShiftR)>>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionLoad_Next_Page->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLoad_Prev_Page->setText(QCoreApplication::translate("MainWindow", "<<Page(CntrlShftL)", nullptr));
#if QT_CONFIG(tooltip)
        actionLoad_Prev_Page->setToolTip(QCoreApplication::translate("MainWindow", "<<Page(CntrlShftL)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionLoad_Prev_Page->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+L", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLoadGDocPage->setText(QCoreApplication::translate("MainWindow", "Save&LoadPWords(CntrlShftP)", nullptr));
#if QT_CONFIG(shortcut)
        actionLoadGDocPage->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionToDevanagari->setText(QCoreApplication::translate("MainWindow", "toDevanagari(CntrlD)", nullptr));
#if QT_CONFIG(shortcut)
        actionToDevanagari->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLoadData->setText(QCoreApplication::translate("MainWindow", "LoadData", nullptr));
        actionLoadDict->setText(QCoreApplication::translate("MainWindow", "LoadDict", nullptr));
        actionLoadOCRWords->setText(QCoreApplication::translate("MainWindow", "LoadOCRWords", nullptr));
        actionLoadDomain->setText(QCoreApplication::translate("MainWindow", "LoadDomain", nullptr));
        actionLoadSubPS->setText(QCoreApplication::translate("MainWindow", "LoadSubPS", nullptr));
        actionLoadConfusions->setText(QCoreApplication::translate("MainWindow", "LoadConfusions", nullptr));
        actionSugg->setText(QCoreApplication::translate("MainWindow", "sugg", nullptr));
#if QT_CONFIG(shortcut)
        actionSugg->setShortcut(QCoreApplication::translate("MainWindow", "Menu", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCreateBest2OCR->setText(QCoreApplication::translate("MainWindow", "CreateBest2OCR", nullptr));
        actionToSlp1->setText(QCoreApplication::translate("MainWindow", "toSlp1", nullptr));
#if QT_CONFIG(shortcut)
        actionToSlp1->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+G", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCreateSuggestionLog->setText(QCoreApplication::translate("MainWindow", "CreateSuggestionLog", nullptr));
        actionCreateSuggestionLogNearestPriority->setText(QCoreApplication::translate("MainWindow", "CreateSuggestionLogNearestPriority", nullptr));
        actionErrorDetectionRep->setText(QCoreApplication::translate("MainWindow", "ErrorDetectionRep", nullptr));
        actionErrorDetectWithoutAdaptation->setText(QCoreApplication::translate("MainWindow", "ErrorDetectWithoutAdaptation", nullptr));
        actionCPair->setText(QCoreApplication::translate("MainWindow", "CPair", nullptr));
        actionToSlp1_2->setText(QCoreApplication::translate("MainWindow", "toSlp1", nullptr));
        actionToDev->setText(QCoreApplication::translate("MainWindow", "toDev", nullptr));
        actionExtractDev->setText(QCoreApplication::translate("MainWindow", "ExtractDevWords", nullptr));
#if QT_CONFIG(tooltip)
        actionExtractDev->setToolTip(QCoreApplication::translate("MainWindow", "ExtractDevWords", nullptr));
#endif // QT_CONFIG(tooltip)
        actionPrimarySecOCRPair->setText(QCoreApplication::translate("MainWindow", "PrimarySecOCRPairs", nullptr));
        actionCPairIEROcrVsCorrect->setText(QCoreApplication::translate("MainWindow", "CPairIEROcrVsCorrect", nullptr));
        actionEditDistRep->setText(QCoreApplication::translate("MainWindow", "EditDistRep", nullptr));
        actionConfusionFreqHist->setText(QCoreApplication::translate("MainWindow", "ConfusionFreqHist", nullptr));
        actionCPairGEROcrVsCorrect->setText(QCoreApplication::translate("MainWindow", "CPairGEROcrVsCorrect", nullptr));
        actionFilterOutGT50EditDisPairs->setText(QCoreApplication::translate("MainWindow", "FilterOutGT50EditDisPairs", nullptr));
        actionPrepareFeatures->setText(QCoreApplication::translate("MainWindow", "PrepareFeatures", nullptr));
        actionErrorDetectionRepUniq->setText(QCoreApplication::translate("MainWindow", "ErrorSuggRepUniq", nullptr));
        actionSanskrit->setText(QCoreApplication::translate("MainWindow", "Sanskrit", nullptr));
        actionHindi->setText(QCoreApplication::translate("MainWindow", "Hindi/Marathi", nullptr));
        actionEnglish->setText(QCoreApplication::translate("MainWindow", "English", nullptr));
#if QT_CONFIG(tooltip)
        actionEnglish->setToolTip(QCoreApplication::translate("MainWindow", "English", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAllFontProperties->setText(QCoreApplication::translate("MainWindow", "AllFontProperties", nullptr));
        actionBold->setText(QCoreApplication::translate("MainWindow", "Bold", nullptr));
        actionUnBold->setText(QCoreApplication::translate("MainWindow", "UnBold", nullptr));
        actionLeftAlign->setText(QCoreApplication::translate("MainWindow", "LeftAlign", nullptr));
        actionRightAlign->setText(QCoreApplication::translate("MainWindow", "RightAlign", nullptr));
        actionCentreAlign->setText(QCoreApplication::translate("MainWindow", "CentreAlign", nullptr));
        actionJusitfiedAlign->setText(QCoreApplication::translate("MainWindow", "JusitfiedAlign", nullptr));
        actionAccuracyLog->setText(QCoreApplication::translate("MainWindow", "AccuracyLog", nullptr));
        actionOpen_Project->setText(QCoreApplication::translate("MainWindow", "Open Project", nullptr));
        actionView_File_Hierarchy->setText(QCoreApplication::translate("MainWindow", "View File Hierarchy", nullptr));
        actionTurn_In->setText(QCoreApplication::translate("MainWindow", "Turn In", nullptr));
        actionCompare_Verifier->setText(QCoreApplication::translate("MainWindow", "Verifier Diff View", nullptr));
        actionCompare_Corrector->setText(QCoreApplication::translate("MainWindow", "Corrector Diff View", nullptr));
        actionAverage_Accuracy->setText(QCoreApplication::translate("MainWindow", "Average Accuracy", nullptr));
        actionView_Comments->setText(QCoreApplication::translate("MainWindow", "View Comments", nullptr));
        actionCommit->setText(QCoreApplication::translate("MainWindow", "Commit", nullptr));
        actionFetch_2->setText(QCoreApplication::translate("MainWindow", "Pull", nullptr));
        actionPush->setText(QCoreApplication::translate("MainWindow", "Push", nullptr));
        actionVerifier_Turn_In->setText(QCoreApplication::translate("MainWindow", "Verifier Turn In", nullptr));
        actionHighlight->setText(QCoreApplication::translate("MainWindow", "Highlight", nullptr));
        actionZoom_In->setText(QCoreApplication::translate("MainWindow", "Zoom In", nullptr));
#if QT_CONFIG(tooltip)
        actionZoom_In->setToolTip(QCoreApplication::translate("MainWindow", "Zoom In", nullptr));
#endif // QT_CONFIG(tooltip)
        actionZoom_Out->setText(QCoreApplication::translate("MainWindow", "Zoom Out", nullptr));
#if QT_CONFIG(tooltip)
        actionZoom_Out->setToolTip(QCoreApplication::translate("MainWindow", "Zoom Out", nullptr));
#endif // QT_CONFIG(tooltip)
        actionDiacritics->setText(QCoreApplication::translate("MainWindow", "Diacritics", nullptr));
#if QT_CONFIG(tooltip)
        actionDiacritics->setToolTip(QCoreApplication::translate("MainWindow", "Diacritics", nullptr));
#endif // QT_CONFIG(tooltip)
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "SLP", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Project", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Shobhika'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">Please Select the Language from top left menu before loading any document.</span></p></body></html>", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        menuOCR_Correction_Window->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuCreateReports->setTitle(QCoreApplication::translate("MainWindow", "CreateReports", nullptr));
        menuSaveVariables->setTitle(QCoreApplication::translate("MainWindow", "SaveVariables", nullptr));
        menuConvertFiles->setTitle(QCoreApplication::translate("MainWindow", "ConvertFiles", nullptr));
        menuFeatureExtraction->setTitle(QCoreApplication::translate("MainWindow", "FeatureExtraction", nullptr));
        menuSelectLanguage->setTitle(QCoreApplication::translate("MainWindow", "SelectLanguage", nullptr));
        menuFontAndLayout->setTitle(QCoreApplication::translate("MainWindow", "FontAndLayout", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuGit->setTitle(QCoreApplication::translate("MainWindow", "Version Control", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
