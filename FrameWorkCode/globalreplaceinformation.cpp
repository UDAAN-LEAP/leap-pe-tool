#include "globalreplaceinformation.h"
#include "ui_globalreplaceinformation.h"
#include <qtablewidget.h>
#include "crashlog.h"
globalReplaceInformation::globalReplaceInformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::globalReplaceInformation)
{
    ui->setupUi(this);
    qInstallMessageHandler(crashlog::myMessageHandler);
    this->setFixedSize(1080,230);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
 }

globalReplaceInformation::~globalReplaceInformation()
{
    delete ui;
}
