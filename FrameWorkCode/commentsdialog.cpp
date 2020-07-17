#include "commentsdialog.h"
#include "ui_commentsdialog.h"

CommentsDialog::CommentsDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CommentsDialog)
{
    ui->setupUi(this);
}

CommentsDialog::~CommentsDialog()
{
    delete ui;
}
