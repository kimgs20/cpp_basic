/*
reference variable
*/

#include <iostream>

// pointer
// int change_val(int *arg) {
//     *arg = 3;

//     return 0;
// }

// int main() {
//     int number = 5;

//     std::cout << number << std::endl;
//     change_val(&number);
//     std::cout << number << std::endl;

//     return 0;
// }

// reference
int main() {
    int a = 3;  // normal integer
    int& another_a = a;  // reference to variable value
    // another_a is a reference of a.
    // tell to compiler that another_a is a another name of variable a.
    // whatever do to another_a, that is same as do to a.

    another_a = 5;
    std::cout << "a: " << a << std::endl;                   // 5
    std::cout << "another_a: " << another_a << std::endl;   // 5

    std::cout << "address of a: " << &a << std::endl;                   // 0x7fffffffdc5c
    std::cout << "address of another_a: " << &another_a << std::endl;   // 0x7fffffffdc5c

    return 0;
}

/*
pointer and reference are very similar.
But there are some important differences.

1. A reference must specify whose nickname it is in its definition.
   So, int& another_a; is impossible.
   But, int* p; is fine.

2. Once a reference is nicknamed, it can never be anyone else's nickname.
   
   2-1)
   int a = 10;
   int &another_a = a; (o)

   int b = 3;
   another_a = b; (x: a = b: 10 = 3)

   2-2)
   int a = 10;
   int* p = &a;  // p point a.

   int b = 3;
   p = &b  // p abandon a and point b.

3. The reference may not exist on the memory.

reference can be replace pointer because we don't need & and *.
ex) std::cin >> user_input; = scanf("%d", &user_input);

return reference variable in function: Be careful not to return the reference of the local variable.
*/