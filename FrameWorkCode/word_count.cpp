#include "word_count.h"
#include "customtextbrowser.h"
#include<QtCore>
#include<QDir>
#include<QDirIterator>
#include<QTextStream>
#include<QRegExp>


word_count::word_count(CustomTextBrowser * curr_browser, QString mRole, QString gDirTwoLevelUp)
{
    this->curr_browser = curr_browser;
    this->mRole = mRole;
    this->gDirTwoLevelUp = gDirTwoLevelUp;
}

void word_count::run_wordCount()
{
    if(curr_browser){
        QString extText = curr_browser->toPlainText();
        //!Removes these symbol while counting
        extText.remove("?");
        extText.remove("|");
        extText.remove("`");
        extText.remove("[");
        extText.remove("]");
        extText.remove("'");
        extText.remove(",");

        int wordcnt = extText.split(QRegExp("(\\s|\\n|\\r)+"), QString::SkipEmptyParts).count();

        //QString str = QString::number(wordcnt);
        emit word_Count(wordcnt);

        QString currentDirAbsolutePath;
        if(mRole=="Verifier")
            currentDirAbsolutePath = gDirTwoLevelUp + "/VerifierOutput/";
        else if (mRole=="Corrector") {
            currentDirAbsolutePath = gDirTwoLevelUp + "/CorrectorOutput/";
        }


        //! We then open this directory and set sorting preferences.
        QDir dir(currentDirAbsolutePath);
        dir.setSorting(QDir::SortFlag::DirsFirst | QDir::SortFlag::Name);
        QDirIterator dirIterator(dir,QDirIterator::NoIteratorFlags);
        qDebug()<<dir;
        //! Set count of files in directory

        int count = dir.entryList(QStringList("*.html"), QDir::Files | QDir::NoDotAndDotDot).count();

        //QString str1 = QString::number(count);
        emit page_Count(count);

        int t_words=0;
        foreach(auto a, dir.entryList())
        {
            QString x = currentDirAbsolutePath + a;
            QString mainHtml;
            int count=0;
            if(x.contains("."))
            {
                QStringList html_files = x.split(QRegExp("[.]"));
                if(html_files[1]=="html")
                {
                    QFile file(x);
                    if (!file.open(QIODevice::ReadOnly))
                        qDebug() << "Error reading file main.html";
                    QTextStream stream(&file);
                    stream.setCodec("UTF-8");
                    mainHtml=stream.readAll();
                    QRegularExpression rex_dollar("(?<=\\$\\$)(.*?)(?=\\$\\$)",QRegularExpression::DotMatchesEverythingOption);

                    auto itr = rex_dollar.globalMatch(mainHtml);
                    QTextDocument doc;
                    doc.setHtml(mainHtml);
                    QString s1 = doc.toPlainText();

                    while(itr.hasNext())
                    {
                        count++;
                        itr.next();
                    }
                    s1.remove("?");
                    s1.remove("|");
                    s1.remove("`");
                    s1.remove("[");
                    s1.remove("]");
                    s1.remove("'");
                    s1.remove(",");
                    s1.remove(rex_dollar);

                    int wordcnt = s1.split(QRegExp("(\\s|\\n|\\r)+"), QString::SkipEmptyParts).count();
                    wordcnt += (count-1)/2;
                    t_words += wordcnt;

                }
            }
        }

        //QString str3 = QString::number(t_words);
        emit total_Words(t_words);
        emit done();
    }
}
