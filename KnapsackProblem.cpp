#include "KnapsackProblem.h"
#include "OutOfDomainException.h"
#include "InvalidPathException.h"
#include "UnexpectedArgumentException.h"
#include "IndexOutOfBoundsException.h"
#include "ExceptionMessages.h"
#include <fstream>
#include <sstream>
using namespace std;

KnapsackProblem::KnapsackProblem(string path)
{
	ifstream fileReader;
	fileReader.open(path);

	if (!fileReader) {
		fileReader.close();
		throw InvalidPathException();
	}
	
	int lineNumber = 0;
	int wordNumber = 0;

	if (!(fileReader >> capacity)) {
		fileReader.close();
		throw UnexpectedArgumentException(lineNumber, wordNumber);
	}

	if(capacity <= 0) throw OutOfDomainException(capacityOutOfDomainMessage);
	/*
	lineNumber++;
	if (!(fileReader >> genotypeSize)) {
		fileReader.close();
		throw UnexpectedArgumentException(lineNumber, wordNumber);
	}
	

	if (genotypeSize <= 0) throw OutOfDomainException(genotypeSizeOutOfDomainMessage);
	*/

	std::string line;
	getline(fileReader, line);
	while (!fileReader.eof()) {
		wordNumber = 0;

		getline(fileReader, line);
		lineNumber++;

		istringstream stringReader(line);
		double weight;
		if (!(stringReader >> weight)) {
			fileReader.close();
			throw UnexpectedArgumentException(lineNumber, wordNumber);
		}
		wordNumber++;

		if (weight <= 0) {
			fileReader.close();
			throw OutOfDomainException(weightOutOfDomainMessage);
		}
		weightsOfItems.push_back(weight);

		double value;
		if (!(stringReader >> value)) {
			fileReader.close();
			throw UnexpectedArgumentException(lineNumber, wordNumber);
		}
		wordNumber++;

		if (value < 0) {
			fileReader.close();
			throw OutOfDomainException(valueOutOfDomainMessage);
		}
		valuesOfItems.push_back(value);

		if (!stringReader.eof()) {
			fileReader.close();
			throw UnexpectedArgumentException(lineNumber, wordNumber);
		}
		
	}

	genotypeSize = weightsOfItems.size();
	if (genotypeSize == 0) throw OutOfDomainException(genotypeSizeOutOfDomainMessage);
}

KnapsackProblem::KnapsackProblem(const KnapsackProblem& other) {
	capacity = other.capacity;
	genotypeSize = other.genotypeSize;
	weightsOfItems = other.weightsOfItems;
	valuesOfItems = other.valuesOfItems;
}

KnapsackProblem::KnapsackProblem(KnapsackProblem&& other) {
	capacity = other.capacity;
	genotypeSize = other.genotypeSize;
	weightsOfItems = std::move(other.weightsOfItems);
	valuesOfItems = std::move(other.valuesOfItems);
}

KnapsackProblem::~KnapsackProblem() {}


double KnapsackProblem::calculateFitness(const vector<int>& genotype) const {
	double weightSum = 0;
	double valueSum = 0;
	bool endofGenotype = false;
	bool aboveCapacity = false;
	int i = 0;
	while(!endofGenotype && !aboveCapacity) {
		if (genotype[i] == 1) {
			weightSum += weightsOfItems[i];
			valueSum += valuesOfItems[i];
		}
		i++;
		if (i >= genotype.size()) {
			endofGenotype = true;
		}
		if (weightSum > capacity) {
			aboveCapacity = true;
			valueSum = 0;
		}
	}

	return valueSum;
}

double KnapsackProblem::getWeight(int index) const {
	if (index < 0 || index >= weightsOfItems.size()) throw IndexOutOfBoundsException();
	return weightsOfItems[index];
}

double KnapsackProblem::getValue(int index) const {
	if (index < 0 || index >= weightsOfItems.size()) throw IndexOutOfBoundsException();
	return valuesOfItems[index];
}

KnapsackProblem& KnapsackProblem::operator=(const KnapsackProblem& other) {
	capacity = other.capacity;
	Problem::genotypeSize = other.genotypeSize;
	weightsOfItems = other.weightsOfItems;
	valuesOfItems = other.valuesOfItems;
	return *this;
}

KnapsackProblem& KnapsackProblem::operator=(KnapsackProblem&& other) {
	capacity = other.capacity;
	Problem::genotypeSize = other.genotypeSize;
	weightsOfItems = move(other.weightsOfItems);
	valuesOfItems = move(other.valuesOfItems);
	return *this;
}