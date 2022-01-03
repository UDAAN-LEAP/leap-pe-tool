#include<QDomDocument>
#include<QGraphicsRectItem>
#include <QFileSystemWatcher>
#include <iostream>
#include <fstream>
#include <sstream>
#include<Project.h>
class markRegion {
public:
    Project & GetProject() {
        return mProject;
    }
   ~markRegion(){

    }

    void updateEntries(QDomDocument, QString, QString, QString, int);

    void createImageInfoXMLFile();

private:
Project mProject;
};

 // MARKREGION_H
