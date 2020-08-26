/********************************************************************************
** Form generated from reading UI file 'Symbols.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
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
        verticalLayout_4 = new QVBoxLayout(SymbolsView);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        copyButton = new QPushButton(SymbolsView);
        copyButton->setObjectName(QString::fromUtf8("copyButton"));

        verticalLayout_4->addWidget(copyButton);

        tabWidget = new QTabWidget(SymbolsView);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        verticalLayout_2 = new QVBoxLayout(tab_1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Diacritics = new QTextEdit(tab_1);
        Diacritics->setObjectName(QString::fromUtf8("Diacritics"));
        QFont font;
        font.setPointSize(20);
        Diacritics->setFont(font);

        verticalLayout_2->addWidget(Diacritics);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout = new QVBoxLayout(tab_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        SpecialCharacters = new QTextEdit(tab_2);
        SpecialCharacters->setObjectName(QString::fromUtf8("SpecialCharacters"));
        SpecialCharacters->setFont(font);

        verticalLayout->addWidget(SpecialCharacters);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        MathematicalSymbols = new QTextEdit(tab_3);
        MathematicalSymbols->setObjectName(QString::fromUtf8("MathematicalSymbols"));
        MathematicalSymbols->setFont(font);

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
"</style></head><body style=\" font-family:'Ubuntu'; font-size:20pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">A</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\341\272\240 \341\272\241   \310\246 \310\247   \303\204 \303\244   \310\200 \310\201   \304\200 \304\201   \303\202 \303\242   \307\215 \307\216   \303\203 \303\243    </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\303\205 \303\245   \341\270\200 \341\270\201   \304\202\304\203   \310\202 \310\203   \303\200 \303"
                        "\240   A\314\262 a\314\262   \341\272\266 \341\272\267   \341\272\242 \341\272\243   </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\307\215 \307\216   \303\206 <a name=\"docs-internal-guid-9bc969e4-7fff-90e1-a47c-a049236ab599\"></a><span style=\" font-family:'Arial'; color:#202122; background-color:#f8f9fa;\">\323\225</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">B</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\316\262</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-ind"
                        "ent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">C</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\304\212 \304\213   C\314\210 c\314\210   \304\206 \304\207   \304\210 \304\211   \304\214 \304\215   \341\270\210 \341\270\211   \306\207 \306\210  \303\207 \303\247</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">D</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\341\270\212 \341\270\213   \341\270\214 \341\270\215   \341\270\216 \341\270"
                        "\217   \304\216 \304\217   \341\270\220 \341\270\221    \341\270\222 \341\270\223   \306\212 \311\227   \303\220 \304\221</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">E</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\304\226 \304\227   \303\213 \303\253   \303\211 \303\251   \303\210 \303\250   \303\212 \303\252   \304\232 \304\233   \341\272\274 \341\272\275   \304\224 \304\225   </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\341\272\276 \341\272\277   \304\222 \304\223   \341\272\272 \341\272\273   \310\204 \310\205   \341\272\270 \341\272\271   \341\273\206 \341\273"
                        "\207   \341\270\230 \341\270\231   \341\270\232 \341\270\233      </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">E\314\213 e\314\213</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">F</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\341\270\236 \341\270\237   \306\221 \306\222</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style"
                        "=\" font-weight:600;\">G</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\304\240 \304\241   \341\270\240 \341\270\241   \307\264 \307\265   \304\234 \304\235   \307\246 \307\247   \304\236 \304\237   \307\244 \307\245   \304\242 \304\243   \306\223 \311\240</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">H</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\341\270\242 \341\270\243   \341\270\246 \341\270\247   \304\244 \304\245   \310\236 \310\237   \304\246 \304\247   \341\270\250 \341\270\251    \342\261\247 \342\261\250   \341\272\226 \341\272\226   </p>\n"
"<p sty"
                        "le=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\341\270\244 \341\270\245   \341\270\252 \341\270\253</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">I</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\303\215\342\200\211\303\255   \303\214\342\200\211\303\254    i\314\207\314\201      i\314\207\314\200     i\314\207\314\203   \303\217 \303\257   \303\216\342\200\211\303\256   \304\250 \304\251   </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\304\254\342\200\211\304\255   \307\217\342\200\211\307\220   \304"
                        "\252\342\200\211\304\253   \341\273\210\342\200\211\341\273\211   \310\210\342\200\211\310\211   I\314\213\342\200\211i\314\213   \310\212\342\200\211\310\213   \341\273\212\342\200\211\341\273\213   </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\341\266\226   \304\260\342\200\211i</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">J</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\304\264 \304\265    \307\260    \311\210 \311\211    J\314\203 j\314\207\314\203</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px;"
                        " -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">K</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\341\270\260 \341\270\261   \307\250 \307\251   \341\270\262 \341\270\263   \306\230 \306\231   \341\270\264 \341\270\265   \304\266 \304\267   \341\266\204   \342\261\251 \342\261\252</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">L</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\304\271 \304\272   \304\275 \304"
                        "\276   \304\273 \304\274   \341\270\266 \341\270\267   \341\270\270 \341\270\271   L\314\203 l\314\203   \341\270\274 \341\270\275   \341\270\272 \341\270\273 </p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">M</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\341\271\200 \341\271\201   \341\271\202 \341\271\203   \341\270\276 \341\270\277   M\314\213 m\314\213   M\314\203 m\314\203    \341\265\257   \341\266\206</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:"
                        "0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">N</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\341\271\204\341\271\205   \341\271\206\341\271\207 \305\203\305\204   \307\270\307\271   \305\207\305\210   \303\221\303\261   \305\205\305\206    \341\271\212\341\271\213   \341\271\210\341\271\211   N\314\210n\314\210   \306\235\311\262</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">O</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\303\223 \303\263   \303\222 \303\262   \310\256 \310\257   \303\226 \303\266   O\315\230 o\315\230   \303\224"
                        " \303\264   \307\221 \307\222   \305\216 \305\217   </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\305\214 \305\215   \305\220 \305\221   \303\225 \303\265   \307\252 \307\253   \341\273\216 \341\273\217   \310\214 \310\215   \310\216 \310\217  \341\273\214 \341\273\215</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">P</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\341\271\224 \341\271\225   \341\271\226 \341\271\227   \342\261\243 \341\265\275   \306\244 \306\245   P\314\203 p\314\203   \341\265\261   \341\266\210</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-to"
                        "p:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Q</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\312\240   \311\212   \311\213   q\314\203</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">R</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\305\224 \305\225   \311\214 \311\215   \305\230 \305\231   \305\226 \305\227   \341\271\230 \341\271\231   \310"
                        "\220 \310\221   \310\222 \310\223   \341\271\232 \341\271\233   </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\341\271\234 \341\271\235   \341\271\236 \341\271\237   \342\261\244 \311\275   R\314\203 r\314\203   \341\266\211</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">S</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\305\232 \305\233   \341\271\240 \341\271\241   \341\271\242 \341\271\243   \341\271\250 \341\271\251   S\314\210 s\314\210   \310\277</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-"
                        "block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">T</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\305\244 \305\245   \341\271\252 \341\271\253   \305\242 \305\243   \341\271\254 \341\271\255   \310\232 \310\233   \341\271\260 \341\271\261   \341\271\256 \341\271\257   T\314\210 \341\272\227</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">U</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\303\232 \303\272   \303\231"
                        " \303\271   \305\250 \305\251   \341\273\244 \341\273\245   \303\234 \303\274   \341\271\262 \341\271\263   \305\252 \305\253   \303\233 \303\273   </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\341\271\266 \341\271\267   \307\223 \307\224   \305\260 \305\261   \305\254 \305\255   \310\226 \310\227   \305\256 \305\257   \310\224 \310\225</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">V</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\341\271\274 \341\271\275   \341\271\276 \341\271\277   \306\262 \312\213   \341\266\214</p>\n"
"<p style=\"-qt-paragraph-type:empty; margi"
                        "n-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">W</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\341\272\202 \341\272\203   \341\272\200 \341\272\201   \305\264 \305\265   \341\272\204 \341\272\205   \341\272\206 \341\272\207   \341\272\210 \341\272\211   \341\272\230</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">X</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:"
                        "0; text-indent:0px;\">\341\272\214 \341\272\215   \341\272\212 \341\272\213   \341\266\215</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Y</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\303\235 \303\275   \341\273\262 \341\273\263   \305\266 \305\267   \305\270 \303\277   \341\273\270 \341\273\271   \341\272\216 \341\272\217   \341\273\264 \341\273\265   \341\273\266 \341\273\267   </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\310\262 \310\263</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block"
                        "-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Z</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\305\271 \305\272   \341\272\220 \341\272\221   \305\275 \305\276   \305\273 \305\274   \341\272\222 \341\272\223   \341\272\224 \341\272\225   \342\261\253 \342\261\254</p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QCoreApplication::translate("SymbolsView", "Diacritics", nullptr));
        SpecialCharacters->setHtml(QCoreApplication::translate("SymbolsView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:20pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"docs-internal-guid-f0af7852-7fff-6c5b-db96-c848c4aeda35\"></a><span style=\" font-family:'Arial'; font-size:24pt; color:#1d1c1d; background-color:#ffffff;\">\302\266</span><span style=\" font-family:'Arial'; font-size:24pt; color:#1d1c1d; background-color:#ffffff;\">\302\240 \302\246\302\240 \310\234\302\240 \310\235\302\240 \342\200\224\302\240 \342\200\223\302\240 \342\200\221\302\240 \302\260\302\240 \302\267</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("SymbolsView", "Special Characters", nullptr));
        MathematicalSymbols->setHtml(QCoreApplication::translate("SymbolsView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:20pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:138%;\"><a name=\"docs-internal-guid-da2b489d-7fff-3a9f-1ab2-7e8e61a9c3d8\"></a><span style=\" font-family:'Arial'; font-size:24pt; color:#202122; background-color:#ffffff;\">\342\210\200</span><span style=\" font-family:'Arial'; font-size:24pt; color:#202122; background-color:#ffffff;\">\302\240 \342\210\201\302\240 \342\210\202\302\240 \342\210\203\302\240 \342\210\204\302\240 \342\210\205\302\240 \342\210\206\302\240 \342\210\207\302\240 \342\210\210\302\240 \342\210\211\302\240 \342\210\212\302\240 \342\210\213\302\240 \342\210\214\302\240 \342\210\215"
                        "\302\240 \342\210\216\302\240 \342\210\217</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:138%;\"><span style=\" font-family:'Arial'; font-size:24pt; color:#202122; background-color:#ffffff;\">\342\210\220\302\240 \342\210\221\302\240 \342\210\222\302\240 \342\210\223\302\240 \342\210\224\302\240 \342\210\225\302\240 \342\210\226\302\240 \342\210\227\302\240 \342\210\230\302\240 \342\210\231\302\240 \342\210\232\302\240 \342\210\233\302\240 \342\210\234\302\240 \342\210\235\302\240 \342\210\236\302\240 \342\210\237  \342\210\240  </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:138%;\"><span style=\" font-family:'Arial'; font-size:24pt; color:#202122; background-color:#ffffff;\">\342\210\241\302\240 \342\210\242\302\240 \342\210\243\302\240 \342\210\244\302\240 \342\210\245\302\240 \342\210\246\302\240 \342\210\247\302"
                        "\240 \342\210\250\302\240 \342\210\251\302\240 \342\210\252\302\240\302\240\342\210\253\302\240 \342\210\254\302\240 \342\210\255\302\240 \342\210\256\302\240 \342\210\257\302\240 \342\210\260\302\240 </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:138%;\"><span style=\" font-family:'Arial'; font-size:24pt; color:#202122; background-color:#ffffff;\">\342\210\261\302\240 \342\210\262\302\240 \342\210\263\302\240\302\240\342\210\264\302\240 \342\210\265\302\240 \342\210\266\302\240 \342\210\267\302\240 \342\210\270\302\240 \342\210\271\302\240 \342\210\272\302\240 \342\210\273\302\240 \342\210\274\302\240 \342\210\275\302\240 \342\210\276\302\240 \342\210\277\302\240\302\240\342\211\200\302\240 \342\211\201\302\240 </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:138%;\"><span style=\" font-family:'Arial'; font-size:24"
                        "pt; color:#202122; background-color:#ffffff;\">\342\211\202\302\240 \342\211\203\302\240 \342\211\204\302\240 \342\211\205\302\240 \342\211\206\302\240 \342\211\207\302\240 \342\211\210\302\240 \342\211\211\302\240 \342\211\212\302\240 \342\211\213\302\240 \342\211\214\302\240 \342\211\215\302\240 \342\211\216\302\240 \342\211\217\302\240\302\240\342\211\220\302\240 </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:138%;\"><span style=\" font-family:'Arial'; font-size:24pt; color:#202122; background-color:#ffffff;\">\342\211\221\302\240 \342\211\222\302\240 \342\211\223\302\240 \342\211\224\302\240 \342\211\225\302\240 \342\211\226\302\240 \342\211\227\302\240 \342\211\230\302\240 \342\211\231\302\240 \342\211\232\302\240 \342\211\233\302\240 \342\211\234\302\240 \342\211\235\302\240 \342\211\236\302\240 \342\211\237\302\240\302\240</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; marg"
                        "in-right:0px; -qt-block-indent:0; text-indent:0px; line-height:138%;\"><span style=\" font-family:'Arial'; font-size:24pt; color:#202122; background-color:#ffffff;\">\342\211\240\302\240 \342\211\241\302\240 \342\211\242\302\240 \342\211\243\302\240 \342\211\244\302\240 \342\211\245\302\240 \342\211\246\302\240 \342\211\247\302\240 \342\211\250\302\240 \342\211\251\302\240 \342\211\252\302\240 \342\211\253\302\240 \342\211\254\302\240 \342\211\255\302\240 \342\211\256\302\240 \342\211\257\302\240\302\240</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:138%;\"><span style=\" font-family:'Arial'; font-size:24pt; color:#202122; background-color:#ffffff;\">\342\211\260\302\240 \342\211\261\302\240 \342\211\262\302\240 \342\211\263\302\240 \342\211\264\302\240 \342\211\265\302\240 \342\211\266\302\240 \342\211\267\302\240 \342\211\270\302\240 \342\211\271  \342\212\202\302\240 \342\212\203\302\240 \342\212\204\302\240 "
                        "\342\212\205\302\240 \342\212\206\302\240 \342\212\207\302\240 </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:138%;\"><span style=\" font-family:'Arial'; font-size:24pt; color:#202122; background-color:#ffffff;\">\342\212\210\302\240 \342\212\211\302\240 \342\212\212\302\240 \342\212\213\302\240 \342\212\214\302\240 \342\212\215\302\240 \342\212\216\302\240 \342\212\217\302\240\302\240\342\212\220\302\240 \342\212\221\302\240 \342\212\222\302\240 \342\212\223\302\240 \342\212\224\302\240 \342\212\225\302\240 \342\212\226\302\240 \342\212\227\302\240 </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:138%;\"><span style=\" font-family:'Arial'; font-size:24pt; color:#202122; background-color:#ffffff;\">\342\212\230\302\240 \342\212\231\302\240 \342\212\242\302\240 \342\212\243\302\240 \342\212\244\302\240 \342\212\245\302"
                        "\240 \342\212\246\302\240 \342\212\247\302\240 \342\212\250\302\240 \342\212\251\302\240 \342\212\252\302\240 \342\212\253\302\240 \342\212\254\302\240 \342\212\255\302\240 \342\212\256\302\240 \342\212\257\302\240\302\240</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:138%;\"><span style=\" font-family:'Arial'; font-size:24pt; color:#202122; background-color:#ffffff;\">\342\212\273\302\240 \342\212\274\302\240 \342\212\275\302\240 \342\212\276\302\240 \342\212\277\302\240\302\240\342\213\200\302\240 \342\213\201\302\240 \342\213\202\302\240 \342\213\203\302\240 \342\213\204\302\240 \342\213\205\302\240 \342\213\206\302\240 \342\213\207\302\240 \342\213\210\302\240 \342\213\211\302\240 \342\213\212\302\240 </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:138%;\"><span style=\" font-family:'Arial'; font-size:24pt; col"
                        "or:#202122; background-color:#ffffff;\">\342\213\213\302\240 \342\213\214\302\240 \342\213\215\302\240 \342\213\216\302\240 \342\213\217  \342\213\220\302\240 \342\213\221\302\240 \342\213\222\302\240 \342\213\223\302\240 \342\213\224\302\240 \342\213\225\302\240 \342\213\226\302\240 \342\213\227\302\240 \342\213\230\302\240 \342\213\231\302\240 </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:138%;\"><span style=\" font-family:'Arial'; font-size:24pt; color:#202122; background-color:#ffffff;\">\342\213\232\302\240 \342\213\233\302\240 \342\213\234\302\240 \342\213\235\302\240 \342\213\236\302\240 \342\213\237\302\240\302\240\342\213\256\302\240 \342\213\257\302\240\302\240\342\213\260\302\240 \342\213\261\302\240 \342\213\265\302\240 \342\213\266\302\240 \342\213\267\302\240 \342\213\270\302\240 \342\213\271\302\240 </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; "
                        "-qt-block-indent:0; text-indent:0px; line-height:138%;\"><span style=\" font-family:'Arial'; font-size:24pt; color:#202122; background-color:#ffffff;\">\342\213\272\302\240 \342\213\273\302\240 \342\213\274\302\240 \342\213\275\302\240 \342\213\276\302\240 \342\213\277</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:138%; font-family:'Arial'; font-size:24pt; color:#202122;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:138%;\"><span style=\" font-family:'Arial'; font-size:24pt; color:#000000; background-color:transparent;\">\342\245\242\302\240 \342\245\243\302\240 \342\245\244\302\240 \342\245\245\302\240 \342\245\246\302\240 \342\245\247\302\240 \342\245\250\302\240 \342\245\251\302\240 \342\245\252\302\240 \342\245\253\302\240 \342\245\254\302\240 \342\245\255\302\240 \342\245\256\302\240"
                        " \342\245\257</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:138%; font-family:'Arial'; font-size:24pt; color:#202122;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:138%;\"><span style=\" font-family:'Arial'; font-size:24pt; color:#000000; background-color:transparent;\">\360\235\233\243\302\240 \360\235\233\244\302\240 \360\235\233\245\302\240 \360\235\233\246\302\240 \360\235\233\247\302\240 \360\235\233\250\302\240 \360\235\233\251\302\240 \360\235\233\252\302\240 \360\235\233\253\302\240 \360\235\233\254\302\240 \360\235\233\255\302\240 \360\235\233\256\302\240 \360\235\233\257  \360\235\233\260\302\240 \360\235\233\261\302\240 \360\235\233\262\302\240 \360\235\233\263\302\240 \360\235\233\264\302\240 </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; marg"
                        "in-right:0px; -qt-block-indent:0; text-indent:0px; line-height:138%;\"><span style=\" font-family:'Arial'; font-size:24pt; color:#000000; background-color:transparent;\">\360\235\233\265\302\240 \360\235\233\266\302\240 \360\235\233\267\302\240 \360\235\233\270\302\240 \360\235\233\271\302\240 \360\235\233\272\302\240 \360\235\233\273\302\240 \360\235\233\274\302\240 \360\235\233\275\302\240 \360\235\233\276\302\240 \360\235\233\277  \360\235\234\200\302\240 \360\235\234\201\302\240 \360\235\234\202\302\240 \360\235\234\203\302\240 \360\235\234\204\302\240 \360\235\234\205\302\240 \360\235\234\206\302\240 \360\235\234\207\302\240 \360\235\234\210  </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:138%;\"><span style=\" font-family:'Arial'; font-size:24pt; color:#000000; background-color:transparent;\">\360\235\234\211\302\240 \360\235\234\212\302\240 \360\235\234\213\302\240 \360\235\234\214\302\240 \360\235\234\215"
                        "\302\240 \360\235\234\216\302\240 \360\235\234\217  \360\235\234\220\302\240 \360\235\234\221\302\240 \360\235\234\222\302\240 \360\235\234\223\302\240 \360\235\234\224\302\240 \360\235\234\225\302\240 \360\235\234\226\302\240 \360\235\234\227\302\240 \360\235\234\230\302\240 \360\235\234\231\302\240 \360\235\234\232\302\240 \360\235\234\233\302\240 </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:138%;\"><a name=\"docs-internal-guid-c92af4c9-7fff-bba2-a4a0-51e856a97003\"></a><span style=\" font-family:'Arial'; font-size:24pt; color:#000000; background-color:transparent;\">\342\204\211</span><span style=\" font-family:'Arial'; font-size:24pt; color:#000000; background-color:transparent;\"> \342\204\203	</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bot"
                        "tom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:138%; font-family:'Arial'; font-size:24pt; color:#202122;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("SymbolsView", "Mathematical Symbols", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SymbolsView: public Ui_SymbolsView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYMBOLS_H
