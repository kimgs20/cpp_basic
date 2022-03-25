/*
std::fucntion
*/

#include <functional>
#include <iostream>
#include <string>

int some_func1(const std::string& a) {
    std::cout << "call Func1 " << a << std::endl;
    return 0;
}

struct S {
    void operator()(char c) { std::cout << "call Func2 " << c << std::endl; }
};


int main() {
    std::function<int(const std::string&)> f1 = some_func1;
    std::function<void(char)> f2 = S();
    std::function<void()> f3 = []() { std::cout << "call Func3 " << std::endl; };

    f1("hello");
    f2('c');
    f3();

    return 0;
}