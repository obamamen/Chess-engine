#ifndef BIT
#define BIT

#include <iostream>
#include <cstdint>


uint64_t setBit(uint64_t num,int pos);

uint64_t clearBit(uint64_t,int);

uint64_t toggleBit(uint64_t,int); 

bool isBitSet(uint64_t,int); 

int countSetBits(uint64_t); 



#endif