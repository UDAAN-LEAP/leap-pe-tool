#include "loadingspinner.h"
#include "ui_loadingspinner.h"
#include "QMovie"
#define MAINWINDOW_H
#include <QMainWindow>
#include <QWidget>
#include <mainwindow.h>
LoadingSpinner::LoadingSpinner(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadingSpinner)
{
    this->setStyleSheet("background-color: white;");
    ui->setupUi(this);
    this->move(425,300);
    QMovie *mv = new QMovie(":/Images/spinbar-tp.gif");
    ui->labelspin->setAttribute(Qt::WA_NoSystemBackground);
    ui->labelspin->setMovie(mv);
    ui->labelspin->setScaledContents(true);
    mv->start();
}


void LoadingSpinner::SetSave(){
    ui->label_2->setText("Saving...");
    this->setWindowTitle("Saving File");

}

LoadingSpinner::~LoadingSpinner()
{
    delete ui;
}

