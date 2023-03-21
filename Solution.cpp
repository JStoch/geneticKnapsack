#include "Solution.h"

Solution::Solution(const std::vector<int>& ans, double fit) {
	fitness = fit;
	answer = ans;
}

Solution::Solution(const Solution& other) {
	fitness = other.fitness;
	answer = other.answer;
}

Solution::Solution(Solution&& other) {
	fitness = other.fitness;
	answer = move(other.answer);
}

Solution::~Solution() {}

vector<int>& Solution::getAnswer() {
	return answer;
}

vector<int> Solution::getAnswer() const {
	return answer;
}

double Solution::getFitness() const {
	return fitness;
}

Solution& Solution::operator=(const Solution& other) {
	fitness = other.fitness;
	answer = other.answer;
	return *this;
}

Solution& Solution::operator=(Solution&& other) {
	fitness = other.fitness;
	answer = move(other.answer);
	return *this;
}

