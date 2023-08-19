#ifndef RELEASENOTE_MSG_H
#define RELEASENOTE_MSG_H

#include <QDialog>

namespace Ui {
class ReleaseNote_Msg;
}

class ReleaseNote_Msg : public QDialog
{
    Q_OBJECT

public:
    explicit ReleaseNote_Msg(QWidget *parent = nullptr, QString msg = "");
    ~ReleaseNote_Msg();

private:
    Ui::ReleaseNote_Msg *ui;
};

#endif // RELEASENOTE_MSG_H
