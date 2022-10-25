#include<stdio.h>
#include<math.h>
double myround (double x)
{
    if(x>0)
    {
        return ceil(x);
    }
    else 
    {
        return floor(x);
    }
}
void test(double x)
{
    if(round(x)==myround(x))
    {
        printf("test for %f passed. \n",x);
    }
    else 
    {
        printf("test for %f failed. \n",x);
    }
}
int main()
{
    double x;
   printf( "%f",myround(2.4));
   

}