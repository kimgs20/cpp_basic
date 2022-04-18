/*
type_traits 2
*/

#include <iostream>
#include <type_traits>

class A {};

// take integer type only
template <typename T>
void only_integer (const T& t) {
    static_assert(std::is_integral<T>::value);
    std::cout << "T is integer" << std::endl;
}

int main() {
    int n = 3;
    only_integer(n);

    // A a;
    // only_integer(a);  // static assertion fail

    return 0;
}
/*
type_traits - is class function

namespace detail {
template <class T>
char test(int T::*);  // Pointer to Data member
struct two {
  char c[2];
};
template <class T>
two test(...);
}  // namespace detail

template <class T>
struct is_class
    : std::integral_constant<bool, sizeof(detail::test<T>(0)) == 1 &&
                                     !std::is_union<T>::value> {};

*/