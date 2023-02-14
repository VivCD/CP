#include<stdio.h>
#include<stdint.h>
/*Se citește numărul n. Să se determine numărul de ordine al celui mai semnificativ bit.
 int main(){
    unsigned n=5,posibleMostSemnificant=-1;
    for(int i=0;i<sizeof(n);i++){
        if(( (n >> i) & 1)==1)
          posibleMostSemnificant=i;
    }
    printf("%d",sizeof(n));
    printf("%d",posibleMostSemnificant);
}*/
/*Dându-se un număr natural n, să se afle toate numerele obținute resetând succesiv cel mai nesemnificativ bit cu valoarea 1, fără a folosi variabile auxiliare.
int main(){
 uint8_t n=123,posibleMostSemnificant;
 printf("%zu",sizeof(n));
 for(int i=0;i<sizeof(n)*8;i++){
    if(((n>>i)&1)==1){
          n = n & ~(1 << i);
        
         printf("%d ",n);
    }
 } 
 
}*/
/*Determinați distanța dintre primul bit setat și ultimul bit setat al unui număr natural.
int main(){
    unsigned n=4,posibleMostSemnificant=-1,leastSemnificantSetted=-1;
    for(int i=0;i<sizeof(n)*8;i++){
        if(( (n >> i) & 1)==1){
          posibleMostSemnificant=i;
          if(leastSemnificantSetted==-1)
              leastSemnificantSetted=i;
    }
    }
   
    printf("%d",posibleMostSemnificant-leastSemnificantSetted+1);

}
*/
/*Se citește un număr n. Să se calculeze n+1, folosind doar operatori pe biți.
int main()
{
    int n , x = 1;
    cin >> n;
    while(n & x)
    {
        n ^= x;
        x <<= 1;
    }
    n ^= x;
    cout << n;
    return 0;
}
*/
/*
int main(){
    uint64_t n=67; 
    int lenght0=0,lenght1=0,maxlenght0=-1,maxlenght1=-1,i=0;
    int state= (n >> i) & 1;
   
     while(i<=sizeof(n)*8){
        if(state==0){ 
           
             lenght0 +=1; 
            
         i++;
         if(((n >> i) & 1)==1) 
            { 
              state=1;
              
              if(lenght0>=maxlenght0)
                { 
                    maxlenght0=lenght0;
                 lenght0=0;
                }
            } 
            else state=0;
        }
         if(state==1){
           
            lenght1 +=1;
           
             i++;
            if(((n >> i) & 1)==0) 
              { state=0;
               
                if(lenght1>=maxlenght1)
                 {
                    maxlenght1=lenght1;
                 
                 lenght1=0;
                 }
            } 
            else state=1;
        } 
     }
     if(maxlenght0<=maxlenght1)
        printf("%d",maxlenght1%10) ;
        else
         printf("%d",maxlenght0%10);
}
*/ 


