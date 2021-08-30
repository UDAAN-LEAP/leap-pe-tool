#include "secdialog.h"
#include "ui_secdialog.h"
#include "mainwindow.h"
#include <QProcess>
#include<qdebug.h>

static QString path;
static QString src,src1;
static bool deciderimage = false;
SecDialog::SecDialog(QString html,QString src1,QString path1,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
    path = path1;
    src = src1;
    setWindowTitle("Image Extraction Window");
    //ui->textBrowser->textCursor().insertHtml(html);
    //QString src = path+"/new.png";
    //html = QString("<img src='%1'>").arg(src);
    ui->textBrowser->textCursor().insertHtml(html);
}

SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::on_pushButton_4_clicked()
{
    QString command0("python3");
    QString command("pip install opencv-python");
    QString command1("pip install matplotlib");
    QString command2("pip install glob2");

    //QString command3("pwd");
    QStringList params = QStringList() << path+"/image_matching.py"<<path<<src;

    QProcess *process = new QProcess();
    process->startDetached(command);
    process->startDetached(command1);
    process->startDetached(command1);
    process->start(command0, params);
    process->waitForFinished(-1);
    QString p_stdout = process->readAll();

    src1 = p_stdout;
    src1.chop(1);
    //qDebug() <<src1;
    //ui->textBrowser_2->setText(p_stdout);
    QString html = QString("<img src='%1'>").arg(src1);
    ui->textBrowser_2->textCursor().insertHtml(html);
}

QString SecDialog::on_pushButton_3_clicked()
{
    //QTextCursor cursor = ui->textBrowser->textCursor();
    //cursor.insertText("hddjnj");
    this->hide();
    deciderimage=false;
    return (src+QString::number(deciderimage));
    //MainWindow::display();
    //MainWindow *mw = new MainWindow();
    //mw->show();
    //mw->display();
//    QTextCursor cursor = mw->curr_browser->textCursor();
//    cursor.insertText("hddjnj");
}

QString SecDialog::on_pushButton_clicked()
{
    this->hide();
    deciderimage = true;
    return (src1+QString::number(deciderimage));
}

//! decide which button ic clicked? source_image/ocr image
QString SecDialog::on_push_clicked()
{
    if(deciderimage==false)
    {
        return (src);
    }
    else
    {
        if(ui->textBrowser_2->toPlainText()!="")
        {
            return (src1);
        }
        else
        {
            return "not loaded";
        }
    }
}
