/********************************************************************************
** Form generated from reading UI file 'DiffView.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFFVIEW_H
#define UI_DIFFVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DiffView
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *diff1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTextEdit *diff2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QTextEdit *diff3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DiffView)
    {
        if (DiffView->objectName().isEmpty())
            DiffView->setObjectName(QString::fromUtf8("DiffView"));
        DiffView->resize(1271, 508);
        centralWidget = new QWidget(DiffView);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        diff1 = new QTextEdit(centralWidget);
        diff1->setObjectName(QString::fromUtf8("diff1"));
        QFont font;
        font.setFamily(QString::fromUtf8("Shobhika Bold"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        diff1->setFont(font);

        verticalLayout->addWidget(diff1);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        diff2 = new QTextEdit(centralWidget);
        diff2->setObjectName(QString::fromUtf8("diff2"));
        diff2->setFont(font);

        verticalLayout_2->addWidget(diff2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        diff3 = new QTextEdit(centralWidget);
        diff3->setObjectName(QString::fromUtf8("diff3"));
        diff3->setFont(font);

        verticalLayout_3->addWidget(diff3);


        horizontalLayout->addLayout(verticalLayout_3);

        DiffView->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DiffView);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1271, 21));
        DiffView->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DiffView);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        DiffView->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DiffView);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DiffView->setStatusBar(statusBar);

        retranslateUi(DiffView);

        QMetaObject::connectSlotsByName(DiffView);
    } // setupUi

    void retranslateUi(QMainWindow *DiffView)
    {
        DiffView->setWindowTitle(QCoreApplication::translate("DiffView", "DiffView", nullptr));
        label->setText(QCoreApplication::translate("DiffView", "OCR Text", nullptr));
        label_2->setText(QCoreApplication::translate("DiffView", "Intern's Output Text", nullptr));
        label_3->setText(QCoreApplication::translate("DiffView", "Verified Text", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DiffView: public Ui_DiffView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFVIEW_H
