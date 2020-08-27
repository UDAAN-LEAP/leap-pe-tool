#ifndef LOGINPAGEVIEW_H
#define LOGINPAGEVIEW_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class LoginPageView;
}

class LoginPageView : public QDialog
{
    Q_OBJECT

public:
    explicit LoginPageView(QWidget *parent = 0);
    ~LoginPageView();

private slots:
    void on_loginButton_clicked();

private:
    Ui::LoginPageView *ui;
    MainWindow *mwindow;
};

#endif // LOGINPAGEVIEW_H
