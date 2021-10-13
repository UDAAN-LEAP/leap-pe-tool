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
    string pageNo;
    QString gDirTwoLevelUp;
    QString html1;
    QString html2;
    QString html3;
    float correctorChangesPerc=0;
    float OcrAcc=0;
    float verifierChangesPerc=0;

private slots:
    void on_PrevButton_clicked();
    void Load_comparePage(string page);
    void on_NextButton_clicked();
    void UpdateUI();

private:
	Ui::DiffView *ui;
    Project mProject;
};
