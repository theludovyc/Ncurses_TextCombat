#include "item_armor.h"

using namespace std;

string Armor::getName(unsigned int i, const Player& p){
	armor=i;

	//int(i-p.getArmor()) 

	return ("une Armure("+to_string(i)+" / "+ to_string(p.getArmorMax() ) +")");
}

void Armor::use(Player* p){
	p->setArmorMax(armor);
}