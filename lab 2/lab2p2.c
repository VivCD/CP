#include<stdio.h>

void addTime(unsigned int h, unsigned int m, unsigned int dMin)
{
    if(dMin>60)
    {
        while(dMin/60)
        {
            h=h+1;
            dMin=dMin % 60;

        }
        m=m+dMin;
        if(m>60)
        {
            while(m/60)
            {
                h=h+1;
                m=m%60;
            }
        }
    }
    else {
          m=m+dMin;
        if(m>60)
        {
            while(m/60)
            {
                h=h+1;
                m=m%60;
            }
        }
    }
    printf("%d:%d",h,m);
        
}
int main()
{
     addTime(1,34,78);
    return 0;
}