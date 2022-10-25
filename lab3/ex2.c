#include<stdio.h>
#include<ctype.h>
int main()
{
    int line=0,words=0,ok=1,c;
    while((c=getchar())!=EOF)
    {
       
        if (isspace(c))
        {
            if(ok==0)//daca nu esti la inceput de linie cu spatiu 
            {
                 words++;
                
            } 
            if((c=='\n'||c==EOF)&&(words!=0&&line!=0))
            {
               
                printf("%d %d ",words,line); 
                words=0;line=0;
                ok=1;
            }
            
           
        } 
        else 
        {
            
            ok=0;
           if(c=='.')
           {
            line++;
           }
        }

        
    }
}