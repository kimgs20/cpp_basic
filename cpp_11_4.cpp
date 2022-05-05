/*
std::bind
when creating a function, it can also specify a argument.
*/

#include <functional>
#include <iostream>

void add(int x, int y) {
    std::cout << x << " + " << y << " = " << x + y << std::endl;
}

void subtract(int x, int y) {
    std::cout << x << " - " << y << " = " << x - y << std::endl;
}

int main() {
    // std::bind work for add specific agrument at original function.
    auto add_with_2 = std::bind(add, 2, std::placeholders::_1);
    // function add, bind 2 for first arg, bind first arg of new function object.

    add_with_2(3);  // first arg: 2, second arg: first arg of add_with_2 = 3

    add_with_2(3, 4);  // igrore second arg(4)

    auto subtract_from_2 = std::bind(subtract, std::placeholders::_1, 2);
    auto negate = std::bind(subtract, std::placeholders::_2, std::placeholders::_1);

    subtract_from_2(3);  // 3 - 2
    negate(4, 2);        // 2 - 4

    return 0;
}
/*
2 + 3 = 5
2 + 3 = 5
3 - 2 = 1
2 - 4 = -2
*/
