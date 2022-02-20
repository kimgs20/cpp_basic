/*
inheritance
*/

#include <iostream>

class Base {
    std::string s;

    public:
        Base() : s("Base") { std::cout << "Base class" << std::endl; }

        void func() { std::cout << s << std::endl; }
};

class Derived : public Base {
    std::string s;

    public:
        Derived() : Base(), s("Derived") {
            std::cout << "Derived class" << std::endl;
            func();
        }
    
    // void func() {std::cout << s << std::endl; }
};


int main() {
    std::cout << "create base class" << std::endl;
    Base b;

    std::cout << "create derived class" << std::endl;
    Derived d;

    return 0;
}
/*
create base class
Base class
create derived class
Base class
Derived class
Base (or Derived)
*/
