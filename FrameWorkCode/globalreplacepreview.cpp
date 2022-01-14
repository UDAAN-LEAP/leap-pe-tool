#include "globalreplacepreview.h"
#include "ui_globalreplacepreview.h"
#include <QStandardItemModel>
#include "crashlog.h"
globalReplacePreview::globalReplacePreview(QWidget *parent,QStandardItemModel *model) :
    QDialog(parent),
    ui(new Ui::globalReplacePreview)
{
    ui->setupUi(this);
    qInstallMessageHandler(crashlog::myMessageHandler);
    setWindowTitle("Preview of word replacement");
    ui->tableView->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

globalReplacePreview::~globalReplacePreview()
{
    delete ui;
}
