#pragma once
#include "NegativeNumberException.h"

class Item
{
public:
	Item(double value, double weight);
	~Item() = default;
	double getValue() const;
	double getWeight() const;

private:
	double value;
	double weight;
};
