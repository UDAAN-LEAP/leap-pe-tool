/********************************************************************************
** Form generated from reading UI file 'shortcutguidedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHORTCUTGUIDEDIALOG_H
#define UI_SHORTCUTGUIDEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_ShortcutGuideDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *ShortcutGuideDialog)
    {
        if (ShortcutGuideDialog->objectName().isEmpty())
            ShortcutGuideDialog->setObjectName(QString::fromUtf8("ShortcutGuideDialog"));
        ShortcutGuideDialog->resize(760, 444);
        horizontalLayout = new QHBoxLayout(ShortcutGuideDialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        textBrowser = new QTextBrowser(ShortcutGuideDialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        horizontalLayout->addWidget(textBrowser);


        retranslateUi(ShortcutGuideDialog);

        QMetaObject::connectSlotsByName(ShortcutGuideDialog);
    } // setupUi

    void retranslateUi(QDialog *ShortcutGuideDialog)
    {
        ShortcutGuideDialog->setWindowTitle(QApplication::translate("ShortcutGuideDialog", " Shortcut Guide", nullptr));
        textBrowser->setHtml(QApplication::translate("ShortcutGuideDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"docs-internal-guid-207f323b-7fff-f7c8-e38e-64c168e8249e\"></a><span style=\" font-family:'Arial'; font-size:24pt; color:#000000; background-color:transparent;\">O</span><span style=\" font-family:'Arial'; font-size:24pt; color:#000000; background-color:transparent;\">penOCRCorrect - Shortcut Guide</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Arial'; font-size:24pt; color:#000000;\"><br /></p>\n"
""
                        "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"docs-internal-guid-0b74e873-7fff-3304-3708-713a3a99570c\"></a><span style=\" font-family:'Arial'; font-size:16pt; color:#000000; background-color:transparent;\">1</span><span style=\" font-family:'Arial'; font-size:16pt; color:#000000; background-color:transparent;\">. Open a project</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"docs-internal-guid-53297173-7fff-4e76-dc90-52d64f9fbae0\"></a><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\"> </span><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">    \342\227\217 Press </span><span style=\" font-family:'Arial'; font-size:12pt; font-weight:696; color:#000000; background-color:transparent;\">Ctrl + O </span><span style=\" font-family:'Arial"
                        "'; font-size:12pt; color:#000000; background-color:transparent;\">and select the project.xml file from the project folder to open the project.\302\240</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Arial'; font-size:12pt; color:#000000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"docs-internal-guid-0b65b253-7fff-9539-67d0-6fa1a76d8d37\"></a><span style=\" font-family:'Arial'; font-size:16pt; color:#000000; background-color:transparent;\">2</span><span style=\" font-family:'Arial'; font-size:16pt; color:#000000; background-color:transparent;\">. Save a File\302\240</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:120%;\"><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; back"
                        "ground-color:transparent;\">     \342\227\217 Press </span><span style=\" font-family:'Arial'; font-size:12pt; font-weight:696; color:#000000; background-color:transparent;\">Ctrl + S </span><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">to save the file.\302\240</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:120%; font-family:'Arial'; font-size:12pt; color:#000000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:120%;\"><a name=\"docs-internal-guid-cdef9869-7fff-d767-c867-43621f5dfe17\"></a><span style=\" font-family:'Arial'; font-size:16pt; color:#000000; background-color:transparent;\">3</span><span style=\" font-family:'Arial'; font-size:16pt; color:#000000; background-color:transparent;\">. Open a new tab\302\240</span></p>\n"
"<p sty"
                        "le=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">     \342\227\217 Press </span><span style=\" font-family:'Arial'; font-size:12pt; font-weight:696; color:#000000; background-color:transparent;\">Ctrl + N </span><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">to open a new tab in the window. </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Arial'; font-size:12pt; color:#000000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"docs-internal-guid-9a3be215-7fff-539a-01c6-5f292e060498\"></a><span style=\" font-family:'Arial'; font-size:16pt; color:#000000; background-color:transparen"
                        "t;\">4</span><span style=\" font-family:'Arial'; font-size:16pt; color:#000000; background-color:transparent;\">. Save As\302\240</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:137.445%;\"><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">     \342\227\217 Press </span><span style=\" font-family:'Arial'; font-size:12pt; font-weight:696; color:#000000; background-color:transparent;\">Ctrl + Shift + S </span><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">to save the file as a different copy with a different name and/or different location.\302\240</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:137.445%; font-family:'Arial'; font-size:12pt; color:#000000;\"><br /></p>\n"
"<p style=\" margin-top:0"
                        "px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:137.445%;\"><a name=\"docs-internal-guid-bacf0f61-7fff-f1fb-6d85-3fd9d2c514ce\"></a><span style=\" font-family:'Arial'; font-size:16pt; color:#000000; background-color:transparent;\">5</span><span style=\" font-family:'Arial'; font-size:16pt; color:#000000; background-color:transparent;\">. Navigate between pages\302\240</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial'; color:#000000; background-color:transparent;\">     \342\227\217 </span><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">Press </span><span style=\" font-family:'Arial'; font-size:12pt; font-weight:696; color:#000000; background-color:transparent;\">Ctrl + Shift + R </span><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">"
                        "to navigate through the next page, </span><span style=\" font-family:'Arial'; font-size:12pt; font-weight:696; color:#000000; background-color:transparent;\">Ctrl + Shift + L </span><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">to navigate to the previous page.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Arial'; font-size:12pt; color:#000000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"docs-internal-guid-53e0e007-7fff-372e-8c61-3b2dee5e0974\"></a><span style=\" font-family:'Arial'; font-size:16pt; color:#000000; background-color:transparent;\">6</span><span style=\" font-family:'Arial'; font-size:16pt; color:#000000; background-color:transparent;\">. Undo &amp; Redo\302\240</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:"
                        "0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">     \342\227\217 Press </span><span style=\" font-family:'Arial'; font-size:12pt; font-weight:696; color:#000000; background-color:transparent;\">Ctrl + Z </span><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">to undo the changes and </span><span style=\" font-family:'Arial'; font-size:12pt; font-weight:696; color:#000000; background-color:transparent;\">Ctrl + Shift + Z </span><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">to redo the changes.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Arial'; font-size:12pt; color:#000000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; ma"
                        "rgin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"docs-internal-guid-c87b004b-7fff-696d-698c-87f081646800\"></a><span style=\" font-family:'Arial'; font-size:16pt; color:#000000; background-color:transparent;\">7</span><span style=\" font-family:'Arial'; font-size:16pt; color:#000000; background-color:transparent;\">. Find &amp; Replace\302\240</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">     \342\227\217 Press </span><span style=\" font-family:'Arial'; font-size:12pt; font-weight:696; color:#000000; background-color:transparent;\">Ctrl + F </span><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">to find and/or replace text.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-inden"
                        "t:0; text-indent:0px; font-family:'Arial'; font-size:12pt; color:#000000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"docs-internal-guid-90129f6b-7fff-9a18-b608-e0e70525b201\"></a><span style=\" font-family:'Arial'; font-size:16pt; color:#000000; background-color:transparent;\">8</span><span style=\" font-family:'Arial'; font-size:16pt; color:#000000; background-color:transparent;\">. Highlight\302\240</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">     \342\227\217 Press </span><span style=\" font-family:'Arial'; font-size:12pt; font-weight:696; color:#000000; background-color:transparent;\">Ctrl + H </span><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">to highlight the s"
                        "elected text.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Arial'; font-size:12pt; color:#000000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"docs-internal-guid-d22fbf0c-7fff-c67d-6948-1bf776d7287f\"></a><span style=\" font-family:'Arial'; font-size:16pt; color:#000000; background-color:transparent;\">9</span><span style=\" font-family:'Arial'; font-size:16pt; color:#000000; background-color:transparent;\">. Spell Check\302\240</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">     \342\227\217 Press </span><span style=\" font-family:'Arial'; font-size:12pt; font-weight:696; color:#000000; background-c"
                        "olor:transparent;\">Ctrl + C </span><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">to perform Spell Check.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Arial'; font-size:12pt; color:#000000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"docs-internal-guid-672dffa8-7fff-109c-3dc6-e7fe50b891b2\"></a><span style=\" font-family:'Arial'; font-size:16pt; color:#000000; background-color:transparent;\">1</span><span style=\" font-family:'Arial'; font-size:16pt; color:#000000; background-color:transparent;\">0. Convert text to Devanagari\302\240</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial'; color:#000000; background-col"
                        "or:transparent;\">     \342\227\217 </span><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">Press </span><span style=\" font-family:'Arial'; font-size:12pt; font-weight:696; color:#000000; background-color:transparent;\">Ctrl + D </span><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">to convert selected text to devanagari format.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Arial'; font-size:12pt; color:#000000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"docs-internal-guid-2e7f5aea-7fff-3f34-ad42-f5c05e7ea901\"></a><span style=\" font-family:'Arial'; font-size:16pt; color:#000000; background-color:transparent;\">1</span><span style=\" font-family:'Arial'; font-size:16pt; color:#00000"
                        "0; background-color:transparent;\">1. Text Formatting\302\240</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:120%;\"><span style=\" font-family:'Arial'; font-size:12pt; font-weight:696; color:#000000; background-color:transparent;\">     \342\227\217 Bold: </span><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">Press </span><span style=\" font-family:'Arial'; font-size:12pt; font-weight:696; color:#000000; background-color:transparent;\">Ctrl + B </span><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">to make selected text </span><span style=\" font-family:'Arial'; font-size:12pt; font-weight:696; color:#000000; background-color:transparent;\">Bold\302\240</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:120%;\"><span s"
                        "tyle=\" font-family:'Arial'; font-size:12pt; font-style:italic; color:#000000; background-color:transparent;\">     \342\227\217 Italic: </span><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">Press </span><span style=\" font-family:'Arial'; font-size:12pt; font-weight:696; color:#000000; background-color:transparent;\">Ctrl + I </span><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">to make text </span><span style=\" font-family:'Arial'; font-size:12pt; font-style:italic; color:#000000; background-color:transparent;\">Italic\302\240</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:120%;\"><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">     \342\227\217 Subscript: Press </span><span style=\" font-family:'Arial'; font-size:12pt; font-weight:696; color:#000000; backgr"
                        "ound-color:transparent;\">Ctrl + ` </span><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">to make text subscripted\302\240</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:120%;\"><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">     \342\227\217 Superscript: Press </span><span style=\" font-family:'Arial'; font-size:12pt; font-weight:696; color:#000000; background-color:transparent;\">Ctrl + Shift + ` </span><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">to make text superscript\302\240</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">     \342\227\217 Tab Space: Press </span><span"
                        " style=\" font-family:'Arial'; font-size:12pt; font-weight:696; color:#000000; background-color:transparent;\">Ctrl + T </span><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">to add tab space</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Arial'; font-size:12pt; color:#000000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a name=\"docs-internal-guid-bf1235c0-7fff-b3bc-9c96-be483f42d2af\"></a><span style=\" font-family:'Arial'; font-size:16pt; color:#000000; background-color:transparent;\">1</span><span style=\" font-family:'Arial'; font-size:16pt; color:#000000; background-color:transparent;\">2. Devanagari to SLP\302\240</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-inde"
                        "nt:0px;\"><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">     \342\227\217 Press </span><span style=\" font-family:'Arial'; font-size:12pt; font-weight:696; color:#000000; background-color:transparent;\">Ctrl + G </span><span style=\" font-family:'Arial'; font-size:12pt; color:#000000; background-color:transparent;\">to Convert devanagari to roman letters as mapped in SLP Guide</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShortcutGuideDialog: public Ui_ShortcutGuideDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHORTCUTGUIDEDIALOG_H
