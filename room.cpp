#include "room.hpp"


Room::Room(int num,int capacity, int currentAmount) {
    this->num = num;
    this->capacity = capacity;
    this->currentAmount = currentAmount;
    if (this->capacity < this->currentAmount) {
        std::cerr << "Capacity exceeded on room " <<this->num<< std::endl;
        exit(INVALID_CONSTRUCTOR);
    }
    if (this->currentAmount < 0) {
        std::cerr<<this->num<< "has negative ants, physically impossible"<<std::endl;
        exit(NEGATIVE_AMOUNT);
    }
};


void Room::addNextRoom(std::vector<Room*> rooms) {
    for (Room* listItem : rooms) {
        if (std::find(this->nextRoom.begin(), this->nextRoom.end(), listItem)!=this->nextRoom.end()) {
            std::cout<<"room number: "<<listItem->num<<"is already in the list. skipping addition"<<std::endl;
            continue;
        }
        this->nextRoom.push_back(listItem);
    }
}





