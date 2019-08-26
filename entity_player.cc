#include "entity_player.h"

Player::Player():Entity("Héro"){
	pvMax=5;
	pv=pvMax;

	armorMax=1;
	armor=armorMax;

	ini=5;

	cc=50;

	damageMax=3;
	damageMin=1;
}