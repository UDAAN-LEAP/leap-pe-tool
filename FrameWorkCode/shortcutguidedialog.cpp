/*!
  \class shortcutguidedialog.cpp
  \brief Shortcut dialog shows a list of all the shortcuts available and
         the action that will occur on applying those shortcuts
 */
#include "shortcutguidedialog.h"
#include "ui_shortcutguidedialog.h"
/*!
 * \class ShortcutGuideDialog
 * \fn ShortcutGuideDialog::ShortcutGuideDialog
 * \param QWidget->parent
 * \brief
 * 1)Sets up the user interface for the specified widget.
 * 2)sets flag to specify how the text should react to user input
*/
ShortcutGuideDialog::ShortcutGuideDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShortcutGuideDialog)
{
    ui->setupUi(this);
    ui->textBrowser->setTextInteractionFlags(Qt::NoTextInteraction);
}

/*!
 * Destructor: deletes and destroys the object after useage
*/
ShortcutGuideDialog::~ShortcutGuideDialog()
{
    delete ui;
}
