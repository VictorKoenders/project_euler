#include <string>
#include <iostream>
#include <cstdint>
#include <vector>
#include <array>

bool is_prime(uint64_t number);
bool is_palindrome(uint64_t number);
bool is_integer(double number);
size_t number_length(uint64_t number);
uint64_t factorial(uint64_t number);
uint64_t factorial_sum(uint64_t number);
std::vector<uint64_t> get_primes_below(uint64_t target);
std::vector<uint64_t> get_divisable_numbers(uint64_t number);

template<int WIDTH, int HEIGHT, class TYPE>
std::array<std::array<TYPE, HEIGHT + 1>, WIDTH + 1> calculate_binomial_coefficient(){
    std::array<std::array<uint64_t, HEIGHT + 1>, WIDTH + 1> coefficient;

    for(uint64_t x = 0; x <= WIDTH; x++){
        coefficient[x][0] = 1;
    }
    for(uint64_t y = 0; y <= HEIGHT; y++){
        coefficient[0][y] = 1;
    }
    for(uint64_t x = 1; x <= WIDTH; x++){
        for(uint64_t y = 1; y <= HEIGHT; y++){
            coefficient[x][y] = coefficient[x-1][y] + coefficient[x][y - 1];
        }
    }
    return coefficient;
}
