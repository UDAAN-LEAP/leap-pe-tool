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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GlobalReplaceDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBox;
    QListWidget *listWidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox_2;
    QListWidget *ReplaceInAllPagesListWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *previewButton;
    QPushButton *applyButton;

    void setupUi(QDialog *GlobalReplaceDialog)
    {
        if (GlobalReplaceDialog->objectName().isEmpty())
            GlobalReplaceDialog->setObjectName(QString::fromUtf8("GlobalReplaceDialog"));
        GlobalReplaceDialog->resize(913, 433);
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
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        groupBox_2 = new QGroupBox(GlobalReplaceDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color: rgb(255, 255, 255);"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout_3->addWidget(checkBox);

        listWidget = new QListWidget(groupBox_2);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget{background-color: white; color:black; border:0px;}\n"
"QGraphicsView{background-color:white;}\n"
"\n"
"QListView::item {\n"
"	/*border: 1x solid black;*/\n"
"	height: 28px;\n"
"}\n"
"\n"
""));

        verticalLayout_3->addWidget(listWidget);


        horizontalLayout_2->addWidget(groupBox_2);

        groupBox = new QGroupBox(GlobalReplaceDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-color: rgb(255, 255, 255);"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        verticalLayout_2->addWidget(checkBox_2);

        ReplaceInAllPagesListWidget = new QListWidget(groupBox);
        ReplaceInAllPagesListWidget->setObjectName(QString::fromUtf8("ReplaceInAllPagesListWidget"));
        ReplaceInAllPagesListWidget->setStyleSheet(QString::fromUtf8("QListWidget{background-color: white; color:black; border:0px;}\n"
"QGraphicsView{background-color:white;}\n"
"\n"
"QListView::item {\n"
"	/*border: 1x solid black;*/\n"
"	height: 28px;\n"
"}"));

        verticalLayout_2->addWidget(ReplaceInAllPagesListWidget);


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
        groupBox_2->setTitle(QApplication::translate("GlobalReplaceDialog", "Choose the words to be replaced", nullptr));
        checkBox->setText(QApplication::translate("GlobalReplaceDialog", "Select All", nullptr));
        groupBox->setTitle(QApplication::translate("GlobalReplaceDialog", "Replace In All Pages", nullptr));
        checkBox_2->setText(QApplication::translate("GlobalReplaceDialog", "Select All", nullptr));
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
