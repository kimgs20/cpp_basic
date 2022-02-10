/*
initializer list
static member variable
*/

#include <iostream>

class Marine {
    static int total_marine_num;  // for counting num of units

    int hp;
    int coord_x, coord_y;
    bool is_dead;

    const int default_damage;

    public:
        Marine();               // default constructor
        Marine(int x, int y);                           // ?
        Marine(int x, int y, int default_damage);       // ?

        int attack();
        void be_attacked(int damage_earn);
        void move(int x, int y);

        void show_status();
        static void show_total_marine();
        ~Marine() { total_marine_num--; }  // destuctor and decrease count
};

int Marine::total_marine_num = 0;

void Marine::show_total_marine() {
    std::cout << "total number of units: " << total_marine_num << std::endl;
}

// initializer list
Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
    total_marine_num++;
}

Marine::Marine(int x, int y)
    : hp(50), coord_x(x), coord_y(y), default_damage(5), is_dead(false) {
    total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage) 
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(5),
      is_dead(false) {
          total_marine_num++;
      }

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return default_damage; }

void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
    std::cout << "Marine" << std::endl;
    std::cout << "Location: (" << coord_x << ", " << coord_y << ") " << std::endl;
    std::cout << "HP: " << hp << std::endl;
    std::cout << "total number of units: " << total_marine_num << std::endl;
}

void create_marine() {
    Marine marine3(10, 10, 4);
    marine3.show_total_marine();
}

int main() {
    Marine marine1(2, 3, 5);
    marine1.show_total_marine();

    Marine marine2(3, 5, 10);
    marine2.show_total_marine();

    create_marine();

    std::cout << std::endl << "marine1 attack marine2" << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();

    return 0;
}
