/*
exception
try, catch
*/

#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
    public:
        Vector(size_t size) : size_(size) {
            data_ = new T[size_];
            for (int i = 0; i < size_; i++) {
                data_[i] = 3;
            }
        }
        const T& at(size_t index) const {
            if (index >= size_) {
                throw std::out_of_range("index of vector out of range.");
            }
            return data_[index];
        }
        ~Vector() { delete[] data_; }

    private:
        T* data_;
        size_t size_;
};

int main() {
    Vector<int> vec(3);  // length: 3

    int index, data = 0;
    std::cin >> index;

    try {
        data = vec.at(index);
    } catch (std::out_of_range& e) {
        std::cout << "except occur: " << e.what() << std::endl;
    }
    // if except occur: print 3
    // else: print 0 which originally stored.
    std::cout << "read data: " << data << std::endl;

    return 0;
}
/*
1
read data: 3
- - -
4
except occur: index of vector out of range.
read data: 0
*/