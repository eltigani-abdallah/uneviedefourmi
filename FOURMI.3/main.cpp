#include <iostream>
#include <chrono>
#include "ants.hpp"

int main() {
    Fourmiliere fourmiliere;

    // Ajout des salles
    fourmiliere.ajouterSalle("Sv", 5);  // Vestibule
    fourmiliere.ajouterSalle("S1", 1);
    fourmiliere.ajouterSalle("S2", 1);
    fourmiliere.ajouterSalle("S3", 1);
    fourmiliere.ajouterSalle("S4", 1);
    fourmiliere.ajouterSalle("Sd", 5);  // Dortoir

    // Ajout des tunnels
    fourmiliere.ajouterTunnel("Sv", "S1");
    fourmiliere.ajouterTunnel("S1", "S2");
    fourmiliere.ajouterTunnel("S1", "S4");
    fourmiliere.ajouterTunnel("S2", "S3");
    fourmiliere.ajouterTunnel("S4", "Sd");

    // Ajout des fourmis
    for (int i = 1; i <= 5; ++i) {
        fourmiliere.ajouterFourmi("f" + std::to_string(i), "Sv");
    }

    std::cout << "=== Simulation BFS ===\n";
    auto start_bfs = std::chrono::high_resolution_clock::now();
    simulateurBFS(fourmiliere);
    auto end_bfs = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_bfs = end_bfs - start_bfs;
    std::cout << "Temps BFS : " << duration_bfs.count() << " secondes\n";

    // Réinitialisation de la fourmilière pour DFS
    Fourmiliere fourmiliereDFS;

    fourmiliereDFS.ajouterSalle("Sv", 5);
    fourmiliereDFS.ajouterSalle("S1", 1);
    fourmiliereDFS.ajouterSalle("S2", 1);
    fourmiliereDFS.ajouterSalle("S3", 1);
    fourmiliereDFS.ajouterSalle("S4", 1);
    fourmiliereDFS.ajouterSalle("Sd", 5);

    fourmiliereDFS.ajouterTunnel("Sv", "S1");
    fourmiliereDFS.ajouterTunnel("S1", "S2");
    fourmiliereDFS.ajouterTunnel("S1", "S4");
    fourmiliereDFS.ajouterTunnel("S2", "S3");
    fourmiliereDFS.ajouterTunnel("S4", "Sd");

    for (int i = 1; i <= 5; ++i) {
        fourmiliereDFS.ajouterFourmi("f" + std::to_string(i), "Sv");
    }

    std::cout << "\n=== Simulation DFS ===\n";
    auto start_dfs = std::chrono::high_resolution_clock::now();
    simulateurDFS(fourmiliereDFS);
    auto end_dfs = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_dfs = end_dfs - start_dfs;
    std::cout << "Temps DFS : " << duration_dfs.count() << " secondes\n";

    return 0;
}
