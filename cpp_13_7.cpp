/*
filesystem
*/

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
    fs::directory_iterator itr(fs::current_path());
    while (itr != fs::end(itr)) {
        const fs::directory_entry& entry = *itr;
        std::cout << entry.path() << std::endl;
        itr++;
    }
    return 0;
}
/* range for
for (const fs::directory_entry& entry : 
        fs::directory_iterator(fs::current_path()) {
            std::cout << entry.path() << std::endl;
        }
*/