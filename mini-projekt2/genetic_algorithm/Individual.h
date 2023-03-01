#pragma once
#include <vector>
#include <iostream>
#include "KnapsackProblem.h"
#include "Random.h"
using namespace std;

class Individual
{
public:
	Individual();
	Individual(int size);
	Individual(vector<bool>& setGenotype);
	Individual(const Individual& other);
	~Individual() = default;
	double calculateFitness(const KnapsackProblem& knapsackProblem);
	double getFitness() const;
	vector<bool> getGenotype() const;
	void mutate(double mutationProb);
	vector<Individual> cross(const Individual& other);

private:
	Random random;
	double fitness;
	vector<bool> genotype;
	bool computed;
};
