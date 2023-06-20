#include "tutorial.h"
#include "ui_tutorial.h"
#include "QSettings"

int i=0;

tutorial::tutorial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tutorial)
{
    ui->setupUi(this);
    QString path = ":/Images/Resources/Old Icons/two.jpeg";
    QString html = "<img width='%100' height='%50' src=\""+path+"\">";
    QString texteFinal = ui->textEdit->toHtml() + html;
        ui->textEdit->setHtml(texteFinal);
   // ui->textEdit->setReadOnly(true);
}

tutorial::~tutorial()
{
    delete ui;
}

void tutorial::on_pushButton_clicked()
{
  //  ui->textEdit->setStyleSheet("text-align:center");
    i++;
    if(i==1)
    {
        ui->textEdit->clear();
        QString path = ":/Images/Resources/Old Icons/one.jpeg";
        QString html = "<img width='%100' height='%50' src=\""+path+"\">";
        QString texteFinal = ui->textEdit->toHtml() + html;
            ui->textEdit->setHtml(texteFinal);
    }
    else if(i==2)
    {
         ui->textEdit->clear();
        QString path = ":/Images/Resources/Old Icons/three.jpeg";
        QString html = "<img width='%100' height='%50' src=\""+path+"\">";
        QString texteFinal = ui->textEdit->toHtml() + html;
            ui->textEdit->setHtml(texteFinal);
    }
    else if(i==3)
    {
         ui->textEdit->clear();
        QString path = ":/Images/Resources/Old Icons/four.jpeg";
        QString html = "<img width='%100' height='%50' src=\""+path+"\">";
        QString texteFinal = ui->textEdit->toHtml() + html;
            ui->textEdit->setHtml(texteFinal);
    }
    else if(i==4)
    {
         ui->textEdit->clear();
        QString path = ":/Images/Resources/Old Icons/six.jpeg";
        QString html = "<img width='%100' height='%50' src=\""+path+"\">";
        QString texteFinal = ui->textEdit->toHtml() + html;
            ui->textEdit->setHtml(texteFinal);
    }
    else if(i==5)
    {
         ui->textEdit->clear();
        QString path = ":/Images/Resources/Old Icons/seven.jpeg";
        QString html = "<img width='%100' height='%50' src=\""+path+"\">";
        QString texteFinal = ui->textEdit->toHtml() + html;
            ui->textEdit->setHtml(texteFinal);
    }
    else if(i==6)
    {
         ui->textEdit->clear();
        QString path = ":/Images/Resources/Old Icons/eight.jpeg";
        QString html = "<img width='%100' height='%50' src=\""+path+"\">";
        QString texteFinal = ui->textEdit->toHtml() + html;
            ui->textEdit->setHtml(texteFinal);
    }
    else if(i==7)
    {
         ui->textEdit->clear();
        QString path = ":/Images/Resources/Old Icons/nine.jpeg";
        QString html = "<img width='%100' height='%50' src=\""+path+"\">";
        QString texteFinal = ui->textEdit->toHtml() + html;
            ui->textEdit->setHtml(texteFinal);
    }
    else if(i==8)
    {
         ui->textEdit->clear();
        QString path = ":/Images/Resources/Old Icons/ten.jpeg";
        QString html = "<img width='%100' height='%50' src=\""+path+"\">";
        QString texteFinal = ui->textEdit->toHtml() + html;
            ui->textEdit->setHtml(texteFinal);
    }
    else if(i==9)
    {
         ui->textEdit->clear();
        QString path = ":/Images/Resources/Old Icons/eleven.jpeg";
        QString html = "<img width='%100' height='%50' src=\""+path+"\">";
        QString texteFinal = ui->textEdit->toHtml() + html;
            ui->textEdit->setHtml(texteFinal);
    }

    else if(i==10)
    {
         ui->textEdit->clear();
        QString path = ":/Images/Resources/Old Icons/five.jpeg";
        QString html = "<img width='%100' height='%50' src=\""+path+"\">";
        QString texteFinal = ui->textEdit->toHtml() + html;
            ui->textEdit->setHtml(texteFinal);
            on_pushButton_2_clicked();
    }
}


void tutorial::on_pushButton_2_clicked()
{
    this->close();
    QSettings settings("IIT-B","OpenOCRCorrect");
    settings.beginGroup("tutorial");
    settings.setValue("consent","never show again");
    settings.endGroup();

}
