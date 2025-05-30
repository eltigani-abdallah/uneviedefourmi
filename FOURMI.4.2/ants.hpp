#ifndef FOURMIS_HPP
#define FOURMIS_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

struct Salle {
    std::string nom;
    int capacite;
    int courant = 0;
    std::vector<std::string> voisins;
};

struct Fourmi {
    int id;
    std::vector<std::string> chemin;
    int position = 0;
};

void bfs_trouver_chemins(const std::unordered_map<std::string, Salle>& graphe, const std::string& debut, const std::string& fin);
void dfs_trouver_chemins(const std::unordered_map<std::string, Salle>& graphe, const std::string& debut, const std::string& fin);
void simulerDeplacementDesFourmis(std::unordered_map<std::string, Salle>& graphe, int nombreDeFourmis);



#endif // FOURMIS_HPP
