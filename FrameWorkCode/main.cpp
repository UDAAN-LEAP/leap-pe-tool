/*!
\class main
\brief Main class is entry contains main function which is entry point of a C++ application.
       This class using main function loads first window of the software. It also provides
       signal handlers for various tasks and unexpected crashes.
\sa    signalHandler(), mySignal(), main(), return_signal()
*/
#include "loginpageview.h"
#include <QApplication>
#include <QMessageBox>
#include <git2.h>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <signal.h>
#include "crashlog.h"
#include <QAbstractItemModel>
QAbstractItemModel* CustomTextBrowser::engModel = nullptr;
QAbstractItemModel* CustomTextBrowser::devModel = nullptr;
int CustomTextBrowser::modelFlag = 0;

/*!
 * \fn signalHandler
 * \brief This function takes signal number as argument and then calls signal function
 *        of c++ which is used to trap unexpected interupts and events causing program to
 *        stop. This function identifies the type of signal caused interupt and then prints it in
 *        log.
 * \param signum
 *
 * \sa signal()
 */
void signalHandler(int signum){
    signal(signum, SIG_DFL);
    std:string signame;
    if(signum == SIGSEGV)
        signame = "SIGSEGV";
    else if(signum == SIGFPE)
        signame = "SIGFPE";
    else if(signum == SIGILL)
        signame = "SIGILL";
    else if(signum == SIGTERM)
        signame = "SIGTERM";
    else if(signum == SIGABRT)
        signame = "SIGABRT";
    else
        signame = "SIGUNKN";
    qDebug() << "App crashed with signal: " << QString::fromStdString(signame);
    QMessageBox::critical(nullptr, "Udaan Editing Tool has Unfortunately crashed", "Application has unexpectedly crashed!\n\nA log file was written to:\n"+QString::fromStdString(qApp->applicationDirPath().toStdString())+"/application.log" + " \n\nTry restarting the application and email this to sanskritdigitization@gmail.com");
    QApplication::quit();
}

/*!
 * \fn mysignal
 * \brief This function calls signal function of c++ to trap the unexpected interupts.
 * \sa signal()
 */
void mySignal(){

    signal(SIGSEGV, signalHandler); //!SIGSEGV for invalid access to storage
    signal(SIGFPE, signalHandler);  //!SIGFPE for overflow or mathematically invalid operation
    signal(SIGILL, signalHandler);  //!SIGIIL for Detected illegal command
    signal(SIGTERM, signalHandler); //!SIGTERM for termination request
    signal(SIGABRT, signalHandler); //!SIGABRT for termination of program abnormally
}


/*!
 * \fn main
 * \brief Main function in c++ is entry point of the software and it also serves as exit point.
 *        This function initialises git and then creates object for QApplication class which helps
 *        to manage GUI of QTC++ application and using this object this function loads logo and
 *        title of the applications. Then this function creates object for MainWindow class
 *        and loads it into the memory.
 * \param argc
 * \param argv
 *
 * \sa qInstallMessageHandler(), git_libgit2_init(), mySignal(), git_libgit2_shutdown()
 *
 * \return retn
 *
 * \note This function also used to write all logs generated into a file.
 */
int main(int argc, char *argv[])
{
    git_libgit2_init();

    qInstallMessageHandler(crashlog::myMessageHandler);  //Handles all crashing related messages

    //!Setting Icons and stylesheet
    QApplication a(argc, argv);
    QIcon windowIcon(":/Images/Resources/logonew.png");
    a.setWindowIcon(windowIcon);             //Sets icon of the GUI window.
    a.setStyleSheet("QMessageBox{font: 15px \"Work Sans\"; background:rgb(32, 33, 72);} QMessageBox QLabel{color:white;} QMessageBox QPushButton{background-color:rgb(227, 228, 228);border:0px; color: rgb(32, 33, 72); height:26.96px; width: 113.5px; padding-top:1px; border-radius:4.8px; padding-left:1.3px; selection-color: rgb(32, 33, 72); selection-background-color: rgb(136, 138, 133);} QMessageBox QPushButton:checked{background-color: rgb(136, 138, 133);} QMessageBox QPushButton:pressed {background-color: rgb(136, 138, 133);}");
    a.setApplicationName( QStringLiteral( "Udaan Editing Tool" ) );
    a.setApplicationVersion("v3.5.4");

    //! Writing Log Files
    QFile logFile(QString::fromStdString(qApp->applicationDirPath().toStdString())+"/application.log");
    logFile.open(QFile::ReadWrite | QFile::Append);
    QTextStream ts(&logFile);
    ts << endl << "Udaan Editing Tool Application Log" << endl << "Date: " <<  QDateTime::currentDateTime().toString( "dd MMM yyyy @ HH:mm:ss" ) << endl << QString("Username:" + qgetenv("USERNAME")) << endl << endl << "Application Log:" << endl ;
    ts.setCodec("UTF-8");
    logFile.flush();
    logFile.close();

    mySignal();
    MainWindow w;
    //! Checking login
    if(w.exitStatus()) {
        QMessageBox msgBox;
        msgBox.setText("Login");
        msgBox.setInformativeText("Login Failed");
        msgBox.setStandardButtons(QMessageBox::Cancel);
        msgBox.show();
    }
    else {
        w.showMaximized();  //loads main window ui and backend files
    }

    int retn = a.exec();
    git_libgit2_shutdown();
    return retn;
}

/*!
 * \fn return_signal
 * \brief Returns a signal
 * \param sig
 * \return std::string
 */
std::string return_signal(int sig)
{
    return "";
}
