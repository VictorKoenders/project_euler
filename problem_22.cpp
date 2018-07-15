#include "time_utils.h"
#include "string_utils.h"
#include <fstream>
#include <algorithm>
#include <iostream>

std::vector<std::string> get_names() {
    std::ifstream file;
    file.open("problem_22_input.txt");
    if(!file) {
        std::cout << "Could not open \"problem_22_input.txt\"";
        exit(-1);
    }
    std::string line;
    if(!(file >> line)) {
        std::cout << "Could not read line";
        exit(-2);
    }
    std::vector<std::string> names = split(line, ',');
    for(std::string& name : names) {
        name.erase(0, 1);
        name.erase(name.size() - 1, 1);
    }
    return names;
}
int main(){
    measure_time([]{
        auto names = get_names();
        std::sort(names.begin(), names.end());
        uint64_t sum = 0;
        for(uint64_t i = 0; i < names.size(); i++ ){
            uint64_t value = 0;
            for(char c : names[i]){
                value += c - 'A' + 1;
            }
            uint64_t name_value = value;
            value *= i + 1;
            sum += value;
        }
        std::cout << "The sum of all names * positions is " << sum << std::endl;
    });
}