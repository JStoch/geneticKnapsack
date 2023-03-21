#include "Individual.h"
#include "GenotypeSizesDontMatchException.h"
#include "OutOfDomainException.h"
#include "ExceptionMessages.h"

#include <iostream>

Individual::Individual(int genSize)
{
	if (genotypeSize < 0) throw OutOfDomainException(genotypeSizeOutOfDomainMessage);
	genotypeSize = genSize;
	fitness = 0;
	fitnessUpToDate = false;

	generateGenotype();
}

Individual::Individual(const Individual& other)
{
	genotypeSize = other.genotypeSize;
	fitness = other.fitness;
	fitnessUpToDate = other.fitnessUpToDate;
	genotype = other.genotype;
}

Individual::Individual(Individual&& other)
{
	genotypeSize = other.genotypeSize;
	fitness = other.fitness;
	fitnessUpToDate = other.fitnessUpToDate;
	genotype = std::move(other.genotype);

}

Individual::Individual(const Individual& parent1, const Individual& parent2, int splitSpot)
{
	if (parent1.genotypeSize != parent2.genotypeSize) throw GenotypeSizesDontMatchException();
	if (parent1.genotypeSize <= splitSpot) throw OutOfDomainException(splitPointOutOfDomainException);
	genotypeSize = parent1.genotypeSize;

	for (int i = 0; i < splitSpot; i++) {
		genotype.push_back(parent1.genotype[i]);
	}

	for (int i = splitSpot; i < genotypeSize; i++) {
		genotype.push_back(parent2.genotype[i]);
	}

	fitness = 0;
	fitnessUpToDate = false;

}


Individual::~Individual() {
}

void Individual::mutate(int geneIndex) {
	if (genotype[geneIndex] == 0) {
		genotype[geneIndex] = 1;
	}
	else {
		genotype[geneIndex] = 0;
	}
	fitnessUpToDate = false;
}

double Individual::getFitness(const Problem& problem) {
	if (!fitnessUpToDate) {
		fitness = problem.calculateFitness(genotype);
		fitnessUpToDate = true;
	}

	return fitness;
}

std::vector<int>& Individual::getGenotype() {
	return genotype;
}

Individual& Individual::operator=(const Individual& other) {
	genotypeSize = other.genotypeSize;
	fitness = other.fitness;
	fitnessUpToDate = other.fitnessUpToDate;

	for (int i = 0; i < genotypeSize; i++) {
		genotype[i] = other.genotype[i];
	}

	return *this;
}

Individual& Individual::operator=(Individual&& other){
	genotypeSize = other.genotypeSize;
	fitness = other.fitness;
	fitnessUpToDate = other.fitnessUpToDate;

	genotype = move(other.genotype);

	return *this;
}


void Individual::generateGenotype() {
	IntRandom random = IntRandom(0, 1);
	std::random_device seed;
	Generator gen{ seed()};
	
	for (int i = 0; i < genotypeSize; i++) {
		genotype.push_back(random(gen));
	}
}