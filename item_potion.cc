#include "item_potion.h"

using namespace std;

string Potion::getName(unsigned int i, Player p){
	life=i;

	return ("une Potion("+to_string(life)+")");
}

void Potion::use(Player* p){
	p->addLife(life);
}