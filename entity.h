#ifndef _entity
#define _entity

#include <string>

class Entity{
	std::string name;

	public:
		Entity();
		Entity(std::string s);

		std::string getName();
};

#endif