#include "pdfrangedialog.h"
#include "ui_pdfrangedialog.h"

#include <QMessageBox>

PdfRangeDialog::PdfRangeDialog(QWidget *parent, int numOfPages, int maxLimit) :
	QDialog(parent),
	ui(new Ui::PdfRangeDialog)
{
	ui->setupUi(this);
	this->numberOfPages = numOfPages;
	this->maximumLimit = maxLimit;

	ui->spinBox_start->setMinimum(1);
	ui->spinBox_start->setMaximum(numOfPages);
	ui->spinBox_end->setMinimum(1);
	ui->spinBox_end->setMaximum(numOfPages);

	ui->spinBox_start->setValue(1);
	ui->spinBox_end->setValue(1);
}

PdfRangeDialog::~PdfRangeDialog()
{
	delete ui;
}

bool PdfRangeDialog::isOkClicked()
{
	return okClicked;
}

int PdfRangeDialog::getStartPage() const
{
	return startPage;
}

int PdfRangeDialog::getEndPage() const
{
	return endPage;
}

void PdfRangeDialog::on_button_Cancel_clicked()
{
	okClicked = false;

	this->close();
}

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

