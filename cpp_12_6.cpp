/* 
thread - producer and consumer pattern
web crawling
producer: web crawler
consumer: page analizer
*/

#include <chrono>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

void producer(std::queue<std::string>* downloaded_pages, std::mutex* m, int index) {
    for (int i = 0; i < 5; i++) {
        // time to download web pages
        // each thraed have different download speed
        std::this_thread::sleep_for(std::chrono::milliseconds(100 * index));
        std::string content = "website: " + std::to_string(i) + " from thread(" +
                                std::to_string(index) + ")\n";

        // data should be placed in critical section because shared among threads
        m->lock();
        downloaded_pages->push(content);
        m->unlock();
    }
}

void consumer(std::queue<std::string>* downloaded_pages, std::mutex* m, int* num_processed) {
    // totla num of pages: 5 * 5 = 25
    while(*num_processed < 25) {
        m->lock();
        // wait if there is no downloaded pages
        if (downloaded_pages->empty()) {
            m->unlock();
            // check after 10 millisecond again (this is inefficient)
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            continue;
        }

        // read front page and delete from wating list
        std::string content = downloaded_pages->front();
        downloaded_pages->pop();
        (*num_processed)++;
        m->unlock();

        // process contents
        std::cout << content;
        std::this_thread::sleep_for(std::chrono::milliseconds(80));
    }
}

int main() {
    std::queue<std::string> downloaded_pages;
    std::mutex m;

    std::vector<std::thread> producers;
    for (int i = 0; i < 5; i++) {
        producers.push_back(std::thread(producer, &downloaded_pages, &m, i + 1));
    }

    int num_processed = 0;
    std::vector<std::thread> consumers;
    for (int i = 0; i < 3; i++) {
        consumers.push_back(std::thread(consumer, &downloaded_pages, &m, &num_processed));
    }

    for (int i = 0; i < 5; i++) {
        producers[i].join();
    }

    for (int i = 0; i < 3; i++) {
        consumers[i].join();
    }

    return 0;
}
/* 
website: 0 from thread(1)
website: 0 from thread(2)
website: 1 from thread(1)
website: 0 from thread(3)
website: 2 from thread(1)
website: 0 from thread(4)
website: 1 from thread(2)
website: 3 from thread(1)
website: 0 from thread(5)
website: 4 from thread(1)
website: 1 from thread(3)
website: 2 from thread(2)
website: 1 from thread(4)
website: 3 from thread(2)
website: 2 from thread(3)
website: 1 from thread(5)
website: 4 from thread(2)
website: 3 from thread(3)
website: 2 from thread(4)
website: 2 from thread(5)
website: 4 from thread(3)
website: 3 from thread(4)
website: 3 from thread(5)
website: 4 from thread(4)
website: 4 from thread(5)
*/