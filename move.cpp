#include <iostream>
#include <cstdint>

#include "move.h"
#include "bit.h"

Move::Move(int s, int t) {
    start = s;
    target = t;
    //piece = p;
}

uint64_t Move::getStart() {
    return setBit(0ULL, start);
}



uint64_t Move::getTarget() {
    return setBit(0ULL, target);
}

