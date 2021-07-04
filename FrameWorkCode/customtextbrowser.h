#ifndef CUSTOMTEXTBROWSER_H
#define CUSTOMTEXTBROWSER_H

#include <QObject>
#include <QWidget>
#include <QTextBrowser>

class customTextBrowser: public QTextBrowser
{
public:
    customTextBrowser();
    bool eventFilter(QObject *, QEvent*);
};

#endif // CUSTOMTEXTBROWSER_H
