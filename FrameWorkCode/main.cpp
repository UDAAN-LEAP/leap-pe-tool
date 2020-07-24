#include "mainwindow.h"
#include <QApplication>
#include <git2.h>
int main(int argc, char *argv[])
{
	git_libgit2_init();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
	git_libgit2_shutdown();
    return a.exec();
}
