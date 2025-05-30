#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <vector>
#include <chrono>
#include <set>
#include "ants.hpp"
#include <algorithm>

using namespace std;


vector<string> bfs(Fourmiliere& f, const string& start, const string& end) {
    unordered_map<string, string> parent;
    queue<string> q;
    set<string> visited;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        string current = q.front(); q.pop();
        if (current == end) break;

        for (auto& neighbor : f.getVoisins(current)) {
            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    // Построение пути
    vector<string> path;
    string current = end;
    while (current != start) {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    return path;
}

void simulation(Fourmiliere& f, vector<vector<string>> chemins) {
    unordered_map<string, int> occupation = {
        {"Sv", 5}, {"S1", 0}, {"S2", 0}, {"Sd", 0}
    };

    struct Fourmi {
        string nom;
        string position;
        queue<string> chemin;
    };

    vector<Fourmi> fourmis;
    for (int i = 0; i < chemins.size(); ++i) {
        Fourmi fmi;
        fmi.nom = "f" + to_string(i + 1);
        fmi.position = chemins[i][0];
        for (size_t j = 1; j < chemins[i].size(); ++j) {
            fmi.chemin.push(chemins[i][j]);
        }
        fourmis.push_back(fmi);
    }

    int etape = 1;
    while (true) {
        bool moved = false;
        string etapeLog;

        for (auto& fourmi : fourmis) {
			if (!fourmi.chemin.empty()) {
            	string next = fourmi.chemin.front();
        		int cap = f.getSalle(next).capacite;
                if (occupation[next] < cap) {
                    occupation[fourmi.position]--;
                    occupation[next]++;
                    etapeLog += fourmi.nom + " - " + fourmi.position + " --> " + next + "\n";
                    fourmi.position = next;
                    fourmi.chemin.pop();
                    moved = true;
                }
            }
        }
        if (!moved) break;
        cout << "\netape " << etape++ << "\n" << etapeLog;
    }
}

int main() {
    Fourmiliere fourmiliere;
    fourmiliere.ajouterSalle("Sv", 5);
    fourmiliere.ajouterSalle("S1", 1);
    fourmiliere.ajouterSalle("S2", 1);
    fourmiliere.ajouterSalle("Sd", 5);

    fourmiliere.ajouterTunnel("Sv", "S1");
    fourmiliere.ajouterTunnel("S1", "S2");
    fourmiliere.ajouterTunnel("S2", "Sd");
    fourmiliere.ajouterTunnel("Sv", "Sd");

    cout << "=== Variante 1 : Tous directement ===\n";
    auto chemin_direct = bfs(fourmiliere, "Sv", "Sd");
    vector<vector<string>> chemins1(5, chemin_direct);

    auto start1 = chrono::high_resolution_clock::now();
    simulation(fourmiliere, chemins1);
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double> duration1 = end1 - start1;
    cout << "\nTemps d'execution (Variante 1): " << duration1.count() << " secondes\n";

    cout << "\n=== Variante 2 : Un seul fait un detour ===\n";
    vector<vector<string>> chemins2;
    for (int i = 0; i < 5; ++i) {
        if (i == 1) chemins2.push_back(bfs(fourmiliere, "Sv", "Sd"));
        else chemins2.push_back(chemin_direct);
    }
    chemins2[1] = {"Sv", "S1", "S2", "Sd"};

    auto start2 = chrono::high_resolution_clock::now();
    simulation(fourmiliere, chemins2);
    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double> duration2 = end2 - start2;
    cout << "\nTemps d'execution (Variante 2): " << duration2.count() << " secondes\n";

    return 0;

}
