#include "loginpageview.h"
#include <QApplication>
#include <QMessageBox>
#include <git2.h>
#include "CrashReport.h"
int main(int argc, char *argv[])
{
	git_libgit2_init();
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("./logonew.png"));
    a.setStyleSheet("QMessageBox{font: 15px \"Work Sans\"; background:rgb(32, 33, 72);} QMessageBox QLabel{color:white;} QMessageBox QPushButton{background-color:rgb(227, 228, 228);border:0px; color: rgb(32, 33, 72); height:26.96px; width: 113.5px; padding-top:1px; border-radius:4.8px; padding-left:1.3px; selection-color: rgb(32, 33, 72); selection-background-color: rgb(136, 138, 133);} QMessageBox QPushButton:checked{background-color: rgb(136, 138, 133);} QMessageBox QPushButton:pressed {background-color: rgb(136, 138, 133);}");
    a.setApplicationName( QStringLiteral( "OpenOCRCorrect" ) );
    QString logPath = QApplication::applicationDirPath() + "/Crash logs";
    CrashReport::setSignalHandler(logPath, [] (const QString &inFileName, bool inSuccess) {
    QString  message;
      if (inSuccess)
      {
         message = QStringLiteral( "Sorry, %1 has crashed.\n\nA log file was written to:\n\n%2\n\nPlease email this to akshay.j@iitb.ac.in." ).arg( QCoreApplication::applicationName(), inFileName );
      }
      else
      {
         message = QStringLiteral( "Sorry, %1 has crashed and we could not write a log file to:\n\n%2\n\nPlease contact akshay.j@iitb.ac.in.").arg( QCoreApplication::applicationName(), inFileName );
      }

      QMessageBox::critical( nullptr, QObject::tr( "%1 has Unfortunately Crashed" ).arg( QCoreApplication::applicationName() ), message );
   });
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

