#include "passkey.h"
#include "ui_passkey.h"

PassKey::PassKey(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PassKey)
{
    ui->setupUi(this);
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
}

PassKey::~PassKey()
{
    delete ui;
}

void PassKey::on_pushButton_clicked()
{
    QString passwordString= ui->passwordEdit->text();

    mwindow =new MainWindow(this);

    if(passwordString == "Verifer")
        mwindow->setRole("Verifier");
    if(passwordString == "Corrector")
        mwindow->setRole("Corrector");
    hide();
    mwindow->show();
}
