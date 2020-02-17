#include <ctime>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <string>
#include <iostream>

using namespace std;

class BaseEnemy;

class Player {
  public:
	Player() : Health(100), AttackMag(10) { }

	short Health;
	short AttackMag;
	void Attack(BaseEnemy &);
};
  class BaseEnemy {
    public:
      BaseEnemy() : Health(50), AttackMag(5) { }

      short Health;
      short AttackMag;

      virtual void Attack(Player &);
      // Additional information.
  };
void Player::Attack(BaseEnemy &Target) {
	Target.Health -= this->AttackMag;
	if (Target.Health < 0)
		Target.Health = 0;
}


void BaseEnemy::Attack(Player &Target) {
	Target.Health -= this->AttackMag;
	if (Target.Health < 0)
		Target.Health = 0;
}

void clear(int t) {
	sleep(t);
	system("clear");
}

void intro() {
	clear(0);
	cout << "Welcome to the...\n";
	clear(2);
	system("figlet BATTLE");
	clear(2);
}
int main() {

	intro();
	Player *active = &hero;
	BaseEnemy *inactive = &monster;


	



}
