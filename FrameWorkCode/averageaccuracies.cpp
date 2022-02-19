/*!
\class AverageAccuracies
\brief This class provides functionality to calculate the avearage accuracies of correctors
       and verifiers made changes in the text respective text files.
*/
#include "averageaccuracies.h"
#include "ui_averageaccuracies.h"
#include "crashlog.h"


/*!
 * \fn AverageAccuracies::AverageAccuracies
 * \brief This constructer opens the file changed in text browser and compares each and every line and then give output of avearage accuracy in the toolbar.
 * \param csvfilepath , avgwordacc , avgcharacc , avgworderrors, avgcharerrors, parent
 */
AverageAccuracies::AverageAccuracies(QString csvfilepath,float avgwordacc, float avgcharacc, int avgworderrors, int avgcharerrors, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AverageAccuracies)
{
    ui->setupUi(this);
    qInstallMessageHandler(crashlog::myMessageHandler);
    setWindowTitle("Average Accuracies");
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
