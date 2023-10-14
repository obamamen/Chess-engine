#ifndef MOVEGENERATOR
#define MOVEGENERATOR

#include <iostream>
#include <cstdint>

#include "move.h"
#include "movelist.h"
#include "board.h"

uint64_t GenerateKnightMoves(int pos);

moveList GenerateBakedKnightMoves();


#endif