#include<stdio.h>
#include<stdint.h>
uint16_t get16OutOf32_b(uint32_t n)
{
    uint16_t r=0;
    while(n)
    {
        uint16_t bit=0;
        if((n&0x1)!=0)
        {
            bit=1;
        }
        r=(r<<1)|bit;
        n=n>>2;
    }
    return r;
}
uint16_t get16OutOf32_a(uint32_t n)
{
    uint16_t r=0;
    uint16_t posR=15;

    for(int posN=31;posN>0; posN-=2)
    {
        uint16_t bit=0;
        if((n&(1<<posN))!=0)
        {
            bit=1;
        }
        printf("Bit on position %d id %d\n",posN,bit);
        r=r| (bit<<posR);
        posR--;
    }
    return r;
}
int main()
{
    uint16_t r_a=get16OutOf32_a(0x37AB9C1D);
    uint16_t r_b=get16OutOf32_b(0x37AB9C1D);
    print("%x\n",r_a);

    return 0;
}