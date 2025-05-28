#include "room.hpp"


Room::Room(int num,int capacity, int currentAmount, bool dormitory) {
    this->num = num;
    this->capacity = capacity;
    this->currentAmount = currentAmount;
    this->dormitory = dormitory;
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
        if (std::find(this->nextRoomList.begin(), this->nextRoomList.end(), listItem)!=this->nextRoomList.end()) {
            std::cout<<"room number: "<<listItem->num<<"is already in the list. skipping addition"<<std::endl;
            continue;
        }
        this->nextRoomList.push_back(listItem);
    }
}

bool roomIsFull(Room* roomToCheck) {
    if (roomToCheck->currentAmount == roomToCheck->capacity) {
        return true;
    }
    return false;
}





