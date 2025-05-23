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
Tunnel::Tunnel(const std::shared_ptr<Room> from, std::shared_ptr<Room> to) : from_room(from), to_room(to) {}
std::shared_ptr<Room> Tunnel::getFromRoom() const { return from_room; }
std::shared_ptr<Room> Tunnel::getToRoom() const { return to_room; }

//PathNode

//Ant

//AntHill

