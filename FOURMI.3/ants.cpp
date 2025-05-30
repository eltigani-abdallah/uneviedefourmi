#include "ants.hpp"
#include <iostream>
#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <algorithm>

// ===== Salle =====

Salle::Salle(const std::string& nom, int capacite)
    : nom(nom), capacite(capacite), occupants(0) {}
Salle::Salle() : nom(""), capacite(0), occupants(0) {}

void Salle::ajouterConnexion(const std::string& destination) {
    voisins.push_back(destination);
}

bool Salle::peutEntrer() const {
    return occupants < capacite;
}

void Salle::entrer() {
    occupants++;
}

void Salle::sortir() {
    if (occupants > 0) occupants--;
}

// ===== Tunnel =====

Tunnel::Tunnel(const std::string& d, const std::string& v)
    : depuis(d), vers(v) {}

// ===== Fourmi =====

Fourmi::Fourmi(const std::string& nom, const std::string& start)
    : nom(nom), position(start) {}

bool Fourmi::aTermine() const {
    return chemin.empty();
}

void Fourmi::definirChemin(const std::vector<std::string>& c) {
    chemin = c;
}

std::string Fourmi::prochaineSalle() const {
    if (!chemin.empty()) return chemin.front();
    return "";
}

void Fourmi::avancer() {
    if (!chemin.empty()) {
        position = chemin.front();
        chemin.erase(chemin.begin());
    }
}

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
    for (const auto& [nom, salle] : salles) {
        std::cout << nom << " (" << salle.capacite << ") : ";
        for (const auto& dest : salle.voisins) {
            std::cout << "-> " << dest << " ";
        }
        std::cout << "\n";
    }
}

Salle& Fourmiliere::getSalle(const std::string& nom) {
    return salles.at(nom);
}

void Fourmiliere::bfs(const std::string& depart) const {
    std::unordered_set<std::string> visitees;
    std::queue<std::string> file;
    file.push(depart);

    while (!file.empty()) {
        std::string courant = file.front();
        file.pop();

        if (visitees.find(courant) == visitees.end()) {
            std::cout << courant << " ";
            visitees.insert(courant);

            for (const auto& voisin : salles.at(courant).voisins) {
                file.push(voisin);
            }
        }
    }

    std::cout << "\n";
}

std::vector<std::string> Fourmiliere::chercherCheminBFS(const std::string& debut, const std::string& fin) const {
    std::unordered_map<std::string, std::string> parent;
    std::queue<std::string> file;
    std::unordered_set<std::string> visite;

    file.push(debut);
    visite.insert(debut);

    while (!file.empty()) {
        std::string courant = file.front();
        file.pop();

        if (courant == fin) break;

        for (const auto& voisin : salles.at(courant).voisins) {
            if (!visite.count(voisin)) {
                parent[voisin] = courant;
                visite.insert(voisin);
                file.push(voisin);
            }
        }
    }

    std::vector<std::string> chemin;
    for (std::string at = fin; at != debut; at = parent[at]) {
        chemin.push_back(at);
    }
    chemin.push_back(debut);
    std::reverse(chemin.begin(), chemin.end());
    chemin.erase(chemin.begin());

    return chemin;
}

bool dfsUtil(const std::string& courant, const std::string& fin,
             std::unordered_set<std::string>& visite,
             std::unordered_map<std::string, std::string>& parent,
             const std::map<std::string, Salle>& salles) { // исправлено
    if (courant == fin) return true;

    visite.insert(courant);

    for (const auto& voisin : salles.at(courant).voisins) {
        if (!visite.count(voisin)) {
            parent[voisin] = courant;
            if (dfsUtil(voisin, fin, visite, parent, salles)) return true;
        }
    }

    return false;
}

std::vector<std::string> Fourmiliere::chercherCheminDFS(const std::string& debut, const std::string& fin) const {
    std::unordered_map<std::string, std::string> parent;
    std::unordered_set<std::string> visite;

    dfsUtil(debut, fin, visite, parent, salles);

    std::vector<std::string> chemin;
    for (std::string at = fin; at != debut; at = parent[at]) {
        chemin.push_back(at);
    }
    chemin.push_back(debut);
    std::reverse(chemin.begin(), chemin.end());
    chemin.erase(chemin.begin());

    return chemin;
}

void simulateurBFS(Fourmiliere& f) {
    for (auto& fourmi : f.fourmis) {
        auto chemin = f.chercherCheminBFS(fourmi.position, "Sd");
        fourmi.definirChemin(chemin);
    }

    int etape = 1;
    while (true) {
        bool auMoinsUnMouvement = false;
        std::vector<std::tuple<Fourmi*, std::string, std::string>> mouvements;

        for (auto& fourmi : f.fourmis) {
            if (!fourmi.aTermine()) {
                std::string actuelle = fourmi.position;
                std::string suivante = fourmi.prochaineSalle();
                if (f.getSalle(suivante).peutEntrer()) {
                    mouvements.emplace_back(&fourmi, actuelle, suivante);
                    auMoinsUnMouvement = true;
                }
            }
        }

        if (!auMoinsUnMouvement) break;

        std::cout << "Etape " << etape++ << "\n";
        for (auto& [ptr, de, vers] : mouvements) {
            f.getSalle(de).sortir();
            f.getSalle(vers).entrer();
            ptr->avancer();
            std::cout << ptr->nom << " - " << de << " --> " << vers << "\n";
        }
        std::cout << "\n";
    }
}

void Fourmiliere::reinitialiserOccupants() {
    for (auto& [_, salle] : salles) {
        salle.occupants = 0;
    }
    for (auto& fourmi : fourmis) {
        salles[fourmi.position].entrer();
    }
}

void simulateurDFS(Fourmiliere& f) {
    std::vector<std::string> chemin = f.chercherCheminDFS("Sv", "Sd");
    for (auto& fourmi : f.fourmis) {
        fourmi.definirChemin(chemin);
    }

    int etape = 1;
    while (true) {
        bool auMoinsUnMouvement = false;
        std::vector<std::tuple<Fourmi*, std::string, std::string>> mouvements;

        for (auto& fourmi : f.fourmis) {
            if (!fourmi.aTermine()) {
                std::string actuelle = fourmi.position;
                std::string suivante = fourmi.prochaineSalle();
                if (f.getSalle(suivante).peutEntrer()) {
                    mouvements.emplace_back(&fourmi, actuelle, suivante);
                    auMoinsUnMouvement = true;
                }
            }
        }

        if (!auMoinsUnMouvement) break;

        std::cout << "Etape " << etape++ << "\n";
        for (auto& [ptr, de, vers] : mouvements) {
            f.getSalle(de).sortir();
            f.getSalle(vers).entrer();
            ptr->avancer();
            std::cout << ptr->nom << " - " << de << " --> " << vers << "\n";
        }
        std::cout << "\n";
    }
}
