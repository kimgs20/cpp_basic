/*
type_traits
*/

#include <iostream>

// template specialization
template <typename T>
struct is_void {
    static constexpr bool value = false;
};

template <>
struct is_void<void> {
    static constexpr bool value = true;
};

template <typename T>
void tell_type() {
    if (is_void<T>::value) {  // std::is_void
        std::cout << "T is void" << std::endl;
    } else {
        std::cout << "T is not void" << std::endl;
    }
}

int main() {
    tell_type<int>();  // not void

    tell_type<void>();  // void

    return 0;
}