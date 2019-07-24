#include <ncurses.h>

unsigned char again=1;

int key;

int main(){
  initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);

	while(again){
		switch(key=getch()){
			case KEY_F(2):
				again=0;
				break;
		}
	}

	endwin();

	return 0;
}