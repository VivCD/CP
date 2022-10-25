#include<stdio.h>
#include<ctype.h>

void lines(unsigned n)
{
    unsigned a = n; unsigned c;
    while ((c = getchar()) != EOF)
    {
        while (n)
        {
            
            putchar(c);
            c = getchar();
            n--;
        }
        n = a;
        if (!isspace(c))
        {
            printf("\n");
            putchar('-');
            putchar(c);
        }

    }
}
int main()
{
   
    lines(6);
}