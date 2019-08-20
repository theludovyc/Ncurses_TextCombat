#include "entity_player.h"

Player::Player():Entity("Héro"){
	pvMax=5;
	pv=pvMax;

	ini=5;

	cc=50;

	degMax=3;
	degMin=1;
}