/*!
\class CommentsView
\brief The comments view class provides a window to user with title Comments and Accuracy
       and raating options are provided to correctors and verifiers. It saves the comments in
       a json file.
\sa on_pushButton_clicked()
*/
#include "commentsview.h"
#include "ui_commentsview.h"
#include "mainwindow.h"
#include <QCloseEvent>
#include <QString>
#include "crashlog.h"
#include <string>
QString commentFilename;
QString pagename;

/*!
 * \fn CommentsView::CommentsView
 * \param words
 * \param chars
 * \param wordacc
 * \param characc
 * \param commentsField
 * \param commentsFilelocation
 * \param currentpagename
 * \param rating
 * \param avgAcc
 * \param role
 * \param version
 * \param parent
 * \brief This class provides a view for showing comments to the users
 * \details It shows the "Words", "Word Accuracy", etc. values
 */
CommentsView::CommentsView(const int &words, const int &chars, const float &wordacc, const float &characc,const QString commentsField,const QString commentsFilelocation, const QString currentpagename, int rating, const QString avgAcc, const QString role, QString version, QWidget *parent) :
    QDialog(parent)
{

    ui = new Ui::CommentsView();
    ui->setupUi(this);
    qInstallMessageHandler(crashlog::myMessageHandler);
    setWindowTitle("Comments and Accuracy");
    ui->h_words->setText(QString::number(words));
    ui->h_characters->setText(QString::number(chars));
    ui->acc_word->setText(QString::number(wordacc));
    ui->acc_character->setText(QString::number(characc));
    ui->commentTextBrowser->setText(commentsField);
    ui->commentTextBrowser->setFocus();

    ui->rating->setText(QString::number(rating));
    ui->avgAcc->setText(avgAcc);

    //!Verifier
    ui->ratingLabel->setText("<b>Rating for V-" + QString::number(version.toInt()) + "</b>");
    ui->avgAccLabel->setText("<b>Avg. Char. Accuracy for V-" + QString::number(version.toInt()) + "</b>");

    commentFilename = commentsFilelocation;
    pagename = currentpagename;
	pagename.replace(".txt", "");
	pagename.replace(".html", "");
    if(role == "Corrector") {

        //!Corrector
        ui->ratingLabel->setText("<b>Rating for V-" + QString::number(version.toInt() - 1) + "</b>");
        ui->avgAccLabel->setText("<b>Avg. Char. Accuracy for V-" + QString::number(version.toInt() - 1) + "</b>");

        ui->commentTextBrowser->setReadOnly(true);
        ui->pushButton->setEnabled(false);
        ui->pushButton->setVisible(false);
        if(version == "1") {
            //!No rating will be available to corrector in Version-1
            ui->rating->setVisible(false);
            ui->avgAcc->setVisible(false);
            ui->ratingLabel->setVisible(false);
            ui->avgAccLabel->setVisible(false);
            ui->ratingsAccLayout->setEnabled(false);
        }
    }


}

/*!
 * \fn CommentsView::~CommentsView
 * \brief Destructor
 */
CommentsView::~CommentsView()
{
    delete ui;
}

/*!
* \fn CommentsView::on_pushButton_clicked()
* \brief This functions get called when push button is clicked in dialog.
*        It allows verifier to save the comments and rating in a json file
*        with page details.
*
*\note Verifier-Version
*/
void CommentsView::on_pushButton_clicked() //Verifier-Version
{

    QString comments = ui->commentTextBrowser->toPlainText();

    QFile jsonFile(commentFilename);
    jsonFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray data = jsonFile.readAll();

    QJsonParseError errorPtr;
    QJsonDocument document = QJsonDocument::fromJson(data, &errorPtr);
    QJsonObject mainObj = document.object();
    QJsonObject pages = mainObj.value("pages").toObject();
    QJsonObject page = pages.value(pagename).toObject();
    jsonFile.close();
    page["comments"] = comments;

    pages.remove(pagename);
    pages.insert(pagename,page);
    mainObj.remove("pages");
    mainObj.insert("pages",pages);
    document.setObject(mainObj);

    QFile jsonFile1(commentFilename);
    jsonFile1.open(QIODevice::WriteOnly);
    jsonFile1.write(document.toJson());

}
