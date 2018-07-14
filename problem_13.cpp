#include "number_utils.h"
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

std::string sum_line(std::string first, std::string second){
    std::string result;
    result.reserve(std::max(first.size(), second.size()));
    int carry = 0;
    for(size_t i = 0; i < first.size() || i < second.size(); i++) {
        char left = first.size() > i ? first[first.size() - i - 1] : '0';
        char right = second.size() > i ? second[second.size() - i - 1] : '0';

        char result_char = carry + left + right - '0';
        carry = 0;
        while(result_char > '9') {
            carry++;
            result_char -= 10;
        }
        result.insert(0, 1, result_char);
    }
    while(carry > 0) {
        auto num = carry % 10;
        carry /= 10;
        result.insert(0, 1, '0' + num);
    }
    return result;
}

int main(){
    auto lines = get_input();
    std::string result = "0";
    for(std::string line : lines) {
        auto new_result = sum_line(result, line);
        result = new_result;
    }
    std::cout << result << std::endl;;
    std::cout << result.substr(0, 10) << std::endl;;
}