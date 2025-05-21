

#ifndef SALLE_H
#define SALLE_H
#include <iostream>
#include <vector>


class Room {
    public:
    int num;
    int capacity;
    int currentAmount;
    std::vector<Room*> nextRoom;

    Room(int num, int capacity, int currentAmount=0);
    void moveIntoRoom(int amount, Room* prevRoom,Room* nextRoom);
    void showStats();
    void addNextRoom(Room* room);
};



#endif //SALLE_H
