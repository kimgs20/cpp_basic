/*
standard template library 8
algorithm

two types
1.
template <typename Iter>
void do_something(Iter begin, Iter end);

2.
template <typename Iter, typename Pred>
void do_something(Iter begin, Iter end, Pred pred)
*/

#include <algorithm>
#include <iostream>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << *begin << " ";
        begin++;
    }
    std::cout << std::endl;
}

// if want descending sort
// struct int_compare {
//     bool operator() (const int& a, const int& b) const { return a > b; }
// };

int main() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(4);
    vec.push_back(7);
    vec.push_back(2);

    std::cout << "- - - before sort - - -" << std::endl;
    print(vec.begin(), vec.end());
    std::sort(vec.begin(), vec.end());  // ascending sort
    // std::sort(vec.begin(), vec.end(), int_compare());  // descending sort

    std::cout << "- - - after sort - - -" << std::endl;
    print(vec.begin(), vec.end());

    return 0;
}
