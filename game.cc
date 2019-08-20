#include "game.h"
#include "entity_player.h"
#include "entity_monster.h"

#include <array>
#include <string>

#define string_buffer_size 5

WINDOW *win_game;
WINDOW *win_help;

enum states{
	OPEN_DOOR,
	MONSTER_POP,
	CHECK_INI,
	MONSTER_ATTACK,
	PLAYER_ATTACK,
	NEW_TURN
};

using namespace std;

Player* player;
Monster* monster;

unsigned int lvl = 1;

array<string, string_buffer_size> string_buffer;

unsigned int state = OPEN_DOOR;

bool player_attack;
bool monster_attack;

void printS(string s){
	printw(s.c_str());
}

void addLine(string s){
	int i=0;

	for(; i<string_buffer.size()-1; i++){
		string_buffer[i]=string_buffer[i+1];
	}

	string_buffer[i]=s;
}

void addText(string s){
	string_buffer.back() += s;
}

void printLine(string s){
	wprintw(win_game, (s+"\n").c_str());
}

void printBuffer(){
	wmove(win_game, 0, 0);

	for(string s:string_buffer){
		printLine(s);
	}
}

void openDoor(){
	addLine("--- "+player->getName()+" ouvre une porte("+to_string(lvl)+").");
}


void monsterPop(){
	monster->init(lvl);

	addLine("Un "+monster->getName()+" apparait...");
}

void checkIni(){
	player_attack=false;
	monster_attack=false;

	if (player->getIni() > monster->getIni() ){
		addLine(player->getName());
		state=PLAYER_ATTACK;
	}else{
		addLine(monster->getName());
		state=MONSTER_ATTACK;
	}

	addText(" attaque en premier !");
}

void monsterAttack(){
	monster_attack=true;

	addLine(monster->getName());

	if(monster->testAttack()){
		addText(" attaque.");
	}else{
		addText(" rate son attaque.");
	}

	if(!player_attack){
		state=PLAYER_ATTACK;
		return;
	}
	state=NEW_TURN;
}

void playerAttack(){
	player_attack=true;

	addLine(player->getName());

	if(player->testAttack()){
		addText(" attaque.");
	}else{
		addText(" rate son attaque.");
	}

	if(!monster_attack){
		state=MONSTER_ATTACK;
		return;
	}
	state=NEW_TURN;
}

void todo(){
	switch(state){
		case OPEN_DOOR:
			openDoor();
			state=MONSTER_POP;
			break;

		case MONSTER_POP:
			monsterPop();
			state=CHECK_INI;
			break;

		case CHECK_INI:
			checkIni();
			break;

		case MONSTER_ATTACK:
			monsterAttack();
			break;

		case PLAYER_ATTACK:
			playerAttack();
			break;

		case NEW_TURN:
			addLine("- Nouveau tour");
			state=CHECK_INI;
			break;

		default:
			goto end;
			break;
	}

	//werase(win_game);

	printBuffer();

	touchwin(win_game);
	wrefresh(win_game);

	end:
	return;
}

void onInit(){
	Helper::seed("Bla");

	win_game=derwin(stdscr, string_buffer_size, COLS, 0, 0);
	
	win_help=derwin(stdscr, 2, COLS, string_buffer_size, 0);

	player = new Player(); 

	monster = new Monster();

	todo();

	wcursyncup(win_game);
}

void onKey(int key){
	switch(key){
		case ' ':
			todo();
	}
}

void onUpdate(){
}

void onExit(){
	delwin(win_game);
	delwin(win_help);

	delete(player);
	delete(monster);
}