#include "indentoptions.h"
#include "ui_indentoptions.h"

indentOptions::indentOptions(QWidget *parent, int* left, int* right) :
    QDialog(parent),
    ui(new Ui::indentOptions)
{
    ui->setupUi(this);
    this->left = left;
    this->right = right;
    setWindowTitle("Indentation Options");
}

indentOptions::~indentOptions()
{
    delete ui;
}

void indentOptions::closeEvent(QCloseEvent* event)
{
    emit dialogRejected();
    QDialog::closeEvent(event);
}

void indentOptions::on_buttonBox_accepted()
{

    int l = ui->textEdit_left->toPlainText().toInt();
    int r = ui->textEdit_right->toPlainText().toInt();
    if(l==0 && r==0){
        emit dialogRejected();
        return;
    }

    *left = l;
    *right = r;
    emit dialogAccepted();
}


void indentOptions::on_buttonBox_rejected()
{
    emit dialogRejected();
    this->close();
}
