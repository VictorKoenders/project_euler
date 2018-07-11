#include "number_utils.h"

int main(){
    uint64_t sum = 0;
    std::vector<uint64_t> primes = get_primes_below(2000000);
    for(uint64_t prime : primes) {
        sum += prime;
    }
    std::cout << sum << std::endl;
}