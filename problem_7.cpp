#include "number_utils.h"
#include "time_utils.h"

int main() {
    measure_time([]{
    uint64_t number = 0;
    uint64_t count = 0;
    while(count <= 10001) {
        number++;
        if(is_prime(number)) count++;
    }
    std::cout << "The 10001's prime is: " << number << std::endl;
    });
}