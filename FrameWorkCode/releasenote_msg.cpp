#include "releasenote_msg.h"
#include "ui_releasenote_msg.h"

ReleaseNote_Msg::ReleaseNote_Msg(QWidget *parent, QString msg) :
    QDialog(parent),
    ui(new Ui::ReleaseNote_Msg)
{
    ui->setupUi(this);
    ui->textBrowser->setText(msg);
    setWindowTitle("Release Notes");
    ui->textBrowser->setReadOnly(true);
}

ReleaseNote_Msg::~ReleaseNote_Msg()
{
    delete ui;
}
