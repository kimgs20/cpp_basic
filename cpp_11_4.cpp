/*
std::bind
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
    auto add_with_2 = std::bind(add, 2, std::placeholders::_1);
    add_with_2(3);

    // igrore second element
    add_with_2(3, 4);

    auto subtract_from_2 = std::bind(subtract, std::placeholders::_1, 2);
    auto negate = std::bind(subtract, std::placeholders::_2, std::placeholders::_1);

    subtract_from_2(3);  // 3 - 2
    negate(4, 2);        // 2 - 4

    return 0;
}