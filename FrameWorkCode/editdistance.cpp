#include <editdistance.h>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <map>
#include <string>
#include <QMap>

using  namespace std;

map<string, string> CPair_editDis;

int editDistance(QString a, QString b)
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

//    qDebug()<<solution[s1.count()][s2.count()];
            //find the optimal path
    int si= s1.count();
    int sj= s2.count();
    QVector<QString> optimalPath;


    while(si>0 && sj >0){
                int current = solution[si][sj];

                // edge cases
                if (si - 1 < 0)
                {
//                    optimalPath.append("Delete '" + s1[si] + "'");
                    si--;
                    continue;
                }

                if (sj - 1 < 0)
                {
//                    optimalPath.append("Insert '" + s2[sj] + "'");
                    sj--;
                    continue;
                }

                // horizontal is for tracking insertion, vertical is for tracking deletion, diagonal is for substitution
                int horizontal = solution[si][sj-1];
                int vertical = solution[si-1][sj];
                int diagonal = solution[si-1][sj-1];




                if((diagonal <= horizontal && diagonal <= vertical) && (diagonal == current-1 || diagonal == current)){
                    // we never expect the diagonal < current - 1 otherwise current would have been diagonal + 1
                    if(diagonal == current -1){
                        //add to the Cword
                        optimalPath.append("Replace: "+s1[si-1]+" by "+s2[sj-1]);
                        CPair_editDis[s1[si-1].toStdString()] = s2[sj-1].toStdString();
                        si = si - 1;
                        sj = sj - 1;

                    }
                    else{
//                        optimalPath.append("Keep: "+s1[si-1]);
                        si=si-1;
                        sj=sj-1;

                    }
                }
                else if(horizontal <= diagonal && horizontal <= current-1){
//                    optimalPath.append("Insert: "+s2[sj-1]);
                    sj=sj-1;
                }
                else{
//                    optimalPath.append("Delete: "+s1[si-1]);
                    si=si-1;

                }


            }

            //Collections.reverse(optimalPath);
//            qDebug() << optimalPath;
            int ret = solution[s1.count()][s2.count()];
            for (int i = 0;i < s1.count()+1;i++)
                delete[] solution[i];
            delete[] solution;

            return ret;




}


int min(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}
