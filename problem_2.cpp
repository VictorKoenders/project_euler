#include <iostream>
#include <cstdint>

int main(){
    uint64_t current = 1, previous = 1;
    uint64_t sum = 0;
    while(true) {
        uint64_t next = current + previous;
        previous = current;
        current = next;
        if(current >= 4000000) {
            break;
        }

        if(current % 2 == 0) {
            sum += current;
        }
    }

    std::cout << sum << std::endl;
    return 0;
}
