/*
std::declval
*/

#include <utility>



template <typename T>
// 1.
// decltype(T().f()) call_f_and_return(T& t) {
//   return t.f();
// }

// 2.
decltype(std::declval<T>().f()) call_f_and_return(T& t) {
    return t.f();
}

struct A {
    int f() { return 0; }
};

struct B {
    B(int x) {}
    int f() { return 0; }
};

int main() {
    A a;
    B b(1);

    call_f_and_return(a);  // ok
    call_f_and_return(b);  // ok
}