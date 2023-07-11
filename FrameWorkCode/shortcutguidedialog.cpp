/*!
  \class shortcutguidedialog.cpp
  \brief Shortcut dialog shows a list of all the shortcuts available and
         the action that will occur on applying those shortcuts
 */
#include "shortcutguidedialog.h"
#include "ui_shortcutguidedialog.h"
#include"addkeyshortcut.h"


/*!
 * \fn ShortcutGuideDialog::ShortcutGuideDialog
 * \param parent
 * \brief
 * 1)Sets up the user interface for the specified widget.
 * 2)sets flag to specify how the text should react to user input
*/
ShortcutGuideDialog::ShortcutGuideDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShortcutGuideDialog)
{
    ui->setupUi(this);
//    ui->textBrowser->setMarkdown(this->list);
    ui->textBrowser->setHtml(this->list);
}

/*!
 * \fn ShortcutGuideDialog::~ShortcutGuideDialog
 * \brief Destructor
 */
ShortcutGuideDialog::~ShortcutGuideDialog()
{
    delete ui;
}
