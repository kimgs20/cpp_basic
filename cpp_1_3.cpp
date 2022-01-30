/*
pointer review
*/

#include <iostream>

int main() {
    int var = 3;
    int *ptr;

    ptr = &var;  // alloc address(same dim)

    std::cout << var << std::endl;  // 3
    std::cout << &var << std::endl;  // address: 0x7fffffffdc5c

    std::cout << ptr << std::endl;  // address: 0x7fffffffdc5c
    std::cout << *ptr << std::endl;  // 3

    // &: high dim
    // *: low dim

    return 0;
}
