#include "printbitboard.h"


#include <iostream>
#include <cstdint>




void printBitboard(uint64_t bitboard)
{
        for (int rank = 7; rank >= 0; --rank) {
        for (int file = 0; file < 8; ++file) {
            int square = rank * 8 + file;
            if ((bitboard >> square) & 1ULL) {
                std::cout << "1 ";
            } else {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
}
