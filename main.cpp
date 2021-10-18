#include <iostream>
#include <fstream>
#include <cmath>
#include "utils.h"

using namespace std;


int main() {
    //Input params
    int N;
    int Q = 6;
    int Nst = 1;
    int NFin = 100;
    int NStep = 1;
    //#################
    double empty = 0;
    double success = 0;
    double conflict = 0;
    ofstream out("../theory.dat");
    int subFrame = pow(2.0, Q);
    for (N = Nst; N <= NFin; N += NStep) {
        conflict = 0;
        empty = pow((1.0 - (1.0 / subFrame)), N);
        success = pow((1.0 - (1.0 / subFrame)), N - 1) * (1.0 / subFrame) * N;
        /*for (auto i = 2; i <= N; i++) {
            conflict += (factorial(N) / factorial(i) / factorial(N - i)) * pow(1.0 / subFrame, i) *
                       pow(1.0 - 1.0 / subFrame, N - i);
        }*/
        conflict = 1 - empty -success;
        out << N << ' ' << success << ' ' << conflict << ' ' << empty << endl;
        cout << conflict + success + empty << endl;
    }
    return 0;
}
