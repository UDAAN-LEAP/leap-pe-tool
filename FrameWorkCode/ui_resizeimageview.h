/********************************************************************************
** Form generated from reading UI file 'resizeimageview.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESIZEIMAGEVIEW_H
#define UI_RESIZEIMAGEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_ResizeImageView
{
public:

    void setupUi(QDialog *ResizeImageView)
    {
        if (ResizeImageView->objectName().isEmpty())
            ResizeImageView->setObjectName(QString::fromUtf8("ResizeImageView"));
        ResizeImageView->resize(310, 300);

        retranslateUi(ResizeImageView);

        QMetaObject::connectSlotsByName(ResizeImageView);
    } // setupUi

    void retranslateUi(QDialog *ResizeImageView)
    {
        ResizeImageView->setWindowTitle(QCoreApplication::translate("ResizeImageView", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResizeImageView: public Ui_ResizeImageView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESIZEIMAGEVIEW_H
