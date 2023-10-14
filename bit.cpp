

#include <iostream>
#include <cstdint>

#include "bit.h"






uint64_t setBit(uint64_t num, int pos) {
    return num | (1ULL << pos);
};

uint64_t clearBit(uint64_t num, int pos) {
    return num & ~(1ULL << pos);
}

uint64_t toggleBit(uint64_t num, int pos) {
    return num ^ (1ULL << pos);
}

int getLSB(uint64_t b) {
    return __builtin_ctzll(b);
}

int popLSB(uint64_t &b) {
    int i = __builtin_ctzll(b);
    b &= b - 1;
    return i;
}

bool isBitSet(uint64_t num, int pos) {
    return (num & (1ULL << pos)) != 0;
}

int countSetBits(uint64_t num) {
    int count = 0;
    while (num) {
        num &= (num - 1ULL);
        count++;
    }
    return count;
}

