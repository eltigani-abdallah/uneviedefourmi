#include "ants.hpp"
#include <iostream>
#include <unordered_set>

// ===== Salle =====

Salle::Salle(const std::string& nom, int capacite)
    : nom(nom), capacite(capacite) {}

void Salle::ajouterConnexion(const std::string& destination) {
    connexions.push_back(destination);
}

// ===== Tunnel =====

Tunnel::Tunnel(const std::string& d, const std::string& v)
    : depuis(d), vers(v) {}

// ===== Fourmi =====

Fourmi::Fourmi(const std::string& nom, const std::string& start)
    : nom(nom), position(start) {}

// ===== Fourmiliere =====

void Fourmiliere::ajouterSalle(const std::string& nom, int capacite) {
    salles[nom] = Salle(nom, capacite);
}

void Fourmiliere::ajouterTunnel(const std::string& depuis, const std::string& vers) {
    salles[depuis].ajouterConnexion(vers);
}

void Fourmiliere::ajouterFourmi(const std::string& nom, const std::string& start) {
    fourmis.emplace_back(nom, start);
}

void Fourmiliere::afficher() const {
    //std::cout << "=== Schéma du fourmilière ===\n";
    for (const auto& [nom, salle] : salles) {
        std::cout << nom << " (" << salle.capacite << ") : ";
        for (const auto& dest : salle.connexions) {
            std::cout << "-> " << dest << " ";
        }
        std::cout << "\n";
    }
}

void Fourmiliere::bfs(const std::string& depart) const {
    std::unordered_set<std::string> visitees;
    std::queue<std::string> file;
    file.push(depart);

    //std::cout << "Ordre de visite (BFS) : ";

    while (!file.empty()) {
        std::string courant = file.front();
        file.pop();

        if (visitees.find(courant) == visitees.end()) {
            std::cout << courant << " ";
            visitees.insert(courant);

            for (const auto& voisin : salles.at(courant).connexions) {
                file.push(voisin);
            }
        }
    }

    std::cout << "\n";
}

Salle& Fourmiliere::getSalle(const std::string& nom) {
    return salles.at(nom);
}
