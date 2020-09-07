#include "loginpageview.h"
#include <QApplication>
#include <QMessageBox>
#include <git2.h>
int main(int argc, char *argv[])
{
	git_libgit2_init();
    QApplication a(argc, argv);
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
