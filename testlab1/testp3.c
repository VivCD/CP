#include<stdio.h>
#include<ctype.h>
   int nr=0;
   unsigned c;
  void pozNumbers()

    { 
      int state;
      while((c=getchar()) != EOF)
      { 
          
          while(isdigit(c))
          {
              state=1;
              c=getchar();
          } 
          if(state==1) 
            nr=nr+1;
          if(c=='-')
          {
              nr=nr-1;
          }
      }
     if(c==getchar()=='\n')
     { 
         printf("%d",nr);
         nr=0;
     }
  int main()
  { 
       int nr=0;
       unsigned c;
      pozNumbers();
      return 0;
  }