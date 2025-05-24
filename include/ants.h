#ifndef ANTS_H
#define ANTS_H

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <iostream>
#include <algorithm>

// class room
class Room {
public:
    std::string name;
    int capacity;
    int current_occupants;

    Room(std::string name, int capacity)
        : name(std::move(name)), capacity(capacity), current_occupants(0) {}

    bool canAcceptAnt(int value) const { return current_occupants + value <= capacity; }
    void arrive() { current_occupants++; }
    void depart() { current_occupants--; }
};

//class tunnel
class Tunnel {
public:
    std::shared_ptr<Room> from_room;
    std::shared_ptr<Room> to_room;

    Tunnel(std::shared_ptr<Room> from, std::shared_ptr<Room> to)
        : from_room(std::move(from)), to_room(std::move(to)) {}
};

//class ant
class Ant {
public:
    int id;
    std::shared_ptr<Room> current_room;

    Ant(int id, std::shared_ptr<Room> starting_room)
        : id(id), current_room(std::move(starting_room)) {}
};

// class anthill
class AntHill {
private:
    std::unordered_map<std::string, std::shared_ptr<Room>> rooms;
    std::vector<std::shared_ptr<Tunnel>> tunnels;
    std::vector<std::shared_ptr<Ant>> ants;

public:
    void addRoom(std::string name, int capacity);
    void addTunnel(std::string from, std::string to);
    void addAnt(std::shared_ptr<Ant> ant);
    void simulateMovement();

    std::shared_ptr<Room> getRoom(const std::string& name) {
        auto it = rooms.find(name);
        if (it != rooms.end()) {
            return it->second;
        }
        return nullptr;
    }
};

#endif