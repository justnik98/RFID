#include "rfid.h"
#include "utils.h"
#include <cmath>
using namespace std;
matrix<double> create_matrix(int N, int V) {

    matrix<double> p(N + 1, N + 1);
    for (int i = 0; i < p.size1(); ++i)
        for (int j = 0; j < p.size2(); ++j)
            if (i < j) {
                p(i, j) = 0;
            } else {
                int k = 0;
                k = i - j;
                double p_sum = 0;
                for (auto l = k; l < min(V, i); l++) {
                    p_sum += (pow(-1, l) * pow(V - l, i - l)) / factorial(l - k) / factorial(V - l) / factorial(i - l);
                }
                p_sum *= (pow(-1, k) * factorial(V) * factorial(i)) / (pow(V, i) * factorial(k));
                p(i, j) = p_sum;
            }
    return p;
}
  matrix<double> b_matrix(int N) {
    matrix <double> b(N+1,1);
    for(auto i=0;i<N+1; i++){
        if(i==0){
            b(i,0)=0;
        }else{
            b(i,0)=1;
        }
  }
    return b;
}
/*matrix<double> x_matrix(matrix<double> A, matrix<double> B){
    matrix<double> X (A.size1(),B.size2());
    for(auto i=0; i<=A.size1();i++){        //size1() rows size2() cols
        for(auto j=0;j<=A.size2();j++){
            for(auto g=0; g<=A.size1(); g++) {
                X(i, j) += A(i, g) * B(g, j);
            }
        }
    }
return X;
}*/








