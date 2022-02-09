/*
copy constructor, shallow copy, deep copy
*/

#include <string.h>
#include <iostream>

class Cannon {
    int hp, shield;
    int coord_x, coord_y;
    int damage;

    char *name;

    public:
        Cannon(int x, int y);      // constructor
        Cannon(int x, int y, const char *cannon_name);

        Cannon(const Cannon &cn); // for deep copy
        // typical definition of copy constructor
        // T(const T& a);
        // get object 'a' of another 'T' componenet as constant reference (what?)

        ~Cannon();                  // destructor

        void show_status();
};

Cannon::Cannon(int x, int y) {
    std::cout << "call constructor" << std::endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = NULL;
}

Cannon::Cannon(const Cannon& cn) {
    std::cout << "call copy constructor" << std::endl;

    hp = cn.hp;
    shield = cn.shield;
    coord_x = cn.coord_x;
    coord_y = cn.coord_y;
    damage = cn.damage;
    name = cn.name;

    name = new char[strlen(cn.name) + 1];  // deep copy
    strcpy(name, cn.name);
}

Cannon::Cannon(int x, int y, const char *cannon_name) {
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = new char[strlen(cannon_name) + 1];  // shallow copy
    strcpy(name, cannon_name);
}
// runtime error of shallow copy: free(): double free detected in tcache 2

Cannon::~Cannon() {
    if (name) delete[] name;
}

void Cannon::show_status() {
    std::cout << "Cannon" << std::endl;
    std::cout << "Location: ( " << coord_x << ", " << coord_y << ")" << std::endl;
    std::cout << "HP: " << hp << std::endl;
}

int main() {
    Cannon cn1(3, 3, "cannon");
    Cannon cn2 = cn1;               // shallow copy

    cn1.show_status();
    cn2.show_status();

    return 0;
}
