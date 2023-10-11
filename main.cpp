#include <iostream>
#include <cstdint>

#include "enum.hpp"
#include "printbitboard.h"
#include "board.h"


int main() {
    Bitboard board;
    board.setPiece(BPAWN, E2); // Set a white pawn on E2
    board.setPiece(WKNIGHT, G1); // Set a white knight on G1

    std::cout << "Bitboard for black pawns:" << std::endl;
    printBitboard(board.pieces[BPAWN]);

    std::cout << "Bitboard for white knights3:" << std::endl;
    printBitboard(board.pieces[WKNIGHT]);

    return 0;
}
