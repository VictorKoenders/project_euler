#include <iostream>
#include <cstdint>
#include "number_utils.h"

bool is_answer(uint64_t number){
    for(uint64_t divider = 20; divider > 0; divider--){
        if(number % divider == 0) {
            continue;
        }
        // std::cout << number << " can not be divided by " << divider << std::endl;
        return false;
    }
    return true;
}

int main(){
    uint64_t number = 20;
    while(!is_answer(number)){
        number += 20;
    }
    std::cout << "The answer is " << number << std::endl;
}