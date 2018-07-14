#include "number_utils.h"
#include "time_utils.h"

int main(){
    measure_time([] {
    uint64_t number = 600851475143;
    // uint64_t number = 13195;

    uint64_t divider = 3;
    while(true){
        uint64_t remainder = number % divider;
        if(remainder == 0) {
            std::cout << "Dividable by " << divider << std::endl;
            number /= divider;
            std::cout << "New number: " << number << std::endl;
            if(is_prime(number)) {
                std::cout << "This is a prime, we're done!" << std::endl;
                break;
            }
            continue;
        }
        // find the next divider that's a prime and less than half of the remaining number
        // If the divider is larger than half of the remaining number, it will never devide
        while(true){
            divider ++;
            if(divider > number / 2) {
                std::cout << "Divider is larger than half of the number, this should not happen" << std::endl;
                return;
            }
            if(is_prime(divider)){
                break;
            }
        }
    }
    });
    return 0;
}