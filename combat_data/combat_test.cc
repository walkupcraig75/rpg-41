//FOR TESTING PURPOSES, DELETE LATER
#include "fighter.h"
#include "slime.h"
#include <iostream>
using namespace std;

int main() {
	Fighter f("Slime", 10, 2, 0.5, 3);
	Slime s(10, 2, 0.5, 3);
	cout << f << endl;
	cout << s << endl;
}
