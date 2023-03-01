#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(int popSize, double crossoverProb, double mutationProb)
	: popSize(popSize), 
	crossoverProb(crossoverProb),
	mutationProb(mutationProb)
{
	if (popSize <= 0)
	{
		throw NegativeNumberException("popSize cannot be less than zero");
	}
	if (crossoverProb > 1 || crossoverProb < 0 || mutationProb > 1 || mutationProb < 0)
	{
		throw InvalidProbabilityValueException("probability must be in range (0, 1)");
	}
	bestIndividual = Individual();
}

void GeneticAlgorithm::runAlgorithm(int stopParameter, const KnapsackProblem& knapsackProblem)
{
	if (stopParameter < 0) throw NegativeNumberException("number of iterations cannot be less than zero");

	generatePopulation(knapsackProblem.getNumberOfItems());
	calculateFitness(knapsackProblem);
	setBestIndividual();
	int i = 0;

	while (i < stopParameter)
	{
		iteration();
		calculateFitness(knapsackProblem);
		setBestIndividual();
		i++;
	}
}

Individual& GeneticAlgorithm::getBestIndividual()
{
	return bestIndividual;
}

void GeneticAlgorithm::setBestIndividual()
{
	for (int i = 0; i < population.size(); i++)
	{
		if (bestIndividual.getFitness() < population[i].getFitness())
		{
			bestIndividual = population[i];
		}
	}
}

void GeneticAlgorithm::generatePopulation(int numberOfItems)
{
	for (int i = 0; i < popSize; i++)
	{
		population.push_back(numberOfItems);
	}
}

void GeneticAlgorithm::calculateFitness(const KnapsackProblem& knapsackProblem)
{
	for (int i = 0; i < popSize; i++)
	{
		population[i].calculateFitness(knapsackProblem);
	}
}

void GeneticAlgorithm::iteration()
{
	vector<Individual> newPopulation;
	Individual firstChild;
	Individual secondChild;

	while (newPopulation.size() < popSize)
	{
		const int firstIndex = chooseParentIndex();
		const int secondIndex = chooseParentIndex();

		vector<Individual> children;
		children = crossover(firstIndex, secondIndex);

		mutation(children);

		newPopulation.push_back(children[0]);
		newPopulation.push_back(children[1]);
	}

	population.clear();
	population = newPopulation;
}

void GeneticAlgorithm::mutation(vector<Individual>& children)
{
	for (int i = 0; i < children.size(); i++) {
		children[i].mutate(mutationProb);
	}
}

vector<Individual> GeneticAlgorithm::crossover(int firstIndex, int secondIndex)
{
	const double randomCrossoverProb = random.generateRandom(0, 1000) / static_cast<double>(1000);

	if(randomCrossoverProb < crossoverProb)
	{
		return population[firstIndex].cross(population[secondIndex]);
	}
	else
	{	
		return { population[firstIndex], population[secondIndex] };
	}
}

int GeneticAlgorithm::chooseParentIndex()
{
	int firstIndex = random.generateRandom(0, popSize - 1);
	const int secondIndex = random.generateRandom(0, popSize - 1);

	if (population[firstIndex].getFitness() > population[secondIndex].getFitness())
	{
		return firstIndex;
	}
	return secondIndex;
}
