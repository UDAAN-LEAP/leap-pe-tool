#include "undoglobalreplace.h"
#include "ui_undoglobalreplace.h"

UndoGlobalReplace::UndoGlobalReplace(QMap<QString, QString> reversedGRMap, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UndoGlobalReplace)
{
    ui->setupUi(this);
    setWindowTitle("Undo Globally Replace Words");
    displayListForUndoOperation(reversedGRMap);
    QObject::connect(ui->listWidget, SIGNAL(itemChanged(QlistWidgetItem*)), this, SLOT(highlightChecked(QListWidgetItem*)));

}

UndoGlobalReplace::~UndoGlobalReplace()
{
    delete ui;
}

void UndoGlobalReplace::displayListForUndoOperation(QMap<QString, QString> listMap)
{
    QMap<QString, QString>::iterator i;
    for (i = listMap.begin(); i != listMap.end(); ++i)
    {
        ui->listWidget->addItem(i.key() + " -> " + i.value());
    }

    QListWidgetItem *item;

    for (int i = 0; i < ui->listWidget->count(); ++i)
    {
        item = ui->listWidget->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
    }
}

void UndoGlobalReplace::highlightChecked(QListWidgetItem *item)
{
    if ( item->checkState() == Qt::Checked )
        item->setBackgroundColor("#add8e6");
    else
        item->setBackgroundColor("#ffffff");
}


bool UndoGlobalReplace::on_applyButton_clicked()
{
    for (int i = 0; i < ui->listWidget->count(); i++)
    {
        QListWidgetItem *item = ui->listWidget->item(i);
        if ( item->checkState() == Qt::Checked )
        {
            QStringList strList = item->text().split(" ");
            this->finalUndoMap[strList[0]] = strList[2];
        }
    }
    this->close();
    return true;
}


void UndoGlobalReplace::on_cancelButton_clicked()
{
    this->close();
}

QMap<QString, QString> UndoGlobalReplace::getFinalUndoMap()
{
    return this->finalUndoMap;
}

