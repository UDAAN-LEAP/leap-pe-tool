#include "commentsview.h"
#include "ui_commentsview.h"
#include "mainwindow.h"
#include <QCloseEvent>
string commentsFilename;
CommentsView::CommentsView(const int &words, const int &chars, const float &wordacc, const float &characc,const QString commentsFilelocation, QWidget *parent) :
    QDialog(parent)
{
    ui = new Ui::CommentsView();
    ui->setupUi(this);
    ui->h_words->setText(QString::number(words));
    ui->h_characters->setText(QString::number(chars));
    ui->acc_word->setText(QString::number(wordacc));
    ui->acc_character->setText(QString::number(characc));
    commentsFilename = commentsFilelocation.toUtf8().constData();
    fstream commentsFile(commentsFilename);
    string comments;
    commentsFile>>comments;
    commentsFile.close();
    ui->commentTextBrowser->setText(QString::fromStdString(comments));
}


CommentsView::~CommentsView()
{
    delete ui;
}

void CommentsView::on_pushButton_clicked()
{
    fstream commentsFile;
    commentsFile.open(commentsFilename, ios::out | ios::trunc);
    string comments = ui->commentTextBrowser->toPlainText().toUtf8().constData();
    commentsFile<<comments;
    commentsFile.close();

}
