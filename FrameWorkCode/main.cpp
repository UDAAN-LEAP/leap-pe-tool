#include "loginpageview.h"
#include <QApplication>
#include <QMessageBox>
#include <git2.h>
#include <QFile>
#include <QTextStream>
#include <signal.h>

void signalHandler(int signum){
    signal(signum, SIG_DFL);
    qDebug() << "App crashed";
    QMessageBox::critical(nullptr, "OpenOCRCorrect has Unfortunately crashed", "Application has unexpectedly crashed! \n\nTry restarting the application and contact technical team at akansharawat.ind@gmail.com");
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
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("./logonew.png"));
    a.setStyleSheet("QMessageBox{font: 15px \"Work Sans\"; background:rgb(32, 33, 72);} QMessageBox QLabel{color:white;} QMessageBox QPushButton{background-color:rgb(227, 228, 228);border:0px; color: rgb(32, 33, 72); height:26.96px; width: 113.5px; padding-top:1px; border-radius:4.8px; padding-left:1.3px; selection-color: rgb(32, 33, 72); selection-background-color: rgb(136, 138, 133);} QMessageBox QPushButton:checked{background-color: rgb(136, 138, 133);} QMessageBox QPushButton:pressed {background-color: rgb(136, 138, 133);}");
    a.setApplicationName( QStringLiteral( "OpenOCRCorrect" ) );
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
        qDebug() << "mwindow";
        w.show();
    }
    int retn = a.exec();
    git_libgit2_shutdown();
    return retn;
}


