#include <iostream>
#include <fstream>
using namespace std;

int main() {
	cout << "Select what you want the new file to be named: \n";
	string s;
	cin >> s;
	ofstream out(s);
	
	cout << "What width and height do you want the room to be?\n";
	int width = 0, height = 0;
	cin >> width >> height;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0 || j == 0 || i == height - 1 || j == width - 1) {
				if ((i < height / 2 && i > height / 2 - 3) || (j < width / 2 + 1 && j > width / 2 - 3)) out << ' ';
				else out << '#';
			}
			else out << ' ';
		}
		out << '\n';
	}
}
