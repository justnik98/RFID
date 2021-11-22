#include <iostream>
#include <fstream>
#include <cmath>
#include "rfid.h"
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/lu.hpp>

using namespace std;
using namespace boost::numeric::ublas;

template<class T>
inline bool InvertMatrix(const matrix<T> &input, matrix<T> &inverse) {
    using namespace boost::numeric::ublas;
    typedef permutation_matrix<std::size_t> pMatrix;
    // create a working copy of the input
    matrix<T> A(input);
    // create a permutation matrix for the LU-factorization
    pMatrix pm(A.size1());
    // perform LU-factorization
    int res = lu_factorize(A, pm);
    if (res != 0)
        return false;
    // create identity matrix of "inverse"
    inverse.assign(identity_matrix<T>(A.size1()));
    // backsubstitute to get the inverse
    lu_substitute(A, pm, inverse);
    return true;
}

int main() {
    //Input params
    int N = 4;
    int Nst = 1;
    int NFin = 100;
    int NStep = 1;
    int V = 32;
    //#################
    auto p = create_matrix(N, V);
    identity_matrix<double> I(N + 1);
    matrix<double> A(N + 1, N + 1);
    A = static_cast<matrix<double>>(I) - p; // A = I(един) - P
    matrix<double> C(N + 1, N + 1);
    A(0, 0) = 1;
    InvertMatrix(static_cast<matrix<double>>(A), C);
    auto B = b_matrix(N);  // это вектор 0 1 1 1
    auto res = x_matrix(C, B);
    for (auto i = 0; i < N + 1; ++i) {
        std::cout << i << " : " << res(i, 0) << endl;
    }
    return 0;
}
