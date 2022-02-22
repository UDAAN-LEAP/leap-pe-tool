#include "CreateProjectPage.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QAction>
/*! \class CreateProjectPage
 * This class is used to allow users to create new project.
*/


/*!
 * \fn CreateProjectPage::CreateProjectPage
 * \brief This function is used to initialize the ui for the CreateProjectPage Dialog Box
 * It sets the window title and creates appropriate text boxes and labels and buttons and also sets the layout
 * as well.
 *
 * Then we add all the widgets to their respective layouts.
 *
 * \param parent
 */
CreateProjectPage::CreateProjectPage(QWidget *parent)
	: QWizardPage(parent)
{
	setTitle("Create Project");
    bookId_lineEdit = new QLineEdit();
    bookId_label = new QLabel(tr("Book ID: "));
    docExtn_lineEdit  = new QLineEdit();
    docExtn_label = new QLabel(tr("Document Extensions: "));
    imgExtn_lineEdit = new QLineEdit();
    imgExtn_label = new QLabel(tr("Image Extension: "));
    pmEmail_lineEdit= new QLineEdit();
    pmEmail_label = new QLabel(tr("Project Manager Email: "));
    setId_lineEdit = new QLineEdit();
    setId_label = new QLabel(tr("Set Id: "));
    repo_lineEdit = new QLineEdit();
    repo_label = new QLabel(tr("Repository Link: "));
	dirline = new QLineEdit();
	dirline->setReadOnly(true);
	btn = new QPushButton("Open Directory");
	
    QHBoxLayout * bookId_layout = new QHBoxLayout();
	QHBoxLayout * image_layout = new QHBoxLayout();
	QHBoxLayout * document_layout = new QHBoxLayout();
	QHBoxLayout * dir_layout = new QHBoxLayout();
    QHBoxLayout * pmEmail_layout = new QHBoxLayout();
    QHBoxLayout * setId_layout = new QHBoxLayout();
    QHBoxLayout * repo_layout = new QHBoxLayout();
	
	dir_layout->addWidget(btn);
    dir_layout->addWidget(dirline);


    bookId_layout->addWidget(bookId_label);
    bookId_layout->addWidget(bookId_lineEdit);

    setId_layout->addWidget(setId_label);
    setId_layout->addWidget(setId_lineEdit);

    document_layout->addWidget(docExtn_label);
    document_layout->addWidget(docExtn_lineEdit);

    image_layout->addWidget(imgExtn_label);
    image_layout->addWidget(imgExtn_lineEdit);

    pmEmail_layout->addWidget(pmEmail_label);
    pmEmail_layout->addWidget(pmEmail_lineEdit);

    repo_layout->addWidget(repo_label);
    repo_layout->addWidget(repo_lineEdit);


	connect(btn, &QPushButton::clicked, this, &CreateProjectPage::OpenDirectory);
	
	QVBoxLayout * layout = new QVBoxLayout();
    layout->addLayout(bookId_layout);
    layout->addLayout(setId_layout);
    layout->addLayout(pmEmail_layout);
    layout->addLayout(repo_layout);
	layout->addLayout(document_layout);
	layout->addLayout(image_layout);
	layout->addLayout(dir_layout);



	setLayout(layout);
	
}

CreateProjectPage::~CreateProjectPage()
{
}


/*!
 * \fn CreateProjectPage::getProjectInfo
 * \brief This function is used to get the information related to project.
 *
 * Info is a struct declared in createprojectpage header file, consisting of QStrings to store information about
 * various fields of the project.
 *
 * The function fetches all the fields and returns to the calling function.
 *
 * \return
 */
CreateProjectPage::ProjectInfo CreateProjectPage::getProjectInfo() {
	CreateProjectPage::ProjectInfo info;
    info.bookId = bookId_lineEdit->text();
    info.docExtn = docExtn_lineEdit->text();
    info.imgExtn = imgExtn_lineEdit->text();
	info.dir = dirline->text();
    info.pmEmail = pmEmail_lineEdit->text();
    info.setId = setId_lineEdit->text();
    info.repo = repo_lineEdit->text();

    return info;
}

/*!
 * \fn CreateProjectPage::OpenDirectory
 *
 * \brief
 *
 */

void CreateProjectPage::OpenDirectory()
{
	QString dir_str = QFileDialog::getExistingDirectory();
	dirline->setText(dir_str);
	QDir dir(dir_str);
}

