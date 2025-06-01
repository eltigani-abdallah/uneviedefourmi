

#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <vector>
#include "errcodes.h"
#include <algorithm>


class Room {
    public:
    int num=0;
    int capacity=0;
    int currentAmount=0;
    bool dormitory=false;
    bool deadend=false;
    std::vector<Room*> nextRoomList{};
    std::vector<Room*> prevRoomList{};

    Room(int num, int capacity=1, int currentAmount=0, bool dormitory=false);


    void addNextRoom(std::vector<Room*> rooms);
    void addPrevRoom(std::vector<Room*> rooms);

};

bool roomIsFull(Room* roomToCheck);



#endif //ROOM_H
