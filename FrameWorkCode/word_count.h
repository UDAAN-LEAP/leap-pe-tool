#ifndef WORD_COUNT_H
#define WORD_COUNT_H

#include <QObject>
#include "customtextbrowser.h"

class word_count: public QObject
{
    Q_OBJECT
public:
    word_count(CustomTextBrowser * curr_browser = nullptr, QString mRole = "" , QString gDirTwoLevelUp = "");

public slots:
    void run_wordCount();

private:
    CustomTextBrowser * curr_browser;
    QString mRole ;
    QString gDirTwoLevelUp;

signals:
    void word_Count(int);
    void page_Count(int);
    void total_Words(int);
    void done();
};

#endif // WORD_COUNT_H
