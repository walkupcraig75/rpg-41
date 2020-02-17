#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void load_rooms(vector<vector<vector<char>>> &room_data, const vector<string> &paths) {
	for (int i = 0; i < paths.size(); i++) {
		ifstream ins("map_data/" + paths.at(i));
		
		vector<vector<char>> col;
		while (ins) {
			string s;
			getline(ins, s);
			if (!ins) break;

			vector<char> row;
			for (char c : s) {
				row.push_back(c);
			}

			col.push_back(row);
		}

		room_data.push_back(col);
	}

}

