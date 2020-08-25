#ifndef RESIZEIMAGEVIEW_H
#define RESIZEIMAGEVIEW_H

#include <QDialog>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>

namespace Ui {
class ResizeImageView;
}

class ResizeImageView : public QDialog
{
    Q_OBJECT

    QDoubleSpinBox  * widthSpinBox;
    QDoubleSpinBox  * hightSpinBox;
    double ratio;

    QLabel *widthLabel;
    QLabel *hightLabel;


    QCheckBox *keepRatioCheckBox;

    QPushButton *okButton;
    QPushButton *cancelButton;

    QHBoxLayout *widthLayout;
    QHBoxLayout *hightLayout;
    QHBoxLayout *buttonLayout;
    QVBoxLayout *generalLayout;

public:
    explicit ResizeImageView(QWidget *parent=0,double imageWidth=100.0,double imageHight=100.0);
    static QPair<double,double> getNewSize(QWidget *parent=0,double imageWidth=100.0,double imageHight=100.0);
    ~ResizeImageView();

private:
    Ui::ResizeImageView *ui;
    //static QPair<double,double> getNewSize(QWidget *parent,double imageWidth=100,double imageHight=100);
};

#endif // RESIZEIMAGEVIEW_H
