
#include "colony.hpp"

void moveIntoRoom(int amount, Room* prevRoom,Room* nextRoom){

    if (prevRoom->currentAmount < amount) {
        std::cout<<"ERROR: amount exceeds available ants"<<std::endl;
    }
    else if (nextRoom->capacity < amount) {
        std::cout<<"not enough capacity in room number "<<nextRoom->num<<std::endl;
    }
    else {
        nextRoom->currentAmount += amount;
        prevRoom->currentAmount -= amount;

        std::cout << "F"<<amount<<"--R"<<prevRoom->num<<"--R"<<nextRoom->num<<std::endl;
    }
}

void showRoomPaths(Room* room) {
    if ( room->nextRoom.empty() == 0 ) {
        std::cout<<"Tunnels for room "<<room->num<<": "<<std::endl;

        for (Room* possPath :room->nextRoom) {
            std::cout<<"room number: "<<possPath->num<<" ";
        }
        std::cout<<std::endl;
    } else {
        std::cout<<"looks like you're stuck, maybe go back?"<<std::endl;
    }
}

