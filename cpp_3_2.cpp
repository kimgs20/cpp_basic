/*
friend keyword
*/

#include <iostream>

class A {
    private:
        void private_func() {}
        int private_num;

        // class B is friend of A
        friend class B;

        // func is friend of A
        friend void func();
};
// But class A cannot access to private variable and function of class B and func().

class B {
    public:
        void b() {
            A a;
            a.private_func();
            a.private_num = 3;
            std::cout << a.private_num << std::endl;
        }

};

void func() {
    A a;
    a.private_func();
    a.private_num = 2;
    std::cout << a.private_num << std::endl;
}

int main() {

    B b;
    b.b();  // 3

    func();  // 2

    return 0;
}
