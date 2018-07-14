#include "number_utils.h"
#include "time_utils.h"
#include <fstream>
#include <array>
#include <cassert>

enum class Direction
{
    Right,
    Bottom,
    BottomRight,
    BottomLeft,
};

const char *to_string(Direction direction)
{
    if (direction == Direction::Right)
        return "Right";
    if (direction == Direction::Bottom)
        return "Bottom";
    if (direction == Direction::BottomRight)
        return "BottomRight";
}

#define GRID_WIDTH 20
#define GRID_HEIGHT 20

typedef std::array<std::array<uint8_t, GRID_WIDTH>, GRID_HEIGHT> grid_t;

grid_t get_grid() {
    grid_t grid;
    std::ifstream file;
    file.open("problem_11_input.txt");
    if (!file)
    {
        std::cout << "Could not open file 'problem_11_input.txt'";
        exit(1);
    }

    char c;
    uint8_t x = 0;
    uint8_t y = 0;
    while ((file.get(c)))
    {
        if (c >= '0' && c <= '9')
        {
            uint8_t number = (c - '0') * 10;
            if (!(file.get(c)))
            {
                exit(2);
            }
            number += c - '0';
            grid[y][x] = number;
        }
        else if (c == ' ')
        {
            x++;
        }
        else if (c == '\n')
        {
            y++;
            x = 0;
        }
    }
    assert(x == 0);
    assert(y == GRID_HEIGHT);
    file.close();
    return grid;
}
int main()
{
    measure_time([]{
    grid_t grid = get_grid();
    uint64_t highest_product = 0;
    for (uint8_t y = 0; y < GRID_HEIGHT; y++)
    {
        for (uint8_t x = 0; x < GRID_WIDTH; x++)
        {
            if (x <= GRID_WIDTH - 4)
            {
                // calculate horizontal product
                uint64_t product = static_cast<uint64_t>(grid[y][x])
                                 * static_cast<uint64_t>(grid[y][x + 1])
                                 * static_cast<uint64_t>(grid[y][x + 2])
                                 * static_cast<uint64_t>(grid[y][x + 3]);
                if (product > highest_product)
                {
                    highest_product = product;
                }
            }
            if (y <= GRID_HEIGHT - 4)
            {
                // calculate vertical product
                uint64_t product = static_cast<uint64_t>(grid[y][x])
                                 * static_cast<uint64_t>(grid[y + 1][x])
                                 * static_cast<uint64_t>(grid[y + 2][x])
                                 * static_cast<uint64_t>(grid[y + 3][x]);
                if (product > highest_product)
                {
                    highest_product = product;
                }
            }
            if (x <= GRID_WIDTH - 4 && y <= GRID_HEIGHT - 4)
            {
                // calculate diagonal product from top-left to bottom-right
                uint64_t product = static_cast<uint64_t>(grid[y][x])
                                 * static_cast<uint64_t>(grid[y + 1][x + 1])
                                 * static_cast<uint64_t>(grid[y + 2][x + 2])
                                 * static_cast<uint64_t>(grid[y + 3][x + 3]);
                if (product > highest_product)
                {
                    highest_product = product;
                }
            }
            if (x >= 3 && y <= GRID_HEIGHT - 4)
            {
                // calculate diagonal product from top-right to bottom-left
                uint64_t product = static_cast<uint64_t>(grid[y][x])
                                 * static_cast<uint64_t>(grid[y + 1][x - 1])
                                 * static_cast<uint64_t>(grid[y + 2][x - 2])
                                 * static_cast<uint64_t>(grid[y + 3][x - 3]);
                if (product > highest_product)
                {
                    highest_product = product;
                }
            }
        }
    }
    std::cout << highest_product << std::endl;
});
}