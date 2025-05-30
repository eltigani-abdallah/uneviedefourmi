#include "ants.hpp"
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <algorithm>  //  std::find


void bfs_trouver_chemins(const std::unordered_map<std::string, Salle>& graphe, const std::string& debut, const std::string& fin) {
    std::vector<std::vector<std::string>> file = { {debut} };
    std::cout << "\nBFS - Chemins de " << debut << " a " << fin << " :\n";

    while (!file.empty()) {
        std::vector<std::string> chemin = file.front();
        file.erase(file.begin());
        std::string courant = chemin.back();

        if (courant == fin) {
            for (const auto& salle : chemin) {
                std::cout << salle << " ";
            }
            std::cout << "\n";
            continue;
        }

        for (const auto& voisin : graphe.at(courant).voisins) {
            if (std::find(chemin.begin(), chemin.end(), voisin) == chemin.end()) {
                std::vector<std::string> nouveau_chemin = chemin;
                nouveau_chemin.push_back(voisin);
                file.push_back(nouveau_chemin);
            }
        }
    }
}

void dfs_util(const std::unordered_map<std::string, Salle>& graphe, const std::string& courant, const std::string& fin,
              std::vector<std::string>& chemin_actuel, std::unordered_set<std::string>& visites) {
    chemin_actuel.push_back(courant);
    visites.insert(courant);

    if (courant == fin) {
        for (const auto& salle : chemin_actuel) {
            std::cout << salle << " ";
        }
        std::cout << "\n";
    } else {
        for (const auto& voisin : graphe.at(courant).voisins) {
            if (visites.find(voisin) == visites.end()) {
                dfs_util(graphe, voisin, fin, chemin_actuel, visites);
            }
        }
    }

    chemin_actuel.pop_back();
    visites.erase(courant);
}

void dfs_trouver_chemins(const std::unordered_map<std::string, Salle>& graphe, const std::string& debut, const std::string& fin) {
    std::vector<std::string> chemin_actuel;
    std::unordered_set<std::string> visites;
    std::cout << "\nDFS - Chemins de " << debut << " a " << fin << " :\n";
    dfs_util(graphe, debut, fin, chemin_actuel, visites);
}

void simulerDeplacementDesFourmis(std::unordered_map<std::string, Salle>& graphe, int nombreDeFourmis) {
    std::vector<Fourmi> fourmis;
    for (int i = 0; i < nombreDeFourmis; ++i) {
        fourmis.push_back({i + 1, {"SV", "S1", (i % 2 == 0 ? "S2" : "S3"), "S4", (i % 2 == 0 ? "S5" : "S6"), "SD"}});
    }

    std::cout << "\n--- Simulation du deplacement des fourmis ---\n";
    for (int etape = 0; etape < 6; ++etape) {
        std::cout << "etape " << etape + 1 << ":\n";
        for (auto& fourmi : fourmis) {
            if (fourmi.position < fourmi.chemin.size()) {
                std::string de = (fourmi.position > 0) ? fourmi.chemin[fourmi.position - 1] : "Depart";
                std::string vers = fourmi.chemin[fourmi.position];
                std::cout << "  Fourmi F" << fourmi.id << ": " << de << " -> " << vers << "\n";
                ++fourmi.position;
            }
        }
    }
}
