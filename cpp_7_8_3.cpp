/*
lambda function

람다 함수는 함수 객체와 함수 포인터의 장점만 가지고 있다.
1. 함수 객체와 다르게 class를 선언할 필요가 없다.
2. 함수의 인라인화 가능.
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << "[" << *begin << "]";
        begin++;
    }
    std::cout << std::endl;
}

int main () {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::cout << "- - - initial vec - - -" << std::endl;
    print(vec.begin(), vec.end());

    std::cout << "- - - remove odd number - - -" << std::endl;
    // 1. lambda function
    // vec.erase(std::remove_if(vec.begin(), vec.end(), [](int i) -> bool { return i % 2 == 1; }), vec.end());

    // 2. using capture list
    int num_erased = 0;
    vec.erase(std::remove_if(vec.begin(), vec.end(),
                        [&num_erased](int i) {
                            if (num_erased >= 2)
                                return false;
                            else if (i %  2 == 1) {
                                num_erased++;
                                return true;
                            }
                            return false;
                        }),
                        vec.end());
    print(vec.begin(), vec.end());

    return 0;
}
/*
- - - initial vec - - -
[5][3][1][2][3][4]
- - - remove odd number - - -
[2][4]


*** lambda function ***

[](int i) -> bool { return i % 2 == 1; }

[capture list] (paramter list) -> return type { body of function }


1. return type 생략
[](int i) -> { return i % 2 == 1; }

2. 함수 바로 사용
[](int i) -> { return i % 2 == 1; }(3);  // true

3. func 함수 객체 생성한 후 호출
auto func = [](int i) -> { return i % 2 == 1; }

람다 함수도 함수이므로 자기 자신만의 스코프를 가진다. 따라서 일반적인
상황에서는 함수 외부에서 정의된 변수들을 사용할 수 없다. 그러나 람다 함수의
경우엔 capture list를 활용하여 그 변수에 접근 할 수 있다.

[&num_erased](int i) { ... }
실제 num_erased 의 레퍼런스를 캡쳐한다. 즉, 함수 내부에서 num_erased의 값을 바꿀 수 있는 것
*/
