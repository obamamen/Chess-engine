#include <iostream>
#include <cstdint>

#include "movelist.h"

#include "move.h"
#include "bit.h"
#include "enum.hpp"


void moveList::addMove(int start, uint64_t ends, Piece p) {
    while (ends)
    {
        int end = popLSB(ends);
        Move m(start, end, p);
        moves.push_back(m);
    }
}