#include "game.h"

using namespace std;

Player* player;

void printS(string s){
	printw(s.c_str());
}

void onInit(){
	player = new Player(); 

	printS(player->getName());

	//refresh();
}

void onKey(int key){

}

void onUpdate(){
	
}

void onExit(){
	delete(player);
}