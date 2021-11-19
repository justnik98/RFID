//
// Created by User on 18.10.2021.
//

#include "utils.h"

double factorial(double num) {
    double tmp = 1;
    for (auto i = 2; i <= num; i++) {
        tmp *= i;
    }
    return tmp;
}
