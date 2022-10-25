#include<stdio.h>
#include<ctype.h>


int main()
{
	int c,w=0,state=0,l=0;
	while((c=getchar()) != EOF)
	{ 
		if(state==0)
		{
			if(!isspace(c))
			{
				state=1;
				w++;
			}
			else if(c=='\n')
			{
				l++;
				printf("Words: %d \n",w);
				printf("Lines: %d \n",l);
				w=0;
			}
		}

		else if(state==1)
		{
			if(!isspace(c))
				state=1;
			else {
				state=0;

			}
			if(c=='\n')
			{
				l++;
				printf("Words: %d \n",w);
				printf("Lines: %d \n",l);
				w=0;
			}
			

		}
	}


	return 0;
}