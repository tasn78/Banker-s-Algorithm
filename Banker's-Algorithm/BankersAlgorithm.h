// Tom Steinman
// Banker's Algorithm
// CS431-0001

#ifndef BANKERSALGORITHM_H
#define BANKERSALGORITHM_H

#include <vector>
#include <iostream>
#include <stdexcept>

class Banker {
public:
	// Calculate needs of each process
	void calculateNeed(std::vector<std::vector<int>>& need, std::vector<std::vector<int>>& maxm,
						std::vector<std::vector<int>>& allot);

	// Determine if system is safe or not


	void setNeedVector();

	std::vector<std::vector<int>> getNeedVector();

	void setMaxmVector();

	std::vector<std::vector<int>> getMaxmVector();

	void setAllotVector();

	std::vector<std::vector<int>> getAllotVector();

private:
	int processes = 5;
	int resources = 3;
	std::vector<std::vector<int>> need;
	std::vector<std::vector<int>> maxm;
	std::vector<std::vector<int>> allot;

};



#endif // !BankersAlgorithm.h

