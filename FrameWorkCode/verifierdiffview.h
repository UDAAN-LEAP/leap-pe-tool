#pragma once

#include <QMainWindow>
#include "ui_verifierdiffview.h"

class VerifierDiffView : public QMainWindow
{
	Q_OBJECT

public:
	VerifierDiffView(QWidget *parent = Q_NULLPTR);
	~VerifierDiffView();

private:
	Ui::VerifierDiffView ui;
};
