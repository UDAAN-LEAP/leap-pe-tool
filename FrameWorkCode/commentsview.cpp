#include "commentsview.h"
#include "ui_commentsview.h"
#include<QFile>
#include<QTextStream>
CommentsView::CommentsView(const int &words, const int &chars, const float &wordacc, const float &characc,const QString commentFilename, QWidget *parent) :
    QDialog(parent)
{
    ui = new Ui::CommentsView();
    ui->setupUi(this);
    ui->h_words->setText(QString::number(words));
    ui->h_characters->setText(QString::number(chars));
    ui->acc_word->setText(QString::number(wordacc));
    ui->acc_character->setText(QString::number(characc));
 
    QFile sFile(commentFilename);
    if(sFile.open(QFile::ReadWrite | QFile::Text))
    {
        QTextStream in(&sFile);
        in.setCodec("UTF-8");
        ui->commentTextBrowser->setText(in.readAll());
        sFile.close();
    }
}

CommentsView::~CommentsView()
{
    delete ui;
}
