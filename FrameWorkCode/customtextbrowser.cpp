#include "customtextbrowser.h"

#include <QCompleter>
#include <QKeyEvent>
#include <QAbstractItemView>
#include <QtDebug>
#include <QApplication>
#include <QModelIndex>
#include <QAbstractItemModel>
#include <QStringListModel>
#include <QScrollBar>
CustomTextBrowser::CustomTextBrowser(QWidget *parent): QTextBrowser(parent)
{

    this->setReadOnly(false);
    c = new QCompleter((CustomTextBrowser *)this);
    //c->setModel(modelFromFile(":/WordList/wordlists/english.txt"));
    //c->setModelSorting(QCompleter::CaseInsensitivelySortedModel);
    //c->setCaseSensitivity(Qt::CaseInsensitive);
	this->setCompleter(c);

    QAbstractItemModel *temp;
    engModel = modelFromFile(":/WordList/wordlists/english.txt") ;
    devModel = modelFromFile(":/WordList/wordlists/sanskrit.txt") ;
}

CustomTextBrowser::~CustomTextBrowser()
{
}

void CustomTextBrowser::setCompleter(QCompleter *completer)
{
    if (c)
        c->disconnect(this);

    c = completer;

    if (!c)
        return;

    c->setWidget(this);
    c->setCompletionMode(QCompleter::PopupCompletion);
    c->setCaseSensitivity(Qt::CaseInsensitive);
    QObject::connect(c, QOverload<const QString &>::of(&QCompleter::activated),
                     this, &CustomTextBrowser::insertCompletion);
}
//! [2]

//! [3]
QCompleter *CustomTextBrowser::completer() const
{
    return c;
}

QAbstractItemModel *CustomTextBrowser::modelFromFile(const QString& fileName)
{
	QFile file(fileName);
	if (!file.open(QFile::ReadOnly)){

		qDebug()<<"File not opened...";
        return new QStringListModel(nullptr);
	}
qDebug()<<"File opened...";
#ifndef QT_NO_CURSOR
	QGuiApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
#endif
	QStringList words;

	while (!file.atEnd()) {
		QByteArray line = file.readLine();
		if (!line.isEmpty())
			words << QString::fromUtf8(line.trimmed());
	}

#ifndef QT_NO_CURSOR
	QGuiApplication::restoreOverrideCursor();
#endif
    return new QStringListModel(words, nullptr);
}

void CustomTextBrowser::insertCompletion(const QString &completion)
{
    if (c->widget() != this)
        return;
    QTextCursor tc = textCursor();
    int extra = completion.length() - c->completionPrefix().length();
    tc.movePosition(QTextCursor::Left);
    tc.movePosition(QTextCursor::EndOfWord);
    tc.insertText(completion.right(extra));
    setTextCursor(tc);
}

QString CustomTextBrowser::textUnderCursor() const
{
    QTextCursor tc = textCursor();
    tc.select(QTextCursor::WordUnderCursor);
    return tc.selectedText();
}

void CustomTextBrowser::focusInEvent(QFocusEvent *e)
{
    if (c)
        c->setWidget(this);
    QTextBrowser::focusInEvent(e);
}

void CustomTextBrowser::keyPressEvent(QKeyEvent *e)
{
    qDebug()<<"textBrowser poped up...";

    if (c && c->popup()->isVisible()) {
        // The following keys are forwarded by the completer to the widget
       switch (e->key()) {
       case Qt::Key_Enter:
       case Qt::Key_Return:
       case Qt::Key_Escape:
       case Qt::Key_Tab:
       case Qt::Key_Backtab:
            e->ignore();
            return;
            // let the completer do default behavior
       case Qt::Key_Space:

       default:
           break;
       }
    }

    const bool isShortcut = (e->modifiers().testFlag(Qt::ControlModifier) && e->key() == Qt::Key_E); // CTRL+E
    if (!c || !isShortcut) // do not process the shortcut when we have a completer
        QTextBrowser::keyPressEvent(e);

    const bool ctrlOrShift = e->modifiers().testFlag(Qt::ControlModifier) ||
                             e->modifiers().testFlag(Qt::ShiftModifier);
    if (!c || (ctrlOrShift && e->text().isEmpty()))
        return;

    static QString eow("~!@#$%^&*()_+{}|:\"<>?,./;'[]\\-="); // end of word
    const bool hasModifier = (e->modifiers() != Qt::NoModifier) && !ctrlOrShift;
    QString completionPrefix = textUnderCursor();



    if ((hasModifier || e->text().isEmpty()|| completionPrefix.length() < 3
                      || eow.contains(e->text().right(1)))) {
        c->popup()->hide();
        return;
    }





    //.............................
    string str = completionPrefix.toStdString();


    slpNPatternDict justForCheck ;

    int  x= 0;


     x = (str==justForCheck.toDev(str));


    if(e->key()==Qt::Key_Tab || e->key()== Qt::Key_Enter || e->key()== Qt::Key_Space) x=0;


    else if(x)
    {
        x=1;
        c->setModel(devModel);
        c->setModelSorting(QCompleter::CaseInsensitivelySortedModel);
        //c->setCaseSensitivity(Qt::CaseInsensitive);
        //this->setCompleter(c);
    }
    else
    {
        x=1;
        c->setModel(engModel);
        c->setModelSorting(QCompleter::CaseInsensitivelySortedModel);
        c->setCaseSensitivity(Qt::CaseInsensitive);
        //this->setCompleter(c);
    }
    //.............................


    if (completionPrefix != c->completionPrefix()) {
        c->setCompletionPrefix(completionPrefix);
        c->popup()->setCurrentIndex(c->completionModel()->index(0, 0));
    }
    QRect cr = cursorRect();



    cr.setWidth(c->popup()->sizeHintForColumn(0)
                + c->popup()->verticalScrollBar()->sizeHint().width());
    c->complete(cr); // popup it up!
    qDebug()<<"textBrowser last poped up...";
}


//QAbstractItemModel *CustomTextBrowser::modelFromFile(const QString& fileName)
//{
//    QFile file(fileName);
//    if (!file.open(QFile::ReadOnly))
//    {
//        qDebug()<<"File not opened...";
//        return new QStringListModel(c);
//    }
//qDebug()<<"File opened...";
//#ifndef QT_NO_CURSOR
//    QGuiApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
//#endif
//    QStringList words;

//    while (!file.atEnd()) {
//        QByteArray line = file.readLine();
//        if (!line.isEmpty())
//            words << QString::fromUtf8(line.trimmed());
//    }

//#ifndef QT_NO_CURSOR
//    QGuiApplication::restoreOverrideCursor();
//#endif
//    return new QStringListModel(words, c);
//}
