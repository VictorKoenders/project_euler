#include "number_utils.h"
#include "time_utils.h"
#include <fstream>
#include <cassert>

int main()
{
    measure_time([] {
        std::ifstream file;
        file.open("problem_8_input.txt");
        if (!file)
        {
            std::cerr << "Could not open problem_8_input.txt" << std::endl;
            return;
        }
        std::vector<uint8_t> numbers;
        numbers.reserve(1000);

        char x;
        while (file >> x)
        {
            if (x >= '0' && x <= '9')
            {
                numbers.push_back(static_cast<uint8_t>(x - '0'));
            }
        }
        file.close();

        uint64_t highest_product = 0;
        size_t index = 0;
        for (size_t i = 0; i < numbers.size() - 13; i++)
        {
            uint64_t sum = static_cast<uint64_t>(numbers[i]);
            for (size_t j = i + 1; j < i + 13; j++)
            {
                sum *= static_cast<uint64_t>(numbers[j]);
            }
            if (sum > highest_product)
            {
                index = i;
                highest_product = sum;
            }
        }

        std::cout << "Highest product is " << highest_product << " found at index " << index << std::endl;
    });
}