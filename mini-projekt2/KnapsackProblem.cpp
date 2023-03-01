#include "KnapsackProblem.h"
#include <iostream>
#include <fstream>

KnapsackProblem::KnapsackProblem(const string& sourcePath)
{
	ifstream file;
	file.open(sourcePath);
	if (!file)
	{
		throw FileNotFoundException("file not found");
	}

	double setCapacity;
	file >> setCapacity;
	if (setCapacity <= 0) throw NegativeNumberException("invalid capacity, it cannot be less than zero");
	capacity = setCapacity;

	while (!file.eof())
	{
		double value;
		double weight;
		file >> value;
		if (!file.eof()) {
			file >> weight;
			try
			{
				Item item(value, weight);
				addItem(item);
			}
			catch (NegativeNumberException& e)
			{
				throw e;
			}
		}
		else {
			throw IncompleteFileException("file is incorect");
		}
	}
	file.close();
}

int KnapsackProblem::getNumberOfItems() const
{
	return items.size();
}

double KnapsackProblem::evaluate(const vector<bool>& genotype) const
{
	double weight = 0;
	double value = 0;

	for (int i = 0; i < genotype.size(); i++)
	{
		if (genotype[i])
		{
			Item item = items[i];
			weight += item.getWeight();
			value += item.getValue();
		}
	}

	if (weight > capacity) value = 0;
	return value;
}

void KnapsackProblem::addItem(Item& item)
{
	items.push_back(item);
}