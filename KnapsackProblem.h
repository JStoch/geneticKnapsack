#pragma once
#include "Problem.h"
#include <vector>

class KnapsackProblem: public Problem {
public:
	KnapsackProblem() = delete;
	KnapsackProblem(std::string path);
	~KnapsackProblem();
	KnapsackProblem(const KnapsackProblem& other);
	KnapsackProblem(KnapsackProblem&& other);
	double calculateFitness(const std::vector<int>& genotype) const override;
	double getWeight(int index) const;
	double getValue(int index) const;
	KnapsackProblem& operator=(const KnapsackProblem& other);
	KnapsackProblem& operator=(KnapsackProblem&& other);
private:
	double capacity;
	std::vector<double> weightsOfItems;
	std::vector<double> valuesOfItems;
};