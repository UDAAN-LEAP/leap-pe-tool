/********************************************************************************
** Form generated from reading UI file 'VCSWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VCSWIDGET_H
#define UI_VCSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VCSWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *VCSWidget)
    {
        if (VCSWidget->objectName().isEmpty())
            VCSWidget->setObjectName(QString::fromUtf8("VCSWidget"));
        VCSWidget->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(VCSWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        verticalLayout->addLayout(horizontalLayout);

        label = new QLabel(VCSWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(VCSWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(VCSWidget);

        QMetaObject::connectSlotsByName(VCSWidget);
    } // setupUi

    void retranslateUi(QWidget *VCSWidget)
    {
        VCSWidget->setWindowTitle(QCoreApplication::translate("VCSWidget", "VCSWidget", nullptr));
        label->setText(QCoreApplication::translate("VCSWidget", "Current Project:", nullptr));
        label_2->setText(QCoreApplication::translate("VCSWidget", "Pending Files:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VCSWidget: public Ui_VCSWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VCSWIDGET_H
