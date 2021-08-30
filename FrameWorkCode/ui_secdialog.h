/********************************************************************************
** Form generated from reading UI file 'secdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECDIALOG_H
#define UI_SECDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_SecDialog
{
public:
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *SecDialog)
    {
        if (SecDialog->objectName().isEmpty())
            SecDialog->setObjectName(QString::fromUtf8("SecDialog"));
        SecDialog->resize(1093, 512);
        textBrowser = new QTextBrowser(SecDialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 50, 411, 441));
        textBrowser_2 = new QTextBrowser(SecDialog);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(450, 50, 391, 441));
        label = new QLabel(SecDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 10, 91, 17));
        label_2 = new QLabel(SecDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(590, 10, 91, 17));
        pushButton = new QPushButton(SecDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(930, 380, 101, 25));
        pushButton_3 = new QPushButton(SecDialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(930, 320, 91, 25));
        label_3 = new QLabel(SecDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(860, 270, 221, 17));
        pushButton_4 = new QPushButton(SecDialog);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(860, 100, 221, 25));

        retranslateUi(SecDialog);

        QMetaObject::connectSlotsByName(SecDialog);
    } // setupUi

    void retranslateUi(QDialog *SecDialog)
    {
        SecDialog->setWindowTitle(QApplication::translate("SecDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("SecDialog", "OCR image", nullptr));
        label_2->setText(QApplication::translate("SecDialog", "Source Image", nullptr));
        pushButton->setText(QApplication::translate("SecDialog", "Source-Image", nullptr));
        pushButton_3->setText(QApplication::translate("SecDialog", "OCR-Image", nullptr));
        label_3->setText(QApplication::translate("SecDialog", "What do you want to preserve??", nullptr));
        pushButton_4->setText(QApplication::translate("SecDialog", "Search in Gallery", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecDialog: public Ui_SecDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECDIALOG_H
