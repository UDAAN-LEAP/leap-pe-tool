/*!
\class UndoGlobalReplace
\brief UndoGlobalReplace class undo global replaced words.
       It provides list of global replace made and allows to undo them
       at once or by specific selecion.
\sa displayListForUndoOperation(), on_cancelButton_clicked(), highlightChecked(),
    on_applyButton_clicked(), getFinalUndoMap()
*/
#include "undoglobalreplace.h"
#include "ui_undoglobalreplace.h"
#include "crashlog.h"

/*! \class UndoGlobalReplace
 *  \brief This class is used to show undo global replace window. Refer to Undo Global Replace Documentation
 *  In mainwindow class for more details.
 */

UndoGlobalReplace::UndoGlobalReplace(QMap<QString, QString> reversedGRMap, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UndoGlobalReplace)
{
    ui->setupUi(this);
    qInstallMessageHandler(crashlog::myMessageHandler);
    setWindowTitle("Undo Globally Replace Words");
    displayListForUndoOperation(reversedGRMap);
    QObject::connect(ui->listWidget, SIGNAL(itemChanged(QlistWidgetItem*)), this, SLOT(highlightChecked(QListWidgetItem*)));

}


UndoGlobalReplace::~UndoGlobalReplace()
{
    delete ui;
}

/*!
* \fn UndoGlobalReplace::displayListForUndoOperation
* \brief Shows list of global replaced words for undo operation.
* \param listMap
*/
void UndoGlobalReplace::displayListForUndoOperation(QMap<QString, QString> listMap)
{
    QMap<QString, QString>::iterator i;
    //!Adding all items in list
    for (i = listMap.begin(); i != listMap.end(); ++i)
    {
        ui->listWidget->addItem(i.key() + " -> " + i.value());
    }

    QListWidgetItem *item;
   //!Setting up checkbox for all items
    for (int i = 0; i < ui->listWidget->count(); ++i)
    {
        item = ui->listWidget->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
    }
}


/*!
* \fn UndoGlobalReplace::highlightChecked
* \brief Highlights checked items from the list.
* \param item
*/
void UndoGlobalReplace::highlightChecked(QListWidgetItem *item)
{
    if ( item->checkState() == Qt::Checked )
        item->setBackgroundColor("#add8e6");
    else
        item->setBackgroundColor("#ffffff");
}


/*!
 * \fn UndoGlobalReplace::on_applyButton_clicked()
 * \brief Updates the finalUndoMap variable with checked items only.
 */
bool UndoGlobalReplace::on_applyButton_clicked()
{
    //!Checking for checked items
    for (int i = 0; i < ui->listWidget->count(); i++)
    {
        QListWidgetItem *item = ui->listWidget->item(i);
        if ( item->checkState() == Qt::Checked )
        {
            QStringList strList = item->text().split(" ");
            this->finalUndoMap[strList[0]] = strList[3];
        }
    }
    this->close();
    return true;
}


/*!
* \fn UndoGlobalReplace::on_cancelButton_clicked()
* \brief Closes the undo global replace dialog.
*/
void UndoGlobalReplace::on_cancelButton_clicked()
{
    this->close();
}

/*!
* \fn UndoGlobalReplace::getFinalUndoMap()
* \brief returns finalUndoMap variable.
*/
QMap<QString, QString> UndoGlobalReplace::getFinalUndoMap()
{
    return this->finalUndoMap;
}
