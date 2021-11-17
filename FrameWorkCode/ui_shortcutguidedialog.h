/********************************************************************************
** Form generated from reading UI file 'shortcutguidedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHORTCUTGUIDEDIALOG_H
#define UI_SHORTCUTGUIDEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
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
            ShortcutGuideDialog->setObjectName(QStringLiteral("ShortcutGuideDialog"));
        ShortcutGuideDialog->resize(576, 408);
        label = new QLabel(ShortcutGuideDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 571, 691));
        scrollArea = new QScrollArea(ShortcutGuideDialog);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(550, -10, 20, 411));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 18, 409));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(ShortcutGuideDialog);

        QMetaObject::connectSlotsByName(ShortcutGuideDialog);
    } // setupUi

    void retranslateUi(QDialog *ShortcutGuideDialog)
    {
        ShortcutGuideDialog->setWindowTitle(QApplication::translate("ShortcutGuideDialog", " Shortcut Guide", Q_NULLPTR));
        label->setText(QApplication::translate("ShortcutGuideDialog", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ShortcutGuideDialog: public Ui_ShortcutGuideDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHORTCUTGUIDEDIALOG_H
