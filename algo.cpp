#include "algo.h"


void fillNextRooms(Room* currentRoom) {

    int currentAmount = currentRoom->currentAmount;

    for (Room* possRoom: currentRoom->nextRoom) {

        int nextEmptySpace= possRoom->capacity-possRoom->currentAmount;

        bool availableSpace=possRoom->currentAmount < possRoom->capacity;

        if (availableSpace && currentAmount >= nextEmptySpace) {
            moveIntoRoom(nextEmptySpace, currentRoom, possRoom);
        }
        //showStats({possRoom});
    }
}

void checkForDeadEnd(Room* )

// void headToGoal(Room* start, Room* goal) {
//     int i=0;
//
//     while (goal->currentAmount < goal->capacity) {
//         std::cout<<"+++++E"<<i<<"+++++"<<std::endl;
//         while (start->currentAmount >0) {
//             for (Room* nextRoom: start->nextRoom) {
//                 if (nextRoom->nextRoom.empty()==1 && nextRoom!=goal) {
//                     exit(DEAD_END);
//                 }
//                 if (nextRoom->currentAmount < nextRoom->capacity && nextRoom->nextRoom.empty()==0) {
//                     if (start->currentAmount >=nextRoom->capacity-nextRoom->currentAmount) {
//                         moveIntoRoom(nextRoom->capacity-nextRoom->currentAmount, start, nextRoom);
//                     } else {
//                         continue;
//                     }
//                 }
//                 if (nextRoom->nextRoom.empty()==0) {
//                     headToGoal(nextRoom, goal);
//                 }
//             }
//
//
//         }
//         showStats({start, goal});
//         i++;
//     }
//     std::cout<<"all ants are now asleep, congratulations!"<<std::endl;
//
// }
