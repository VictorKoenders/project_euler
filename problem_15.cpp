#include "number_utils.h"
#include "time_utils.h"

int main()
{
    measure_time([] {
        const int GRID_SIZE = 20;
        auto coefficient = calculate_binomial_coefficient<GRID_SIZE, GRID_SIZE, uint64_t>();

        std::cout << "Possible routes in a " << GRID_SIZE << "x" << GRID_SIZE << " grid is " << coefficient[GRID_SIZE][GRID_SIZE] << std::endl;
    });
}