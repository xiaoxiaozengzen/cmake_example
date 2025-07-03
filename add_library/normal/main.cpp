#include <iostream>

#include "add.hpp"

int main() {
    int a = 10;
    int b = 20;
    int c = Add(a, b);
    std::cout << "Addition of " << a << " and " << b << " is " << c << std::endl;
}