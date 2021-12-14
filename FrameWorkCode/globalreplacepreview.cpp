#include "globalreplacepreview.h"
#include "ui_globalreplacepreview.h"

globalReplacePreview::globalReplacePreview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::globalReplacePreview)
{
    ui->setupUi(this);
    setWindowTitle("Preview of word replacement");
}

globalReplacePreview::~globalReplacePreview()
{
    delete ui;
}
