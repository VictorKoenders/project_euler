#include <iostream>
#include <cstdint>
#include <cmath>
#include "number_utils.h"

int main(){
    uint64_t a = 0;
    while(a <= 1000){
        uint64_t b = a + 1;
        while(b <= 1000) {
            double c = sqrt(a * a + b * b);
            if(!is_integer(c)) {
                // C is not a whole number, so ignore this
                b++;
                continue;
            }
            if(c <= b) {
                // C has to be bigger than B, so we've gone too far!
                break; 
            }
            if(a + b + c == 1000) {
                std::cout << a << "^2 + " << b << "^2 = " << c << "^2" << std::endl;
                std::cout << (a*a) << " + " << (b*b) << " = " << (c*c) << std::endl;
                std::cout << "product: " << (a * b * c) << std::endl;
                return 0;
            }
            b++;
        }

        a++;
    }
    std::cout << "Could not find answer" << std::endl;
}