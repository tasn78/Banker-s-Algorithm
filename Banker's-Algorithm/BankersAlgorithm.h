// Tom Steinman
// Banker's Algorithm
// CS431-0001

#ifndef BANKERSALGORITHM_H
#define BANKERSALGORITHM_H

#include <vector>
#include <iostream>
#include <stdexcept>


// Code derived from https://www.geeksforgeeks.org/program-bankers-algorithm-set-1-safety-algorithm/
class Banker {
public:

	Banker() {};
	~Banker() {};

	// Setter and getter for ProcessesToDo vector
	void setProcesses();
	std::vector<int> getProcesses();

	// Setter and getter for AvailResources vector; resources available to processes
	void setAvailableResources();
	std::vector<int> getAvailableResources();

	// Getter for Need vector
	std::vector<std::vector<int>> getNeedVector();

	// Setter and getter for maxm vector (max resources available)
	void setMaxmVector();
	std::vector<std::vector<int>> getMaxmVector();

	//  Setter and getter for allot vector, resources allocated to processes vector
	void setAllotVector();
	std::vector<std::vector<int>> getAllotVector();

	// Calculate needs of each process
	void calculateNeed(std::vector<std::vector<int>>& need, std::vector<std::vector<int>>& maxm,
						std::vector<std::vector<int>>& allot);

	// Determine if system is safe or not
	bool isSafe(std::vector<int> processes, std::vector<int> avail, std::vector<std::vector<int>> maxm,
				std::vector<std::vector<int>> allot);

	// Resizes vector of vectors
	void resizeVector(std::vector<std::vector<int>>);

private:
	// Processes amount can be changed
	int processes = 5;
	// Resources amount can be changed
	int resources = 3;
	std::vector<std::vector<int>> need;
	std::vector<std::vector<int>> maxm;
	std::vector<std::vector<int>> allot;
	std::vector<int> ProcessesToDo;
	std::vector<int> AvailResources;
};



#endif // !BankersAlgorithm.h

