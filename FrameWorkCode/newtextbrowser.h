
#ifndef NEWTEXTBROWSER_H
#define NEWTEXTBROWSER_H

#include <QTextBrowser>
#include<QAbstractItemModel>
#include"slpNPatternDict.h"

QT_BEGIN_NAMESPACE
class QCompleter;
class QAbstractItemModel;
QT_END_NAMESPACE

//! [0]
class newTextBrowser : public QTextBrowser
{
    Q_OBJECT

public:
    newTextBrowser(QWidget *parent = nullptr);
    ~newTextBrowser();

    void setCompleter(QCompleter *c);
    QCompleter *completer() const;
    QAbstractItemModel *modelFromFile(const QString&);
    int modelFlag = 0;
    QAbstractItemModel *engModel ;
    QAbstractItemModel *devModel ;

protected:
    void keyPressEvent(QKeyEvent *e) override;
    void focusInEvent(QFocusEvent *e) override;

private slots:
    void insertCompletion(const QString &completion);

private:
    QString textUnderCursor() const;


private:
    QCompleter *c = nullptr;
};
//! [0]

#endif // TEXTEDIT_H
