/*
class, constructor, destructor
*/

#include <iostream>
#include <string.h>

class Marine {
    int hp;
    int coord_x, coord_y;
    int damage;
    bool is_dead;
    char* name;

    public:
        Marine();  // default constructor
        Marine(int x, int y, const char* marine_name);  // constructor
        Marine(int x, int y);
        ~Marine();  // class destructor

        int attack();
        void be_attacked(int damage_earn);
        void move(int x, int y);

        void show_status();
        void return_name();
};

Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
}

Marine::Marine(int x, int y, const char* marine_name) {
    name = new char[strlen(marine_name) + 1];
    strcpy(name, marine_name);
    // strlen, strcpy in <string.h>

    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}

Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
    name = NULL;
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return damage; }

void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
    std::cout << "Marine" << std::endl;
    std::cout << "Location: (" << coord_x << ", " << coord_y << ") " << std::endl;
    std::cout << "HP: " << hp << std::endl;
}

void Marine::return_name() {
    std::cout << name << std::endl;
}

Marine::~Marine() {  // no arguments, return
    std::cout << "call destructor of " << name << std::endl;
    if (name != NULL) {
        delete[] name;  // because name is dynamically allocated by array of char
    }
}

int main() {
    Marine* marines[100];  // pointer to a class
    // Marine *marines[100];

    marines[0] = new Marine(2, 3, "Marine 1");  // c++ style dynamic allocation
    marines[1] = new Marine(3, 5, "Marine 2");

                                    // ptr->method = (*ptr).method
    marines[0]->show_status();      // call method use -> instead of . (because this array of pointers)
    // (*marines[0]).show_status();
    marines[1]->show_status();

    std::cout << std::endl << "marine1 attack marine2" << std::endl;

    marines[0]->be_attacked(marines[1]->attack());

    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0];  // call destructor
    delete marines[1];

    return 0;
}
// new vs. malloc
// new: dynamically make object and call constructor at the same time.