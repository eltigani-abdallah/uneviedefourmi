//
// Created by chris on 21/05/2025.
//
#include <iostream>
#include <limits>
#include "menu.h"
#include "AntHillConfig.h"

int main() {
    int anthillChoice = -1;

    // Choose anthill
    anthillChoice = getAntHillChoice();

    // Create and config a anthillhouse
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
            return 1;
    }

    // other funcs

    return 0;
}