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
    QCheckBox *keepRatioCheckBox;

    QPushButton *okButton;
    QPushButton *cancelButton;

public:
    explicit ResizeImageView(QWidget *parent=0,double imageWidth=100.0,double imageHight=100.0);
    static QPair<double,double> getNewSize(QWidget *parent=0,double imageWidth=100.0,double imageHight=100.0);
    ~ResizeImageView();

private slots:
    void on_widthSpinBox_valueChanged(double arg1);

    void on_hightSpinBox_valueChanged(double arg1);

    void on_Ok_clicked();

    void on_Cancel_clicked();

private:
    Ui::ResizeImageView *ui;
    bool heightChanged;
    bool widthChanged;
    //static QPair<double,double> getNewSize(QWidget *parent,double imageWidth=100,double imageHight=100);
};

#endif // RESIZEIMAGEVIEW_H
