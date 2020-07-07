#include "DiffView.h"
#include "ui_DiffView.h"
#include "diff_match_patch.h"
DiffView::DiffView(const QString &str1, const QString &str2, const QString &str3, QWidget *parent)
	: QMainWindow(parent)
{
	ui = new Ui::DiffView();
	ui->setupUi(this);
	diff_match_patch dmp;
    auto diffs = dmp.diff_main(str1,str2);
    QString textcolor = "ccfcc"; //Change
    QList<QString> htmlList = dmp.diff_prettyHtml(diffs, textcolor);
    QString html1 = htmlList.first();
    QString html2 = htmlList.last();
    html1.remove("&para;");
    html2.remove("&para;");
    //CHANGE-->
//    ui->diff->setHtml(html1);
//    ui->original->setPlainText(str2);
}

DiffView::~DiffView()
{
	delete ui;
}
