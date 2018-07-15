#include "time_utils.h"
#include "number_utils.h"
#include <iostream>
#include <cstdint>

uint64_t d(uint64_t number){
    auto numbers = get_divisable_numbers(number);
    uint64_t sum = 0;
    for(uint64_t num : numbers) {
        if(num >= number) continue;
        sum += num;
    }
    return sum;
}

int main(){
    measure_time([]{
        uint64_t sum = 0;
        for(uint64_t i = 1; i <= 10000; i++){
            uint64_t pair = d(i);
            if(pair == i) continue;
            uint64_t reverse_pair = d(pair);
            if(reverse_pair == i) {
                std::cout << i << " and " << pair << " are a pair" << std::endl;
                sum += i;
            }
        }
        std::cout << "The sum of all pairs is " << sum << std::endl;
    });
}