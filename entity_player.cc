#include "entity_player.h"

Player::Player():Entity("Héro"){
	pvMax=5;
	pv=pvMax;

	armorMax=5;
	armor=armorMax;

	ini=5;

	cc=50;

	degMax=3;
	degMin=1;
}