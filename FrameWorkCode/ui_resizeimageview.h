/********************************************************************************
** Form generated from reading UI file 'resizeimageview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESIZEIMAGEVIEW_H
#define UI_RESIZEIMAGEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ResizeImageView
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDoubleSpinBox *widthSpinBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QDoubleSpinBox *hightSpinBox;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Cancel;
    QPushButton *Ok;

    void setupUi(QDialog *ResizeImageView)
    {
        if (ResizeImageView->objectName().isEmpty())
            ResizeImageView->setObjectName(QStringLiteral("ResizeImageView"));
        ResizeImageView->resize(310, 192);
        ResizeImageView->setStyleSheet(QLatin1String("font: 11pt \"Work Sans\"; \n"
"background-color: rgb(32, 33, 72);"));
        verticalLayout_3 = new QVBoxLayout(ResizeImageView);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(ResizeImageView);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout_2->addWidget(label);

        widthSpinBox = new QDoubleSpinBox(ResizeImageView);
        widthSpinBox->setObjectName(QStringLiteral("widthSpinBox"));
        widthSpinBox->setStyleSheet(QLatin1String("color:black; \n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(widthSpinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(ResizeImageView);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout->addWidget(label_2);

        hightSpinBox = new QDoubleSpinBox(ResizeImageView);
        hightSpinBox->setObjectName(QStringLiteral("hightSpinBox"));
        hightSpinBox->setStyleSheet(QLatin1String("color:black; \n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(hightSpinBox);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        checkBox = new QCheckBox(ResizeImageView);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setStyleSheet(QStringLiteral("color:white;"));

        verticalLayout_2->addWidget(checkBox);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        Cancel = new QPushButton(ResizeImageView);
        Cancel->setObjectName(QStringLiteral("Cancel"));
        Cancel->setStyleSheet(QLatin1String("QPushButton{background-color:rgb(227, 228, 228);border:0px; color: rgb(32, 33, 72); height:26.96px; width: 113.5px; padding-top:1px; border-radius:4.8px; padding-left:1.3px; selection-color: rgb(32, 33, 72); selection-background-color: rgb(136, 138, 133);\n"
"} QPushButton:checked{background-color: rgb(136, 138, 133);} QPushButton:pressed {background-color: rgb(136, 138, 133);}"));

        horizontalLayout_3->addWidget(Cancel);

        Ok = new QPushButton(ResizeImageView);
        Ok->setObjectName(QStringLiteral("Ok"));
        Ok->setStyleSheet(QLatin1String("QPushButton{background-color:rgb(227, 228, 228);border:0px; color: rgb(32, 33, 72); height:26.96px; width: 113.5px; padding-top:1px; border-radius:4.8px; padding-left:1.3px; selection-color: rgb(32, 33, 72); selection-background-color: rgb(136, 138, 133);\n"
"} QPushButton:checked{background-color: rgb(136, 138, 133);} QPushButton:pressed {background-color: rgb(136, 138, 133);}"));

        horizontalLayout_3->addWidget(Ok);


        verticalLayout_3->addLayout(horizontalLayout_3);


        retranslateUi(ResizeImageView);

        QMetaObject::connectSlotsByName(ResizeImageView);
    } // setupUi

    void retranslateUi(QDialog *ResizeImageView)
    {
        ResizeImageView->setWindowTitle(QApplication::translate("ResizeImageView", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ResizeImageView", "Image Width", Q_NULLPTR));
        label_2->setText(QApplication::translate("ResizeImageView", "Image Height", Q_NULLPTR));
        checkBox->setText(QApplication::translate("ResizeImageView", "Keep Aspect Ratio", Q_NULLPTR));
        Cancel->setText(QApplication::translate("ResizeImageView", "Cancel", Q_NULLPTR));
        Ok->setText(QApplication::translate("ResizeImageView", "Ok", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ResizeImageView: public Ui_ResizeImageView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESIZEIMAGEVIEW_H
