#include <string>
#include <iostream>
#include "time_utils.h"

std::string numbers[] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen"
};

std::string tens_names[] = {
    "zero",
    "ten",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety"
};

std::string number_to_english_string(uint64_t number){ 
    std::string result;
    if(number >= 1000) {
        uint64_t thousands = number / 1000;
        number %= 1000;
        result += numbers[thousands] + " thousand ";
    }
    if(number >= 100) {
        uint64_t hundreds = number / 100;
        number %= 100;
        result += numbers[hundreds] + " hundred ";
        if(number != 0) {
            result += "and ";
        }
    }
    if(number >= 20) {
        uint64_t tens = number / 10;
        number %= 10;
        result += tens_names[tens] + " ";
    }
    if(number > 0 || result.size() == 0) {
        result += numbers[number];
    }
    return result;
}
int main(){
    measure_time([]{
        uint64_t sum = 0;
        std::string text = number_to_english_string(342);
        for(char c : text) {
            if(c >= 'a' && c <= 'z') { sum++; }
        }
        std::cout << "342 = " << text << " = " << sum << " letters" << std::endl;
        sum = 0;
        text = number_to_english_string(115);
        for(char c : text) {
            if(c >= 'a' && c <= 'z') { sum++; }
        }
        std::cout << "115 = " << text << " = " << sum << " letters" << std::endl;
        sum = 0;

        for(uint64_t i = 1; i <= 1000; i++){
            text = number_to_english_string(i);
            for(char c : text) {
                if(c >= 'a' && c <= 'z') { sum++; }
            }
        }
        std::cout << sum << std::endl;
    });
}