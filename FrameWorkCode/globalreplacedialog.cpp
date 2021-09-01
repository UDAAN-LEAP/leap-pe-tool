#include "globalreplacedialog.h"
#include "ui_globalreplacedialog.h"
#include <QDialogButtonBox>
#include <QDebug>

GlobalReplaceDialog::GlobalReplaceDialog(QVector <QString> replacedWords, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GlobalReplaceDialog)
{

    ui->setupUi(this);
    setWindowTitle("Select the words you want to replace globally");
    displayOriginalList(replacedWords);
    QObject::connect(ui->listWidget, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(highlightChecked(QListWidgetItem*)));


}

GlobalReplaceDialog::~GlobalReplaceDialog()
{
    delete ui;
}


QMap <QString, QString> GlobalReplaceDialog::getFilteredGlobalReplacementMap(){
    return this->filteredGlobalReplacementMap;
}

/*!
 * \fn GlobalReplaceDialog::displayOriginalList
 * \brief Adds the list of Global Cpairs to the listWidget(UI) and spawns checkboxes
 * \param replacedWords
 */
void GlobalReplaceDialog::displayOriginalList(QVector <QString> replacedWords){

    for (int i = 0; i < replacedWords.size(); ++i){
        QStringList changedList = replacedWords[i].split(" ");
        ui -> listWidget ->addItem(changedList[1]+ " -> " + changedList[3]);
    }

    //! spawn  checkboxes for list
    QListWidgetItem* item = 0;
    for(int i = 0; i < ui ->listWidget->count(); ++i){
        item = ui->listWidget->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
    }

}

/*!
 * \fn GlobalReplaceDialog::highlightChecked
 * \brief Sets background color to blue if the check box for that item is checked in the dialog
 * \param item
 */
void GlobalReplaceDialog::highlightChecked(QListWidgetItem *item){
    if(item->checkState() == Qt::Checked)
        item->setBackgroundColor(QColor("#add8e6"));
    else
        item->setBackgroundColor(QColor("#ffffff"));
}

/*!
 * \fn GlobalReplaceDialog::on_applyButton_clicked
 * \return bool
 */
bool GlobalReplaceDialog::on_applyButton_clicked()
{
    QList<QListWidgetItem *> items = ui->listWidget->findItems(QString("*"), Qt::MatchWrap | Qt::MatchWildcard); //get all items

    foreach (QListWidgetItem *item, items){
        if(item->checkState() == Qt::Checked){
            QStringList string = item->text().split(" ");
            this->filteredGlobalReplacementMap[string[0]] = string[2];
        }

    }

    this->close();
    return true;

}

/*!
 * \fn GlobalReplaceDialog::on_cancelButton_clicked
 * \brief Closes the Global replace dialog(UI) if cancel button is clicked
 */
void GlobalReplaceDialog::on_cancelButton_clicked()
{
    this->close();
}
