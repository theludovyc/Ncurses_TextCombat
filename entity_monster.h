#ifndef _monster
#define _monster

#include "entity.h"

class Monster : public Entity{
	public:
		Monster(){};

		void init(int i);
};

#endif