#include "algo.h"


int main() {
    //colony 0
    /*Room start(0, 2, 2);
    Room r1(1);
    Room r2(2);
    Room end(3, 2, 0, true);

    start.addNextRoom({&r1, &r2});
    r1.addNextRoom({&end});
    r2.addNextRoom({&end});

    goToSleep(&start, &end);*/

    //colony 1
    /*Room start(0, 5, 5);
    Room r1(1);
    Room r2(2);
    Room end(3, 5, 0, true);

    start.addNextRoom({&r1});
    r1.addNextRoom({&r2});
    r2.addNextRoom({&end});

    goToSleep(&start, &end);*/


    //colony 2
    /*Room start(0, 5, 5);
    Room r1(1);
    Room r2(2);
    Room end(3, 5, 0, true);

    start.addNextRoom({&r1, &r2});
    r1.addNextRoom({&end});
    r2.addNextRoom({&end});

    goToSleep(&start, &end);*/

    //colony 3
    Room start(0, 5,5);
    Room r1(1);
    Room r2(2);
    Room r3(3);
    Room r4(4);
    Room end(5, 5, 0, true);

    start.addNextRoom({&r1});
    r1.addNextRoom({&r2, &r4});
    r2.addNextRoom({&r3});
    r4.addNextRoom({&end});



    goToSleep(&start, &end);
    //std::cout<<markDeadEnds(&start)<<std::endl;

    return 0;
}