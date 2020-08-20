#ifndef DIACRITICSVIEW_H
#define DIACRITICSVIEW_H

#include <QDialog>

namespace Ui {
class DiacriticsView;
}

class DiacriticsView : public QDialog
{
    Q_OBJECT

public:
    explicit DiacriticsView(QWidget *parent = 0);
    ~DiacriticsView();

private slots:
    void on_copyButton_clicked();

private:
    Ui::DiacriticsView *ui;
};

#endif // DIACRITICSVIEW_H
