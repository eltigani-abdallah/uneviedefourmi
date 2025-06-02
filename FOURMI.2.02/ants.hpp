#ifndef ANTS_HPP
#define ANTS_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <queue>
#include <stack>
#include <unordered_set>

// The Room class represents a room in the anthill
class Room {
private:
    std::string name;
    int capacity;
    int current_occupants;

public:
    Room(std::string name, int capacity);

    std::string getName() const;
    int getCapacity() const;
    int getCurrentOccupants() const;

    bool canAcceptAnt(int value) const;
    void arrive(int value = 1);
    void depart(int value = 1);
    bool isEmpty() const;
    bool isFull() const;
};

// The Tunnel class represents a tunnel between rooms
class Tunnel {
private:
    std::shared_ptr<Room> from_room;
    std::shared_ptr<Room> to_room;

public:
    Tunnel(std::shared_ptr<Room> from, std::shared_ptr<Room> to);

    std::shared_ptr<Room> getFromRoom() const;
    std::shared_ptr<Room> getToRoom() const;
};

// The Ant class represents an ant
class Ant {
private:
    int id;
    std::shared_ptr<Room> current_room;

public:
    Ant(int id, std::shared_ptr<Room> starting_room);

    int getId() const;
    std::shared_ptr<Room> getCurrentRoom() const;
    void setCurrentRoom(std::shared_ptr<Room> room);
};

// The AntHill class represents the anthill
class AntHill {
private:
    std::unordered_map<std::string, std::shared_ptr<Room>> rooms;
    std::vector<std::shared_ptr<Tunnel>> tunnels;
    std::vector<std::shared_ptr<Ant>> ants;

public:
    void addRoom(std::string name, int capacity);
    void addTunnel(std::string from, std::string to);
    void addAnt(std::shared_ptr<Ant> ant);
    void simulateMovementWithBFS(); // Simulate ant movement using Breadth-First Search
    void simulateMovementWithDFS(); // Simulate ant movement using Depth-First Search
    bool canReachRoom(const std::shared_ptr<Room>& startRoom, const std::string& targetRoomName) const;
    std::shared_ptr<Room> getRoom(const std::string& name);
};

// Functions to simulate ant movement using BFS and DFS
void simulateurBFS(AntHill& anthill);
void simulateurDFS(AntHill& anthill);

#endif
