/*
move constructor
*/

#include <iostream>
#include <cstring>
#include <vector>

class MyString {
    char *string_content;
    int string_length;
    int memory_capacity;

    public:
        MyString();

        // create from string
        MyString(const char *str);

        // copy constructor
        MyString(const MyString &str);

        // move constructor
        MyString(MyString &&str) noexcept;

        ~MyString();
};

MyString::MyString() {
    std::cout << "call constructor" << std::endl;
    string_length = 0;
    memory_capacity = 0;
    string_content = nullptr;
}

MyString::MyString(const char *str) {
    std::cout << "call constructor" << std::endl;
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) string_content[i] = str[i];

}

MyString::MyString(const MyString &str) {
    std::cout << "call copy constructor" << std::endl;
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) string_content[i] = str.string_content[i];
}

MyString::MyString(MyString &&str) noexcept{
    std::cout << "call move constructor" << std::endl;
    string_length = str.string_length;
    string_content = str.string_content;
    memory_capacity = str.memory_capacity;

    str.string_content = nullptr;
}

MyString::~MyString() {
    if (string_content) delete[] string_content;
}

int main() {
    MyString s("abc");
    std::vector<MyString> vec;
    vec.resize(0);

    std::cout << "- - - first addition - - -" << std::endl;
    vec.push_back(s);
    std::cout << "- - - second addition - - -" << std::endl;
    vec.push_back(s);
    std::cout << "- - - third addition - - -" << std::endl;
    vec.push_back(s);

    return 0;
}
/*
1) before noexcept

call constructor
- - - first addition - - -
call copy constructor
- - - second addition - - -
call copy constructor
call copy constructor
- - - third addition - - -
call copy constructor
call copy constructor
call copy constructor

2) noexcept
call constructor
- - - first addition - - -
call copy constructor
- - - second addition - - -
call copy constructor
call move constructor
- - - third addition - - -
call copy constructor
call move constructor
call move constructor
*/