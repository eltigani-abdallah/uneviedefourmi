

#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <vector>
#include "errcodes.h"
#include <algorithm>


class Room {
    public:
    int num;
    int capacity;
    int currentAmount;
    bool dormitory;
    std::vector<Room*> nextRoomList;

    Room(int num, int capacity=1, int currentAmount=0, bool dormitory=false);


    void addNextRoom(std::vector<Room*> rooms);

};

bool roomIsFull(Room* roomToCheck);



#endif //ROOM_H
