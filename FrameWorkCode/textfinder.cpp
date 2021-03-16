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
    QDialog(parent),
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

TextFinder* TextFinder::openFindAndReplace(QWidget *parent) {
    if (textFinder) {
        return textFinder;
    }

    textFinder = new TextFinder(parent);
    return textFinder;
}

void TextFinder::on_findNextButton_clicked()
{
    QString searchString = ui->findLineEdit->text();
    QTextBrowser *curr_browser = ((MainWindow *)(parent()))->getCurrentBrowser();
    if (!curr_browser) {
        return;
    }
    if(!curr_browser->find(searchString, QTextDocument::FindFlags()))
    {
        curr_browser->moveCursor(QTextCursor::Start);
        curr_browser->find(searchString, QTextDocument::FindFlags());
    }
}

void TextFinder::on_findPreviousButton_clicked()
{
    QString searchString = ui->findLineEdit->text();
    QTextBrowser *curr_browser = ((MainWindow *)(parent()))->getCurrentBrowser();
    if (!curr_browser) {
        return;
    }
    if(!curr_browser->find(searchString, QTextDocument::FindBackward))
    {
        curr_browser->moveCursor(QTextCursor::End);
        curr_browser->find(searchString, QTextDocument::FindBackward);
    }
}

void TextFinder::on_replaceButton_clicked()
{
    QString searchString = ui->findLineEdit->text();
    QString replaceString = ui->replaceLineEdit->text();
    QTextBrowser *curr_browser = ((MainWindow *)(parent()))->getCurrentBrowser();
    if (!curr_browser) {
        return;
    }
    QTextCursor cursor = curr_browser->textCursor();
    if(cursor.hasSelection())
    {
        if(cursor.selectedText() == searchString)
            cursor.insertText(replaceString);
    }
}


void TextFinder::on_replaceAllButton_clicked()
{
    QString searchString = ui->findLineEdit->text();
    QString replaceString = ui->replaceLineEdit->text();
    QTextBrowser *curr_browser = ((MainWindow *)(parent()))->getCurrentBrowser();
    if (!curr_browser) {
        return;
    }
    QTextCursor saved_cursor = curr_browser->textCursor();
    curr_browser->moveCursor(QTextCursor::Start);
    while(curr_browser->find(searchString))
    {
        curr_browser->textCursor().insertText(replaceString);
    }
    curr_browser->setTextCursor(saved_cursor);
}

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

QString TextFinder::toDevanagari(string text) {
    return QString::fromStdString(toDev(toslp1(text)));
}

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
