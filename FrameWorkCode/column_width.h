#ifndef COLUMN_WIDTH_H
#define COLUMN_WIDTH_H

#include <QDialog>

namespace Ui {
class column_width;
}

class column_width : public QDialog
{
    Q_OBJECT

public:
    explicit column_width(int * presentWidth, QWidget *parent = nullptr);
    ~column_width();

private slots:
    void on_close_clicked();

    void on_change_clicked();

private:
    Ui::column_width *ui;
    int * width;

signals:
    void changed();

};

#endif // COLUMN_WIDTH_H
