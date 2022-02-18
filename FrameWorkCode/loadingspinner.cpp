#include "loadingspinner.h"
#include "ui_loadingspinner.h"
#include "QMovie"
#define MAINWINDOW_H
#include <QMainWindow>
#include <QWidget>
#include <mainwindow.h>
#include "crashlog.h"
LoadingSpinner::LoadingSpinner(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadingSpinner)
{
    this->setStyleSheet("background-color: white;");
    ui->setupUi(this);
    qInstallMessageHandler(crashlog::myMessageHandler);
    mv = new QMovie(":/Images/spinbar-tp.gif");
    ui->labelspin->setAttribute(Qt::WA_NoSystemBackground);
    ui->labelspin->setMovie(mv);
    ui->labelspin->setScaledContents(true);
    mv->start();
}


void LoadingSpinner::SetMessage(QString head, QString body){
    ui->label_2->setText(body);
    this->setWindowTitle(head);

}



LoadingSpinner::~LoadingSpinner()
{
    mv->stop();
    delete ui;
}

