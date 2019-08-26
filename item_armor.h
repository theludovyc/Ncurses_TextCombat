#ifndef _h_armor
#define _h_armor

#include "item.h"

class Armor : public Item{
	unsigned int armor;

	public:
		Armor(){};

		std::string getName(unsigned int, Player);

		void use(Player*);
};

#endif