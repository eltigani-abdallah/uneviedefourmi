//
// Created by chris on 22/05/2025.
//

#ifndef ANTS_H
#define ANTS_H

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <list>

class Room {
private:
std::string name;
int capacity;
int current_occupants;

public:
Room(std::string name, int capacity);
~Room() = default;

const std::string& getName() const;
int getCapacity() const;
int getCurrentOccupants() const;
void setCurrentOccupants(int value);

bool canAcceptAnt() const;
};

#endif //ANTS_H
