#include "entity.h"

using namespace std;

Entity* entity;

void printS(string s){
	printw(s.c_str());
}

void onInit(){
	entity = new Entity("Joel"); 

	printS(entity->getName()+"bubule");

	//refresh();
}

void onKey(int key){

}

void onUpdate(){
	
}

void onExit(){
	delete(entity);
}