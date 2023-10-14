#ifndef BIT
#define BIT

#include <iostream>
#include <cstdint>


uint64_t setBit(uint64_t num,int pos); 

uint64_t clearBit(uint64_t num, int pos); 

uint64_t toggleBit(uint64_t num, int pos); 


int getLSB(uint64_t b);

int popLSB(uint64_t &b);

bool isBitSet(uint64_t num, int pos); 

int countSetBits(uint64_t num); 



#endif