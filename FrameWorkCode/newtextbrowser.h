
#ifndef NEWTEXTBROWSER_H
#define NEWTEXTBROWSER_H

#include <QTextBrowser>

QT_BEGIN_NAMESPACE
class QCompleter;
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
