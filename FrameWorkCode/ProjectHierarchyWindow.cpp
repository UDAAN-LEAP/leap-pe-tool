#include "ProjectHierarchyWindow.h"
#include "Project.h"

/*!
 * \class ProjectHierarchyWindow
 * \brief This class is used to display the file hierarchy window for the project files
 *
 * In this class we get the model from project class (check project.cpp) which contains the tree model for
 * project files and we then set the model to our treeView widget and we update it.
 *
 * \param parent
 */

ProjectHierarchyWindow::ProjectHierarchyWindow(Project & pProject,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	auto model = pProject.getModel();
	ui.treeView->setModel(model);
	ui.treeView->show();
}
/*!
 * \brief ProjectHierarchyWindow::~ProjectHierarchyWindow
 */
ProjectHierarchyWindow::~ProjectHierarchyWindow()
{

}
