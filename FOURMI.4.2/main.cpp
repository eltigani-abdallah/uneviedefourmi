#include <iostream>
#include "ants.hpp"
#include <chrono>

void printAdjacencyMatrix(int matrix[8][8], int size) {
    std::cout << "Adjacency Matrix:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

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
    std::unordered_map<std::string, Salle> graph = {
        {"SV", {"SV", 10, 0, {"S1"}}},
        {"S1", {"S1", 2, 0, {"S2", "S3"}}},
        {"S2", {"S2", 1, 0, {"S4"}}},
        {"S3", {"S3", 1, 0, {"S4"}}},
        {"S4", {"S4", 2, 0, {"S5", "S6"}}},
        {"S5", {"S5", 1, 0, {"SD"}}},
        {"S6", {"S6", 1, 0, {"SD"}}},
        {"SD", {"SD", 10, 0, {}}}
    };

    std::cout << "Graph Traversal:\n";
    bfs_trouver_chemins(graph, "SV", "SD");
    dfs_trouver_chemins(graph, "SV", "SD");

    std::string vertexData[8] = {"SV", "S1", "S2", "S3", "S4", "S5", "S6", "SD"};
    int adjacencyMatrix[8][8] = {
        {0, 1, 0, 0, 0, 0, 0, 0},  // SV
        {1, 0, 1, 1, 0, 0, 0, 0},  // S1
        {0, 1, 0, 0, 1, 0, 0, 0},  // S2
        {0, 1, 0, 0, 1, 0, 0, 0},  // S3
        {0, 0, 1, 1, 0, 1, 1, 0},  // S4
        {0, 0, 0, 0, 1, 0, 0, 1},  // S5
        {0, 0, 0, 0, 1, 0, 0, 1},  // S6
        {0, 0, 0, 0, 0, 1, 1, 0}   // SD
    };

    std::cout << "\nVertices: ";
    for (int i = 0; i < 8; i++) {
        std::cout << vertexData[i] << " ";
    }
    std::cout << "\n\n";

    printAdjacencyMatrix(adjacencyMatrix, 8);
    printConnections(adjacencyMatrix, vertexData, 8);


    std::cout << "===Simulation BFS====\n";
    auto start = std::chrono::high_resolution_clock::now();
    simulationBFS(adjacencyMatrix, 8);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << duration.count() << " microseconds\n";

    std::cout << "===Simulation DFS====\n";
    start = std::chrono::high_resolution_clock::now();
    simulationDFS(adjacencyMatrix, 8);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << duration.count() << " microseconds\n";

    void simulationBFS(int matrix[8][8], int size);
    void simulationDFS(int matrix[8][8], int size);
    simulerDeplacementDesFourmis(graph, 10);

    return 0;
}
