#include <stdio.h>

void decompose( unsigned int n )
{
    const unsigned int FIRST_PRIME = 2;

    printf( "%u = ", n );

    if ( n < FIRST_PRIME )
    {
        printf( "%u\n", n );
    }

    unsigned int m = FIRST_PRIME;

    while ( n > 1 )
    {
        unsigned int i = 0;

        while ( n % m == 0 )
        {
            ++i;
            n /= m;
        }

        if ( i != 0 )
        {
            printf( "%u", m );
            if ( i != 1 )
            {
                printf( "^%u", i );
            }

            if ( n != 1 ) putchar( '*' );
        }

        m = m == FIRST_PRIME ? 3 : m + 2;
    }
}


int main(void) 
{
    while ( 1 )
    {
        printf( "Enter a non-negative number (0 - exit): " );

        unsigned int n;

        if ( scanf( "%u", &n ) != 1 || n == 0 ) break;

        putchar( '\n' );
        decompose( n );
        putchar( '\n' );
    }

    return 0;
}