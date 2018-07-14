#include "string_utils.h"
#include "time_utils.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

std::vector<std::string> get_input() {
    std::ifstream file;
    file.open("problem_13_input.txt");
    if (!file)
    {
        std::cout << "Could not open file 'problem_13_input.txt'";
        exit(1);
    }
    std::vector<std::string> result;
    std::string line;
    while(file >> line) {
        result.push_back(line);
    }
    return result;
}
int main(){
    measure_time([]{
    auto lines = get_input();
    std::string result = "0";
    for(std::string line : lines) {
        auto new_result = sum_string(result, line);
        result = new_result;
    }
    std::cout << result << std::endl;;
    std::cout << result.substr(0, 10) << std::endl;;
    });
}