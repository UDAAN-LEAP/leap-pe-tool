#include "globalreplacedialog.h"
#include "ui_globalreplacedialog.h"
#include <QDialogButtonBox>
#include <QDebug>
#include <string>

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


void GlobalReplaceDialog::displayOriginalList(QVector <QString> replacedWords){

    for (int i = 0; i < replacedWords.size(); ++i){
        QString si=replacedWords.value(i);
        std::string str=si.toStdString();
        std::string str1=str.substr(0,str.find("=>"));          //Original String
        int pos=str.find("=>");
        std::string str2=str.substr(pos+2);                     //Replaced String
        QString s1=QString::fromStdString(str1);
        QString s2=QString::fromStdString(str2);
        ui -> listWidget ->addItem(s1+ " -> " + s2);
    }

    //! spawn  checkboxes for list
    QListWidgetItem* item = 0;
    for(int i = 0; i < ui ->listWidget->count(); ++i){
        item = ui->listWidget->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
    }

}

void GlobalReplaceDialog::highlightChecked(QListWidgetItem *item){
    if(item->checkState() == Qt::Checked)
        item->setBackgroundColor(QColor("#add8e6"));
    else
        item->setBackgroundColor(QColor("#ffffff"));
}

bool GlobalReplaceDialog::on_applyButton_clicked()
{
    QList<QListWidgetItem *> items = ui->listWidget->findItems(QString("*"), Qt::MatchWrap | Qt::MatchWildcard); //get all items

    foreach (QListWidgetItem *item, items){
        if(item->checkState() == Qt::Checked){
            QString si=item->text();
            std::string str=si.toStdString();
            std::string str1=str.substr(0,str.find("=>"));          //Original String
            int pos=str.find("=>");
            std::string str2=str.substr(pos+2);                     //Replaced String
            QString s1=QString::fromStdString(str1);
            QString s2=QString::fromStdString(str2);
            this->filteredGlobalReplacementMap[s1] = s2;
        }

    }

    this->close();
    return true;

}

void GlobalReplaceDialog::on_cancelButton_clicked()
{
    this->close();
}

