#include "room.hpp"


Room::Room(int num,int capacity, int currentAmount) {
    this->num = num;
    this->capacity = capacity;
    this->currentAmount = currentAmount;
};

void Room::showStats() {
    std::cout<<"R "<<this->num<<": "<<this->currentAmount<<"/"<<this->capacity<<std::endl;
}

void Room::addNextRoom(Room* room) {
    nextRoom.push_back(room);
}

