#ifndef ADDSHORTCUT_H
#define ADDSHORTCUT_H

#include <QDialog>

namespace Ui {
class addShortcut;
}

class addShortcut : public QDialog
{
    Q_OBJECT

public:
    explicit addShortcut(QWidget *parent = nullptr);
    ~addShortcut();

private:
    Ui::addShortcut *ui;
};

#endif // ADDSHORTCUT_H
