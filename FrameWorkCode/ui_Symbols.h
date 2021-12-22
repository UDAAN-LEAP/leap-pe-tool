/********************************************************************************
** Form generated from reading UI file 'Symbols.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYMBOLS_H
#define UI_SYMBOLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
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
            SymbolsView->setObjectName(QString::fromUtf8("SymbolsView"));
        SymbolsView->resize(744, 428);
        SymbolsView->setStyleSheet(QString::fromUtf8("font: 11pt \"Work Sans\";\n"
"background-color: rgb(32, 33, 72);"));
        verticalLayout_4 = new QVBoxLayout(SymbolsView);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        copyButton = new QPushButton(SymbolsView);
        copyButton->setObjectName(QString::fromUtf8("copyButton"));
        copyButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:rgb(227, 228, 228);border:0px; color: rgb(32, 33, 72); height:26.96px; width: 113.5px; padding-top:1px; border-radius:4.8px; padding-left:1.3px; selection-color: rgb(32, 33, 72); selection-background-color: rgb(136, 138, 133);\n"
"} QPushButton:checked{background-color: rgb(136, 138, 133);} QPushButton:pressed {background-color: rgb(136, 138, 133);}"));

        verticalLayout_4->addWidget(copyButton);

        tabWidget = new QTabWidget(SymbolsView);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
"	border-radius: 0px;\n"
"	padding: 5px 15px;\n"
"	color: #1F2046;\n"
"\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"	background-color: #BCBDBD;\n"
"}\n"
"\n"
"QTabBar::tab:!selected {\n"
"	background-color: #E3E4E4;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"	top: -1px;\n"
"	bottom: 0px;\n"
"	border: 0px solid #BCBDBD;\n"
"	padding: 0px;\n"
"	margin: -10px -9px -10px -9px;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        verticalLayout_2 = new QVBoxLayout(tab_1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Diacritics = new QTextEdit(tab_1);
        Diacritics->setObjectName(QString::fromUtf8("Diacritics"));
        Diacritics->setEnabled(true);
        QFont font;
        font.setFamily(QString::fromUtf8("Work Sans"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        Diacritics->setFont(font);
        Diacritics->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255); color: black;"));
        Diacritics->setReadOnly(true);

        verticalLayout_2->addWidget(Diacritics);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout = new QVBoxLayout(tab_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        SpecialCharacters = new QTextEdit(tab_2);
        SpecialCharacters->setObjectName(QString::fromUtf8("SpecialCharacters"));
        SpecialCharacters->setFont(font);
        SpecialCharacters->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255); color: black;"));
        SpecialCharacters->setReadOnly(true);

        verticalLayout->addWidget(SpecialCharacters);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        MathematicalSymbols = new QTextEdit(tab_3);
        MathematicalSymbols->setObjectName(QString::fromUtf8("MathematicalSymbols"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Work Sans"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        font1.setKerning(false);
        MathematicalSymbols->setFont(font1);
        MathematicalSymbols->setStyleSheet(QString::fromUtf8("color: black; background-color: rgb(255, 255, 255);"));
        MathematicalSymbols->setReadOnly(true);
        MathematicalSymbols->setAcceptRichText(false);
        MathematicalSymbols->setTextInteractionFlags(Qt::TextSelectableByMouse);

        verticalLayout_3->addWidget(MathematicalSymbols);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_4->addWidget(tabWidget);


        retranslateUi(SymbolsView);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(SymbolsView);
    } // setupUi

    void retranslateUi(QDialog *SymbolsView)
    {
        SymbolsView->setWindowTitle(QCoreApplication::translate("SymbolsView", "Dialog", nullptr));
        copyButton->setText(QCoreApplication::translate("SymbolsView", "Copy", nullptr));
        Diacritics->setHtml(QCoreApplication::translate("SymbolsView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Work Sans'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Shobhika'; font-size:16pt;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Shobhika'; font-size:16pt;\"><br /></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QCoreApplication::translate("SymbolsView", "Diacritics", nullptr));
        SpecialCharacters->setHtml(QCoreApplication::translate("SymbolsView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Work Sans'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Shobhika'; font-size:16pt;\"><br /></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("SymbolsView", "Special Characters", nullptr));
        MathematicalSymbols->setHtml(QCoreApplication::translate("SymbolsView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Work Sans'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Shobhika'; font-size:16pt;\"><br /></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("SymbolsView", "Mathematical Symbols", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SymbolsView: public Ui_SymbolsView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYMBOLS_H
