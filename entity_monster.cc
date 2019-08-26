#include "entity_monster.h"
#include "helper.h"

void Monster::init(int i){
	if(i%10){
		this->name="Monstre";
		armorMax=Helper::rand_between(i*0.25,i*0.75);
		armor=armorMax;
		ini=Helper::rand_between(1, 10);
		cc=Helper::rand_between(35, 75);
		damageMax=i+3;
		damageMin=(i>3)?(i-3):1;
	}else{
		this->name="Boss";
		armorMax=i*0.75;
		armor=armorMax;
		ini=10;
		cc=Helper::rand_between(i*0.75, i);
		damageMax=i+3;
		damageMin=i;
	}

	pvMax=i;
	pv=pvMax;
}