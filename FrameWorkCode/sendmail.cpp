#include "sendmail.h"
#include "ui_sendmail.h"

/*!
 * \class sendMail
 * This class asked user the info required for sending email
*/
sendMail::sendMail(QString * send_to , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sendMail)
{
    ui->setupUi(this);
    this->to = send_to;
}

sendMail::~sendMail()
{
    delete ui;
}


/*!
 * \slot onclicked
 * This will set the info to the pointers
*/
void sendMail::on_send_comment_clicked()
{
    *(this->to) = ui->send_to->text();
    this->close();
}

