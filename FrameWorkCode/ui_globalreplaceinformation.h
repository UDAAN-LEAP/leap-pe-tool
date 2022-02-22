/********************************************************************************
** Form generated from reading UI file 'globalreplaceinformation.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GLOBALREPLACEINFORMATION_H
#define UI_GLOBALREPLACEINFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_globalReplaceInformation
{
public:
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;

    void setupUi(QDialog *globalReplaceInformation)
    {
        if (globalReplaceInformation->objectName().isEmpty())
            globalReplaceInformation->setObjectName(QStringLiteral("globalReplaceInformation"));
        globalReplaceInformation->resize(1100, 355);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(globalReplaceInformation->sizePolicy().hasHeightForWidth());
        globalReplaceInformation->setSizePolicy(sizePolicy);
        globalReplaceInformation->setMaximumSize(QSize(1200, 355));
        globalReplaceInformation->setStyleSheet(QLatin1String("QDialog{background-color: rgb(32, 33, 72);}\n"
"QScrollBar:vertical { \n"
"               border: none;\n"
"                background: white;    \n"
"             }\n"
"QScrollBar::handle:vertical { \n"
"                                                background-color:  rgba(1, 22, 51, 0.5);\n"
"                                                min-height: 273.41px;\n"
"														border: 0px solid red; \n"
"														border-radius:4.905px;\n"
"                                            }\n"
"QScrollBar::add-line:vertical {       \n"
"                            height: 0px;\n"
"                            subcontrol-position: bottom; \n"
"                            subcontrol-origin: margin; \n"
"								\n"
"                        } \n"
"QScrollBar::sub-line:vertical { \n"
"                            height: 0 px; \n"
"                            subcontrol-position: top; \n"
"                            subcontrol-origin: margin; \n"
"                        }\n"
""));
        horizontalLayout = new QHBoxLayout(globalReplaceInformation);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tableWidget = new QTableWidget(globalReplaceInformation);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 5)
            tableWidget->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(3, 1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(4, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setItem(4, 1, __qtablewidgetitem16);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setStyleSheet(QLatin1String("QTableWidget {background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"font: 15px \"WorkSans\",  \"Sans\";\n"
"gridline-color:white;\n"
"padding-left:10px;\n"
" }\n"
"QTableWidget::item{\n"
"  border-top: 1px solid black; \n"
"  border-bottom : solid black;\n"
"  padding: 10px;\n"
"}\n"
""));
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(190);
        tableWidget->verticalHeader()->setVisible(false);

        horizontalLayout->addWidget(tableWidget);


        retranslateUi(globalReplaceInformation);

        QMetaObject::connectSlotsByName(globalReplaceInformation);
    } // setupUi

    void retranslateUi(QDialog *globalReplaceInformation)
    {
        globalReplaceInformation->setWindowTitle(QApplication::translate("globalReplaceInformation", "Global Replacement", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("globalReplaceInformation", "New Column", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("globalReplaceInformation", "New Column", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("globalReplaceInformation", "New Row", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("globalReplaceInformation", "New Row", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("globalReplaceInformation", "New Row", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("globalReplaceInformation", "New Row", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem6->setText(QApplication::translate("globalReplaceInformation", "New Row", Q_NULLPTR));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(0, 0);
        ___qtablewidgetitem7->setText(QApplication::translate("globalReplaceInformation", "Global replacement", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(0, 1);
        ___qtablewidgetitem8->setText(QApplication::translate("globalReplaceInformation", "The words which need to be replaced throughout the whole file can be changed with this option.", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(1, 0);
        ___qtablewidgetitem9->setText(QApplication::translate("globalReplaceInformation", "Choose the words to be replaced", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(1, 1);
        ___qtablewidgetitem10->setText(QApplication::translate("globalReplaceInformation", "Selected list of words will be replaced in unedited pages", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(2, 0);
        ___qtablewidgetitem11->setText(QApplication::translate("globalReplaceInformation", "Replace in all pages", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(2, 1);
        ___qtablewidgetitem12->setText(QApplication::translate("globalReplaceInformation", "Checking these tick box will replace the words in already edited pages also.", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(3, 0);
        ___qtablewidgetitem13->setText(QApplication::translate("globalReplaceInformation", "Preview", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(3, 1);
        ___qtablewidgetitem14->setText(QApplication::translate("globalReplaceInformation", "Click the preview button to see how the changes will reflect in the document.", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(4, 0);
        ___qtablewidgetitem15->setText(QApplication::translate("globalReplaceInformation", "Save and Replace", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(4, 1);
        ___qtablewidgetitem16->setText(QApplication::translate("globalReplaceInformation", "Click the button to save and replace the changes made.", Q_NULLPTR));
        tableWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class globalReplaceInformation: public Ui_globalReplaceInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLOBALREPLACEINFORMATION_H
