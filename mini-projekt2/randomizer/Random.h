#pragma once
#include <random>
#include <iostream>

class Random
{
public:
	Random();
	int generateRandom(int start, int end);
	bool generateBool();
private:
	std::mt19937 gen;
};
