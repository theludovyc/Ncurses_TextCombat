#ifndef _h_item
#define _h_item

#include <string>

#include "entity_player.h"

class Item{
	protected:
		std::string name;

	public:
		virtual std::string getName(unsigned int i, const Player&) =0;

		virtual void use(Player*) =0;
};

#endif