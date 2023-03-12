#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include <QStandardItemModel>
#include <loadingspinner.h>

namespace Ui {
class dashboard;
}

class dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit dashboard(QWidget *parent, QString s, int max, QMap<int, QString> repoMap, QString *p);
    ~dashboard();

private slots:
    void on_pushButton_clicked();
    void stopSpinning();

private:
    Ui::dashboard *ui;
    QMap<int, QString> repoMap;
    LoadingSpinner *spinner;
    QString *p;
};

#endif // DASHBOARD_H
