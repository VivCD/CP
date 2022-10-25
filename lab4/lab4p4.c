#include<stdio.h>
#include<ctype.h>

int number()
{
	int n=0;
	int c,counter=0;
	while((c=getchar())!='\n')
	{
		 if(counter>3) 
		 { 
			printf("not a valid number");
			return -1;
			
		 }
		else if(isdigit(c) && counter<=3){
			n=n+(c-'0');
			counter++;
		} else if(c==',')
		{
               counter=0;
		}
            
	}
	return n;
}

int main()
{
	int finalNumber;
	finalNumber=number();
	if(finalNumber!=-1)
	  printf("%d",finalNumber);
	  else printf("not a valid number");

}