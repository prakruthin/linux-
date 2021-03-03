#include"Bitmask.h"
int set(int num,int set_bit)
{
    int m=num|(1<<(set_bit-1));
    return m;
}
int reset(int num, int set_bit)
{
    int m=num&(~(1<<(set_bit-1)));
    return m;
}
int flip(int num)
{
    int m=15-num;
    return m;
}
int query(int num)
{
    if((num&1)==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}