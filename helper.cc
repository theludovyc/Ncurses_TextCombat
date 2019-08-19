#include "helper.h"

#include <functional>

using namespace std;

default_random_engine Helper::generator;

void Helper::seed(string s){
	hash<string> str_hash;
	generator.seed(str_hash(s));
}

int Helper::rand_between(int a, int b){
	uniform_int_distribution<int> distribution(a, b);
	return distribution(generator);
}