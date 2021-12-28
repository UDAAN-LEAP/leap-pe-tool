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
QVector <QString> editDistance(QString a, QString b)
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
            //solution [i,j] is the cost of transforming 0 to i of s1 and o to j of s2
            if (s1[i - 1]==(s2[j - 1]))
                   solution[i][j] = solution[i - 1][j - 1];
             else
            {
                //Assuming that the cost of insertion in s1 is 1
                int insertS1=solution[i - 1][j] + 1;
                //Assuming that the cost of insertion in s2 is 1, which is the same as cost of deletion in s1
                int insertS2=solution[i][j - 1] + 1;
                //Assuming that the cost of substitution in s1->s2 is 1
                int substituteS1S2= solution[i - 1][j - 1] + 1;
                solution[i][j] = min(insertS1, min(insertS2,substituteS1S2));
            }
         }
    }

    backtrace(s1,s2,solution);
    QVector <QString> something = phrase_heuristics(s1,s2);
    qDebug()<<"test"<<something;
    for (int i = 0;i < s1.count()+1;i++)
        delete[] solution[i];
    delete[] solution;
    return something;
}

void backtrace(QStringList s1, QStringList s2, int **solution)
{
    int si= s1.count();
    int sj= s2.count();
//    QVector<QString> optimalPath;

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

QVector <QString> phrase_heuristics(QStringList s1, QStringList s2)
{
    int size_edits = map_operations_list.size();
    int i = 0;
    QList <QList<QMap<QString, QString>>> segments_operations;
    QList <QList<QMap<int, int>>> segments_positions;
    QVector <QString> optimalPath;
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
        }
    }

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
            int replace_i_second = itr.key();
            int replace_j_second = itr.value();
            QString st1,st2;
            for (int itr=replace_i_first; itr<=replace_i_second; itr++)
            {

                st1 += s1[itr];
                st1 += " ";
            }
            for (int itr=replace_j_first; itr<=replace_j_second; itr++)
            {
                 st2 += s2[itr];
                 st2 += " ";
            }
            if(!optimalPath.contains(st1 + "=>" + st2)){
                optimalPath.append(st1 + "=>" + st2 );
            }
            //qDebug() <<"Substitution"<< st1 << " => " << st2;
            CPair_editDis[st1.toStdString()] = st2.toStdString();
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
                     st1 += " ";
                }
                if(!optimalPath.contains(st1 + "=>" + st2)){
                    optimalPath.append(st1 + "=>" + st2 );
                }
                //CPair_editDis[st1.toStdString()] = st2.toStdString();
//                qDebug() << st1 << " => " << st2;
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
                    optimalPath.append(st1 + "=>" + st2 );
                }
                //CPair_editDis[st1.toStdString()] = st2.toStdString();
//                qDebug() << st1 << " => " << st2;
            }
        }

//        qDebug()<<"hello i am here";
//        qDebug()<<segments_operations;
//        qDebug()<<segments_positions[seg][0];


    }
    return optimalPath;
}

int min(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}
