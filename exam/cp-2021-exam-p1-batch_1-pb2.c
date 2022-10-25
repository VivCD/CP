#include <stdio.h>
#include <stdint.h>

uint32_t getNibble(uint32_t n, int pos)
{
    return ((n >> (pos * 4)) & 0xF);
}

uint32_t extractNibbles(uint64_t n)
{
    uint32_t res = 0;
    int halfPos = sizeof(n);
    int pos = 0;

    // Extract nibbles from even positions in the first (LS) half.
    for(int i = 0; i < halfPos; i++)
    {
        if(i % 2 == 0)
        {
            res = res | (getNibble(n, i) << pos);
            pos += 4;
        }
    }

    // Extract nibbles from odd positions in the second (MS) half.
    for(int i = halfPos; i < sizeof(n) * 2; i++)
    {
        if(i % 2 == 1)
        {
            res = res | (((n >> (4 * i)) & 0xF) << pos);
            pos += 4;
        }
    }

    return res;
}

int main()
{
    printf("%x\n", extractNibbles(0x1234567887654321LL));
    return 0;
}
