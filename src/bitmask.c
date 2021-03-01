

#include "bitmask.h"


int setBit(unsigned int data,unsigned int pos)
{
    return (data|(1 << pos));
}

char* resetBit(char bit, char *byte)
{
    bit = 1 << bit;
    bit ^= 0xff;
    *byte = *byte & bit;
    return byte;
}

unsigned int flipBits(unsigned int num) 
{ 
    unsigned int  NO_OF_BITS = sizeof(num) * 8; 
    unsigned int reverse_num = 0, i, temp; 
  
    for (i = 0; i < NO_OF_BITS; i++) 
    { 
        temp = (num & (1 << i)); 
        if(temp) 
            reverse_num |= (1 << ((NO_OF_BITS - 1) - i)); 
    } 
   
    return reverse_num; 
}

BitArray::BitArray(unsigned int n)
{
	int placer= n%SIZE;
    arraySize= n/SIZE;
    if(placer>0)
       arraySize++;
    barray = new unsigned char[arraySize];
    for(int i=0; i<arraySize; i++)
        barray[i]= 0;
}
bool BitArray::Query(unsigned int index) const
{
	int holder = index%SIZE;
	int placer = index/SIZE;
	if (barray[placer] & Mask(index))
		return true;
	else
		return false;
}

const unsigned Mask(unsigned int x)
{
	return (1 << x);
}