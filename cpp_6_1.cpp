/*
template
*/

#include <iostream>
#include <string>

template <typename T>

class Vector {
    T* data;
    int capacity;
    int length;

    public:
    // constructor
    Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}

    // add new element
    void push_back(T s) {
        if (capacity <= length) {
            T* temp = new T[capacity * 2];
            for (int i = 0; i < length; i++) {
                temp[i] = data[i];
            }
        delete[] data;
        data = temp;
        capacity *2;
        }
        data[length] = s;
        length++;
    }

    // access to element of random position
    T operator[](int i) { return data[i]; }

    // remove x-th element
    void remove(int x) {
        for (int i = x + 1; i < length; i++) {
            data[i - 1] = data[i];
        }
        length--;
    }

    // calculate current size of vector
    int size() { return length; }

    ~Vector() {
        if (data) {
            delete[] data;
        }
    }
};

int main() {
    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(2);

    std::cout << "- - - int vector - - -" << std::endl;
    std::cout << "first element: " << int_vec[0] << std::endl;
    std::cout << "second element: " << int_vec[1] << std::endl;

    Vector<std::string> str_vec;
    str_vec.push_back("hello");
    str_vec.push_back("world");

    std::cout << "- - - int vector - - -" << std::endl;
    std::cout << "first element: " << str_vec[0] << std::endl;
    std::cout << "second element: " << str_vec[1] << std::endl;

    return 0;
}