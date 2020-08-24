#include "commentsview.h"
#include "ui_commentsview.h"
#include<QFile>
#include<QTextStream>

CommentsView::CommentsView(const int &words, const int &chars, const float &wordacc, const float &characc,const QString commentsField,const QString commentsFilelocation, int rating, QWidget *parent) :
    QDialog(parent)
{
    ui = new Ui::CommentsView();
    ui->setupUi(this);
    setWindowTitle("Comments and Accuracy");
    ui->h_words->setText(QString::number(words));
    ui->h_characters->setText(QString::number(chars));
    ui->acc_word->setText(QString::number(wordacc));
    ui->acc_character->setText(QString::number(characc));
    ui->commentTextBrowser->setText(commentsField);
    //ui->rating->setText(QString::number(rating));
}


CommentsView::~CommentsView()
{
    delete ui;
}
