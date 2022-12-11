/*!
\class ResizeImageView
\brief The ResizeImageView class provides the feature to resize the image inserted into the project
       by taking width and height from user.
\sa    on_widthSpinBox_valueChanged(), QPair<double,double> getNewSize(), on_Cancel_clicked(), on_Ok_clicked(), on_hightSpinBox_valueChanged()
*/
#include "resizeimageview.h"
#include "ui_resizeimageview.h"
#include <QDoubleSpinBox>
#include <QLabel>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

/*! \class ResizeImageView
 * \fn ResizeImageView::ResizeImageView
 * \brief This Class is used to Resize the image.
 * \param QWidget->parent
 * \param double->imageWidth
 * \param double->imageHight
 * \details
 * 1)Sets the Window title as "Resize Image Size"
 * 2)Sets up the user interface for the specified widget.
 * 3)Maximum limit of width is kept as 1500 units and minimum as 20 units
 * 4)Maximum limit of height is kept as 1500 units and minimum as 20 units
 * 5)Ok and Cancel button are kept in order to perform desired tasks.
 * 6)Translated version of sourceText is set to "Resize Image"
 * 7)several flags are set thus giving hints on the behavior of the window.
 *  The behavior is platform-dependent
 */
ResizeImageView::ResizeImageView(QWidget *parent,double imageWidth,double imageHight):
    QDialog(parent),
    ui(new Ui::ResizeImageView)
{
    setWindowTitle("Resize Image Size");
    ui->setupUi(this);
        ratio = imageWidth/imageHight;

        widthSpinBox = ui->widthSpinBox;
        hightSpinBox = ui->hightSpinBox;

        keepRatioCheckBox = ui->checkBox;
        keepRatioCheckBox->setChecked(true);

        widthSpinBox->setMaximum(1500);
        widthSpinBox->setMinimum(20);
        widthSpinBox->setValue(imageWidth);
        hightSpinBox->setMaximum(1500);
        hightSpinBox->setMinimum(20);
        hightSpinBox->setValue(imageHight);

        okButton = ui->Ok;

        cancelButton = ui->Cancel;

        setWindowTitle(tr("Resize Image"));
        setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

}

/*!
 * \fn ResizeImageView::getNewSize
 * \brief This function creates an object for ResizeImageview class and passes the width and height provided by
 *        the user as input.
 * \param parent
 * \param imageWidth
 * \param imageHight
 *
 */
QPair<double,double> ResizeImageView::getNewSize(QWidget * parent, double imageWidth, double imageHight)
{
    ResizeImageView rz(parent,imageWidth,imageHight);
    rz.exec();
    QPair<double, double> size;
    size.first = rz.widthSpinBox->value();
    size.second = rz.hightSpinBox->value();
    return size;
}

/*!
 * \fn ResizeImageView::~ResizeImageView
 * \brief Destructor
 */
ResizeImageView::~ResizeImageView()
{
    delete ui;
}

/*!
 * \fn ResizeImageView::on_widthSpinBox_valueChanged
 * \brief This function changes the height of the hightSpinBox when width is changed.
 * \param width
 */
void ResizeImageView::on_widthSpinBox_valueChanged(double width)
{
    if(keepRatioCheckBox->isChecked()) {
        double hight = (double)((int)(width/ratio*10)/10.0);
        if(widthChanged)
            return;
        heightChanged = 1;
        ui->hightSpinBox->setValue(hight);
        heightChanged = 0;
    }
}

/*!
 * \fn ResizeImageView::on_hightSpinBox_valueChanged
 * \brief This function changes the width of the widthSpinBox when height is changed.
 * \param hight
 */
void ResizeImageView::on_hightSpinBox_valueChanged(double hight)
{
    if(keepRatioCheckBox->isChecked()) {
        double width = (double)((int)(ratio*hight*10)/10.0);
        if(heightChanged)
            return;
        widthChanged = 1;
        ui->widthSpinBox->setValue(width);
        widthChanged = 0;
    }
}

/*!
 * \fn ResizeImageView::on_Ok_clicked
 * \brief This function called when ok is clicked for resizing
 * \sa accept()
 */
void ResizeImageView::on_Ok_clicked()
{
    accept();
}

/*!
 * \fn ResizeImageView::on_Ok_clicked
 * \brief This function called when cancle is clicked for resizing
 * \sa reject()
 */
void ResizeImageView::on_Cancel_clicked()
{
    reject();
}
