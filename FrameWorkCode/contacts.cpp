#include "contacts.h"
#include "ui_contacts.h"

ContactUsDialog::ContactUsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactUsDialog)
{
    ui->setupUi(this);

    ui->textBrowser->setOpenExternalLinks(true);
     ui->textBrowser->setMarkdown(this->list);
    ui->textBrowser->setStyleSheet("background-color:#E8E8E8; font-size:14px; font-family:sans; font-weight:0; text-indent:15px; margin-top:3px; font-style:normal; ");

}

/*!
 * \fn ContactUsDialog::~ContactUsDialog
 * \brief Destructor
 */
ContactUsDialog::~ContactUsDialog()
{
    delete ui;
}

