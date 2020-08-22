/********************************************************************************
** Form generated from reading UI file 'DiffView.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFFVIEW_H
#define UI_DIFFVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
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
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *VerifierLabel;
    QTextEdit *VerifierText;
    QVBoxLayout *verticalLayout_2;
    QLabel *InternLabel;
    QTextEdit *InternText;
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
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        VerifierLabel = new QLabel(centralWidget);
        VerifierLabel->setObjectName(QString::fromUtf8("VerifierLabel"));
        VerifierLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(VerifierLabel);

        VerifierText = new QTextEdit(centralWidget);
        VerifierText->setObjectName(QString::fromUtf8("VerifierText"));
        QFont font;
        font.setFamily(QString::fromUtf8("Shobhika"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        VerifierText->setFont(font);

        verticalLayout_3->addWidget(VerifierText);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        InternLabel = new QLabel(centralWidget);
        InternLabel->setObjectName(QString::fromUtf8("InternLabel"));
        InternLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(InternLabel);

        InternText = new QTextEdit(centralWidget);
        InternText->setObjectName(QString::fromUtf8("InternText"));
        InternText->setFont(font);

        verticalLayout_2->addWidget(InternText);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        OCRLabel = new QLabel(centralWidget);
        OCRLabel->setObjectName(QString::fromUtf8("OCRLabel"));
        OCRLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(OCRLabel);

        OCRText = new QTextEdit(centralWidget);
        OCRText->setObjectName(QString::fromUtf8("OCRText"));
        OCRText->setFont(font);

        verticalLayout->addWidget(OCRText);


        horizontalLayout->addLayout(verticalLayout);

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
        DiffView->setWindowTitle(QCoreApplication::translate("DiffView", "DiffView", nullptr));
        VerifierLabel->setText(QCoreApplication::translate("DiffView", "<p><b>Verified Text</b></p>\n"
"Changes Made by Verifier: ", nullptr));
        VerifierText->setHtml(QCoreApplication::translate("DiffView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Shobhika'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Shobhika Regular'; font-weight:400;\"><br /></p></body></html>", nullptr));
        InternLabel->setText(QCoreApplication::translate("DiffView", "<b><p>Corrector's Output Text</b></p>Changes Made by Corrector: ", nullptr));
        InternText->setHtml(QCoreApplication::translate("DiffView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Shobhika'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Shobhika Regular'; font-weight:400;\"><br /></p></body></html>", nullptr));
        OCRLabel->setText(QCoreApplication::translate("DiffView", "<p><b>OCR Text </b><i>(To be Replaced with Image)</i></p>\n"
"Accuracy of OCR Text (w.r.t Verified Text): ", nullptr));
        OCRText->setHtml(QCoreApplication::translate("DiffView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
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
