
#ifndef ALGO_H
#define ALGO_H

#include "colony.hpp"

//void goToSleep(Room* start, Room* goal);

void fillNextRooms(Room* currentRoom);

bool isDeadEnd(Room* deadEnd);

void markDeadEnds(Room* target);

void goToSleep(Room* start, Room* goal);

bool pathsAreFull(Room* target);



#endif //ALGO_H
