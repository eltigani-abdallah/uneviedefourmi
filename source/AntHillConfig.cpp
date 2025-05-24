#include "AntHillConfig.h"

// Configure Anthill house 0
void configureAntHillHouse0(AntHill& anthill) {
    anthill.addRoom("Sv", 100);
    anthill.addRoom("S1", 1);
    anthill.addRoom("S2", 1);
    anthill.addRoom("Sd", 100);

    anthill.addTunnel("Sv", "S1");
    anthill.addTunnel("Sv", "S2");
    anthill.addTunnel("S1", "Sd");
    anthill.addTunnel("S2", "Sd");

    for (int i = 1; i <= 2; ++i) {
        anthill.addAnt(std::make_shared<Ant>(i, anthill.getRoom("Sv")));
    }

    std::cout << "=== Anthill 0 - 2 ants going to sleep ===" << std::endl;
    anthill.simulateMovement();
}

// Configure Anthill house 1
void configureAntHillHouse1(AntHill& anthill) {
    // Add Rooms
    anthill.addRoom("Sv", 100);
    anthill.addRoom("S1", 1);
    anthill.addRoom("S2", 1);
    anthill.addRoom("Sd", 100);

    // Add Tunnels
    anthill.addTunnel("Sv", "S1");
    anthill.addTunnel("Sv", "S2");
    anthill.addTunnel("S1", "Sd");
    anthill.addTunnel("S2", "Sd");

    for (int i = 1; i <= 5; ++i) {
        anthill.addAnt(std::make_shared<Ant>(i, anthill.getRoom("Sv")));
    }

    std::cout << "=== Anthill 1 - 5 ants going to sleep ===" << std::endl;
    anthill.simulateMovement();
}

// Configure Anthill house 2
void configureAntHillHouse2(AntHill& anthill) {
    // Add Rooms
    anthill.addRoom("Sv", 100);
    anthill.addRoom("S1", 1);
    anthill.addRoom("S2", 1);
    anthill.addRoom("Sd", 100);

    // Add Tunnels
    anthill.addTunnel("Sv", "S1");
    anthill.addTunnel("Sv", "S2");
    anthill.addTunnel("Sv", "Sd");

    for (int i = 1; i <= 5; ++i) {
        anthill.addAnt(std::make_shared<Ant>(i, anthill.getRoom("Sv")));
    }

    std::cout << "=== Anthill 2 - 5 ants going to sleep ===" << std::endl;
    anthill.simulateMovement();
}

// Configure Anthill house 3
void configureAntHillHouse3(AntHill& anthill) {
    // Add Rooms
    anthill.addRoom("Sv", 100);
    anthill.addRoom("S1", 1);
    anthill.addRoom("S2", 1);
    anthill.addRoom("S3", 1);
    anthill.addRoom("S4", 1);
    anthill.addRoom("Sd", 100);

    // Add Tunnels
    anthill.addTunnel("Sv", "S1");
    anthill.addTunnel("S1", "S2");
    anthill.addTunnel("S1", "S4");
    anthill.addTunnel("S4", "Sd");
    anthill.addTunnel("S2", "S3");

    for (int i = 1; i <= 5; ++i) {
        anthill.addAnt(std::make_shared<Ant>(i, anthill.getRoom("Sv")));
    }

    std::cout << "=== Anthill 3 - 5 ants going to sleep ===" << std::endl;
    anthill.simulateMovement();
}

// Configure Anthill house 4
void configureAntHillHouse4(AntHill& anthill) {
    // Add Rooms
    anthill.addRoom("Sv", 100);
    anthill.addRoom("S1", 2);
    anthill.addRoom("S2", 1);
    anthill.addRoom("S3", 1);
    anthill.addRoom("S4", 2);
    anthill.addRoom("S5", 1);
    anthill.addRoom("S6", 1);
    anthill.addRoom("Sd", 100);

    // Add Tunnels
    anthill.addTunnel("Sv", "S1");
    anthill.addTunnel("S1", "S2");
    anthill.addTunnel("S1", "S3");
    anthill.addTunnel("S2", "S4");
    anthill.addTunnel("S3", "S4");
    anthill.addTunnel("S4", "S5");
    anthill.addTunnel("S4", "S6");
    anthill.addTunnel("S5", "Sd");
    anthill.addTunnel("S6", "Sd");

    for (int i = 1; i <= 10; ++i) {
        anthill.addAnt(std::make_shared<Ant>(i, anthill.getRoom("Sv")));
    }

    std::cout << "=== Anthill 4 - 10 ants going to sleep ===" << std::endl;
    anthill.simulateMovement();
}

// Configure Anthill house 5
void configureAntHillHouse5(AntHill& anthill) {
    // Add Rooms
    anthill.addRoom("Sv", 100);
    anthill.addRoom("S1", 8);
    anthill.addRoom("S2", 4);
    anthill.addRoom("S3", 2);
    anthill.addRoom("S4", 4);
    anthill.addRoom("S5", 2);
    anthill.addRoom("S6", 4);
    anthill.addRoom("S7", 2);
    anthill.addRoom("S8", 5);
    anthill.addRoom("S9", 1);
    anthill.addRoom("S10", 1);
    anthill.addRoom("S11", 1);
    anthill.addRoom("S12", 1);
    anthill.addRoom("S13", 4);
    anthill.addRoom("S14", 2);
    anthill.addRoom("Sd", 100);

    // Add Tunnels
    anthill.addTunnel("Sv", "S1");
    anthill.addTunnel("S1", "S2");
    anthill.addTunnel("S1", "S6");
    anthill.addTunnel("S2", "S3");
    anthill.addTunnel("S2", "S5");
    anthill.addTunnel("S3", "S4");
    anthill.addTunnel("S5", "S4");
    anthill.addTunnel("S4", "Sd");
    anthill.addTunnel("S6", "S7");
    anthill.addTunnel("S6", "S8");
    anthill.addTunnel("S7", "S9");
    anthill.addTunnel("S7", "S10");
    anthill.addTunnel("S9", "S14");
    anthill.addTunnel("S10", "S14");
    anthill.addTunnel("S14", "Sd");
    anthill.addTunnel("S8", "S11");
    anthill.addTunnel("S8", "S12");
    anthill.addTunnel("S11", "S13");
    anthill.addTunnel("S12", "S13");
    anthill.addTunnel("S13", "Sd");


    for (int i = 1; i <= 50; ++i) {
        anthill.addAnt(std::make_shared<Ant>(i, anthill.getRoom("Sv")));
    }

    std::cout << "=== Anthill 5 - 50 ants going to sleep ===" << std::endl;
    anthill.simulateMovement();
}