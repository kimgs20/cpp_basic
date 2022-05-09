/*
std::fucntion

Callable: 호출 할 수 있는 모든 것. 대표적인 예시로 함수. 

C++ 에서는 ()를 붙여서 호출할 수 있는 모든 것을 Callable이라고 정의한다.
C++ 에서 Callable들을 객체의 형태로 보관 할 수 잇는 std::function 이라는 클래스를 제공한다.
C에서 함수 포인터는 진짜 함수들만 보관할 수 있는 객체라고 볼 수 있다면, std::function의 경우
함수 뿐 만 아니라 모든 Callable 들을 보관할 수 있는 객체이다.
*/

#include <functional>
#include <iostream>
#include <string>

int some_func1(const std::string& a) {
    std::cout << "call Func1 " << a << std::endl;
    return 0;
}

struct S {
    void operator()(char c) { std::cout << "call Func2 " << c << std::endl; }
};


int main() {
    // 템플릿 인자로 전달받을 함수의 타입을 갖게 됨
    std::function<int(const std::string&)> f1 = some_func1;

    // Functor인 클래스 S의 객체는 단순히 S의 객체를 전달하여도 이를 함수처럼 받음
    // 함수 포인터로 구현한다면 Functor와 같은 경우를 성공적으로 보관할 수 없음
    std::function<void(char)> f2 = S();

    // 람다 함수의 경우 리턴이 없고 인자가 없으므로 이와 같이 표현
    std::function<void()> f3 = []() { std::cout << "call Func3 " << std::endl; };

    f1("hello");
    f2('c');
    f3();

    return 0;
}