/********************************************************************************
** Form generated from reading UI file 'interndiffview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERNDIFFVIEW_H
#define UI_INTERNDIFFVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            InternDiffView->setObjectName(QStringLiteral("InternDiffView"));
        InternDiffView->resize(1157, 576);
        InternDiffView->setStyleSheet(QStringLiteral("background-color: rgb(32, 33, 72);"));
        centralWidget = new QWidget(InternDiffView);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        prevButton = new QPushButton(centralWidget);
        prevButton->setObjectName(QStringLiteral("prevButton"));
        prevButton->setStyleSheet(QStringLiteral("border: 0px; "));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/Resources/Previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        prevButton->setIcon(icon);

        horizontalLayout->addWidget(prevButton);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setStyleSheet(QLatin1String("QScrollBar:vertical { \n"
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
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        graphicsView = new QGraphicsView(layoutWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QFont font;
        font.setFamily(QStringLiteral("Shobhika"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        graphicsView->setFont(font);
        graphicsView->setStyleSheet(QStringLiteral("background-color:white; color:black;"));
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

        verticalLayout_3->addWidget(graphicsView);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        OCRtextLabel = new QLabel(layoutWidget1);
        OCRtextLabel->setObjectName(QStringLiteral("OCRtextLabel"));
        OCRtextLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        OCRtextLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(OCRtextLabel);

        ocroutput = new QTextBrowser(layoutWidget1);
        ocroutput->setObjectName(QStringLiteral("ocroutput"));
        QFont font1;
        font1.setFamily(QStringLiteral("Shobhika"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        ocroutput->setFont(font1);
        ocroutput->setStyleSheet(QStringLiteral("background-color:white; color:black;"));

        verticalLayout->addWidget(ocroutput);

        splitter->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(splitter);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        InternLabel = new QLabel(layoutWidget2);
        InternLabel->setObjectName(QStringLiteral("InternLabel"));
        InternLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        InternLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(InternLabel);

        current = new QTextBrowser(layoutWidget2);
        current->setObjectName(QStringLiteral("current"));
        current->setFont(font1);
        current->setStyleSheet(QStringLiteral("background-color:white; color:black;"));

        verticalLayout_2->addWidget(current);

        splitter->addWidget(layoutWidget2);

        horizontalLayout->addWidget(splitter);

        NextButton = new QPushButton(centralWidget);
        NextButton->setObjectName(QStringLiteral("NextButton"));
        NextButton->setStyleSheet(QStringLiteral("border: 0px; "));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/Resources/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        NextButton->setIcon(icon1);

        horizontalLayout->addWidget(NextButton);

        InternDiffView->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(InternDiffView);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        InternDiffView->setStatusBar(statusBar);

        retranslateUi(InternDiffView);

        QMetaObject::connectSlotsByName(InternDiffView);
    } // setupUi

    void retranslateUi(QMainWindow *InternDiffView)
    {
        InternDiffView->setWindowTitle(QApplication::translate("InternDiffView", "InternDiffView", Q_NULLPTR));
        prevButton->setText(QString());
        label->setText(QApplication::translate("InternDiffView", "<p><b>1. OCR Image<b></p>\n"
"<p> </p>", Q_NULLPTR));
        OCRtextLabel->setText(QApplication::translate("InternDiffView", "<p><b>2. Initial Text<b></p>\n"
"<p> </p>", Q_NULLPTR));
        ocroutput->setHtml(QApplication::translate("InternDiffView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Shobhika'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:400;\"><br /></p></body></html>", Q_NULLPTR));
        InternLabel->setText(QApplication::translate("InternDiffView", "<p><b>3. Corrector's Output Text</b></p>Changes made by Corrector: ", Q_NULLPTR));
        current->setHtml(QApplication::translate("InternDiffView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Shobhika'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:400;\"><br /></p></body></html>", Q_NULLPTR));
        NextButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class InternDiffView: public Ui_InternDiffView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERNDIFFVIEW_H
