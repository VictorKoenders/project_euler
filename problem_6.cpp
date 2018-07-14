#include <iostream>
#include <cstdint>
#include "time_utils.h"

int main(){
    measure_time([]{
    uint64_t sum_of_squared = 0;
    uint64_t sum_squared = 0;
    for(uint64_t i = 1; i <= 100; i++){
        sum_of_squared += i * i;
        sum_squared += i;
    }
    sum_squared *= sum_squared;
    uint64_t difference = (sum_squared > sum_of_squared) ? sum_squared - sum_of_squared : sum_of_squared - sum_squared;
    std::cout << "The sum of squared (1^2 + 2^2 ...) is " << sum_of_squared << std::endl;
    std::cout << "The squared sum (1 + 2 ...)^2 is " << sum_squared << std::endl;
    std::cout << "The difference is " << difference << std::endl;
    });
}