#include <stdio.h>
#include <stdint.h>

uint32_t getNibble(uint32_t n, int pos)
{
    return ((n >> (pos * 4)) & 0xF);
}

uint64_t injectNibbles(uint32_t n)
{
    uint64_t res = 0;
    int pos;

    // Split nibbles into even positions of destination.
    pos = 0;
    for(int i = 0; i < sizeof(n) * 2; i++)
    {
        res = res | ((uint64_t)getNibble(n, i) << pos);
        pos += 8;
    }

    // Inject XOR-ed nibbles, except for 7th nibble.
    pos = 4;
    for(int i = 0; i < sizeof(uint64_t) * 8 - 4; i++)
    {
        uint64_t valXor = (getNibble(n, i) ^ getNibble(n, i + 1));
        res = res | (valXor << pos);
        pos += 8;
    }
    // Inject 7th XOR-ed nibble.
    res = res | (getNibble(n, 7) ^ getNibble(n, 0));

    return res;
}

int main()
{
    printf("%lx\n", injectNibbles(0x12488421LL));
    return 0;
}
