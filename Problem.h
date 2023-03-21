#pragma once
#include <iostream>
#include "SmartPtr.h"
#include <vector>

class Problem {
public:
	virtual double calculateFitness(const std::vector<int>& genotype) const = 0;
	int getGenotypeSize() const;
protected:
	int genotypeSize;
};