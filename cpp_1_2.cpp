/*
for, while, if, else, switch
*/
 
#include <iostream>

int main() {

    int i;
    int sum = 0;

    // for
    for (i = 0; i < 10; i++) {
        std::cout << i << std::endl;
    }

    // while
    int j = 0;
    while (j <= 10) {
        sum += j;
        j++;
    }
    std::cout << "sum(1-10): " << sum << std::endl;

    // if-else
    int lucky_number = 3;
    std::cout << "guess(1-10): " << std::endl;

    int user_input;

    while(1) {
        std::cout << "input: ";
        std::cin >> user_input;
        if (lucky_number == user_input) {
            std::cout << "true" << std::endl;
            break;
        } else {
            std::cout << "retry" << std::endl;
        }
    }

    // switch
    int user_input_for_switch;
    std::cout << "date" << std::endl;
    std::cout << "1. year" << std::endl;
    std::cout << "2. month" << std::endl;
    std::cout << "3. day" << std::endl;
    std::cin >> user_input_for_switch;

    switch (user_input_for_switch) {
        case 1:
            std::cout << "2022" << std::endl;
            break;
        case 2:
            std::cout << "01" << std::endl;
            break;
        case 3:
            std::cout << "28" << std::endl;
            break;
        default:
            std::cout << "input num: (1-3)" << std::endl;
            break;
    }
    return 0;
}
