#include "globalreplacepreview.h"
#include "ui_globalreplacepreview.h"
#include <QStandardItemModel>
#include "crashlog.h"

/*!
 * \fn MainWindow::globalReplacePreview()
 * \brief This feature allows user to view the changes in advance that are going to be done by global replace
 *
 * This function is used to initialize the dialog box for the preview of global replace.
 * Please refer to globalReplacePreviewfn() and getBeforeAndAfterWords for more information
 *
 * \param QWidget *parent,QStandardItemModel *model
 * \sa qInstallMessageHandler()
 */
globalReplacePreview::globalReplacePreview(QWidget *parent,QStandardItemModel *model) :
    QDialog(parent),
    ui(new Ui::globalReplacePreview)
{
    ui->setupUi(this);
    qInstallMessageHandler(crashlog::myMessageHandler);
    setWindowTitle("Preview of word replacement");
    ui->tableView->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setMaximumSectionSize(600);
    ui->tableView->setWordWrap(true);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();


}

globalReplacePreview::~globalReplacePreview()
{
    delete ui;
}
