#include "string_utils.h"
#include "time_utils.h"
#include <iostream>

int main(){
    measure_time([]{ 
        std::string result = "1";
        for(uint64_t i = 0; i < 1000; i++){
            result = sum_string(result, result);
        }
        std::cout << "2^1000 = " << result << std::endl;
        uint64_t sum = 0;
        for(char c : result){
            sum += (c - '0');
        }
        std::cout << "The sum of all digits is " << sum << std::endl;
    });
}