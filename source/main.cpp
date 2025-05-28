#include <iostream>
#include "menu.h"
#include "AntHillConfig.h"

int main() {
    int anthillChoice = -1;
    while (true) {
        anthillChoice = getAntHillChoice();
        AntHill anthill;
        // to execute the right anthill depending on user choice
        switch (anthillChoice) {
            case 0: configureAntHillHouse0(anthill); break;
            case 1: configureAntHillHouse1(anthill); break;
            case 2: configureAntHillHouse2(anthill); break;
            case 3: configureAntHillHouse3(anthill); break;
            case 4: configureAntHillHouse4(anthill); break;
            case 5: configureAntHillHouse5(anthill); break;
            case 6: configureAntHillHouse6(anthill); break;
            case 7: configureAntHillHouse7(anthill); break;
            case 8: configureAntHillHouse8(anthill); break;
            default: std::cout << "Invalid AntHill choice." << std::endl; continue;
        }

        char choice;
        std::cout << "Do you want to run another simulation? (y/n): ";
        std::cin >> choice;
        if (choice == 'n') break;
    }

    return 0;
}