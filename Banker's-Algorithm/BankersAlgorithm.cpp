// Tom Steinman
// CS431-0001 Introduction to Operating Systems
// HW#3 Programming Problem on Deadlocks

#include "BankersAlgorithm.h"


// Setter for ProcessesToDo
void Banker::setProcesses() {
    for (int i = 0; i < processes; i++) {
        ProcessesToDo.push_back(i);
    }
}


// Getter for ProcessesToDo
std::vector<int> Banker::getProcesses() {
    return ProcessesToDo;
}


// Setter for AvailResources; user inputs resources available by the system
void Banker::setAvailableResources() {
    AvailResources.resize(resources);

    bool inputSuccessful = false; // Used ChatGPT to fix infinite loop

    while (!inputSuccessful) {  // Continue until input is successful
        try {
            std::cout << "Enter the number of resources (" << resources << " total) available: ";
            for (int i = 0; i < resources; i++) { 
                int resourceInput;
                std::cin >> resourceInput;

                if (std::cin.fail()) {
                    throw std::invalid_argument("Invalid input. Please enter an integer.");
                }

                AvailResources[i] = resourceInput;  // Store the input in the AvailResources vector
            }

            inputSuccessful = true;  // Mark the input process as successful
        }

        // Catches any invalid input
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}


// Getter for AvailResources
std::vector<int> Banker::getAvailableResources() {
    return AvailResources;
}


// Calculates the needs of processes, creating need vector, used for reference https://www.geeksforgeeks.org/program-bankers-algorithm-set-1-safety-algorithm/
void Banker::calculateNeed(std::vector<std::vector<int>>& need, std::vector<std::vector<int>>& maxm,
                           std::vector<std::vector<int>>& allot) {
    // Creates the Need matrix
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            need[i][j] = maxm[i][j] - allot[i][j];
        }
    }
}


//  Getter for Need vector
std::vector<std::vector<int>> Banker::getNeedVector() {
    return need;
}


// Setter for maxm vector; sets maximum resources for each process
void Banker::setMaxmVector() {
    maxm.resize(processes, std::vector<int>(resources));

    bool inputSuccessful = false;

    while (!inputSuccessful) {  // Continue until input is successful
        try {
            for (int i = 0; i < processes; i++) {
                std::cout << "\nEnter the number of maximum resources for process " << i << " for " << resources << " total resources: ";
                for (int j = 0; j < resources; j++) {
                    int maxResourceInput;
                    std::cin >> maxResourceInput;

                    if (std::cin.fail()) {
                        throw std::invalid_argument("Invalid input. Please enter an integer.");
                    }

                    maxm[i][j] = maxResourceInput;  // Store the input in the maxm vector
                }
            }
            inputSuccessful = true;
        }
        // Catches any invalid input
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

// Getter for maxm vector
std::vector<std::vector<int>> Banker::getMaxmVector() {
    return maxm;
}

// Setter for allot vector; user inputs number of allotted resources for each process
void Banker::setAllotVector() {
    allot.resize(processes, std::vector<int>(resources));

    for (int i = 0; i < processes; i++) {
        while (true) {
            try {
                std::cout << "\nEnter the number of allotted resources for process " << i << ": ";
                for (int j = 0; j < resources; j++) {
                    int allottedResourceInput;
                    std::cin >> allottedResourceInput;

                    if (std::cin.fail()) {
                        throw std::invalid_argument("Invalid input. Please enter an integer.");
                    }

                    allot[i][j] = allottedResourceInput;  // Store the input in the allot vector
                }
                break;
            }
            // Catches any invalid input
            catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
}


// Getter for allot vector
std::vector<std::vector<int>> Banker::getAllotVector() {
    return allot;
}


// Function to find the system is in a safe state or not, used and edited code from https://www.geeksforgeeks.org/program-bankers-algorithm-set-1-safety-algorithm/
bool Banker::isSafe(std::vector<int> processes, std::vector<int> avail, std::vector<std::vector<int>> maxm,
    std::vector<std::vector<int>> allot)
{
    int P = processes.size(); // Number of processes
    int R = avail.size();     // Number of resources

    std::vector<std::vector<int>> need(P, std::vector<int>(R, 0));

    // Function to calculate the need matrix
    calculateNeed(need, maxm, allot);

    // Mark all processes as unfinished
    std::vector<bool> finish(P, false);

    // To store the safe sequence
    std::vector<int> safeSeq(P, -1);

    // Make a copy of available resources
    std::vector<int> work(avail);

    // While all processes are not finished
    // or the system is not in a safe state.
    int count = 0;
    while (count < P)
    {
        // Find a process that is not finished and
        // whose needs can be satisfied with the current
        // work[] resources.
        bool found = false;
        for (int i = 0; i < P; i++)
        {
            // First check if a process is finished,
            // if not, go to the next condition
            if (!finish[i])
            {
                // Check if for all resources of
                // the current process, need is less
                // than work
                bool canAllocate = true;
                for (int j = 0; j < R; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        canAllocate = false;
                        break;
                    }
                }

                // If all needs of process p are satisfied.
                if (canAllocate)
                {
                    // Add the allocated resources of
                    // the current process to the available/work
                    // resources, i.e., free the resources
                    for (int k = 0; k < R; k++)
                        work[k] += allot[i][k];

                    // Add this process to the safe sequence.
                    safeSeq[count++] = i;

                    // Mark this process as finished
                    finish[i] = true;

                    found = true;
                }
            }
        }

        // If we could not find the next process in the safe sequence.
        if (!found)
        {
            std::cout << "\nSystem is not in a safe state";
            return false;
        }
    }

    // If the system is in a safe state, then
    // the safe sequence will be as below
    std::cout << "System is in a safe state.\nSafe sequence is: ";
    for (int i = 0; i < P; i++)
        std::cout << safeSeq[i] << " ";

    return true;
}

void Banker::resizeVector(std::vector<std::vector<int>> vectorToSize) {
    vectorToSize.resize(processes, std::vector<int>(resources));
}