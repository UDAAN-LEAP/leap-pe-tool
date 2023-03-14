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


/*!
 * \fn CustomTextBrowser::CustomTextBrowser
 * \brief This class is used for creating a custom QTextBrowser which supports auto-completion
 * \details Auto-completion suggestions are being shown on the basis of the words stored in the specific language file. It matches by taking the first 3 letters of the words and then gives suggestions whose prefix matches.
 * \param QWidget *parent
 */
CustomTextBrowser::CustomTextBrowser(QWidget *parent): QTextBrowser(parent)
{
    this->setReadOnly(false);
    c = new QCompleter((CustomTextBrowser *)this);
    this->setCompleter(c);
    this->setPlaceholderText("How to Open a Project:\n"
                                        "―――――――――――――――――――――――――――――――――――――\n"
                                        "If your project is in a zip folder:\n"
                                        "  ⚫ Extract the project to a location of your choice,\n"
                                        "  ⚫ File > Open Project ('Ctrl + o'),\n"
                                        "  ⚫ Browse to the location where you extracted your project, and select it,\n"
                                        "  ⚫ Click 'Open'.\n"
                                        "If you want to download a project:\n"
                                        "  ⚫ File > Import Project > Import.\n"
                                        "If you want to download & open a project:\n"
                                        "  ⚫ File > Import Project > Import and Open.\n"
                                        "User dashboard: Enter project ID, click 'Import Project' button, browse and select location to import project.\n"
                                        "To open a recent project:\n"
                                        "  ⚫ File > Recent Project,\n"
                                        "  ⚫ Select the project you want to open from the list of recent projects.\n"
                                        "For detailed instructions, you can refer to the User Guide under the 'Help' menu.");

    if(modelFlag == 0){
        engModel = modelFromFile(":/WordList/wordlists/english.txt");
        devModel = modelFromFile(":/WordList/wordlists/sanskrit.txt");
        modelFlag = 1;
    }

    // Setup grip band
    m_gripBand = new RubberBand(this);
    m_gripBand->setMoveEnabled(false);
    m_gripBand->setVisible(false);

    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(updateGripBand()));
    connect(this, SIGNAL(textChanged()), this, SLOT(updateGripBand()));
    connect(this, SIGNAL(currentCharFormatChanged(const QTextCharFormat&)), this, SLOT(updateGripBand()));
    connect(horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(updateGripBand()));
    connect(verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(updateGripBand()));
    connect(m_gripBand, SIGNAL(resizeFinished(QRect)), this, SLOT(resizeObject(QRect)));
}

/*!
 * \fn CustomTextBrowser::~CustomTextBrowser/
 * \brief Destructor
 */
CustomTextBrowser::~CustomTextBrowser()
{
}

/*!
 * \fn CustomTextBrowser::setCompleter
 * \brief This function sets the completer passed into it and connects the SIGNAL(activated) to the SLOT(insertCompletion).
 * \param completer
 */
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

/*!
 * \fn CustomTextBrowser::completer
 * \brief This function returns the pointer to the QCompleter which was set earlier
 * \return QCompleter *completer
 */
QCompleter *CustomTextBrowser::completer() const
{
    return c;
}

/*!
 * \fn CustomTextBrowser::modelFromFile
 * \brief This function takes a filename and reads the data line by line and adds it to an array which it stores in the QStringListModel and returns this model.
 * \param fileName
 * \return QAbstractItemModel *model
 */
QAbstractItemModel *CustomTextBrowser::modelFromFile(const QString& fileName)
{
	QFile file(fileName);
	if (!file.open(QFile::ReadOnly)){

		qDebug()<<"File not opened...";
        return new QStringListModel(nullptr);
	}
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

/*!
 * \fn CustomTextBrowser::insertCompletion
 * \brief This function inserts the top-most suggestion in the browser
 * \param completion
 */
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

/*!
 * \fn CustomTextBrowser::updateGripBand
 * \brief This function updates the geometry of rubber band
 * whenever a signal like cursorPositionChanged or value of horizontal and vertical scroll bars is emitted.
 */
void CustomTextBrowser::updateGripBand()
{
    QTextCursor cursor = textCursor();
    m_gripBand->setVisible(!cursor.hasSelection() && cursor.charFormat().isImageFormat());

    if (!cursor.hasSelection() && cursor.charFormat().isImageFormat()) {
        QTextImageFormat fmt = cursor.charFormat().toImageFormat();

        if (!cursor.atBlockStart())
            cursor.movePosition(QTextCursor::Left);

        QRect rc = cursorRect(cursor);
        rc.setLeft(rc.left() + 1);
        rc.setTop(rc.top() + 1);
        rc.setWidth(fmt.width());
        rc.setHeight(rc.height() + 1);

        if (!rc.width()) {
            QImage image = document()->resource(QTextDocument::ImageResource, fmt.name()).value<QImage>();
            rc.setWidth(image.width());
        }

        m_gripBand->setGeometry(rc);
    }
}

/*!
 * \fn CustomTextBrowser::resizeObject
 * \brief Resizes the image to the geometry of rubber band after the mouse button is released.
 * \param rect Used for resizing the image object to the geometry of this rect
 */
void CustomTextBrowser::resizeObject(const QRect &rect)
{
    QTextCursor cursor = textCursor();

    if (cursor.charFormat().isImageFormat()) {
        QTextImageFormat fmt = cursor.charFormat().toImageFormat();
        fmt.setWidth(rect.width());
        fmt.setHeight(rect.height());
        cursor.setCharFormat(fmt);

        QTextCursor temp = cursor;

        if (!temp.atBlockStart()) {
            temp.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor);
        } else {
            temp.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor);
        }

        setTextCursor(temp);
        setCurrentCharFormat(fmt);
        setTextCursor(cursor);
    }
}

/*!
 * \fn CustomTextBrowser::textUnderCursor
 * \brief This function returns the word under the cursor.
 * \return QString textUnderCursor
 */
QString CustomTextBrowser::textUnderCursor() const
{
    QTextCursor tc = textCursor();
    tc.select(QTextCursor::WordUnderCursor);
    return tc.selectedText();
}

/*!
 * \fn CustomTextBrowser::focusInEvent
 * \brief This function is responsible for making the text browser receive keyboard focus events.
 * \param QFocusEvent *e
 */
void CustomTextBrowser::focusInEvent(QFocusEvent *e)
{
    if (c)
        c->setWidget(this);
    QTextBrowser::focusInEvent(e);
}

/*!
 * \fn CustomTextBrowser::resizeEvent
 * \brief Updates the rubber band whenever geometry of this browser is altered.
 * \param event QResizeEvent is used for passing it to QTextBrowser but not used for updating rubber band.
 */
void CustomTextBrowser::resizeEvent(QResizeEvent *event)
{
    updateGripBand();

    QTextBrowser::resizeEvent(event);
}

/*!
 * \fn CustomTextBrowser::keyPressEvent
 * \brief The function is written to ignore key events like Qt::Key_Enter, Qt::Key_Return, Qt::Key_Escape, Qt::Key_Tab, and Qt::Key_Backtab so the completer can handle them. If there is an active completer, we cannot process the shortcut, Ctrl+E. e also handle other modifiers and shortcuts for which we do not want the completer to respond to.
 * \param QKeyEvent *e
 */
void CustomTextBrowser::keyPressEvent(QKeyEvent *e)
{
    if (c && c->popup()->isVisible()) {
        // The following keys are forwarded by the completer to the widget
       switch (e->key()) {
       case Qt::Key_Enter:
       case Qt::Key_Return:
       case Qt::Key_Escape:
       case Qt::Key_Tab:
       case Qt::Key_Backtab:
       {
           e->ignore();
           return;
       }
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

    string str = completionPrefix.toStdString();
    slpNPatternDict justForCheck ;
    int  x = 0;
    x = (str == justForCheck.toDev(str));
    if(e->key()==Qt::Key_Tab || e->key()== Qt::Key_Enter || e->key()== Qt::Key_Space) x = 0;

    else if(x)
    {
        x=1;
        c->setModel(devModel);
        c->setModelSorting(QCompleter::CaseInsensitivelySortedModel);
    }
    else
    {
        x=1;
        c->setModel(engModel);
        c->setModelSorting(QCompleter::CaseInsensitivelySortedModel);
        c->setCaseSensitivity(Qt::CaseInsensitive);
    }

    if (completionPrefix != c->completionPrefix()) {
        c->setCompletionPrefix(completionPrefix);
        c->popup()->setCurrentIndex(c->completionModel()->index(0, 0));
    }
    QRect cr = cursorRect();
    cr.setWidth(c->popup()->sizeHintForColumn(0)
                + c->popup()->verticalScrollBar()->sizeHint().width());
    c->complete(cr); // popup it up!
}
