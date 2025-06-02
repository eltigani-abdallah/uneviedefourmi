#include <iostream>
#include "ants.hpp"
#include <chrono>

// Function to print the adjacency matrix
void printAdjacencyMatrix(int matrix[16][16], int size) {
    std::cout << "Adjacency Matrix:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// Function to print connections for each vertex
void printConnections(int matrix[16][16], std::string vertices[16], int size) {
    std::cout << "\nConnections for each vertex:\n";
    for (int i = 0; i < size; i++) {
        std::cout << vertices[i] << ": ";
        for (int j = 0; j < size; j++) {
            if (matrix[i][j]) {
                std::cout << vertices[j] << " ";
            }
        }
        std::cout << "\n";
    }
}

int main() {
    AntHill anthill;

    // Adding rooms to the anthill
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

    // Adding tunnels between rooms
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

    // Adding ants to the anthill
    for (int i = 1; i <= 50; ++i) {
        anthill.addAnt(std::make_shared<Ant>(i, anthill.getRoom("Sv")));
    }

    // Simulation using BFS
    std::cout << "\n=== Simulation BFS ===\n";
    auto start_bfs = std::chrono::high_resolution_clock::now();
    simulateurBFS(anthill);
    auto end_bfs = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_bfs = end_bfs - start_bfs;
    std::cout << "\nTime BFS: " << duration_bfs.count() << " seconds\n";

    // Reset for DFS simulation
    anthill = AntHill();
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

    // Simulation using DFS
    std::cout << "\n=== Simulation DFS ===\n";
    auto start_dfs = std::chrono::high_resolution_clock::now();
    simulateurDFS(anthill);
    auto end_dfs = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_dfs = end_dfs - start_dfs;
    std::cout << "\nTime DFS: " << duration_dfs.count() << " seconds\n";

    // Graph: vertex names
    std::string vertexData[16] = {
        "Sv", "S1", "S2", "S3", "S5", "S4", "S6", "S7",
        "S9", "S10", "S14", "S8", "S11", "S12", "S13", "Sd"
    };

    // Adjacency matrix
    int adjacencyMatrix[16][16] = {
        { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // Sv
        { 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // S1
        { 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // S2
        { 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // S3
        { 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, // S5
        { 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // S4
        { 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0 }, // S6
        { 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0 }, // S7
        { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0 }, // S9
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0 }, // S10
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, // S14
        { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 }, // S8
        { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 }, // S11
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1 }, // S12
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1 }, // S13
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0 }  // Sd
    };

    std::cout << "\n=== Graph Info (Adjacency Matrix & Connections) ===\n";
    printAdjacencyMatrix(adjacencyMatrix, 16);
    printConnections(adjacencyMatrix, vertexData, 16);
    return 0;
}
