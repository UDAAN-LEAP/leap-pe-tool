#include "DiffView.h"
#include "ui_DiffView.h"
#include "diff_match_patch.h"
DiffView::DiffView( QString &ocrtext,  QString &interntext,  QString &verifiertext,const QString &InternAcc, const QString &VerifierAcc, const QString &OcrAcc, QWidget *parent)
	: QMainWindow(parent)
{

    QTextDocument doc;
    doc.setHtml(interntext);
    interntext = doc.toPlainText();

    doc.setHtml(ocrtext);
    ocrtext = doc.toPlainText();

    doc.setHtml(verifiertext);
    verifiertext = doc.toPlainText();

    ui = new Ui::DiffView();
	ui->setupUi(this);
	diff_match_patch dmp;
    auto diffs = dmp.diff_main(ocrtext,interntext);
    QString textcolor = "ffd13d";
    QList<QString> htmlList1 = dmp.diff_prettyHtml(diffs, textcolor);
    QString html1 = htmlList1.first();
    QString html2 = htmlList1.last();

     diffs = dmp.diff_main(interntext,verifiertext);
    textcolor = "90ff90";
    QList<QString> htmlList2 = dmp.diff_prettyHtml(diffs, textcolor);
    QString html3 = htmlList2.first();
    html1.remove("&para;");
    html2.remove("&para;");
    html3.remove("&para;");

    ui->InternText->setHtml(html1);
    ui->OCRText->setHtml(html2);
    ui->VerifierText->setHtml(html3);

    QString InternLabel = ui->InternLabel->text();
    InternLabel.append(InternAcc+"%");
    ui->InternLabel->setText(InternLabel);

    QString VerifierLabel = ui->VerifierLabel->text();
    VerifierLabel.append(VerifierAcc+"%");
    ui->VerifierLabel->setText(VerifierLabel);

    QString OCRLabel = ui->OCRLabel->text();
    OCRLabel.append(OcrAcc+"%");
    ui->OCRLabel->setText(OCRLabel);


}

DiffView::~DiffView()
{
	delete ui;
}
