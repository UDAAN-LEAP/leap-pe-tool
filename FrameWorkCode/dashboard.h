#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include <QStandardItemModel>
#include <loadingspinner.h>
#include<map>

namespace Ui {
class dashboard;
}

class dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit dashboard(QWidget *parent, QString s, int max, QMap<int, QString> repoMap, QString *p, bool* open);
    ~dashboard();

private slots:
    void on_pushButton_clicked();
    void stopSpinning();
    void clicked(int id);

    void on_pushButton_2_clicked();

    void on_Import_Open_btn_clicked();

    void on_Import_btn_clicked();

private:
    Ui::dashboard *ui;
    QMap<int, QString> repoMap;
    LoadingSpinner *spinner;
    QString *p;
    QMap<int,int> presentId;
    QMap<int,QPushButton*>btnMap;
    int selectedBooks = -1;
    int totalClickedBooks = 0;
    bool* toOpen;

};

#endif // DASHBOARD_H
