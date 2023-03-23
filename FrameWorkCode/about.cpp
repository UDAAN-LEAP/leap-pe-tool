#include "about.h"
#include "ui_about.h"
#include <QDebug>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    this->setWindowTitle("About Udaan PE Tool");
    QString version = qApp->applicationVersion();
    ui->label->setTextFormat(Qt::RichText);
    QString date ="Date: No info available.";
    ui->label->setText("<b>Udaan Post Editing Tool <u>"+version+"</u></b>");
    QUrl url("https://api.github.com/repos/UDAAN-LEAP/leap-pe-tool/releases");
    QNetworkRequest request(url);               //requesting url over the network
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkAccessManager nam;                  //sending network request
    QNetworkReply * reply = nam.get(request);
    while(true){
        qApp->processEvents();
        if(reply->isFinished()) break;
    }

    if(reply->isFinished()){
        QByteArray response_data = reply->readAll();
        QJsonDocument json = QJsonDocument::fromJson(response_data);
        date = json[0]["published_at"].toString();
    }
    ui->label_3->setText("Build released on: "+(!date.isEmpty()?date:"No info available"));
}

about::~about()
{
    delete ui;
}

void about::on_pushButton_clicked()
{
    this->close();
}

