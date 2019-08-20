#include "entity_monster.h"
#include "helper.h"

void Monster::init(int i){
	if(i%10){
		this->name="Monstre";
		ini=Helper::rand_between(1, 10);
		cc=Helper::rand_between(25, 75);
		degMax=i+3;
		degMin=(i>3)?(i-3):1;
	}else{
		this->name="Boss";
		ini=10;
		cc=i;
		degMax=i+3;
		degMin=i;
	}

	pvMax=i;
	pv=pvMax;
}