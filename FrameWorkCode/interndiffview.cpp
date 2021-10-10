#include "interndiffview.h"
#include "ui_interndiffview.h"
#include "zoom.h"
#include "diff_match_patch.h"
#include <string>
#include <qstring.h>
#include <Project.h>
#include <QMessageBox>

InternDiffView::InternDiffView( QString &ocroutput,  QString &interntxt, const QString &ocrimgpath,QString fpath, QString page , const QString acc, QWidget *parent)
	: QMainWindow(parent)
{
    gDirTwoLevelUp = fpath;
    QString title = "Corrector Output Difference " + page ;
    pageNo = page.toStdString();
    QTextDocument doc;
    doc.setHtml(interntxt);
    interntxt = doc.toPlainText();

    doc.setHtml(ocroutput);
    ocroutput = doc.toPlainText();

    ui = new Ui::InternDiffView();
	ui->setupUi(this);
	diff_match_patch dmp;
	auto diffs = dmp.diff_main(ocroutput, interntxt);
    auto html = dmp.diff_prettyHtml(diffs, "ffd13d");
	auto html1 = html[0];
	auto html2 = html[1];
	html1.remove("&para;");
	html2.remove("&para;");

    ui->current->setHtml(html1);
	ui->ocroutput->setHtml(html2);

    img.load(ocrimgpath);
    //QGraphicsScene *scene = new QGraphicsScene(this);
    //scene(this);
	scene->addPixmap(QPixmap::fromImage(img));	
    //setWindowTitle("Corrector");
    setWindowTitle(title);
	ui->graphicsView->setScene(scene);
	ui->graphicsView->adjustSize();
	ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
	Graphics_view_zoom* z = new Graphics_view_zoom(ui->graphicsView);
	z->set_modifiers(Qt::NoModifier);
    z->gentle_zoom(30);

    QString label1 = ui->InternLabel->text();
    label1.append(acc+"%");
    ui->InternLabel->setText(label1);
}

InternDiffView::~InternDiffView()
{
	delete ui;
}

void InternDiffView::Load_comparePage(string page)
{

   QString qs1="", qs2="";
   QMessageBox msgBox;

   //! Open a Corrector's Output File
   QString file = gDirTwoLevelUp + "/CorrectorOutput/" + QString::fromStdString(page);

   //! Opens corresponding OCR text file and image
   if(!file.isEmpty())
   {
       QString correctortext = file;
       QString ocrtext = file;
       ocrtext.replace("CorrectorOutput","Inds"); //CAN CHANGE ACCORDING TO FILE STRUCTURE
       ocrtext.replace(".html",".txt");
       QString ocrimage = ocrtext;
       ocrimage.replace("Inds", "Images");
       QString temp = ocrimage;
       int flag=0;
       temp.replace(".txt", ".jpeg");
       if (QFile::exists(temp) && flag==0)
       {
           ocrimage=temp;
           flag=1;
       }
       else
       {
           temp=ocrimage;
       }
       temp.replace(".html", ".jpeg");
       if (QFile::exists(temp) && flag==0)
       {
           ocrimage=temp;
           flag=1;
       }
       else
       {
           temp=ocrimage;
       }
       temp.replace(".txt", ".png");
       if (QFile::exists(temp) && flag==0)
       {
           ocrimage=temp;
           flag=1;
       }
       else
       {
           temp=ocrimage;
       }
       temp.replace(".html", ".png");
       if (QFile::exists(temp) && flag==0)
       {
           ocrimage=temp;
           flag=1;
       }
       else
       {
           temp=ocrimage;
       }
       temp.replace(".txt", ".jpg");
       if (QFile::exists(temp) && flag==0)
       {
           ocrimage=temp;
           flag=1;
       }
       else
       {
           temp=ocrimage;
       }
       temp.replace(".html", ".jpg");
       if (QFile::exists(temp) && flag==0)
       {
           ocrimage=temp;
           flag=1;
       }
       else
       {
           temp=ocrimage;
       }

       //! select the image. look for jpeg, jpg and png(select first whichever is found)
       QFileInfo check_file(ocrimage);
       if (!(check_file.exists() && check_file.isFile()))
       {
           ocrimage.replace(".jpeg", ".jpg");
           check_file.setFile(ocrimage);
           if (!(check_file.exists() && check_file.isFile()))
           {
               ocrimage.replace(".jpg", ".png");
               check_file.setFile(ocrimage);
           }
       }

       //! Reads the OCR text file
       if(!ocrtext.isEmpty())
       {
           QFile sFile(ocrtext);
           if(sFile.open(QFile::ReadOnly | QFile::Text))
           {
               QTextStream in(&sFile);
               in.setCodec("UTF-8");
               qs1 = in.readAll().replace(" \n","\n");
               //! Displays an error if OCR text file is empty
               if(qs1=="")
               {
                   msgBox.setText("Error in Displaying File: "+ ocrtext+ "is Empty");
                   msgBox.exec();
                   return;
               }
               sFile.close();
           }
       }

       //! Reads the Corrector's Output file
       if(!correctortext.isEmpty())
       {
           QFile sFile(correctortext);
           if(sFile.open(QFile::ReadOnly | QFile::Text))
           {
               QTextStream in(&sFile);
               in.setCodec("UTF-8");
               qs2 = in.readAll();

               //! Displays an error if Corrector's Output file is empty
               if(qs2=="")
               {
                   msgBox.setText("Error in Displaying File: "+ correctortext + "is Empty");
                   msgBox.exec();
                   return;
               }
               sFile.close();
           }

       }
       QTextDocument doc;
       doc.setHtml(qs2);
       qs2 = doc.toPlainText().replace(" \n", "\n");

       int l1,l2, DiffOcr_Corrector; float correctorChangesPerc;

       l1 = mProject.GetGraphemesCount(qs1); l2 = mProject.GetGraphemesCount(qs2);

       diff_match_patch dmp;
       auto diffs1 = dmp.diff_main(qs1,qs2);

       //! Calculates the percentage of changes made by the corrector in OCR text file
       DiffOcr_Corrector = mProject.LevenshteinWithGraphemes(diffs1);
       correctorChangesPerc = ((float)(DiffOcr_Corrector)/(float)l2)*100;
       if(correctorChangesPerc>100) correctorChangesPerc = ((float)(DiffOcr_Corrector)/(float)l1)*100;
       correctorChangesPerc = (((float)lround(correctorChangesPerc*100))/100);

       QString title = "Compare Corrector Output " + QString::fromStdString(page) ;
       doc.setHtml(qs1);
       QString interntxt = doc.toPlainText();;
       doc.setHtml(qs2);
       QString ocroutput = doc.toPlainText();

       auto diffs = dmp.diff_main(qs1, qs2);
       auto html = dmp.diff_prettyHtml(diffs, "ffd13d");
       auto html1 = html[0];
       auto html2 = html[1];
       html1.remove("&para;");
       html2.remove("&para;");

       ui->current->setHtml(html1);
       ui->ocroutput->setHtml(html2);

       //!Load Image
       QImage image;
       image.load(ocrimage);
       scene->addPixmap(QPixmap::fromImage(image));
       setWindowTitle(title);
       ui->graphicsView->setScene(scene);

       //!Set corrector Change Percentage
       QString acc = QString::number(correctorChangesPerc,'f',2) + "%";
       ui->InternLabel->setText("<p><b>3. Corrector's Output Text</b></p>Changes made by Corrector: " + acc);
  }
}
void InternDiffView::on_NextButton_clicked()
{
   //! Extract page number from the localFilename
   string no = "";
   size_t loc;
   QString ext = "";
   if(!InternDiffView::GetPageNumber(pageNo, &no, &loc, &ext))
       return;

   //!check if file exists
   string pages = pageNo;
   pages.replace(loc,no.size(),to_string(stoi(no) + 1));
   QFile fcorrector(gDirTwoLevelUp+ "/CorrectorOutput/"+ QString::fromStdString(pages) );

    if(fcorrector.exists())
    {
      pageNo.replace(loc,no.size(),to_string(stoi(no) + 1));
      Load_comparePage(pageNo);
    }
    else{
        return;
    }
}

void InternDiffView::on_prevButton_clicked()
{
    //! Extract page number from the localFilename
    string no = "";
    size_t loc;
    QString ext = "";
    if(!InternDiffView::GetPageNumber(pageNo, &no, &loc, &ext))
        return;

    //!check if file exists
    string pages = pageNo;
    pages.replace(loc,no.size(),to_string(stoi(no) - 1));
    QFile fcorrector(gDirTwoLevelUp+ "/CorrectorOutput/"+ QString::fromStdString(pages) );

     if(fcorrector.exists())
     {
       pageNo.replace(loc,no.size(),to_string(stoi(no) - 1));
       QString nos = QString::fromStdString(to_string(stoi(no)-1));
       Load_comparePage(pageNo);
     }
     else{
         return;
     }

}

int InternDiffView::GetPageNumber(string localFilename, string *no, size_t *loc, QString *ext)
{
    string nos = "0123456789";
    *no = "";
    *loc = localFilename.find(".txt");
    *ext = "txt";
    if(*loc == string::npos) {
        *loc = localFilename.find(".html");
        *ext = "html";
    }
    if(*loc == string::npos)
        return 0;
    string s = localFilename.substr((*loc)-1,1);
    while(nos.find(s) != string::npos) {
        *no = s + *no; (*loc)--; s = localFilename.substr((*loc)-1,1);
    }
    return 1;
}
