#include "game.h"
#include "entity_player.h"
#include "entity_monster.h"

using namespace std;

Player* player;
Monster* monster;

unsigned int lvl = 1;

string string_buffer[5];

unsigned int state = 1;

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
	/*if(lvl%10==0):
		mob.initBoss(lvl)
	else:
		mob.initMonster(lvl)*/

	addLine("Un "+monster->getName()+" apparait !");
}

void onInit(){
	player = new Player(); 

	monster = new Monster();

	openDoor();

	printBuffer();
}

void todo(){
	switch(state){
		case 0:
			openDoor();
			state=1;
			break;

		case 1:
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