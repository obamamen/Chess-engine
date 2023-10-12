#include <iostream>
#include <cstdint>

#include "enum.hpp"
#include "printbitboard.h"
#include "board.h"
#include "move.h"


int main() {
    Bitboard board;

    board.setPiece(WPAWN, A2);
    board.setPiece(WPAWN, B2);
    board.setPiece(WPAWN, C2);
    board.setPiece(WPAWN, D2);
    board.setPiece(WPAWN, E2);
    board.setPiece(WPAWN, F2);
    board.setPiece(WPAWN, G2);
    board.setPiece(WPAWN, H2);

    std::cout << "Bitboard for white pawns:" << std::endl;
    printBitboard(board.pieces[WPAWN]);

    Move m(A2,A4,WPAWN);
    
    board.MakeMove(m);


    std::cout << "Bitboard for white pawns:" << std::endl;
    printBitboard(board.pieces[WPAWN]);



    //std::cout << "Bitboard for black pawns:" << std::endl;
    //printBitboard(board.pieces[BPAWN]);

    //std::cout << "Bitboard for white knights3:" << std::endl;
    //printBitboard(board.pieces[WKNIGHT]);

    return 0;
}
