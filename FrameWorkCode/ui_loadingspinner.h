/********************************************************************************
** Form generated from reading UI file 'loadingspinner.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADINGSPINNER_H
#define UI_LOADINGSPINNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_LoadingSpinner
{
public:
    QLabel *labelspin;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *LoadingSpinner)
    {
        if (LoadingSpinner->objectName().isEmpty())
            LoadingSpinner->setObjectName(QStringLiteral("LoadingSpinner"));
        LoadingSpinner->resize(248, 88);
        labelspin = new QLabel(LoadingSpinner);
        labelspin->setObjectName(QStringLiteral("labelspin"));
        labelspin->setGeometry(QRect(10, 10, 81, 71));
        label = new QLabel(LoadingSpinner);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 10, 111, 31));
        label_2 = new QLabel(LoadingSpinner);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 40, 111, 31));

        retranslateUi(LoadingSpinner);

        QMetaObject::connectSlotsByName(LoadingSpinner);
    } // setupUi

    void retranslateUi(QDialog *LoadingSpinner)
    {
        LoadingSpinner->setWindowTitle(QApplication::translate("LoadingSpinner", "Form", Q_NULLPTR));
        labelspin->setText(QApplication::translate("LoadingSpinner", "TextLabel", Q_NULLPTR));
        label->setText(QApplication::translate("LoadingSpinner", "Please Wait", Q_NULLPTR));
        label_2->setText(QApplication::translate("LoadingSpinner", "Loading...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoadingSpinner: public Ui_LoadingSpinner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADINGSPINNER_H
