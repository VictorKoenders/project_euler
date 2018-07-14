#include "time_utils.h"
#include <ctime>
#include <iostream>

void measure_time(void (*fn)()){
    auto begin = clock();
    fn();
    auto end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    std::cout << "Finished in " << elapsed_secs << " seconds" << std::endl;
}