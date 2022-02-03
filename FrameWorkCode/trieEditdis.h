#ifndef TRIEEDITDIS_H
#define TRIEEDITDIS_H
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include "slpNPatternDict.h"
#include <cctype>
#include <vector>
//#include <boost/range/adaptor/reversed.hpp>

/*
 * Algorithm: Edit distance using a trie-tree (Dynamic Programming)
 * Author: Murilo Adriano Vasconcelos <muriloufg@gmail.com>
 */

using namespace std;

// Trie's node
struct trie
{
    typedef map<char, trie*> next_t;

    // The set with all the letters which this node is prefix
    next_t next;

    // If word is equal to "" is because there is no word in the
    //  dictionary which ends here.
    string word;

    trie() : next(map<char, trie*>()) {}

    void clear() { next.clear(); }

    void insert(string w)
    {
        w = string("$") + w;

        int sz = w.size();

        trie* n = this;
        for (int i = 0; i < sz; ++i) {
            if (n->next.find(w[i]) == n->next.end()) {
                n->next[w[i]] = new trie();
            }

            n = n->next[w[i]];
        }

        n->word = w;
    }
};




    //trie tree;
    //vector<pair<int,string>> min_str;
class trieEditDis {

public:
    int min_cost;

    void search_impl(trie* tree, char ch, vector<int> last_row, const string& word, vector<pair<int,string>>& min_str);

    vector<pair<int,string>> searchTrie(trie& tree, string word);

    void search_impl1(trie* tree, char ch, vector<int> last_row, const string& word, string& min_str);

    string searchTrie1(trie& tree, string word);

    void loadmaptoTrie(trie& tree,map<string,int > m2);

    vector<string> print5NearestEntries(trie& tree,string OCRWord);

    vector<string> print1OCRNearestEntries(string OCRWord, vector<string> vec);

    bool insertPatternsOf(string str, trie& TPWordsP, size_t& count);

    size_t loadPWordsPatternstoTrie(trie& TPWordsP, map<string,int >& PWords);

    string SamasBreakLRCorrect(string s1, map<string, int>& m1, map<string, int>& PWordsNew,trie& tree, trie& treeP);

};



#endif // TRIEEDITDIS_H
