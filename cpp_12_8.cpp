/*
thread - atomic
*/

#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

void worker(std::atomic<int>& counter) {
    for (int i = 0; i < 100; i++) {
        counter++;
    }
}

int main() {
    std::atomic<int> counter(0);

    std::vector<std::thread> workers;
    for (int i = 0; i < 4; i++) {
        workers.push_back(std::thread(worker, ref(counter)));
    }

    for (int i = 0; i < 4; i++) {
        workers[i].join();
    }

    std::cout << "final value of counter: " << counter << std::endl;

    return 0;
}
/*
g++ -o cpp_12_8.s cpp_12_8.cpp -pthread -S -masm=intel

	lock xadd	DWORD PTR [rax], edx

intel x86 atomic operation
*/