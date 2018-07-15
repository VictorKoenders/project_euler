#include "time_utils.h"
#include "number_utils.h"
#include <vector>

bool is_abundant(uint64_t number){
    std::vector<uint64_t> divisors = get_divisable_numbers(number);
    uint64_t sum = 0;
    for(uint64_t divisor : divisors) {
        if(divisor == number) continue;
        sum += divisor;
    }
    return sum > number;
}

int main(){
    measure_time([]{
        std::vector<uint64_t> abundants;
        for(uint64_t i = 0; i < 28123; i++){
            if(is_abundant(i)){
                abundants.push_back(i);
            }
        }

        std::cout << "Found " << abundants.size() << " abundants" << std::endl;

        std::vector<uint64_t> numbers_not_summed_by_abundants;
        for(uint64_t i = 0; i < 28123; i++){
            bool is_summable = false;
            for(uint64_t j = 0; j < abundants.size() && !is_summable; j++){
                if(abundants[j] > i) break;
                for(uint64_t k = j; k < abundants.size() && !is_summable; k++){
                    if(abundants[k] > i) break;
                    if(abundants[k] + abundants[j] == i) {
                        is_summable = true;
                        break;
                    }
                }
            }
            if(!is_summable) {
                numbers_not_summed_by_abundants.push_back(i);
            }
        }
        std::cout << "Found " << numbers_not_summed_by_abundants.size() << " numbers that can not be summed by two abundants" << std::endl;

        uint64_t sum = 0;
        for(auto& number : numbers_not_summed_by_abundants) {
            sum += number;
        }
        std::cout << "The sum of these numbers is " << sum << std::endl;
    });
}