#include<stdio.h>
#include<stdint.h>
/*Se dă un număr n. Afișați rezultatul operației 2^n 


int main()
{ 
    unsigned n=3;
    unsigned x=1<<n;
    printf("%d",x);
}
*/

/*Se citesc n numere naturale. Determinați pentru fiecare dintre ele dacă este par sau impar.
int main(){
    unsigned n=60;
    unsigned x=n&1;
    if(x==0)
            printf("numar par");
    else printf("numar impar");

}
*/ 
/*  Se dau mai multe perechi de forma număr, bit. Afișați pentru fiecare pereche valoarea bitului corespunzător din reprezentarea internă pe 64 de biți a numărului dat.
int main(){
    unsigned n,b;
    n=5;b=2;
    printf("%d",(n>>b)&1);

}*/

/*Se dau: n un număr întreg și b un număr natural. Setați la 0 bitul b al lui n.
int main(){
    unsigned n,b;
    n=5;b=0;
     n = n & ~(1ll << b);
    printf("%d",n);

}*/
/*Se dau: n un număr întreg și b un număr natural. Setați la 1 bitul b al lui n.
int main(){
    unsigned n,b;
    n=5;b=1;
     n = n|(1ll << b);
    printf("%d",n);

}
*/
/*Se citește un număr n într-o variabilă de tip întreg pe 16 biți cu semn. Setați la valoarea 1 cei mai puțin semnificativi doi biți ai săi apoi afișați valoarea variabilei.
int main(){
    unsigned n,b;
    n=9;
     n = n|3;
    printf("%d",n);

}*/
/*Se citește un număr n într-o variabilă de tip întreg pe 16 biți cu semn. Setați la valoarea 0 cei mai puțin semnificativi doi biți ai săi apoi afișați valoarea variabilei.
int main(){
    unsigned n,b;
    n=5;
     n = n & ~3;
    printf("%d",n);

}*/
/*Dat fiind un număr natural n, să se determine numărul natural m care are are proprietatea că are în reprezentarea în baza 2 biți de 1 pe pozițiile unde n are biți de 0 și are biți de 0 pe pozițiile unde n are biți de 1
int main()
{
  unsigned n= 346, x =0x1ff;
    n=n^x;
    printf("%d",n);

}
/*
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
/* CP EXAM lenght of identical bits 
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
/*CP EXAM NR OF EVEN DIGITS*/
uint64_t generatenumber(unsigned n){
     int evenDigits=0,oddDigits=0; 
     uint64_t constructNumber=0;
      while(n){
        if(n%2==0){
              evenDigits+=1;
              n=n/10;
          }
          else{
                 oddDigits+=1;
                 n=n/10;
          }
      } 
      for(int i=0;i<evenDigits;i++)
        {  
           constructNumber= constructNumber|(1ll<<i);
        }
        printf("%d-even   ",evenDigits);
        printf("%d   ",constructNumber);
        
           constructNumber= constructNumber<<oddDigits;
    
        printf("%d-odd   ",oddDigits);
        printf("%d",constructNumber);
        

      return  1;

}

int main(){
unsigned n=766544876;
uint64_t resultNumber=generatenumber(n); 

}


