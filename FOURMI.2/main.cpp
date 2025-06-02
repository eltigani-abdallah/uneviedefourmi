#include <iostream>
#include "ants.hpp"
#include <chrono>

// Function to print the adjacency matrix
void printAdjacencyMatrix(int matrix[4][4], int size) {
    std::cout << "Adjacency Matrix:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

// Function to print connections for each vertex
void printConnections(int matrix[4][4], std::string vertices[4], int size) {
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
    anthill.addRoom("Sv", 5);
    anthill.addRoom("S1", 1);
    anthill.addRoom("S2", 1);
    anthill.addRoom("Sd", 5);

    // Adding tunnels between rooms according to the problem statement
    anthill.addTunnel("Sv", "S1");
    anthill.addTunnel("S1", "S2");
    anthill.addTunnel("S2", "Sd");
    anthill.addTunnel("Sd", "Sv");
"
    // Adding ants to the anthill
    for (int i = 1; i <= 5; ++i) {
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
    anthill.addRoom("Sv", 5);
    anthill.addRoom("S1", 1);
    anthill.addRoom("S2", 1);
    anthill.addRoom("Sd", 5);

    anthill.addTunnel("Sv", "S1");
    anthill.addTunnel("S1", "S2");
    anthill.addTunnel("S2", "Sd");
    anthill.addTunnel("Sd", "Sv");

    for (int i = 1; i <= 5; ++i) {
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
    std::string vertexData[4] = {"Sv", "S1", "S2", "Sd"};

    // Adjacency matrix
    int adjacencyMatrix[4][4] = {
        {0, 1, 0, 1}, // Sv
        {1, 0, 1, 0}, // S1
        {0, 1, 0, 1}, // S2
        {1, 0, 1, 0}  // Sd
    };

    std::cout << "\n=== Graph Info (Adjacency Matrix & Connections) ===\n";
    printAdjacencyMatrix(adjacencyMatrix, 4);
    printConnections(adjacencyMatrix, vertexData, 4);
    return 0;
}
