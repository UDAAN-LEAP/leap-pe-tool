#include "markRegion.h"
#include<QFile>
#include<QTextStream>
#include<QDir>

extern QString gDirOneLevelUp,gDirTwoLevelUp,gCurrentPageName, gCurrentDirName;


//! Updating entries for figure/table/equation pagewise in image.xml
void markRegion::updateEntries(QDomDocument document, QString filename,QString PageNo, QString s2, int i)
{
    QDomElement root = document.documentElement();
    QDomElement Component=root.firstChild().toElement();

    while(!Component.isNull())       // Loop while there is a child
    {
        //! Check if the child tag name is COMPONENT
        if (Component.tagName()=="page"+PageNo)
        {
            QDomElement Child=Component.firstChild().toElement();
            while (!Child.isNull())
            {
                if (s2 == "Figure" && Child.tagName()=="figure")
                {
                    Child.childNodes().at(0).setNodeValue(QString::number(i));
                }
                else if (s2 == "Table" && Child.tagName()=="table")
                {
                    Child.childNodes().at(0).setNodeValue(QString::number(i));
                }
                else if (s2 == "Equation" && Child.tagName()=="equation")
                {
                    Child.childNodes().at(0).setNodeValue(QString::number(i));
                }

                Child = Child.nextSibling().toElement();       // Next child
            }
        }
        Component = Component.nextSibling().toElement();        // Next component
     }
    QFile f(filename);
    f.open(QIODevice::WriteOnly);
    QTextStream stream;
    stream.setDevice(&f);
    stream.setCodec("UTF-8");
    document.save(stream,4);
    f.close();
}




//! Genearte image.xml for figure/table/equation entries and initialize these values by 1 iff when this file does not exist.
void markRegion::createImageInfoXMLFile()
{
    QDomDocument document;

    // Add processing instructions that are XML instructions
    QDomProcessingInstruction instruction;
    instruction = document.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
    document.appendChild(instruction);

    // add root element
    QDomElement root = document.createElement("BookSet");
    document.appendChild(root);

    //add some elements
    QString strI = gDirTwoLevelUp + "/Inds";
    QDir directory(strI);
    QStringList list1 = directory.entryList(QStringList() << "*.txt",QDir::Files);
    int counter_i = 1;
    for ( const auto& i : list1 )
    {
        QStringList PageNo = i.split(QRegExp("[-.]"));
        QDomElement tagPage = document.createElement("page"+PageNo[1]);
        tagPage.setAttribute("count", counter_i);
        root.appendChild(tagPage);

        QDomElement tagImage = document.createElement("figure");
        tagPage.appendChild(tagImage);
        QDomText NoImage = document.createTextNode("1");
        tagImage.appendChild(NoImage);

        QDomElement tagTable = document.createElement("table");
        tagPage.appendChild(tagTable);
        QDomText NoTable = document.createTextNode("1");
        tagTable.appendChild(NoTable);

        QDomElement tagEquation = document.createElement("equation");
        tagPage.appendChild(tagEquation);
        QDomText NoEquation = document.createTextNode("1");
        tagEquation.appendChild(NoEquation);
        counter_i++;
    }

    QString filename12 = mProject.GetDir().absolutePath() + "/image.xml";
    if(!QFileInfo::exists(filename12))
    {
        QFile file(filename12);

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
            qDebug()<<"Failed to open xml file";
            return;
        }
        else{
            QTextStream out(&file);
            out << document.toString();
            file.close();
            qDebug()<<"Writing to xml file";
        }
    }
}