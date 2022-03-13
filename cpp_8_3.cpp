/*
exception
*/

#include <exception>
#include <iostream>

class Parent : public std::exception {
    public:
        virtual const char* what() const noexcept override { return "Parent\n"; }
};

class Child : public Parent {
    public:
        const char* what() const noexcept override { return "Child\n"; }
};

int func(int c) {
    if (c == 1) {
        throw Parent();
    } else if (c == 2) {
        throw Child();
    }
    return 0;
}

int main() {
    int c;
    std::cin >> c;

    try {
        func(c);
    } catch (Child& c) {
        std::cout << "Child catch" << std::endl;
        std::cout << c.what();
    } catch (Parent& p) {
        std::cout << "Parent catch" << std::endl;
        std::cout << p.what();
    }
    return 0;
}

/*
1
Parent catch
Parent
- - -
2
Child catch
Child
*/