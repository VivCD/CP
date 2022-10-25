#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

unsigned decompress(char *s, char buf[], unsigned cap)
{
    unsigned sz = 0;
    char prevCh;

    for(unsigned i = 0; s[i] && sz < cap; i++)
    {
        if(isalpha(s[i]))
        {
            prevCh = s[i];
            buf[sz] = prevCh;
            sz++;
        }
        else if(isdigit(s[i]))
        {
            char *endPtr;
            int nrChar = strtol(s + i, &endPtr, 10);
            while(nrChar > 0 && sz < cap)
            {
                buf[sz] = prevCh;
                sz++;
                nrChar--;
            }
            i = endPtr - s - 1; // Compensate due to for increment
        }
    }

    return sz;
}

int main()
{
    char buf[32];
    unsigned sz;
    sz = decompress("a6b2cce12d", buf, 32);
    printf("Size of decompressed buffer: %u\n", sz);
    for(unsigned i = 0; i < sz; i++)
    {
        printf("%c", buf[i]);
    }
    printf("\n");

    return 0;
}
