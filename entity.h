#ifndef _entity
#define _entity

#include <string>

class Entity{
	protected:
		std::string name;

		int pv;
		int pvMax;

	public:
		Entity(){};

		Entity(std::string s);

		std::string getName();
};

#endif