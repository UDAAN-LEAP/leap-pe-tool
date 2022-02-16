/********************************************************************************
** Form generated from reading UI file 'interndiffview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InternDiffView
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *prevButton;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout_2;
    QLabel *OCRtextLabel;
    QTextBrowser *ocroutput;
    QVBoxLayout *verticalLayout_3;
    QLabel *InternLabel;
    QTextBrowser *current;
    QPushButton *NextButton;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *zoom_Out_Button;
    QSlider *horizontalSlider;
    QPushButton *zoom_In_Button;
    QLabel *zoom_level_value;
    QSpacerItem *horizontalSpacer;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *InternDiffView)
    {
        if (InternDiffView->objectName().isEmpty())
            InternDiffView->setObjectName(QStringLiteral("InternDiffView"));
        InternDiffView->resize(1157, 576);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InternDiffView->sizePolicy().hasHeightForWidth());
        InternDiffView->setSizePolicy(sizePolicy);
        InternDiffView->setStyleSheet(QLatin1String("\n"
"background-color: rgb(32, 33, 72);\n"
""));
        centralWidget = new QWidget(InternDiffView);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setStyleSheet(QLatin1String("QScrollBar:vertical { \n"
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
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        prevButton = new QPushButton(centralWidget);
        prevButton->setObjectName(QStringLiteral("prevButton"));
        prevButton->setStyleSheet(QStringLiteral("border: 0px; "));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/Resources/Previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        prevButton->setIcon(icon);

        horizontalLayout->addWidget(prevButton);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setSizeIncrement(QSize(0, 0));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        graphicsView->setFont(font);
        graphicsView->setStyleSheet(QLatin1String("#graphicsView{\n"
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


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        OCRtextLabel = new QLabel(centralWidget);
        OCRtextLabel->setObjectName(QStringLiteral("OCRtextLabel"));
        OCRtextLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        OCRtextLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(OCRtextLabel);

        ocroutput = new QTextBrowser(centralWidget);
        ocroutput->setObjectName(QStringLiteral("ocroutput"));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        ocroutput->setFont(font1);
        ocroutput->setStyleSheet(QLatin1String("#ocroutput{\n"
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


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        InternLabel = new QLabel(centralWidget);
        InternLabel->setObjectName(QStringLiteral("InternLabel"));
        InternLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        InternLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(InternLabel);

        current = new QTextBrowser(centralWidget);
        current->setObjectName(QStringLiteral("current"));
        current->setFont(font1);
        current->setStyleSheet(QLatin1String("#current{\n"
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


        horizontalLayout->addLayout(verticalLayout_3);

        NextButton = new QPushButton(centralWidget);
        NextButton->setObjectName(QStringLiteral("NextButton"));
        NextButton->setStyleSheet(QStringLiteral("border: 0px; "));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/Resources/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        NextButton->setIcon(icon1);

        horizontalLayout->addWidget(NextButton);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(264, 37));
        groupBox->setMaximumSize(QSize(264, 37));
        groupBox->setStyleSheet(QLatin1String("QGroupBox {\n"
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
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        zoom_Out_Button = new QPushButton(groupBox);
        zoom_Out_Button->setObjectName(QStringLiteral("zoom_Out_Button"));
        sizePolicy1.setHeightForWidth(zoom_Out_Button->sizePolicy().hasHeightForWidth());
        zoom_Out_Button->setSizePolicy(sizePolicy1);
        zoom_Out_Button->setStyleSheet(QLatin1String("#zoom_Out_Button {\n"
"	color: #202148;\n"
"	background: white;\n"
"	font-size: 24px;\n"
"	padding-right: 12px;\n"
"	padding-left: 12px;\n"
"	border: none;\n"
"}"));

        horizontalLayout_3->addWidget(zoom_Out_Button);

        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        sizePolicy1.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy1);
        horizontalSlider->setStyleSheet(QLatin1String("QSlider {\n"
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
        zoom_In_Button->setObjectName(QStringLiteral("zoom_In_Button"));
        sizePolicy1.setHeightForWidth(zoom_In_Button->sizePolicy().hasHeightForWidth());
        zoom_In_Button->setSizePolicy(sizePolicy1);
        zoom_In_Button->setStyleSheet(QLatin1String("#zoom_In_Button {\n"
"	color: #202148;\n"
"	background: white;\n"
"	font-size: 24px;\n"
"	padding-right: 12px;\n"
"	padding-left: 12px;\n"
"	border: none;\n"
"}"));

        horizontalLayout_3->addWidget(zoom_In_Button);

        zoom_level_value = new QLabel(groupBox);
        zoom_level_value->setObjectName(QStringLiteral("zoom_level_value"));
        sizePolicy1.setHeightForWidth(zoom_level_value->sizePolicy().hasHeightForWidth());
        zoom_level_value->setSizePolicy(sizePolicy1);
        zoom_level_value->setStyleSheet(QLatin1String("#zoom_level_value {\n"
"	color: #202148;\n"
"	background: white;\n"
"}"));

        horizontalLayout_3->addWidget(zoom_level_value);


        horizontalLayout_2->addWidget(groupBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout_2);

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
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Shobhika'; font-weight:400;\"><br /></p></body></html>", Q_NULLPTR));
        InternLabel->setText(QApplication::translate("InternDiffView", "<p><b>3. Corrector's Output Text</b></p>Changes made by Corrector: ", Q_NULLPTR));
        current->setHtml(QApplication::translate("InternDiffView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Shobhika'; font-weight:400;\"><br /></p></body></html>", Q_NULLPTR));
        NextButton->setText(QString());
        groupBox->setTitle(QString());
        zoom_Out_Button->setText(QApplication::translate("InternDiffView", "-", Q_NULLPTR));
        zoom_In_Button->setText(QApplication::translate("InternDiffView", "+", Q_NULLPTR));
        zoom_level_value->setText(QApplication::translate("InternDiffView", "100%", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InternDiffView: public Ui_InternDiffView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERNDIFFVIEW_H
