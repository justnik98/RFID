#include <iostream>
#include <fstream>
#include <cmath>
#include "utils.h"
#include "rfid.h"
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/vector_proxy.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/triangular.hpp>
#include <boost/numeric/ublas/lu.hpp>
using namespace std;
using namespace boost::numeric::ublas;
template<class T>
inline bool InvertMatrix (const matrix<T>& input, matrix<T>& inverse) {
    using namespace boost::numeric::ublas;
    typedef permutation_matrix<std::size_t> pMatrix;
    // create a working copy of the input
    matrix<T> A(input);
    // create a permutation matrix for the LU-factorization
    pMatrix pm(A.size1());
    // perform LU-factorization
    int res = lu_factorize(A,pm);
    if( res != 0 )
        return false;
    // create identity matrix of "inverse"
    inverse.assign(identity_matrix<T>(A.size1()));
    // backsubstitute to get the inverse
    lu_substitute(A, pm, inverse);
    return true;
}


int main() {
    //Input params
    int N=4;
    int Q = 6;
    int Nst = 1;
    int NFin = 100;
    int NStep = 1;
    int V = pow(2,Q);
    //#################
    double empty = 0;
    double success = 0;
    double conflict = 0;
   /* ofstream out("../theory.dat");
    int subFrame = pow(2.0, Q);
    for (N = Nst; N <= NFin; N += NStep) {
        conflict = 0;
        empty = pow((1.0 - (1.0 / subFrame)), N);
        success = pow((1.0 - (1.0 / subFrame)), N - 1) * (1.0 / subFrame) * N;
        /*for (auto i = 2; i <= N; i++) {
            conflict += (factorial(N) / factorial(i) / factorial(N - i)) * pow(1.0 / subFrame, i) *
                       pow(1.0 - 1.0 / subFrame, N - i);
        }
        conflict = 1 - empty -success;
        out << N << ' ' << success << ' ' << conflict << ' ' << empty << endl;
        cout << conflict + success + empty << endl;
    }*/
    auto p = create_matrix(N,V);
    std::cout << p << std::endl;
    identity_matrix<double> I (N+1);
    std::cout << I << std::endl;
    matrix <double> A (N+1,N+1) ;
    A=static_cast<matrix<double>>(I) - p;
    cout<<A<<endl;
    matrix<double> C (N+1,N+1);
    InvertMatrix(static_cast<matrix<double>>(I),C);
    cout<<C<<endl;
    matrix<double> product = prod(trans(A), A);
    std::cout<<product<<std::endl;
    matrix<double> inversion(N+1,N+1);
    bool inverted;
    inverted = InvertMatrix(product, inversion);
    std::cout << inversion << std::endl;
    auto B =  b_matrix(N);
    std::cout << B << std::endl;
    matrix<double> X;
    X=x_matrix(C,B);
    std::cout<<X<<endl;
   return 0;
  }
