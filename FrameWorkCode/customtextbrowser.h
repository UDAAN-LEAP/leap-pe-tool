#ifndef CUSTOMTEXTBROWSER_H
#define CUSTOMTEXTBROWSER_H

#include <QTextBrowser>
#include <QAbstractItemModel>
#include "slpNPatternDict.h"
#include "rubberband.h"

QT_BEGIN_NAMESPACE
class QCompleter;
class QAbstractItemModel;
QT_END_NAMESPACE

//! [0]
class CustomTextBrowser : public QTextBrowser
{
    Q_OBJECT

public:
    CustomTextBrowser(QWidget *parent = nullptr);
    ~CustomTextBrowser();

    void setCompleter(QCompleter *c);
    QCompleter *completer() const;
    QAbstractItemModel *modelFromFile(const QString&);
    static int modelFlag;
    static QAbstractItemModel *engModel ;
    static QAbstractItemModel *devModel ;

protected:
    void keyPressEvent(QKeyEvent *e) override;
    void focusInEvent(QFocusEvent *e) override;
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void insertCompletion(const QString &completion);
    void updateGripBand();
    void resizeObject(const QRect &rect);

private:
    QString textUnderCursor() const;

private:
    QCompleter *c = nullptr;
    RubberBand *m_gripBand;
};
//! [0]

#endif // TEXTEDIT_H
