/*! \class GlobalReplaceDialog
 *
 *  \brief This class is used to handle the gui functionality of global replace dialog box
 *         Whenever user saves the page and makes changes to words, this dialog box will appear and
 *         show the words which can be globally replaced by the user.
 */

#include "globalreplacedialog.h"
#include "ui_globalreplacedialog.h"
#include <QDialogButtonBox>
#include <QDebug>
#include "globalreplacepreview.h"
#include "ui_globalreplacepreview.h"
#include "globalreplaceinformation.h"
#include <QMessageBox>
#include "crashlog.h"

/*!
 * \fn GlobalReplaceDialog::GlobalReplaceDialog
 * \brief In this constructor function we initialize the UI and setup the layout, margins, alignment,etc.
 * \param replacedWords,parent
 */
GlobalReplaceDialog::GlobalReplaceDialog(QVector <QString> replacedWords, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GlobalReplaceDialog)
{
    ui->setupUi(this);
    qInstallMessageHandler(crashlog::myMessageHandler);
    setWindowTitle("Select the words you want to replace globally");
    displayOriginalList(replacedWords);
    //ui->listWidget->insertItem(,"Replacement Words");


    QObject::connect(ui->listWidget, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(highlightChecked(QListWidgetItem*)));

    //! Whenever user clicks on global replace preview, the words that are checked are fetched and those
    //! words are passed to show global replace preview.
    QObject::connect(this , SIGNAL(fetchCheckedlist(QMap<QString,QString>,  QVector<int>)), parent, SLOT(globalReplacePreviewfn(QMap<QString,QString>,QVector<int>)));

    //! Set layout, margins, alignment
    QVBoxLayout *listLayout = new QVBoxLayout;
    ui->listWidget->setLayout(listLayout);
    ui->groupBox->setVisible(false);
//    ui->groupBox->setLayout(vbox);
//    ui->horizontalLayout_2->setAlignment(ui->groupBox, Qt::AlignTop);
    ui->ReplaceInAllPagesListWidget->setLayout(listLayout);
//    vbox->setAlignment(ui->groupBox, Qt::AlignTop);
//    vbox->setSpacing(12);
//    vbox->setMargin(12);
   // vbox->setContentsMargins(0, 0, 0, 0);
}

/*!
 * \brief GlobalReplaceDialog::~GlobalReplaceDialog
 */
GlobalReplaceDialog::~GlobalReplaceDialog()
{
    rightPaneCheckboxes.clear();
//    delete vbox;
    delete ui;
}

/*!
 * \fn GlobalReplaceDialog::getFilteredGlobalReplacementMap
 * \brief Returns the processed globalreplacement map which contain the key value pairs of word before
 * replacement and after it is replaced.
 */
QMap <QString, QString> GlobalReplaceDialog::getFilteredGlobalReplacementMap(){
    return this->filteredGlobalReplacementMap;
}

/*!
 * \fn GlobalReplaceDialog::displayOriginalList
 * \brief This function is used to show the checkboxes for words that can be globally replaced in
 *        list format.
 */
void GlobalReplaceDialog::displayOriginalList(QVector <QString> replacedWords)
{
    //ui->groupBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    //! We get words in the format old Word => new Word. (See editdistance.cpp for more info)
    //! We run the loop of the list of such strings and we separate them using QRegExp and add
    //! to the widget.
    //int flag_save = 0;
    for (int i = 0; i < replacedWords.size(); ++i){
        QRegExp sep("\\s*=>*");
        QStringList changedList = replacedWords[i].split(sep);
        //QStringList changedList = replacedWords[i].split(" ");
        ui->listWidget ->addItem(changedList[0]+ " -> " + changedList[1]);
        QString test_word = changedList[0];
                //qDebug ()<<test_word<<test_word.size();
               /*for(int z = 0;z<test_word.size();z++){
                    if(test_word[z] == " ")
                        flag_save = 1;
                }*/
        //! Creating & adding checkboxes in the groupbox
//        box = new QCheckBox(this);
//        box->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
//        box->setCheckState(Qt::Unchecked);
//        box->setStyleSheet("QCheckBox::indicator:unchecked {border: 0px solid white}");
//        box->setEnabled(false);

//        vbox->addWidget(box);
//        vbox->setAlignment(box, Qt::AlignTop);
        //! Inserting addresses of checkboxes in the vector so that we can change the state of the same accordingly
//        replaceInAllFiles_Checkboxes.push_back(box);
        //! Initializing the states to 0 and pushing them in the vector
        leftPaneCheckboxesStates.push_back(0);

        // NEW IMPLEMENTATION OF RIGHT PANE USING QListWidget
        ui->ReplaceInAllPagesListWidget->addItem("");
        QListWidgetItem* item = ui->ReplaceInAllPagesListWidget->item(i);
        rightPaneCheckboxes.push_back(item);
    }
    /*if(flag_save == 1){
        QMessageBox::information(0, "Warning!", "Using this cpair file for global replace may cause corruption");
    }*/

    //! spawn  checkboxes for list
    QListWidgetItem *item = 0, *rightPaneListItem = 0;
    Qt::ItemFlags flags;
    for(int i = 0; i < ui ->listWidget->count(); ++i){
        item = ui->listWidget->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);

        rightPaneListItem = ui->ReplaceInAllPagesListWidget->item(i);
        rightPaneListItem->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        rightPaneListItem->setCheckState(Qt::Unchecked);

        flags = rightPaneListItem->flags();
        flags = flags & (~(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable));
        rightPaneListItem->setFlags(flags);
    }
    //! Whenever user checks the word for global replace, the adjacent checkbox
    //! (to ask user whether to replace in all pages or only unedited pages) becomes visible.
    //! The connect function does the necessary syncing.

    connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(leftCheckBoxStateChanged(QListWidgetItem*)));
}


/*!
 * \fn GlobalReplaceDialog::highlightChecked
 * \brief We change the color of list to lightblue when it is checked and when it is unchecked.
 * This is done to make the GUI elegant.
 */
void GlobalReplaceDialog::highlightChecked(QListWidgetItem *item){
    if(item->checkState() == Qt::Checked)
        item->setBackgroundColor(QColor("#add8e6"));
    else
        item->setBackgroundColor(QColor("#ffffff"));
}

/*!
 * \fn GlobalReplaceDialog::on_applyButton_clicked
 * \brief Defines what happens when user clicks on apply to global replace.
 *        It puts the words in the global replace map and applies global replace.
 */
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
              QRegExp sep("\\s* -> *");
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
 * \fn GlobalReplaceDialog::uncheckedItemsList
 * \brief This function returns the map of unchecked items list.
 * \param item
 * \return
 */
QMap <QString, QString> GlobalReplaceDialog::uncheckedItemsList()
{
    //! We first get the list of all checkbox item labels.
    QList<QListWidgetItem *> items = ui->listWidget->findItems(QString("*"), Qt::MatchWrap | Qt::MatchWildcard);

    //! Then we loop through this list and get unchecked items
    //! Then we separate key from the value i.e (oldword and newWord) and we add that to the map of
    //! unchecked items.
    foreach (QListWidgetItem *item, items){
    if(item->checkState() == Qt::Unchecked){
        QRegExp sep("\\s* -> *");
        QStringList string = item->text().split(sep);
        this->uncheckedItemsListMap[string[0]] = string[1];
       }
   }
    //! We return this map to the calling function.
    return this->uncheckedItemsListMap;
}


/*!
 * \fn "GlobalReplaceDialog::leftCheckBoxStateChanged"
 * \brief "This function is a SLOT which receives signal from listWidget when an item is selected"
 *
 * \brief This function is called by QT whenever user checks or unchecks the left hand side checkbox
 * in the global replace window.
 *
 * \brief If user clicks on lecft checkbox, then right hand side checkbox gets visible.
 * \param "Address of QListWidgetItem is passed"
 * \return "void"
*/

void GlobalReplaceDialog::leftCheckBoxStateChanged(QListWidgetItem* item)
{
    int itemRow;
    itemRow = ui->listWidget->row(item);
    Qt::ItemFlags flags = ui->ReplaceInAllPagesListWidget->item(itemRow)->flags();

    //! This enables the right hand side pane, which was invisible when no words were checked.
    //! Enables the checkbox for the respective left hand side word checkbox checked.
    if (item->checkState() == Qt::Checked)
    {
        leftPaneCheckboxesStates[itemRow] = 1;
        ui->groupBox->setVisible(true);
        flags = flags | Qt::ItemIsEnabled | Qt::ItemIsUserCheckable;
        ui->ReplaceInAllPagesListWidget->item(itemRow)->setFlags(flags);

//        ui->groupBox->setMinimumHeight(28*ui ->listWidget->count());
        //ui->groupBox->setMinimumHeight(ui->listWidget->height());
        //ui->groupBox->setMinimumHeight(ui->groupBox_2->height());
//        vbox->addStretch(1);
//        ui->groupBox->setTitle("Replace in all pages");
//        replaceInAllFiles_Checkboxes.at(itemRow)->setEnabled(true);
//        replaceInAllFiles_Checkboxes.at(itemRow)->setStyleSheet("color: black; background-color: white; padding-left:75px");
//        ui->groupBox->setStyleSheet("background-color : white; color: black;");
    }
    //! If the word on the left side is unchecked then the right checkbox gets disabled.
    else if (item->checkState() == Qt::Unchecked)
    {
//        ui->groupBox->setMaximumHeight(ui->listWidget->height());
        leftPaneCheckboxesStates[itemRow] = 0;

//        replaceInAllFiles_Checkboxes.at(itemRow)->setCheckState(Qt::Unchecked);
//        replaceInAllFiles_Checkboxes.at(itemRow)->setEnabled(false);
//        replaceInAllFiles_Checkboxes.at(itemRow)->setStyleSheet("QCheckBox::indicator:unchecked {border: 0px solid white}");

        flags = flags & (~(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable));
        ui->ReplaceInAllPagesListWidget->item(itemRow)->setFlags(flags);
        ui->ReplaceInAllPagesListWidget->item(itemRow)->setCheckState(Qt::Unchecked);
        //! However if some other word is checked then we still keep the right hand side groupbox pane
        //! visible, only those words are not selected their right hand side checkbox is disabled.
        //! Thus we check if some other checkbox is checked or not?? If yes the groupbox is visible else
        //! invisible
        for (int i = 0; i < leftPaneCheckboxesStates.size(); i++)
        {
            if ( leftPaneCheckboxesStates.at(i) == 1 )
            {
                ui->groupBox->setVisible(true);
                return;
            }
        }
        ui->groupBox->setVisible(false);
//        ui->groupBox->setTitle("");
    }
}

/*!
 * \fn GlobalReplaceDialog::getStatesOfCheckboxes
 * \brief This gets the state of checkboxes at the right hand side of the pane and returns the vector.
 */
QVector<int> GlobalReplaceDialog::getStatesOfCheckboxes()
{
    QVector<int> statesOfRightCheckboxes;

    //! Loop through all checkboxes, if left hand side checkboxed is checked
    //! and right hand side of checkbox is also checked then push 1 else push 0
    for (int i = 0; i < leftPaneCheckboxesStates.size(); i++)
    {
        if (leftPaneCheckboxesStates.at(i) == 1) {
            if (rightPaneCheckboxes.at(i)->checkState() == Qt::Checked)
                statesOfRightCheckboxes.push_back(1);
            else
                statesOfRightCheckboxes.push_back(0);
        }
    }
    return statesOfRightCheckboxes;
}


/*!
 * \fn GlobalReplaceDialog::clicked_applyButton
 * \brief Returns if apply button is clicked
 */
bool GlobalReplaceDialog::clicked_applyButton()
{
    return applyButtonIsClicked;
}

/*!
 * \fn GlobalReplaceDialog::on_previewButton_clicked
 * \brief Defines what happens when preview button is clicked. Gets the checkboxes are clicked and
 * emits a signal which causes preview dialog to show up.
 */
void GlobalReplaceDialog::on_previewButton_clicked()
{
    QMap <QString, QString> obj;
    QList<QListWidgetItem *> items = ui->listWidget->findItems(QString("*"), Qt::MatchWrap | Qt::MatchWildcard); //get all items
    QVector<int> allPages;
    //! Loops through each item and splits the string such that when oldword newword is the format of
    //! the string then we get key as oldword and value as new word.
    foreach (QListWidgetItem *item, items)
    {
        if(item->checkState() == Qt::Checked)
          {
            QStringList string = item->text().split(" ");
            obj[string[0]] = string[2];
          }
    }

    //! This will check if the words are selected to be replaced in unedited pages or all pages as well
    //! This data is stored in vector.
    if(obj.size()>0)
    {
      allPages= getStatesOfCheckboxes();
    }
    //! Once the signal is emitted, it _implicitly_ calls the global replace preview function and makes the
    //! dialog box show up. All pages vector defines whether the preview function show preview for all pages
    //! for that particular word or just unedited pages.
    emit fetchCheckedlist(obj,allPages);
}

/*!
 * \fn GlobalReplaceDialog::on_pushButton_clicked
 * \brief This opens the global replace information dialog box.
 * Whenever users click on the 𝒊 symbol they can see what each button does in global replace,
 * thus better equipped to use the feature.
 */
void GlobalReplaceDialog::on_pushButton_clicked()
{
    globalReplaceInformation info(this);
    info.exec();
}

void GlobalReplaceDialog::on_checkBox_stateChanged(int arg1)
{
    QListWidgetItem* item = 0;
    for(int i = 0; i < ui ->listWidget->count(); ++i){
        item = ui->listWidget->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        if(arg1 == 2){
        item->setCheckState(Qt::Checked);
        leftCheckBoxStateChanged(item);
        }
        if(arg1 == 0){
        item->setCheckState(Qt::Unchecked);
        leftCheckBoxStateChanged(item);
        }
    }
}

void GlobalReplaceDialog::on_checkBox_2_stateChanged(int arg1)
{
    QListWidgetItem* item = 0;
    Qt::ItemFlags flags;

    for(int i = 0; i < ui ->ReplaceInAllPagesListWidget->count(); ++i){
        item = ui->ReplaceInAllPagesListWidget->item(i);
        flags = item->flags();
        if(flags == (flags | Qt::ItemIsUserCheckable)){
        if(arg1 == 2){
        item->setCheckState(Qt::Checked);
        }
        if(arg1 == 0){
        item->setCheckState(Qt::Unchecked);
        }
    }
}
}
