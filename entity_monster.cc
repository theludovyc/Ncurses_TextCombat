#include "entity_monster.h"
#include "helper.h"

void Monster::init(int i){
	if(i%10){
		this->name="Monstre";
		ini=Helper::rand_between(1, 10);
		cc=Helper::rand_between(25, 75);
	}else{
		this->name="Boss";
		ini=10;
		cc=i;
	}

	pvMax=i;
	pv=pvMax;
}