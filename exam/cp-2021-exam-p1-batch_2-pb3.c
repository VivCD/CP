#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

/* Variant 1 - easy to implement and understand. */
char* compress(char *s)
{
    unsigned sz = 0, charCnt, len = strlen(s);
    char prevCh;
    char *res;

    res = malloc(len + 1); // Compressed string cannot be longer than the original.
    if(res == NULL)
        return NULL;

    prevCh = s[0];
    charCnt = 1;
    for(unsigned i = 1; i <= len; i++)
    {
        if(s[i] == prevCh)
            charCnt++;
        else
        {
            res[sz] = prevCh;
            sz++;
            if(charCnt > 1)
            {
                sz += sprintf(res + sz, "%u", charCnt);
            }
            charCnt = 1;
        }
        prevCh = s[i];
    }
    res[sz] = '\0';

    // Optimizing size properly in a safe way
    char *tmp = realloc(res, sz + 1); // Shrink the string to a minimum
    if(tmp == NULL)
    {
        free(res);
        return NULL;
    }
    res = tmp;

    return res;
}

/* Variant 2 - memory and time efficient (balanced).

   This implementation is less memory efficient than Variant 1 when
   the compressed is using more than half of memory of the uncompressed string.

   The highest memory optimization can be applied only if the decompressed string is pre-analyzed,
   which doubles the computation time.
*/
char* compressOptimized(char *s)
{
    unsigned sz = 0, capacity = 1, charCnt;
    char prevCh;
    char *res, cntAsString[11];

    res = malloc(capacity);
    if(res == NULL)
        return NULL;

    prevCh = s[0];
    charCnt = 1;
    /* Iterate until '\0' was also processed, as the last step.
       If string is empty from the beginning, do nothing. */
    for(unsigned i = 1; prevCh; i++)
    {
        if(s[i] == prevCh)
            charCnt++;
        else
        {
            int nrLen = 0;
            if(charCnt > 1)
            {
                // Just measure how long will the number be.
                nrLen = sprintf(cntAsString, "%u", charCnt);
            }

            /* Expand the buffer until there is enough room for data.
               Doubling the buffer capacity is a common practice. */
            while(sz + 1 + nrLen >= capacity)
            {
                char *tmp = realloc(res, capacity * 2);
                if(tmp == NULL)
                {
                    // Cannot reallocate, cleanup resources.
                    free(res);
                    return NULL;
                }
                res = tmp;
                capacity = capacity * 2;
            }

            res[sz] = prevCh;
            sz++;
            if(charCnt > 1)
            {
                sz += sprintf(res + sz, "%d", charCnt);
            }
            charCnt = 1;
        }
        prevCh = s[i];
    }
    res[sz] = '\0';

    // Optimizing size, as we might have allocated too much above.
    char *tmp = realloc(res, sz + 1);
    if(tmp == NULL) // Shrink the string to a minimum.
    {
        /* As the above realloc is for shrinking, this branch might never be reached because
           shrinking (usually) does not need to reallocate the memory.
           However, the check must be performed in order to have a robust code. */

        // Cannot reallocate, cleanup resources.
        free(res);
        return NULL;
    }
    res = tmp;

    return res;
}

int main()
{
    char *s;
    // s = compress("aaabcdeeeeff");
    s = compressOptimized("aaabcdeeeeff");
    printf("Length of compressed string: %lu\n", strlen(s));
    printf("%s\n", s);

    return 0;
}
