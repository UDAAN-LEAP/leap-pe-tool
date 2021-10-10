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
    InternDiffView( QString &ocrtext, QString &interntxt, const QString &ocrimagepath, QString fpath, QString page, const QString acc, QWidget *parent = Q_NULLPTR);
	~InternDiffView();
   string pageNo;
   QString gDirTwoLevelUp;
   QGraphicsScene *scene = new QGraphicsScene(this);

private slots:
    void on_NextButton_clicked();
    void Load_comparePage(string page);
    void on_prevButton_clicked();
    int GetPageNumber(string localFilename, string *no, size_t *loc, QString *ext);
private:
	Ui::InternDiffView *ui;
	QImage img;
    Project mProject;
};
