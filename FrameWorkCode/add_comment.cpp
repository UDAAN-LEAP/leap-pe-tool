#include "add_comment.h"
#include "ui_add_comment.h"

/*!
 * \class CommentHandler
 * \param It will take comments from corrector and verifier,
 * \param Role of the user
*/
CommentHandler::CommentHandler(QWidget *parent, QString corrector_comment ,QString verifier_comment, QString mRole) :
    QDialog(parent),
    ui(new Ui::CommentHandler)
{
    ui->setupUi(this);
    ui->previousComment->setVisible(false);
    ui->label->setVisible(false);
    setWindowTitle("Comments");

    QString comment = "";
    QString previousComment = "";

    if(mRole == "Corrector"){
        comment = corrector_comment;
        previousComment = verifier_comment;
        ui->label->setText("Verifier");
    }
    if(mRole == "Verifier"){
        comment = verifier_comment;
        previousComment = corrector_comment;
        ui->label->setText("Corrector");
    }

    if(comment != ""){
        ui->presentComment->setText(comment);
    }
    if(previousComment != ""){
        ui->label->setVisible(true);

        ui->previousComment->setVisible(true);
        ui->previousComment->setText(previousComment);
        ui->previousComment->setReadOnly(true);
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
    if(ui->presentComment->toPlainText() == "") return;

    this->_comment = ui->presentComment->toPlainText();
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

