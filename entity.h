#ifndef _entity
#define _entity

#include <string>

class Entity{
	protected:
		std::string name;

		unsigned int pv;
		unsigned int pvMax;

		//initiative
		unsigned int ini;

		//capacite de combat
		unsigned int cc;

		//degat
		unsigned int degMin;
		unsigned int degMax;

	public:
		Entity(){};

		Entity(std::string s);

		std::string getName();

		unsigned int getIni();

		bool testAttack();

		unsigned int getDamage();

		bool removeLife(unsigned int i);
};

#endif