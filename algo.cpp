#include "algo.h"


void fillNextRooms(Room* currentRoom) {

    for (Room* possRoom: currentRoom->nextRoomList) {
        if (possRoom->deadend==true) {
            continue;
        }
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
bool isDeadEnd(Room* deadEnd) {
    if (deadEnd->nextRoomList.empty()==true && deadEnd->dormitory==false) {
        deadEnd->deadend=true;
        return true;
    }
    return false;
}

void markDeadEnds(Room* target) {
    if (isDeadEnd(target)==true && target->dormitory==false) {
        std::cout<<"Room "<<target->num<<" has no possible paths"<<std::endl;
    }

    int checkedCount=0;


    for (Room* possRoom: target->nextRoomList) {
        markDeadEnds(possRoom);

        int checkedRoomNum = possRoom->num;
        bool isDorm=possRoom->dormitory;
        bool isDeadEnd=possRoom->deadend;

        if (isDorm==true) {
            //std::cout<<"Dorm reached from room number: "<<target->num<<std::endl;
            continue;
        }

        if (isDeadEnd==true && isDorm==false) {
            std::cout<<"Room "<<checkedRoomNum<<" is a dead end "<<std::endl;
            checkedCount++;

        }
    }

    int nexRoomsCount=target->nextRoomList.size();
    bool targetIsDorm=target->dormitory;
    int targetNum=target->num;

    if (checkedCount==nexRoomsCount && targetIsDorm==false) {
        target->deadend=true;
        std::cout<<"room number: "<<targetNum<<" has been marked as a dead end because all children are dead"<<std::endl;
        std::cout<<"type F in the chat to pay respects"<<std::endl;
    }

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
    markDeadEnds(start);
    Room* origin=start;
        int i=1;
        while (roomIsFull(goal)==false) {
            while (start->currentAmount>0) {
                if (start->deadend==true) {
                    continue;
                }
                std::cout <<"+++++Step "<<i<<"+++++"<<std::endl;
                fillNextRooms(start);
                i++;
                if (i==100) {
                    exit(INFINITE_LOOP);
                }

                if (pathsAreFull(start)==true) {
                    break;
                }
            }

            for (Room* possRoom: start->nextRoomList) {
                // if (start==origin) {
                //     std::cout<<"entered replacement loop, start unchanged"<<std::endl;
                // }
                if (possRoom->deadend==true) {
                    continue;
                }
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



