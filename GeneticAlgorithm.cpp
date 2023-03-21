#include "GeneticAlgorithm.h"
#include "GeneticAlgorithmValues.h"
#include "OutOfDomainException.h"
#include "GenotypeSizesDontMatchException.h"
#include "IndexOutOfBoundsException.h"
#include "ExceptionMessages.h"
using GA = GeneticAlgorithm;

GA::GeneticAlgorithm(const Problem& problem) :
	prob{ problem },
	popSize{ defaultPopulationSize },
	coChance{ defaultCrossoverChance },
	mutChance{ defaultMutationChance },
	noIter{ defaultNumberOfIterations },
	population{new vector<SmartPtr<Individual>>},
	newGeneration{new vector<SmartPtr<Individual>>},
	best{ new Individual(prob.getGenotypeSize()) }
{
	initRandomGenerators();
}

GA::GeneticAlgorithm(const Problem& problem, int populationSize, double crossoverChance, double mutationChance, int permittedIterations) :
	prob { problem },
	popSize { populationSize},
	coChance{ crossoverChance },
	mutChance{ mutationChance },
	noIter { permittedIterations },
	population{ new vector<SmartPtr<Individual>> },
	newGeneration{ new vector<SmartPtr<Individual>> },
	best{ new Individual(prob.getGenotypeSize()) }
{
	if (popSize < 2) throw OutOfDomainException(populationSizeOutOfDomainMessage);
	if (coChance < 0 || coChance > 1) throw OutOfDomainException(crossoverChanceOutOfDomainMessage);
	if (mutChance < 0 || mutChance > 1) throw OutOfDomainException(mutationChanceOutOfDomainMessage);
	if (noIter < 0) throw OutOfDomainException(iterationsOutOfDomainException);
	initRandomGenerators();
}

void GA::initRandomGenerators() {
	seed s;
	gen = Generator(s());
	randChance = DoubleRandom(0, 1);
	randIndex = IntRandom(0, popSize - 1);
	randSplitPoint = IntRandom(0, prob.getGenotypeSize() - 1);
}

GA::GeneticAlgorithm(const GA& other) : 
	prob{ other.prob },
	popSize{ other.popSize },
	coChance{ other.coChance },
	mutChance{ other.mutChance },
	noIter { other.noIter},
	population{ other.population },
	newGeneration{ other.newGeneration },
	best{ other.best }
{
	gen = other.gen;
	randChance = other.randChance;
	randIndex = other.randIndex;
	randSplitPoint = other.randSplitPoint;

}

GA::GeneticAlgorithm(GA&& other) :
	prob{ other.prob },
	popSize{ other.popSize },
	coChance{ other.coChance },
	mutChance{ other.mutChance },
	noIter{ other.noIter },
	best{ other.best }
{
	population = other.population;
	other.population = nullptr;

	newGeneration = other.newGeneration;
	other.newGeneration = nullptr;

	gen = std::move(other.gen);
	randChance = std::move(other.randChance);
	randIndex = std::move(other.randIndex);
	randSplitPoint = std::move(other.randSplitPoint);

}

GA::~GeneticAlgorithm() {
	delete population;
	delete newGeneration;
}

void GA::run() {
	populate();

	for (int i = 0; i < noIter; i++) {
		if (popSize % 2 != 0) {
			newGeneration->push_back(best);
		}
		
		while (newGeneration->size() < popSize) {
			add2ToNewGeneration();
		}

		for (int j = 0; j < newGeneration->size(); j++) {
			if (best->getFitness(prob) < newGeneration->at(j)->getFitness(prob)) {
				best = newGeneration->at(j);
			}
		}
		
		population->clear();
		population = newGeneration;
		newGeneration = new vector<SmartPtr<Individual>>;
	}
	population->clear();
}

Solution GA::getBestResult() const {
	return Solution(best->getGenotype(), best->getFitness(prob));
}

void GA::populate() {
	for (int i = 0; i < popSize; i++) {
		population->push_back(SmartPtr<Individual>(new Individual(prob.getGenotypeSize())));
	}
}

void GA::add2ToNewGeneration() {
	SmartPtr<Individual> parent1{ chooseParent() };
	SmartPtr<Individual> parent2{ chooseParent() };
	if (!tryCrossingOverAndMutating(parent1, parent2)) {
		newGeneration->push_back(tryMutating(parent1));
		newGeneration->push_back(tryMutating(parent2));
	}
}

SmartPtr<Individual> GA::tryMutating(SmartPtr<Individual> toMutate) {
	int i = 0;
	while (i < prob.getGenotypeSize()) {
		if (randChance(gen) < mutChance) {
			SmartPtr<Individual> copy{ new Individual{ *toMutate } };
			copy->mutate(i);
			
			while (i < prob.getGenotypeSize()) {
				if (randChance(gen) < mutChance) {
					copy->mutate(i);
				}
				i++;
			}
			return copy;
		}
		i++;
	}
	return toMutate;
}

SmartPtr<Individual> GA::chooseParent() {

	SmartPtr<Individual> contestant1{ population->at(randIndex(gen)) };
	SmartPtr<Individual> contestant2{ population->at(randIndex(gen)) };
	if (contestant1->getFitness(prob) > contestant2->getFitness(prob)) {
		return contestant1;
	}
	else return contestant2;
}

bool GA::tryCrossingOverAndMutating(SmartPtr<Individual>& parent1, SmartPtr<Individual>& parent2) {
	if (randChance(gen) < coChance) {
		int splitAt = randSplitPoint(gen);
		newGeneration->push_back(tryMutating(new Individual(*parent1, *parent2, splitAt)));
		newGeneration->push_back(tryMutating(new Individual(*parent2, *parent1, splitAt)));
		return true;
	}
	return false;
}



