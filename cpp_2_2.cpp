/*
function overloading
*/

#include <iostream>

void print(int x) { std::cout << "int: " << x << std::endl; }
void print(char x) { std::cout << "char: " << x << std::endl; }
void print(double x) { std::cout << "double: " << x << std::endl; }

int main() {
    int a = 1;
    char b = 'c';
    double c = 3.2f;

    print(a);
    print(b);
    print(c);
    // even if names of fuctions are the same, c++ compiler determines that they
    // are difference functions when arguments are different.

    return 0;
}

/*
pay attention to ambiguous function overloading.
(ex)

#include <iostream>

void print(int x) { std::cout << "int: " << x << std::endl; }
void print(char x) { std::cout << "double: " << x << std::endl; }

int main() {
    int a = 1;
    char b = 'c';
    double c = 3.2f;

    print(a);
    print(b);
    print(c);  // error: call of overloaded ‘print(double&)’ is ambiguous

    return 0;
}
*/