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
    ui->setupUi(this);

        widthLabel = new QLabel("Image width");
        hightLabel = new QLabel("Image height");

        widthSpinBox = new QDoubleSpinBox;
        widthSpinBox->setMaximum(1500);
        widthSpinBox->setValue(imageWidth);
        connect(widthSpinBox, SIGNAL(valueChanged(double)), this, SLOT(widthChanged(double)));


        hightSpinBox = new QDoubleSpinBox;
        hightSpinBox->setMaximum(1500);
        hightSpinBox->setValue(imageHight);
        connect(hightSpinBox, SIGNAL(valueChanged(double)), this, SLOT(hightChanged(double)));

        ratio = imageWidth/imageHight;


        keepRatioCheckBox = new QCheckBox("Keep ratio",this);
        keepRatioCheckBox->setChecked(true);


        widthLayout = new QHBoxLayout;
        widthLayout->addWidget(widthLabel);
        widthLayout->addWidget(widthSpinBox);

        hightLayout  = new QHBoxLayout;
        hightLayout->addWidget(hightLabel);
        hightLayout->addWidget(hightSpinBox);

        okButton = new QPushButton("OK",this);
        QObject::connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));

        cancelButton = new QPushButton("Cancel",this);
        QObject::connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

        buttonLayout = new QHBoxLayout;
        buttonLayout->addStretch();
        buttonLayout->addWidget(okButton);
        buttonLayout->addWidget(cancelButton);

        generalLayout = new QVBoxLayout;
        generalLayout->addLayout(widthLayout);
        generalLayout->addLayout(hightLayout);
        generalLayout->addWidget(keepRatioCheckBox);
        generalLayout->addLayout(buttonLayout);
        setLayout(generalLayout);

        setMaximumSize(300, 300);
        setModal(true);
        //resize(670,630);
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
