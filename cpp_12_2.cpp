/*
thread - partial sum
*/

#include <iostream>
#include <thread>
#include <vector>

using std::thread;
using std::vector;

void worker(vector<int>::iterator start, vector<int>::iterator end, int* result) {
    int sum = 0;
    for (auto itr = start; itr < end; ++itr) {
        sum += *itr;
    }
    *result = sum;

    thread::id this_id = std::this_thread::get_id();
    std::cout << "calculated result of thread " << this_id << " from "
              << *start << " to " << *(end - 1) << ": " << sum << std::endl;
}

int main() {
    vector<int> data(10000);
    for (int i = 0; i < 10000; i++) {
        data[i] = i;
    }

    // vector that stroe partial sum of each thread
    vector<int> partial_sums(4);

    vector<thread> workers;
    for (int i = 0; i < 4; i++) {
        workers.push_back(thread(worker, data.begin() + i * 2500,
                                    data.begin() + (i + 1) *2500, &partial_sums[i]));
    }

    for (int i = 0; i < 4; i++) {
        workers[i].join();
    }

    int total = 0;
    for (int i = 0; i < 4; i++) {
        total += partial_sums[i];
    }

    std::cout << "total sum: " << total << std::endl;
    return 0;
}
/*
calculated result of thread 139850280920832 from 7500 to 9999: 21873750
calculated result of thread 139850297706240 from 2500 to 4999: 9373750
calculated result of thread 139850289313536 from 5000 to 7499: 15623750
calculated result of thread 139850306098944 from 0 to 2499: 3123750
total sum: 49995000
*/