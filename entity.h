#ifndef _entity
#define _entity

#include <string>

class Entity{
	protected:
		std::string name;

	public:
		Entity(std::string s);

		std::string getName();
};

#endif