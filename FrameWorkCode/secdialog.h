#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QString html,QString src,QString path,QWidget *parent = nullptr);
    ~SecDialog();

public slots:
    void on_pushButton_4_clicked();

    QString on_pushButton_3_clicked();

    QString on_pushButton_clicked();

    QString on_push_clicked();

private:
    Ui::SecDialog *ui;
};

#endif // SECDIALOG_H
