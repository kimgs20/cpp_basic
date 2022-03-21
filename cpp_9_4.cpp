/*
perfect forwarding
*/

#include <iostream>
#include <vector>

template <typename T>
void wrapper(T& u) {
    std::cout << "T&" << std::endl;
    g(u);
}

template <typename T>
void wrapper(const T& u) {
    std::cout << "const T&" << std::endl;
    g(u);
}

class A {};

void g(A& a) { std::cout << "called lvalue reference" << std::endl; }
void g(const A& a) { std::cout << "called const lvalue reference" << std::endl; }
void g(A&& a) { std::cout << "called rvalue reference" << std::endl; }

int main() {
    A a;
    const A ca;

    std::cout << "- - - original - - -" << std::endl;
    g(a);
    g(ca);
    g(A());

    std::cout << "- - - wrapper - - -" << std::endl;
    wrapper(a);
    wrapper(ca);
    wrapper(A());

    return 0;
}