/*
copy constructor, deep copy, shallow copy, destructor
*/

#include <iostream>

class Marine {
    int hp;
    int coord_x, coord_y;
    int damage;
    bool is_dead;

    public:
        Marine();               // default constructor
        Marine(int x, int y);

        int attack();
        void be_attacked(int damage_earn);
        void move(int x, int y);

        void show_status();
};

Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
}

Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
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

int main() {
    Marine* marines[100];

    marines[0] = new Marine(2, 3);
    marines[1] = new Marine(3, 5);

    marines[0]->show_status();
    marines[0]->show_status();

    std::cout << std::endl << "marine1 attack marine2" << std::endl;

    marines[0]->show_status();
    marines[0]->show_status();
    
    delete marines[0];
    delete marines[1];  // auto delete: destuctor

    return 0;
}

/*
new-delete != malloc

new: automatically call constructor at dynamically create object (?) (line60, 61)


*** 2/5 review malloc, new, delete
*/
