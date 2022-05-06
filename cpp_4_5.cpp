/*
override
*/

#include <iostream>
#include <string>

class Base {
    std::string s;

    public:
        Base() : s("base") { std::cout << "base class" << std::endl; }

    virtual void incorrect () { std::cout << "base class" << std::endl; }
};

class Derived : public Base {
    std::string s;

    public:
        Derived() : Base(), s("derived") {}

        void incorrect() override { std::cout << "derivde class" << std::endl; }
};

int main() {
    Base b;
    Derived d;

    Base* b_d = &d;
    Base* b_b = &b;

    std::cout << "- - - base- - -" << std::endl;
    b_d->incorrect();

    std::cout << "- - - derived- - -" << std::endl;
    b_b->incorrect(); 

    return 0;
}