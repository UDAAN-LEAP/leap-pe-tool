#include "add_comment.h"
#include "ui_add_comment.h"

CommentHandler::CommentHandler(QWidget *parent, QString comment) :
    QDialog(parent),
    ui(new Ui::CommentHandler)
{
    ui->setupUi(this);
    setWindowTitle("Comments");
    if(comment != ""){
        ui->textEdit->setText(comment);
        ui->textEdit->setEnabled(false);
        ui->AddComment->setVisible(false);
        ui->Cancel->setText("Close");
    }
}

CommentHandler::~CommentHandler()
{
    delete ui;
}

QString CommentHandler::getComment()
{
    return this->_comment;
}

void CommentHandler::on_AddComment_clicked()
{
    if(ui->textEdit->toPlainText() == "") return;

    this->_comment = ui->textEdit->toPlainText();
    ui->AddComment->setVisible(false);
    ui->Cancel->setText("Close");
    emit commented();
}


void CommentHandler::on_Cancel_clicked()
{
    this->close();
}


void CommentHandler::on_deleteComment_clicked()
{
    emit deleted();
}

