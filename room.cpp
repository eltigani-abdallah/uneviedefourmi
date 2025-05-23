#include "room.hpp"


Room::Room(int num,int capacity, int currentAmount) {
    this->num = num;
    this->capacity = capacity;
    this->currentAmount = currentAmount;
    if (this->capacity < this->currentAmount) {
        std::cerr << "Capacity exceeded on room " <<this->num<< std::endl;
        exit(1);
    }
};

void Room::showStats() {
    std::cout<<"R "<<this->num<<": "<<this->currentAmount<<"/"<<this->capacity<<std::endl;
}

void Room::addNextRoom(std::vector<Room*> rooms) {
    for (Room* listItem : rooms) {
        this->nextRoom.push_back(listItem);
    }
}





