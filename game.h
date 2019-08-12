#ifndef _game
#define _game

#include <ncurses.h>
#include "entity_player.h"

void onInit();

void onKey(int key);

void onUpdate();

void onExit();

#endif