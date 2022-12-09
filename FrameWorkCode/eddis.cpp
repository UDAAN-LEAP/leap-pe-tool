/*!
\class size_t eddi
\brief This class provides the functionality for suggestion of simliar words
       or nearest smilar word based on edit distance algorithm.
\sa    min(),editDist()
*/
#include <cassert>
#include <string>
#include <vector>
#include "eddis.h"

/*!
 * \fn size_t eddis :: min
 * \brief This functions compares x,y and z an returns the smallest one among them.
 * \param x
 * \param y
 * \param z
 * \return x,y,z
 */
size_t eddis :: min(size_t x, size_t y, size_t z)
{
        if (x < y)
            return x < z ? x : z;
        else
            return y < z ? y : z;
}

/*!
 * \fn size_t eddis::editDist
 * \brief This function takes two strings as argument then calculates the edit distance of both strings
 *        ie. minimum number of operation required to convert string first to string second then
 *        it returns the converted string
 * \param A
 * \param B
 * \return M[A.size()][B.size()]
 * \sa min()
 */
size_t eddis::editDist(const string& A, const string& B)
{
    size_t NA = A.size();
       size_t NB = B.size();

       vector<vector<size_t>> M(NA + 1, vector<size_t>(NB + 1));

       for (size_t a = 0; a <= NA; ++a)
           M[a][0] = a;

       for (size_t b = 0; b <= NB; ++b)
           M[0][b] = b;

       for (size_t a = 1; a <= NA; ++a)
           for (size_t b = 1; b <= NB; ++b)
           {
               size_t x = M[a-1][b] + 1;
               size_t y = M[a][b-1] + 1;
               size_t z = M[a-1][b-1] + (A[a-1] == B[b-1] ? 0 : 1);
               M[a][b] = min(x,y,z);
           }

       return M[A.size()][B.size()];
}
