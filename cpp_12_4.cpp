/*
thread - mutex
*/

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

void worker(int& result, std::mutex& m) {
    for (int i = 0; i < 10000; i++) {
        m.lock();
        result += 1;
        m.unlock();
    }
}

int main() {
    int counter = 0;
    std::mutex m;

    std::vector<std::thread> workers;
    for (int i = 0; i < 4; i++) {
        workers.push_back(std::thread(worker, std::ref(counter), std::ref(m)));
    }

    for (int i = 0; i < 4; i++) {
        workers[i].join();
    }

    std::cout << "final value of counter: " << counter << std::endl;

    return 0;
}
/*
final value of counter: 40000
final value of counter: 40000
final value of counter: 40000
final value of counter: 40000
*/