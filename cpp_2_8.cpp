/*
function that return reference
*/

#include <iostream>

class A{
    int x;

    public:
        A(int c) : x(c) {}

        int& access_x() { return x; }  // reference return
        int get_x() { return x; }  // type(value) return, x is temporary object and disappear at the end of sentence.
        void show_x() { std::cout << x << std::endl; }
};

int main() {
    A a(5);
    a.show_x();  // 5

    int& c = a.access_x();  // same as int& c = x;
    // in a nutshell, change c is same as change a.
    c = 4;
    a.show_x();  // 4

    a.access_x() = 3;  // same as a.x = 3
    a.show_x();  // 3

    int d = a.access_x();
    d = 2;  // d is not reference of x, just independent variable
    a.show_x();  // 3

    // error
    // int &e = a.get_x();
    // // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    // // temporary object created at type return, but temporary object cannot have reference.
    // e = 1;
    // a.show_x();

    int f = a.get_x();
    f = 1;
    a.show_x();  // 3
}
