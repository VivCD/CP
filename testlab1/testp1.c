#include<stdio.h>

 unsigned nmax=0,n;
 int v[10]; 

unsigned itsunique(unsigned n)
{
    unsigned c,b=0,p=1;
    
    while(n)
    {
    c=n%10;
    v[c]++;
    n=n%10;
    } 
   for(int i=1;i<=9;i++)
    if(v[i]==1)
    {
        if(i>b)
        {
            nmax=i*p+nmax;
            p=p*10;
        }
        else 
        nmax=nmax*10+i;
        b=i;
        p=p*10;
    } 
  return nmax;

} 
//  unsigned maxNumber(unsigned i)
//  { 
     
//      unsigned b=0,p=1;
//      if(i>b)
//      {
//          nmax=i*p+nmax;
//          p=p*10;
//      }
//       else 
//        nmax=nmax*10+i;
//        return nmax;
//  }

int main()
{
     
     printf("%f",itsunique(1423));
     
     
}