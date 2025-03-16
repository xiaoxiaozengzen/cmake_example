#include <iostream>

int main() {
#ifdef My_DA
    std::cout << "Hello! MY_DA" << std::endl;
#elif defined(My_DB) 
    std::cout << "Hello, MY_DB!" << std::endl;
#else
    std::cout << "Hello, World!" << std::endl;
#endif
    return 0;
}