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
    int N = 20;
    int V = 4;
    //#################
    auto p = create_matrix(N, V);
    std::cout << p << std::endl << endl;
    identity_matrix<double> I(N + 1);
    matrix<double> A(N + 1, N + 1);
    A = static_cast<matrix<double>>(I) - p; // A = I(един) - P
    cout << A << endl << endl;
    A(0, 0) = 1;
    matrix<double> C(N + 1, N + 1);
    InvertMatrix(static_cast<matrix<double>>(A), C);
    cout << C << endl;
    auto B = b_matrix(N);  // это вектор 0 1 1 1
    std::cout << B << std::endl;
    std::cout << x_matrix(C, B) << endl;
    return 0;
}
