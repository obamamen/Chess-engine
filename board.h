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

//constexpr U64 north(U64 b) { return b << 8; }
//constexpr U64 south(U64 b) { return b >> 8; }
//constexpr U64 west(U64 b) { return (b & ~FILE_A) << 1; }
//constexpr U64 east(U64 b) { return (b & ~FILE_H) >> 1; }
//constexpr U64 north_west(U64 b) { return (b & ~FILE_A) << 9; }
///constexpr U64 north_east(U64 b) { return (b & ~FILE_H) << 7; }
//constexpr U64 south_west(U64 b) { return (b & ~FILE_A) >> 7; }
//constexpr U64 south_east(U64 b) { return (b & ~FILE_H) >> 9; }

#endif