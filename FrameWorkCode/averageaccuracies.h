#ifndef AVERAGEACCURACIES_H
#define AVERAGEACCURACIES_H

#include <QDialog>
#include <QStandardItemModel>
#include <QFile>
#include <QTextStream>

namespace Ui {
class AverageAccuracies;
}

class AverageAccuracies : public QDialog
{
    Q_OBJECT

public:
    explicit AverageAccuracies(QString averageaccuraciescsv, float avgwordacc, float avgcharacc, int avgworderrors, int avgcharerrors, QWidget *parent = nullptr);
    ~AverageAccuracies();

private:
    Ui::AverageAccuracies *ui;
};

#endif // AVERAGEACCURACIES_H
