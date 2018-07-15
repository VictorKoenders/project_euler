#include "time_utils.h"
#include <iostream>
#include "date_utils.h"

int main()
{
    measure_time([] {
        Date date;
        uint64_t count = 0;
        while(date.year < 1901) date.next();
        while (date.year <= 2000)
        {
            if (date.day == 1 && date.weekday == Weekday::Sunday)
            {
                count++;
            }
            date.next();
        }
        std::cout << "There are " << count << " 1st of jan's that were a sunday" << std::endl;
    });
}