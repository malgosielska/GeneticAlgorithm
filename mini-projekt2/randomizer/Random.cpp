#include "Random.h"

Random::Random()
	: gen(std::random_device{}()) {
}

int Random::generateRandom(int start, int end)
{
	std::uniform_int_distribution<> distrib(start, end);
	return distrib(gen);
}

bool Random::generateBool()
{
	std::uniform_int_distribution<> distrib(0, 1);
	if (distrib(gen) == 1) return true;
	return false;
}
