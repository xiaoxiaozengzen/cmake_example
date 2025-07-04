#pragma once

#include <type_traits>

template <class T, class = typename std::enable_if<std::is_integral<T>::value>::type>
int plus(int a, int b) {
    return a + b;
}

template <class T>
typename std::enable_if<std::is_integral<T>::value, T>::type
plus1(T a, T b) {
    return a + b;
}

int plus(int a, int b);
