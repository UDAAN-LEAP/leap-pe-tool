/*!
 * \class InternDiffView
 * \brief Find the difference between OCR output and Corrector's output
 *
 * The InternDiffView class compares the OCR and Corrector's text and
 * it displays the percentage of changes made by the corrector.
 *
 * \sa diff_main(), diff_prettyHtml(), gentle_zoom(), set_modifiers()
*/

#include "interndiffview.h"
#include "ui_interndiffview.h"
#include "zoom.h"
#include "diff_match_patch.h"
/*!
 * \fn InternDiffView::InternDiffView
 * \brief Creates a window showing comparison between OCR and Corrector's output.
 * \param ocroutput
 * \param interntxt
 * \param ocrimgpath
 * \param acc
 * \param parent
 * \note InternDiffView() is inherited from InternDiffView class in interdiffview.h file
 */
InternDiffView::InternDiffView( QString &ocroutput,  QString &interntxt, const QString &ocrimgpath, const QString acc, QWidget *parent)
	: QMainWindow(parent)
{
    setWindowTitle("Corrector Output Difference");
    QTextDocument doc;

    //!Get Corrector output text
    doc.setHtml(interntxt);
    interntxt = doc.toPlainText();

    //!Get OCR output text
    doc.setHtml(ocroutput);
    ocroutput = doc.toPlainText();

    /*
     *  Ui::InternDiffView is an interface description object from the ui_interndiffview.h file.
     * \brief Sets up all the dialog's widgets and the connections between its signals and slots.
    */
    ui = new Ui::InternDiffView();
	ui->setupUi(this);
	diff_match_patch dmp;

    /*!
     * \cite diff_main() inherited from diff_match_path.cpp.
     * \brief This function finds the difference between ocroutput and interntxt and return a linked list of Diff objects.
     */
	auto diffs = dmp.diff_main(ocroutput, interntxt);

    /*!
     * \cite diff_prettyHtml() inherited from diff_match_patch.cpp
     * \brief Replaces symbols, sets background color and spacing of text.
     * \return Returns the source text in the mentioned text color value.
     */
    auto html = dmp.diff_prettyHtml(diffs, "ffd13d");
	auto html1 = html[0];
	auto html2 = html[1];
	html1.remove("&para;");
	html2.remove("&para;");

    //!Load the text data into ui
    ui->current->setHtml(html1);
	ui->ocroutput->setHtml(html2);

    /*
     * \description
     * 1. The loaded image is converted into a pixmap using fromImage().
     * 2. Converted image is then added to the current scene using addPixmap().
    */
    img.load(ocrimgpath);
	QGraphicsScene *scene = new QGraphicsScene(this);
	scene->addPixmap(QPixmap::fromImage(img));	
	setWindowTitle("Corrector");

    //!GraphicsView size is adjusted to ensure that all the items on the scene fits tightly inside the view.
	ui->graphicsView->setScene(scene);
	ui->graphicsView->adjustSize();
	ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
	Graphics_view_zoom* z = new Graphics_view_zoom(ui->graphicsView);
	z->set_modifiers(Qt::NoModifier);
    z->gentle_zoom(30);      //Zooms the image by scaling vector 30.

    //!Shows the percentage of changes made by the corrector.
    QString label1 = ui->InternLabel->text();
    label1.append(acc+"%");
    ui->InternLabel->setText(label1);
}

InternDiffView::~InternDiffView()
{
	delete ui;
}
