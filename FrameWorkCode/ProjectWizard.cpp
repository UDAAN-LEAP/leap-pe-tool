/*!
  \class ProjectWizard.cpp
  \brief Creates a project.xml file
 */
#include "ProjectWizard.h"
#include "CreateProjectPage.h"
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>
ProjectWizard::ProjectWizard(QWidget *parent)
	: QWizard(parent)
{
	page1 = new CreateProjectPage();
	addPage(page1);
	setWindowTitle("Project Wizard");
}

/*!
 * \fn ProjectWizard::GenerateProject
 * \brief creates a new project.xml file and writes content to it
 * \param info
 */
void ProjectWizard::GenerateProject(CreateProjectPage::ProjectInfo &info) {

    //!Fetches project details
    QString bookId = info.bookId;
    QString imageExtensions = info.imgExtn;
    QString docExtensions = info.docExtn;
    QString pmEmail = info.pmEmail;
    QString setId = info.setId;
    QString repo = info.repo;

    //! Declaring the skeleton of xml file
	QString dir = info.dir+"/project.xml";
	QString str = "<?xml version=\"1.0\"?>\r\n";
    QString str2 = "<Project name=\"" + bookId + "\">\r\n";
	QString str3 = "\t<ItemGroup>\r\n\t\t<Filter Include=\"Image\">\r\n\t\t\t<Extensions>"+imageExtensions+"</Extensions>\r\n\t\t</Filter>\r\n";
	QString str4 = "\t\t<Filter Include=\"Document\">\r\n\t\t\t<Extensions>" + docExtensions + "</Extensions>\r\n\t\t</Filter>\r\n\t</ItemGroup>\r\n";
    QString str5 = "\t<ItemGroup>\r\n\t</ItemGroup>\r\n\t<Metadata>\r\n\t\t<Version>1</Version>\r\n\t\t<Stage>Corrector</Stage>\r\n\t\t<ProjectManagerEmail>"+pmEmail+"</ProjectManagerEmail>\r\n\t\t<SetId>"+setId+"</SetId>\r\n\t<BookId>"+bookId+"</BookId>\r\n\t<RepositoryLink>"+repo+"</RepositoryLink>\r\n\t</MetaData>\r\n</Project>";

    //!Writing content to xml file
    QFile file(dir);
	QDir qdir(info.dir);
	if(qdir.exists(info.dir)) {
		if(file.open(QFile::WriteOnly)) {
			QTextStream textStream(&file);
			textStream << str<<str2<<str3<<str4<<str5;
			file.close();
		}
	}
}

/*!
 * \fn ProjectWizard::accept
 * \brief Generates xml file
 */
void ProjectWizard::accept()
{
	CreateProjectPage::ProjectInfo info;
	info = page1->getProjectInfo();

    //!Create Project
    QString bookId = info.bookId;
    QString imageExtensions = info.imgExtn;
    QString docExtensions = info.docExtn;
    QString pmEmail = info.pmEmail;
    QString setId = info.setId;
    QString repo = info.repo;
    QString dir = info.dir;

    //!Generates project.xml file and shows message to user
    if (bookId.length() != 0 && docExtensions.length() != 0 && imageExtensions.length() != 0 && dir.length() != 0 &&
        pmEmail.length()!=0 && setId.length()!=0 && repo.length()!=0) {
		GenerateProject(info);
		QMessageBox box;
		QString msg = "Project.xml file created at " + dir+" successfully.";
		QMessageBox::information(nullptr, "Project Wizard", msg, QMessageBox::Ok);
		close();
	}
	else
	{
		QMessageBox box;
		QMessageBox::information(nullptr, "Project Wizard", "Please enter details in all of the fields.", QMessageBox::Ok);
	}
}

ProjectWizard::~ProjectWizard()
{
}
