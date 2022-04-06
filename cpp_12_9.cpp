/*
thread - memory order
*/

#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

using std::memory_order_relaxed;

void t1(std::atomic<int>* a, std::atomic<int>* b) {
    b->store(1, memory_order_relaxed);      // b = 1 (write)
    int x = a->load(memory_order_relaxed);  // x = a (read)

    std::cout << "x: " << x << std::endl;
}

void t2(std::atomic<int>* a, std::atomic<int>* b) {
    a->store(1, memory_order_relaxed);      // a = 1 (write)
    int y = b->load(memory_order_relaxed);  // y = b (read)

    std::cout << "y: " << y << std::endl;
}

int main() {
    std::vector<std::thread> threads;

    std::atomic<int> a(0);
    std::atomic<int> b(0);

    threads.push_back(std::thread(t1, &a, &b));
    threads.push_back(std::thread(t2, &a, &b));

    for (int i = 0; i < 2; i++) {
        threads[i].join();
    }

    return 0;
}
/*
1)
y: 1
x: 0

2)
y: 0
x: 1

3) impossible
x: 0
y: 0
*/