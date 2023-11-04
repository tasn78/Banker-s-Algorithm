# Banker-s-Algorithm
 Implementation example of Banker's Algorithm

Process count and resource count can be updated in BankersAlgorithm.h under:

private:
	// Processes amount can be changed
	int processes = 5;
	// Resources amount can be changed
	int resources = 3;

Default amounts are 5 processes and 3 resources.

1) Enter number of available resources (3 total by default)
2) Enter number of maximum resources for each process (3 for each of the 5 processes by default)
3) Enter number of resources already allotted to each process (3 resources, 5 processes by default)
4) Algorithm will determine if system is in a safe state or not. If safe, prints process completion order.
