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

	public:
		Entity(){};

		Entity(std::string s);

		std::string getName();

		unsigned int getIni();
};

#endif