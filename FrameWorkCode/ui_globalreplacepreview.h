/********************************************************************************
** Form generated from reading UI file 'globalreplacepreview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GLOBALREPLACEPREVIEW_H
#define UI_GLOBALREPLACEPREVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_globalReplacePreview
{
public:
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;

    void setupUi(QDialog *globalReplacePreview)
    {
        if (globalReplacePreview->objectName().isEmpty())
            globalReplacePreview->setObjectName(QStringLiteral("globalReplacePreview"));
        globalReplacePreview->resize(669, 509);
        globalReplacePreview->setStyleSheet(QStringLiteral("background-color: rgb(32, 33, 72);"));
        horizontalLayout = new QHBoxLayout(globalReplacePreview);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableView = new QTableView(globalReplacePreview);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setStyleSheet(QLatin1String("color:black; \n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(tableView);


        retranslateUi(globalReplacePreview);

        QMetaObject::connectSlotsByName(globalReplacePreview);
    } // setupUi

    void retranslateUi(QDialog *globalReplacePreview)
    {
        globalReplacePreview->setWindowTitle(QApplication::translate("globalReplacePreview", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class globalReplacePreview: public Ui_globalReplacePreview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLOBALREPLACEPREVIEW_H
