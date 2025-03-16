#include "hello.hpp"

void hello(std::string* name) {
  std::cout << "Hello, " << *name << "!" << std::endl;
}