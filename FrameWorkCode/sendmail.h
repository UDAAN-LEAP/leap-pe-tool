#ifndef SENDMAIL_H
#define SENDMAIL_H

#include <QDialog>

namespace Ui {
class sendMail;
}

class sendMail : public QDialog
{
    Q_OBJECT

public:
    explicit sendMail(QString * send_to , QWidget *parent = nullptr);
    ~sendMail();

private slots:

    void on_send_comment_clicked();

private:
    Ui::sendMail *ui;
    QString * to;
};

#endif // SENDMAIL_H
