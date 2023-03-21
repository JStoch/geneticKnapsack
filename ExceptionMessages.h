#pragma once
#include <string>

const std::string defaultInvalidPathMessage = "Can't open file at given path";

const std::string defaultGenotypeSizesDontMatchMessage = "Individuals have different genotype sizes - can't produce a child";

const std::string defaultOutOfDomainMessage = "Argument out of permitted domain";
const std::string weightOutOfDomainMessage = "Weight can't be a number less than or equal to 0";
const std::string valueOutOfDomainMessage = "Value can't be a negative number";
const std::string capacityOutOfDomainMessage = "Capacity can't be a number less than or equal to 0";
const std::string genotypeSizeOutOfDomainMessage = "Genotype size 0 - there are no items in the presented problem";
const std::string populationSizeOutOfDomainMessage = "Population can't be a number below 2";
const std::string crossoverChanceOutOfDomainMessage = "Crossover chance can't be less than 0 or more than 1";
const std::string mutationChanceOutOfDomainMessage = "Mutation chance can't be less than 0 or more than 1";
const std::string splitPointOutOfDomainException = "Split spot for making a child is greater than genotype size";
const std::string iterationsOutOfDomainException = "Number or iterations can't be a negative number";

const std::string defaultUnexpectedArgumentMessage = "Unexpected argument found in file";
const std::string unexpectedArgumentWithPlaceMessage = "Unexpected argument found in file at: ";

const std::string defaultIndexOutOfBoundsMessage = "Index out of bounds";