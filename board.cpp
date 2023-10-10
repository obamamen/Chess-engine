#include <iostream>
#include <cstdint>

#include "enum.hpp"
#include "board.hpp"


    

void eBitboard::Bitboard() {
    for (int i = 0; i < 7; ++i) {
        pieces[i] = 0ULL; // Initialize all pieces to empty
    }
}

void eBitboard::setPiece(Piece piece, Square square) {
    pieces[piece] |= (1ULL << square);
}
