#include "ants.hpp"
#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include <queue>
#include <vector>

// Implementation of Room class methods
Room::Room(std::string name, int capacity) : name(name), capacity(capacity), current_occupants(0) {}

std::string Room::getName() const {
    return name;
}

int Room::getCapacity() const {
    return capacity;
}

int Room::getCurrentOccupants() const {
    return current_occupants;
}

bool Room::canAcceptAnt(int value) const {
    // Check if the room can accept a given number of ants
    return current_occupants + value <= capacity;
}

void Room::arrive(int value) {
    // Increase the number of occupants if the room can accept the ants
    if (canAcceptAnt(value)) {
        current_occupants += value;
    } else {
        std::cout << "Room " << name << " cannot accept more ants." << std::endl;
    }
}

void Room::depart(int value) {
    // Decrease the number of occupants if there are enough ants to depart
    if (current_occupants - value >= 0) {
        current_occupants -= value;
    } else {
        std::cout << "Room " << name << " has no ants to depart." << std::endl;
    }
}

bool Room::isEmpty() const {
    // Check if the room is empty
    return current_occupants == 0;
}

bool Room::isFull() const {
    // Check if the room is full
    return current_occupants == capacity;
}

// Implementation of Tunnel class methods
Tunnel::Tunnel(std::shared_ptr<Room> from, std::shared_ptr<Room> to) : from_room(from), to_room(to) {}

std::shared_ptr<Room> Tunnel::getFromRoom() const {
    return from_room;
}

std::shared_ptr<Room> Tunnel::getToRoom() const {
    return to_room;
}

// Implementation of Ant class methods
Ant::Ant(int id, std::shared_ptr<Room> starting_room) : id(id), current_room(starting_room) {}

int Ant::getId() const {
    return id;
}

std::shared_ptr<Room> Ant::getCurrentRoom() const {
    return current_room;
}

void Ant::setCurrentRoom(std::shared_ptr<Room> room) {
    current_room = room;
}

// Implementation of AntHill class methods
void AntHill::addRoom(std::string roomName, int roomCapacity) {
    // Add a new room to the anthill
    auto room = std::make_shared<Room>(roomName, roomCapacity);
    rooms.insert(std::make_pair(roomName, room));
}

void AntHill::addTunnel(std::string sourceRoomName, std::string destinationRoomName) {
    // Add a new tunnel connecting two rooms
    auto sourceRoom = rooms.find(sourceRoomName)->second;
    auto destinationRoom = rooms.find(destinationRoomName)->second;
    auto tunnel = std::make_shared<Tunnel>(sourceRoom, destinationRoom);
    tunnels.emplace_back(tunnel);
}

void AntHill::addAnt(std::shared_ptr<Ant> newAnt) {
    // Add a new ant to the anthill
    ants.emplace_back(newAnt);
    auto currentRoom = newAnt->getCurrentRoom();
    currentRoom->arrive();
}

bool AntHill::canReachRoom(const std::shared_ptr<Room>& startRoom, const std::string& targetRoomName) const {
    // Check if a room can be reached from a starting room using BFS
    std::unordered_set<std::shared_ptr<Room>> visited;
    std::queue<std::shared_ptr<Room>> queue;
    queue.push(startRoom);
    visited.insert(startRoom);

    while (!queue.empty()) {
        auto currentRoom = queue.front();
        queue.pop();

        if (currentRoom->getName() == targetRoomName) {
            return true;
        }

        for (const auto& tunnel : tunnels) {
            if (tunnel->getFromRoom() == currentRoom && visited.find(tunnel->getToRoom()) == visited.end()) {
                visited.insert(tunnel->getToRoom());
                queue.push(tunnel->getToRoom());
            }
        }
    }
    return false;
}

std::shared_ptr<Room> AntHill::getRoom(const std::string& name) {
    // Retrieve a room by its name
    auto it = rooms.find(name);
    if (it != rooms.end()) {
        return it->second;
    }
    return nullptr;
}

void AntHill::simulateMovementWithBFS() {
    // Simulate ant movement using BFS
    int stepCount = 0;
    bool simulationActive = true;

    while (simulationActive) {
        std::vector<std::string> stepMoves;
        bool anyMoves = false;
        std::vector<std::shared_ptr<Ant>> completedAnts;

        for (auto antIt = ants.begin(); antIt != ants.end(); ++antIt) {
            auto ant = *antIt;
            if (ant->getCurrentRoom()->getName() == "Sd") {
                completedAnts.push_back(ant);
                continue;
            }

            std::shared_ptr<Tunnel> tunnelSelected = nullptr;
            std::vector<std::shared_ptr<Tunnel>> availableTunnels;

            for (const auto& tunnel : tunnels) {
                if (tunnel->getFromRoom() == ant->getCurrentRoom() && tunnel->getToRoom()->canAcceptAnt(1)) {
                    availableTunnels.push_back(tunnel);
                }
            }

            for (auto tunnelIt = availableTunnels.begin(); tunnelIt != availableTunnels.end(); ++tunnelIt) {
                auto tunnel = *tunnelIt;
                if (tunnel->getToRoom()->getName() == "Sd") {
                    tunnelSelected = tunnel;
                    break;
                } else if (!tunnelSelected && canReachRoom(tunnel->getToRoom(), "Sd")) {
                    tunnelSelected = tunnel;
                }
            }

            if (!tunnelSelected && !availableTunnels.empty()) {
                tunnelSelected = availableTunnels.front();
            }

            if (tunnelSelected) {
                std::string moveDescription = "  F " + std::to_string(ant->getId()) + "  -  " + ant->getCurrentRoom()->getName() + " --> " + tunnelSelected->getToRoom()->getName();
                stepMoves.push_back(moveDescription);

                ant->getCurrentRoom()->depart();
                ant->setCurrentRoom(tunnelSelected->getToRoom());
                ant->getCurrentRoom()->arrive();

                anyMoves = true;
            }
        }

        for (auto& ant : completedAnts) {
            ants.erase(std::remove(ants.begin(), ants.end(), ant), ants.end());
        }

        if (anyMoves) {
            stepCount++;
            std::cout << "\nStep " << stepCount << ":" << std::endl;
            for (const auto& move : stepMoves) {
                std::cout << move << std::endl;
            }
        }
        simulationActive = !ants.empty();
    }
}

void AntHill::simulateMovementWithDFS() {
    // Simulate ant movement using DFS
    int steps = 0;
    std::vector<std::string> movements;

    for (auto& ant : ants) {
        std::stack<std::shared_ptr<Room>> stack;
        std::unordered_set<std::shared_ptr<Room>> visited;
        std::unordered_map<std::shared_ptr<Room>, std::shared_ptr<Room>> parent;

        stack.push(ant->getCurrentRoom());
        visited.insert(ant->getCurrentRoom());
        parent[ant->getCurrentRoom()] = nullptr;

        while (!stack.empty()) {
            auto currentRoom = stack.top();
            stack.pop();

            if (currentRoom->getName() == "Sd") {
                break;
            }

            for (auto it = tunnels.rbegin(); it != tunnels.rend(); ++it) {
                const auto& tunnel = *it;
                if (tunnel->getFromRoom() == currentRoom && visited.find(tunnel->getToRoom()) == visited.end()) {
                    visited.insert(tunnel->getToRoom());
                    stack.push(tunnel->getToRoom());
                    parent[tunnel->getToRoom()] = currentRoom;
                }
            }
        }

        std::vector<std::shared_ptr<Room>> path;
        auto current = getRoom("Sd");
        while (current != nullptr) {
            path.push_back(current);
            current = parent[current];
        }

        std::reverse(path.begin(), path.end());

        for (size_t i = 0; i < path.size() - 1; ++i) {
            movements.push_back("  F " + std::to_string(ant->getId()) + "  - " + path[i]->getName() + " --> " + path[i+1]->getName());
        }
    }

    for (size_t step = 0; step < movements.size(); ++step) {
        std::cout << "Step " << step + 1 << ":" << std::endl;
        std::cout << movements[step] << std::endl;
    }
}

void simulateurBFS(AntHill& anthill) {
    // Function to simulate ant movement using BFS
    anthill.simulateMovementWithBFS();
}

void simulateurDFS(AntHill& anthill) {
    // Function to simulate ant movement using DFS
    anthill.simulateMovementWithDFS();
}
