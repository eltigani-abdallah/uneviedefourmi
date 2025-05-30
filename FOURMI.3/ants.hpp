#pragma once
#include <string>
#include <vector>
#include <map>

// ===== Salle =====
class Salle {
public:
    std::string nom;
    int capacite;
    int occupants;
    std::vector<std::string> voisins;

    Salle(); // Конструктор по умолчанию — необходим для std::map
    Salle(const std::string& nom, int capacite);
    void ajouterConnexion(const std::string& destination);
    bool peutEntrer() const;
    void entrer();
    void sortir();
};

// ===== Tunnel =====
class Tunnel {
public:
    std::string depuis, vers;
    Tunnel(const std::string& d, const std::string& v);
};

// ===== Fourmi =====
class Fourmi {
public:
    std::string nom;
    std::string position;
    std::vector<std::string> chemin;

    Fourmi(const std::string& nom, const std::string& start);
    bool aTermine() const;
    void definirChemin(const std::vector<std::string>& c);
    std::string prochaineSalle() const;
    void avancer();
};

// ===== Fourmiliere =====
class Fourmiliere {
public:
    std::map<std::string, Salle> salles;
    std::vector<Fourmi> fourmis;

    void ajouterSalle(const std::string& nom, int capacite);
    void ajouterTunnel(const std::string& depuis, const std::string& vers);
    void ajouterFourmi(const std::string& nom, const std::string& start);
    void afficher() const;
    void bfs(const std::string& depart) const;
    void reinitialiserOccupants();
    Salle& getSalle(const std::string& nom);

    std::vector<std::string> chercherCheminBFS(const std::string& debut, const std::string& fin) const;
    std::vector<std::string> chercherCheminDFS(const std::string& debut, const std::string& fin) const;
};

// ===== simulateurs =====
void simulateur(Fourmiliere& f);
void simulateurBFS(Fourmiliere& f);
void simulateurDFS(Fourmiliere& f);