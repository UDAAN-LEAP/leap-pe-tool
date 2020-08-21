/********************************************************************************
** Form generated from reading UI file 'interndiffview.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERNDIFFVIEW_H
#define UI_INTERNDIFFVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InternDiffView
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *InternLabel;
    QTextBrowser *current;
    QVBoxLayout *verticalLayout;
    QLabel *OCRtextLabel;
    QTextBrowser *ocroutput;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *InternDiffView)
    {
        if (InternDiffView->objectName().isEmpty())
            InternDiffView->setObjectName(QString::fromUtf8("InternDiffView"));
        InternDiffView->resize(1175, 576);
        centralWidget = new QWidget(InternDiffView);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        InternLabel = new QLabel(centralWidget);
        InternLabel->setObjectName(QString::fromUtf8("InternLabel"));
        InternLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(InternLabel);

        current = new QTextBrowser(centralWidget);
        current->setObjectName(QString::fromUtf8("current"));
        QFont font;
        font.setFamily(QString::fromUtf8("Shobhika"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        current->setFont(font);

        verticalLayout_3->addWidget(current);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        OCRtextLabel = new QLabel(centralWidget);
        OCRtextLabel->setObjectName(QString::fromUtf8("OCRtextLabel"));
        OCRtextLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(OCRtextLabel);

        ocroutput = new QTextBrowser(centralWidget);
        ocroutput->setObjectName(QString::fromUtf8("ocroutput"));
        ocroutput->setFont(font);

        verticalLayout->addWidget(ocroutput);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Shobhika"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        graphicsView->setFont(font1);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

        verticalLayout_2->addWidget(graphicsView);


        horizontalLayout->addLayout(verticalLayout_2);

        InternDiffView->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(InternDiffView);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1175, 22));
        InternDiffView->setMenuBar(menuBar);
        mainToolBar = new QToolBar(InternDiffView);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        InternDiffView->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(InternDiffView);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        InternDiffView->setStatusBar(statusBar);

        retranslateUi(InternDiffView);

        QMetaObject::connectSlotsByName(InternDiffView);
    } // setupUi

    void retranslateUi(QMainWindow *InternDiffView)
    {
        InternDiffView->setWindowTitle(QCoreApplication::translate("InternDiffView", "InternDiffView", nullptr));
        InternLabel->setText(QCoreApplication::translate("InternDiffView", "<p><b>Corrector's Output Text</b></p>Changes made by Corrector: ", nullptr));
        current->setHtml(QCoreApplication::translate("InternDiffView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Shobhika'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:400;\"><br /></p></body></html>", nullptr));
        OCRtextLabel->setText(QCoreApplication::translate("InternDiffView", "<p><b>OCR Text<b></p>\n"
"<p> </p>", nullptr));
        ocroutput->setHtml(QCoreApplication::translate("InternDiffView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Shobhika'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:400;\"><br /></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("InternDiffView", "<p><b>OCR Image<b></p>\n"
"<p> </p>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InternDiffView: public Ui_InternDiffView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERNDIFFVIEW_H
