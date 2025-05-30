#include <exception>
#include "ants.hpp"
#include <iostream>
#include <queue>
#include <unordered_map>

int main() {
    Fourmiliere fourmiliere;

    // --- Salle ---
    fourmiliere.ajouterSalle("Sv", 2);
    fourmiliere.ajouterSalle("S1", 1);
    fourmiliere.ajouterSalle("S2", 1);
    fourmiliere.ajouterSalle("Sd", 2);

    // --- Tunnel ---
    fourmiliere.ajouterTunnel("Sv", "S1");
    fourmiliere.ajouterTunnel("Sv", "S2");
    fourmiliere.ajouterTunnel("S1", "Sd");
    fourmiliere.ajouterTunnel("S2", "Sd");

    // --- affiche ---
    std::cout << "=== Schema du fourmiliere ===\n";
    fourmiliere.afficher();
    //std::cout << "Ordre de visite (BFS) : ";
    //fourmiliere.bfs("Sv");

    // --- silation ---
    std::cout << "\n=== Simulation ===\n";

    struct Fourmi {
        std::string nom;
        std::string position;
        std::queue<std::string> chemin;
    };

    // f1 - S1, f2 - S2
    std::vector<Fourmi> fourmis = {
        {"f1", "Sv", std::queue<std::string>({"S1", "Sd"})},
        {"f2", "Sv", std::queue<std::string>({"S2", "Sd"})}
    };

    std::unordered_map<std::string, int> occupation = {
        {"Sv", 2}, {"S1", 0}, {"S2", 0}, {"Sd", 0}
    };

    int etape = 1;
    while (true) {
        bool moved = false;
        std::string etapeLog; // временно храним сообщения муравьев
        for (auto& f : fourmis) {
            if (!f.chemin.empty()) {
                std::string next = f.chemin.front();
                int cap = fourmiliere.getSalle(next).capacite;
                if (occupation[next] < cap) {
                    occupation[f.position]--;
                    occupation[next]++;
                    etapeLog += f.nom + " - " + f.position + " --> " + next + "\n";
                    f.position = next;
                    f.chemin.pop();
                    moved = true;
                }
            }
        }
        if (!moved) break;
        std::cout << "\netape " << etape++ << "\n" << etapeLog;
    }


    return 0;
}
