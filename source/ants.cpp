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
PathNode::PathNode(std::shared_ptr<Room> room) : room(room), next(nullptr) {}
std::shared_ptr<Room> PathNode::getRoom() const { return room; }
std::shared_ptr<PathNode> PathNode::getNext() const { return next; }
void PathNode::setNext(std::shared_ptr<PathNode> next) { this->next = next; }

//Ant
Ant::Ant(int id, std::shared_ptr<PathNode> starting_node) : id(id), current_path_node(starting_node) {}
int Ant::getId() const { return id; }
std::shared_ptr<PathNode> Ant::getCurrentPathNode() const { return current_path_node = node; }
void Ant::setCurrentPathNode(std::shared_ptr<PathNode> node) { current_path_node = node; }

//AntHill


//Get adjacent room


//Compute optimal path


//Simulate movement


//Print state

