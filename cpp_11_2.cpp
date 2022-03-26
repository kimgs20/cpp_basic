/*
std::function with member function
*/

#include <functional>
#include <iostream>
#include <string>

// 1.
/*
class A {
    int c;

    public:
        A(int c) : c(c) {}
        int some_func() { std::cout << "internal data: " << c << std::endl; }
};

int main() {
    A a(5);
    std::function<int()> f1 = a.some_func;

    return 0;
}
*/
// error: invalid use of non-static member function ‘int A::some_func()’

// 2.
class A {
    int c;

    public:
        A(int c) : c(c) {}
        int some_func() {
            std::cout << "non const fucntion: " << ++c << std::endl;
            return c;
        }

        int some_const_function() const {
            std::cout << "const function: " << c << std::endl;
            return c;
        }

        static void st() {}
};

int main() {
    A a(5);
    std::function<int(A&)> f1 = &A::some_func;
    std::function<int(const A&)> f2 = &A::some_const_function;

    f1(a);
    f2(a);

    return 0;
}