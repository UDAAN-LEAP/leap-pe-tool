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
#include "slpNPatternDict.h"
#include <QString>
#include <string>
#include <QMessageBox>
#include <globalreplaceworker.h>

using namespace std;
extern string toslp1(string s);
extern string toDev(string s);
extern QString gDirOneLevelUp,gDirTwoLevelUp,gCurrentPageName, gCurrentDirName;

/*! \class TextFinder
 * \fn TextFinder::TextFinder
 * \brief This Class is used to find and replace the text in text view
 * \param QWidget->parent
 * \param QDialog->(parent, Qt::WindowCloseButtonHint),
 * \param ui(new Ui::TextFinder)
 * \details
 * 1) Sets up the user interface for the specified widget.
 * 2)Sets both the minimum and maximum sizes of the widget,
 *  thereby preventing it from ever growing or shrinking.
 * 3)Installs an event filter filterObj on "this" object(findLineEdit,replaceLineEdit)
 */
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

/*!
 * \fn TextFinder::~TextFinder
 * \brief Destructor
 */
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
    QString searchstr = ui->findLineEdit->text();
    QRegExp searchExpr = QRegExp(ui->findLineEdit->text());
    QTextBrowser *curr_browser = ((MainWindow *)(parent()))->getCurrentBrowser();   //getCurrentBrowser() returns the current QTextBrower
    if (ui->matchCaseCheckBox->checkState() == Qt::Checked)
        searchExpr.setCaseSensitivity(Qt::CaseSensitive);
    else
        searchExpr.setCaseSensitivity(Qt::CaseInsensitive);

    if (!curr_browser) {
        return;
    }

    if(!curr_browser->find(searchExpr, QTextDocument::FindFlags()))
    {
        QString currentFileDirectory = gDirTwoLevelUp + "/" + gCurrentDirName;
        QDir dir(currentFileDirectory);
        QStringList nameFilter;
        nameFilter << "*.html";
        QFileInfoList list = dir.entryInfoList(nameFilter, QDir::NoDotAndDotDot | QDir::Files);
        QString path;
        QFileInfo fileInfo;
        QString temp1 = currentFileDirectory + "/" + gCurrentPageName;
        int index = list.indexOf(temp1,0);
        qDebug()<<index;
        int i;
        i = (index == (list.count()-1)) ? 0 : index+1 ;
        for (i ; i < list.size(); ++i)
        {
            fileInfo = list.at(i);
            path = fileInfo.filePath();

            if(stringCheck(path,searchstr)){
                gCurrentPageName = fileInfo.fileName();
                break;
            }
        }
        QString suff = fileInfo.completeSuffix();
        QFile *f = new QFile(path);
        QString filename(fileInfo.fileName());
        ((MainWindow *)(parent()))->LoadDocument(f,suff,filename);
        curr_browser = ((MainWindow *)(parent()))->getCurrentBrowser();
        curr_browser->moveCursor(QTextCursor::Start);                        //Moves the cursor to the end of text
        curr_browser->find(searchExpr, QTextDocument::FindFlags());

    }
}

/*!
 * \fn void TextFinder::on_findPreviousButton_clicked()
 * \brief Moves the cursor to the previously identified
 * text which the user entered to search
 */
void TextFinder::on_findPreviousButton_clicked()
{
    QString searchstr = ui->findLineEdit->text();
    QRegExp searchExpr = QRegExp(ui->findLineEdit->text());
    QTextBrowser *curr_browser = ((MainWindow *)(parent()))->getCurrentBrowser();
    if (ui->matchCaseCheckBox->checkState() == Qt::Checked)
        searchExpr.setCaseSensitivity(Qt::CaseSensitive);
    else
        searchExpr.setCaseSensitivity(Qt::CaseInsensitive);

    if (!curr_browser) {
        return;
    }
    if(!curr_browser->find(searchExpr, QTextDocument::FindBackward))
    {
        QString currentFileDirectory = gDirTwoLevelUp + "/" + gCurrentDirName;
        QDir dir(currentFileDirectory);
        QStringList nameFilter;
        nameFilter << "*.html";
        QFileInfoList list = dir.entryInfoList(nameFilter, QDir::NoDotAndDotDot | QDir::Files);
        QString path;
        QFileInfo fileInfo;
        QString temp1 = currentFileDirectory + "/" + gCurrentPageName;
        int index = list.indexOf(temp1,0);
        int i;
        i = (index == 0) ? (list.count()-1) : index-1 ;

        for (i ; i >= 0; --i)
        {
            fileInfo = list.at(i);
            path = fileInfo.filePath();
            if(stringCheck(path,searchstr)){
                gCurrentPageName = fileInfo.fileName();
                break;
            }
        }
        QString suff = fileInfo.completeSuffix();
        QFile *f = new QFile(path);
        QString filename(fileInfo.fileName());
        ((MainWindow *)(parent()))->LoadDocument(f,suff,filename);
        curr_browser = ((MainWindow *)(parent()))->getCurrentBrowser();
        curr_browser->moveCursor(QTextCursor::End);                        //Moves the cursor to the end of text
        curr_browser->find(searchExpr, QTextDocument::FindBackward);
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
    QTextCharFormat format = cursor.charFormat();
    format.setBackground(QColor("#ADD8E6"));
    if(cursor.hasSelection())
    {
        if(ui->matchCaseCheckBox->checkState() == Qt::Checked && cursor.selectedText() == searchString)
            cursor.insertText(replaceString,format);
        else if (ui->matchCaseCheckBox->checkState() == Qt::Unchecked && cursor.selectedText().toLower() == searchString.toLower())
            cursor.insertText(replaceString,format);
    }
}

/*!
 * \fn void TextFinder::on_replaceAllButton_clicked()
 * \brief Replaces all the found text with a new user entered text
 */
void TextFinder::on_replaceAllButton_clicked()
{
    QString temp1 =  "(\\b)" +ui->findLineEdit->text() + "(\\b)";
    QRegExp searchExpr(temp1);
    QString replaceString = ui->replaceLineEdit->text();
    QTextBrowser *curr_browser = ((MainWindow *)(parent()))->getCurrentBrowser();
    if (ui->matchCaseCheckBox->checkState() == Qt::Checked)
        searchExpr.setCaseSensitivity(Qt::CaseSensitive);
    else
        searchExpr.setCaseSensitivity(Qt::CaseInsensitive);
    if (!curr_browser || curr_browser->isReadOnly()) {
        return;
    }

    //! Replace in All Pages
   if(ui->ReplaceAllPages->checkState()== Qt::Checked)
   {
      if(replaceString=="")
      {
          QMessageBox infoBox;
          infoBox.information(0, "Error","Choose a replacement word to replace");
          return;
      }
      QString currentFileDirectory = gDirTwoLevelUp + "/" + gCurrentDirName;
      QDirIterator dirIterator(currentFileDirectory, QDirIterator::Subdirectories);

      //!Get all the file names by iterating the directory
      while (dirIterator.hasNext())
      {
          QString it_file_path = dirIterator.next();
          QString suff = dirIterator.fileInfo().completeSuffix();

          if(suff == "html")
            {
              //!Get the file string
               GlobalReplaceWorker grw;
               grw.saveBboxInfo(it_file_path); //to save bbox information
               QFile *f = new QFile(it_file_path);
               f->open(QIODevice::ReadOnly);
               QTextStream in(f);
               in.setCodec("UTF-8");
               QString s1 = in.readAll();
               f->close();

               //!Replacing Words
               string str = replaceString.toStdString();
               QString::fromStdString(str).toUtf8();
               //QString replacementString1 = "<span style = \"background-color:#ADD8E6;\">" + QString::fromStdString(str) + "</span>";
               QString replacementString1 =QString::fromStdString(str);
               string str2 = ui->findLineEdit->text().toStdString();
               QString::fromStdString(str2).toUtf8();
               QString temp2 = "(\\b)" + ui->findLineEdit->text() + "(\\b)";
               QRegExp findWord(temp2);

               if (ui->matchCaseCheckBox->checkState() == Qt::Checked)
                   findWord.setCaseSensitivity(Qt::CaseSensitive);
               else
                   findWord.setCaseSensitivity(Qt::CaseInsensitive);
               //replace words on text instead of html files

               QTextBrowser * browser = new QTextBrowser();
               browser->setReadOnly(false);
               QFont font("Shobhika-Regular");
               font.setWeight(16);
               font.setPointSize(16);
               font.setFamily("Shobhika");
               browser->setFont(font);
               browser->setHtml(s1);

               while(browser->find(findWord))
               {
                   QTextCursor cursor = browser->textCursor(); //get the cursor
                   QTextCharFormat fmt;
                   int pos = cursor.position(); //get the cursor position
                   int ancr = pos - replaceString.size() + 1; //anchor is now cursor position - length of old word to be replaced
                   if (pos < ancr) {
                       cursor.setPosition(pos, QTextCursor::MoveAnchor);
                       cursor.setPosition(ancr, QTextCursor::KeepAnchor);
                   }
                   fmt = cursor.charFormat(); //get the QTextCharFormat of old word/phrase to be replaced

                   browser->textCursor().insertHtml("<span style = \"background-color:#ADD8E6;\">" +replacementString1+ "</span>");

                   cursor = browser->textCursor(); //get new cursor position after old word is replaced by new one

                   pos = cursor.position();
                   ancr = pos - replacementString1.size();//anchor is cursor position - new word/phrase length
                   cursor.setPosition(pos, QTextCursor::MoveAnchor);
                   cursor.setPosition(ancr, QTextCursor::KeepAnchor);
                   cursor.mergeCharFormat(fmt); //apply the text properties captured earlier

               }
               s1 = browser->toHtml();
               f->open(QIODevice::WriteOnly);
               f->write(s1.toUtf8());
               f->close();
               grw.bboxInsertion(it_file_path); //insert back bbox info
            }
      }
      ((MainWindow *)(parent()))->reLoadTabWindow();
      //!Display message
      QMessageBox messageBox;
      messageBox.information(0, "Replacement Successful","Replaced in All Pages.");
   }
   else{
       QTextCursor saved_cursor = curr_browser->textCursor();
       curr_browser->moveCursor(QTextCursor::Start);
       QTextCharFormat format = saved_cursor.charFormat();
       format.setBackground(QColor("#ADD8E6"));
       while(curr_browser->find(searchExpr))
       {
           curr_browser->textCursor().insertText(replaceString,format);
       }
       curr_browser->setTextCursor(saved_cursor);               //Moves the cursor to the last text location placed by the user
   }
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
 * \fn TextFinder::toDevanagari
 * \brief The function assess the user entered text language
 * and converts the string of text into devanagari
 */
QString TextFinder::toDevanagari(string text) {
    slpNPatternDict slnp;
    return QString::fromStdString(slnp.toDev(slnp.toslp1(text)));
}

/*!
 * \fn TextFinder::eventFilter
 * \brief Filters the user key events and raises handlers if
 * ' ctrl + D' is pressed.
 * \return QDialog::eventFilter(watched, event)
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

/*!
 * \fn TextFinder::stringCheck
 * \param QString->path
 * \param QString searchstr
 * \details
 * 1)Saves file path as string
 * 2)Opens the File in readOnly mode
 * 3)Sets the codec for this stream to codec("UTF-8")
 * 4)Reads the entire content of the stream, and returns it as a QString.
 * 5)closes the file
 * 6)If string contains the specifics, function returns true else false
 */
bool TextFinder::stringCheck(QString path, QString searchstr)
{
    QFile *f = new QFile(path);
    f->open(QIODevice::ReadOnly);
    QTextStream in(f);
    in.setCodec("UTF-8");
    QString s1 = in.readAll();
    f->close();
    if(s1.contains(searchstr))      //checks wheather the string is found or not
    {
        return true;
    }
    else
    {
        return false;
    }
}
