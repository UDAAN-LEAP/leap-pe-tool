/*!
  \class DiffView
  \brief The DiffView class compares and shows the changes between verifier,corrector and OCR text.
  Once the verifier rectified the correctors text. It is important to show the changes to corrector to
  avoid future errors. The DiffView class compares the OCR, corrector and verifier text and it displays
  the percentage of changes and accuracy of OCR text.
   \sa diff_main(), diff_prettyHtml()
*/

#include "DiffView.h"
#include "ui_DiffView.h"
#include "diff_match_patch.h"
DiffView::DiffView( QString &ocrtext,  QString &interntext,  QString &verifiertext,const QString &InternAcc, const QString &VerifierAcc, const QString &OcrAcc, QWidget *parent)
	: QMainWindow(parent)
{
    //! Open a new DiffView window
    ui = new Ui::DiffView();
	ui->setupUi(this);

    //! set DiffView title
    setWindowTitle("Verifier Output Difference");

    //! Get corrector output text
    QTextDocument doc;
    doc.setHtml(interntext);
    interntext = doc.toPlainText();

    //! Get OCR text
    doc.setHtml(ocrtext);
    ocrtext = doc.toPlainText();

    //! Get verified text
    doc.setHtml(verifiertext);
    verifiertext = doc.toPlainText();

    /*!
         * \cite diff_main() inherited from diff_match_path.cpp computes
         * the differences between two text and returns linked list
         * of Diff objects.
     */
    //! Compute differences between OCR and corrector text
	diff_match_patch dmp;
    auto diffs = dmp.diff_main(ocrtext,interntext);

    /*!
    * \cite diff_prettyHtml() inherited from diff_match_patch.cpp
    * replaces symbols, sets background color and spacing of text.
    */

    //! Declare Html text formatting
    QString textcolor = "ffd13d";
    QList<QString> htmlList1 = dmp.diff_prettyHtml(diffs, textcolor);
    QString html1 = htmlList1.first();
    QString html2 = htmlList1.last();

    //! Compute differences between corrector and verifiers text
    diffs = dmp.diff_main(interntext,verifiertext);
    textcolor = "90ff90";

    //! Declare Html text formatting
    QList<QString> htmlList2 = dmp.diff_prettyHtml(diffs, textcolor);
    QString html3 = htmlList2.first();
    html1.remove("&para;");
    html2.remove("&para;");
    html3.remove("&para;");

    //! Load the text data into ui
    ui->InternText->setHtml(html1);
    ui->OCRText->setHtml(html2);
    ui->VerifierText->setHtml(html3);

    //! Set percentage of changes made by corrector
    QString InternLabel = ui->InternLabel->text();
    InternLabel.append(InternAcc+"%");
    ui->InternLabel->setText(InternLabel);

    //! Set percentage of changes made by verifer
    QString VerifierLabel = ui->VerifierLabel->text();
    VerifierLabel.append(VerifierAcc+"%");
    ui->VerifierLabel->setText(VerifierLabel);

    //! Set percentage of accuracy of OCR text
    QString OCRLabel = ui->OCRLabel->text();
    OCRLabel.append(OcrAcc+"%");
    ui->OCRLabel->setText(OCRLabel);

}

DiffView::~DiffView()
{
	delete ui;
}
