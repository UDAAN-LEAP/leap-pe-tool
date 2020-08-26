#include "interndiffview.h"
#include "ui_interndiffview.h"
#include "zoom.h"
#include "diff_match_patch.h"
InternDiffView::InternDiffView( QString &ocroutput,  QString &interntxt, const QString &ocrimgpath, const QString acc, QWidget *parent)
	: QMainWindow(parent)
{
    setWindowTitle("Corrector Output Difference");
    QTextDocument doc;
    doc.setHtml(interntxt);
    interntxt = doc.toPlainText();

    doc.setHtml(ocroutput);
    ocroutput = doc.toPlainText();

    ui = new Ui::InternDiffView();
	ui->setupUi(this);
	diff_match_patch dmp;
	auto diffs = dmp.diff_main(ocroutput, interntxt);
    auto html = dmp.diff_prettyHtml(diffs, "ffd13d");
	auto html1 = html[0];
	auto html2 = html[1];
	html1.remove("&para;");
	html2.remove("&para;");

    ui->current->setHtml(html1);
	ui->ocroutput->setHtml(html2);

    img.load(ocrimgpath);
	QGraphicsScene *scene = new QGraphicsScene(this);
	scene->addPixmap(QPixmap::fromImage(img));	
	setWindowTitle("Corrector");
	ui->graphicsView->setScene(scene);
	ui->graphicsView->adjustSize();
	ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
	Graphics_view_zoom* z = new Graphics_view_zoom(ui->graphicsView);
	z->set_modifiers(Qt::NoModifier);
    z->gentle_zoom(30);

    QString label1 = ui->InternLabel->text();
    label1.append(acc+"%");
    ui->InternLabel->setText(label1);
}

InternDiffView::~InternDiffView()
{
	delete ui;
}
