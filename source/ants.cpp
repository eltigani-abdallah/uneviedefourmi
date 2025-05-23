//
// Created by chris on 22/05/2025.
//
#include "ants.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <memory>

//Room
Room::Room(const std::string& name, int capacity) : name(name), capacity(capacity), current_occupants(0) {}
const std::string& Room::getName() const { return name; }
int Room::getCapacity() const { return capacity; }
int Room::getCurrentOccupants() const { return current_occupants; }
void Room::setCurrentOccupants(int value) {current_occupants = value;}

bool Room::canAcceptAnt(int value) {return current_occupants < capacity;}

//Tunnel

//PathNode

//Ant

//AntHill

