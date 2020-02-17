#include "heroes.h"
#include <iostream>
using namespace std;

//constructor (PLACEHOLDER FOR TESTING: DELETE LATER)
//unique constructors may be needed for child classes
Hero::Hero(string name, int hp, int attack, float defense, int speed) {
    this->name = name;
    this->hp = hp;
    this->attack = attack;
    this->defense = defense;
	
    this->speed = speed;
}

//getters
string Hero::get_name() { return name; }
int Hero::get_health() { return hp; }
int Hero::get_attack() { return attack; }
float Hero::get_defense() { return defense; }
int Hero::get_speed() { return speed; }



//operators
ostream& operator<<(ostream& outs, Hero h) {
    outs << h.get_name() << endl;
    outs << "Health: " << h.get_health() << endl;
    outs << "Attack: " << h.get_attack() << endl;
    outs << "Defense: " << h.get_defense() << endl;
    outs << "Speed: " << h.get_speed() << endl;
    return outs;
}
