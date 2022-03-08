#ifndef VERIFYSET_H
#define VERIFYSET_H

#pragma once
#include <iostream>
#include <QString>
#include <pugixml.hpp>


enum error_codes
{
    node_name_error = 1,
    attribute_error,
    node_availability_error,
    project_file_opening_error
};


class VerifySet
{
public:
    VerifySet(QString projectXMLPath, QString projectXML_formatPath);
    int testProjectXML();
    bool LoadProjectXMLFormat();
    int getErrorCode();
    QString getErrorString();

private:
    pugi::xml_document doc;
    pugi::xml_document docFormat;
    QString SetDirectoryPath;
    std::string ProjectXMLPath;
    std::string ProjectXML_formatPath;
    bool verifyNode(pugi::xml_node nodeTest, pugi::xml_node nodeFormat);
    bool verifyNodeAttributes(pugi::xml_node nodeTest, pugi::xml_node nodeFormat);
    QString error_string = "";
    int error_code = 0;
};

#endif // VERIFYSET_H
