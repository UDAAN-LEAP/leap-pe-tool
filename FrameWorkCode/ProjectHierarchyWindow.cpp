#include "ProjectHierarchyWindow.h"
#include "Project.h"
ProjectHierarchyWindow::ProjectHierarchyWindow(Project & pProject,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	auto model = pProject.getModel();
	

}

ProjectHierarchyWindow::~ProjectHierarchyWindow()
{
}
