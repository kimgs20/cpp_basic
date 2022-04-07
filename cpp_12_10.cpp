/*
thread - future
*/

#include <future>
#include <iostream>
#include <string>
#include <thread>

using std::string;

void worker(std::promise<string>* p) {
    // result get into future
    p->set_value("some data");
}

int main() {
    std::promise<string> p;

    // promise that return sting data at the future
    std::future<string> data = p.get_future();

    std::thread t(worker, &p);

    // wait until get promised data
    data.wait();

    // wait return = data ready at future
    std::cout << "return data: " << data.get() << std::endl;

    return 0;
}