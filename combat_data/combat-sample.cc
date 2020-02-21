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
//To delete a node from list
void list_remove(CircSLelement<Fighter> *removed, CircSLelement<Fighter> *&head) {
//If link list is empty
    if (head == NULL) return;
//If list contains single node
    if (head == removed and head-> getNext() == head) {
        free(head);
        head = NULL;
		return;
    }
    CircSLelement<Fighter> *last = head, *d;
//  CircSLelement<Fighter> *last = head;
//  CircSLelement<Fighter> *d = head;
//If the head were to be deleted
    if (head == removed) {
        while (last-> getNext() != head)
            last = last -> getNext();


        //Point last node to the next
        last->setNext( head -> getNext());
        free(head);
        head = last -> getNext();

    }
    //Node to be deleted not found or end of list not reached
    while (last -> getNext() != head && last -> getNext() != removed) {
        last = last -> getNext();
    }
    cout << "Found Target!\n";
    d = last->getNext();
    last->setNext(d->getNext());
    free(d);
    cout << "Eliminated the target!\n";
}
bool player_lives(CircSLelement<Fighter> *head) {
    cout << "in function\n";
    cout << head << endl;
    if (head == NULL) return false;
    cout << head << endl;
    cout << head->getLabel() << endl;
    CircSLelement<Fighter> *temp = head;
	cout << head->getNext() << endl;
	temp = temp->getNext();
    cout << temp << endl;
    while(temp != head) {
        cout << temp << endl;
        if (temp == NULL) return false;
        if (temp->getLabel() == "Monster") {
            temp = temp->getNext();
            continue;
        }
        return true;
    }
    return false;
}
void combat_mode() {
cout << endl;
system("figlet -f smblock BATTLE  | lolcat"); //prints title to the screen
cout << "(ง'̀-'́)ง" << endl;
srand(time(0));
int encounter_size = rand() % 5 + 100;
CircSLelement<Fighter> *encounter = new CircSLelement<Fighter>(CircSLelement<Fighter>(Fighter("The Wizard", 100, 2, 0.5, 1), "Player"));
CircSLelement<Fighter> *temp = encounter;
for (int i = 0; i < encounter_size; i++) {
    temp->setNext(new CircSLelement<Fighter>(Fighter("Goblin " + to_string(i), 50, 1, 0.3, 4), "enemy"));
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
    CircSLelement<Fighter> *active = encounter; //Head, attacking
    CircSLelement<Fighter> *inactive = active->getNext(); //Defending
    while (active->getValue().get_health() > 0){
        if (active->getLabel() == "Player") inactive = active->getNext();
        else inactive = encounter; //the first item in encounter is the player. 


        cout << "\n (╯°□°)╯︵◓" << endl;
        cout << "\n " << active->getValue().get_name() << " is attacking " << inactive->getValue().get_name() << endl;
        int damage = 1;

        damage *= active->getValue().get_attack() / (inactive->getValue().get_defense());

        cout << "\n (。_°)☆ " << endl;
        cout << "\n " << inactive->getValue().get_name() << " takes damage of " << damage << " and the hp goes from " << inactive->getValue().get_health() << " to ";
                inactive->getValue().change_health(inactive->getValue().get_health() - damage);
        cout << inactive->getValue().get_health() << endl;

        if (inactive->getValue().get_health() <= 0) {
            cout << inactive->getValue() << endl;
            list_remove(inactive, encounter);
            temp = encounter;
            /*
            while (true) {
                cout << "\n ✳ " << temp->getValue() << "\n";
                cout << encounter_size;
                temp = temp->getNext();
            }
            */
        }

        cout << "before end of list\n";
        if (active->getNext() == active) break;
        cout << "still works\n";
        cout << encounter << endl;
        /*
        while (true) {
            cout << temp << endl;
            temp->setNext(temp->getNext());
            if (temp == encounter || temp == NULL) break;
        }
        */
        if (!player_lives(encounter)) break;
        cout << encounter << endl;
        cout << "encounter next\n";
        cout << active << endl;
        active = active->getNext();
    }

    cout << endl;
    cout << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
    if (encounter->getValue().get_health() > 0) system("figlet VICTORY!!!!! | lolcat");
    else system("figlet Defeat...");
    cout << "\n ";
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
      
