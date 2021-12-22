#include "uploaddialogbox.h"
#include "ui_uploaddialogbox.h"

uploadDialogBox::uploadDialogBox(QMap<QString, QString> filteredGblReplacementMap, QVector<bool> stateOfReplaceInAllPages, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::uploadDialogBox)
{
    ui->setupUi(this);
    setWindowTitle("Upload to CSV File");

    // Displaying the list widget items
    QMap<QString, QString>::iterator it;
    QListWidgetItem *item = NULL;
    for (it = filteredGblReplacementMap.begin(); it != filteredGblReplacementMap.end(); it++)
    {
        ui->listWidget->addItem(it.key() + " -> " + it.value());
    }
    // Adding checkboxes for replace in all pages
    for (int i = 0; i < ui->listWidget->count(); i++)
    {
        item = ui->listWidget->item(i);
        item->setFlags(Qt::NoItemFlags);
        if (stateOfReplaceInAllPages.at(i) == true)
            item->setCheckState(Qt::Checked);
        else
            item->setCheckState(Qt::Unchecked);
    }
}

uploadDialogBox::~uploadDialogBox()
{
    delete ui;
}

void uploadDialogBox::on_cancelButton_clicked()
{
    saveCSVfile = false;
    this->close();
}


void uploadDialogBox::on_okButton_clicked()
{
    saveCSVfile = true;
    this->close();
}

bool uploadDialogBox::saveInCSVfile()
{
    return saveCSVfile;
}


