

#ifndef COLONY_H
#define COLONY_H

#include "room.hpp"


void moveIntoRoom(int amount, Room* prevRoom,Room* nextRoom);

void showRoomPaths(std::vector<Room*> rooms);

void showStats(std::vector<Room*> rooms);

#endif //COLONY_H
