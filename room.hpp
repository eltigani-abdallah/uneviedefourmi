

#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <vector>


class Room {
    public:
    int num;
    int capacity;
    int currentAmount;
    std::vector<Room*> nextRoom;

    Room(int num, int capacity=1, int currentAmount=0);
    void showStats();
    void addNextRoom(std::vector<Room*> rooms);
};



#endif //ROOM_H
