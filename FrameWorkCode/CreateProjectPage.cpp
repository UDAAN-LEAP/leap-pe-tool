/*! \class CreateProjectPage
 *  \brief This class is used to allow users to create new project.
*/
#include "CreateProjectPage.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QAction>

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

    setTitle("Create Project"); //! set the window title to create the project

    //! Initialize all the line edit and button widgets with their respective labels
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
	
    //! Initialize layout for all the widgets
    QHBoxLayout * bookId_layout = new QHBoxLayout();
	QHBoxLayout * image_layout = new QHBoxLayout();
	QHBoxLayout * document_layout = new QHBoxLayout();
	QHBoxLayout * dir_layout = new QHBoxLayout();
    QHBoxLayout * pmEmail_layout = new QHBoxLayout();
    QHBoxLayout * setId_layout = new QHBoxLayout();
    QHBoxLayout * repo_layout = new QHBoxLayout();


    //! Add widgets to the respective layouts

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

    //! We use connect function here which implictly invokes OpenDirectory function when the button
    //! is clicked
	connect(btn, &QPushButton::clicked, this, &CreateProjectPage::OpenDirectory);
	

    //! We create the VBox Layout and add all the sub-layouts to this layout
    //! Check Layout in QT documentation for more info
	QVBoxLayout * layout = new QVBoxLayout();
    layout->addLayout(bookId_layout);
    layout->addLayout(setId_layout);
    layout->addLayout(pmEmail_layout);
    layout->addLayout(repo_layout);
	layout->addLayout(document_layout);
	layout->addLayout(image_layout);
	layout->addLayout(dir_layout);


    //! We set VBox layout to whole dialog box
	setLayout(layout);
	
}

/*!
 * \fn CreateProjectPage::~CreateProjectPage
 * \brief Destructor
 */
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
    //! info is a struct with many sub - fields (check header file for this class - CreateProjectPage.h)
	CreateProjectPage::ProjectInfo info;

    //! We set the struct child items with the data entered by the user

    info.bookId = bookId_lineEdit->text();
    info.docExtn = docExtn_lineEdit->text();
    info.imgExtn = imgExtn_lineEdit->text();
	info.dir = dirline->text();
    info.pmEmail = pmEmail_lineEdit->text();
    info.setId = setId_lineEdit->text();
    info.repo = repo_lineEdit->text();

    //! We return this struct to the calling function

    return info;
}

/*!
 * \fn CreateProjectPage::OpenDirectory
 * \brief We open a QFileDialog which opens the OS File Browser Dialog Box.
 * \details Then we set the text of dirline i.e line edit widget to the text obtained from getExisting directory
 * and we also intialize a QDir Object with the directory string.
 */
void CreateProjectPage::OpenDirectory()
{
    //! The user selects a directory and this is returned by the getExistingDirectory() Function.
	QString dir_str = QFileDialog::getExistingDirectory();
	dirline->setText(dir_str);
	QDir dir(dir_str);
}

