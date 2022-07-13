/*!
\class edit_Distance
\brief This class provides the functionality for suggestion of simliar words
       or nearest smilar word based on edit distance algorithm.
\sa    editDistance(), backtrace(), phrase_heuristics(), min()
*/
#include <editdistance.h>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <map>
#include <string>
#include <QMap>
#include <QList>
#include <QDebug>
#include <limits>
#include <QMap>
#include <QMapIterator>
#include <iostream>
using  namespace std;

map<string, string> CPair_editDis;
QList <QMap<QString, QString>> map_operations_list;
QList<QMap<int, int>> map_positions_list;

/*!
* \fn edit_Distance :: editDistance
* \brief This function takes two strings as argument then calculates the edit distance of both strings
*        ie. minimum number of operation required to convert string first to string second then
*        it returns the converted string and also it uses heuristics way to limit the searches.
* \param a
* \param b
*
* \return something
* \sa backtrace(), phrase_heuristics()
*/
QVector <QString> edit_Distance :: editDistance(QString a, QString b)
{
    QStringList s1,s2;

    QRegExp rx( "[ \t\n]" );

    s1=a.split( rx, QString::SkipEmptyParts );
    s2=b.split( rx, QString::SkipEmptyParts );

    int** solution = new int* [s1.count() + 1];

    for (int i = 0; i <= s1.count(); i++) {
        solution[i] = new int[s2.count() + 1];
    }

    //int solution[s1.count()+1][s2.count()+1];
    for (int i = 0; i <= s1.count(); i++)
    {
        solution[i][0] = i;
    }

    for (int i = 0; i <= s2.count(); i++)
    {
         solution[0][i] = i;
    }

    int m = s1.count();
    int n = s2.count();

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            //!solution [i,j] is the cost of transforming 0 to i of s1 and o to j of s2
            if (s1[i - 1]==(s2[j - 1]))
                   solution[i][j] = solution[i - 1][j - 1];
             else
            {
                //!Assuming that the cost of insertion in s1 is 1
                int insertS1=solution[i - 1][j] + 1;
                //!Assuming that the cost of insertion in s2 is 1, which is the same as cost of deletion in s1
                int insertS2=solution[i][j - 1] + 1;
                //!Assuming that the cost of substitution in s1->s2 is 1
                int substituteS1S2= solution[i - 1][j - 1] + 1;
                solution[i][j] = min(insertS1, min(insertS2,substituteS1S2));
            }
         }
    }

    backtrace(s1,s2,solution);
    QVector <QString> something = phrase_heuristics(s1,s2);
    for (int i = 0;i < s1.count()+1;i++)
        delete[] solution[i];
    delete[] solution;

    return something;
}

/*!
* \fn    edit_Distance :: backtrace
* \brief This function helps edit distance algorith by pointing to the previous cell which
*         was used in calculation of the cost to convert string first to string second.
* \param s1
* \param s2
* \param solution
*/
void edit_Distance :: backtrace(QStringList s1, QStringList s2, int **solution)
{
    int si= s1.count();
    int sj= s2.count();
   //!To trace back-trace path from the cost derived from cost of cell
    while (!(si==0 && sj==0))
    {
        QMap<QString, QString> temp_operations;
        QMap<int,int> temp_positions;
        int prev_cost = solution[si][sj];
        QVector<int> neighbours;
        if (si!=0 && sj!=0)
        {
            neighbours.append(solution[si-1][sj-1]);
        }
        if (si!=0)
        {
            neighbours.append(solution[si-1][sj]);
        }
        if (sj!=0)
        {
            neighbours.append(solution[si][sj-1]);
        }

        int min_cost = std::numeric_limits<int>::max();
        foreach(int i , neighbours)
        {
            min_cost = qMin(min_cost , i);
        }

        if(min_cost == prev_cost)
        {
            si = si - 1;
            sj = sj - 1;
            temp_operations.insert("type" , "match");
            temp_positions.insert(si , sj);
            map_operations_list.push_front(temp_operations);
            map_positions_list.push_front(temp_positions);
        }
        else if(si!=0 && sj!=0 && min_cost == solution[si-1][sj-1])
        {
            si = si-1;
            sj = sj-1;
            temp_operations.insert("type" , "substitution");
            temp_positions.insert(si , sj);
            map_operations_list.push_front(temp_operations);
            map_positions_list.push_front(temp_positions);
        }
        else if(si!=0 && min_cost == solution[si-1][sj])
        {
            si = si-1;

            temp_operations.insert("type" , "deletion");
            temp_positions.insert(si , sj);
            map_operations_list.push_front(temp_operations);
            map_positions_list.push_front(temp_positions);
        }
        else if(sj!=0 && min_cost == solution[si][sj-1])
        {
            sj = sj-1;
            temp_operations.insert("type" , "insertion");
            temp_positions.insert(si , sj);
            map_operations_list.push_front(temp_operations);
            map_positions_list.push_front(temp_positions);
        }
    }
}

/*!
* \fn    edit_Distance :: phrase_heuristics
* \brief This functions is used to eficiently retrieve the vocabulary terms likely to have
*        low edit distance to query items by restricting searches and then returning the optimal
*        path to convert string first to string second.
* \param s1
* \param s2
*
* \return optimalPath
*/
QVector <QString> edit_Distance :: phrase_heuristics(QStringList s1, QStringList s2)
{
    int size_edits = map_operations_list.size();
    int i = 0;
    QList <QList<QMap<QString, QString>>> segments_operations;
    QList <QList<QMap<int, int>>> segments_positions;
    QVector <QString> optimalPath;
    //!Used to create segment operations mapped list.
    while(i<size_edits)
    {

        if (map_operations_list[i]["type"] == "match")
        {
            i = i+1;
            continue;
        }
        else
        {
            QList <QMap<QString,QString>> final_operations_list;
            QList <QMap<int,int>> final_positions_list;

            while (i<size_edits && map_operations_list[i]["type"] != "match")
            {
                final_operations_list.push_back(map_operations_list[i]);
                final_positions_list.push_back(map_positions_list[i]);
                i = i+1;
            }
            segments_operations.push_back(final_operations_list);
            segments_positions.push_back(final_positions_list);
            final_operations_list.clear();
            final_positions_list.clear();

        }
    }

    //!For finding optimal path for conversion
    for (int seg=0; seg<segments_operations.size(); seg++)
    {
        QList<QString> se;
        for(int s=0; s<segments_operations[seg].size(); s++)
        {
            se.push_back(segments_operations[seg][s]["type"]);
        }
        if (se.contains("substitution"))
        {

            QMap<int,int>::iterator itr = segments_positions[seg][0].begin();
            int replace_i_first = itr.key();
            int replace_j_first = itr.value();
            itr = segments_positions[seg][segments_positions[seg].size() - 1].begin();
            int replace_i_second = itr.key()+1;
            int replace_j_second = itr.value()+1;
            QString st1,st2;
            for (int itr=replace_i_first; itr<replace_i_second; itr++)
            {

                st1 += s1[itr];
                st1 += " ";
            }
            for (int itr=replace_j_first; itr<replace_j_second; itr++)
            {
                 st2 += s2[itr];
                 st2 += " ";
            }
            if(!optimalPath.contains(st1 + "=>" + st2)){
                if(!(st1 == st2) && (st1 != "" && st2 != ""))
                optimalPath.append(st1 + "=>" + st2 );
            }
            CPair_editDis[st1.trimmed().toStdString()] = st2.trimmed().toStdString();
        }
        else
        {
            if (se[0] == "deletion")
            {
                QMap<int,int>::iterator itr = segments_positions[seg][0].begin();
                int replace_i_first = itr.key();
                itr = segments_positions[seg][segments_positions[seg].size() - 1].begin();
                int replace_i_second = itr.key();
                QString st1,st2;
                for (int itr=replace_i_first; itr<=replace_i_second; itr++)
                {
                     st1 += s1[itr];
                     //st1 += " ";
                }
                if(!optimalPath.contains(st1 + "=>" + st2)){
                    if(!(st1 == st2) && (st1 != "" && st2 != ""))
                    optimalPath.append(st1 + "=>" + st2 );
                }
            }
            else if (se[0] == "insertion")
            {
                QMap<int,int>::iterator itr = segments_positions[seg][0].begin();
                int replace_j_first = itr.value();
                itr = segments_positions[seg][segments_positions[seg].size() - 1].begin();
                int replace_j_second = itr.value();
                QString st1,st2;
                for (int itr=replace_j_first; itr<=replace_j_second; itr++)
                {
                     st2 += s2[itr];
                     st2 += " ";
                }
                if(!optimalPath.contains(st1 + "=>" + st2)){
                    if(!(st1 == st2) && (st1 != "" && st2 != ""))
                    optimalPath.append(st1 + "=>" + st2 );
                }
            }
        }




    }
    segments_operations.clear();
    segments_positions.clear();
    map_operations_list.clear();
    map_positions_list.clear();
    return optimalPath;
}

/*!
* \fn    edit_Distance :: min
* \brief This function compares a and b an returns the smaller one.
* \param a
* \param b
*
* \return a, b
*/
int edit_Distance :: min(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}

/*!
 * \fn    edit_Distance::getEditDistance
 * \brief This function takes two strings as argument then calculates the edit distance of both strings
 *        ie. minimum number of operation required to convert string first to string second.
 * \param first
 * \param second
 *
 * \return T[m][n]
 */
int edit_Distance :: getEditDistance(std::string first, std::string second)
{
    QStringList f = QString::fromStdString(first).split(" ", QString::SkipEmptyParts);
    QStringList s = QString::fromStdString(second).split(" ", QString::SkipEmptyParts);
    int m = f.count();
    int n = s.count();

    int** T = new int* [m + 1];

    for (int i = 0; i <= m; i++) {
        T[i] = new int[n + 1];
    }

    for (int i = 1; i <= m; i++) {
        T[i][0] = i;
    }

    for (int j = 1; j <= n; j++) {
        T[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int weight = f[i - 1] == s[j - 1] ? 0: 1;
            T[i][j] = std::min(std::min(T[i-1][j] + 1, T[i][j-1] + 1), T[i-1][j-1] + weight);
        }
    }
    return T[m][n];
}

/*!
 * \fn    edit_Distance::findStringSimilarity
 * \brief This function takes two strings as argument then calculates the similarity between them.
 * \param first
 * \param second
 *
 * \return double
 * \sa getEditDistance()
 */
double edit_Distance :: findStringSimilarity(std::string first, std::string second) {
    double max_length = std::max(first.length(), second.length());
    if (max_length > 0) {
        return (max_length - getEditDistance(first, second)) / max_length;
    }
    return 1.0;
}
//for string similarity
int edit_Distance ::matchPattern(std::string str1, int arLengthLeft, std::string str2, int arLengthRight)
{
    const char* arLeft = str1.c_str();
    const char* arRight = str2.c_str();

    int i, j, k, m;
    int arLength = 0;
    int arLengthLeftReset = 0;
    int arLengthRightReset = 0;

    for (i = 0; i < arLengthLeft - arLength; i++)
    {
        for (j = 0; j < arLengthRight - arLength; j++)
        {
            if (arLeft[i] == arRight[j] && arLeft[i + arLength] == arRight[j + arLength])
            {
                for (k = i + 1, m = j + 1; arLeft[k] == arRight[m] && k < arLengthLeft && m < arLengthRight; k++, m++);

                if (k - i > arLength)
                {
                    arLengthLeftReset = i;
                    arLengthRightReset = j;
                    arLength = k - i;
                }
            }
        }
    }

    if (arLength == 0) return 0;

    i = (arLengthLeftReset + arLength);
    j = (arLengthRightReset + arLength);

    arLengthLeft -= i;
    arLengthRight -= j;

    int leftMatch = (arLengthLeftReset != 0 && arLengthRightReset != 0) ? matchPattern(arLeft, arLengthLeftReset, arRight, arLengthRightReset) : 0;
    int rightMatch = (arLengthLeft != 0 && arLengthRight != 0) ? matchPattern(arLeft + i, arLengthLeft, arRight + j, arLengthRight) : 0;

    return arLength + leftMatch + rightMatch;
}
//! This is implementation of Ratcliff/Obershelp pattern-matching algorithm
//! it returns the similiraity index of two strings i.e., how similar or disimilar two strings are
//! it is Sequence based algorithm
//! Refer  https://itnext.io/string-similarity-the-basic-know-your-algorithms-guide-3de3d7346227 for more knowledge on this topic
//! jun 19 - sadam
int edit_Distance ::getSimilarityValue(std::string str1, std::string str2)
{
    int strLen1 = str1.length();
    int strLen2 = str2.length();
    if (strLen1 == 0 || strLen2 == 0) return 0;
    return (matchPattern(str1, strLen1, str2, strLen2) * 200) / (strLen1 + strLen2);
}

//! This is an implementation of Sorensen-Dice algorithm to calculate similarity between two strings
//! It is a Token based algorithm
double edit_Distance::DiceMatch(std::string string1, std::string string2)
{

        QStringList string1_bigrams;
        QStringList string2_bigrams;

        //base case
        if(string1.length() == 0 || string2.length() == 0)
        {
                return 0;
        }

        for(unsigned int i = 0; i < (string1.length() - 1); i++) {
            string tmp = string1.substr(i, 2);
            // extract character bigrams from string1
            QString qstr = QString::fromStdString(tmp);
                string1_bigrams.append(qstr);
        }
        for(unsigned int i = 0; i < (string2.length() - 1); i++) {      // extract character bigrams from string2
            string tmp1 = string2.substr(i, 2);
            QString qstr1 = QString::fromStdString(tmp1);
                string2_bigrams.append(qstr1);
        }

        int intersection = 0;

        // find the intersection between the two sets

        for(QStringList::iterator IT = string2_bigrams.begin();
            IT != string2_bigrams.end();
            IT++)
        {
                intersection += string1_bigrams.count((*IT));
        }

        // calculate dice coefficient
        int total = string1_bigrams.size() + string2_bigrams.size();
        float dice = (float)(intersection * 2) / (float)total;

        return dice;
}
