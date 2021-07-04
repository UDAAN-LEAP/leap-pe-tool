/********************************************************************************
** Form generated from reading UI file 'DiffView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFFVIEW_H
#define UI_DIFFVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DiffView
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *VerifierLabel;
    QTextEdit *VerifierText;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *InternLabel;
    QTextEdit *InternText;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QLabel *OCRLabel;
    QTextEdit *OCRText;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DiffView)
    {
        if (DiffView->objectName().isEmpty())
            DiffView->setObjectName(QString::fromUtf8("DiffView"));
        DiffView->resize(1271, 508);
        centralWidget = new QWidget(DiffView);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        VerifierLabel = new QLabel(layoutWidget);
        VerifierLabel->setObjectName(QString::fromUtf8("VerifierLabel"));
        VerifierLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(VerifierLabel);

        VerifierText = new QTextEdit(layoutWidget);
        VerifierText->setObjectName(QString::fromUtf8("VerifierText"));
        QFont font;
        font.setFamily(QString::fromUtf8("Shobhika"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        VerifierText->setFont(font);

        verticalLayout_3->addWidget(VerifierText);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        InternLabel = new QLabel(layoutWidget1);
        InternLabel->setObjectName(QString::fromUtf8("InternLabel"));
        InternLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(InternLabel);

        InternText = new QTextEdit(layoutWidget1);
        InternText->setObjectName(QString::fromUtf8("InternText"));
        InternText->setFont(font);

        verticalLayout_2->addWidget(InternText);

        splitter->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(splitter);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        OCRLabel = new QLabel(layoutWidget2);
        OCRLabel->setObjectName(QString::fromUtf8("OCRLabel"));
        OCRLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(OCRLabel);

        OCRText = new QTextEdit(layoutWidget2);
        OCRText->setObjectName(QString::fromUtf8("OCRText"));
        OCRText->setFont(font);

        verticalLayout->addWidget(OCRText);

        splitter->addWidget(layoutWidget2);

        verticalLayout_4->addWidget(splitter);

        DiffView->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DiffView);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1271, 22));
        DiffView->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DiffView);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        DiffView->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DiffView);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DiffView->setStatusBar(statusBar);

        retranslateUi(DiffView);

        QMetaObject::connectSlotsByName(DiffView);
    } // setupUi

    void retranslateUi(QMainWindow *DiffView)
    {
        DiffView->setWindowTitle(QApplication::translate("DiffView", "DiffView", nullptr));
        VerifierLabel->setText(QApplication::translate("DiffView", "<p><b>Verified Text</b></p>\n"
"Changes Made by Verifier: ", nullptr));
        VerifierText->setHtml(QApplication::translate("DiffView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Shobhika'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Shobhika Regular'; font-weight:400;\"><br /></p></body></html>", nullptr));
        InternLabel->setText(QApplication::translate("DiffView", "<b><p>Corrector's Output Text</b></p>Changes Made by Corrector: ", nullptr));
        InternText->setHtml(QApplication::translate("DiffView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Shobhika'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Shobhika Regular'; font-weight:400;\"><br /></p></body></html>", nullptr));
        OCRLabel->setText(QApplication::translate("DiffView", "<p><b>OCR Text </b></p>\n"
"Accuracy of OCR Text (w.r.t Verified Text): ", nullptr));
        OCRText->setHtml(QApplication::translate("DiffView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Shobhika'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Shobhika Regular'; font-weight:400;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DiffView: public Ui_DiffView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFVIEW_H
