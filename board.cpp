#include <iostream>
#include <cstdint>

#include "board.h"
#include "enum.hpp"
#include "move.h"
#include "bit.h"

// Bitboards for files A, B, G, and H
    uint64_t FILE_A = 0x0101010101010101ULL;
    uint64_t FILE_B = 0x0202020202020202ULL;
    uint64_t FILE_G = 0x4040404040404040ULL;
    uint64_t FILE_H = 0x8080808080808080ULL;

    uint64_t FILE_AB = FILE_A | FILE_B;
    uint64_t FILE_GH = FILE_G | FILE_H;

// Bitboards for ranks 2 and 7
    uint64_t secondRankBitboard = 0x000000000000FF00ULL;
    uint64_t seventhRankBitboard = 0x00FF000000000000ULL;

uint64_t north(uint64_t b) { return b << 8; }
uint64_t south(uint64_t b) { return b >> 8; }
uint64_t west(uint64_t b) { return (b & ~FILE_H) << 1; }
uint64_t east(uint64_t b) { return (b & ~FILE_A) >> 1; }
uint64_t north_west(uint64_t b) { return (b & ~FILE_H) << 9; }
uint64_t north_east(uint64_t b) { return (b & ~FILE_A) << 7; }
uint64_t south_west(uint64_t b) { return (b & ~FILE_H) >> 7; }
uint64_t south_east(uint64_t b) { return (b & ~FILE_A) >> 9; }


Board::Board() {
    for (int i = 0; i < 12; ++i) {
        pieces[i] = 0ULL; // Initialize all pieces to empty
    }
}

void Board::MakeMove(Move move, int piece) {
    pieces[piece] = setBit(pieces[piece],move.target);
    pieces[piece] = clearBit(pieces[piece],move.start);

    //std::cout <<  "MakeMove move.start: " <<  move.start  << std::endl;
    //std::cout << "MakeMove move.target: " << move.target << std::endl;
}

void Board::setPiece(Piece piece, Square square) {
    pieces[piece] |= (1ULL << square);
}

void Board::PrintBoard(uint64_t bitboards[12]) {
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
