#include <iostream>
#include "ants.hpp"
#include <chrono>

// Function to print the adjacency matrix
void printAdjacencyMatrix(int matrix[8][8], int size) {
    std::cout << "Adjacency Matrix:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// Function to print connections for each vertex
void printConnections(int matrix[8][8], std::string vertices[8], int size) {
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

    // Adding rooms to the anthill with updated capacities
    anthill.addRoom("Sv", 10);
    anthill.addRoom("S1", 2);
    anthill.addRoom("S2", 1);
    anthill.addRoom("S3", 1);
    anthill.addRoom("S4", 2);
    anthill.addRoom("S5", 1);
    anthill.addRoom("S6", 1);
    anthill.addRoom("Sd", 10);

    // Adding tunnels between rooms according to the problem statement
    anthill.addTunnel("Sv", "S1");
    anthill.addTunnel("S1", "S2");
    anthill.addTunnel("S1", "S3");
    anthill.addTunnel("S2", "S4");
    anthill.addTunnel("S3", "S4");
    anthill.addTunnel("S4", "S5");
    anthill.addTunnel("S4", "S6");
    anthill.addTunnel("S5", "Sd");
    anthill.addTunnel("S6", "Sd");

    // Adding ants to the anthill
    for (int i = 1; i <= 10; ++i) {
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
    anthill.addRoom("Sv", 10);
    anthill.addRoom("S1", 2);
    anthill.addRoom("S2", 1);
    anthill.addRoom("S3", 1);
    anthill.addRoom("S4", 2);
    anthill.addRoom("S5", 1);
    anthill.addRoom("S6", 1);
    anthill.addRoom("Sd", 10);

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

    // Simulation using DFS
    std::cout << "\n=== Simulation DFS ===\n";
    auto start_dfs = std::chrono::high_resolution_clock::now();
    simulateurDFS(anthill);
    auto end_dfs = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_dfs = end_dfs - start_dfs;
    std::cout << "\nTime DFS: " << duration_dfs.count() << " seconds\n";

    // Graph: vertex names
    std::string vertexData[8] = {"Sv", "S1", "S2", "S3", "S4", "S5", "S6", "Sd"};

    // Adjacency matrix
    int adjacencyMatrix[8][8] = {
        {0, 1, 0, 0, 0, 0, 0, 0},  // Sv
        {1, 0, 1, 1, 0, 0, 0, 0},  // S1
        {0, 1, 0, 0, 1, 0, 0, 0},  // S2
        {0, 1, 0, 0, 1, 0, 0, 0},  // S3
        {0, 0, 1, 1, 0, 1, 1, 0},  // S4
        {0, 0, 0, 0, 1, 0, 0, 1},  // S5
        {0, 0, 0, 0, 1, 0, 0, 1},  // S6
        {0, 0, 0, 0, 0, 1, 1, 0}   // Sd
    };

    std::cout << "\n=== Graph Info (Adjacency Matrix & Connections) ===\n";
    printAdjacencyMatrix(adjacencyMatrix, 8);
    printConnections(adjacencyMatrix, vertexData, 8);
    return 0;
}
