#include <iostream>
#include <chrono>
#include "ants.hpp"

int main() {
    Fourmiliere fourmiliere;

    // Ajout des salles
    fourmiliere.ajouterSalle("Sv", 50);  // Vestibule
    fourmiliere.ajouterSalle("S1", 8);
    fourmiliere.ajouterSalle("S2", 4);
    fourmiliere.ajouterSalle("S3", 2);
    fourmiliere.ajouterSalle("S4", 4);
    fourmiliere.ajouterSalle("S5", 2);
    fourmiliere.ajouterSalle("S6", 4);
    fourmiliere.ajouterSalle("S7", 2);
    fourmiliere.ajouterSalle("S8", 5);
    fourmiliere.ajouterSalle("S9", 1);
    fourmiliere.ajouterSalle("S10", 1);
    fourmiliere.ajouterSalle("S11", 1);
    fourmiliere.ajouterSalle("S12", 1);
    fourmiliere.ajouterSalle("S13", 4);
    fourmiliere.ajouterSalle("S14", 2);
    fourmiliere.ajouterSalle("Sd", 50);  // Dortoir

    // Ajout des tunnels
    fourmiliere.ajouterTunnel("Sv", "S1");
    fourmiliere.ajouterTunnel("S1", "S2");
    fourmiliere.ajouterTunnel("S1", "S6");
    fourmiliere.ajouterTunnel("S2", "S3");
    fourmiliere.ajouterTunnel("S2", "S5");
    fourmiliere.ajouterTunnel("S3", "S4");
    fourmiliere.ajouterTunnel("S5", "S4");
    fourmiliere.ajouterTunnel("S4", "Sd");
    fourmiliere.ajouterTunnel("S6", "S7");
    fourmiliere.ajouterTunnel("S7", "S9");
    fourmiliere.ajouterTunnel("S9", "S14");
    fourmiliere.ajouterTunnel("S7", "S10");
    fourmiliere.ajouterTunnel("S10", "S14");
    fourmiliere.ajouterTunnel("S14", "Sd");
    fourmiliere.ajouterTunnel("S8", "S11");
    fourmiliere.ajouterTunnel("S8", "S12");
    fourmiliere.ajouterTunnel("S11", "S13");
    fourmiliere.ajouterTunnel("S12", "S13");
    fourmiliere.ajouterTunnel("S13", "Sd");

    // Ajout des fourmis
    for (int i = 1; i <= 50; ++i) {
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

    fourmiliereDFS.ajouterSalle("Sv", 50);
    fourmiliereDFS.ajouterSalle("S1", 8);
    fourmiliereDFS.ajouterSalle("S2", 4);
    fourmiliereDFS.ajouterSalle("S3", 2);
    fourmiliereDFS.ajouterSalle("S4", 4);
    fourmiliereDFS.ajouterSalle("S5", 2);
    fourmiliereDFS.ajouterSalle("S6", 4);
    fourmiliereDFS.ajouterSalle("S7", 2);
    fourmiliereDFS.ajouterSalle("S8", 5);
    fourmiliereDFS.ajouterSalle("S9", 1);
    fourmiliereDFS.ajouterSalle("S10", 1);
    fourmiliereDFS.ajouterSalle("S11", 1);
    fourmiliereDFS.ajouterSalle("S12", 1);
    fourmiliereDFS.ajouterSalle("S13", 4);
    fourmiliereDFS.ajouterSalle("S14", 2);
    fourmiliereDFS.ajouterSalle("Sd", 50);


    fourmiliereDFS.ajouterTunnel("Sv", "S1");
    fourmiliereDFS.ajouterTunnel("S1", "S2");
    fourmiliereDFS.ajouterTunnel("S1", "S6");
    fourmiliereDFS.ajouterTunnel("S2", "S3");
    fourmiliereDFS.ajouterTunnel("S2", "S5");
    fourmiliereDFS.ajouterTunnel("S3", "S4");
    fourmiliereDFS.ajouterTunnel("S5", "S4");
    fourmiliereDFS.ajouterTunnel("S4", "Sd");
    fourmiliereDFS.ajouterTunnel("S6", "S7");
    fourmiliereDFS.ajouterTunnel("S7", "S9");
    fourmiliereDFS.ajouterTunnel("S9", "S14");
    fourmiliereDFS.ajouterTunnel("S7", "S10");
    fourmiliereDFS.ajouterTunnel("S10", "S14");
    fourmiliereDFS.ajouterTunnel("S14", "Sd");
    fourmiliereDFS.ajouterTunnel("S8", "S11");
    fourmiliereDFS.ajouterTunnel("S8", "S12");
    fourmiliereDFS.ajouterTunnel("S11", "S13");
    fourmiliereDFS.ajouterTunnel("S12", "S13");
    fourmiliereDFS.ajouterTunnel("S13", "Sd");
    fourmiliereDFS.ajouterTunnel("S4", "Sd");

    for (int i = 1; i <= 50; ++i) {
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
