#ifndef MOVELIST
#define MOVELIST

#include <iostream>
#include <vector>
#include <cstdint>

#include "move.h"
#include "enum.hpp"

class moveList {
    public:
        std::vector<Move> moves;

        void addMoves(int start, uint64_t ends);

};



#endif