#include "sendmail.h"
#include "ui_sendmail.h"

/*!
 * \class sendMail
 * This class asked user the info required for sending email
*/
sendMail::sendMail(QString * send_from ,QString * send_to , QString * password, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sendMail)
{
    ui->setupUi(this);
    this->from = send_from;
    this->to = send_to;
    this->password = password;
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
    *(this->from) = ui->send_from->text();
    *(this->to) = ui->send_to->text();
    *(this->password) = ui->mail_password->text();
    this->close();
}

