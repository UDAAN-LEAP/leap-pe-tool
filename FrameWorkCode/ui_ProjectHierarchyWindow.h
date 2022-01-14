/********************************************************************************
** Form generated from reading UI file 'ProjectHierarchyWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTHIERARCHYWINDOW_H
#define UI_PROJECTHIERARCHYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjectHierarchyWindow
{
public:
    QGridLayout *gridLayout;
    QTreeView *treeView;

    void setupUi(QWidget *ProjectHierarchyWindow)
    {
        if (ProjectHierarchyWindow->objectName().isEmpty())
            ProjectHierarchyWindow->setObjectName(QStringLiteral("ProjectHierarchyWindow"));
        ProjectHierarchyWindow->resize(714, 525);
        ProjectHierarchyWindow->setStyleSheet(QStringLiteral("font: 11pt \"Work Sans\";"));
        gridLayout = new QGridLayout(ProjectHierarchyWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        treeView = new QTreeView(ProjectHierarchyWindow);
        treeView->setObjectName(QStringLiteral("treeView"));

        gridLayout->addWidget(treeView, 0, 0, 1, 1);


        retranslateUi(ProjectHierarchyWindow);

        QMetaObject::connectSlotsByName(ProjectHierarchyWindow);
    } // setupUi

    void retranslateUi(QWidget *ProjectHierarchyWindow)
    {
        ProjectHierarchyWindow->setWindowTitle(QApplication::translate("ProjectHierarchyWindow", "ProjectHierarchyWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ProjectHierarchyWindow: public Ui_ProjectHierarchyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTHIERARCHYWINDOW_H
