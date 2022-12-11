#include "progressbardialog.h"
#include "ui_progressbardialog.h"

/*!
 * \fn ProgressBarDialog::ProgressBarDialog
 * \brief Constructor of this class which setups the UI and initializes the widgets' values.
 * \param parent
 */
ProgressBarDialog::ProgressBarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgressBarDialog)
{
    ui->setupUi(this);
    ui->description->setReadOnly(true);
    ui->progressBar->setValue(0);
}

/*!
 * \fn ProgressBarDialog::~ProgressBarDialog
 * \brief Deletes the UI object(s).
 */
ProgressBarDialog::~ProgressBarDialog()
{
    delete ui;
}

/*!
 * \fn ProgressBarDialog::setMessage
 * \brief Sets the message to the string passed.
 * \param message
 */
void ProgressBarDialog::setMessage(QString message)
{
    ui->description->setText(message);
}

/*!
 * \fn ProgressBarDialog::setPercentage
 * \brief Sets the percentage to the value passed.
 * \param percentage
 */
void ProgressBarDialog::setPercentage(int percentage)
{
    ui->progressBar->setValue(percentage);
}
