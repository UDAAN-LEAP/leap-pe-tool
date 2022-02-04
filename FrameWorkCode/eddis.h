#ifndef EDDIS_H
#define EDDIS_H

#include <cassert>
#include <string>
#include <vector>
using namespace std;

class eddis {
public:
inline size_t min(size_t x, size_t y, size_t z);

size_t editDist(const string& A, const string& B);

};

#endif // EDDIS_H
