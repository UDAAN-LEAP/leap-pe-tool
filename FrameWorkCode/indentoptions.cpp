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

void indentOptions::on_buttonBox_accepted()
{
    int l = ui->textEdit_left->toPlainText().toInt();
    int r = ui->textEdit_right->toPlainText().toInt();

    *left = l;
    *right = r;
    this->close();

}

