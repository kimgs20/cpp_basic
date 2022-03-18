/*
rvalue reference

c++ expression: 1. type 2. value

int a = 3;      // a is lvalue
int& l_a = a;   // l_a is lvalue reference

int& r_b = 3;   // 3 is rvalue (error)
*/

#include <iostream>
#include <cstring>

class MyString {
    char *string_content;
    int string_length;

    int memory_capacity;

    public:
        MyString();
        MyString(const char *str);      // initialized from string
        MyString(const MyString &str);  // copy constructor
        MyString(MyString &&str);       // move constructor

        void reserve(int size);
        MyString operator+(const MyString &s);
        ~MyString();

        int length() const;

        void print();
        void println();
};

MyString::MyString() {
    std::cout << "call constructor" << std::endl;
    string_length = 0;
    memory_capacity = 0;
    string_content = nullptr;
}

// initialized from string
MyString::MyString(const char *str) {
    std::cout << "call constructor" << std::endl;
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) {
        string_content[i] = str[i];
    }
}

// copy constructor
MyString::MyString(const MyString &str) {
    std::cout << "call copy constructor" << std::endl;
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) {
        string_content[i] = str.string_content[i];
    }
}

MyString::MyString(MyString &&str) {
    std::cout << "call move constructor" << std::endl;
    string_length = str.string_length;
    string_content = str.string_content;
    memory_capacity = str.memory_capacity;

    // do not allow memory deallocation
    // when free temporary object
    str.string_content = nullptr;
}

MyString::~MyString() {
    if (string_content) delete[] string_content;
}

void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char *prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for (int i = 0; i != string_length; i++)
            string_content[i] = prev_string_content[i];

        if (prev_string_content != nullptr) delete[] prev_string_content;
    }
}

MyString MyString::operator+(const MyString &s) {
    MyString str;
    str.reserve(string_length + s.string_length);

    for (int i = 0; i < string_length; i++)
        str.string_content[i] = string_content[i];

    for (int i = 0; i < s.string_length; i++)
        str.string_content[string_length + i] = s.string_content[i];

    str.string_length = string_length + s.string_length;
    return str;
}

int MyString::length() const { return string_length; }

void MyString::print() {
    for (int i = 0; i != string_length; i++) std::cout << string_content[i];
}

void MyString::println() {
    for (int i = 0; i != string_length; i++) std::cout << string_content[i];

    std::cout << std::endl;
}

int main() {
    MyString str1("abc");
    MyString str2("def");

    std::cout << " - - - " << std::endl;

    MyString str3 = str1 + str2;
    str3.println(); 

    return 0;
}

// move constructor doesn't called