#include"bitmask.h"
int set(int n,int set_bit)
{
    int m=n|(1<<(set_bit-1));
    return m;
}
int reset(int n, int set_bit)
{
    int m=n&(~(1<<(set_bit-1)));
    return m;
}
int flip(int n)
{
    int m=15-n;
    return m;
}
int query(int n)
{
    if((n&1)==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}