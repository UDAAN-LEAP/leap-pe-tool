/********************************************************************************
** Form generated from reading UI file 'DiffView.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFFVIEW_H
#define UI_DIFFVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DiffView
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QTextEdit *diff2;
    QTextEdit *diff3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DiffView)
    {
        if (DiffView->objectName().isEmpty())
            DiffView->setObjectName(QStringLiteral("DiffView"));
        DiffView->resize(721, 511);
        centralWidget = new QWidget(DiffView);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        horizontalLayout->addWidget(graphicsView);

        diff2 = new QTextEdit(centralWidget);
        diff2->setObjectName(QStringLiteral("diff2"));

        horizontalLayout->addWidget(diff2);

        diff3 = new QTextEdit(centralWidget);
        diff3->setObjectName(QStringLiteral("diff3"));

        horizontalLayout->addWidget(diff3);

        DiffView->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DiffView);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 721, 22));
        DiffView->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DiffView);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DiffView->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DiffView);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DiffView->setStatusBar(statusBar);

        retranslateUi(DiffView);

        QMetaObject::connectSlotsByName(DiffView);
    } // setupUi

    void retranslateUi(QMainWindow *DiffView)
    {
        DiffView->setWindowTitle(QApplication::translate("DiffView", "DiffView", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DiffView: public Ui_DiffView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFVIEW_H
