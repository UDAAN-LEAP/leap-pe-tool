#include "dashboard.h"
#include "QtConcurrent/qtconcurrentrun.h"
#include "qfuturewatcher.h"
#include "ui_dashboard.h"
#include "crashlog.h"
#include <QStandardItemModel>
#include <QSettings>
#include <QProcess>
#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>
#include <QJsonParseError>
#include <QPushButton>
#include <QFileDialog>
#include <QInputDialog>
#include <QLineEdit>
#include "loadingspinner.h"
#include <Project.h>

dashboard::dashboard(QWidget *parent, QString s, int max, QMap<int, QString> repoMap) :
    QDialog(parent),
    ui(new Ui::dashboard)
{
    ui->setupUi(this);
    qInstallMessageHandler(crashlog::myMessageHandler);
    setWindowTitle("User Dashboard");
//    ui->tableView->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
//    //ui->tableView->setModel(model);
//    ui->tableView->horizontalHeader()->setMaximumSectionSize(600);
//    ui->tableView->setWordWrap(true);
//    ui->tableView->resizeColumnsToContents();
//    ui->tableView->resizeRowsToContents();
    this->repoMap = repoMap;

    ui->textBrowser->setHtml(s);
    ui->spinBox->setRange(0,max);
}

dashboard::~dashboard()
{
    delete ui;
}



void dashboard::on_pushButton_clicked()
{
    int id = ui->spinBox->value();
    qDebug()<<"id "<<id<<repoMap[id];
    QString path, url_;
    bool ok;
    int ret;

    path = QFileDialog::getExistingDirectory(this, tr("Open Directory for importing project"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (path == "") {
        qDebug() << "User cancelled import #1";
        return;
    }

//    url_ = QInputDialog::getText(this, tr("Project url"),
//                                     tr("Enter Project url"), QLineEdit::Normal, "", &ok);
    url_ = "https://github.com/UdaanContentForLogging/"+repoMap[id]+".git";
    qDebug()<<"url "<<url_;
//    if (!ok) {
//        qDebug() << "User cancelled import #2";
//        return;
//    }
    if (url_.startsWith("git@github.com")) {
        qDebug() << "Not prepared to import using SSH. Please provide HTTPS URL";
        QMessageBox::information(this, "Use HTTPS URL", "This URL requires SSH key. Please provide HTTPS URL", QMessageBox::Ok, QMessageBox::Ok);
        return;
    }

    QFutureWatcher<int> watcher;
    connect(&watcher, &QFutureWatcher<int>::finished, this, &dashboard::stopSpinning);

    QFuture<int> t1 = QtConcurrent::run(Project::clone, QString(url_), QString(path));
    watcher.setFuture(t1);

    spinner = new LoadingSpinner(this);
    spinner->SetMessage("Importing Set...", "Importing...");
    spinner->setModal(false);
    spinner->exec();

    if ((ret = t1.result()) != 0) {
        QMessageBox::information(this, "Error", "The project is already downloaded", QMessageBox::Ok, QMessageBox::Ok);
        qDebug()<<"Exited with return code"<<ret;
    } else {
        QMessageBox::information(this, "Successful", "Successfully imported the set", QMessageBox::Ok, QMessageBox::Ok);
    }
    dashboard::close();
}

/*!
* \fn    dashboard::stopSpinning
* \brief This function stops the sppiner whenever called.
*
*/
void dashboard::stopSpinning()
{
    spinner->close();
    spinner->deleteLater();
}

