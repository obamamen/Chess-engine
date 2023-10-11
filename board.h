#ifndef BOARD
#define BOARD

#include <iostream>
#include <cstdint>

#include "enum.hpp"

class Bitboard {
public:
    uint64_t pieces[12]; // One for each piece type

    Bitboard();
    

    void setPiece(Piece piece, Square square);

    void PrintBoard(uint64_t bitboards[12]);
    
};

#endif