#include <iostream>
#include <cstdint>
#include "number_utils.h"

int main(){
    // The largest number that can be created by the product of 
    // 2 3-digit numbers, is 999x999 = 998_001
    // So we go backwards from there, and find the first palindrome
    // Then we'll need to figure out what to divide it by

    uint64_t number = 998001;
    while(true){
        number--;
        while(!is_palindrome(number)) {
            number --;
        }
        std::cout << "Trying palindrome " << number << std::endl;

        // now we find the smallest 3-digit number that this divides by
        // And see if it results in another 3-digit number
        for(uint64_t i = 100; i <= 999; i++){
            if(number % i == 0) {
                uint64_t result = number / i;
                if(number_length(result) == 3) {
                    // we found our number!
                    std::cout << "This number is dividable by:" << std::endl;
                    std::cout << " - " << i << std::endl;
                    std::cout << " - " << result << std::endl;
                    return 0;
                }
            }
        }

        std::cout << "This number is not dividable by anything..." << std::endl;
    }
}