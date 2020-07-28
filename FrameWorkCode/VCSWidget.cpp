#include "VCSWidget.h"
#include "lg2_common.h"
#include "mainwindow.h"
VCSWidget::VCSWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

VCSWidget::~VCSWidget()
{
}

void VCSWidget::open_git_repo() {

}

void VCSWidget::add_and_commit() {

	Project & p = ((MainWindow*)parent())->GetProject();
	QDir mProjectDir = p.GetDir();
	std::string dir = mProjectDir.path().toStdString();
	QString gitpath = mProjectDir.path() + "/.git";
	QDir gitdir(gitpath);
	git_signature * out;

	if (gitdir.exists())
	{
		check_lg2(git_repository_open(&repo, dir.c_str()), "Failed to Open", "");
		//lg2_add(repo);
		//commit(repo, "Commit after adding files.");
		//push(repo);
	}
	else
	{
		check_lg2(git_repository_init(&repo, dir.c_str(), 0), "Failed to Open", "");
		//create_initial_commit(repo);
		//lg2_add(repo);
	}
	git_repository_free(repo);
}