#ifndef EDITDISTANCE_H
#define EDITDISTANCE_H
#include <QString>
#include <map>
#include <string>

class edit_Distance{
public:
    QVector <QString> editDistance(QString , QString );
    int min(int ,int );
    QVector <QString> phrase_heuristics(QStringList, QStringList );
    void backtrace(QStringList, QStringList, int **);
    int getEditDistance(std::string first, std::string second);
    double findStringSimilarity(std::string first, std::string second);
    int getSimilarityValue(std::string str1, std::string str2);
    int matchPattern(std::string str1, int arLengthLeft, std::string str2, int arLengthRight);
    double DiceMatch(std::string string1, std::string string2);
};


extern std::map<std::string, std::string> CPair_editDis;
#endif // EDITDISTANCE_H
