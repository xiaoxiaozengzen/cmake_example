#include <iostream>

#include "plus.h"

int main() {
    int a = 10;
    int b = 20;
    int c = plus<int, int>(a, b);
    int d = plus1<int>(a, b);
    std::cout << "Addition of " << a << " and " << b << " is " << c << std::endl;
    std::cout << "Addition of " << a << " and " << b << " is " << d << std::endl;
}