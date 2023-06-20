#ifndef TUTORIAL_H
#define TUTORIAL_H

#include <QDialog>

namespace Ui {
class tutorial;
}

class tutorial : public QDialog
{
    Q_OBJECT

public:
    explicit tutorial(QWidget *parent = nullptr);
    ~tutorial();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::tutorial *ui;
};

#endif // TUTORIAL_H
