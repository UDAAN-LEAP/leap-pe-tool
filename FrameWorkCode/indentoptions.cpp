#include "indentoptions.h"
#include "ui_indentoptions.h"

indentOptions::indentOptions(QWidget *parent, int* left, int* right) :
    QDialog(parent),
    ui(new Ui::indentOptions)
{
    ui->setupUi(this);
    this->left = left;
    this->right = right;
}

indentOptions::~indentOptions()
{
    delete ui;
}

void indentOptions::closeEvent(QCloseEvent* event)
{

    reject();// Set check_b to true when the dialog is closed
    QDialog::closeEvent(event);
}
void indentOptions::on_buttonBox_accepted()
{

    int l = ui->textEdit_left->toPlainText().toInt();
    int r = ui->textEdit_right->toPlainText().toInt();
    if(l==0 && r==0){
        reject();
        return;
    }

    *left = l;
    *right = r;
    accept();


}


void indentOptions::on_buttonBox_rejected()
{
    reject();
    this->close();
}
