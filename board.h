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


    bool whiteOO  =true;
    bool whiteOOO =true;

    bool blackOO  =true;
    bool blackOOO =true;

    uint64_t enpassant;

    int plyCount = 0;

    //std::vector<uint64_t bitboards[12]> threeFoldRepetition;


    // Really important
    bool isWhite = true;

    uint64_t pieces[12]; // One for each piece type

   
    void setPiece(Piece piece, Square square);

    void MakeMove(Move move, int piece);

    void PrintBoard(uint64_t bitboards[12]);
    
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

#endif