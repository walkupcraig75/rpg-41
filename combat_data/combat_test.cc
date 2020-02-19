//FOR TESTING PURPOSES, DELETE LATER
#include "fighter.h"
#include "monsters.h"
#include "list.h"
#include <CircSLelement.h>
#include <Bridges.h>
#include <iostream>
using namespace std;
using namespace bridges;

//helper function for linked list
CircSLelement<Fighter> *insertFront(
			CircSLelement<Fighter> *tailElement,
			CircSLelement<Fighter> *newElement);

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

	CircSLelement<Fighter> *player = new CircSLelement<Fighter>(CircSLelement<Fighter>(Fighter("The Wizard", 10, 2, 0.5, 1), "Player"));

	CircSLelement<Fighter> *encounter[] = {
		new CircSLelement<Fighter>(Fighter("Haigen - The Troll", 100, 10, 2, 1), "Enemy"),
		new CircSLelement<Fighter>(CircSLelement<Fighter>(Fighter("The Wizard", 10, 2, 0.5, 1), "Player"))
	};
	encounter[0]->setNext(encounter[1]);
	encounter[1]->setNext(encounter[0]);
	
	CircSLelement<Fighter> *temp = encounter[0];
	/*
	while (true) {
		cout << "\n ✳ " << temp->getValue() << " goes first.\n";
		temp = temp->getNext();
	}
	*/
	CircSLelement<Fighter> *active = encounter[0];
	CircSLelement<Fighter> *inactive = active->getNext();
	while (active->getValue().get_health() > 0){	
        inactive = active->getNext();
		cout << "\n (╯°□°)╯︵◓" << endl;
        cout << "\n " << active->getValue().get_name() << " is attacking " << inactive->getValue().get_name() << endl;
        int damage = 1;

		damage *= active->getValue().get_attack() / (inactive->getValue().get_defense());

        cout << "\n (。_°)☆ " << endl;
        cout << "\n " << inactive->getValue().get_name() << " takes damage of " << damage << " and the hp goes from " << inactive->getValue().get_health() << " to ";
        inactive->getValue().change_health(inactive->getValue().get_health() - damage);
        cout << inactive->getValue().get_health() << endl;
		
		active = active->getNext();
	}
		
    cout << endl;
    cout << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
    system("figlet VICTORY!!!!! | lolcat");
    cout << "\n ";
    cout << " 🏆 " << inactive->getValue().get_name() << " has defeated " << active->getValue().get_name() << " !!!" << endl;
    cout << "\n   (∩ᄑ_ᄑ)⊃*･｡*･:≡( ε:) " << endl;
    cout << endl;
    cout << endl;
    cout << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
	
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
