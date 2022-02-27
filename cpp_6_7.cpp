/*
template application
concatenate string without unnecessary memory allocation
*/

#include <cstring>
#include <iostream>
#include <string>

size_t GetStringSize(const char* s) { return strlen(s); }

size_t GetStringSize(const std::string& s) { return s.size(); }

template <typename String, typename... Strings>
size_t GetStringSize(const String& s, Strings... strs) {
    return GetStringSize(s) + GetStringSize(strs...);
}

void AppendToString(std::string* concat_str) { return; }

template <typename String, typename... Strings>
void AppendToString(std::string* concat_str, const String& s, Strings... strs) {
    concat_str->append(s);
    AppendToString(concat_str, strs...);
}

template <typename String, typename... Strings>
std::string StrCat(const String& s, Strings... strs) {
    // calculate total length of string.
    size_t total_size = GetStringSize(s, strs...);

    // allocate memory space with reserve in advance.
    std::string concat_str;
    concat_str.reserve(total_size);

    concat_str = s;

    // attache strings to the concat_str.
    AppendToString(&concat_str, strs...);

    return concat_str;
}

int main() {
    std::cout << StrCat(std::string("this"), " ", "is", " ", std::string("a"), 
                        " ", std::string("sentence"));
    return 0;
}
