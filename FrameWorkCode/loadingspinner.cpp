/*!
 * \class LoadingSpinner
 * \brief This is a class to show loading window whenever there is some backend task going on in the tool
 *        for eg. Performing a lengthy saving action or loading data, etc.
 *
 * This function is used to initialize the dialog box for the Loading Window
 *
 * We first load the gif for the loading window spinner and we set the gif to the label(refer loadingspinner.ui)
 * Then we scale it to fit the window and then we start the gif. Whenever the dialog is called, it will start the
 * gif and the loading spinner will start spinning.
 *
 * \sa qInstallMessageHandler()
 */
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
    ui->setupUi(this);
    qInstallMessageHandler(crashlog::myMessageHandler);
    mv = new QMovie(":/Images/spinbar-tp.gif");
    ui->labelspin->setAttribute(Qt::WA_NoSystemBackground);
    ui->labelspin->setMovie(mv);
    ui->labelspin->setScaledContents(true);
    mv->start();
}


/*!
 * \fn LoadingSpinner::SetMessage()
 * \brief This function is used to set message to the loading window.
 *
 * We have called this function wherever we are calling the loading window.
 *
 * We set the body of the loading window using setText and title(i.e. head) using the setWindowTitle function
 *
 * \param QString head, QString body
 */

void LoadingSpinner::SetMessage(QString head, QString body){
    ui->label_2->setText(body);
    this->setWindowTitle(head);

}



LoadingSpinner::~LoadingSpinner()
{
    mv->stop();
    delete ui;
}

