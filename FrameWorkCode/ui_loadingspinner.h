/********************************************************************************
** Form generated from reading UI file 'loadingspinner.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADINGSPINNER_H
#define UI_LOADINGSPINNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
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
            LoadingSpinner->setObjectName(QString::fromUtf8("LoadingSpinner"));
        LoadingSpinner->resize(248, 88);
        LoadingSpinner->setStyleSheet(QString::fromUtf8("font: 11pt \"Work Sans\";"));
        labelspin = new QLabel(LoadingSpinner);
        labelspin->setObjectName(QString::fromUtf8("labelspin"));
        labelspin->setGeometry(QRect(10, 10, 81, 71));
        label = new QLabel(LoadingSpinner);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 10, 111, 31));
        label_2 = new QLabel(LoadingSpinner);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 40, 111, 31));

        retranslateUi(LoadingSpinner);

        QMetaObject::connectSlotsByName(LoadingSpinner);
    } // setupUi

    void retranslateUi(QDialog *LoadingSpinner)
    {
        LoadingSpinner->setWindowTitle(QApplication::translate("LoadingSpinner", "Form", nullptr));
        labelspin->setText(QApplication::translate("LoadingSpinner", "TextLabel", nullptr));
        label->setText(QApplication::translate("LoadingSpinner", "Please Wait", nullptr));
        label_2->setText(QApplication::translate("LoadingSpinner", "Loading...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoadingSpinner: public Ui_LoadingSpinner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADINGSPINNER_H
