#include<stdio.h>

void median(int a, int b, int c)
{ 
    
    int d;
    if(a>=b)
     {
         d=a;
         a=b;
         b=d;
     }
     if(a>=c)
      {
         d=a;
         a=c;
         c=d; 
      }
      if(b>c)
    {
        d=b;
         b=c;
         c=d;
    }
      
    printf("%d",b);
}
int main()
{
    median(16,82,39);
    return 0;
}