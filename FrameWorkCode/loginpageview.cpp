/*!
 *\class LoginPageView
 *\brief This class is used to authenticate the Github User
 */
#include "loginpageview.h"
#include "ui_loginpageview.h"
#include "mainwindow.h"
#include <QMessageBox>

/*!
 * \fn LoginPageView::LoginPageView
 * \brief Sets up the UI and sets the text edit for the password field so that the typed characters are
 * not visible
 * \param parent
 */
LoginPageView::LoginPageView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginPageView)
{
    ui->setupUi(this);
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
}
/*!
 * \brief LoginPageView::~LoginPageView
 */
LoginPageView::~LoginPageView()
{
    delete ui;
}

/*!
 * \fn LoginPageView::on_loginButton_clicked
 * \brief This function Authenticates the user
 */
void LoginPageView::on_loginButton_clicked()
{


    //! Get credentials from user

    QString usernameString= ui->usernameEdit->text();
    QString passwordString= ui->passwordEdit->text();
    //ui->usernameEdit->clear();
    ui->passwordEdit->clear();


    //QString projectId = ""; //should be added in project.xml file and fetched from there
    QString userId, userRole;  //fetch on sign in   //add location
    QString userJsonFilePath = QDir::currentPath() + "/UserJson.json";  //add location


    //User JSON
    QFile userJsonFile(userJsonFilePath);
    userJsonFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray userData = userJsonFile.readAll();

    QJsonDocument userDocument = QJsonDocument::fromJson(userData);
    QJsonObject userObj = userDocument.object();

    //! Get userid and password of Github and authenticate user. If userid is undefined print message to
    //! user that login was unsucessful

    if(!userObj.value(usernameString).isUndefined()) {
        QJsonObject user = userObj.value(usernameString).toObject();
//      QString username = user["github userid"].toString();
        QString password =user["github password"].toString();
        if(password==passwordString){
            userId=usernameString;
            userRole = user["Role"].toString();
            userJsonFile.close();
            QMessageBox::information(this,"Login","Login Succesful!");
            hide();
            mwindow =new MainWindow(this);
            mwindow->setRole(userRole);
            mwindow->show();
        } else {
            userJsonFile.close();
            QMessageBox::information(this,"Login","Login Un-succesful!\nIncorrent Password");
        }
    } else {
        userJsonFile.close();
        QMessageBox::information(this,"Login","Login Un-succesful!\nUsername not found");
    }

}
