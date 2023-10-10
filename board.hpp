#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <cstdint>

#include "enum.hpp"

class eBitboard {
public:
    uint64_t pieces[7]; // One for each piece type

    void Bitboard() {
    }

    //void setPiece(Piece piece, Square square) {
    //}
};

#endif