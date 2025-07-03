#pragma once

#include <type_traits>

template<typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type>
int add(int a, int b) {
    return a + b;
}