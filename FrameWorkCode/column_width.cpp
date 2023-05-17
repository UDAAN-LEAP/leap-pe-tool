#include "column_width.h"
#include "ui_column_width.h"

column_width::column_width(int* presentWidth , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::column_width)
{
    ui->setupUi(this);
    this->setWindowTitle("Set Column Width");
    this->width = presentWidth;
    int data = *presentWidth;
    ui->width->setPlainText(QString::number(data));
}

column_width::~column_width()
{
    delete ui;
}

void column_width::on_close_clicked()
{
    done(1);
}

void column_width::on_change_clicked()
{
    int  input = (ui->width->toPlainText().toInt());

    *(this->width) = input;
    int data = *this->width;
    ui->width->setPlainText(QString::number(data));
    emit changed();
}

