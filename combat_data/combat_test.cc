//FOR TESTING PURPOSES, DELETE LATER
#include "fighter.h"
#include "monsters.h"
#include "list.h"
#include <CircSLelement.h>
#include <Bridges.h>
#include <iostream>
#include <cmath>
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
	srand(time(0));
	int encounter_size = rand() % 5 + 1;
	CircSLelement<Fighter> *encounter = new CircSLelement<Fighter>(CircSLelement<Fighter>(Fighter("The Wizard", 100, 2, 0.5, 1), "Player"));
	CircSLelement<Fighter> *temp = encounter;
	for (int i = 0; i < encounter_size; i++) {
		temp->setNext(new CircSLelement<Fighter>(Fighter("Goblin", 50, 1, 0.3, 4), "enemy"));
		temp = temp->getNext();
	}
	temp->setNext(encounter);

/*
	temp = encounter;
	while (true) {
		cout << "\n ✳ " << temp->getValue() << " goes first.\n";
		temp = temp->getNext();
	}
*/
	CircSLelement<Fighter> *active = encounter;
	CircSLelement<Fighter> *inactive = active->getNext();
	while (active->getValue().get_health() > 0){	
        if (active->getLabel() == "Player") inactive = active->getNext();
		else inactive = encounter; //the first item in encounter is the player
		

		cout << "\n (╯°□°)╯︵◓" << endl;
        cout << "\n " << active->getValue().get_name() << " is attacking " << inactive->getValue().get_name() << endl;
        int damage = 1;

		damage *= active->getValue().get_attack() / (inactive->getValue().get_defense());

        cout << "\n (。_°)☆ " << endl;
        cout << "\n " << inactive->getValue().get_name() << " takes damage of " << damage << " and the hp goes from " << inactive->getValue().get_health() << " to ";
        inactive->getValue().change_health(inactive->getValue().get_health() - damage);
        cout << inactive->getValue().get_health() << endl;
		
		if (inactive->getValue().get_health() <= 0) remove(inactive);
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
