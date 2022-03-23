/*
shared_ptr
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
    std::vector<std::shared_ptr<A>> vec;

    vec.push_back(std::shared_ptr<A>(new A()));
    vec.push_back(std::shared_ptr<A>(vec[0]));
    vec.push_back(std::shared_ptr<A>(vec[1]));

    std::cout << "destruct first element" << std::endl;
    vec.erase(vec.begin());

    std::cout << "destruct next element" << std::endl;
    vec.erase(vec.begin());

    std::cout << "destruct last element" << std::endl;
    vec.erase(vec.begin());

    return 0;
}