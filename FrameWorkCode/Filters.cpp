#include "Filters.h"
#include <string>
#include <QStringList>

Filter::Filter(const std::string & pName, const std::string & pExt) {
	m_name.fromStdString(pName);
	QString exts;
	exts.fromStdString(pExt);
	QRegExp exp(";");
	QStringList list = exts.split(QChar(';'));
	m_extensions = list;
}

QString Filter::name() const
{
	return m_name;
}

QStringList  Filter::extensions() const
{
	return m_extensions;
}
