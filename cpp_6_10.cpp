/*
template meta programming (TMP) 2
greatest common divisor (euclidean algorithm)
*/

#include <iostream>

/*
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a = 36, b = 24;

    std::cout << "gcd of (36, 24): " << gcd(a, b) << std::endl;

    return 0;
}
*/

template <int X, int Y>
struct GCD {
    static const int value = GCD<Y, X % Y>::value;
};

template <int X>
struct GCD<X, 0> {
    static const int value = X;
};

int main() {
    std::cout << "gcd of (36, 24): " << GCD<36, 24>::value << std::endl;

    return 0;
}