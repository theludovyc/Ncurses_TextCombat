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
	return Helper::rand_between(damageMin, damageMax);
}

bool Entity::removeLife(unsigned int i){
	if(i>(armor+pv) ){
		pv=0;
		armor=0;
		return true;
	}else if(armor>i){
		armor-=i;
		return false;
	}else if(armor>0){
		armor=0;
		i-=armor;
		if(pv>i){
			pv-=i;
			return false;
		}
		pv=0;
		return true;
	}else if(pv>i){
		pv-=i;
		return false;
	}else{
		pv=0;
		return true;
	}
	return false;
}

void Entity::addLife(unsigned int i){
	if(i>=(pvMax-pv)){
		pv=pvMax;
		return;
	}
	pv+=i;
}

void Entity::setArmorToMax(){
	armor=armorMax;
}