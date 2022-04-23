/*
std::variant
*/

#include <iostream>
#include <memory>
#include <variant>

class A {
    public:
        void a() { std::cout << "A" << std::endl; }
};

class B {
    public:
        void b() { std::cout << "B" << std::endl; }
};

std::variant<A, B> GetDataFromDB(bool is_a) {
    if (is_a) {
        return A();
    }
    return B();
}


int main() {
    auto v = GetDataFromDB(true);

    std::cout << v.index() << std::endl;
    std::get<A>(v).a();

    return 0;
}