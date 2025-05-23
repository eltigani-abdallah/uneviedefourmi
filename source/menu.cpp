//
#include <iostream>
#include <limits>
#include "menu.h"

//To display AntHill menu
void displayAntHillMenu() {
    std::cout << "=== Choose your AntHill House ===" << std::endl;
    std::cout << "0 - AntHill House 0" << std::endl;
    std::cout << "1 - AntHill House 1" << std::endl;
    std::cout << "2 - AntHill House 2" << std::endl;
    std::cout << "3 - AntHill House 3" << std::endl;
    std::cout << "4 - AntHill House 4" << std::endl;
    std::cout << "5 - AntHill House 5" << std::endl;
    }

// Get Anthill menu choice
 int getAntHillChoice(){
    int choice = -1;
    while (true) {
    displayAntHillMenu();
    std::cout << "Enter your AntHill Choice (0-5): " << std::endl;
    std::cin >> choice;
    if (std::cin.fail() || anthillChoice < 0 || anthillChoice > 5) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a valid number between 0 and 5" << std::endl;
        } else {
            break;
        }
    }
    return choice;
   }


// Created by chris on 21/05/2025.
//
