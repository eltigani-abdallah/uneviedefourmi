
#include "antColony.hpp"

void moveIntoRoom(int amount, Room* prevRoom,Room* nextRoom){
    if (nextRoom->capacity >= amount){
        nextRoom->currentAmount += amount;
        prevRoom->currentAmount -= amount;

        std::cout << "F"<<amount<<"--R"<<prevRoom->num<<"--R"<<nextRoom->num<<std::endl;
    } else{
        std::cout<<"too many ants in room number "<<nextRoom->num<<std::endl;
    }
}

