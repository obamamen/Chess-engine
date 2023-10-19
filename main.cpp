#include <iostream>
#include <cstdint>
#include <vector>

#include "enum.hpp"
#include "printbitboard.h"
#include "board.h"
#include "move.h"
#include "bit.h"
#include "movegenerator.h"

int main() {

    uint64_t knights[64];
    GenerateBakedKnightMoves(knights);

    for (int i = 0; i < 63; i++) {

        printBitboard(knights[i]);
        std::cout << "|" << std::endl;
        std::cout << "position: " << i << std::endl;
        std::cout << "|" << std::endl;

    }
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
    
    std::cout << "test :" << std::endl;
    uint64_t bit = setBit(0ULL,H5);
    uint64_t n = north(bit);
    uint64_t s = south(bit);
    uint64_t w = west(bit);
    uint64_t e = east(bit);
    uint64_t nw = north_west(bit);
    uint64_t ne = north_east(bit);
    uint64_t sw = south_west(bit);
    uint64_t se = south_east(bit);

    printBitboard(n|s|w|e|nw|ne|sw|se);

    return 0;

    
}
