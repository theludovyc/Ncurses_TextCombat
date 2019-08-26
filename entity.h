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
		unsigned int damageMin;
		unsigned int damageMax;

		unsigned int armor;
		unsigned int armorMax;

	public:
		Entity(){};

		Entity(std::string s);

		std::string getName();

		unsigned int getIni();

		bool testAttack();

		unsigned int getDamage();

		bool removeLife(unsigned int i);

		void addLife(unsigned int i);

		unsigned int getArmor();

		void setArmorMax(unsigned int);

		void setArmorToMax();
};

#endif