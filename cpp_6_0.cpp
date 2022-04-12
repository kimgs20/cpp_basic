/*
need of template
*/

#include <iostream>
#include <string>

// vector(data structure): dynamic arrays with the ability to resize itself
// automatically when an element is inserted or deleted.
class Vector {
    std::string* data;
    int capacity;
    int length;

    public:
        // constructor
        Vector(int n = 1) : data(new std::string[n]), capacity(n), length(0) {}

        // add new element at last.
        void push_back(std::string s) {
            if (capacity <= length) {
                std::string* temp = new std::string[capacity * 2]; // ??
                for (int i = 0; i < length; i++) {
                    temp[i] = data[i];
                }

                delete[] data;
                data = temp;
                capacity *= 2;  // ??
            }

            data[length] = s;
            length++;
        }

        // access to arbitary element
        std::string operator[](int i) { return data[i]; }

        // remove x-th element
        void remove(int x) {
            for (int i = x + 1; i < length; i++) {
                data[i - 1] = data[i];
            }
            length--;
        }

        // return size of vector
        int size() { return length; }

        ~Vector() {
            if (data) {
                delete[] data;
            }
        }
};

int main() {
    Vector vec;
    std::string a("a");

    vec.push_back(a);
    vec.push_back(a);
    vec.push_back(a);

    // vec.push_back(1); // error

    std::cout << vec[0] << vec[1] << vec[2] << vec[3] << vec.size() << std::endl;

    return 0;
}