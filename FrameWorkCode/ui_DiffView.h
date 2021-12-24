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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DiffView
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *PrevButton;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *OCRLabel;
    QTextEdit *OCRText;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *InternLabel;
    QTextEdit *InternText;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QLabel *VerifierLabel;
    QTextEdit *VerifierText;
    QPushButton *NextButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DiffView)
    {
        if (DiffView->objectName().isEmpty())
            DiffView->setObjectName(QString::fromUtf8("DiffView"));
        DiffView->resize(1280, 516);
        DiffView->setStyleSheet(QString::fromUtf8("font: 11pt \"Work Sans\";\n"
"background-color: rgb(32, 33, 72);"));
        centralWidget = new QWidget(DiffView);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        PrevButton = new QPushButton(centralWidget);
        PrevButton->setObjectName(QString::fromUtf8("PrevButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        PrevButton->setIcon(icon);

        horizontalLayout_3->addWidget(PrevButton);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setStyleSheet(QString::fromUtf8("QScrollBar:vertical { \n"
"                                                border: none;\n"
"                                                background: white;\n"
"                                                width: 9.81px;\n"
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
"                            subcontrol-position: top; \n"
"            "
                        "                subcontrol-origin: margin; \n"
"                        }\n"
""));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        OCRLabel = new QLabel(layoutWidget);
        OCRLabel->setObjectName(QString::fromUtf8("OCRLabel"));
        OCRLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        OCRLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(OCRLabel);

        OCRText = new QTextEdit(layoutWidget);
        OCRText->setObjectName(QString::fromUtf8("OCRText"));
        QFont font;
        font.setFamily(QString::fromUtf8("Work Sans"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        OCRText->setFont(font);
        OCRText->setStyleSheet(QString::fromUtf8("background-color:white; color:black;"));

        verticalLayout_3->addWidget(OCRText);

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
        InternLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        InternLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(InternLabel);

        InternText = new QTextEdit(layoutWidget1);
        InternText->setObjectName(QString::fromUtf8("InternText"));
        InternText->setFont(font);
        InternText->setStyleSheet(QString::fromUtf8("background-color:white; color:black;"));

        verticalLayout_2->addWidget(InternText);

        splitter->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(splitter);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        VerifierLabel = new QLabel(layoutWidget2);
        VerifierLabel->setObjectName(QString::fromUtf8("VerifierLabel"));
        VerifierLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        VerifierLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(VerifierLabel);

        VerifierText = new QTextEdit(layoutWidget2);
        VerifierText->setObjectName(QString::fromUtf8("VerifierText"));
        VerifierText->setFont(font);
        VerifierText->setStyleSheet(QString::fromUtf8("background-color:white; color:black;"));

        verticalLayout->addWidget(VerifierText);

        splitter->addWidget(layoutWidget2);

        horizontalLayout_3->addWidget(splitter);

        NextButton = new QPushButton(centralWidget);
        NextButton->setObjectName(QString::fromUtf8("NextButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        NextButton->setIcon(icon1);
        NextButton->setAutoDefault(false);

        horizontalLayout_3->addWidget(NextButton);

        DiffView->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DiffView);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DiffView->setStatusBar(statusBar);

        retranslateUi(DiffView);

        QMetaObject::connectSlotsByName(DiffView);
    } // setupUi

    void retranslateUi(QMainWindow *DiffView)
    {
        DiffView->setWindowTitle(QApplication::translate("DiffView", "DiffView", nullptr));
        PrevButton->setText(QString());
        OCRLabel->setText(QApplication::translate("DiffView", "<p><b>1. Initial Text </b></p>\n"
"Accuracy of OCR Text (w.r.t Verified Text): ", nullptr));
        OCRText->setHtml(QApplication::translate("DiffView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Work Sans'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Shobhika Regular';\"><br /></p></body></html>", nullptr));
        InternLabel->setText(QApplication::translate("DiffView", "<b><p>2. Corrector's Output Text</b></p>Changes Made by Corrector: ", nullptr));
        InternText->setHtml(QApplication::translate("DiffView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Work Sans'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Shobhika Regular';\"><br /></p></body></html>", nullptr));
        VerifierLabel->setText(QApplication::translate("DiffView", "<p><b>3. Verified Text</b></p>\n"
"Changes Made by Verifier: ", nullptr));
        VerifierText->setHtml(QApplication::translate("DiffView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Work Sans'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Shobhika Regular';\"><br /></p></body></html>", nullptr));
        NextButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DiffView: public Ui_DiffView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFVIEW_H
