/*!
 * \class globalReplaceInformation::globalReplaceInformation()
 * This constructor function is used to initialize dialog box for Global Replace Information
 *
 * Global Replace is a feature in our tool which we invoke after a user has changed a word and saved the file,
 * this feature allows the change made to be applied globally i.e in all pages of the project.
 *
 * When users are using this feature, initially they may not be aware of the terminology.
 *
 * Thus when they click on the 𝒊 symbol they can see what each button does, thus better equipped to use the feature.
 *
 */
#include "globalreplaceinformation.h"
#include "ui_globalreplaceinformation.h"
#include <qtablewidget.h>
#include "crashlog.h"


/*!
 * \fn globalReplaceInformation::globalReplaceInformation
 * \brief This is the constructor of this class which sets the default size of rows and columns of the tableWidget.
 * \param parent
 */
globalReplaceInformation::globalReplaceInformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::globalReplaceInformation)
{
    ui->setupUi(this);
    qInstallMessageHandler(crashlog::myMessageHandler);
    this->setFixedSize(1080,230);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
}

/*!
 * \fn globalReplaceInformation::~globalReplaceInformation
 * \brief Destructor
 */
globalReplaceInformation::~globalReplaceInformation()
{
    delete ui;
}
