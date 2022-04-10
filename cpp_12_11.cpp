/*
thread - promise-future
*/

// 1. condition variable
/* #include <condition_variable>
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
} */

// 2. promise - future (much clean and easy than cv)
#include <exception>
#include <future>
#include <iostream>
#include <string>
#include <thread>

using std::string;

void worker(std::promise<string>* p) {
    try {
        throw std::runtime_error("some error");
    } catch (...) {
        // should deliver exception_ptr to set_exception
        p->set_exception(std::current_exception());
    }
}

int main() {
    std::promise<string> p;

    std::future<string> data = p.get_future();

    std::thread t(worker, &p);

    data.wait();

    try {
        data.get();
    } catch (const std::exception& e) {
        std::cout << "exception: " << e.what() << std::endl;
    }
    t.join();

    return 0;
}
