#include "globalreplacedialog.h"
#include "ui_globalreplacedialog.h"
#include <QDialogButtonBox>
#include <QDebug>
#include "globalreplacepreview.h"
#include "ui_globalreplacepreview.h"
#include "globalreplaceinformation.h"
#include <QMessageBox>

GlobalReplaceDialog::GlobalReplaceDialog(QVector <QString> replacedWords, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GlobalReplaceDialog)
{

    ui->setupUi(this);

    setWindowTitle("Select the words you want to replace globally");
    displayOriginalList(replacedWords);
    //ui->listWidget->insertItem(,"Replacement Words");
    QObject::connect(ui->listWidget, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(highlightChecked(QListWidgetItem*)));
    QObject::connect(this , SIGNAL(fetchCheckedlist(QMap<QString,QString>,  QVector<int>)), parent, SLOT(globalReplacePreviewfn(QMap<QString,QString>,QVector<int>)));
    QVBoxLayout *listLayout = new QVBoxLayout;
    ui->listWidget->setLayout(listLayout);
    ui->groupBox->setVisible(false);
    ui->groupBox->setLayout(vbox);
    ui->horizontalLayout_2->setAlignment(ui->groupBox, Qt::AlignTop);
    vbox->setAlignment(ui->groupBox, Qt::AlignTop);
    vbox->setSpacing(12);
    vbox->setMargin(12);
   // vbox->setContentsMargins(0, 0, 0, 0);
}

GlobalReplaceDialog::~GlobalReplaceDialog()
{
    replaceInAllFiles_Checkboxes.clear();
    delete vbox;
    delete ui;
}


QMap <QString, QString> GlobalReplaceDialog::getFilteredGlobalReplacementMap(){
    return this->filteredGlobalReplacementMap;
}


void GlobalReplaceDialog::displayOriginalList(QVector <QString> replacedWords){
    //ui->groupBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    for (int i = 0; i < replacedWords.size(); ++i){
        QRegExp sep("\\s*=>*");
        QStringList changedList = replacedWords[i].split(sep);
        //QStringList changedList = replacedWords[i].split(" ");
        ui -> listWidget ->addItem(changedList[0]+ " -> " + changedList[1]);

        // Creating & adding checkboxes in the groupbox
        box = new QCheckBox(this);
        box->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        box->setCheckState(Qt::Unchecked);
        box->setStyleSheet("QCheckBox::indicator:unchecked {border: 0px solid white}");
        box->setEnabled(false);

        vbox->addWidget(box);
        vbox->setAlignment(box, Qt::AlignTop);
        // Inserting addresses of checkboxes in the vector so that we can change the state of the same accordingly
        replaceInAllFiles_Checkboxes.push_back(box);
        // Initializing the states to 0 and pushing them in the vector
        wordSelection_CheckboxesState.push_back(0);
    }

    //! spawn  checkboxes for list
    QListWidgetItem* item = 0;
    for(int i = 0; i < ui ->listWidget->count(); ++i){
        item = ui->listWidget->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
        connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(leftCheckBoxStateChanged(QListWidgetItem*)));
    }
}

void GlobalReplaceDialog::highlightChecked(QListWidgetItem *item){
    if(item->checkState() == Qt::Checked)
        item->setBackgroundColor(QColor("#add8e6"));
    else
        item->setBackgroundColor(QColor("#ffffff"));
}

void GlobalReplaceDialog::on_applyButton_clicked()
{
    QMessageBox replace;
    replace.setWindowTitle("Save and Replace");
    replace.setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint);
    replace.setIcon(QMessageBox::Question);
    replace.setInformativeText("Selected words will be saved and replaced");
    QPushButton *confirmButton = replace.addButton(tr("Confirm"),QMessageBox::AcceptRole);
    replace.exec();
    if(replace.clickedButton() == confirmButton)
    {
      applyButtonIsClicked = true;
      QList<QListWidgetItem *> items = ui->listWidget->findItems(QString("*"), Qt::MatchWrap | Qt::MatchWildcard); //get all items

      foreach (QListWidgetItem *item, items){
          if(item->checkState() == Qt::Checked){
              QRegExp sep("\\s*->*");
              QStringList string = item->text().split(sep);
              //QStringList string = item->text().split(" ");
              this->filteredGlobalReplacementMap[string[0]] = string[1];
         }
     }
      this->close();
    }
}

//void GlobalReplaceDialog::on_cancelButton_clicked()
//{
//    this->close();
//}

/*!
 * \fn "GlobalReplaceDialog::leftCheckBoxStateChanged"
 * \brief "This function is a SLOT which receives signal from listWidget when an item is selected"
 * \param "Address of QListWidgetItem is passed"
 * \return "void"
*/

void GlobalReplaceDialog::leftCheckBoxStateChanged(QListWidgetItem* item)
{
    int itemRow;
    itemRow = ui->listWidget->row(item);
    if (item->checkState() == Qt::Checked)
    {
        wordSelection_CheckboxesState[itemRow] = 1;
        ui->groupBox->setVisible(true);
        ui->groupBox->setMinimumHeight(ui->groupBox_2->height());
        vbox->addStretch(1);
        ui->groupBox->setTitle("Replace in all pages");
        replaceInAllFiles_Checkboxes.at(itemRow)->setEnabled(true);
        replaceInAllFiles_Checkboxes.at(itemRow)->setStyleSheet("color: black;"
                                                                "background-color: white; padding-left:75px");
        ui->groupBox->setStyleSheet("background-color : white;"
                                    "color: black;");
    }
    else if (item->checkState() == Qt::Unchecked)
    {
        ui->groupBox->setMaximumHeight(ui->listWidget->height());
        wordSelection_CheckboxesState[itemRow] = 0;
        replaceInAllFiles_Checkboxes.at(itemRow)->setCheckState(Qt::Unchecked);
        replaceInAllFiles_Checkboxes.at(itemRow)->setEnabled(false);
        replaceInAllFiles_Checkboxes.at(itemRow)->setStyleSheet("QCheckBox::indicator:unchecked {border: 0px solid white}");
        for (int i = 0; i < wordSelection_CheckboxesState.size(); i++)
        {
            if ( wordSelection_CheckboxesState.at(i) == 1 )
            {
                ui->groupBox->setVisible(true);
                return;
            }
        }
        ui->groupBox->setVisible(false);
        ui->groupBox->setTitle("");
    }
}


QVector<int> GlobalReplaceDialog::getStatesOfCheckboxes()
{
    QVector<int> statesOfRightCheckboxes;

    qDebug() << "Before Size of leftCheckbox Vector = " << wordSelection_CheckboxesState.size();
    qDebug() << "Before Size of rightCheckbox Vector = " << replaceInAllFiles_Checkboxes.size();
    for (int i = 0; i < wordSelection_CheckboxesState.size(); i++)
    {
        if (wordSelection_CheckboxesState.at(i) == 1) {
            if (replaceInAllFiles_Checkboxes.at(i)->checkState() == Qt::Checked)
                statesOfRightCheckboxes.push_back(1);
            else
                statesOfRightCheckboxes.push_back(0);
        }
    }
    qDebug() << "Size = " << statesOfRightCheckboxes.size();
    return statesOfRightCheckboxes;
}

bool GlobalReplaceDialog::clicked_applyButton()
{
    return applyButtonIsClicked;
}


void GlobalReplaceDialog::on_previewButton_clicked()
{
    QMap <QString, QString> obj;
    QList<QListWidgetItem *> items = ui->listWidget->findItems(QString("*"), Qt::MatchWrap | Qt::MatchWildcard); //get all items
    QVector<int> allPages;

    foreach (QListWidgetItem *item, items)
    {
        if(item->checkState() == Qt::Checked)
          {
            QStringList string = item->text().split(" ");
            obj[string[0]] = string[2];
          }
    }

    if(obj.size()>0)
    {
      allPages= getStatesOfCheckboxes();
    }

    emit fetchCheckedlist(obj,allPages);
}

void GlobalReplaceDialog::on_pushButton_clicked()
{
    globalReplaceInformation info(this);
    info.exec();
}
