/*
algorithm - remove

이미 대부분의 컨테이너에서는 원소를 제거하는 함수를 지원한다.

std::vector<int> vec;
...
vec.erase(vec.begin() + 3);  // vec[3] 에 해당하는 원소 제거

그러나 원소가 제거될 때 마다 기존에 제거했던 반복자들이 초기화 되기 때문에
해당 위치를 가리키는 반복자를 다시 가져와야 한다.
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

struct is_odd {
    bool operator()(const int& i) { return i % 2 == 1; }
};

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

    // std::cout << "- - - remove 3 - - -" << std::endl;
    // vec.erase(std::remove(vec.begin(), vec.end(), 3), vec.end());
    // print(vec.begin(), vec.end());\

    std::cout << "- - - remove odd number - - -" << std::endl;
    vec.erase(std::remove_if(vec.begin(), vec.end(), is_odd()), vec.end());
    print(vec.begin(), vec.end());

    return 0;
}
/*
remove 함수는 원소의 이동만을 수행하고 실제로 원소를 제거하는 연산을 하지 않으므로
벡터에서 실제로 원소를 지우기 위해서는 반드시 erase 함수를 호출하여야 한다.
*/
