
#include "colony.hpp"

void moveIntoRoom(int amountToSend, Room* prevRoom,Room* nextRoom){

    if (prevRoom->currentAmount < amountToSend) {
        std::cout<<"ERROR: amount To Send exceeds available ants"<<std::endl;
        exit(INVALID_MOVEMENT);

    }

    if (amountToSend<0) {
        std::cout<<"how the frick do you want me to send negative ants??"<<std::endl;
        exit(NEGATIVE_AMOUNT);
    }
    if (nextRoom->capacity < amountToSend) {
        std::cout<<"not enough capacity in room number "<<nextRoom->num<<std::endl;
        exit(CAPACITY_EXCEEDED);
    }

        nextRoom->currentAmount += amountToSend;
        prevRoom->currentAmount -= amountToSend;

        std::cout << "F"<<amountToSend<<"--R"<<prevRoom->num<<"--R"<<nextRoom->num<<std::endl;
}

void showRoomPaths(std::vector<Room*> rooms) {
    for (Room* room: rooms) {
        if ( room->nextRoomList.empty() == 0 ) {
            std::cout<<"Tunnels for room "<<room->num<<": "<<std::endl;

            for (Room* possPath :room->nextRoomList) {
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


