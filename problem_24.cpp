#include "string_utils.h"
#include "time_utils.h"
#include <iostream>

int main()
{
    measure_time([] {
        std::string set = "0123456789";
        uint64_t count = 0;
        do
        {
            count++;
            if (count == 1000000)
            {
                std::cout << "The one millionth lexograph is " << set << std::endl;
                break;
            }
        } while (calculate_next_lexicographic_permutation(set));
        std::cout << "Ended at " << count << " lexographs" << std::endl;
    });
}