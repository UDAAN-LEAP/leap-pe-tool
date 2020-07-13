#include "Filters.h"

void Filter::parse_xml()
{
}

QString& Filter::get_name()
{
	return mName;
}

QVector<QString>& Filter::get_extensions()
{
	return mExtensions;
}
