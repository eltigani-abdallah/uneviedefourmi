#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

class Salle {
public:
    std::string nom;
    int capacite;
    std::vector<std::string> connexions;
    Salle() : nom(""), capacite(0) {}
    Salle(const std::string& nom, int capacite = 1);
    void ajouterConnexion(const std::string& destination);
};

class Tunnel {
public:
    std::string depuis;
    std::string vers;

    Tunnel(const std::string& d, const std::string& v);
};

class Fourmi {
public:
    std::string nom;
    std::string position;

    Fourmi(const std::string& nom, const std::string& start);
};

class Fourmiliere {
public:
    std::unordered_map<std::string, Salle> salles;
    std::vector<Fourmi> fourmis;

    void ajouterSalle(const std::string& nom, int capacite = 1);
    void ajouterTunnel(const std::string& depuis, const std::string& vers);
    void ajouterFourmi(const std::string& nom, const std::string& start);
    void afficher() const;
    void bfs(const std::string& depart) const;
    Salle& getSalle(const std::string& nom); // Ajoute
};
