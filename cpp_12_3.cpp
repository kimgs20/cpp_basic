/*
race condition
*/

#include <iostream>
#include <thread>
#include <vector>

void worker(int& counter) {
    for (int i = 0; i < 10000; i++) {
        counter += 1;
    }
}

int main() {
    int counter = 0;

    std::vector<std::thread> workers;
    for (int i = 0; i < 4; i++) {
        workers.push_back(std::thread(worker, std::ref(counter)));
    }

    for (int i = 0; i < 4; i++) {
        workers[i].join();
    }

    std::cout << "final value of counter: " << counter << std::endl;

    return 0;
}
/*
values of counter are strange (because of 'counter += 1;' on multiple thread)

final value of counter: 26652
final value of counter: 40000
final value of counter: 40000
final value of counter: 30039
final value of counter: 28569

solution: mutex
*/