/*(implement a function that receives an unsigned number as an argument and returns the maximum
 number obtained with the unique(distinct) digit of argument.test tha function with relevant data)*/ 


#include<stdio.h>
 int a[10];//vector de frecventa initializat cu 0
int number(int n) //receives a number
{  printf("%d    ",n);
 
    while(n!=0)
    {
        int c=n%10;
      
        a[c]++; //pe pozitia egala cu cifra crestem numarul de aparitii
        n=n/10;
    } 
   int m=0; //numarul ce il returnam
    for(int i=9;i>=0;i--) //parcurgem vectoru de la capat ca sa obtinem numerele mari intai
     {
        if(a[i]>=1) 
        {  m=m*10+i;
         
        }
     }
        return m;
}



int main()
{
    
    int numar_primit,numar_obtinut,a;
    scanf("%d",&numar_primit);
     printf("%d    ",numar_primit);
    numar_obtinut=number(numar_primit);
    printf("%d",numar_obtinut);
    scanf("%d",&a);
   

}