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

//Class Room
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

// Class Tunnel
class Tunnel {

private:
std::shared_ptr<Room> from_room;
std::shared_ptr<Room> to_room;

public:
Tunnel(std::shared_ptr<Room> from_room, std::shared_ptr<Room> to_room);
~Tunnel() = default;

std::shared_ptr<Room> getFromRoom() const;
std::shared_ptr<Room> getToRoom() const;
};

//Class Pathnode
class PathNode {

private:
std::shared_ptr<Room> room;
std::shared_ptr<PathNode> next;

public:
PathNode(std::shared_ptr<Room> room);
~PathNode() = default;

std::shared_ptr<Room> getRoom() const;
std::shared_ptr<PathNode> getNext() const;
void setNext(std::shared_ptr<PathNode> next);
};

#endif //ANTS_H
