#pragma once
#include <vector>
#include <string>
#include "Item.h"
#include "FileNotFoundException.h"
#include "IncompleteFileException.h"

using namespace std;

class KnapsackProblem
{
public:
	KnapsackProblem(const string& sourcePath);
	~KnapsackProblem() = default;
	void addItem(Item& item);
	double evaluate(const vector<bool>& genotype) const;
	int getNumberOfItems() const;

private:
	double capacity;
	vector<Item> items;
};
