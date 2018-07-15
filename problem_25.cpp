#include "string_utils.h"
#include "time_utils.h"
#include <iostream>

int main(){
    measure_time([]{
        std::string first = "1";
        std::string second = "1";
        uint64_t count = 2;
        while(true) {
            std::string next = sum_string(first, second);
            count++;
            if(next.size() >= 1000) {
                std::cout << "F" << count << " contains " << next.size() << " digits" << std::endl;
                std::cout << next << std::endl;
                break;
            }
            first = second;
            second = next;
        }
    });
}