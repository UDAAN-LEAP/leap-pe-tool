#include "resizeimageview.h"
#include "ui_resizeimageview.h"
#include <QDoubleSpinBox>
#include <QLabel>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
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

QPair<double,double> ResizeImageView::getNewSize(QWidget * parent, double imageWidth, double imageHight)
{
    ResizeImageView rz(parent,imageWidth,imageHight);
    rz.exec();
    QPair<double, double> size;
    size.first = rz.widthSpinBox->value();
    size.second = rz.hightSpinBox->value();
    return size;
}

ResizeImageView::~ResizeImageView()
{
    delete ui;
}

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

void ResizeImageView::on_Ok_clicked()
{
    accept();
}

void ResizeImageView::on_Cancel_clicked()
{
    reject();
}
