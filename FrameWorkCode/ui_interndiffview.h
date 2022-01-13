/********************************************************************************
** Form generated from reading UI file 'interndiffview.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERNDIFFVIEW_H
#define UI_INTERNDIFFVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InternDiffView
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *prevButton;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QGraphicsView *graphicsView;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *OCRtextLabel;
    QTextBrowser *ocroutput;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QLabel *InternLabel;
    QTextBrowser *current;
    QPushButton *NextButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *InternDiffView)
    {
        if (InternDiffView->objectName().isEmpty())
            InternDiffView->setObjectName(QString::fromUtf8("InternDiffView"));
        InternDiffView->resize(1157, 576);
        InternDiffView->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 33, 72);"));
        centralWidget = new QWidget(InternDiffView);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        prevButton = new QPushButton(centralWidget);
        prevButton->setObjectName(QString::fromUtf8("prevButton"));
        prevButton->setStyleSheet(QString::fromUtf8("border: 0px; "));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/Resources/Previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        prevButton->setIcon(icon);

        horizontalLayout->addWidget(prevButton);

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
"                            subcontrol-position: top"
                        "; \n"
"                            subcontrol-origin: margin; \n"
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
"														border-radius:4.905px;\n"
"                                            }\n"
"QScrollBar::add-line:horizontal {       \n"
"                            height: 0px;\n"
"                            subcontrol-position: bottom; \n"
"                            subcontrol-origin: margin; \n"
"								\n"
"                        } \n"
"QScrollBar::sub-line:horizontal { \n"
"                            height: 0 px; \n"
"                            subcontrol-position: t"
                        "op; \n"
"                            subcontrol-origin: margin; \n"
"                        }\n"
"\n"
""));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        graphicsView = new QGraphicsView(layoutWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QFont font;
        font.setFamily(QString::fromUtf8("Shobhika"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        graphicsView->setFont(font);
        graphicsView->setStyleSheet(QString::fromUtf8("background-color:white; color:black;"));
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

        verticalLayout_3->addWidget(graphicsView);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        OCRtextLabel = new QLabel(layoutWidget1);
        OCRtextLabel->setObjectName(QString::fromUtf8("OCRtextLabel"));
        OCRtextLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        OCRtextLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(OCRtextLabel);

        ocroutput = new QTextBrowser(layoutWidget1);
        ocroutput->setObjectName(QString::fromUtf8("ocroutput"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Shobhika"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        ocroutput->setFont(font1);
        ocroutput->setStyleSheet(QString::fromUtf8("background-color:white; color:black;"));

        verticalLayout->addWidget(ocroutput);

        splitter->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(splitter);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        InternLabel = new QLabel(layoutWidget2);
        InternLabel->setObjectName(QString::fromUtf8("InternLabel"));
        InternLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        InternLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(InternLabel);

        current = new QTextBrowser(layoutWidget2);
        current->setObjectName(QString::fromUtf8("current"));
        current->setFont(font1);
        current->setStyleSheet(QString::fromUtf8("background-color:white; color:black;"));

        verticalLayout_2->addWidget(current);

        splitter->addWidget(layoutWidget2);

        horizontalLayout->addWidget(splitter);

        NextButton = new QPushButton(centralWidget);
        NextButton->setObjectName(QString::fromUtf8("NextButton"));
        NextButton->setStyleSheet(QString::fromUtf8("border: 0px; "));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/Resources/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        NextButton->setIcon(icon1);

        horizontalLayout->addWidget(NextButton);

        InternDiffView->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(InternDiffView);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        InternDiffView->setStatusBar(statusBar);

        retranslateUi(InternDiffView);

        QMetaObject::connectSlotsByName(InternDiffView);
    } // setupUi

    void retranslateUi(QMainWindow *InternDiffView)
    {
        InternDiffView->setWindowTitle(QApplication::translate("InternDiffView", "InternDiffView", nullptr));
        prevButton->setText(QString());
        label->setText(QApplication::translate("InternDiffView", "<p><b>1. OCR Image<b></p>\n"
"<p> </p>", nullptr));
        OCRtextLabel->setText(QApplication::translate("InternDiffView", "<p><b>2. Initial Text<b></p>\n"
"<p> </p>", nullptr));
        ocroutput->setHtml(QApplication::translate("InternDiffView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Shobhika'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:400;\"><br /></p></body></html>", nullptr));
        InternLabel->setText(QApplication::translate("InternDiffView", "<p><b>3. Corrector's Output Text</b></p>Changes made by Corrector: ", nullptr));
        current->setHtml(QApplication::translate("InternDiffView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Shobhika'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:400;\"><br /></p></body></html>", nullptr));
        NextButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class InternDiffView: public Ui_InternDiffView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERNDIFFVIEW_H
