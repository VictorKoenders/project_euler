#include "number_utils.h"
#include "time_utils.h"

int main()
{
    measure_time([]{
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
    });
}