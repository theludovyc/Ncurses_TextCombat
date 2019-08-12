#include "entity.h"

using namespace std;

Entity::Entity(){
}

Entity::Entity(std::string s){
	this->name=s;
}

string Entity::getName(){
	return this->name;
}