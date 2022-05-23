/*
iterator

반복자
칸테이너 원소에 접근할 수 있는 포인터와 같은 객체
알고리즘 라이브러리의 경우 대부분이 반복자를 인자로 받아서 알고리즘을 수행함

    [1]    [2]    [3]    [4]    [5]    [6]    []
vec.begin()이 가리키는 위치                    vec.end()가 가리키는 위치
*/

#include <iostream>
#include <vector>

template <typename T>
void print(std::vector<T>& vec) {
    // print whole vector
    std::cout << "[ ";
    for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << "]";
}

int main() {
    std::vector<int> vec;
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(6);

    // vector의 iterator 타입은 std::vector<>::iterator 멤버 타입으로 정의 되어있음
    // vec.begin() 이나 vec.end() 가 이를 리턴
    // vec.end() 는 비어있으므로 vec.end()가 아닐 때 까지 반복
    // for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
    //     std::cout << *itr << std::endl;  // itr은 실제 포인터가 아니며 * 연산자는 itr이 가리키는 원소의 레퍼런스를 리턴함
    // }

    // std::vector<int>::iterator itr = vec.begin() + 2;
    // std::cout << "third element: " << *itr << std::endl;

    std::cout << " - - - initial vector - - - " << std::endl;
    print(vec);

    std::vector<int>::iterator itr = vec.begin();
    std::vector<int>::iterator end_itr = vec.end(); 

    // 컨테이너에 원소를 추가하거나 제거하게 되면 기존에 사용하였던
    // 모든 반복자들을 사용할 수 없게 된다.
    // 즉 vec.erase(itr) 을 하는 순간 더이상 itr은 유효한 반복자가 아니게 된다.
    // 따라서 itr != end_itr 이 성립되어 무한 루프가 된다.
    for (; itr != end_itr; ++itr) {
        if (*itr == 1) {
            vec.erase(itr);
            itr = vec.begin();  // 해결 되지만 비효율적
        }
    }

    // 다른 방식
    // 굳이 반복자를 쓰지 않고 erase 함수에만 반복자를 바로 만들어서 전달
    for (std::vector<int>::size_type i = 0; i != vec.size(); i++) {
        if (vec[i] == 1) {
            vec.erase(vec.begin() + i);
            i--;
        }
    }

    // 하지만 이것 역시 좋은 방식은 아님
    // 왜냐하면 기껏 원소에 접근하는 방식은 반복자를 사용하는 것으로 통일하였는데
    // 그것을 무시하고 그냥 기존의 배열처럼 int i 로 원소에 접근하기 때문.
    // 이럴 땐 stl algorithm을 쓰면 된다.

    std::cout << "erase value 1" << std::endl;
    print(vec);

    return 0;
}