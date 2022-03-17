/*
standard template library (STL) 1
vector
*/

#include <iostream>
#include <vector>

// print whole vector
template <typename T>
void print_vector(std::vector<T>& vec) {
    // need typename at 'for': iterator is dependent type of std::vector<T>
    for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        std::cout << *itr << std::endl;
    }
}

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    // print whole vector
    for (std::vector<int>::size_type i = 0; i < vec.size(); i++) {
        std::cout << i + 1 << "-th element of vec: " << vec[i] << std::endl;
    }

    // print whole vector
    for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        std::cout << *itr << std::endl;
    }

    std::cout << "- - - vector before - - -" << std::endl;
    print_vector(vec);

    // add '15' in front of vec[2]
    vec.insert(vec.begin() + 2, 15);

    std::cout << "- - - add 15 - - -" << std::endl;
    print_vector(vec);

    std::cout << "- - - delete vec[3] - - -" << std::endl;
    vec.erase(vec.begin() + 3);
    print_vector(vec);

    return 0;
}
