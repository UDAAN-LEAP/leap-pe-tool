/********************************************************************************
** Form generated from reading UI file 'globalreplacepreview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GLOBALREPLACEPREVIEW_H
#define UI_GLOBALREPLACEPREVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_globalReplacePreview
{
public:
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;

    void setupUi(QDialog *globalReplacePreview)
    {
        if (globalReplacePreview->objectName().isEmpty())
            globalReplacePreview->setObjectName(QString::fromUtf8("globalReplacePreview"));
        globalReplacePreview->resize(669, 509);
        globalReplacePreview->setStyleSheet(QString::fromUtf8("QDialog{background-color: rgb(32, 33, 72);}\n"
"QScrollBar:vertical { \n"
"                                                border: none;\n"
"                                                background: white;\n"
"                                                width: 9.81px;\n"
"                                            }\n"
"QScrollBar::handle:vertical { \n"
"                                                background-color:  rgba(1, 22, 51, 0.5);\n"
"                                                min-height: 273.41px;\n"
"														border: 0px solid red; \n"
"														border-radius:4.905px;\n"
"														\n"
"                                            }\n"
"QScrollBar::add-line:vertical {       \n"
"                            height: 0px;\n"
"                            subcontrol-position: bottom; \n"
"                            subcontrol-origin: margin; \n"
"								\n"
"                        } \n"
"QScrollBar::sub-line:vertical { \n"
"                            height: 0 px; \n"
"    "
                        "                        subcontrol-position: top; \n"
"                            subcontrol-origin: margin; \n"
"                        }\n"
"\n"
"QScrollBar:horizontal { \n"
"                                                border: none;\n"
"                                                background: white;\n"
"                                             		\n"
"                                            }\n"
"QScrollBar::handle:horizontal { \n"
"                                                background-color:  rgba(1, 22, 51, 0.5);\n"
"														border: 0px solid red; \n"
"														border-radius:4.905px;\n"
"                                            }\n"
"QScrollBar::add-line:horizontal {       \n"
"                            height: 0px;\n"
"                            subcontrol-position: bottom; \n"
"                            subcontrol-origin: margin; \n"
"								\n"
"                        } \n"
"QScrollBar::sub-line:horizontal { \n"
"                            height: 0 px; \n"
"  "
                        "                          subcontrol-position: top; \n"
"                            subcontrol-origin: margin; \n"
"                        }\n"
"\n"
""));
        horizontalLayout = new QHBoxLayout(globalReplacePreview);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableView = new QTableView(globalReplacePreview);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setStyleSheet(QString::fromUtf8("color:black; \n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(tableView);


        retranslateUi(globalReplacePreview);

        QMetaObject::connectSlotsByName(globalReplacePreview);
    } // setupUi

    void retranslateUi(QDialog *globalReplacePreview)
    {
        globalReplacePreview->setWindowTitle(QCoreApplication::translate("globalReplacePreview", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class globalReplacePreview: public Ui_globalReplacePreview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLOBALREPLACEPREVIEW_H
