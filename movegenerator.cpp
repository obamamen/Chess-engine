#include "movegenerator.h"

#include <iostream>
#include <cstdint>
#include <array>

#include "move.h"
#include "movelist.h"
#include "board.h"
#include "bit.h"

uint64_t GenerateKnightMoves(int pos) {
    uint64_t attacks, knights = 0ULL;

    // place knight on board
    knights = toggleBit(knights, pos);

    // add attacks
    attacks = (((knights << 6)  | (knights >> 10)) & ~FILE_GH) |
        (((knights << 10) | (knights >> 6))  & ~FILE_AB) |
        (((knights << 15) | (knights >> 17)) & ~FILE_H)  |
        (((knights << 17) | (knights >> 15)) & ~FILE_A);

    return attacks;
}

void GenerateBakedKnightMoves(uint64_t *arr) {

    for (int i = 0; i < 64; i++)
    {   
        arr[i] = GenerateKnightMoves(i);

    }

}   