#include "interndiffview.h"
#include "ui_interndiffview.h"
#include "zoom.h"
#include "diff_match_patch.h"
InternDiffView::InternDiffView(const QString &ocroutput, const QString &interntxt, const QString &ocrimgpath, QWidget *parent)
	: QMainWindow(parent)
{
	ui = new Ui::InternDiffView();
	ui->setupUi(this);
	diff_match_patch dmp;
	auto diffs = dmp.diff_main(ocroutput, interntxt);
	auto html = dmp.diff_prettyHtml(diffs, "ccffcc");
	auto html1 = html[0];
	auto html2 = html[1];
	html1.remove("&para;");
	html2.remove("&para;");
	ui->current->setHtml(html1);
	ui->ocroutput->setHtml(html2);
	img.load(ocrimgpath);
	QGraphicsScene *scene = new QGraphicsScene(this);
	scene->addPixmap(QPixmap::fromImage(img));
	ui->graphicsView->setScene(scene);
	ui->graphicsView->adjustSize();
	ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
	Graphics_view_zoom* z = new Graphics_view_zoom(ui->graphicsView);
	z->set_modifiers(Qt::NoModifier);
}

InternDiffView::~InternDiffView()
{
	delete ui;
}
