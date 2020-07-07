#include "DiffView.h"
#include "ui_DiffView.h"
#include "diff_match_patch.h"
DiffView::DiffView(const QString &ocrtext, const QString &interntext, const QString &verifiertext, QWidget *parent)
	: QMainWindow(parent)
{
	ui = new Ui::DiffView();
	ui->setupUi(this);
	diff_match_patch dmp;
    auto diffs = dmp.diff_main(ocrtext,interntext);
    QString textcolor = "ccffcc";
    QList<QString> htmlList1 = dmp.diff_prettyHtml(diffs, textcolor);
    QString html1 = htmlList1.first();
    QString html2 = htmlList1.last();
//    qDebug() << "html1" << html1;
//    qDebug() <<"htmllist" << htmlList1;
     diffs = dmp.diff_main(interntext,verifiertext);
    textcolor = "cce6ff";
    QList<QString> htmlList2 = dmp.diff_prettyHtml(diffs, textcolor);
    QString html3 = htmlList2.first();
    html1.remove("&para;");
    html2.remove("&para;");
    html3.remove("&para;");
    ui->diff2->setHtml(html1);
    ui->diff1->setHtml(html2);
    ui->diff3->setHtml(html3);

}

DiffView::~DiffView()
{
	delete ui;
}
