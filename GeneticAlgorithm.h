#pragma once
#include "Problem.h"
#include "Individual.h"
#include "Solution.h"
#include <iostream>
#include <vector>
#include <random>
using DoubleRandom = std::uniform_real_distribution<double>;
using IntRandom = std::uniform_int_distribution<int>;
using Generator = std::mt19937;
using seed = std::random_device;

class GeneticAlgorithm {
public:
	GeneticAlgorithm() = delete;
	GeneticAlgorithm(const Problem& problem);
	GeneticAlgorithm(const Problem& problem, int populationSize, double crossoverChance, double mutationChance, int permittedIterations);
	GeneticAlgorithm(const GeneticAlgorithm& other);
	GeneticAlgorithm(GeneticAlgorithm&& other);
	~GeneticAlgorithm();
	void run();
	Solution getBestResult() const;
	GeneticAlgorithm& operator=(const GeneticAlgorithm& other) = delete;
	GeneticAlgorithm& operator=(GeneticAlgorithm&& other) = delete;
private:
	void initRandomGenerators();
	void populate();
	void add2ToNewGeneration();
	SmartPtr<Individual> tryMutating(SmartPtr<Individual> toMutate);
	SmartPtr<Individual> chooseParent();
	bool tryCrossingOverAndMutating(SmartPtr<Individual>& parent1, SmartPtr<Individual>& parent2);
	const Problem& prob;
	const int popSize;
	const double coChance;
	const double mutChance;
	const int noIter;
	SmartPtr<Individual> best;
	std::vector<SmartPtr<Individual>>* population;
	std::vector<SmartPtr<Individual>>* newGeneration;
	Generator gen;
	DoubleRandom randChance;
	IntRandom randSplitPoint;
	IntRandom randIndex;
};