#pragma once
#include <string>
#include <QMainWindow>
#include <Project.h>
#include <qlist.h>
#include <diff_match_patch.h>
#include <QGraphicsScene>

using namespace std;
namespace Ui { class InternDiffView; };

class InternDiffView : public QMainWindow
{
	Q_OBJECT

public:
    InternDiffView( QWidget *parent,  QString page, QString fpath);
    bool validFilePath();
	~InternDiffView();

private slots:
    void on_NextButton_clicked();
    void Load_comparePage(string page);
    void on_prevButton_clicked();
    void Update_UI();

private:
	Ui::InternDiffView *ui;
	QImage img;
    Project mProject;
    string pageNo;
    QString gDirTwoLevelUp;
    QGraphicsScene *scene = new QGraphicsScene(this);
    QString html1;
    QString html2;
    QString ocrimage;
    float correctorChangesPerc;
    bool isValidFile;
};
