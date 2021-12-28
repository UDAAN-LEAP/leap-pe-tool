/********************************************************************************
** Form generated from reading UI file 'globalreplacedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GLOBALREPLACEDIALOG_H
#define UI_GLOBALREPLACEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GlobalReplaceDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *mylabel;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *previewButton;
    QPushButton *applyButton;

    void setupUi(QDialog *GlobalReplaceDialog)
    {
        if (GlobalReplaceDialog->objectName().isEmpty())
            GlobalReplaceDialog->setObjectName(QString::fromUtf8("GlobalReplaceDialog"));
        GlobalReplaceDialog->resize(659, 335);
        GlobalReplaceDialog->setStyleSheet(QString::fromUtf8("QDialog{font: 11pt \"Work Sans\"; \n"
"background-color: rgb(32, 33, 72);\n"
"}\n"
"QGraphicsView{background-color:white;}\n"
"QScrollBar:vertical { \n"
"                                                border: none;\n"
"                                                background: white;\n"
"                                                width: 9.81px;\n"
"                                            }\n"
"QScrollBar::handle:vertical { \n"
"                                                background-color:  rgba(1, 22, 51, 0.5);\n"
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
""
                        "                            subcontrol-position: top; \n"
"                            subcontrol-origin: margin; \n"
"                        }\n"
"\n"
""));
        verticalLayout = new QVBoxLayout(GlobalReplaceDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mylabel = new QLabel(GlobalReplaceDialog);
        mylabel->setObjectName(QString::fromUtf8("mylabel"));
        mylabel->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"color: black;\n"
""));

        verticalLayout->addWidget(mylabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        listWidget = new QListWidget(GlobalReplaceDialog);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget{background-color: white; color:black;}\n"
"QGraphicsView{background-color:white;}\n"
""));

        horizontalLayout_2->addWidget(listWidget);

        groupBox = new QGroupBox(GlobalReplaceDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(groupBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(GlobalReplaceDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("border:0px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/Resources/information.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(27, 27));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        previewButton = new QPushButton(GlobalReplaceDialog);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));
        previewButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:rgb(227, 228, 228);border:0px; color: rgb(32, 33, 72); height:26.96px; width: 113.5px; padding-top:1px; border-radius:4.8px; padding-left:1.3px; selection-color: rgb(32, 33, 72); selection-background-color: rgb(136, 138, 133);\n"
"} QPushButton:checked{background-color: rgb(136, 138, 133);} QPushButton:pressed {background-color: rgb(136, 138, 133);}"));

        horizontalLayout->addWidget(previewButton);

        applyButton = new QPushButton(GlobalReplaceDialog);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));
        applyButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:rgb(227, 228, 228);border:0px; color: rgb(32, 33, 72); height:26.96px; width: 139.5px; padding-top:1px; border-radius:4.8px; padding-left:1.3px; selection-color: rgb(32, 33, 72); selection-background-color: rgb(136, 138, 133);\n"
"} QPushButton:checked{background-color: rgb(136, 138, 133);} QPushButton:pressed {background-color: rgb(136, 138, 133);}"));

        horizontalLayout->addWidget(applyButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GlobalReplaceDialog);

        QMetaObject::connectSlotsByName(GlobalReplaceDialog);
    } // setupUi

    void retranslateUi(QDialog *GlobalReplaceDialog)
    {
        GlobalReplaceDialog->setWindowTitle(QApplication::translate("GlobalReplaceDialog", "Dialog", nullptr));
        mylabel->setText(QApplication::translate("GlobalReplaceDialog", "Select words to replace", nullptr));
        groupBox->setTitle(QString());
        pushButton->setText(QString());
        previewButton->setText(QApplication::translate("GlobalReplaceDialog", "Preview", nullptr));
        applyButton->setText(QApplication::translate("GlobalReplaceDialog", "Save and Replace", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GlobalReplaceDialog: public Ui_GlobalReplaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLOBALREPLACEDIALOG_H
