/* 
std::mem_fn
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main() {

    std::vector<int> a(1);
    std::vector<int> b(2);
    std::vector<int> c(3);
    std::vector<int> d(4);

    std::vector<std::vector<int>> containter;
    containter.push_back(b);
    containter.push_back(d);
    containter.push_back(a);
    containter.push_back(c);

// error: must use ‘.*’ or ‘->*’ to call pointer-to-member function in 
// ‘__unary_op (...)’, e.g. ‘(... ->* __unary_op) (...)’
/* std::vector<int> size_vec(4);
   std::transform(containter.begin(), containter.end(), size_vec.begin(),
                    &std::vector<int>::size);

    for (auto itr = size_vec.begin(); itr != size_vec.end(); ++itr) {
        std::cout << "size of vector: " << *itr << std::endl;
    }
 */

    std::function<size_t(const std::vector<int>&)> sz_func = &std::vector<int>::size;

    std::vector<int> size_vec(4);
    std::transform(containter.begin(), containter.end(), size_vec.begin(), sz_func);
    for (auto itr = size_vec.begin(); itr != size_vec.end(); ++itr) {
        std::cout << "size of vector: " << *itr << std::endl;
    }


    return 0;
}