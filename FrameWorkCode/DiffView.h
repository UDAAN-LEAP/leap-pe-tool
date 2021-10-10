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
    DiffView(QString &str1, QString &str2, QString &str3,QString page, QString fpath, const QString &acc1, const QString &acc2, const QString &acc3,QWidget *parent = Q_NULLPTR);
	~DiffView();
    string pageNo;
    QString gDirTwoLevelUp;
   // QGraphicsScene *scene = new QGraphicsScene(this);

private slots:
    void on_PrevButton_clicked();
    void Load_comparePage(string page);
    int GetPageNumber(string localFilename, string *no, size_t *loc, QString *ext);
    void on_NextButton_clicked();

private:
	Ui::DiffView *ui;
    Project mProject;
};
