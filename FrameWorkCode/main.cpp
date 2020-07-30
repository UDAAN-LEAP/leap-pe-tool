#include "mainwindow.h"
#include <QApplication>
#include <git2.h>
int main(int argc, char *argv[])
{
	git_libgit2_init();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
	int retn = a.exec();
	git_libgit2_shutdown();
    return retn;
}
