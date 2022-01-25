/********************************************************************************
** Form generated from reading UI file 'interndiffview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERNDIFFVIEW_H
#define UI_INTERNDIFFVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InternDiffView
{
public:
    QWidget *centralWidget;
    QPushButton *prevButton;
    QPushButton *NextButton;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *zoom_Out_Button;
    QSlider *horizontalSlider;
    QPushButton *zoom_In_Button;
    QLabel *zoom_level_value;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGraphicsView *graphicsView;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *OCRtextLabel;
    QTextBrowser *ocroutput;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *InternLabel;
    QTextBrowser *current;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *InternDiffView)
    {
        if (InternDiffView->objectName().isEmpty())
            InternDiffView->setObjectName(QString::fromUtf8("InternDiffView"));
        InternDiffView->resize(1157, 576);
        InternDiffView->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(32, 33, 72);\n"
""));
        centralWidget = new QWidget(InternDiffView);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        prevButton = new QPushButton(centralWidget);
        prevButton->setObjectName(QString::fromUtf8("prevButton"));
        prevButton->setGeometry(QRect(9, 269, 20, 16));
        prevButton->setStyleSheet(QString::fromUtf8("border: 0px; "));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/Resources/Previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        prevButton->setIcon(icon);
        NextButton = new QPushButton(centralWidget);
        NextButton->setObjectName(QString::fromUtf8("NextButton"));
        NextButton->setGeometry(QRect(1128, 269, 20, 16));
        NextButton->setStyleSheet(QString::fromUtf8("border: 0px; "));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/Resources/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        NextButton->setIcon(icon1);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(40, 510, 264, 37));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(264, 37));
        groupBox->setMaximumSize(QSize(264, 37));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	background: white;\n"
"	padding-top:15px;\n"
"	margin-top:-15px; \n"
"   height:37.9px;\n"
"   font-size: 11pt !important;\n"
"}\n"
""));
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        zoom_Out_Button = new QPushButton(groupBox);
        zoom_Out_Button->setObjectName(QString::fromUtf8("zoom_Out_Button"));
        zoom_Out_Button->setStyleSheet(QString::fromUtf8("#zoom_Out_Button {\n"
"	color: #202148;\n"
"	background: white;\n"
"	font-size: 24px;\n"
"	padding-right: 12px;\n"
"	padding-left: 12px;\n"
"	border: none;\n"
"}"));

        horizontalLayout_3->addWidget(zoom_Out_Button);

        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setStyleSheet(QString::fromUtf8("QSlider {\n"
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
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setSingleStep(10);
        horizontalSlider->setPageStep(0);
        horizontalSlider->setValue(1);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider);

        zoom_In_Button = new QPushButton(groupBox);
        zoom_In_Button->setObjectName(QString::fromUtf8("zoom_In_Button"));
        zoom_In_Button->setStyleSheet(QString::fromUtf8("#zoom_In_Button {\n"
"	color: #202148;\n"
"	background: white;\n"
"	font-size: 24px;\n"
"	padding-right: 12px;\n"
"	padding-left: 12px;\n"
"	border: none;\n"
"}"));

        horizontalLayout_3->addWidget(zoom_In_Button);

        zoom_level_value = new QLabel(groupBox);
        zoom_level_value->setObjectName(QString::fromUtf8("zoom_level_value"));
        sizePolicy.setHeightForWidth(zoom_level_value->sizePolicy().hasHeightForWidth());
        zoom_level_value->setSizePolicy(sizePolicy);
        zoom_level_value->setStyleSheet(QString::fromUtf8("#zoom_level_value {\n"
"	color: #202148;\n"
"	background: white;\n"
"}"));

        horizontalLayout_3->addWidget(zoom_level_value);

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 0, 331, 501));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        graphicsView = new QGraphicsView(verticalLayoutWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        graphicsView->setFont(font);
        graphicsView->setStyleSheet(QString::fromUtf8("#graphicsView{\n"
"background-color:white; color:black;\n"
"}                \n"
"QScrollBar:vertical { \n"
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
"                 "
                        "           height: 0 px; \n"
"                            subcontrol-position: top; \n"
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
"               "
                        "             height: 0 px; \n"
"                            subcontrol-position: top; \n"
"                            subcontrol-origin: margin; \n"
"                        }\n"
"\n"
""));
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

        verticalLayout->addWidget(graphicsView);

        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(380, 0, 371, 501));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        OCRtextLabel = new QLabel(verticalLayoutWidget_2);
        OCRtextLabel->setObjectName(QString::fromUtf8("OCRtextLabel"));
        OCRtextLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        OCRtextLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(OCRtextLabel);

        ocroutput = new QTextBrowser(verticalLayoutWidget_2);
        ocroutput->setObjectName(QString::fromUtf8("ocroutput"));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        ocroutput->setFont(font1);
        ocroutput->setStyleSheet(QString::fromUtf8("#ocroutput{\n"
"background-color:white; color:black;\n"
"}\n"
"QScrollBar:vertical { \n"
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
"                            height: "
                        "0 px; \n"
"                            subcontrol-position: top; \n"
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
"                            height"
                        ": 0 px; \n"
"                            subcontrol-position: top; \n"
"                            subcontrol-origin: margin; \n"
"                        }\n"
"\n"
""));

        verticalLayout_2->addWidget(ocroutput);

        verticalLayoutWidget_3 = new QWidget(centralWidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(760, 0, 361, 501));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        InternLabel = new QLabel(verticalLayoutWidget_3);
        InternLabel->setObjectName(QString::fromUtf8("InternLabel"));
        InternLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        InternLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(InternLabel);

        current = new QTextBrowser(verticalLayoutWidget_3);
        current->setObjectName(QString::fromUtf8("current"));
        current->setFont(font1);
        current->setStyleSheet(QString::fromUtf8("#current{\n"
"background-color:white; color:black;\n"
"}\n"
"QScrollBar:vertical { \n"
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
"                            height: 0 "
                        "px; \n"
"                            subcontrol-position: top; \n"
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
"                            height: "
                        "0 px; \n"
"                            subcontrol-position: top; \n"
"                            subcontrol-origin: margin; \n"
"                        }\n"
"\n"
""));

        verticalLayout_3->addWidget(current);

        InternDiffView->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(InternDiffView);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        InternDiffView->setStatusBar(statusBar);

        retranslateUi(InternDiffView);

        QMetaObject::connectSlotsByName(InternDiffView);
    } // setupUi

    void retranslateUi(QMainWindow *InternDiffView)
    {
        InternDiffView->setWindowTitle(QCoreApplication::translate("InternDiffView", "InternDiffView", nullptr));
        prevButton->setText(QString());
        NextButton->setText(QString());
        groupBox->setTitle(QString());
        zoom_Out_Button->setText(QCoreApplication::translate("InternDiffView", "-", nullptr));
        zoom_In_Button->setText(QCoreApplication::translate("InternDiffView", "+", nullptr));
        zoom_level_value->setText(QCoreApplication::translate("InternDiffView", "100%", nullptr));
        label->setText(QCoreApplication::translate("InternDiffView", "<p><b>1. OCR Image<b></p>\n"
"<p> </p>", nullptr));
        OCRtextLabel->setText(QCoreApplication::translate("InternDiffView", "<p><b>2. Initial Text<b></p>\n"
"<p> </p>", nullptr));
        ocroutput->setHtml(QCoreApplication::translate("InternDiffView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Shobhika'; font-weight:400;\"><br /></p></body></html>", nullptr));
        InternLabel->setText(QCoreApplication::translate("InternDiffView", "<p><b>3. Corrector's Output Text</b></p>Changes made by Corrector: ", nullptr));
        current->setHtml(QCoreApplication::translate("InternDiffView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Shobhika'; font-weight:400;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InternDiffView: public Ui_InternDiffView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERNDIFFVIEW_H
