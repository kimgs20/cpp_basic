/*
standard template library 6
map
*/

#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void print_map(std::map<K, V>& m) {
    for (auto itr = m.begin(); itr != m.end(); ++itr) {
        std::cout << itr->first << "\t" << itr->second << std::endl;
    }
}

int main() {
    std::map<std::string, double> stock_list;

    // insert function of map take pair object as argument
    stock_list.insert(std::pair<std::string, double>("AAPL", 159.30));
    stock_list.insert(std::pair<std::string, double>("MSFT", 278.91));

    // don't have to specify the type
    stock_list.insert(std::make_pair("GOOG", 2529.29));
    stock_list.insert(std::make_pair("INTC", 47.68));

    // even can add element by using []
    stock_list["NVDA"] = 213.52;
    stock_list["AMD"] = 102.95;

    print_map(stock_list);

    std::cout << "stock price of intel: " << stock_list["INTC"] << std::endl;

    return 0;
}
