//
// Created by User on 18.10.2021.
//

#include "utils.h"

uint64_t factorial(uint32_t num) {
    uint64_t tmp=1;
    for(auto i=2; i<=num ; i++){
        tmp*=i;
    }
    return tmp;
}
