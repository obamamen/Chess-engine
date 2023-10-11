#include <iostream>
#include <cstdint>

#include "board.h"
#include "enum.hpp"


Bitboard::Bitboard() {
    for (int i = 0; i < 12; ++i) {
        pieces[i] = 0ULL; // Initialize all pieces to empty
    }
}

void Bitboard::setPiece(Piece piece, Square square) {
    pieces[piece] |= (1ULL << square);
}

void PrintBoard(uint64_t bitboards[12]) {
    for (int piece = 0; piece < 12; piece++) {

        for (int rank = 7; rank >= 0; --rank) {
            for (int file = 0; file < 8; ++file) {
                int square = rank * 8 + file;
                if ((bitboards[piece] >> square) & 1ULL) {
                    std::cout << "1 ";
                } else {
                    std::cout << "0 ";
                }
            }
            std::cout << std::endl;
        }
    }
}
