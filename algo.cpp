#include "algo.h"


void fillNextRooms(Room* currentRoom) {

    for (Room* possRoom: currentRoom->nextRoomList) {
        int currentRoomAmount = currentRoom->currentAmount;

        int nextRoomEmptySpace= possRoom->capacity-possRoom->currentAmount;

        bool availableSpace=possRoom->currentAmount < possRoom->capacity;

        if (availableSpace) {
            if (nextRoomEmptySpace<=currentRoomAmount) {
                if (nextRoomEmptySpace==0) {
                    continue;
                }
                moveIntoRoom(nextRoomEmptySpace, currentRoom, possRoom);

            } else {
                if (currentRoomAmount==0) {
                    continue;
                }
                moveIntoRoom(currentRoomAmount, currentRoom, possRoom);

            }

        } else {
            std::cout <<"Room no."<< possRoom->num<<" is full"<<std::endl;
            break;
        }
        if (possRoom->dormitory==true && possRoom->currentAmount==possRoom->capacity) {
            std::cout<<"all the ants are asleep now"<<std::endl;
            //exit(0);
        }
        showStats({currentRoom,possRoom});
        //fillNextRooms(possRoom);
    }
}

bool checkForDeadEnd(Room* target) {
    if (target->nextRoomList.empty()==1 && target->dormitory==false) {
        std::cout<<"Room "<<target->num<<" has no possible paths"<<std::endl;
        return true;
    }
    for (Room* possRoom: target->nextRoomList) {
        if (possRoom->dormitory==true) {
            //std::cout<<"The road is clear!"<<std::endl;
            return false;
        } if (possRoom->nextRoomList.empty()==1) {
            std::cout<<"Room "<<possRoom->num<<" is a dead end "<<std::endl;
            return true;
        }
        checkForDeadEnd(possRoom);
    }
    return false;
}



bool pathsAreFull(Room* target) {
    int totalItems=target->nextRoomList.size();
    int itemCount=0;
    for (Room* possRoom: target->nextRoomList) {
        if (roomIsFull(possRoom)) {
            itemCount++;
        }
        if (itemCount==totalItems) {
            std::cout<<"all paths of Room no. "<<target->num<<" are full."<<std::endl;
            return true;
        }
    }
    return false;
}

void goToSleep(Room* start, Room* goal) {
    Room* origin=start;
    if (checkForDeadEnd(start)==false) {
        int i=1;

        while (roomIsFull(goal)==false) {
            while (start->currentAmount>0) {

                std::cout <<"+++++Step "<<i<<"+++++"<<std::endl;
                fillNextRooms(start);
                i++;
                // if (i==10) {
                //     exit(INFINITE_LOOP);
                // }

                if (pathsAreFull(start)==true) {
                    break;
                }
            }



            for (Room* possRoom: start->nextRoomList) {
                // if (start==origin) {
                //     std::cout<<"entered replacement loop, start unchanged"<<std::endl;
                // }
                if (possRoom->currentAmount==0 || start->currentAmount==0) {
                    start=origin;
                    //std::cout<<"Room no. "<<start->num<<" of go to sleep changed to origin"<<std::endl;
                }
                if (possRoom->dormitory==false && possRoom->currentAmount>0) {
                    start=possRoom;
                    //std::cout<<"start of go to sleep changed to room no."<<start->num<<std::endl;
                    break;

                }

            }
        }
    }
}


