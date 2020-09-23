#pragma once

#include <QWizard>
#include "CreateProjectPage.h"

class ProjectWizard : public QWizard
{
	Q_OBJECT

public:
	ProjectWizard(QWidget *parent=nullptr);
	void accept() override;
	void GenerateProject(CreateProjectPage::ProjectInfo &info);
	~ProjectWizard();
private:
	CreateProjectPage * page1;
};
