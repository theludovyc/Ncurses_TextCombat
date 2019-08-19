#include "game.h"
#include "entity_player.h"
#include "entity_monster.h"

#include <array>
#include <string>

#define string_buffer_size 5

enum states{
	OPEN_DOOR,
	POP_MONSTER,
	CHECK_INI
};

using namespace std;

Player* player;
Monster* monster;

unsigned int lvl = 1;

array<string, string_buffer_size> string_buffer;

unsigned int state = OPEN_DOOR;

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
	string_buffer[string_buffer.size()-1]+=s;
}

void printLine(string s){
	printw((s+"\n").c_str());
}

void printBuffer(){
	move(1,1);

	for(string s:string_buffer){
		printLine(s);
	}
}

void openDoor(){
	addLine("--- "+player->getName()+" ouvre une porte("+to_string(lvl)+").");
}


void popMonster(){
	monster->init(lvl);

	addLine("Un "+monster->getName()+" apparait...");
}

void checkIni(){
	if (player->getIni() > monster->getIni() ){
		addLine(player->getName());
	}else{
		addLine(monster->getName());
	}

	addText(" attaque en premier !");
}

void todo(){
	switch(state){
		case OPEN_DOOR:
			openDoor();
			state=POP_MONSTER;
			break;

		case POP_MONSTER:
			popMonster();
			state=CHECK_INI;
			break;

		case CHECK_INI:
			checkIni();
			state++;
			break;

		default:
			goto end;
			break;
	}

	clear();

	printBuffer();

	refresh();

	end:
	return;
}

void onInit(){
	Helper::seed("Bla");

	player = new Player(); 

	monster = new Monster();

	todo();
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
	delete(player);
	delete(monster);
}