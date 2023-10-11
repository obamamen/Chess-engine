#include <iostream>
#include <cstdint>

#include "enum.hpp"
#include "printbitboard.h"





class Bitboard {
public:
    uint64_t pieces[7]; // One for each piece type

    Bitboard() {
        for (int i = 0; i < 7; ++i) {
            pieces[i] = 0ULL; // Initialize all pieces to empty
        }
    }

    void setPiece(Piece piece, Square square) {
        pieces[piece] |= (1ULL << square);
    }
};


int main() {
    Bitboard board;
    board.setPiece(PAWN, E2); // Set a white pawn on E2
    board.setPiece(KNIGHT, G1); // Set a white knight on G1

    std::cout << "Bitboard for white pawns:" << std::endl;
    printBitboard(board.pieces[PAWN]);

    std::cout << "Bitboard for white knights:" << std::endl;
    printBitboard(board.pieces[KNIGHT]);

    return 0;
}
