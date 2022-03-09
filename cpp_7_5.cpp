/*
standard template library 5
set - priority program
*/

#include <iostream>
#include <set>
#include <string>

template <typename T, typename C>
void print_set(std::set<T, C>& s) {
    for (const auto & elem : s) {
        std::cout << elem << " " << std::endl;
    }
}

class Todo {
    int priority;
    std::string job_desc;

    public:
        Todo(int priority, std::string job_desc)
            : priority(priority), job_desc(job_desc) {}

        friend struct TodoCmp;

        friend std::ostream& operator<<(std::ostream& o, const Todo& td);
};

struct TodoCmp {
    bool operator()(const Todo& t1, const Todo& t2) const {
        if (t1.priority == t2.priority) {
            return t1.job_desc < t2.job_desc;
        }
        return t1.priority > t2.priority;
    }
};

std::ostream& operator<<(std::ostream& o, const Todo& td) {
    o << "[priority: " << td.priority << "]" << td.job_desc;
    return o;
}

int main() {
    std::set<Todo, TodoCmp> todos;

    todos.insert(Todo(1, "production coding"));
    todos.insert(Todo(2, "attend meeting"));
    todos.insert(Todo(1, "buy new device"));
    todos.insert(Todo(3, "watch movies"));
    todos.insert(Todo(2, "send email"));

    print_set(todos);

    std::cout << "- - -" << std::endl;
    std::cout << "if done meeting" << std::endl;
    todos.erase(todos.find(Todo(2, "attend meeting")));
    print_set(todos);

    return 0;
}
