/*
standard string class
*/

#include <iostream>
#include <string>

int main() {
    std::string s = "abc";
    std::string t = "def";
    std::string s2 = s;

    std::cout << "length of " << s << ": " << s.length() << std::endl;
    std::cout << "concat " << s << " after " << t << ": " << s + t << std::endl;

    if (s == s2) {
        std::cout << s << " and " << s2 << " are same." << std::endl;
    }

    if (s != t) {
        std::cout << s << " and " << t << " are diffrent." << std::endl;
    }

    return 0;
}
