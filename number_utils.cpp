#include "number_utils.h"
#include <sstream>
#include <cmath>

bool is_prime(uint64_t number) {
    for(uint64_t i = 2; i <= number / 2; i++){
        if(number % i == 0) {
            return false;
        }
    }
    return true;
}

bool is_palindrome(uint64_t number){
    std::ostringstream s;
    s << number;
    std::string text = s.str();

    for(size_t i = 0; i <= text.length(); i++){
        if(text[text.length() - i - 1] != text[i]){
            return false;
        }
    }
    return true;
}

bool is_integer(double number) {
    return number == trunc(number);
}

size_t number_length(uint64_t number){
    size_t size = 0;
    size_t comparison = 1;
    while(number > comparison) {
        comparison *= 10;
        size ++;
    }
    return size;
}

uint64_t factorial(uint64_t number) {
    uint64_t sum = 1;
    while(number > 1){
        sum *= number;
        number--;
    }
    return sum;
}
 
uint64_t factorial_sum(uint64_t number) {
    uint64_t sum = 0;
    while(number >= 1){
        sum += number;
        number--;
    }
    return sum;
}

/*
// Old version, runs in 0(n^n)

std::vector<uint64_t> get_primes_below(uint64_t target) {
    std::vector<uint64_t> result;
    for(uint64_t i = 2; i < target; i++){
        bool is_prime = true;
        for(uint64_t divider : result) {
            if(i % divider == 0) {
                is_prime = false;
                break;
            }
        }
        if(is_prime) {
            result.push_back(i);
        }
    }
    return result;
}
*/
std::vector<uint64_t> get_primes_below(uint64_t target) {
    std::vector<bool> numbers;
    std::vector<uint64_t> result;
    numbers.resize(static_cast<size_t>(target), false);
    for(uint64_t i = 2; i < target; i++){
        if(!numbers[i]) {
            result.push_back(i);
        }
        for(uint64_t j = i * 2; j < target; j += i) {
            numbers[j] = true;
        }
    }
    return result;
}

std::vector<uint64_t> get_divisable_numbers(uint64_t number)
{
    std::vector<uint64_t> result;
    uint64_t number_sqrt = sqrt(number);
    for(uint64_t i = 1; i <= number_sqrt; i++){
        if((number % i) == 0) {
            result.push_back(i);
            result.push_back(number / i);
        }
    }
    
    return result;
}
