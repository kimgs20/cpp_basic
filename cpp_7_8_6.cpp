/*
algorithm - find
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

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

    // 1. find first single element
    // auto result = std::find(vec.begin(), vec.end(), 3);
    // std::cout << "3 is " << std::distance(vec.begin(), result) + 1 << "-th element" << std::endl;

    // 2. find all element
    // auto current = vec.begin();
    // while (true) {
    //     current = std::find(current, vec.end(), 3);
    //     if (current == vec.end()) break;
    //     std::cout << "3 is " << std::distance(vec.begin(), current) + 1 << "-th element" << std::endl;
    //     current++;
    // }

    // 3. find if
    auto current = vec.begin();
    while (true) {
        current = std::find_if(current, vec.end(), [](int i){ return i % 3 == 2; });
        if (current == vec.end()) break;
        std::cout << "the element that divided by 3 and has rest of 2: " << *current << std::endl;
        current++;
    }

    return 0;
}
/*
1.
3 is 2-th element

2.
3 is 2-th element
3 is 5-th element

3.
the element that divided by 3 and has rest of 2: 5
the element that divided by 3 and has rest of 2: 2

주의점
컨테이너에서 기본적으로 find 함수를 지원한다면 이것을 사용하는 것이 빠르다.
알고리즘 라이브러리의 find 함수는 컨테이너가 어떤 구조를 가졌는지 모르기 때문.
예를들어 set에서 find 함수는 셋 내부에서 원소들이 정렬되어 있으므로
O(log n) 으로 수행될 수 있다. 그러나 알고리즘 라이브러리의 경우 평범한 O(n) 으로 처리된다.
vector와 같이 find를 지원하지 않는 컨테이너에 사용하면 된다.
*/