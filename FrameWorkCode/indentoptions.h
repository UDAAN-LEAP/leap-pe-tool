#ifndef INDENTOPTIONS_H
#define INDENTOPTIONS_H

#include <QDialog>

namespace Ui {
class indentOptions;
}

class indentOptions : public QDialog
{
    Q_OBJECT

public:
    explicit indentOptions(QWidget *parent = nullptr, int * left = nullptr, int * right = nullptr);
    ~indentOptions();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::indentOptions *ui;
    int * left;
    int * right;
};

#endif // INDENTOPTIONS_H
