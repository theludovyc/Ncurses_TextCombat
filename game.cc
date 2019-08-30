#include "game.h"
#include "entity_player.h"
#include "entity_monster.h"
#include "item_potion.h"
#include "item_armor.h"

#include <queue>
#include <array>

#define string_buffer_size 5

WINDOW *win_game;
WINDOW *win_help;

enum states{
	OPEN_DOOR,
	MONSTER_POP,
	CHECK_INI,
	MONSTER_ATTACK,
	PLAYER_ATTACK,
	NEW_TURN,
	PLAYER_DEATH,
	MONSTER_DEATH,
	TREASURE_0,
	TREASURE_1,
	TREASURE_2,
	LEAVE_ROOM,
	START
};

using namespace std;

queue<string> string_queue;
array<string, string_buffer_size> string_buffer;

Player* player;
Monster* monster;

unsigned int lvl = 0;

unsigned int state = START;

bool player_attack;
bool monster_attack;

bool player_key_isActive=false;
unsigned char player_key_max;
unsigned char player_key=0;

array<Item*, 2> items;

Item* item;

void printS(string s){
	printw(s.c_str());
}

void addLine(string s){
	int i=0;

	for(; i<string_buffer.size()-1; i++){
		string_buffer[i]=string_buffer[i+1];
	}

	string_buffer[i]=s;
}

void queue_addLine(string s){
	string_queue.push(s);
}

void addText(string s){
	string_buffer.back() += s;
}

void queue_addText(string s){
	string_queue.back() += s;
}

void queue_pop(){
	addLine(string_queue.front());
	string_queue.pop();
}

void printLine(string s){
	wprintw(win_game, (s+"\n").c_str());
}

void printBuffer(){
	wmove(win_game, 0, 0);

	for(string s:string_buffer){
		printLine(s);
	}
}

void refreshBuffer(){
	printBuffer();

	touchwin(win_game);
	wrefresh(win_game);
}

void openDoor(){
	addLine("--- "+player->getName()+" ouvre une porte("+to_string(lvl)+").");
}

void monsterPop(){
	monster->init(lvl);

	queue_addLine("Un "+monster->getName()+" apparait...");
}

void help_print(string s){
	wprintw(win_help, s.c_str());
	touchwin(win_help);
	wrefresh(win_help);
}

void help_erase(){
	werase(win_help);
	touchwin(win_help);
	wrefresh(win_help);
}

bool checkIni(){
	bool b=false;

	if (player->getIni() > monster->getIni() ){
		queue_addLine(player->getName());
		b=true;
	}else{
		queue_addLine(monster->getName());
	}

	queue_addText(" attaque en premier !");

	return b;
}

bool monsterAttack(){
	monster_attack=true;

	queue_addLine(monster->getName());

	if(monster->testAttack()){
		queue_addText(" attaque, ");

		if(player->testAttack()){
			queue_addText("mais " + player->getName() + " se défend !");
		}else{
			auto dam = monster->getDamage();

			queue_addText("et inflige " + to_string(dam) + " dégat(s)");

			if(player->removeLife(dam)){
				return true;
			}
		}
	}else{
		queue_addText(" rate son attaque.");
	}

	return false;
}

bool playerAttack(){
	player_attack=true;

	queue_addLine(player->getName());

	if(player_key!=2){
		if(player->testAttack()){
			auto dam = player->getDamage();

			if(player_key==1){
				dam*=2;
			}

			queue_addText(" inflige " + to_string(dam) + " dégat(s)");

			if(monster->removeLife(dam)){
				return true;
			}
		}else{
			queue_addText(" rate son attaque.");
		}
	}else{
		player->setArmorToMax();
		queue_addText(" prépare sa défense.");
	}

	return false;
}

void todo_newTurn(){
	player_attack=false;
	monster_attack=false;

	if(!checkIni() ){
		if(monsterAttack()){
			queue_addLine("PLAYER DEATH");
			return;
		}
	}

	state=PLAYER_ATTACK;
}

void todo_start(){
	lvl++;

	queue_addLine("--- "+player->getName()+" ouvre une porte("+to_string(lvl)+").");

	monsterPop();

	todo_newTurn();
}

void todo1(){
	switch(state){
		case PLAYER_ATTACK:
			help_erase();

			if(playerAttack() ){
				//MONSTER_DEATH
				queue_addLine(monster->getName() + " est mort.");
				queue_addLine(player->getName() + " a trouvé un trésor !");

				item=items[Helper::rand_between(0, items.size()-1)];

				queue_addLine("C'est "+item->getName(lvl, *player)+".");

				state=TREASURE_0;
			}else{
				if(monster_attack || !monsterAttack()){
					queue_addLine("- Nouveau tour");
					todo_newTurn();
				}else{
					queue_addLine("PLAYER DEATH");
				}
			}

			queue_pop();

			refreshBuffer();
			
			break;

		case TREASURE_0:
			if(player_key<player_key_max){
				help_erase();

				if(player_key==0){
					queue_addLine(player->getName()+" l'utilise.");
					item->use(player);
				}

				queue_addLine(player->getName()+" continue son chemin.");

				todo_start();

				queue_pop();

				refreshBuffer();
				break;
			}
			break;

		case PLAYER_DEATH:
			break;
	}
}

void help_todo(){
	switch(state){
		case PLAYER_ATTACK:
			help_print("a.Atk z.Atk++ e.Def");
			player_key=4;
			player_key_max=3;
			break;

		case TREASURE_0:
			help_print("a.Utiliser z.Laisser");
			player_key=4;
			player_key_max=2;
			break;
	}
}

void onInit(){
	Helper::seed("Bla");

	win_game=derwin(stdscr, string_buffer_size, COLS, 0, 0);
	
	win_help=derwin(stdscr, 2, COLS, string_buffer_size, 0);

	player = new Player(); 

	monster = new Monster();

	items[0] = new Potion();

	items[1] = new Armor();

	todo_start();

	queue_pop();

	refreshBuffer();

	wcursyncup(win_game);
}

void onKey(int key){
	if(!string_queue.empty()){
		if(key==' '){
			queue_pop();

			if(string_queue.empty()){
				help_todo();
			}

			refreshBuffer();		
		}
	}else{
		switch(key){
			case 'a':
				player_key=0;
				todo1();
				break;
			
			case 'z':
				player_key=1;
				todo1();
				break;

			case 'e':
				player_key=2;
				todo1();
				break;

			case 'r':
				player_key=3;
				todo1();
				break;

			default:
				break;
		}
	}
}

void onUpdate(){
}

void onExit(){
	delwin(win_game);
	delwin(win_help);

	delete(player);
	delete(monster);

	for(int i=0; i<items.size(); i++){
		delete(items[i]);
	}
}