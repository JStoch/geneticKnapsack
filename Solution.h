#pragma once
#include <vector>
using namespace std;

class Solution {
public:
	Solution() = delete;
	Solution(const vector<int>& answ, double fitness);
	Solution(const Solution& other);
	Solution(Solution&& other);
	~Solution();
	vector<int>& getAnswer();
	vector<int> getAnswer() const;
	double getFitness() const;
	Solution& operator=(const Solution& other);
	Solution& operator=(Solution&& other);
private:
	vector<int> answer;
	double fitness;
};