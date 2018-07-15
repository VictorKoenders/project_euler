#include "time_utils.h"
#include "string_utils.h"
#include <cmath>
#include <cstdint>
#include <iostream>

int main()
{
    measure_time([] {
        std::string number = "1";
        for(uint64_t i = 1; i <= 100; i++){
            number = multiply_string(number, i);
        }
        uint64_t sum = 0;
        for(char c : number) {
            sum += c - '0';
        }
        std::cout << sum << std::endl;
    });
}