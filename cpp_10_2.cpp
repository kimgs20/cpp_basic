/*
shared_ptr

때에 따라서 여러 개의 스마트 포인터가 하나의 객체를 같이 소유해야 하는 경우가 발생한다.
예를들면 여러 객체에서 하나의 자원을 사용하고 이후에 자원을 해제하기 위해서는 이 자원을
사용하는 모든 객체들이 소멸되어야 하는데, 어떤 객체가 먼저 소멸되는지 알 수 없기 때문에
이 자원 역시 어느 타이밍에 해제 시켜야 할 지 알 수 없게 된다.

shared_ptr 은 특정 자원을 몇 개의 객체에서 가리키는지 추적하고, 그 수가 0이 되어야만
비로서 해제를 시켜주는 방식의 포인터이다.

shared_ptr로 객체를 가리킬 경우 다른 shared_ptr 역시 그 객체를 가리킬 수 있다.

ROS 같은 경우엔 node에 다음과 같이 사용함.
std::shared_ptr<rclcpp::Node> node
*/

#include <iostream>
#include <memory>
#include <vector>

class A {
    int *data;

    public:
        A() {
            data = new int[100];
            std::cout << "get resource" << std::endl;
        }

    ~A() {
        std::cout << "call destuctor" << std::endl;
        delete[] data;
    }
};

int main() {

    std::shared_ptr<A> p1(new A());
    std::shared_ptr<A> p2(p1);  // p1 also point new object A

    std::cout << p1.use_count() << std::endl;  // 2
    std::cout << p2.use_count() << std::endl;  // 2

    p2.reset();

    std::cout << p1.use_count() << std::endl;  // 1

    return 0;
}