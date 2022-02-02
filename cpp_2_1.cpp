/*
class
*/

#include <iostream>

class Computer {
    private:
        int power_consumption;
        float performance;

    public:
        void set_computer(int _power_consumption, float _performance) {
            power_consumption = _power_consumption;
            performance = _performance;
        }
        void increase_power(int inc) {
            power_consumption += inc;
            performance += (inc * 0.5);
        }
        void view_status() {
            std::cout << "this computer's power consumption: " << power_consumption << std::endl;
            std::cout << "this computer's performance: " << performance << std::endl;
        }
};  // important!

int main() {
    Computer computer;
    computer.set_computer(600, 100);
    computer.increase_power(100);

    computer.view_status();
    return 0;
}
