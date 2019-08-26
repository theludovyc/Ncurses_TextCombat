#include "item_armor.h"

using namespace std;

string Armor::getName(unsigned int i, Player p){
	armor=i;

	return ("une Armure("+to_string(int(i-p.getArmor()) )+")");
}

void Armor::use(Player* p){
	p->setArmorMax(armor);
}