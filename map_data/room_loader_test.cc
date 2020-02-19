#include "load_rooms.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<vector<vector<char>>> room_data;
	vector<string> paths = {"room_01.txt", "room_02.txt"};
	load_rooms(room_data, paths);

	for (int i = 0; i < room_data.size(); i++) {
		cout << paths.at(i) << endl;
		for (const auto &v : room_data.at(i)) {
			for (char c : v) {
				cout << c;
			}
			cout << endl;
		}
	}
}
