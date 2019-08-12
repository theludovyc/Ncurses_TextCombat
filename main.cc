#include <ncurses.h>
#include <string>

#include "game.cc"

unsigned char again=1;

int key;

int main(){
  initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);

	onInit();

	while(again){
		switch(key=getch()){
			case KEY_F(2):
				again=0;
				break;
			default:
				onKey(key);
		}

		onUpdate();
	}

	onExit();

	endwin();

	return 0;
}