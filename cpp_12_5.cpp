/*
thread - deadlock and solution
*/

#include <iostream>
#include <mutex>
#include <thread>


// deadlock
/* void worker1(std::mutex& m1, std::mutex& m2) {
    for (int i = 0; i < 10000; i++) {
        std::lock_guard<std::mutex> lock1(m1);
        std::lock_guard<std::mutex> lock2(m2);
    }
}

void worker2(std::mutex& m1, std::mutex& m2) {
    for (int i = 0; i < 10000; i++) {
        std::lock_guard<std::mutex> lock2(m2);
        std::lock_guard<std::mutex> lock1(m1);
    }
} */

void worker1(std::mutex& m1, std::mutex& m2) {
    for (int i = 0; i < 10; i++) {
        m1.lock();
        m2.lock();
        std::cout << "worker1 " << i << std::endl;

        m2.unlock();
        m1.unlock();
    }
}

void worker2(std::mutex& m1, std::mutex& m2) {
    for (int i = 0; i < 10; i++) {
        while (true) {
            m2.lock();

            // if m1 already locked, get off that lock
            if (!m1.try_lock()) {
                m2.unlock();
                continue;
            }

            std::cout << "worker2 " << i << std::endl;
            m1.unlock();
            m2.unlock();
            break;
        }
    }
}

int main() {
    int counter = 0;
    std::mutex m1, m2;

    std::thread t1(worker1, std::ref(m1), std::ref(m2));
    std::thread t2(worker2, std::ref(m1), std::ref(m2));

    t1.join();
    t2.join();

    std::cout << "program exit" << std::endl;  // will not print in deadlock situation

    return 0;
}