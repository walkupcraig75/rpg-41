#pragma once
#include <vector>
#include <cassert>
#include <string>
#include <iostream>
#include <fstream>
#include <random>
#include <ncurses.h>
using namespace std; //Boo hiss

class Map {
	vector<vector<char>> map;
	default_random_engine gen;
	public:
	static const char HERO     = 'H';
	static const char MONSTER  = 'M';
	static const char WALL     = '#';
	static const char WATER    = '~';
	static const char OPEN     = '.';
	static const char TREASURE = '$';
	static const size_t WIDTH = 36; //World is a 100x100 map
	static const size_t HEIGHT = 20;
	static const size_t DISPLAY = 19; //Show a 10x10 area at a time
	//Randomly generate map
	void init_map() {
		string filename = "map_data/room_01.txt";
		ifstream ins(filename);
		while (ins) {
			string s;
			getline(ins, s);
			if (!ins) break;
			
			vector<char> vec;
			for (char c : s) { vec.push_back(c); }
			map.push_back(vec);
		}
		if (map.size() != HEIGHT && map.at(0).size() != WIDTH) cout << "error reading map\n";
	}
	//Draw the DISPLAY tiles around coordinate (x,y)
	void draw(int x, int y) {
		int start_x = x - DISPLAY/2;
		int end_x = x + DISPLAY/2;
		int start_y = y - DISPLAY/2;
		int end_y = y + DISPLAY/2;

		//Bounds check to handle the edges
		if (start_x < 0) {
			end_x = end_x - start_x;
			start_x = 0;
		}
		if (end_x > WIDTH-1) {
			start_x = start_x - (end_x - (WIDTH-1));
			end_x = WIDTH-1;
		}
		if (start_y < 0) {
			end_y = end_y - start_y;
			start_y = 0;
		}
		if (end_y > HEIGHT-1) {
			start_y = start_y - (end_y - (HEIGHT-1));
			end_y = HEIGHT-1;
		}

		
		//Now draw the map using NCURSES
		for (size_t i = start_y; i <= end_y; i++) {
			for (size_t j = start_x; j <= end_x; j++) {
				//if (i == cursor_x && j == cursor_y)
				//	attron(A_UNDERLINE | A_BOLD);
				int color = 1;
				if (map.at(i).at(j) == WALL)
					color = 5;
				else if (map.at(i).at(j) == WATER)
					color = 2;
				else if (map.at(i).at(j) == TREASURE)
					color = 4;
				else if (map.at(i).at(j) == MONSTER)
					color = 6;
				if (i == y && j == x) {
					color = 3;
				}
				if (i == y && j == x) {
					color = 3;
					attron(COLOR_PAIR(color));
					mvaddch(i-start_y,j-start_x, HERO);
				} else {
					attron(COLOR_PAIR(color));
					mvaddch(i-start_y,j-start_x,map.at(i).at(j));
				}
				attroff(COLOR_PAIR(color));
				//attroff(A_UNDERLINE | A_BOLD);
			}
		}

	}
	Map() {
		init_map();
	}

	//returns whatever character is in the map at the provided coordinates
	char spot_data(int x, int y) {
		assert(x < WIDTH && y < HEIGHT && x >= 0 && y >= 0);
		return map.at(y).at(x);
	}
};
