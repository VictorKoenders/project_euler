#include <iostream>
#include <cstdint>
#include "time_utils.h"

bool is_multiple_of_3_or_5(uint32_t num){
    return num % 3 == 0 || num % 5 == 0;
}

int32_t main() {
    measure_time([] {
        uint32_t sum = 0;
        for(uint32_t i = 0; i < 1000; i++){
            if(is_multiple_of_3_or_5(i)){
                sum += i;
            }
        }
        std::cout << sum << std::endl;
    });
    return 0;
}
