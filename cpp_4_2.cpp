/*
inheritance
*/

#include <iostream>

class Employee {
    std::string name;
    int age;

    std::string position;
    int rank;

    public:
        Employee(std::string name, int age, std::string position, int rank)
            : name(name), age(age), position(position), rank(rank) {}

        // copy constructor
        Employee(const Employee& employee) {
            name = employee.name;
            age = employee.age;
            position = employee.position;
            rank = employee.rank;
        }

        // default constructor
        Employee() {}

        void print_info() {
            std::cout << name << "(" << position << ", " << age << "): "
                << calculate_pay() << "dollar" << std::endl;
        }
        int calculate_pay() { return 2000 + rank * 500; }
};

class EmployeeList {
    int alloc_employee;
    int current_employee;
    Employee** employee_list;

    public:
        EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
            employee_list = new Employee*[alloc_employee];
            current_employee = 0;
        }
    
    void add_employee(Employee* employee) {
        employee_list[current_employee] = employee;
        current_employee++;
    }

    int current_employee_num() { return current_employee; }

    void print_employee_info() {
        int total_pay = 0;
        for (int i = 0; i < current_employee; i++) {
            employee_list[i]->print_info();
            total_pay += employee_list[i]->calculate_pay();
        }

        std::cout << "total pay: " << total_pay << " dollar" << std::endl;
    }
    ~EmployeeList() {
        for (int i = 0; i < current_employee; i++) {
            delete employee_list[i];
        }
        delete[] employee_list;
    }
};

int main() {
    EmployeeList emp_list(10);
    emp_list.add_employee(new Employee("A", 34, "staff", 1));  // name, age, position, rank
    emp_list.add_employee(new Employee("B", 34, "staff", 1));

    emp_list.add_employee(new Employee("C", 45, "director", 7));
    emp_list.add_employee(new Employee("D", 43, "manager", 4));
    emp_list.add_employee(new Employee("E", 43, "manager", 4));
    emp_list.add_employee(new Employee("F", 36, "assistance manager", 3));
    emp_list.add_employee(new Employee("G", 29, "intern", 1));
    emp_list.print_employee_info();
    return 0;
}
