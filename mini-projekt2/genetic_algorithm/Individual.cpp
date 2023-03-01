#include "Individual.h"

Individual::Individual()
{
	genotype = vector<bool>();
	fitness = 0;
	computed = false;
}

Individual::Individual(int size)
{
	for (int j = 0; j < size; j++)
	{
		genotype.push_back(random.generateBool());
	}
	fitness = 0;
	computed = false;
}

Individual::Individual(std::vector<bool>& setGenotype)
{
	genotype = setGenotype; 
	fitness = 0;
	computed = false;
}

Individual::Individual(const Individual& other)
{
	for (int i = 0; i < other.genotype.size(); i++)
	{
		genotype.push_back(other.genotype[i]);
	}
	computed = other.computed;
	fitness = other.fitness;
}

double Individual::calculateFitness(const KnapsackProblem& knapsackProblem)
{
	if (!computed)
	{
		fitness = knapsackProblem.evaluate(genotype);
		computed = true;
	}
	return fitness;
}

double Individual::getFitness() const
{
	return fitness;
}

vector<bool> Individual::getGenotype() const
{
	return genotype;
}

void Individual::mutate(double mutationProb)
{
	for (int i = 0; i < genotype.size(); i++)
	{
		const double randomMutProb = random.generateRandom(0, 1000) / static_cast<double>(1000);
		if (randomMutProb <= mutationProb)
		{
			genotype[i] = !genotype[i];
		}
	}
}

std::vector<Individual> Individual::cross(const Individual& other)
{
	std::vector<bool> firstGenotype;
	std::vector<bool> secondGenotype;

	const int split = random.generateRandom(1, genotype.size() - 1);

	for (int i = 0; i < genotype.size(); i++)
	{
		if (i < split)
		{
			firstGenotype.push_back(genotype[i]);
			secondGenotype.push_back(other.genotype[i]);
		}
		else
		{
			firstGenotype.push_back(other.genotype[i]);
			secondGenotype.push_back(genotype[i]);
		}
	}

	return { firstGenotype, secondGenotype };
}
