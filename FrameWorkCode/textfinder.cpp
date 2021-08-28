/*!
  \class TextFinder
  \brief The TextFinder class helps to find particular text and replaces them with new user entered text

  At times, the user may want to find a particular text from a lengthy document to change it. It is time
  consuming for the user to go through each line to find and edit it. The TextFinder class offers functions
  that allows easy text search and replacement.

  \sa getCurrentBrowser()
*/
#include "textfinder.h"
#include "ui_textfinder.h"
#include <QDebug>
#include "mainwindow.h"
#include <QString>
#include <string>

using namespace std;
extern string toslp1(string s);
extern string toDev(string s);

TextFinder *TextFinder::textFinder = 0;
TextFinder::TextFinder(QWidget *parent) :
    QDialog(parent, Qt::WindowCloseButtonHint),
    ui(new Ui::TextFinder)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    ui->findLineEdit->installEventFilter(this);
    ui->replaceLineEdit->installEventFilter(this);

}

TextFinder::~TextFinder()
{
    delete ui;
}

/*!
 * \fn TextFinder* TextFinder::openFindAndReplace(QWidget *parent)
 * \brief The function checks if the window is already open else opens a new one
 */
TextFinder* TextFinder::openFindAndReplace(QWidget *parent) {
    if (textFinder) {
        return textFinder;
    }

    textFinder = new TextFinder(parent);
    return textFinder;
}

/*!
 * \fn TextFinder* TextFinder::openFindAndReplace(QWidget *parent)
 * \brief Moves the cursor to the next identified text
 *  which the user entered to search
 */
void TextFinder::on_findNextButton_clicked()
{
    QString searchString = ui->findLineEdit->text();
    QTextBrowser *curr_browser = ((MainWindow *)(parent()))->getCurrentBrowser();   //getCurrentBrowser() returns the current QTextBrower
    if (!curr_browser) {
        return;
    }
    if(!curr_browser->find(searchString, QTextDocument::FindFlags()))
    {
        curr_browser->moveCursor(QTextCursor::Start);                              //Moves the cursor to start of text
        curr_browser->find(searchString, QTextDocument::FindFlags());
    }
}

/*!
 * \fn void TextFinder::on_findPreviousButton_clicked()
 * \brief Moves the cursor to the previously identified
 * text which the user entered to search
 */
void TextFinder::on_findPreviousButton_clicked()
{
    QString searchString = ui->findLineEdit->text();
    QTextBrowser *curr_browser = ((MainWindow *)(parent()))->getCurrentBrowser();
    if (!curr_browser) {
        return;
    }
    if(!curr_browser->find(searchString, QTextDocument::FindBackward))
    {
        curr_browser->moveCursor(QTextCursor::End);                               //Moves the cursor to the end of text
        curr_browser->find(searchString, QTextDocument::FindBackward);
    }
}

/*!
 * \fn void TextFinder::on_replaceButton_clicked()
 * \brief Replaces the current text under cursor
 * with a new user entered text
 */
void TextFinder::on_replaceButton_clicked()
{
    QString searchString = ui->findLineEdit->text();
    QString replaceString = ui->replaceLineEdit->text();
    QTextBrowser *curr_browser = ((MainWindow *)(parent()))->getCurrentBrowser();
    if (!curr_browser || curr_browser->isReadOnly()) {
        return;
    }
    QTextCursor cursor = curr_browser->textCursor();
    if(cursor.hasSelection())
    {
        if(cursor.selectedText() == searchString)
            cursor.insertText(replaceString);
    }
}

/*!
 * \fn void TextFinder::on_replaceAllButton_clicked()
 * \brief Replaces all the found text with a new user entered text
 */
void TextFinder::on_replaceAllButton_clicked()
{
    QString searchString = ui->findLineEdit->text();
    QString replaceString = ui->replaceLineEdit->text();
    QTextBrowser *curr_browser = ((MainWindow *)(parent()))->getCurrentBrowser();
    if (!curr_browser || curr_browser->isReadOnly()) {
        return;
    }
    QTextCursor saved_cursor = curr_browser->textCursor();
    curr_browser->moveCursor(QTextCursor::Start);
    while(curr_browser->find(searchString))
    {
        curr_browser->textCursor().insertText(replaceString);
    }
    curr_browser->setTextCursor(saved_cursor);               //Moves the cursor to the last text location placed by the user
}

/*!
 * \fn void TextFinder::keyPressEvent(QKeyEvent *e)
 * \brief The function translates the user entered text on the
 * textedit to Devanagari language when Ctrl+D is pressed
 * \sa toDevanagari()
 */
void TextFinder::keyPressEvent(QKeyEvent *e)
{
    if ( (e->key() == Qt::Key_D)  && QApplication::keyboardModifiers() == Qt::ControlModifier)
    {
       QString convertedText;
       string selectedStr;
       if(ui->findLineEdit->hasFocus()) {
           selectedStr = ui->findLineEdit->text().toUtf8().constData();
           convertedText = toDevanagari(selectedStr);
           ui->findLineEdit->setText(convertedText);
       }
       if(ui->replaceLineEdit->hasFocus()) {
           selectedStr = ui->replaceLineEdit->text().toUtf8().constData();
           convertedText = toDevanagari(selectedStr);
           ui->replaceLineEdit->setText(convertedText);
       }
    }
}

/*!
 * \fn QString TextFinder::toDevanagari(string text)
 * \brief The function assess the user entered text language
 * and converts the string of text into devanagari
 */
QString TextFinder::toDevanagari(string text) {
    return QString::fromStdString(toDev(toslp1(text)));
}

/*!
 * \brief Filters the user key events and raises handlers if
 * ' ctrl + D' is pressed.
 * \return QDialog::eventFilter(watched, event)
 *
 * \sa keyPressEvent()
 */
bool TextFinder::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::ShortcutOverride) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->modifiers().testFlag(Qt::ControlModifier) && keyEvent->key() == 'D') {
            keyPressEvent(keyEvent);
            event->ignore();
            return true;
        }
    }
    return QDialog::eventFilter(watched, event);
}
