//FOR TESTING PURPOSES, DELETE LATER
#include "fighter.h"
#include "monsters.h"
#include "list.h"
#include <iostream>
using namespace std;


void die(string s = "INVALID INPUT!") {
    cout << s << endl;
    exit(1);
}

// If you kill monster
void win() {
	system("figlet WINNER");
	exit(0);
}

// If you monster kills you
void lose() {
	system("figlet GAME");
	system("figlet OVER");
	exit(0);
}

void combat_mode() {
    cout << endl;
    system("figlet -f smblock BATTLE  | lolcat"); //prints title to the screen
    cout << "(ง'̀-'́)ง" << endl;
	Fighter f("Haigen - The Troll", 100, 10, 2, 1);
	Fighter d("The Wizard", 10, 2, 0.5, 1);

	LL* head = new LL(f, nullptr);
	insert(head, LL(d, nullptr));

	Fighter *active = &f;
	Fighter *inactive = &d;
	
	cout << "\n ✳ " << active->get_name() << " goes first.\n";
	
	while (active->get_health() > 0){	
        cout << "\n (╯°□°)╯︵◓" << endl;
        cout << "\n " << active->get_name() << " is attacking " << inactive->get_name() << endl;
        int damage = 1;

		damage *= active->get_attack() / (inactive->get_defense());

        cout << "\n (。_°)☆ " << endl;
        cout << "\n " << inactive->get_name() << " takes damage of " << damage << " and the hp goes from " << inactive->get_health() << " to ";
        inactive->change_health(inactive->get_health() - damage);
        cout << inactive->get_health() << endl;
        if (active == &d) {
            active = &f;
            inactive = &d;
        } else {
            active = &d;
            inactive = &f;

        }
	}
		
    cout << endl;
    cout << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
    system("figlet VICTORY!!!!! | lolcat");
    cout << "\n ";
    cout << " 🏆 " << inactive->get_name() << " has defeated " << active->get_name() << " !!!" << endl;
    cout << "\n   (∩ᄑ_ᄑ)⊃*･｡*･:≡( ε:) " << endl;
    cout << endl;
    cout << endl;
    cout << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";

	delete head;
}



int main() {
	
	//MONSTERS
	int choice;
	cout << "Fight Mode? 1.) Yes 2.)  No " << endl;
	cin >> choice;
	if (!cin || choice < 0) die();
	if (choice == 1) {
		combat_mode();
	}


}
