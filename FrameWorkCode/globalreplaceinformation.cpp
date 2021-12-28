#include "globalreplaceinformation.h"
#include "ui_globalreplaceinformation.h"
#include <qtablewidget.h>

globalReplaceInformation::globalReplaceInformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::globalReplaceInformation)
{
    ui->setupUi(this);
  //  ui->tableWidget->horizontalHeader()->resizeSection(1,400);
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
 }

globalReplaceInformation::~globalReplaceInformation()
{
    delete ui;
}
