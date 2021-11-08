/********************************************************************************
** Form generated from reading UI file 'Symbols.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYMBOLS_H
#define UI_SYMBOLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SymbolsView
{
public:
    QVBoxLayout *verticalLayout_4;
    QPushButton *copyButton;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *Diacritics;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *SpecialCharacters;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *MathematicalSymbols;

    void setupUi(QDialog *SymbolsView)
    {
        if (SymbolsView->objectName().isEmpty())
            SymbolsView->setObjectName(QStringLiteral("SymbolsView"));
        SymbolsView->resize(744, 428);
        verticalLayout_4 = new QVBoxLayout(SymbolsView);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        copyButton = new QPushButton(SymbolsView);
        copyButton->setObjectName(QStringLiteral("copyButton"));

        verticalLayout_4->addWidget(copyButton);

        tabWidget = new QTabWidget(SymbolsView);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        verticalLayout_2 = new QVBoxLayout(tab_1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        Diacritics = new QTextEdit(tab_1);
        Diacritics->setObjectName(QStringLiteral("Diacritics"));
        Diacritics->setEnabled(true);
        QFont font;
        font.setFamily(QStringLiteral("Shobhika"));
        font.setPointSize(16);
        Diacritics->setFont(font);
        Diacritics->setReadOnly(true);

        verticalLayout_2->addWidget(Diacritics);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout = new QVBoxLayout(tab_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        SpecialCharacters = new QTextEdit(tab_2);
        SpecialCharacters->setObjectName(QStringLiteral("SpecialCharacters"));
        SpecialCharacters->setFont(font);
        SpecialCharacters->setReadOnly(true);

        verticalLayout->addWidget(SpecialCharacters);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        MathematicalSymbols = new QTextEdit(tab_3);
        MathematicalSymbols->setObjectName(QStringLiteral("MathematicalSymbols"));
        QFont font1;
        font1.setFamily(QStringLiteral("Shobhika"));
        font1.setPointSize(16);
        font1.setKerning(false);
        MathematicalSymbols->setFont(font1);
        MathematicalSymbols->setReadOnly(true);
        MathematicalSymbols->setAcceptRichText(false);
        MathematicalSymbols->setTextInteractionFlags(Qt::TextSelectableByMouse);

        verticalLayout_3->addWidget(MathematicalSymbols);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_4->addWidget(tabWidget);


        retranslateUi(SymbolsView);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SymbolsView);
    } // setupUi

    void retranslateUi(QDialog *SymbolsView)
    {
        SymbolsView->setWindowTitle(QApplication::translate("SymbolsView", "Dialog", Q_NULLPTR));
        copyButton->setText(QApplication::translate("SymbolsView", "Copy", Q_NULLPTR));
        Diacritics->setHtml(QApplication::translate("SymbolsView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Shobhika'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("SymbolsView", "Diacritics", Q_NULLPTR));
        SpecialCharacters->setHtml(QApplication::translate("SymbolsView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Shobhika'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("SymbolsView", "Special Characters", Q_NULLPTR));
        MathematicalSymbols->setHtml(QApplication::translate("SymbolsView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Shobhika'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("SymbolsView", "Mathematical Symbols", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SymbolsView: public Ui_SymbolsView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYMBOLS_H
