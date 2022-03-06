/*
standard template library 3
deque
*/

#include <iostream>
#include <deque>

template <typename T>
void print_deque(std::deque<T>& dq) {
    std::cout << "[";
    for (const auto& elem : dq) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(30);
    dq.push_front(40);

    std::cout << "- - - intitailized dq - - -" << std::endl;
    print_deque(dq);

    std::cout << "- - - delete first element - - -" << std::endl;
    dq.pop_front();
    print_deque(dq);

    return 0;
}