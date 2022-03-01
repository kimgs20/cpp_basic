/*
template meta programming (TMP) 1
*/

#include <iostream>

template <int N>
struct Factorial {
    static const int result = N * Factorial<N - 1>::result;
};

// template specialization - end recursive loop
template <>
struct Factorial<1> {
    static const int result = 1;
};

int main() {
    std::cout << "6! = 1*2*3*4*5* = " << Factorial<6>::result << std::endl;
}

/*
why people care TMP?

pros
 - complie time calculation
 - runtime speed
 - can debug at compile

cons
 - complex
 - hard to debug
*/