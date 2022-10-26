/*implement a function that reads numbers from standars input,until the first negative value and returns the maximum lenght 
of a subsequence of numbers that have the sum of digits an odd value. the input consist of onlu digits, sapce and optional +
or - sign.
test the function with relevant data
 */
#include<stdio.h>
int maximum_lenght()
{ 
    int n,size=0,a[]={},sum=0; 
    do{
    scanf("%d", &n);
    a[size]=n;
    
    size++;
    }while(n>=0); 
    
    for(int i=0;i<size-1;i++)
    {
        sum=sum+a[i];
    }
    printf("%d",sum);
    for(int i=size-1;i>=0;i--)
      {
            if((sum%10)%2!=0)
            {
                 printf("    %d",  i);
               return i;
               
            }
            else  sum=sum-a[i];
      }
      return -1;
}

int main()
{
  int lenght= maximum_lenght();
   printf("%d  ", lenght);
  
}