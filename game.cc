#include "game.h"
#include "entity_player.h"
#include "entity_monster.h"

enum states{
	OPEN_DOOR,
	POP_MONSTER
};

using namespace std;

Player* player;
Monster* monster;

unsigned int lvl = 1;

string string_buffer[5];

unsigned int state = OPEN_DOOR;

void printS(string s){
	printw(s.c_str());
}

void addLine(string s){
	for(int i=0; i<4; i++){
		string_buffer[i]=string_buffer[i+1];
	}

	string_buffer[4]=s;
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

	addLine("Un "+monster->getName()+" apparait !");
}

void todo(){
	switch(state){
		case OPEN_DOOR:
			openDoor();
			state=POP_MONSTER;
			break;

		case POP_MONSTER:
			popMonster();
			state=2;
			break;

		default:
			break;
	}

	clear();

	printBuffer();

	refresh();
}

void onInit(){
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