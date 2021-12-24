#include "globalreplacedialog.h"
#include "ui_globalreplacedialog.h"
#include <QDialogButtonBox>
#include <QDebug>
#include "globalreplacepreview.h"
#include "ui_globalreplacepreview.h"


GlobalReplaceDialog::GlobalReplaceDialog(QVector <QString> replacedWords, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GlobalReplaceDialog)
{

    ui->setupUi(this);
    setWindowTitle("Select the words you want to replace globally");
    displayOriginalList(replacedWords);
    QObject::connect(ui->listWidget, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(highlightChecked(QListWidgetItem*)));
    QVBoxLayout *listLayout = new QVBoxLayout;
    ui->listWidget->setLayout(listLayout);
    ui->groupBox->setVisible(false);
    ui->groupBox->setLayout(vbox);
    ui->horizontalLayout_2->setAlignment(ui->groupBox, Qt::AlignTop);
    vbox->setAlignment(ui->groupBox, Qt::AlignTop);
    vbox->setSpacing(3);
    vbox->setMargin(0);
    vbox->setContentsMargins(0, 0, 0, 0);
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
    ui->groupBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    for (int i = 0; i < replacedWords.size(); ++i){
        QStringList changedList = replacedWords[i].split(" ");
        ui -> listWidget ->addItem(changedList[1]+ " -> " + changedList[3]);

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
    applyButtonIsClicked = true;
    QList<QListWidgetItem *> items = ui->listWidget->findItems(QString("*"), Qt::MatchWrap | Qt::MatchWildcard); //get all items

    foreach (QListWidgetItem *item, items){
        if(item->checkState() == Qt::Checked){
            QStringList string = item->text().split(" ");
            this->filteredGlobalReplacementMap[string[0]] = string[2];
        }
    }

    this->close();
}

void GlobalReplaceDialog::on_cancelButton_clicked()
{
    this->close();
}


void GlobalReplaceDialog::on_pushButton_clicked()
{
    globalReplacePreview dialog;
    dialog.exec();
}

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
        ui->groupBox->setTitle("Replace in all pages");
        replaceInAllFiles_Checkboxes.at(itemRow)->setEnabled(true);
        replaceInAllFiles_Checkboxes.at(itemRow)->setStyleSheet("QCheckBox::indicator:unchecked {border: 1px solid white}");
        return;
    }
    else if (item->checkState() == Qt::Unchecked)
    {
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

    // Removing elements from replaceInAllFiles_Checkboxes whose word_selection is unchecked
    QVector<QCheckBox *>::iterator it;
    it = replaceInAllFiles_Checkboxes.begin();
    for (int i = 0; i < wordSelection_CheckboxesState.size(); i++)
    {
        if (wordSelection_CheckboxesState.at(i) == 0)
            replaceInAllFiles_Checkboxes.erase(it);
        it++;
    }

    for (int i = 0; i < replaceInAllFiles_Checkboxes.size(); i++)
    {
        if (replaceInAllFiles_Checkboxes.at(i)->checkState() == Qt::Checked)
            statesOfRightCheckboxes.push_back(1);
        else
            statesOfRightCheckboxes.push_back(0);
    }
    return statesOfRightCheckboxes;
}

bool GlobalReplaceDialog::clicked_applyButton()
{
    return applyButtonIsClicked;
}



void GlobalReplaceDialog::on_Preview_clicked()
{

}

void GlobalReplaceDialog::on_uploadButton_clicked()
{
    isUploadFromTSVfile = true;
    applyButtonIsClicked = false;
    this->close();
}

bool GlobalReplaceDialog::uploadFromTSVfile()
{
    return isUploadFromTSVfile;
}

