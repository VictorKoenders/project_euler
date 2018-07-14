#include "number_utils.h"
#include "time_utils.h"
#include <map>

uint64_t get_chain_length(uint64_t n) {
    if(n == 1) return 1;
    else if(n % 2 == 0) return get_chain_length(n / 2) + 1;
    else return get_chain_length(n * 3 + 1) + 1;
}

int main(){
    measure_time([]{
        uint64_t highest_chain = 0;
        uint64_t highest_chain_index = 0;
        for(uint64_t i = 2; i < 1000000; i++){
            uint64_t length = get_chain_length(i);
            if(length > highest_chain) {
                highest_chain = length;
                highest_chain_index = i;
            }
        }
        std::cout << highest_chain_index << " has length " << highest_chain << std::endl;
    });
}