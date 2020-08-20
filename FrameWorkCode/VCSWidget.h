#pragma once

#include <QWidget>
#include "ui_VCSWidget.h"
#include <git2.h>
#include <QFileSystemWatcher>

class VCSWidget : public QWidget
{
	Q_OBJECT

public:
	VCSWidget(QWidget *parent = Q_NULLPTR);
	~VCSWidget();
	void add_and_commit();
	void open_git_repo();
private:
	Ui::VCSWidget ui;
	git_repository * repo;
	QFileSystemWatcher watcher;
};
