/********************************************************************************
** Form generated from reading UI file 'uploaddialogbox.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADDIALOGBOX_H
#define UI_UPLOADDIALOGBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_uploadDialogBox
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QDialog *uploadDialogBox)
    {
        if (uploadDialogBox->objectName().isEmpty())
            uploadDialogBox->setObjectName(QString::fromUtf8("uploadDialogBox"));
        uploadDialogBox->resize(661, 485);
        verticalLayout = new QVBoxLayout(uploadDialogBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(uploadDialogBox);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancelButton = new QPushButton(uploadDialogBox);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        okButton = new QPushButton(uploadDialogBox);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(uploadDialogBox);

        QMetaObject::connectSlotsByName(uploadDialogBox);
    } // setupUi

    void retranslateUi(QDialog *uploadDialogBox)
    {
        uploadDialogBox->setWindowTitle(QApplication::translate("uploadDialogBox", "Dialog", nullptr));
        cancelButton->setText(QApplication::translate("uploadDialogBox", "Cancel", nullptr));
        okButton->setText(QApplication::translate("uploadDialogBox", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class uploadDialogBox: public Ui_uploadDialogBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADDIALOGBOX_H
