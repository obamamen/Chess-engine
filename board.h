#ifndef BOARD
#define BOARD

#include <iostream>
#include <cstdint>

#include "enum.hpp"
#include "move.h"

// Bitboards for files A, B, G, and H
    extern uint64_t FILE_A;
    extern uint64_t FILE_B;
    extern uint64_t FILE_G;
    extern uint64_t FILE_H ;

    extern uint64_t FILE_AB;
    extern uint64_t FILE_GH;

// Bitboards for ranks 2 and 7
    extern uint64_t secondRankBitboard;
    extern uint64_t seventhRankBitboard;

class Board {
public:
    uint64_t pieces[12]; // One for each piece type




    Board();
    

    void setPiece(Piece piece, Square square);

    void MakeMove(Move move, int piece);

    void PrintBoard(uint64_t bitboards[12]);
    
};

#endif