#include<stdio.h>
#include<ctype.h>
unsigned ComputeValue(){ 
    char c;
    int putere=10,num=0,aux=0;
    while((c=getchar())!='\n'){
            if(c=='('){
                while(c!='+'){
                    if(isdigit(c)){
                        num=num*putere+(c-'0');
                       
                      
                        c=getchar();
                       
                    }
                    else c=getchar(); 
                }
                if(c=='+'){
                   
                    c=getchar();
                    
                    while(c!=')'){
                    if(isdigit(c)){
                        aux=aux*putere+(c-'0');
                        
                        
                         c=getchar();
                    }
                    else c=getchar();
                    }
                   
                    num=num+aux;
                }

            }
            if(isdigit(c)){
                 num=num*putere+(c-'0');
                 printf("numar %d putere%d ",num,putere);
                
                  
            }
          

    }
     
    return num;

}

int main(){
     
    unsigned value=ComputeValue();
     printf(" fianl value is %d",value);
  
}