/*!
\class meanStdPage
\brief meanStdPage class provides functionality to calculate mean and standerd deviation
       of words in a page.
\sa    findMeanStd()
*/
#include <QString>
#include "slpNPatternDict.h"
#include<string>
#include<vector>
#include "cmath"
#include "meanStdPage.h"
using namespace std;

/*!
 * \fn    meanStdPage :: findMeanStd
 * \brief This function is used to find mean and standerd deviation in a page to do that it first
 *        calculates the number of words in the page and then using count it finds mean and standerd deviation.
 * \param std
 * \param error
 * \param localmFilename1
 * \param localmFilename2
 * \param GBook
 * \param PWords
 * \return 0,1
 */
bool meanStdPage :: findMeanStd(double& mean, double& std,double& error, QString localmFilename1,QString localmFilename2, map<string, int>& GBook,map<string,int>&  PWords)
{
    std::ifstream ssCPage(localmFilename1.toUtf8().constData());
    string localstr;
    vector<string> vCPage;
    slpNPatternDict slnp;

    if (ssCPage.is_open())
    {
        while(ssCPage >> localstr)
        {
            vCPage.push_back(slnp.toslp1(localstr));
            /*cout << localstr << endl;*/
        }
    }
    else
        return 0; ssCPage.close();

    // count no. of words in present page
    int szWordsI =0; string szWordsIstr;
    std::ifstream ssIPagec(localmFilename2.toUtf8().constData());

    while(ssIPagec >> szWordsIstr)    //counts no of words in a page
        szWordsI ++;

    //window
    int vsz = vCPage.size();
    int win = szWordsI - vsz;

    if(win < 0)
        win = -1*win;

    win = std::max(win,5);
    std::ifstream ssIPage(localmFilename2.toUtf8().constData());
    //string localstr;
    int i = 0;
    size_t countBGWords = 0, countBGWordslen = 0,sumSq = 0;
    size_t countBGCorrectWords = 0;

    if (ssIPage.is_open()){

        while(ssIPage >> localstr)
        {
            localstr = slnp.toslp1(localstr);
            if((GBook[(localstr)] > 0) || (PWords[localstr] > 0))
            {
                for(int t1 = std::max(i-win,0); t1 < min(i+win,vsz); t1++)
                {
                    if (vCPage[t1] == localstr)
                    {
                        /*cout <<  vCPage[t1] << " " << localstr<< endl;*/
                        countBGCorrectWords++;
                        break;
                    }
                }
                size_t sz = localstr.size(); //cout << "data " << sz << endl;
                countBGWords ++; countBGWordslen += sz;  sumSq += (sz*sz);
            }
            i++;
        }
        //cout << endl << endl;
        mean = countBGWordslen/countBGWords; std = sqrt((sumSq - (countBGWords*mean*mean))/(countBGWords - 1)); error = 100*(countBGWords - countBGCorrectWords)/countBGWords;
    } else
        return 0;
    return 1;
}
