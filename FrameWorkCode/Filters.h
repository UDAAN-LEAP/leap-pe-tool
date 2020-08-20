#pragma once
#include <string>
#include <QString>
#include <QVector>
#include <QStringList>
#include "3rdParty/RapidXML/rapidxml.hpp"
#include <QMetaType>
class Filter {
public:
	//Name of Filter and Extensions it takes
	Filter() = default;
	Filter(const std::string& pName, const std::string & pExts);
	
	Filter(const Filter & fil) = default;
	Filter & operator=(const Filter& f) = default;
	QString  name() const;
	QStringList  extensions() const;
	void setName(QString name) {
		m_name = name;
	}
	void setExtensions(QStringList extensions) {
		m_extensions = extensions;
	}
	~Filter() = default;
private:
	QString m_name;
	QStringList m_extensions;
};
Q_DECLARE_METATYPE(Filter);