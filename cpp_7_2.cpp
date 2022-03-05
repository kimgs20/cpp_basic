/*
standard template library (STL) 1
list
*/

#include <iostream>
#include <list>

template <typename T>
void print_list(std::list<T>& lst) {
    std::cout << "[";
    // print whole list
    for (const auto& elem : lst) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::list<int> lst;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    std::cout << "initialized list" << std::endl;
    print_list(lst);

    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
        if (*itr == 20) {
            lst.insert(itr, 50);
        }
    }

    std::cout << "- - - add 50 in front of 20 - - -" << std::endl;
    print_list(lst);

    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
        if (*itr == 30) {
            lst.erase(itr);
            break;  // if there is no break, segmentation fault occurs
        }
    }

    std::cout << "- - - delete 30 - - -" << std::endl;
    print_list(lst);

    return 0;
}