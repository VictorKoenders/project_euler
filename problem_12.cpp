#include "number_utils.h"
#include <ctime>

int main()
{
    clock_t begin = clock();
    uint64_t sum = 0;
    for (uint64_t i = 1;; i++)
    {
        sum += i;
        auto dividers = get_divisable_numbers(sum);
        if (dividers.size() > 500)
        {
            std::cout << sum << std::endl;
            break;
        }
    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    std::cout << "Calculated in " << elapsed_secs << " seconds" << std::endl;
}