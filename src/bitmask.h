#ifndef __BIT_MASK_H__
#define __BIT_MASK_H__

#include<stdio.h>
#include<string.h>

int setBit(unsigned int data,unsigned int pos);
char* resetBit(char bit, char *byte);
unsigned int flipBits(unsigned int num) ;
BitArray::BitArray(unsigned int n);
bool BitArray::Query(unsigned int index) const;
const unsigned Mask(unsigned int x);

#endif