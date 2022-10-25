#include<stdio.h>
int compare(int a,int b)
{
    if(a!=b)
    {
        return 1;
    }
    else return 0;
}
int DistinctorEqual(int a,int b,int c)
{
    if(compare(a,b)) 
    {
        if(compare(a,c))
        {
            if(compare(b,c))
             printf("all arguments are distinct");
             else printf("argument 2 and 3 are equal");
        } 
        else printf("argument 1 and 3 are equal");
    }
    else { 
             if(compare(b,c))
                 printf("argument 1 and 2 are equal");
                 else printf("all arguments are equal") ;
               
           } 
        
}
int main()
{
    DistinctorEqual(5,2,4);
    return 0;
}