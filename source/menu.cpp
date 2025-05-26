#include <iostream>
#include "menu.h"

#include <limits>

//To display the menu
void displayAntHillMenu() {
    std::cout << "=== Choose your AntHill House ===" << std::endl;
    std::cout << "0 - AntHill House 0" << std::endl;
    std::cout << "1 - AntHill House 1" << std::endl;
    std::cout << "2 - AntHill House 2" << std::endl;
    std::cout << "3 - AntHill House 3" << std::endl;
    std::cout << "4 - AntHill House 4" << std::endl;
    std::cout << "5 - AntHill House 5" << std::endl;
}

//To get user choice
int getAntHillChoice() {
    int choice = -1;
    while (true) {
        displayAntHillMenu();
        std::cout << "Enter your AntHill Choice (0-5): ";
        std::cin >> choice;

        //handle user typing a letter input error
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a valid number between 0 and 5" << std::endl;
            continue;
        }
        //handle user typing a number not between 0 and 5
        if (choice >= 0 && choice <= 5) break;
        std::cout << "Please enter a valid number between 0 and 5" << std::endl;
    }
    return choice;
}


// Created by chris on 21/05/2025.
//
