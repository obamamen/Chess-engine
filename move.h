#ifndef MOVE
#define MOVE

#include <iostream>
#include <cstdint>



enum Flag {
    NONE, ENPASSANTCAPTURE, CASTLING, PROMOTEQUEEN, PROMOTEROOK, PROMOTEBISHOP, PROMOTEKNIGHT, PAWNTWOFORWARD
};

class Move {
    public:
    int flag; //enum Flag

    int start; // 0-63
    int target; // 0-63

    int piece; // 0-11 for the pieces (WPAWN, BPAWN, WKNIGHT, BKNIGHT etc)

    Move(int s, int t); // constructor

    uint64_t getStart(); //start bitmap

    uint64_t getTarget(); //target bitmap
};



#endif