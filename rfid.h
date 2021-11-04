

#ifndef RFID_RFID_H
#define RFID_RFID_H
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <algorithm>
using namespace boost::numeric::ublas;
matrix <double> create_matrix (int N, int V);
matrix<double> b_matrix(int N);
template <class T> bool InvertMatrix (const matrix<T>& input, matrix<T>& inverse);
#endif //RFID_RFID_H
