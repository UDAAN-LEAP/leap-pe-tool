#pragma once
#include <string>
#include <QString>
#include <QVector>
#include "3rdParty/RapidXML/rapidxml.hpp"
class Filter {
public:
	void parse_xml();
	QString & get_name();
	QVector<QString> & get_extensions();
private:
	QString mName;
	QVector<QString> mExtensions;
};