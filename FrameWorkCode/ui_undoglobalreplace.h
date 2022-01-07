/********************************************************************************
** Form generated from reading UI file 'undoglobalreplace.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNDOGLOBALREPLACE_H
#define UI_UNDOGLOBALREPLACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_UndoGlobalReplace
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *applyButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *UndoGlobalReplace)
    {
        if (UndoGlobalReplace->objectName().isEmpty())
            UndoGlobalReplace->setObjectName(QString::fromUtf8("UndoGlobalReplace"));
        UndoGlobalReplace->resize(680, 439);
        UndoGlobalReplace->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 33, 72);"));
        verticalLayout = new QVBoxLayout(UndoGlobalReplace);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(UndoGlobalReplace);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255); color:black;"));

        verticalLayout->addWidget(listWidget);

        textBrowser = new QTextBrowser(UndoGlobalReplace);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        applyButton = new QPushButton(UndoGlobalReplace);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));
        applyButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:rgb(227, 228, 228);border:0px; color: rgb(32, 33, 72); height:26.96px; width: 113.5px; padding-top:1px; border-radius:4.8px; padding-left:1.3px; selection-color: rgb(32, 33, 72); selection-background-color: rgb(136, 138, 133);\n"
"} QPushButton:checked{background-color: rgb(136, 138, 133);} QPushButton:pressed {background-color: rgb(136, 138, 133);}"));

        horizontalLayout->addWidget(applyButton);

        cancelButton = new QPushButton(UndoGlobalReplace);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:rgb(227, 228, 228);border:0px; color: rgb(32, 33, 72); height:26.96px; width: 113.5px; padding-top:1px; border-radius:4.8px; padding-left:1.3px; selection-color: rgb(32, 33, 72); selection-background-color: rgb(136, 138, 133);\n"
"} QPushButton:checked{background-color: rgb(136, 138, 133);} QPushButton:pressed {background-color: rgb(136, 138, 133);}"));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(UndoGlobalReplace);

        QMetaObject::connectSlotsByName(UndoGlobalReplace);
    } // setupUi

    void retranslateUi(QDialog *UndoGlobalReplace)
    {
        UndoGlobalReplace->setWindowTitle(QCoreApplication::translate("UndoGlobalReplace", "Dialog", nullptr));
        applyButton->setText(QCoreApplication::translate("UndoGlobalReplace", "Yes", nullptr));
        cancelButton->setText(QCoreApplication::translate("UndoGlobalReplace", "No", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UndoGlobalReplace: public Ui_UndoGlobalReplace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNDOGLOBALREPLACE_H
