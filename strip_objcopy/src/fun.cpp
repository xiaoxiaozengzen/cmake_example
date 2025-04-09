#include "fun.hpp"

void fun(int a) {
    int b = a;
    std::cout << "fun :" << b << std::endl;
    fun1();
}

void fun1() {
    int * a = nullptr;
    int b = *a;
    std::cout << "fun1 =" << b << std::endl;
}