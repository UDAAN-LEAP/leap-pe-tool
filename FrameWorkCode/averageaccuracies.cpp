#include "averageaccuracies.h"
#include "ui_averageaccuracies.h"

AverageAccuracies::AverageAccuracies(QString csvfilepath,float avgwordacc, float avgcharacc, int avgworderrors, int avgcharerrors, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AverageAccuracies)
{
    ui->setupUi(this);
    
    QStandardItemModel *model = new QStandardItemModel;

    QFile file(csvfilepath);
    if (file.open(QIODevice::ReadOnly)) {

        int lineindex = 0;                     // file line counter
        QTextStream in(&file);                 // read to text stream

        while (!in.atEnd()) {

            // read one line from textstream(separated by "\n")
            QString fileLine = in.readLine();

            // parse the read line into separate pieces(tokens) with "," as the delimiter
            QStringList lineToken = fileLine.split(",", QString::SkipEmptyParts);

            // load parsed data to model accordingly
            for (int j = 0; j < lineToken.size(); j++) {
                QString value = lineToken.at(j);
                QStandardItem *item = new QStandardItem(value);
                model->setItem(lineindex, j, item);

            }

            lineindex++;
        }

        file.close();
    }
    ui->tableView->setModel(model);
    ui->avgworderrors->setText(QString::number(avgworderrors));
    ui->avgcharerrors->setText(QString::number(avgcharerrors));
    ui->avgwordacc->setText(QString::number(avgwordacc));
    ui->avgcharacc->setText(QString::number(avgcharacc));

}

AverageAccuracies::~AverageAccuracies()
{
    delete ui;
}
