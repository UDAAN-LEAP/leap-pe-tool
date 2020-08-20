#pragma once

#include <QWidget>
#include "ui_ProjectHierarchyWindow.h"
#include "Project.h"
class ProjectHierarchyWindow : public QWidget
{
	Q_OBJECT

public:
	ProjectHierarchyWindow(Project &pProject,QWidget *parent = Q_NULLPTR);
	~ProjectHierarchyWindow();

private:
	Ui::ProjectHierarchyWindow ui;
};
