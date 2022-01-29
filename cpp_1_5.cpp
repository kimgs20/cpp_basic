/*
new, delete
*/

#include <iostream>

// int main() {
//     int* p = new int;  // allocate int size space to address p.
//     *p = 10;

//     std::cout << *p << std::endl;

//     delete p;
//     return 0;
// }

// allocate array by new
int main() {
    int arr_size;
    std::cout << "input array size: ";
    std::cin >> arr_size;

    int *list = new int[arr_size];  // list: address of int array

    for (int i = 0; i < arr_size; i++) {
        std::cin >> list[i];
    }
    for (int i = 0; i < arr_size; i++) {
        std::cout << i << "th element of list: " << list[i] << std::endl;
    }

    delete[] list;
    return 0;
}

/*
pair
new - delete
new [] - delete []
*/