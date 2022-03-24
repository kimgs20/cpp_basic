/*
weak_ptr
*/

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class A {
    std::string s;
    std::weak_ptr<A> other;
    
    public:
        A(const std::string& s) : s(s) { std::cout << "get resource" << std::endl; }

        ~A() { std::cout << "call destructor" << std::endl; }

        void set_other(std::weak_ptr<A> o) { other = o; }
        void access_other() {
            std::shared_ptr<A> o = other.lock();
            if (o) {
                std::cout << "access: " << o->name() << std::endl;
            } else {
                std::cout << "already destructed" << std::endl;
            }
        }
        std::string name() { return s; }
};

int main() {
    std::vector<std::shared_ptr<A>> vec;
    vec.push_back(std::make_shared<A>("resource 1"));
    vec.push_back(std::make_shared<A>("resource 2"));

    vec[0]->set_other(vec[1]);
    vec[1]->set_other(vec[0]);

    // ref count of pa and pb is steady.
    std::cout << "vec[0] ref count: " << vec[0].use_count() << std::endl;
    std::cout << "vec[1] ref count: " << vec[1].use_count() << std::endl;

    // access to object with weak_ptr
    vec[0]->access_other();

    // delete last element (vec[1])
    vec.pop_back();
    vec[0]->access_other();

    return 0;
}
/*
get resource
get resource
vec[0] ref count: 1
vec[1] ref count: 1
access: resource 2
call destructor
already destructed
call destructor
*/