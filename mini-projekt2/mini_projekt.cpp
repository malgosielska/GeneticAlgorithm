#include <iostream>
#include "GeneticAlgorithm.h"
#include "Random.h"


void test1()
{
	try
	{
		KnapsackProblem knap("test1.txt");
		GeneticAlgorithm ag (10, 0.5, 0.2);

		ag.runAlgorithm(100, knap);
		vector<bool> genotype = ag.getBestIndividual().getGenotype();
		for (int i = 0; i < genotype.size(); i++) {
			cout << genotype[i] << " ";
		}
		cout << endl;
		cout << ag.getBestIndividual().getFitness() << endl;

	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}

void test2()
{
	try
	{
		KnapsackProblem knap("test2.txt");
		GeneticAlgorithm ag(100, 0.5, 0.2);

		ag.runAlgorithm(100, knap);
		vector<bool> genotype = ag.getBestIndividual().getGenotype();
		for (int i = 0; i < genotype.size(); i++) {
			cout << genotype[i] << " ";
		}
		cout << endl;
		cout << ag.getBestIndividual().getFitness() << endl;

	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}

void test3()
{
	try
	{
		KnapsackProblem knap("test3.txt");
		GeneticAlgorithm ag(10, 0.5, 0.2);

		ag.runAlgorithm(100, knap);
		vector<bool> genotype = ag.getBestIndividual().getGenotype();
		for (int i = 0; i < genotype.size(); i++) {
			cout << genotype[i] << " ";
		}
		cout << endl;
		cout << ag.getBestIndividual().getFitness() << endl;

	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}

void test4()
{
	try
	{
		KnapsackProblem knap("test4.txt");
		GeneticAlgorithm ag(10, 0.5, 0.2);

		ag.runAlgorithm(100, knap);
		vector<bool> genotype = ag.getBestIndividual().getGenotype();
		for (int i = 0; i < genotype.size(); i++) {
			cout << genotype[i] << " ";
		}
		cout << endl;
		cout << ag.getBestIndividual().getFitness() << endl;

	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}

// file not found exception
void test5()
{
	try
	{
		KnapsackProblem knap("file15.txt");
		GeneticAlgorithm ag(10, 0.5, 0.2);

		ag.runAlgorithm(100, knap);
		vector<bool> genotype = ag.getBestIndividual().getGenotype();
		for (int i = 0; i < genotype.size(); i++) {
			cout << genotype[i] << " ";
		}
		cout << endl;
		cout << ag.getBestIndividual().getFitness() << endl;

	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}

//invalid probalility value
void test6()
{
	try
	{
		KnapsackProblem knap("test4.txt");
		GeneticAlgorithm ag(10, 2.5, -0.2);

		ag.runAlgorithm(100, knap);
		vector<bool> genotype = ag.getBestIndividual().getGenotype();
		for (int i = 0; i < genotype.size(); i++) {
			cout << genotype[i] << " ";
		}
		cout << endl;
		cout << ag.getBestIndividual().getFitness() << endl;

	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}

// negative number expcetion
void test7()
{
	try
	{
		KnapsackProblem knap("test7.txt");
		GeneticAlgorithm ag(10, 0.5, 0.2);

		ag.runAlgorithm(1000, knap);
		vector<bool> genotype = ag.getBestIndividual().getGenotype();
		for (int i = 0; i < genotype.size(); i++) {
			cout << genotype[i] << " ";
		}
		cout << endl;
		cout << ag.getBestIndividual().getFitness() << endl;

	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}

int main()
{
	std::cout << "Hello World!\n";

	test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	
	return 0;
}
