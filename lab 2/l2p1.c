#include<stdio.h>
int swapLMD(unsigned int n)
{
    unsigned nr=0;
    int p=1,a;
    while(n)
    {
        a=n%10;
        nr=nr*p+a;
        n=n/100;
        p=p*10;
    }
    n=nr;
    return n;
}
 
int main()
{
    printf("%d", swapLMD("345"));
    return 0;
}