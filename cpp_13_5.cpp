/*
random
*/

#include <iomanip>  // setw
#include <iostream>
#include <map>
#include <random>

int main() {
    // create random device to get seed value
    std::random_device rd;

    // initialize random number engine through random device
    // mt19937: c++11 basic random number engine
    std::mt19937 gen(rd());

    // normal distribution
    std::normal_distribution<double> dist(/* avg */ 0, /* std */ 1);

    std::map<int, int> hist{};
    for (int n = 0; n < 10000; ++n) {
        ++hist[std::round(dist(gen))];
    }

    for (auto p : hist) {
        std::cout << std::setw(2) << p.first << ' '
                  << std::string(p.second / 100, '*') << " " << p.second << std::endl;
    }

    return 0;
}
/*
-4  3
-3  64
-2 ****** 603
-1 *********************** 2385
 0 ************************************* 3786
 1 ************************ 2480
 2 ****** 602
 3  73
*/