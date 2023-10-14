#include <iostream>
#include <cstdint>

#include "movelist.h"

#include "move.h"
#include "bit.h"
#include "enum.hpp"


void moveList::addMoves(int start, uint64_t ends) {
    while (ends)
    {
        int end = popLSB(ends);
        Move m(start, end);
        moves.push_back(m);
    }
}