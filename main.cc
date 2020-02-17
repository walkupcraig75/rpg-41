#include "map.h"
#include <unistd.h>

const unsigned int TIMEOUT = 10; //Milliseconds to wait for a getch to finish
const int UP = 65; //Key code for up arrow
const int DOWN = 66;
const int LEFT = 68;
const int RIGHT = 67;

bool is_stairs(char c) {
	if (c == '|' || c == '-' || c == '_') return true;
	return false;
}

void turn_on_ncurses() {
	initscr();//Start curses mode
	start_color(); //Enable Colors if possible
	init_pair(1,COLOR_WHITE,COLOR_BLACK); //Set up some color pairs
	init_pair(2,COLOR_CYAN,COLOR_BLACK);
	init_pair(3,COLOR_GREEN,COLOR_BLACK);
	init_pair(4,COLOR_YELLOW,COLOR_BLACK);
	init_pair(5,COLOR_RED,COLOR_BLACK);
	init_pair(6,COLOR_MAGENTA,COLOR_BLACK);
	clear();
	noecho();
	cbreak();
	timeout(TIMEOUT); //Set a max delay for key entry
}

//places the player when a new floor starts, makes sure to not spawn them in a wall
void start_pos(int &x, int &y, const Map &map) {
	x = Map::WIDTH / 2;
	y = Map::HEIGHT / 2;
	for (int i = Map::HEIGHT / 2; i < Map::HEIGHT; i++) {
		if (map.spot_data(x, i) == Map::OPEN) {
			y = i;
			break;
		}
	}
	
}


int main() {
	turn_on_ncurses();
	Map map;
	//determine starting location
	int x, y;
	start_pos(x, y, map);
	
	while (true) {
		int ch = getch(); // Wait for user input, with TIMEOUT delay
		if (ch == 'q' || ch == 'Q') break;
		else if (ch == RIGHT && map.spot_data(x + 1, y) != Map::WALL) {
			x++;
			if (y >= Map::HEIGHT) y = Map::HEIGHT - 1; //Clamp value
		}
		else if (ch == LEFT && map.spot_data(x - 1, y) != Map::WALL) {
			x--;
			if (y < 0) y = 0;
		}
		else if (ch == UP && map.spot_data(x, y - 1) != Map::WALL) {
			y--;
			if (x < 0) x = 0;
		}
		else if (ch == DOWN && map.spot_data(x, y + 1) != Map::WALL) {
			y++;
			if (x >= Map::WIDTH) x = Map::WIDTH - 1; //Clamp value
		}
		else if (ch == ERR) { //No keystroke
			; //Do nothing
		}
		clear();
		map.draw(x,y);
		mvprintw(Map::DISPLAY + 1, Map::DISPLAY + 1,"X: %i Y: %i\n",x,y);
		refresh();
		if (is_stairs(map.spot_data(x, y))) {
			map.init_map();
			start_pos(x, y, map);
		}
		usleep(5000);
	}
	clear();
	endwin(); // End curses mode
	system("clear");
}
