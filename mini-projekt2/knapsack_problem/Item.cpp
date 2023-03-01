#include "Item.h"
#include <stdexcept>

Item::Item(double value, double weight)
	: value(value), 
	weight(weight)
{
	if (weight <= 0 || value <= 0)
	{
		throw NegativeNumberException("incorrect values or weight, it cannot be less than zero");
	}
}

double Item::getValue() const
{
	return value;
}

double Item::getWeight() const 
{
	return weight;
}
