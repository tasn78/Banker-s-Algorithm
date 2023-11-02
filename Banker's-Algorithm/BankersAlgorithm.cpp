#include "BankersAlgorithm.h"


// Calculates the needs of processes, creating need vector
void Banker::calculateNeed(std::vector<std::vector<int>>& need, std::vector<std::vector<int>>& maxm,
                           std::vector<std::vector<int>>& allot) {
    // Calculate the Need matrix
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            need[i][j] = maxm[i][j] - allot[i][j];
        }
    }
}


std::vector<std::vector<int>> Banker::getNeedVector() {
    return need;
}

void Banker::setMaxmVector() {
    while (true) {
        // Exception handling for invalid input
        for (int i = 0; i < processes; i++) {
            try {
                std::cout << "Enter the number of maximum resources for process " << i << " :";
                std::cin >> resources;

                if (std::cin.fail()) {
                    throw std::invalid_argument("Invalid input. Please enter an integer.");
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

std::vector<std::vector<int>> Banker::getMaxmVector() {
    return maxm;
}

void Banker::setAllotVector() {
    while (true) {
        // Exception handling for invalid input
        for (int i = 0; i < processes; i++) {
            try {
                std::cout << "Enter the number of allotted resources for process " << i << " :";
                std::cin >> resources;

                if (std::cin.fail()) {
                    throw std::invalid_argument("Invalid input. Please enter an integer.");
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

std::vector<std::vector<int>> Banker::getAllotVector() {
    return allot;
}