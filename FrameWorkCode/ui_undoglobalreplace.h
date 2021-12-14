/********************************************************************************
** Form generated from reading UI file 'undoglobalreplace.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNDOGLOBALREPLACE_H
#define UI_UNDOGLOBALREPLACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            UndoGlobalReplace->setObjectName(QStringLiteral("UndoGlobalReplace"));
        UndoGlobalReplace->resize(680, 439);
        verticalLayout = new QVBoxLayout(UndoGlobalReplace);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listWidget = new QListWidget(UndoGlobalReplace);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        textBrowser = new QTextBrowser(UndoGlobalReplace);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        applyButton = new QPushButton(UndoGlobalReplace);
        applyButton->setObjectName(QStringLiteral("applyButton"));

        horizontalLayout->addWidget(applyButton);

        cancelButton = new QPushButton(UndoGlobalReplace);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(UndoGlobalReplace);

        QMetaObject::connectSlotsByName(UndoGlobalReplace);
    } // setupUi

    void retranslateUi(QDialog *UndoGlobalReplace)
    {
        UndoGlobalReplace->setWindowTitle(QApplication::translate("UndoGlobalReplace", "Dialog", Q_NULLPTR));
        applyButton->setText(QApplication::translate("UndoGlobalReplace", "Yes", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("UndoGlobalReplace", "No", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UndoGlobalReplace: public Ui_UndoGlobalReplace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNDOGLOBALREPLACE_H
