/*
constexpr
*/

#include <iostream>

// 1. template meta programming
/* template <int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
    static const int value = 1;
};

template <int N>
struct A {
    int operator()() { return N; }
};

int main() {
    A<Factorial<10>::value> a;

    std::cout << a() << std::endl;

    return 0;
} */

// 2. constexpr
// return type - constexpr: make return value as compile time constant
constexpr int Factorial(int n) {
    int total = 1;
    for (int i = 1; i <= n; i++) {
        total *= i;
    }
    return total;
}

template <int N>
struct A {
    int operator()() { return N; }
};

int main() {
    A<Factorial(10)> a;

    std::cout << a() << std::endl;

    return 0;
}