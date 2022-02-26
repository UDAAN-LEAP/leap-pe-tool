/*!
  \class shortcutguidedialog.cpp
  \brief Shortcut dialog shows a list of all the shortcuts available and
         the action that will occur on applying those shortcuts
 */
#include "shortcutguidedialog.h"
#include "ui_shortcutguidedialog.h"

ShortcutGuideDialog::ShortcutGuideDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShortcutGuideDialog)
{
    ui->setupUi(this);
    //display guide
//    QPixmap pm(":/Images/ShortcutGuide.jpg");
//    ui->label->setPixmap(pm);
//    ui->label->setScaledContents(true);
//    QScrollArea *scrollarea = new QScrollArea(this);
//    scrollarea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    scrollarea->setBackgroundRole(QPalette :: Dark);
//    scrollarea->setWidget(ui->label);

    //!sets flag to specify how the text should react to user input
    ui->textBrowser->setTextInteractionFlags(Qt::NoTextInteraction);
}

ShortcutGuideDialog::~ShortcutGuideDialog()
{
    delete ui;
}
