/********************************************************************************
** Form generated from reading UI file 'diacriticsview.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIACRITICSVIEW_H
#define UI_DIACRITICSVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DiacriticsView
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *copyButton;
    QTextEdit *textEdit;

    void setupUi(QDialog *DiacriticsView)
    {
        if (DiacriticsView->objectName().isEmpty())
            DiacriticsView->setObjectName(QString::fromUtf8("DiacriticsView"));
        DiacriticsView->resize(544, 428);
        verticalLayout = new QVBoxLayout(DiacriticsView);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        copyButton = new QPushButton(DiacriticsView);
        copyButton->setObjectName(QString::fromUtf8("copyButton"));

        verticalLayout->addWidget(copyButton);

        textEdit = new QTextEdit(DiacriticsView);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QFont font;
        font.setPointSize(20);
        textEdit->setFont(font);

        verticalLayout->addWidget(textEdit);


        retranslateUi(DiacriticsView);

        QMetaObject::connectSlotsByName(DiacriticsView);
    } // setupUi

    void retranslateUi(QDialog *DiacriticsView)
    {
        DiacriticsView->setWindowTitle(QCoreApplication::translate("DiacriticsView", "Dialog", nullptr));
        copyButton->setText(QCoreApplication::translate("DiacriticsView", "Copy", nullptr));
        textEdit->setHtml(QCoreApplication::translate("DiacriticsView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:20pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">A</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\341\272\240 \341\272\241   \310\246 \310\247   \303\204 \303\244   \310\200 \310\201   \304\200 \304\201   \303\202 \303\242   \307\215 \307\216   \303\203 \303\243    </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubu"
                        "ntu';\">\303\205 \303\245   \341\270\200 \341\270\201   \304\202\304\203   \310\202 \310\203   \303\200 \303\240   A\314\262 a\314\262   \341\272\266 \341\272\267   \341\272\242 \341\272\243   </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\307\215 \307\216   \303\206</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">B</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\316\262</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px"
                        "; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">C</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\304\212 \304\213   C\314\210 c\314\210   \304\206 \304\207   \304\210 \304\211   \304\214 \304\215   \341\270\210 \341\270\211   \306\207 \306\210  \303\207 \303\247</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;"
                        "\">D</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\341\270\212 \341\270\213   \341\270\214 \341\270\215   \341\270\216 \341\270\217   \304\216 \304\217   \341\270\220 \341\270\221    \341\270\222 \341\270\223   \306\212 \311\227   \303\220 \304\221</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">E</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\304\226 \304\227   \303\213 \303\253   \303\211 \303\251   \303\210 \303\250   \303\212 \303\252"
                        "   \304\232 \304\233   \341\272\274 \341\272\275   \304\224 \304\225   </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\341\272\276 \341\272\277   \304\222 \304\223   \341\272\272 \341\272\273   \310\204 \310\205   \341\272\270 \341\272\271   \341\273\206 \341\273\207   \341\270\230 \341\270\231   \341\270\232 \341\270\233      </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">E\314\213 e\314\213</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600"
                        ";\">F</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\341\270\236 \341\270\237   \306\221 \306\222</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">G</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\304\240 \304\241   \341\270\240 \341\270\241   \307\264 \307\265   \304\234 \304\235   \307\246 \307\247   \304\236 \304\237   \307\244 \307\245   \304\242 \304\243   \306\223 \311\240</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-t"
                        "op:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">H</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\341\270\242 \341\270\243   \341\270\246 \341\270\247   \304\244 \304\245   \310\236 \310\237   \304\246 \304\247   \341\270\250 \341\270\251    \342\261\247 \342\261\250   \341\272\226 \341\272\226   </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\341\270\244 \341\270\245   \341\270\252 \341\270\253</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px"
                        "; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">I</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\303\215\342\200\211\303\255   \303\214\342\200\211\303\254    i\314\207\314\201      i\314\207\314\200     i\314\207\314\203   \303\217 \303\257   \303\216\342\200\211\303\256   \304\250 \304\251   </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\304\254\342\200\211\304\255   \307\217\342\200\211\307\220   \304\252\342\200\211\304\253   \341\273\210\342\200\211\341\273\211   \310\210\342\200\211\310\211   I\314\213\342\200\211i\314\213   \310"
                        "\212\342\200\211\310\213   \341\273\212\342\200\211\341\273\213   </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\341\266\226   \304\260\342\200\211i</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">J</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\304\264 \304\265    \307\260    \311\210 \311\211    J\314\203 j\314\207\314\203</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-r"
                        "ight:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">K</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\341\270\260 \341\270\261   \307\250 \307\251   \341\270\262 \341\270\263   \306\230 \306\231   \341\270\264 \341\270\265   \304\266 \304\267   \341\266\204   \342\261\251 \342\261\252</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">L</span></p>\n"
"<p style"
                        "=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\304\271 \304\272   \304\275 \304\276   \304\273 \304\274   \341\270\266 \341\270\267   \341\270\270 \341\270\271   L\314\203 l\314\203   \341\270\274 \341\270\275   \341\270\272 \341\270\273 </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">M</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\341\271\200 \341\271\201   \341\271\202 \341\271\203   \341\270\276 \341\270\277   M\314\213 m\314\213   M\314\203 m\314\203   "
                        " \341\265\257   \341\266\206</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">N</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\341\271\204\341\271\205   \341\271\206\341\271\207 \305\203\305\204   \307\270\307\271   \305\207\305\210   \303\221\303\261   \305\205\305\206    \341\271\212\341\271\213   \341\271\210\341\271\211   N\314\210n\314\210   \306\235\311\262</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p sty"
                        "le=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">O</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\303\223 \303\263   \303\222 \303\262   \310\256 \310\257   \303\226 \303\266   O\315\230 o\315\230   \303\224 \303\264   \307\221 \307\222   \305\216 \305\217   </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\305\214 \305\215   \305\220 \305\221   \303\225 \303\265   \307\252 \307\253   \341\273\216 \341\273\217   \310\214 \310\215   \310\216 \310\217  \341\273\214 \341\273\215</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-fa"
                        "mily:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">P</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\341\271\224 \341\271\225   \341\271\226 \341\271\227   \342\261\243 \341\265\275   \306\244 \306\245   P\314\203 p\314\203   \341\265\261   \341\266\210</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">Q</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-i"
                        "ndent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\312\240   \311\212   \311\213   q\314\203</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">R</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\305\224 \305\225   \311\214 \311\215   \305\230 \305\231   \305\226 \305\227   \341\271\230 \341\271\231   \310\220 \310\221   \310\222 \310\223   \341\271\232 \341\271\233   </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\341\271\234"
                        " \341\271\235   \341\271\236 \341\271\237   \342\261\244 \311\275   R\314\203 r\314\203   \341\266\211</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">S</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\305\232 \305\233   \341\271\240 \341\271\241   \341\271\242 \341\271\243   \341\271\250 \341\271\251   S\314\210 s\314\210   \310\277</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bo"
                        "ttom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">T</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\305\244 \305\245   \341\271\252 \341\271\253   \305\242 \305\243   \341\271\254 \341\271\255   \310\232 \310\233   \341\271\260 \341\271\261   \341\271\256 \341\271\257   T\314\210 \341\272\227</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">U</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
                        "<span style=\" font-family:'Ubuntu';\">\303\232 \303\272   \303\231 \303\271   \305\250 \305\251   \341\273\244 \341\273\245   \303\234 \303\274   \341\271\262 \341\271\263   \305\252 \305\253   \303\233 \303\273   </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\341\271\266 \341\271\267   \307\223 \307\224   \305\260 \305\261   \305\254 \305\255   \310\226 \310\227   \305\256 \305\257   \310\224 \310\225</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">V</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-inde"
                        "nt:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\341\271\274 \341\271\275   \341\271\276 \341\271\277   \306\262 \312\213   \341\266\214</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">W</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\341\272\202 \341\272\203   \341\272\200 \341\272\201   \305\264 \305\265   \341\272\204 \341\272\205   \341\272\206 \341\272\207   \341\272\210 \341\272\211   \341\272\230</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-"
                        "indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">X</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\341\272\214 \341\272\215   \341\272\212 \341\272\213   \341\266\215</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">Y</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\""
                        ">\303\235 \303\275   \341\273\262 \341\273\263   \305\266 \305\267   \305\270 \303\277   \341\273\270 \341\273\271   \341\272\216 \341\272\217   \341\273\264 \341\273\265   \341\273\266 \341\273\267   </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\310\262 \310\263</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">Z</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\305\271 \305\272   \341\272\220 \341\272\221   \305\275 \305\276   \305\273 \305"
                        "\274   \341\272\222 \341\272\223   \341\272\224 \341\272\225   \342\261\253 \342\261\254</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DiacriticsView: public Ui_DiacriticsView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIACRITICSVIEW_H
