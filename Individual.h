#pragma once
#include "Problem.h"
#include "SmartPtr.h"
#include <vector>
#include <random>
using IntRandom = std::uniform_int_distribution<int>;
using Generator = std::mt19937;

class Individual {
public:
	Individual() = delete;
	Individual(int genSize);
	Individual(const Individual& parent1, const Individual& parent2, int splitPoint);
	Individual(const Individual& other);
	Individual(Individual&& other);
	~Individual();
	void mutate(int geneIndex);
	double getFitness(const Problem& problem);
	std::vector<int>& getGenotype();
	Individual& operator=(const Individual& other);
	Individual& operator=(Individual&& other);
private:
	std::vector<int> genotype;
	double fitness;
	int genotypeSize;
	bool fitnessUpToDate;
	void generateGenotype();
};