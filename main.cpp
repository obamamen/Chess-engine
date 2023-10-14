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

    moveList knights = GenerateBakedKnightMoves();
    uint64_t test = 0ULL;
    for (int i = 0; i < knights.moves.size(); i++) {
        test = 0ULL;


        uint64_t start = knights.moves[i].getStart();
        uint64_t end = knights.moves[i].getTarget();

        printBitboard(start | end);
        std::cout << "Start space | : " << knights.moves[i].start <<std::endl;
        std::cout << "End space | : " << knights.moves[i].target <<std::endl;
        std::cout << "Iteration | : " << i <<std::endl;
    }

    return 0;
}
