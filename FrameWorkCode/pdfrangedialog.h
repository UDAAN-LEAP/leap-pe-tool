#ifndef PDFRANGEDIALOG_H
#define PDFRANGEDIALOG_H

#include <QDialog>

namespace Ui {
class PdfRangeDialog;
}

class PdfRangeDialog : public QDialog
{
	Q_OBJECT

public:
	explicit PdfRangeDialog(QWidget *parent = nullptr, int numOfPages = INT_MAX, int maxLimit = 100);

	~PdfRangeDialog();

	bool isOkClicked();

private:
	Ui::PdfRangeDialog *ui;

	int maximumLimit = 100;

	int numberOfPages = INT_MAX;

	bool okClicked = false;

	int startPage = 0;

	int endPage = 0;

public:
	int getStartPage() const;
	int getEndPage() const;
    bool on_checkBox_clicked();

private slots:
	void on_button_Cancel_clicked();
	void on_button_Ok_clicked();
    void on_pushButton_clicked();
};

#endif // PDFRANGEDIALOG_H
