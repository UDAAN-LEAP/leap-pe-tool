#include "DiffView.h"
#include "ui_DiffView.h"
#include "diff_match_patch.h"
DiffView::DiffView(const QString &str1, const QString &str2,QWidget *parent)
	: QMainWindow(parent)
{
	ui = new Ui::DiffView();
	ui->setupUi(this);
	diff_match_patch dmp;
	auto diffs = dmp.diff_main(str1,str2);
	QString html = dmp.diff_prettyHtml(diffs);
	html.remove("&para;");
	ui->diff->setHtml(html);
	ui->original->setPlainText(str1);
}

DiffView::~DiffView()
{
	delete ui;
}
