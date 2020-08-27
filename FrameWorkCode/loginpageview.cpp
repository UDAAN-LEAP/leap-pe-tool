#include "loginpageview.h"
#include "ui_loginpageview.h"
#include "mainwindow.h"

LoginPageView::LoginPageView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginPageView)
{
    ui->setupUi(this);
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
}

LoginPageView::~LoginPageView()
{
    delete ui;
}


void LoginPageView::on_loginButton_clicked()
{
            QString usernameString= ui->usernameEdit->text();
            QString passwordString= ui->passwordEdit->text();
            ui->usernameEdit->clear();
            ui->passwordEdit->clear();

            //QString projectId = ""; //should be added in project.xml file and fetched from there
            QString userId, userRole;  //fetch on sign in   //add location
            QString userJsonFilePath = "UserJson.json";  //add location


            //User JSON
            QFile userJsonFile(userJsonFilePath);
            userJsonFile.open(QIODevice::ReadOnly | QIODevice::Text);
            QByteArray userData = userJsonFile.readAll();

            QJsonDocument userDocument = QJsonDocument::fromJson(userData);
            QJsonObject userObj = userDocument.object();

            QJsonObject user = userObj.value(usernameString).toObject();
            QString username = user["github userid"].toString();
            QString password =user["github password"].toString();


            if(username==usernameString && password==passwordString){
                userId=username;
                userRole = user["Role"].toString();
                userJsonFile.close();
                if(userRole=="Verifier"){
                QMessageBox::information(this,"Login","Login Succesful!");
                hide();
                mwindow =new MainWindow(this);
                mwindow->show();
                }
            }
            else{
                userJsonFile.close();
                QMessageBox::information(this,"Login","Login Un-succesful!\nPlease Check Login Credentials!");
            }
}
