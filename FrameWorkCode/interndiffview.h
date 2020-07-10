#pragma once

#include <QMainWindow>
namespace Ui { class InternDiffView; };

class InternDiffView : public QMainWindow
{
	Q_OBJECT

public:
    InternDiffView(const QString &ocrtext,const QString &interntxt, const QString &ocrimagepath, const QString acc, QWidget *parent = Q_NULLPTR);
	~InternDiffView();

private:
	Ui::InternDiffView *ui;
	QImage img;
};
