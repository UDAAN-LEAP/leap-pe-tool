#ifndef MEANSTDPAGE_H
#define MEANSTDPAGE_H
#include <QString>
#include "slpNPatternDict.h"
#include<string>
#include<vector>
using namespace std;

class meanStdPage {
public:
    bool findMeanStd(double& mean, double& std,double& error, QString localmFilename1,QString localmFilename2, map<string, int>& GBook,map<string,int>&  PWords);

};


#endif // MEANSTDPAGE_H
