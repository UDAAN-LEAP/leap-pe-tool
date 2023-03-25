#ifndef ADDKEYSHORTCUT_H
#define ADDKEYSHORTCUT_H

#include <QDialog>

namespace Ui {
class addKeyShortcut;
}

class addKeyShortcut : public QDialog
{
    Q_OBJECT

public:
    explicit addKeyShortcut( QString * s, QWidget *parent = nullptr);
    ~addKeyShortcut();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::addKeyShortcut *ui;
    QString * s;
};

#endif // ADDKEYSHORTCUT_H
