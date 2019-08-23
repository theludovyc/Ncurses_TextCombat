#ifndef _h_potion
#define _h_potion

#include "item.h"

class Potion : public Item{
	unsigned int life;

	public:
		Potion();

		std::string getName(unsigned int, Player);

		void use(Player*);
};

#endif