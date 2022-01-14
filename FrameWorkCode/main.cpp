#include "loginpageview.h"
#include <QApplication>
#include <QMessageBox>
#include <git2.h>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <signal.h>
#include "crashlog.h"
void signalHandler(int signum){
    signal(signum, SIG_DFL);
    qDebug() << "App crashed";
    QMessageBox::critical(nullptr, "OpenOCRCorrect has Unfortunately crashed", "Application has unexpectedly crashed!\n\nA log file was written to:\n"+QString::fromStdString(qApp->applicationDirPath().toStdString())+"/application_log.txt" + " \n\nTry restarting the application and email this to sanskritdigitization@gmail.com");
    QApplication::quit();
}

void mySignal(){

    signal(SIGSEGV, signalHandler);
    signal(SIGFPE, signalHandler);
    signal(SIGILL, signalHandler);
    signal(SIGTERM, signalHandler);
    signal(SIGABRT, signalHandler);
}



int main(int argc, char *argv[])
{
    git_libgit2_init();

    qInstallMessageHandler(crashlog::myMessageHandler);
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("./logonew.png"));
    a.setStyleSheet("QMessageBox{font: 15px \"Work Sans\"; background:rgb(32, 33, 72);} QMessageBox QLabel{color:white;} QMessageBox QPushButton{background-color:rgb(227, 228, 228);border:0px; color: rgb(32, 33, 72); height:26.96px; width: 113.5px; padding-top:1px; border-radius:4.8px; padding-left:1.3px; selection-color: rgb(32, 33, 72); selection-background-color: rgb(136, 138, 133);} QMessageBox QPushButton:checked{background-color: rgb(136, 138, 133);} QMessageBox QPushButton:pressed {background-color: rgb(136, 138, 133);}");
    a.setApplicationName( QStringLiteral( "OpenOCRCorrect" ) );
    QFile logFile(QString::fromStdString(qApp->applicationDirPath().toStdString())+"/application_log.txt");
    logFile.open(QFile::ReadWrite | QFile::Append);
    QTextStream ts(&logFile);
    ts << endl << "OpenOCRCorrect Application Log" << endl << "Date: " <<  QDateTime::currentDateTime().toString( "dd MMM yyyy @ HH:mm:ss" ) << endl << QString("Username:" + qgetenv("USERNAME")) << endl << endl << "Application Log:" << endl ;
    ts.setCodec("UTF-8");
    logFile.flush();
    logFile.close();

    mySignal();
    MainWindow w;
    if(w.exitStatus()) {
        QMessageBox msgBox;
        msgBox.setText("Login");
        msgBox.setInformativeText("Login Failed");
        msgBox.setStandardButtons(QMessageBox::Cancel);
        msgBox.show();
    }
    else {
        w.show();
    }
    int retn = a.exec();
    git_libgit2_shutdown();
    return retn;
}


