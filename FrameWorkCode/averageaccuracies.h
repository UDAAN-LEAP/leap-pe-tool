#ifndef AVERAGEACCURACIES_H
#define AVERAGEACCURACIES_H

#include <QDialog>

namespace Ui {
class AverageAccuracies;
}

class AverageAccuracies : public QDialog
{
    Q_OBJECT

public:
    explicit AverageAccuracies(QWidget *parent = nullptr);
    ~AverageAccuracies();

private:
    Ui::AverageAccuracies *ui;
};

#endif // AVERAGEACCURACIES_H
