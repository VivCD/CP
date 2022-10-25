#include<stdio.h>
#include<ctype.h>
int static counter=0;
void base16(unsigned n)
{ 
 int a[ ]={};  
	while(n!=0)
	{
		
			a[counter]=n%16; 
			counter++;
			n=n/16;
		}
		// int size = sizeof(a)/sizeof(a[0]);
	for(int i=5;i>0;i--) 
	  printf("%X",a[i]);
	putchar(' ');
	/*	else if(n%16==10)
			putchar('A');
		else if(n%16==11)
			putchar('B');
		else if (n%16==12)
			putchar('C');
		else if (n%16==13)
			putchar('D');
		else if (n%16==14)
			putchar('E');
		else if (n%16==15)
			putchar('F');
		n=n/16;
*/ 
	}


int main()
{
	printf("From left to right: ");
	int c,n=0;
	while((c=getchar())!='\n')
	{
		if(isdigit(c)){
			n=n*10+(c-'0');
		}
            
	}
	base16(n); 
    
	return 0;
}