/*
std::tuple
set of ifferent types
*/

/*
struct Collection {
    int a;
    std::string s;
    double d;
};

just use tuple lib!
*/

#include <iostream>
#include <string>
#include <tuple>

/*
int main() {
    std::tuple<int, double, std::string> tp;  // tp: container
    tp = std::make_tuple(1, 3.14, "hi");
    
    std::cout << std::get<0>(tp) << ", " << std::get<1>(tp) << ", "
              << std::get<2>(tp) << std::endl;

    return 0;
}
 */

std::tuple<int, std::string, bool> GetStudent(int id) {
    if (id == 0) {
        return std::make_tuple(30, "john", true);
    } else {
        return std::make_tuple(28, "jane", false);
    }
}

int main() {
    auto student = GetStudent(1);

    // int age = std::get<0>(student);
    // std::string name = std::get<1>(student);
    // bool is_male = std::get<2>(student);

    // structure binding
    auto [age, name, is_male] = student;

    std::cout << "name: " << name << std::endl;
    std::cout << "age: " << age << std::endl;
    std::cout << "male?: " << is_male << std::endl;

    return 0;
}