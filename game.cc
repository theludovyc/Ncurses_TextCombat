#include "game.h"
#include "entity_player.h"
#include "entity_monster.h"

using namespace std;

Player* player;
Monster* monster;

unsigned int lvl = 1;

void printS(string s){
	printw(s.c_str());
}

void addLine(string s){
	printw((s+"\n").c_str());
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
	popMonster();

	//refresh();
}

void onKey(int key){

}

void onUpdate(){
	
}

void onExit(){
	delete(player);
	delete(monster);
}