/********************************************************************************
** Form generated from reading UI file 'shortcutguidedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHORTCUTGUIDEDIALOG_H
#define UI_SHORTCUTGUIDEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShortcutGuideDialog
{
public:
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QDialog *ShortcutGuideDialog)
    {
        if (ShortcutGuideDialog->objectName().isEmpty())
            ShortcutGuideDialog->setObjectName(QString::fromUtf8("ShortcutGuideDialog"));
        ShortcutGuideDialog->resize(576, 408);
        label = new QLabel(ShortcutGuideDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 571, 691));
        scrollArea = new QScrollArea(ShortcutGuideDialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(550, -10, 20, 411));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 18, 409));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(ShortcutGuideDialog);

        QMetaObject::connectSlotsByName(ShortcutGuideDialog);
    } // setupUi

    void retranslateUi(QDialog *ShortcutGuideDialog)
    {
        ShortcutGuideDialog->setWindowTitle(QApplication::translate("ShortcutGuideDialog", " Shortcut Guide", nullptr));
        label->setText(QApplication::translate("ShortcutGuideDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShortcutGuideDialog: public Ui_ShortcutGuideDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHORTCUTGUIDEDIALOG_H
