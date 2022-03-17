/*
non-type template argument
*/

#include <iostream>

template <typename T, unsigned int N>
class Array {
    T data[N];

    public:
        // reference that take array
        Array(T (&arr)[N]) {
            for (int i = 0; i < N; i++) {
                data[i] = arr[i];
            }
        }
    
        T& get_array() { return data; }

        void print_all() {
            for (int i = 0; i < N; i++) {
                std::cout << data[i] << ", ";
            }
            std::cout << std::endl;
        }
};

int main() {
    int arr[3] = {1, 2, 3};

    // array wrapper class
    Array<int, 3> arr_w(arr);  // T: int, N: 3, T data[N]; = int data[3];

    arr_w.print_all();
}