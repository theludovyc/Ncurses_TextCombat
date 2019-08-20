#include "entity.h"

#include "helper.h"

using namespace std;

//Entity::Entity(){
//}

Entity::Entity(std::string s){
	name=s;
}

string Entity::getName(){
	return name+"("+to_string(pv)+")";
}

unsigned int Entity::getIni(){
	return ini;
}

bool Entity::testAttack(){
	if(Helper::rand_between(1, 100) <= cc){
		return true;
	}
	return false;
}

unsigned int Entity::getDamage(){
	return Helper::rand_between(degMin, degMax);
}

bool Entity::removeLife(unsigned int i){
	if(i>=pv){
		return true;
	}
	pv-=i;
	return false;
}