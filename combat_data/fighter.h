#pragma once
#include <iostream>
using namespace std;
class Fighter {
	protected:
		string name;
		int attack;
		float defense;
		int speed;
		int hp;
	public:
		//PLACEHOLDER CONSTRUCTOR: DELETE LATER
		Fighter(string name, int hp, int attack, float defense, int speed);
		//getters
		string get_name();
		int get_health();
		int get_attack();
		float get_defense();
		int get_speed();
		//mutators
		void change_name(string);
		void change_health(int);
		void change_attack(int);
		void change_defense(float);
		void change_speed(int);

};

ostream& operator<<(ostream&, Fighter);

