#ifndef SLPNPATTERNDICT_H
#define SLPNPATTERNDICT_H
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <cassert>
#include <string>
#include <unordered_map>
#include <QFile>
#include "eddis.h"
//#include <boost/serialization/map.hpp>
//#include <boost/serialization/vector.hpp>
//#include <boost/serialization/serialization.hpp>
//#include <boost/serialization/unordered_map.hpp>
//#include <boost/archive/text_iarchive.hpp>
//#include <boost/archive/text_oarchive.hpp>
//#include "toFromslp1.h"
using namespace std;

class slpNPatternDict{
public:
    //variables
    bool HinFlag = 0, SanFlag = 1;

    //functions

    string ReplaceString(string subject, const string& search, const string& replace);

    string ReplaceStringRestricted(string subject, const string& search, const string& replace);

    void loadFileCSV(map<string, vector<int>>& synonym, vector<vector<string>>& synrows, const string filename="");

    string toDev(string s);

    string toslp1(string s);

    void printmapinDev(map<string,int> m1);

    void printmap(map<string,int>& m1);

    void printmapstrstr(map<string,string>& m1);

    void printmapWFreq(map<string,int>& m1);

    void loadCwordsPair(string wordL,string wordR, map<string, string>& CPair,map<string,int>& Dict,map<string,int>&  PWords);

    void loadCPair(string filename, map<string, string>& CPair,map<string,int>&  Dict, map<string,int>&  PWords);

    void loadCwordsPairs(string wordL,string wordR, map<string, set<string> >& CPairs,map<string,int>& Dict,map<string,int>&  PWords);

    void loadCPairs(string filename, map<string, set<string> >& CPairs,map<string,int>&  Dict, map<string,int>&  PWords);

    void loadMapNV(string fileName, map<string,int>& OCRWords, vector<string>& vec, string GBook);

    int minIG(int a, int b);

    int maxIG(int a, int b);

    void loadMapPWords(vector<string>& vGBook,vector<string>& vIBook, map<string,int>& PWords);

    string findDictEntries1(string s1,  map<string, int>& m2, map<string, int>& m1, int size);

    string findDictEntries(string s1,  map<string, int>& m2, map<string, int>& m1, int size);

    bool hasM40PerAsci(string word1);

    bool hasNoAsci(string word1);

    void loadMap(string fileName, map<string,int>& OCRWords, string GBook);

    bool insertPatternstoMap(string str, map<string,int>& TPWordsP, size_t& count ,size_t& count6);

    size_t loadDictPatternstoMap(map<string,int >& TPWordsP, map<string,int >& PWords,size_t& count6);

    bool getNgramFeaturesinVect(string str,map<string,int>& Dict,vector<bool>& vb,vector<size_t>& vbf, size_t& count);

    bool endsWith(const std::string& s, const std::string& suffix);

    std::vector<std::string> split(const std::string& s, const std::string& delimiter, const bool& removeEmptyEntries = false);

    void removeEndCommonSpaces(string& str1, string& str2);

    bool searchS1inGVec(string s1,size_t iocrdone,vector<string>& gocr,size_t winig);

    string findDictEntries(string s1,  map<string, int>& m2, map<string, int>& m1);

    void find_and_replace(string& source, string const& find, string const& replace);

    string find_and_replace_oddInstancesblue(string source);

    string find_and_replace_oddInstancesorange(string source);

    void allignlcsnew(string& str1,string& str2,string& str3);


    // typedefs
    typedef std::vector<int> lengths;

    /*
      The "members" type is used as a sparse set for LCS calculations.
      Given a sequence, xs, and members, m, then
      if m[i] is true, xs[i] is in the LCS.
    */
    typedef std::vector<bool> members;

    /*
      Fill the LCS sequence from the members of a sequence, xs
      x - an iterator into the sequence xs
      xs_in_lcs - members of xs
      lcs - an output results iterator
    */

    template <typename it, typename ot>
    void set_lcs(it x, members const & xs_in_lcs, ot lcs);


    /*
      Calculate LCS row lengths given iterator ranges into two sequences.
      On completion, `lens` holds LCS lengths in the final row.
    */
    template <typename it>
    void lcs_lens(it xlo, it xhi, it ylo, it yhi, lengths & lens);

    /*
      Recursive LCS calculation.
      See Hirschberg for the theory!
      This is a divide and conquer algorithm.
      In the recursive case, we split the xrange in two.
      Then, by calculating lengths of LCSes from the start and end
      corners of the [xlo, xhi] x [ylo, yhi] grid, we determine where
      the yrange should be split.

      xo is the origin (element 0) of the xs sequence
      xlo, xhi is the range of xs being processed
      ylo, yhi is the range of ys being processed
      Parameter xs_in_lcs holds the members of xs in the LCS.
    */
    template <typename it>
    void calculate_lcs(it xo, it xlo, it xhi, it ylo, it yhi, members & xs_in_lcs);

    // Calculate an LCS of (xs, ys), returning the result in an_lcs.
    template <typename seq>
    void lcs(seq const & xs, seq const & ys, seq & an_lcs);

    bool isNonVowel(string ocrp);

    string removeSpaces(string input);

    void findConfisions(string ocr, string correct, vector<string>& vec);

    void findConfisionsNindex(string ocr, string correct, vector<string>& vec, vector<int>& vind);

    void appendConfusionsPairs(string str1, string str2, vector<string>& vec);

    string appendConfusionsPairsNindex(string str1, string str2, vector<string>& vec, vector<int>& vecind);

    void loadvectomap(vector<string> ConfP, map<string,int>& ConfPmap);

    void printvecstr(vector<string> ConfP);

    void printvecint(vector<int> ConfP);

    void loadConfusions(string fileName,map<string,int>& ConfPmap);

    void loadConfusions2(string fileName1,string fileName2,map<string,int>& ConfPmap);

    void loadConfusionsFont(vector<string> fileName1,vector<string> fileName2,map<string,int>& ConfPmap);

    void generateCorrectionPairs(vector<string> &wrong,vector<string> &right,string localFilenameI,string localFilenameC);

    void generatePairs(vector<string> &wrong,vector<string> &right,string localFilenameI,string localFilenameC);

    void generatePairsIEROCR(string localFilenameI,string localFilenameC, string Rep, string Repy);

    void generatePairsSpaced(vector<string> &wrong,vector<string> &right,string localFilenameI,string localFilenameC);

    void loadCPair(string fileName1,string fileName2,map<string,string>& CPair);

    void loadTopConfusions(map<string,int>& ConfPmap,map<string, string>& TopConfusions,map<string, int>& TopConfusionsMask);

    std::string tokenize(const std::string& s);

    void printConfusionRulesmap(map<string,int>& ConfPmap);

    int loadWConfusionsNindex1(string str1,string str2,map<string,int>& ConfPmap,vector<string>& wordConfusions,vector<int>& wCindex);

    string loadWConfusionsNindex(string str1,string str2,map<string,int>& ConfPmap,vector<string>& wordConfusions,vector<int>& wCindex);

    void replacestrcnf(string& newstring,size_t i,string cnfn);

    bool endswithHalanta(string str);

    void removeEndSpaces(string& str1);

    string deletePoornaVirams(string input);

    size_t cntSamas(string in, string& out);

    string SamasLR(string s1, map<string, int>& m1);

    string SamasRL(string s1, map<string, int>& m1);

    size_t minsize_t(size_t a,size_t b,bool& FlagLR);

    string print2OCRSugg(string str1, string str2, map<string,int>& ConfPmap,map<string,int>& Dict);

    string bestIG(string s1,string s2,map<string, int>& m1);

    void loadSandhiRules(string fileName, map<string, vector<string>>& SRules);

    void printSandhiRUles(map<string,vector<string> >& SRules);

    bool SamasCheck(string OCRNew, map<string, int>& Dict);

    bool SandhiCheck(string OCRNew, map<string, int>& Dict,map<string, vector<string>>& SRules);

    //Sandhi rules

    // OCR Word = BApyopetam
    string generatePossibilitesNsuggest(string OCRWord,map<string,string>& TopConfusions,map<string,int>& TopConfusionsMask,map<string, int>& Dict, map<string, vector<string>>& SRules);

};



#endif // SLPNPATTERNDICT_H
