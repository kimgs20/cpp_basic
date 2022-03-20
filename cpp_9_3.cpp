/*
move semantics

ex) 3 times of useless copy

template <typename T>
void swap(T &a, T &b) {
    T tmp(a);
    a = b;
    b = tmp;
}
*/

#include <iostream>
#include <utility>

class A {
    public:
        A() { std::cout << "call constructor" << std::endl; }
        A(const A& a) { std::cout << "call const constructor" << std::endl; }
        A(A&& a) { std::cout << "call move constructor" << std::endl; }
};

int main() {
    A a;

    std::cout << " - - - " << std::endl;
    A b(a);

    std::cout << " - - - " << std::endl;
    A c(std::move(a));

    return 0;
}