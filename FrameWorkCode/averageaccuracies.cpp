#include "averageaccuracies.h"
#include "ui_averageaccuracies.h"

AverageAccuracies::AverageAccuracies(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AverageAccuracies)
{
    ui->setupUi(this);
}

AverageAccuracies::~AverageAccuracies()
{
    delete ui;
}
