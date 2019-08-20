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