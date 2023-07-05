#include "pdfrangedialog.h"
#include "ui_pdfrangedialog.h"

#include <QMessageBox>

/*!
 * \fn PdfRangeDialog::PdfRangeDialog
 * \brief This class is responsible for showing the PDF range dialog whose maximum value can be restricted by specifying the maxLimit parameter in the constructor
 * \param parent
 * \param numOfPages
 * \param maxLimit
 */
PdfRangeDialog::PdfRangeDialog(QWidget *parent, int numOfPages, int maxLimit) :
    QDialog(parent),
    ui(new Ui::PdfRangeDialog)
{
    ui->setupUi(this);
    setWindowTitle("Download as PDF");
    this->numberOfPages = numOfPages;
    this->maximumLimit = maxLimit;

    ui->spinBox_start->setMinimum(1);
    ui->spinBox_start->setMaximum(numOfPages);
    ui->spinBox_end->setMinimum(1);
    ui->spinBox_end->setMaximum(numOfPages);

    ui->spinBox_start->setValue(1);
    ui->spinBox_end->setValue(1);
}

/*!
 * \fn PdfRangeDialog::~PdfRangeDialog
 * \brief Deletes the UI object(s)
 */
PdfRangeDialog::~PdfRangeDialog()
{
    delete ui;
}

/*!
 * \fn PdfRangeDialog::isOkClicked
 * \brief Returns true if ok button is clicked and false otherwise.
 * \return bool okClicked
 */
bool PdfRangeDialog::isOkClicked()
{
    return okClicked;
}

/*!
 * \fn PdfRangeDialog::getStartPage
 * \brief It returns the start page from which the PDF should be printed.
 * \return int startPage
 */
int PdfRangeDialog::getStartPage() const
{
    return startPage;
}

/*!
 * \fn PdfRangeDialog::getStartPage
 * \brief It returns the end page to which the PDF should be printed.
 * \return int startPage
 */
int PdfRangeDialog::getEndPage() const
{
    return endPage;
}

/*!
 * \fn PdfRangeDialog::on_button_Cancel_clicked
 * \brief Marks the okClicked flag as false
 */
void PdfRangeDialog::on_button_Cancel_clicked()
{
    okClicked = true;

    this->close();
}

/*!
 * \fn PdfRangeDialog::on_button_Ok_clicked
 * \brief Gets the start page and end page from the spinBox widget and stores them in the data members
 */
void PdfRangeDialog::on_button_Ok_clicked()
{
    int sPage = ui->spinBox_start->value();
    int ePage = ui->spinBox_end->value();
    if (sPage > ePage) {
        QMessageBox::warning(this, "Range error", "Page number of start page is greater than that of end page number", QMessageBox::Ok, QMessageBox::Ok);
        return;
    } else if (ePage - sPage > maximumLimit) {
        QMessageBox::warning(this, "Maximum Limit exceeded", "Maximum range is " + QString::number(maximumLimit), QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
    startPage = sPage;
    endPage = ePage;
    okClicked = true;

    this->close();
}

/*!
 * \brief PdfRangeDialog::on_checkBox_clicked
 * \return
 * \details Checks whether the user wants to print the empty pages in pdf or not.
 */
bool PdfRangeDialog::on_checkBox_clicked()
{
    if(ui->checkBox->checkState() == Qt::Checked)
        return true;
    return false;
}

void PdfRangeDialog::on_pushButton_clicked()
{
    okClicked=false;
        this->close();
}

