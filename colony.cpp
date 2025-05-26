
#include "colony.hpp"

void moveIntoRoom(int amount, Room* prevRoom,Room* nextRoom){

    if (prevRoom->currentAmount < amount) {
        std::cout<<"ERROR: amount exceeds available ants"<<std::endl;

    }
    else if (nextRoom->capacity < amount) {
        std::cout<<"not enough capacity in room number "<<nextRoom->num<<std::endl;
        exit(CAPACITY_EXCEEDED);
    }
    else {
        nextRoom->currentAmount += amount;
        prevRoom->currentAmount -= amount;

        std::cout << "F"<<amount<<"--R"<<prevRoom->num<<"--R"<<nextRoom->num<<std::endl;
    }
}

void showRoomPaths(std::vector<Room*> rooms) {
    for (Room* room: rooms) {
        if ( room->nextRoom.empty() == 0 ) {
            std::cout<<"Tunnels for room "<<room->num<<": "<<std::endl;

            for (Room* possPath :room->nextRoom) {
                std::cout<<possPath->num<<" ";
            }
            std::cout<<std::endl;
        } else {
            std::cout<<"room no. "<<room->num<<" is a dead end"<<std::endl;
        }
    }
}

void showStats(std::vector<Room*> rooms) {
    for (Room* room : rooms) {
        std::cout<<"R "<<room->num<<": "<<room->currentAmount<<"/"<<room->capacity<<std::endl;
    }

}


