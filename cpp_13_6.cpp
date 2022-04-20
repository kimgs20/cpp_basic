/*
chrono
*/

#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(0, 1000);

    for (int total = 1; total <= 1000000; total *= 10) {
        std::vector<int> random_numbers;
        random_numbers.reserve(total);

        std::chrono::time_point<std::chrono::high_resolution_clock> start =
            std::chrono::high_resolution_clock::now();
        for (int i = 0; i < total; i++) {
            random_numbers.push_back(dist(gen));
        }
    
        std::chrono::time_point<std::chrono::high_resolution_clock> end =
            std::chrono::high_resolution_clock::now();
        
        // before C++ 17
        auto diff = end - start;

        // after C++ 17
        // std::chrono::duration diff = end - start;

        std::cout << std::setw(7) << "total random number: " << total
                  << " tick count: " << diff.count() << std::endl;
    }

    return 0;
}