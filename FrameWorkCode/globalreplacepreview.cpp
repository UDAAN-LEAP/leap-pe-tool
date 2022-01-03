#include "globalreplacepreview.h"
#include "ui_globalreplacepreview.h"
#include <QStandardItemModel>

globalReplacePreview::globalReplacePreview(QWidget *parent,QStandardItemModel *model) :
    QDialog(parent),
    ui(new Ui::globalReplacePreview)
{
    ui->setupUi(this);
    setWindowTitle("Preview of word replacement");
    ui->tableView->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

globalReplacePreview::~globalReplacePreview()
{
    delete ui;
}
