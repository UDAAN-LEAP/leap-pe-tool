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


/*!
 * \fn UndoGlobalReplace::UndoGlobalReplace
 * \brief This class is used to show undo global replace window.
 * \param reversedGRMap
 * \param parent
 */
UndoGlobalReplace::UndoGlobalReplace(QMap<QString, QString> reversedGRMap, QWidget *parent,QString mRole,QString path) :
    QDialog(parent),
    ui(new Ui::UndoGlobalReplace)
{
    ui->setupUi(this);
    this->mRole = mRole;
    this->path = path;
    qInstallMessageHandler(crashlog::myMessageHandler);
    setWindowTitle("Undo Globally Replace Words");
    displayListForUndoOperation(reversedGRMap);
    QObject::connect(ui->listWidget, SIGNAL(itemChanged(QlistWidgetItem*)), this, SLOT(highlightChecked(QListWidgetItem*)));
     connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(checkBoxStateChanged(QListWidgetItem*)));
}

/*!
 * \fn UndoGlobalReplace::~UndoGlobalReplace
 * \brief Destructor
 */
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
 * \fn UndoGlobalReplace::on_applyButton_clicked
 * \brief Updates the finalUndoMap variable with checked items only.
 * \return bool
 */
bool UndoGlobalReplace::on_applyButton_clicked()
{
    //!Checking for checked items
    for (int i = 0; i < ui->listWidget->count(); i++)
    {
        QListWidgetItem *item = ui->listWidget->item(i);
        if ( item->checkState() == Qt::Checked )
        {
            QStringList strList = item->text().split(" -> ");
            this->finalUndoMap[strList[0]] = strList[1];
        }
    }
    this->close();
    return true;
}


/*!
 * \fn UndoGlobalReplace::on_cancelButton_clicked
 * \brief Closes the undo global replace dialog.
 */
void UndoGlobalReplace::on_cancelButton_clicked()
{
    this->close();
}

/*!
 * \fn UndoGlobalReplace::getFinalUndoMap
 * \brief returns finalUndoMap variable.
 * \return Final Undo map
 */
QMap<QString, QString> UndoGlobalReplace::getFinalUndoMap()
{
    return this->finalUndoMap;
}

void UndoGlobalReplace::on_pushButton_clicked()
{
    QMap<QString, QString> new_cpair;

        QString filename = path + "/Dicts/" + mRole +"_CPair";
        QFile file(filename);
        QStringList split1;

            if(file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QTextStream out1(&file);
                out1.setCodec("UTF-8");
                QString text;
                while(!out1.atEnd())
                {
                    text = out1.readLine();
                    split1 = text.split('\t');
                   // CPairs = {split1[0],split1[1]};
                    new_cpair[split1[1]]= split1[0];
                }
                file.close();
            }

        displayListForUndoOperation(new_cpair);

}



void UndoGlobalReplace::checkBoxStateChanged(QListWidgetItem* item)
{
    int itemRow;
    itemRow = ui->listWidget->row(item);
    QListWidgetItem* item_ = 0;
    int count_=0;
    for(int j = 0; j < ui ->listWidget->count(); ++j){
        item_ = ui->listWidget->item(j);
        if(item_->checkState() == Qt::Checked){
            count_ ++;
        }
    }
    if(count_ == ui ->listWidget->count()){
        ui->checkBox->setCheckState(Qt::Checked);
    }
    else if( count_ != ui ->listWidget->count() ){
        ui->checkBox->setCheckState(Qt::Unchecked);
    }

    return;

}

void UndoGlobalReplace::on_checkBox_clicked()
{
    QListWidgetItem* item = 0;
    for(int i = 0; i < ui ->listWidget->count(); ++i){
        item = ui->listWidget->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        if(ui->checkBox->checkState() == Qt::Unchecked){
            item->setCheckState(Qt::Unchecked);
        }
        else if(ui->checkBox->checkState() == Qt::Checked){
            item->setCheckState(Qt::Checked);
        }
    }
    return;
}

