#pragma once

#include <QWizardPage>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
class CreateProjectPage : public QWizardPage
{
	Q_OBJECT

public:
	struct ProjectInfo {
        QString bookId;
        QString setId;
        QString docExtn;
        QString imgExtn;
		QString dir;
        QString pmEmail;
	};
	CreateProjectPage(QWidget *parent=nullptr);
	~CreateProjectPage();
	ProjectInfo getProjectInfo();
	void OpenDirectory();
	
private:
    QLabel * bookId_label;
    QLineEdit * bookId_lineEdit;
    QLabel * docExtn_label;
    QLineEdit * docExtn_lineEdit;
    QLabel * imgExtn_label;
    QLineEdit * imgExtn_lineEdit;
	QLineEdit * dirline;
	QPushButton * btn;
    QLabel * pmEmail_label;
    QLineEdit * pmEmail_lineEdit;
    QLabel * setId_label;
    QLineEdit * setId_lineEdit;
};
