/*
STL - algorithm
sort: 일반적인 정렬 함수
sort에 들어가는 반복자의 경우 반드시 RandomAccessIterator 타입을 만족해야 하므로,
컨테이너 중에선 vector와 deque만 가능하고 나머지 컨테이너는 sort 함수를 적옹햘 수 없다.
예를 들면 리스트의 경우 반복자 타입이 BidirectinalIterator 이므로 사용 불가.

partial_sort: 배열의 일부분만 정렬한다.

stable_sort: 정렬을 하되 원소들 간의 순서를 보존한다.
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

int main() {
    std::vector<int> vec;
    vec.push_back(4);
    vec.push_back(9);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(7);
    vec.push_back(1);
    vec.push_back(6);

    std::cout << "- - - before sort - - -" << std::endl;
    // std::cout << vec << std::endl;  // 이게 안되니까 함수 정의 한 것
    print(vec.begin(), vec.end());

    std::sort(vec.begin(), vec.end());

    std::cout << "- - - after sort - - -" << std::endl;
    print(vec.begin(), vec.end());

    return 0;
}

/*
- - - before sort - - -
4 9 2 3 5 7 1 6 
- - - after sort - - -
1 2 3 4 5 6 7 9 
*/
