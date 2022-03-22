/*
unique_ptr
*/

#include <iostream>
#include <memory>

class A {
    int *data;

    public:
        A() {
            std::cout << "get resource" << std::endl;
            data = new int[100];
        }

        void some() {std::cout << "can use as general pointer" << std::endl; }

        ~A() {
            std::cout << "free resource" << std::endl;
            delete[] data;
        }
};

void do_something() {
    std::unique_ptr<A> pa(new A());
    pa->some();

    // error: use of deleted function
    // because copy constructor of unique_ptr is explicitly deleted.
    // std::unique_ptr<A> pb = pa;
}

int main() {
    do_something();
    return 0;
}
