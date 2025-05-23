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
AntHill::AntHill() {}

void AntHill::addRoom(const std::string& name, int capacity) {
rooms[name] = std::make_shared<Room>(name, capacity);}

void AntHill::addTunnel(const std::string& from, cosnst std::string& to) {
tunnels.push_back(std::make_shared<Tunnel>(rooms[from], rooms[to]));}

void AntHill::addAnt(std::shared_ptr<Ant> ant) { ants.push_back(ant); }
std::shared_ptr<Room> AntHill::getRoom(const std::string& name) {
return rooms[name];}

//Get adjacent room
std::vector<std::shared_ptr<Room>>
AntHill::getAdjacentRooms(const std::string& name) {
std::vector<std::shared_ptr<Room>> adjacent_rooms;
for (const auto& tunnel : tunnels) {
if (tunnel->getFromRoom()->getName() == room_name) {
adjacent_rooms.push_back(tunnel->getToRoom()); }
}
return adjacent_rooms;
}

//Compute optimal path
std::shared_ptr<PathNode> AntHill::computerOptimalPath(const std::string& start, const std::string& end) {
std::unordered_map<std::string, std::shared_ptr<PathNode>> visited;
std::queue<std::shared_ptr<PathNode>> queue;

auto start_room = getRoom(start);
auto start_node = std::make_shared<PathNode>(start_room);
visited[start] = start_node;
queue.push(start_node);

while (!queue.empty()) {
auto current_node = queue.front();
queue.pop();
auto current_room = current_node->getRoom();
if (current_room->getName() == end) {
return current_node;
}
auto adjacent_rooms = getAdjacentRooms(current_room->getName());
for (const auto& room : adjacent_rooms) {
if (visited.find(room->getName()) == visited.end()) {
auto new_node = std::make_shared<PathNode>(room);
visited[room->getName()] = new_node;
queue.push(new_node);
}
}
}
return nullptr;
}

//Simulate movement
void AntHill::simulateMovement(){
int steps = 0;

while (!ants.empty()) {
std::vector<std::shared_ptr<PathNode>> next_nodes;
std::vector<std::string> movements;

//Calculate next node for each ant
for (const auto& ant : ants) {
auto current_node = ant->getCurrentPathNode();
auto current_room = current_node->getRoom();
std::string movement;
if (current_room->getName() == "Sd") {
next_nodes.push_back(current_node);
continue;
}
auto adjacent_rooms = getAdjacentRooms(current_room->getName());
for (const auto& room : adjacent_rooms) {
auto new_node = std::make_shared<PathNode>(room);
new_node->setNext(current_node);
next_nodes.push_back(new_node);
movement = "f" + std::to_string(ant->getId()) + "-" + current_room->getName() +"->" + room->getName();
movements.push_back(movement);
break;
}
}
if (next-nodes.sizes() != ants.size()) {
next_nodes.push_back(current_node);
}
}
//



//Print state

