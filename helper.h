#ifndef _helper
#define _helper

#include <random>
#include <string>

class Helper{
	static std::default_random_engine generator;

	public:
		static void seed(std::string s);
		static int rand_between(int a, int b);
};

#endif