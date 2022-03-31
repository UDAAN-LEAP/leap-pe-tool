/********************************************************************************
** Form generated from reading UI file 'progressbardialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSBARDIALOG_H
#define UI_PROGRESSBARDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ProgressBarDialog
{
public:
    QVBoxLayout *verticalLayout;
    QProgressBar *progressBar;
    QLineEdit *description;

    void setupUi(QDialog *ProgressBarDialog)
    {
        if (ProgressBarDialog->objectName().isEmpty())
            ProgressBarDialog->setObjectName(QString::fromUtf8("ProgressBarDialog"));
        ProgressBarDialog->resize(409, 175);
        verticalLayout = new QVBoxLayout(ProgressBarDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        progressBar = new QProgressBar(ProgressBarDialog);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);

        description = new QLineEdit(ProgressBarDialog);
        description->setObjectName(QString::fromUtf8("description"));

        verticalLayout->addWidget(description);


        retranslateUi(ProgressBarDialog);

        QMetaObject::connectSlotsByName(ProgressBarDialog);
    } // setupUi

    void retranslateUi(QDialog *ProgressBarDialog)
    {
        ProgressBarDialog->setWindowTitle(QCoreApplication::translate("ProgressBarDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProgressBarDialog: public Ui_ProgressBarDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSBARDIALOG_H
