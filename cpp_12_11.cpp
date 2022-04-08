/*
thread - promise-future
*/

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

std::condition_variable cv;
std::mutex m;
bool done = false;
std::string info;

void worker() {
    {
    std::lock_guard<std::mutex> lk(m);
    info = "some data";
    done = true;
    }
    cv.notify_all();
}

int main() {
    std::thread t(worker);

    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, [] { return done; });
    lk.unlock();

    std::cout << "return data: " << info << std::endl;

    t.join();

    return 0;
}