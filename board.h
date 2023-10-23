#ifndef BOARD
#define BOARD

#include <iostream>
#include <cstdint>
#include <vector>

#include "enum.hpp"
#include "move.h"


class Board {
public:

    // Constructor
    Board();


    int whiteOO;
    int whiteOOO;

    int blackOO;
    int blackOOO;

    uint64_t enpassant;

    int plyCount;

    //std::vector<uint64_t bitboards[12]> threeFoldRepetition;


    // Really important
    bool isWhite;

    uint64_t pieces[12]; // One for each piece type

   
    void setPiece(Piece piece, Square square);

    void MakeMove(Move move, int piece);

    void PrintBoard(uint64_t bitboards[12]);

    void PrintBoardAll();
    
};



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

uint64_t north(uint64_t b);
uint64_t south(uint64_t b);
uint64_t west(uint64_t b);
uint64_t east(uint64_t b);
uint64_t north_west(uint64_t b);
uint64_t north_east(uint64_t b);
uint64_t south_west(uint64_t b);
uint64_t south_east(uint64_t b);

#endif