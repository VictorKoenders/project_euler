#include "string_utils.h"
#include <algorithm>
#include <iostream>

std::string sum_string(const std::string first, const std::string second)
{
    std::string result;
    result.reserve(std::max(first.size(), second.size()));
    int carry = 0;
    for (size_t i = 0; i < first.size() || i < second.size(); i++)
    {
        char left = first.size() > i ? first[first.size() - i - 1] : '0';
        char right = second.size() > i ? second[second.size() - i - 1] : '0';

        char result_char = carry + left + right - '0';
        carry = 0;
        while (result_char > '9')
        {
            carry++;
            result_char -= 10;
        }
        result.insert(0, 1, result_char);
    }
    while (carry > 0)
    {
        auto num = carry % 10;
        carry /= 10;
        result.insert(0, 1, '0' + num);
    }
    return result;
}
std::string multiply_string(const std::string first, uint64_t second) {
    std::string result;
    result.reserve(first.size());
    for(int32_t i = first.size() - 1; i >= 0; --i){
        uint64_t number = first[i] - '0';
        number *= second;

        size_t result_position = first.size() - i - 1;
        int carry = 0;
        while(number > 0 || carry > 0) {
            while(result.size() <= result_position) {
                result.push_back('0');
            }
            uint64_t n;
            if(number > 0) {
                n = number % 10;
                number = (number - n) / 10;
            } else {
                n = 0;
            }
            char c = n + result[result_position] + carry;
            carry = 0;
            while(c > '9') {
                c -= 10;
                carry++;
            }
            result[result_position] = c;
            result_position ++;
        }
    }
    std::reverse(result.begin(), result.end());

    return result;
}

std::vector<std::string> split(const std::string input, char delim)
{
    std::vector<std::string> result;
    auto i = 0;
    auto pos = input.find(delim);
    if (pos == std::string::npos)
        result.push_back(input.substr(i, input.length()));
    while (pos != std::string::npos)
    {
        result.push_back(input.substr(i, pos - i));
        i = ++pos;
        pos = input.find(delim, pos);

        if (pos == std::string::npos)
            result.push_back(input.substr(i, input.length()));
    }
    return result;
}
