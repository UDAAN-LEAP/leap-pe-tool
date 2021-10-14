#pragma once
#include <QMainWindow>
#include <Project.h>
#include <qlist.h>
#include <diff_match_patch.h>
#include <string>

using namespace std;
namespace Ui { class DiffView; };

class DiffView : public QMainWindow
{
	Q_OBJECT

public:
    DiffView(QWidget *parent,QString page, QString fpath);
	~DiffView();

private slots:
    void UpdateUI();
    void on_PrevButton_clicked();
    void Load_comparePage(string page);
    void on_NextButton_clicked();

private:
	Ui::DiffView *ui;
    Project mProject;
    string pageNo;
    QString gDirTwoLevelUp;
    QString html1;
    QString html2;
    QString html3;
    float verifierChangesPerc;
    float correctorChangesPerc;
    float OcrAcc;
};
