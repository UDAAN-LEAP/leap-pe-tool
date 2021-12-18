#ifndef EDITDISTANCE_H
#define EDITDISTANCE_H
#include <QString>
#include <map>
#include <string>
QVector <QString> editDistance(QString , QString );
int min(int ,int );
QVector <QString> phrase_heuristics(QStringList, QStringList );
void backtrace(QStringList, QStringList, int **);


extern std::map<std::string, std::string> CPair_editDis;

#endif // EDITDISTANCE_H
