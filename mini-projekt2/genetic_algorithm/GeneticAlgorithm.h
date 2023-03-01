#pragma once
#include "Individual.h"
#include "InvalidProbabilityValueException.h"

class GeneticAlgorithm
{
public:
	GeneticAlgorithm(int popSize, double crossoverProb, double mutationProb);
	~GeneticAlgorithm() = default;
	void runAlgorithm(int stopParameter, const KnapsackProblem& knapsackProblem);
	Individual& getBestIndividual();

private:
	int popSize;
	double crossoverProb;
	double mutationProb;
	vector<Individual> population;
	Individual bestIndividual;
	Random random;

	void generatePopulation(int numberOfItems);
	void calculateFitness(const KnapsackProblem& knapsackProblem);
	void iteration();
	void setBestIndividual();
	void mutation(vector<Individual>& children);
	vector<Individual> crossover(int firstIndex, int secondIndex);
	int chooseParentIndex();
};
