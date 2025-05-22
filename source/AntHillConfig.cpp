//
// Created by chris on 21/05/2025.
//
#include <iostream>
#include "AntHillConfig.h"

// Configure Anthillhouse 0
void configureAntHillHouse0 (AntHill& anthill) {

    //Add Rooms
    anthill.addRoom("Sv", 100);
    anthill.addRoom("S1", 1);
    anthill.addRoom("S2", 1);
    anthill.addRoom("Sd", 100);

    //Add Tunnels
    anthill.addTunnel("Sv", "S1");
    anthill.addTunnel("Sv", "S2");
    anthill.addTunnel("S1", "Sd");
    anthill.addTunnel("S2", "Sd");

    //Calculate optimal path for each ant
    auto path = anthill.computeOptimalPath("Sv", "Sd");

    // 2 ants
    for (int i = 1; i <= 2; ++i) {
        anthill.addAnt(std::make_shared<Ant>(i, path));
    }

    std::cout << "=== Anthill 0 - 2 ants going to sleep ===" << std::endl;
    anthill.simulateMovement();
    return 0;
}

//Configure Anthillhouse 1
void configureAntHillHouse1 (AntHill& anthill) {

    //Add Rooms
    anthill.addRoom("Sv", 100);
    anthill.addRoom("S1", 1);
    anthill.addRoom("S2", 1);
    anthill.addRoom("Sd", 100);

    // Add Tunnels
    anthill.addTunnel("Sv", "S1");
    anthill.addTunnel("Sv", "S2");
    anthill.addTunnel("S1", "Sd");
    anthill.addTunnel("S2", "Sd");

    //Calculate optimal path for each ant
    auto path = anthill.computeOptimalPath("Sv", "Sd");

    // 5 ants
    for (int i = 1; i <= 5; ++i) {
        anthill.addAnt(std::make_shared<Ant>(i, path));
    }

    std::cout << "=== Anthill 1 - 5 ants going to sleep ===" << std::endl;
    anthill.simulateMovement();
    return 0;
}

//Configure Anthillhouse 2
void configureAntHillHouse2 (AntHill& anthill) {

    //Add Rooms
    anthill.addRoom("Sv", 100);
    anthill.addRoom("S1", 1);
    anthill.addRoom("S2", 1);
    anthill.addRoom("Sd", 100);

    //Add Tunnels
    anthill.addTunnels("Sv", "S1");
    anthill.addTunnels("Sv", "S2");
    anthill.addTunnels("Sv", "Sd");

    //Calculate optimal path for each ant
    auto path = anthill.computeOptimalPath("Sv", "Sd");

    //5 ants
    for (int i = 1; i <= 5; ++i) {
        anthill.addAnt(std::make_shared<Ant>(i, path));
    }

    std::cout << "=== Anthill 2 - 5 ants going to sleep ===" << std::endl;
    anthill.simulateMovement();
    return 0;
}

// Configure Anthillhouse 3
void configureAntHillHouse3 (AntHill& anthill) {

    //Add Rooms
    anthill.addRoom("Sv", 100);
    anthill.addRoom("S1", 1);
    anthill.addRoom("S2", 1);
    anthill.addRoom("S3", 1);
    anthill.addRoom("S4", 1);
    anthill.addRoom("Sd", 1);

    //add Tunnels
    anthill.addTunnel("Sv", "S1");
    anthill.addTunnel("S1", "S2");
    anthill.addTunnel("S1", "S4");
    anthill.addTunnel("S4", "Sd");
    anthill.addTunnel("S2", "S3");

    //Calculate optimal path for each ant
    auto path = anthill.computeOptimalPath("Sv", "Sd");

    // 5 ants
    for (int i = 1; i <= 5; ++i) {
        anthill.addAnt(std::make_shared<Ant>(i, path));
    }

    std::cout << "=== Anthill 3 - 5 ants going to sleep ===" << std::endl;
    anthill.simulateMovement();
    return 0;
}

//Configure Anthillhouse 4
void configureAntHillHouse4 (AntHill& anthill) {

    //add Rooms
    anthill.addRoom("Sv", 100);
    anthill.addRoom("S1", 2);
    anthill.addRoom("S2", 1);
    anthill.addRoom("S3", 1);
    anthill.addRoom("S4", 2);
    anthill.addRoom("S5", 1);
    anthill.addRoom("S6", 1);
    anthill.addRoom("Sd", 100);

    //add Tunnels
    anthill.addTunnel("Sv", "S1");
    anthill.addTunnel("S1", "S2");
    anthill.addTunnel("S1", "S3");
    anthill.addTunnel("S2", "S4");
    anthill.addTunnel("S3", "S4");
    anthill.addTunnel("S4", "S5");
    anthill.addTunnel("S4", "S6");
    anthill.addTunnel("S5", "Sd");
    anthill.addTunnel("S6", "Sd");

    //Calculate optimal path for each ant
    auto path = anthill.computeOptimalPath("Sv", "Sd");

    // 10 ants
    for (int i = 1; i <= 10; ++i) {
        anthill.addAnt(std::make_shared<Ant>(i, path));
    }

    std::cout << "=== Anthill 4 - 10 ants going to sleep ===" << std::endl;
    anthill.simulateMovement();
    return 0;
}

//Configure Anthillhouse 5
void configureAntHillHouse5 (AntHill& anthill) {

    //add Rooms
    anthill.addRoom("Sv", 100);
    anthill.addRoom("S1", 8);
    anthill.addRoom("S2", 4);
    anthill.addRoom("S3", 2);
    anthill.addRoom("S4", 4);
    anthill.addRoom("S5", 2);
    anthill.addRoom("S6", 2);
    anthill.addRoom("S8", 4);
    anthill.addRoom("S9", 2);
    anthill.addRoom("S10", 2);
    anthill.addRoom("S11", 2);
    anthill.addRoom("S12", 2);
    anthill.addRoom("S13", 4);
    anthill.addRoom("S14", 2);
    anthill.addRoom("Sd", 100);

    // add tunnels
    anthill.addTunnel("Sv", "S1");
    anthill.addTunnel("S1", "S2");
    anthill.addTunnel("S1", "S3");
    anthill.addTunnel("S1", "S6");
    anthill.addTunnel("S2", "S3");
    anthill.addTunnel("S2", "S4");
    anthill.addTunnel("S2", "S5");
    anthill.addTunnel("S3", "S4");
    anthill.addTunnel("S4", "S5");
    anthill.addTunnel("S4", "S6");
    anthill.addTunnel("S4", "Sd");
    anthill.addTunnel("S6", "S8");
    anthill.addTunnel("S8", "S11");
    anthill.addTunnel("S8", "S12");
    anthill.addTunnel("S11", "S13");
    anthill.addTunnel("S12", "S13");
    anthill.addTunnel("S13", "Sd");
    anthill.addTunnel("S9", "S10");
    anthill.addTunnel("S10", "S14");
    anthill.addTunnel("S14", "Sd");

    //Calculate optimal path for each ant
    auto path = anthill.computeOptimalPath("Sv", "Sd");

    // 50 ants
    for (int i = 1; i <= 50; ++i) {
        anthill.addAnt(std::make_shared<Ant>(i, path));
    }

    std::cout << "=== Anthill 5 - 50 ants going to sleep ===" << std::endl;
    anthill.simulateMovement();
    return 0;
}
