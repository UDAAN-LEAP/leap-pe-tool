#include "progressbardialog.h"
#include "ui_progressbardialog.h"

ProgressBarDialog::ProgressBarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgressBarDialog)
{
    ui->setupUi(this);
    ui->description->setReadOnly(true);
    ui->progressBar->setValue(0);
}

ProgressBarDialog::~ProgressBarDialog()
{
    delete ui;
}

void ProgressBarDialog::setMessage(QString message)
{
    ui->description->setText(message);
}

void ProgressBarDialog::setPercentage(int percentage)
{
    ui->progressBar->setValue(percentage);
}
