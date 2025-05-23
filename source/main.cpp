//
// Created by chris on 21/05/2025.
//
#include <iostream>
#include <limits>
#include "menu.h"
#include "AntHillConfig.h"

int main() {
    int anthillChoice = -1;

    while (true) {
        // Choose anthill
        anthillChoice = getAntHillChoice();

        // Create and configure an anthill house
        AntHill anthill;
        switch (anthillChoice) {
            case 0:
                configureAntHillHouse0(anthill);
                break;
            case 1:
                configureAntHillHouse1(anthill);
                break;
            case 2:
                configureAntHillHouse2(anthill);
                break;
            case 3:
                configureAntHillHouse3(anthill);
                break;
            case 4:
                configureAntHillHouse4(anthill);
                break;
            case 5:
                configureAntHillHouse5(anthill);
                break;
            default:
                std::cout << "Invalid AntHill choice." << std::endl;
                continue;
        }

        // Ask user if they want to run another simulation
        char choice;
        std::cout << "Do you want to run another simulation? (y/n): ";
        std::cin >> choice;
        if (std::cin.fail() || (choice != 'y' && choice != 'n')) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Exiting." << std::endl;
            break;
        }
        if (choice == 'n') {
            break;
        }
    }

    return 0;
}