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
//        curr_browser->moveCursor(QTextCursor::Start);                              //Moves the cursor to start of text
//        curr_browser->find(searchExpr, QTextDocument::FindFlags());
        ((MainWindow *)(parent()))->on_actionLoad_Next_Page_triggered();
        curr_browser = ((MainWindow *)(parent()))->getCurrentBrowser();
        curr_browser->moveCursor(QTextCursor::Start);
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
       // curr_browser->find(searchExpr, QTextDocument::FindBackward);
        ((MainWindow *)(parent()))->on_actionLoad_Prev_Page_triggered();
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
               //input = browser->toPlainText();
               //input.replace(findWord, replacementString1);

               while(browser->find(findWord))
               {

                     browser->textCursor().insertHtml("<span style = \"background-color:#ADD8E6;\">" +replacementString1+ "</span>");

               }
               //////////////////////////////////
               /*QString fileTmp = gDirTwoLevelUp + "/globalReplace1.txt";
               QFile f5(fileTmp);

               istringstream iss(input.toUtf8().constData());
               string strHtml = "<html><body><p>";
               string line;

               f5.open(QIODevice::WriteOnly);
               QTextStream in5(&f5);
               in5.setCodec("UTF-8");

               int index = 0;
               in5 << "<html><body><p>";
               while(index < input.size()) {
                   QChar s = input.at(index);
                   if((s == "\n") || (s == "\r")){
                       in5 << s;    //for html view
                       in5 <<  "</p><p>";
                   }
                   else
                       in5 <<  s;
                   index++;
               }
               in5 << "</p></body></html>";
               f5.flush();
               f5.close();
               f5.open(QIODevice::ReadOnly);
               QTextStream in6(&f5);
               QString qstrHtml = in6.readAll();
               f5.close();
               qstrHtml.replace("<br /></p>", "</p>");

               QFont font("Shobhika-Regular");
               font.setWeight(16);
               font.setPointSize(16);
               font.setFamily("Shobhika");
               browser->setFont(font);
               browser->setHtml(qstrHtml);*/
               s1 = browser->toHtml();
               //s1.replace(replacementString1,"<span style = \"background-color:#ADD8E6;\">"+replacementString1+"</span>");
               /////////////////////////////////////////////////////////////////////////////
               f->open(QIODevice::WriteOnly);
               //s1.replace(findWord, replacementString1);
               f->write(s1.toUtf8());
               f->close();
               //grw.filterHtml(it_file_path); //filter html file
               grw.bboxInsertion(it_file_path); //insert back bbox info
            }
      }

//      string localFilename = mFilename.toUtf8().constData();
//      QFile *file = new QFile(QString::fromStdString(localFilename));
//      QFileInfo f(*file);
//      QString suff = f.completeSuffix();
//      if (suff == "txt" || suff == "html") {
//       ((MainWindow *)(parent()))->LoadDocument(file,suff,currentTabPageName );
//      }

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
 * \fn QString TextFinder::toDevanagari(string text)
 * \brief The function assess the user entered text language
 * and converts the string of text into devanagari
 */
QString TextFinder::toDevanagari(string text) {
    slpNPatternDict slnp;
    return QString::fromStdString(slnp.toDev(slnp.toslp1(text)));
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
