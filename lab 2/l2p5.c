#include<stdio.h>

void Loads(int NT)
{ 
    // p price without the discount
    // r discount
    float P = 0,r = 0;
    if(NT>=2)
    {
        P=2.75 *  NT;
        r= 0.05*P;
        
        printf("u need %f and  an the rest amount is %f ",P,r);
        
    } 
    
    else printf("u need 2.75 cents");
    
    
}   
int main()
{
     Loads(3);
     return 0;
}