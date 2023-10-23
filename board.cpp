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
    pieces[WPAWN] = 0xFF00ULL;
    pieces[WKNIGHT] = 0x42ULL;
    pieces[WBISHOP] = 0x24ULL;
    pieces[WROOK] = 0x81ULL;
    pieces[WQUEEN] = 0x8ULL;
    pieces[WKING] = 0x10ULL;

    pieces[BPAWN] = pieces[WPAWN] << 40;
    pieces[BKNIGHT] = pieces[WKNIGHT] << 56;
    pieces[BBISHOP] = pieces[WBISHOP] << 56;
    pieces[BROOK] = pieces[WROOK] << 56;
    pieces[BQUEEN] = pieces[WQUEEN] << 56;
    pieces[BKING] = pieces[WKING] << 56;

    whiteOO  = 1;
    whiteOOO = 1;

    blackOO  = 1;
    blackOOO = 1;

    plyCount = 0;

    isWhite = true;
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

void Board::PrintBoardAll() {
    //std::cout << " \n " << std::endl;

std::cout << "////////////////////////////////////  " << std::endl;
std::cout << "//---------- Game board ----------//  " << std::endl;
std::cout << "////////////////////////////////////  " << std::endl;
std::cout << "$ Is white: " << isWhite << std::endl;
        for (int rank = 7; rank >= 0; --rank) {
            for (int file = 0; file < 8; ++file) {
                int square = rank * 8 + file;
                if (isBitSet(pieces[WPAWN],square)) {
                    std::cout << "P  ";
                    continue;
                }
                if (isBitSet(pieces[BPAWN],square)) {
                    std::cout << "p  ";
                    continue;
                }
                if (isBitSet(pieces[WKNIGHT],square)) {
                    std::cout << "N  ";
                    continue;
                }
                if (isBitSet(pieces[BKNIGHT],square)) {
                    std::cout << "n  ";
                    continue;
                }
                if (isBitSet(pieces[WBISHOP],square)) {
                    std::cout << "B  ";
                    continue;
                }
                if (isBitSet(pieces[BBISHOP],square)) {
                    std::cout << "b  ";
                    continue;
                }
                if (isBitSet(pieces[WROOK],square)) {
                    std::cout << "R  ";
                    continue;
                }
                if (isBitSet(pieces[BROOK],square)) {
                    std::cout << "r  ";
                    continue;
                }
                if (isBitSet(pieces[WQUEEN],square)) {
                    std::cout << "Q  ";
                    continue;
                }
                if (isBitSet(pieces[BQUEEN],square)) {
                    std::cout << "q  ";
                    continue;
                }
                if (isBitSet(pieces[WKING],square)) {
                    std::cout << "K  ";
                    continue;
                }
                if (isBitSet(pieces[BKING],square)) {
                    std::cout << "k  ";
                    continue;
                }

                std::cout << "ㅤㅤㅤ";
            }
            std::cout << std::endl;
        }  

std::cout << "///////////////////////////////////  " << std::endl;
std::cout << "//---------- Game info ----------//  " << std::endl;
std::cout << "///////////////////////////////////  " << std::endl;

std::cout << "$ White castle king side: " << whiteOO << std::endl;
std::cout << "$ White castle queen side: " << whiteOOO << std::endl;


std::cout << "$ Black castle king side: " << blackOO << std::endl;
std::cout << "$ Black castle queen side: " << blackOOO << std::endl;

std::cout << "$ Move counter: " << plyCount << std::endl;

}
