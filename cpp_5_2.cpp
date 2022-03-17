/*
fstream (file stream)
*/

#include <fstream>
#include <iostream>

int main() {
    std::ifstream in("test.txt");
    std::string s;

    if (in.is_open()) {
        // move cursor to end of file.
        in.seekg(0, std::ios::end);

        // and read that location.
        int size = in.tellg();
        
        // allocate string of that size.
        s.resize(size);

        // move cursor to begin of file
        in.seekg(0, std::ios::beg);

        // read every contents of file and save to string.
        in.read(&s[0], size);
        std::cout << s << std::endl;
    } else {
        std::cout << "can not open file" << std::endl;
    }
    return 0;
}