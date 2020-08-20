/********************************************************************************
** Form generated from reading UI file 'verifierdiffview.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERIFIERDIFFVIEW_H
#define UI_VERIFIERDIFFVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VerifierDiffView
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QTextBrowser *textBrowser_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VerifierDiffView)
    {
        if (VerifierDiffView->objectName().isEmpty())
            VerifierDiffView->setObjectName(QString::fromUtf8("VerifierDiffView"));
        VerifierDiffView->resize(850, 547);
        centralWidget = new QWidget(VerifierDiffView);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        textBrowser = new QTextBrowser(splitter);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        splitter->addWidget(textBrowser);
        textBrowser_2 = new QTextBrowser(splitter);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        splitter->addWidget(textBrowser_2);
        textBrowser_3 = new QTextBrowser(splitter);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));
        splitter->addWidget(textBrowser_3);

        horizontalLayout->addWidget(splitter);

        VerifierDiffView->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VerifierDiffView);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 850, 21));
        VerifierDiffView->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VerifierDiffView);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        VerifierDiffView->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(VerifierDiffView);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        VerifierDiffView->setStatusBar(statusBar);

        retranslateUi(VerifierDiffView);

        QMetaObject::connectSlotsByName(VerifierDiffView);
    } // setupUi

    void retranslateUi(QMainWindow *VerifierDiffView)
    {
        VerifierDiffView->setWindowTitle(QCoreApplication::translate("VerifierDiffView", "VerifierDiffView", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VerifierDiffView: public Ui_VerifierDiffView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERIFIERDIFFVIEW_H
