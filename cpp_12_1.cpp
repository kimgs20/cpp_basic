/*
thread
*/

#include <iostream>
#include <thread>

void func1() {
    std::cout << "thread id: " << std::this_thread::get_id() << '\n';
    for (int i = 0; i < 3; i++) {
        std::cout << "thread 1 running...\n";
        if (i == 2) {
            std::cout << std::endl;
        }
    }

}

void func2() {
    std::cout << "thread id: " << std::this_thread::get_id() << '\n';
    for (int i = 0; i < 3; i++) {
        std::cout << "thread 2 running...\n";
        if (i == 2) {
            std::cout << std::endl;
        }
    }
}

void func3() {
    std::cout << "thread id: " << std::this_thread::get_id() << '\n';
    for (int i = 0; i < 3; i++) {
        std::cout << "thread 3 running...\n";
        if (i == 2) {
            std::cout << std::endl;
        }
    }
}

int main() {

    std::cout << "number of total thread(intel core i7-12700K): " 
              << std::thread::hardware_concurrency() << std::endl;

    // std::thread t1 = std::thread(function poniter, std::function, lambda fucntion);
    std::thread t1(func1);
    std::thread t2(func2);
    std::thread t3(func3);

    t1.join();  // wait until end of t1 thread
    t2.join();
    t3.join();

    std::cout << "main fucntion exit" << std::endl;
    return 0;
}
// IMPORTANT!
// $ g++ -o {name} {name}.cpp -pthread

/* the funny thing is i can not predict the result!
   because OS allocate the thread to each core automatically.

1) totally fine
number of total thread(intel core i7-12700K): 20
thread id: 139883448346368
thread 1 running...
thread 1 running...
thread 1 running...

thread id: 139883439953664
thread 2 running...
thread 2 running...
thread 2 running...

thread id: 139883431560960
thread 3 running...
thread 3 running...
thread 3 running...

main fucntion exit


2) messy
number of total thread(intel core i7-12700K): 20
thread id: 140700438427392
thread id: 140700430034688thread 1 running...  << ??
thread id: thread 1 running...                 << ??
thread 1 running...

                    << ??
thread 2 running...
thread 2 running...
thread 2 running...

140700421641984     << ??
thread 3 running...
thread 3 running...
thread 3 running...

main fucntion exit

 */