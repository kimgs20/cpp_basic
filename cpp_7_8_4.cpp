/*
transform
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << "[" << *begin << "] ";
        begin++;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::cout << "- - - initial vec - - -" << std::endl;
    print(vec.begin(), vec.end());

    std::cout << "- - - add 1  - - -" << std::endl;
    std::transform(vec.begin(), vec.end(), vec.begin(), [](int i) { return i + 1; });
    print(vec.begin(), vec.end());

    return 0;
}
/*
- - - initial vec - - -
[5] [3] [1] [2] [3] [4] 
- - - add 1  - - -
[6] [4] [2] [3] [4] [5] 
*/
