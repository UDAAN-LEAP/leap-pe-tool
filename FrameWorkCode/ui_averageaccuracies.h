/********************************************************************************
** Form generated from reading UI file 'averageaccuracies.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AVERAGEACCURACIES_H
#define UI_AVERAGEACCURACIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_AverageAccuracies
{
public:
    QTableView *tableView;

    void setupUi(QDialog *AverageAccuracies)
    {
        if (AverageAccuracies->objectName().isEmpty())
            AverageAccuracies->setObjectName(QStringLiteral("AverageAccuracies"));
        AverageAccuracies->resize(489, 364);
        tableView = new QTableView(AverageAccuracies);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(130, 110, 256, 192));

        retranslateUi(AverageAccuracies);

        QMetaObject::connectSlotsByName(AverageAccuracies);
    } // setupUi

    void retranslateUi(QDialog *AverageAccuracies)
    {
        AverageAccuracies->setWindowTitle(QApplication::translate("AverageAccuracies", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AverageAccuracies: public Ui_AverageAccuracies {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AVERAGEACCURACIES_H
