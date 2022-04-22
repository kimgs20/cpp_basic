/*
std::optional
*/

#include <iostream>
#include <map>
#include <string>
#include <utility>

std::optional<std::string> GetValueFromMap(const std::map<int, std::string>& m, int key) {
    auto itr = m.find(key);
    if (itr != m.end()) {
        return itr->second;
    }

    return std::nullopt;
}

int main() {
    std::map<int, std::string> data = {{1, "hi"}, {2, "hello"}, {3, "c++"}};
    std::cout << "map for 2: " << GetValueFromMap(data, 2).value() << std::endl;
    std::cout << "does 4 exist in map?: " << std::boolalpha
              << GetValueFromMap(data, 4).has_value() << std::endl;
    
    return 0;
}