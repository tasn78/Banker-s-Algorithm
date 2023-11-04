// Tom Steinman
// CS431-0001 Introduction to Operating Systems
// HW#3 Programming Problem on Deadlocks

#include "BankersAlgorithm.h"

int main() {
	Banker test;
	test.setProcesses();		  // Creates vector ProcessesToDo based on int processes
	test.setAvailableResources(); // User designates available resources - vecto AvailResources
	test.setMaxmVector();		  // User designates maximum resources
	test.setAllotVector();		  // User designates allocated resources

    std::vector<std::vector<int>> needMatrix = test.getNeedVector(); // Creates process need vector

    // Check if the system is in a safe state
    bool isSafe = test.isSafe(test.getProcesses(), test.getAvailableResources(), test.getMaxmVector(), test.getAllotVector()); // Prints process order if safe


    return 0;
}