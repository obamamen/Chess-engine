#ifndef BOARD
#define BOARD

#include <iostream>
#include <cstdint>

#include "enum.hpp"
#include "move.h"

class Bitboard {
public:
    uint64_t pieces[12]; // One for each piece type

    // Bitboards for files A, B, G, and H
    uint64_t aFileBitboard = 0x0101010101010101ULL;
    uint64_t bFileBitboard = 0x0202020202020202ULL;
    uint64_t gFileBitboard = 0x4040404040404040ULL;
    uint64_t hFileBitboard = 0x8080808080808080ULL;

    // Bitboards for ranks 2 and 7
    uint64_t secondRankBitboard = 0x000000000000FF00ULL;
    uint64_t seventhRankBitboard = 0x00FF000000000000ULL;


    Bitboard();
    

    void setPiece(Piece piece, Square square);

    void MakeMove(Move move);

    void PrintBoard(uint64_t bitboards[12]);
    
};

#endif