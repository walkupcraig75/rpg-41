#pragma once
#include <vector>
#include <cassert>
#include <string>
#include <iostream>
#include <fstream>
#include <random>
#include <ncurses.h>
#include "load_rooms.h"
using namespace std; 

class Map {
	vector<vector<char>> view;//what actually gets put on the screen, pulls from rooms based off of layout
	vector<vector<vector<char>>> rooms;//stores what the rooms look like (each room is a 2d vector of chars)
	vector<vector<int>> layout;//stores which rooms are where
	//file names of all the rooms
	const vector<string> paths = {"room_01.txt", "room_02.txt"};
	default_random_engine gen;//setting up RNG
	public:
	static const char HERO     = 'H';
	static const char MONSTER  = 'M';
	static const char WALL     = '#';
	static const char WATER    = '~';
	static const char OPEN     = '.';
	static const char TREASURE = '$';
	static const size_t WIDTH = 216; 
	static const size_t HEIGHT = 120;
	static const size_t DISPLAY = 19;
	static const size_t LAYOUT_SIZE = 6;
	static const size_t ROOM_WIDTH = 36;
	static const size_t ROOM_HEIGHT = 20;
	//load map
	void init_map() {
		uniform_int_distribution<int> d100(1, 100);
		layout.clear();
		for (int i = 0; i < LAYOUT_SIZE; i++) {
			vector<int> row;
			for (int j = 0; j < LAYOUT_SIZE; j++) {
				row.push_back(d100(gen) % paths.size());
			}
			layout.push_back(row);
		}

		/*
		for (const auto &v : layout) {
			for (int i : v) {
				cout << i;
			}
			cout << endl;
		}
		*/
		//iterates through the different roooms on the y axis
		for (int i = 0; i < LAYOUT_SIZE; i++) {
			//iterates through contents of room on y axis
			for (int j = 0; j < ROOM_HEIGHT; j++) {
				//iterates through the different rooms on the x axis
				vector<char> row;
				for (int k = 0; k < LAYOUT_SIZE; k++) {
					//iterates through contents of room on x axis
					for (int l = 0; l < ROOM_WIDTH; l++) {
						row.push_back(rooms.at(layout.at(i).at(k)).at(j).at(l));
					}
				}
				view.push_back(row);
			}
		}

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
				if (view.at(i).at(j) == WALL)
					color = 5;
				else if (view.at(i).at(j) == WATER)
					color = 2;
				else if (view.at(i).at(j) == TREASURE)
					color = 4;
				else if (view.at(i).at(j) == MONSTER)
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
					mvaddch(i-start_y,j-start_x,view.at(i).at(j));
				}
				attroff(COLOR_PAIR(color));
				//attroff(A_UNDERLINE | A_BOLD);
			}
		}

	}
	Map() {
		load_rooms(rooms, paths);
		init_map();
	}

	//returns whatever character is in the map at the provided coordinates
	char spot_data(int x, int y) {
		assert(x < WIDTH && y < HEIGHT && x >= 0 && y >= 0);
		return view.at(y).at(x);
	}
};
