#ifndef PASSKEY_H
#define PASSKEY_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class PassKey;
}

class PassKey : public QDialog
{
    Q_OBJECT

public:
    explicit PassKey(QWidget *parent = nullptr);
    ~PassKey();

private slots:
    void on_pushButton_clicked();

private:
    Ui::PassKey *ui;
    MainWindow *mwindow;
};

#endif // PASSKEY_H
