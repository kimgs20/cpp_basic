/*
input, output library

fstream, ofstream, ifstram, iostream, istream, ostream, ios, ios_base

ios initialize stream buffer(temporarily store data)

flag of ios class
- goodbit
- badbit
- failbit
- eofbit

operator>> igrnore every space character ex) " ", "\n", "\t"
*/

#include <iostream>

int main() {
    int t;
    while (true) {
        std::cin >> t;
        std::cout << "input: " << t << std::endl;
        if (std::cin.fail()) {  // true of failbit or badbit: return true
            std::cout << "input int data" << std::endl;
            std::cin.clear();  // reinitialize flags
            std::cin.ignore(100, '\n');  // ignore until new line character (max 100 character)
        }
        if (t == 1) break;
    }
}
/*
4
input: 4
5
input: 5
s
input: 0
input int data
q
input: 0
input int data
*/