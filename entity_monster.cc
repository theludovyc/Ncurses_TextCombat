#include "entity_monster.h"

void Monster::init(int i){
	if(i%10){
		this->name="Monstre";
	}else{
		this->name="Boss";
	}

	pvMax=i;
	pv=pvMax;
}