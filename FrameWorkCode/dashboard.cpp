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


/*!
 * \fn dashboard::dashboard
 * \brief This Class is used to preview the dashboard of Application.
 * \details
 * 1)Contains a Dialog Box which is a base class of dialog windows.
 * 2)Sets up the user interface for the specified widget.
 * 3)Includes a message handler which logs the crashlogs of application.
 * 4)Sets up window Title.
 * 5)Sets up html in text browser.
 * 6)Sets the range of SpinBox(The maximum elements textBrowser contains).
 * \param parent
 * \param s
 * \param max
 * \param repoMap
 */
dashboard::dashboard(QWidget *parent, QString s, int max, QMap<int, QString> repoMap, QString *p) :
    QDialog(parent),
    ui(new Ui::dashboard)
{
    ui->setupUi(this);
    qInstallMessageHandler(crashlog::myMessageHandler);
    setWindowTitle("User Dashboard");
    this->repoMap = repoMap;

//    ui->textBrowser->setHtml(s);
    ui->verticalLayout->setAlignment(Qt::AlignHCenter);

    QMapIterator<int,QString>i(repoMap);
    while(i.hasNext()){
        i.next();
        auto btn = new QPushButton();

        btn->setText(i.value());
        btn->setFixedHeight(50);
        ui->verticalLayout->addWidget(btn);
    }
    ui->spinBox->setRange(0,max);
    this->p = p;
}

/*!
 * \fn dashboard::~dashboard
 * \brief Deallocates the memory and cleans up class and it's object's.
 */
dashboard::~dashboard()
{
    delete ui;
}


/*!
 * \fn dashboard::on_pushButton_clicked
 * \inherits from dashboard, Executes when Clicked!
 * \brief
 * 1)Sets the value of spinBox to integer id.
 * 2)if there are no elemets in the textbrowser it returns or terminates the function.
 * 3)stores the filePath into String,if no filePath is Found,function terminates.
 * 4)Allows monitoring signals and slots by using QFuture and QFutureWatcher Classes.
 * 5)Conations Spinner which is displayed when importing is in process
 * 6)If the project is found already downloaded in same directory,throws an
 * error and terminates the function else the project is downloaded Successfully
 */
void dashboard::on_pushButton_clicked()
{
    int id = ui->spinBox->value();
    QString path, url_;
    bool ok;
    int ret;
    if(id == 0){
        QMessageBox::information(this, "Enter Project id", "Project id can't be zero", QMessageBox::Ok, QMessageBox::Ok);
        return;
    }

    path = QFileDialog::getExistingDirectory(this, tr("Open Directory for importing project"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (path == "") {
        qDebug() << "User cancelled import #1";
        return;
    }
    url_ = "https://github.com/UdaanContentForLogging/"+repoMap[id];
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
        *p = path+"/"+repoMap[id]+"/project.xml";
    }
    dashboard::close();
}

/*!
 * \fn dashboard::stopSpinning
 * \brief This function stops the sppiner whenever called.
 */
void dashboard::stopSpinning()
{
    spinner->close();
    spinner->deleteLater();
}

